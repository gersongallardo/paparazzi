// Driver for the DPS310 barometer
#include "modules/sensors/baro_dps310.h"

#include "modules/core/abi.h"
#include "mcu_periph/sys_time.h"
#include "mcu_periph/i2c.h"
#include "math/pprz_isa.h"
#include "modules/datalink/downlink.h"
#include "pprzlink/messages.h"

#ifndef DPS310_I2C_DEV
#define DPS310_I2C_DEV i2c1
#endif

#ifndef DPS310_SLAVE_ADDR
#define DPS310_SLAVE_ADDR 0x77
#endif

float baro_alt = 0.f;
bool baro_alt_valid = false;
static float baro_pressure = 0.f;

static struct i2c_periph *dps_i2c = &DPS310_I2C_DEV;
static struct i2c_transaction dps_trans;

/* calibration coefficients */
static int32_t c0, c1, c00, c10, c01, c11, c20, c21, c30;

/* oversampling scale factor (OSR = 8) */
#define DPS310_SCALE 7864320.0f

static void dps310_read_calib(void)
{
  dps_trans.buf[0] = 0x10; /* coef start */
  i2c_blocking_transceive(dps_i2c, &dps_trans, DPS310_SLAVE_ADDR, 1, 18, 0.01f);
  uint8_t *b = dps_trans.buf;

  c0  = (b[0] << 4) | (b[1] >> 4); if (c0  & 0x800)  c0  -= 1 << 12;
  c1  = ((b[1] & 0x0F) << 8) | b[2]; if (c1  & 0x800)  c1  -= 1 << 12;
  c00 = (b[3] << 12) | (b[4] << 4) | (b[5] >> 4); if (c00 & 0x80000) c00 -= 1 << 20;
  c10 = ((b[5] & 0x0F) << 16) | (b[6] << 8) | b[7]; if (c10 & 0x80000) c10 -= 1 << 20;
  c01 = (b[8] << 8) | b[9];   if (c01 & 0x8000) c01 -= 1 << 16;
  c11 = (b[10] << 8) | b[11]; if (c11 & 0x8000) c11 -= 1 << 16;
  c20 = (b[12] << 8) | b[13]; if (c20 & 0x8000) c20 -= 1 << 16;
  c21 = (b[14] << 8) | b[15]; if (c21 & 0x8000) c21 -= 1 << 16;
  c30 = (b[16] << 8) | b[17]; if (c30 & 0x8000) c30 -= 1 << 16;
}

static void dps310_configure(void)
{
  /* pressure config: oversampling 8x */
  dps_trans.buf[0] = 0x06; dps_trans.buf[1] = 0x04;
  i2c_blocking_transceive(dps_i2c, &dps_trans, DPS310_SLAVE_ADDR, 2, 0, 0.01f);
  /* temp config: oversampling 8x, internal sensor */
  dps_trans.buf[0] = 0x07; dps_trans.buf[1] = 0x84;
  i2c_blocking_transceive(dps_i2c, &dps_trans, DPS310_SLAVE_ADDR, 2, 0, 0.01f);
  /* continuous background measurement of pressure+temperature */
  dps_trans.buf[0] = 0x08; dps_trans.buf[1] = 0x07;
  i2c_blocking_transceive(dps_i2c, &dps_trans, DPS310_SLAVE_ADDR, 2, 0, 0.01f);
}

void baro_dps310_init(void)
{
  dps_trans.status = I2CTransDone;
  baro_alt_valid = false;
  dps310_read_calib();
  dps310_configure();
}

void baro_dps310_periodic(void)
{
  dps_trans.buf[0] = 0x00; /* pressure/temp data start */
  if (i2c_blocking_transceive(dps_i2c, &dps_trans,
                              DPS310_SLAVE_ADDR, 1, 6, 0.01f) != I2CTransSuccess) {
    static uint8_t err_cnt = 0;
    if (err_cnt < 5) {
      /* keep a small counter so we don't spam retries */
      err_cnt++;
#if DOWNLINK
      const char *msg = "DPS310 I2C error";
      DOWNLINK_SEND_INFO_MSG(DefaultChannel, DefaultDevice, strlen(msg), msg);
#endif
    }
    return;
  }

  uint8_t *b = dps_trans.buf;
  int32_t p_raw = (b[0] << 16) | (b[1] << 8) | b[2];
  if (p_raw & 0x800000) { p_raw -= 1 << 24; }
  int32_t t_raw = (b[3] << 16) | (b[4] << 8) | b[5];
  if (t_raw & 0x800000) { t_raw -= 1 << 24; }

  float t_sc = (float)t_raw / DPS310_SCALE;
  float p_sc = (float)p_raw / DPS310_SCALE;

  float temp = c0 * 0.5f + c1 * t_sc;
  float pres = c00 + p_sc * (c10 + p_sc * (c20 + p_sc * c30)) +
               t_sc * c01 + t_sc * p_sc * (c11 + p_sc * c21);

  baro_pressure = pres;
  baro_alt = pprz_isa_altitude_of_pressure(pres);
  baro_alt_valid = true;
  uint32_t ts = get_sys_time_usec();
  AbiSendMsgBARO_ABS(BARO_DPS310_SENDER_ID, ts, (int32_t)pres);
  AbiSendMsgTEMPERATURE(BARO_DPS310_SENDER_ID, (int32_t)(temp * 100));
  DOWNLINK_SEND_BARO_RAW(DefaultChannel, DefaultDevice, &pres, &baro_alt);
}

void baro_dps310_event(void)
{
  /* nothing to do, data already sent in periodic */
}

