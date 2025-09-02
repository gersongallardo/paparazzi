#include "modules/datalink/datalink.h"
#include "modules/actuators/actuators_pwm.h"
#include "modules/core/settings.h"
#include "generated/settings.h"
#include "pprzlink/messages.h"

void dl_actuators_parse_dl_set_actuator(struct link_device *dev __attribute__((unused)),
                                        struct transport_tx *trans __attribute__((unused)),
                                        uint8_t *buf)
{
  uint8_t no = DL_SET_ACTUATOR_no(buf);
  uint16_t val = DL_SET_ACTUATOR_value(buf);
  if (no < ACTUATORS_PWM_NB) {
    ActuatorPwmSet(no, val);
  }
}

void dl_actuators_parse_dl_setting(struct link_device *dev __attribute__((unused)),
                                   struct transport_tx *trans __attribute__((unused)),
                                   uint8_t *buf)
{
  if (DL_SETTING_ac_id(buf) != AC_ID) {
    return;
  }
  uint8_t idx = DL_SETTING_index(buf);
  float val = DL_SETTING_value(buf);
  DlSetting(idx, val);
  for (uint8_t i = 0; i < ACTUATORS_PWM_NB; i++) {
    ActuatorPwmSet(i, actuators_pwm_values[i]);
  }
}
