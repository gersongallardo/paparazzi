#ifndef CONFIG_PX4FMU_2_4_H
#define CONFIG_PX4FMU_2_4_H

/* identify board family */
#define BOARD_PX4FMU

/* include the low level board description */
#include "boards/px4fmu/chibios/v2.4/board.h"

/* -----------------------------------------------------------------
 * Analog channels
 * -----------------------------------------------------------------*/
#ifndef USE_ADC_1
#define USE_ADC_1 1
#endif
#if USE_ADC_1
#define AD1_1_CHANNEL    ADC_CHANNEL_IN9
#define ADC_1            AD1_1
#define ADC_1_GPIO_PORT  GPIOB
#define ADC_1_GPIO_PIN   GPIO1
#endif

#ifndef USE_ADC_2
#define USE_ADC_2 1
#endif
#if USE_ADC_2
#define AD1_2_CHANNEL    ADC_CHANNEL_IN15
#define ADC_2            AD1_2
#define ADC_2_GPIO_PORT  GPIOC
#define ADC_2_GPIO_PIN   GPIO5
#endif

#ifndef USE_ADC_3
#define USE_ADC_3 1
#endif
#if USE_ADC_3
#define AD1_3_CHANNEL    ADC_CHANNEL_IN14
#define ADC_3            AD1_3
#define ADC_3_GPIO_PORT  GPIOC
#define ADC_3_GPIO_PIN   GPIO4
#endif

#ifndef USE_ADC_4
#define USE_ADC_4 1
#endif
#if USE_ADC_4
#define AD1_4_CHANNEL    ADC_CHANNEL_IN4
#define ADC_4            AD1_4
#define ADC_4_GPIO_PORT  GPIOA
#define ADC_4_GPIO_PIN   GPIO4
#endif

#ifndef ADC_CHANNEL_VSUPPLY
#define ADC_CHANNEL_VSUPPLY ADC_4
#endif

#define DefaultVoltageOfAdc(adc) (0.006185 * (adc))

/* -----------------------------------------------------------------
 * PPRZLink file descriptor placeholder
 * -----------------------------------------------------------------*/
#ifdef PPRZLINK_ENABLE_FD
static long _FD;
#define _FD_ADDR (&_FD)
#endif

#endif /* CONFIG_PX4FMU_2_4_H */
