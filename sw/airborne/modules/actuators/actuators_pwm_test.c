#include "modules/actuators/actuators_pwm_test.h"

/* Simple module to commit PWM values set via settings */

int32_t actuators_pwm_test_values[ACTUATORS_PWM_NB];

void actuators_pwm_test_init(void)
{
  for (int i = 0; i < ACTUATORS_PWM_NB; i++) {
    actuators_pwm_test_values[i] = 1000;
  }
}

void actuators_pwm_test_periodic(void)
{
  for (int i = 0; i < ACTUATORS_PWM_NB; i++) {
    ActuatorPwmSet(i, actuators_pwm_test_values[i]);
  }
  ActuatorsPwmCommit();
}

