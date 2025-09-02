#ifndef ACTUATORS_PWM_TEST_H
#define ACTUATORS_PWM_TEST_H

#include "modules/actuators/actuators_pwm.h"

extern int32_t actuators_pwm_test_values[ACTUATORS_PWM_NB];

void actuators_pwm_test_init(void);
void actuators_pwm_test_periodic(void);

#endif
