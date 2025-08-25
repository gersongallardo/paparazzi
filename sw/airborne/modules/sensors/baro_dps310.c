#include "modules/sensors/baro_dps310.h"
#include "modules/core/abi.h"
#include "mcu_periph/sys_time.h"

float baro_alt = 0;
bool baro_alt_valid = false;

void baro_dps310_init(void) {
  baro_alt = 0;
  baro_alt_valid = false;
}

void baro_dps310_periodic(void) {
  /* TODO implement sensor polling */
}

void baro_dps310_event(void) {
  uint32_t now_ts = get_sys_time_usec();
  AbiSendMsgBARO_ABS(BARO_DPS310_SENDER_ID, now_ts, 0);
}
