/*
 * Matek F405 Wing v2 board configuration
 *
 * The v2 variant keeps the general layout of the original F405 Wing but
 * routes the RSSI input differently.  The battery voltage divider remains on
 * PC0 (ADC channel 10) and the current shunt on PC1 (ADC channel 11).
 * RSSI is available on PC2 (ADC channel 12).
 */

#ifndef CONFIG_MATEK_F405_WING_2_0_H
#define CONFIG_MATEK_F405_WING_2_0_H

#include "boards/matek_f405_wing_v1.h"

/* Remap RSSI ADC channel for the v2 hardware */
#undef AD1_3_CHANNEL
#undef ADC_3
#undef ADC_3_GPIO_PORT
#undef ADC_3_GPIO_PIN
#define AD1_3_CHANNEL 12
#define ADC_3 AD1_3
#define ADC_3_GPIO_PORT GPIOC
#define ADC_3_GPIO_PIN GPIO2

/* Default channel mapping (VBAT and current are unchanged) */
#undef ADC_CHANNEL_RSSI
#define ADC_CHANNEL_RSSI ADC_3

#endif /* CONFIG_MATEK_F405_WING_2_0_H */

