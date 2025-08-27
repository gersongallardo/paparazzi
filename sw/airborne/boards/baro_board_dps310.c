#include "modules/sensors/baro.h"
#include "modules/sensors/baro_dps310.h"
#include "modules/core/abi.h"
#include "boards/baro_board_dps310.h"
#include "mcu_periph/sys_time.h"
#include "led.h"
#include "std.h"

void baro_init(void)
{
  baro_dps310_init();
#ifdef BARO_LED
  LED_OFF(BARO_LED);
#endif
}

void baro_periodic(void)
{
  baro_dps310_periodic();
}

void baro_event(void)
{
  baro_dps310_event();
#ifdef BARO_LED
  RunOnceEvery(10, LED_TOGGLE(BARO_LED));
#endif
}
