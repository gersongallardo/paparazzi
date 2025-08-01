#ifndef CONFIG_TAWAKI_2_00_H
#define CONFIG_TAWAKI_2_00_H

#define BOARD_TAWAKI_V2

/**
 * ChibiOS board file
 */
#include "board.h"

/**
 * PPRZ definitions
 */

/*
 * AHB_CLK
 */
#define AHB_CLK STM32_HCLK

/*
 * Concat macro
 */
#define _CONCAT_BOARD_PARAM(_s1, _s2) _s1 ## _s2
#define CONCAT_BOARD_PARAM(_s1, _s2) _CONCAT_BOARD_PARAM(_s1, _s2)

/*
 * LEDs
 */
/* red, on PD15, 1 on LED_ON, 0 on LED_OFF */
#ifndef USE_LED_1
#define USE_LED_1 1
#endif
#define LED_1_GPIO PAL_PORT(LINE_LED1)
#define LED_1_GPIO_PIN PAL_PAD(LINE_LED1)
#define LED_1_GPIO_ON gpio_set
#define LED_1_GPIO_OFF gpio_clear

/* orange, on PA10, 1 on LED_ON, 0 on LED_OFF */
#ifndef USE_LED_2
#define USE_LED_2 1
#endif
#define LED_2_GPIO PAL_PORT(LINE_LED2)
#define LED_2_GPIO_PIN PAL_PAD(LINE_LED2)
#define LED_2_GPIO_ON gpio_set
#define LED_2_GPIO_OFF gpio_clear

/* green, on PC7, 1 on LED_ON, 0 on LED_OFF */
#ifndef USE_LED_3
#define USE_LED_3 1
#endif
#define LED_3_GPIO PAL_PORT(LINE_LED3)
#define LED_3_GPIO_PIN PAL_PAD(LINE_LED3)
#define LED_3_GPIO_ON gpio_set
#define LED_3_GPIO_OFF gpio_clear

/* yellow, on PD10, 1 on LED_ON, 0 on LED_OFF */
#ifndef USE_LED_4
#define USE_LED_4 1
#endif
#define LED_4_GPIO PAL_PORT(LINE_LED4)
#define LED_4_GPIO_PIN PAL_PAD(LINE_LED4)
#define LED_4_GPIO_ON gpio_set
#define LED_4_GPIO_OFF gpio_clear

/*
 * ADCs
 */
// AUXa1
#if USE_ADC_1
#define AD1_1_CHANNEL CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, AUX_A1_ADC_INP)
#define ADC_1 AD1_1
#define ADC_1_GPIO_PORT PAL_PORT(LINE_AUX_A1)
#define ADC_1_GPIO_PIN PAL_PAD(LINE_AUX_A1)
#endif

// AUXa2
#if USE_ADC_2
#define AD1_2_CHANNEL CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, AUX_A2_ADC_INP)
#define ADC_2 AD1_2
#define ADC_2_GPIO_PORT PAL_PORT(LINE_AUX_A2)
#define ADC_2_GPIO_PIN PAL_PAD(LINE_AUX_A2)
#endif

// AUXa3
#if USE_ADC_3
#define AD1_3_CHANNEL CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, AUX_A3_ADC_INP)
#define ADC_3 AD1_3
#define ADC_3_GPIO_PORT PAL_PORT(LINE_AUX_A3)
#define ADC_3_GPIO_PIN PAL_PAD(LINE_AUX_A3)
#endif

// AUXa4
#if USE_ADC_4
#define AD1_4_CHANNEL CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, AUX_A4_ADC_INP)
#define ADC_4 AD1_4
#define ADC_4_GPIO_PORT PAL_PORT(LINE_AUX_A4)
#define ADC_4_GPIO_PIN PAL_PAD(LINE_AUX_A4)
#endif

// AUXb1
#if USE_ADC_5
#define AD1_5_CHANNEL CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, AUX_B1_ADC_IN)
#define ADC_5 AD1_5
#define ADC_5_GPIO_PORT PAL_PORT(LINE_AUX_B1)
#define ADC_5_GPIO_PIN PAL_PAD(LINE_AUX_B1)
#endif

// AUXb2
#if USE_ADC_6
#define AD1_6_CHANNEL CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, AUX_B2_ADC_IN)
#define ADC_6 AD1_6
#define ADC_6_GPIO_PORT PAL_PORT(LINE_AUX_B2)
#define ADC_6_GPIO_PIN PAL_PAD(LINE_AUX_B2)
#endif

// AUXb3
#if USE_ADC_7
#define AD1_7_CHANNEL CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, AUX_B3_ADC_IN)
#define ADC_7 AD1_7
#define ADC_7_GPIO_PORT PAL_PORT(LINE_AUX_B3)
#define ADC_7_GPIO_PIN PAL_PAD(LINE_AUX_B3)
#endif

// AUXb4
#if USE_ADC_8
#define AD1_8_CHANNEL CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, AUX_B4_ADC_IN)
#define ADC_8 AD1_8
#define ADC_8_GPIO_PORT PAL_PORT(LINE_AUX_B4)
#define ADC_8_GPIO_PIN PAL_PAD(LINE_AUX_B4)
#endif

// Internal ADC for battery enabled by default
#ifndef USE_ADC_9
#define USE_ADC_9 1
#endif
#if USE_ADC_9
#define AD1_9_CHANNEL CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, VBAT_MEAS_ADC_INP)
#define ADC_9 AD1_9
#define ADC_9_GPIO_PORT PAL_PORT(LINE_VBAT_MEAS)
#define ADC_9_GPIO_PIN PAL_PAD(LINE_VBAT_MEAS)
#endif

/* allow to define ADC_CHANNEL_VSUPPLY in the airframe file*/
#ifndef ADC_CHANNEL_VSUPPLY
#define ADC_CHANNEL_VSUPPLY ADC_9
#endif

/*
 * R1 = 2.2k
 * R2 = 12k
 * adc * (3.3 / 2^16) * ((R1 + R2) / R1)
 */
#define VBAT_R1 2200.0f
#define VBAT_R2 18000.0f
#define DefaultVoltageOfAdc(adc) ((3.3f/65536.0f)*((VBAT_R1+VBAT_R2)/VBAT_R1)*adc)

/*
 * PWM defines
 */

// SRVa connectors, activated in PWM mode by default

#ifndef USE_PWM1
#define USE_PWM1 1
#endif
#if USE_PWM1
#define PWM_SERVO_1 1
#define PWM_SERVO_1_GPIO PAL_PORT(LINE_SRVA1)
#define PWM_SERVO_1_PIN PAL_PAD(LINE_SRVA1)
#define PWM_SERVO_1_AF AF_SRVA1
#define PWM_SERVO_1_DRIVER CONCAT_BOARD_PARAM(PWMD, SRVA1_TIM)
#define PWM_SERVO_1_CHANNEL (SRVA1_TIM_CH-1)
#define PWM_SERVO_1_CONF CONCAT_BOARD_PARAM(pwmcfg, SRVA1_TIM)
#endif

#ifndef USE_PWM2
#define USE_PWM2 1
#endif
#if USE_PWM2
#define PWM_SERVO_2 2
#define PWM_SERVO_2_GPIO PAL_PORT(LINE_SRVA2)
#define PWM_SERVO_2_PIN PAL_PAD(LINE_SRVA2)
#define PWM_SERVO_2_AF AF_SRVA2
#define PWM_SERVO_2_DRIVER CONCAT_BOARD_PARAM(PWMD, SRVA2_TIM)
#define PWM_SERVO_2_CHANNEL (SRVA2_TIM_CH-1)
#define PWM_SERVO_2_CONF CONCAT_BOARD_PARAM(pwmcfg, SRVA2_TIM)
#endif

#ifndef USE_PWM3
#define USE_PWM3 1
#endif
#if USE_PWM3
#define PWM_SERVO_3 3
#define PWM_SERVO_3_GPIO PAL_PORT(LINE_SRVA3)
#define PWM_SERVO_3_PIN PAL_PAD(LINE_SRVA3)
#define PWM_SERVO_3_AF AF_SRVA3
#define PWM_SERVO_3_DRIVER CONCAT_BOARD_PARAM(PWMD, SRVA3_TIM)
#define PWM_SERVO_3_CHANNEL (SRVA3_TIM_CH-1)
#define PWM_SERVO_3_CONF CONCAT_BOARD_PARAM(pwmcfg, SRVA3_TIM)
#endif

#ifndef USE_PWM4
#define USE_PWM4 1
#endif
#if USE_PWM4
#define PWM_SERVO_4 4
#define PWM_SERVO_4_GPIO PAL_PORT(LINE_SRVA4)
#define PWM_SERVO_4_PIN PAL_PAD(LINE_SRVA4)
#define PWM_SERVO_4_AF AF_SRVA4
#define PWM_SERVO_4_DRIVER CONCAT_BOARD_PARAM(PWMD, SRVA4_TIM)
#define PWM_SERVO_4_CHANNEL (SRVA4_TIM_CH-1)
#define PWM_SERVO_4_CONF CONCAT_BOARD_PARAM(pwmcfg, SRVA4_TIM)
#endif

// SRVb connector, PWM mode disabled by default (DShot is enabled by default)

#ifndef USE_PWM5
#define USE_PWM5 0
#endif
#if USE_PWM5
#define PWM_SERVO_5 5
#define PWM_SERVO_5_GPIO PAL_PORT(LINE_SRVB1)
#define PWM_SERVO_5_PIN PAL_PAD(LINE_SRVB1)
#define PWM_SERVO_5_AF AF_SRVB1
#define PWM_SERVO_5_DRIVER CONCAT_BOARD_PARAM(PWMD, SRVB1_TIM)
#define PWM_SERVO_5_CHANNEL (SRVB1_TIM_CH-1)
#define PWM_SERVO_5_CONF CONCAT_BOARD_PARAM(pwmcfg, SRVB1_TIM)
#endif

#ifndef USE_PWM6
#define USE_PWM6 0
#endif
#if USE_PWM6
#define PWM_SERVO_6 6
#define PWM_SERVO_6_GPIO PAL_PORT(LINE_SRVB2)
#define PWM_SERVO_6_PIN PAL_PAD(LINE_SRVB2)
#define PWM_SERVO_6_AF AF_SRVB2
#define PWM_SERVO_6_DRIVER CONCAT_BOARD_PARAM(PWMD, SRVB2_TIM)
#define PWM_SERVO_6_CHANNEL (SRVB2_TIM_CH-1)
#define PWM_SERVO_6_CONF CONCAT_BOARD_PARAM(pwmcfg, SRVB2_TIM)
#endif

#ifndef USE_PWM7
#define USE_PWM7 0
#endif
#if USE_PWM7
#define PWM_SERVO_7 7
#define PWM_SERVO_7_GPIO PAL_PORT(LINE_SRVB3)
#define PWM_SERVO_7_PIN PAL_PAD(LINE_SRVB3)
#define PWM_SERVO_7_AF AF_SRVB3
#define PWM_SERVO_7_DRIVER CONCAT_BOARD_PARAM(PWMD, SRVB3_TIM)
#define PWM_SERVO_7_CHANNEL (SRVB3_TIM_CH-1)
#define PWM_SERVO_7_CONF CONCAT_BOARD_PARAM(pwmcfg, SRVB3_TIM)
#endif

#ifndef USE_PWM8
#define USE_PWM8 0
#endif
#if USE_PWM8
#define PWM_SERVO_8 8
#define PWM_SERVO_8_GPIO PAL_PORT(LINE_SRVB4)
#define PWM_SERVO_8_PIN PAL_PAD(LINE_SRVB4)
#define PWM_SERVO_8_AF AF_SRVB4
#define PWM_SERVO_8_DRIVER CONCAT_BOARD_PARAM(PWMD, SRVB4_TIM)
#define PWM_SERVO_8_CHANNEL (SRVB4_TIM_CH-1)
#define PWM_SERVO_8_CONF CONCAT_BOARD_PARAM(pwmcfg, SRVB4_TIM)
#endif

#ifndef USE_PWM9
#define USE_PWM9 0
#endif
#if USE_PWM9
#define PWM_SERVO_9 9
#define PWM_SERVO_9_GPIO PAL_PORT(LINE_AUX_A1)
#define PWM_SERVO_9_PIN PAL_PAD(LINE_AUX_A1)
#define PWM_SERVO_9_AF GPIO_AF2
#define PWM_SERVO_9_DRIVER CONCAT_BOARD_PARAM(PWMD, AUX_A1_TIM)
#define PWM_SERVO_9_CHANNEL (AUX_A1_TIM_CH-1)
#define PWM_SERVO_9_CONF CONCAT_BOARD_PARAM(pwmcfg, AUX_A1_TIM)
#endif

#ifndef USE_PWM10
#define USE_PWM10 0
#endif
#if USE_PWM10
#define PWM_SERVO_10 10
#define PWM_SERVO_10_GPIO PAL_PORT(LINE_AUX_A2)
#define PWM_SERVO_10_PIN PAL_PAD(LINE_AUX_A2)
#define PWM_SERVO_10_AF GPIO_AF2
#define PWM_SERVO_10_DRIVER CONCAT_BOARD_PARAM(PWMD, AUX_A2_TIM)
#define PWM_SERVO_10_CHANNEL (AUX_A2_TIM_CH-1)
#define PWM_SERVO_10_CONF CONCAT_BOARD_PARAM(pwmcfg, AUX_A2_TIM)
#endif

#ifndef USE_PWM11
#define USE_PWM11 0
#endif
#if USE_PWM11
#define PWM_SERVO_11 11
#define PWM_SERVO_11_GPIO PAL_PORT(LINE_AUX_A3)
#define PWM_SERVO_11_PIN PAL_PAD(LINE_AUX_A3)
#define PWM_SERVO_11_AF GPIO_AF2
#define PWM_SERVO_11_DRIVER CONCAT_BOARD_PARAM(PWMD, AUX_A3_TIM)
#define PWM_SERVO_11_CHANNEL (AUX_A3_TIM_CH-1)
#define PWM_SERVO_11_CONF CONCAT_BOARD_PARAM(pwmcfg, AUX_A3_TIM)
#endif

#ifndef USE_PWM12
#define USE_PWM12 0
#endif
#if USE_PWM12
#define PWM_SERVO_12 12
#define PWM_SERVO_12_GPIO PAL_PORT(LINE_AUX_A4)
#define PWM_SERVO_12_PIN PAL_PAD(LINE_AUX_A4)
#define PWM_SERVO_12_AF GPIO_AF2
#define PWM_SERVO_12_DRIVER CONCAT_BOARD_PARAM(PWMD, AUX_A4_TIM)
#define PWM_SERVO_12_CHANNEL (AUX_A4_TIM_CH-1)
#define PWM_SERVO_12_CONF CONCAT_BOARD_PARAM(pwmcfg, AUX_A4_TIM)
#endif

#ifndef USE_PWM13
#define USE_PWM13 0
#endif
#if USE_PWM13
#define PWM_SERVO_13 13
#define PWM_SERVO_13_GPIO PAL_PORT(LINE_AUX_B1)
#define PWM_SERVO_13_PIN PAL_PAD(LINE_AUX_B1)
#define PWM_SERVO_13_AF GPIO_AF2
#define PWM_SERVO_13_DRIVER CONCAT_BOARD_PARAM(PWMD, AUX_B1_TIM)
#define PWM_SERVO_13_CHANNEL (AUX_B1_TIM_CH-1)
#define PWM_SERVO_13_CONF CONCAT_BOARD_PARAM(pwmcfg, AUX_B1_TIM)
#endif

#ifndef USE_PWM14
#define USE_PWM14 0
#endif
#if USE_PWM14
#define PWM_SERVO_14 14
#define PWM_SERVO_14_GPIO PAL_PORT(LINE_AUX_B2)
#define PWM_SERVO_14_PIN PAL_PAD(LINE_AUX_B2)
#define PWM_SERVO_14_AF GPIO_AF2
#define PWM_SERVO_14_DRIVER CONCAT_BOARD_PARAM(PWMD, AUX_B2_TIM)
#define PWM_SERVO_14_CHANNEL (AUX_B2_TIM_CH-1)
#define PWM_SERVO_14_CONF CONCAT_BOARD_PARAM(pwmcfg, AUX_B2_TIM)
#endif

#ifndef USE_PWM15
#define USE_PWM15 0
#endif
#if USE_PWM15
#define PWM_SERVO_15 15
#define PWM_SERVO_15_GPIO PAL_PORT(LINE_AUX_B3)
#define PWM_SERVO_15_PIN PAL_PAD(LINE_AUX_B3)
#define PWM_SERVO_15_AF GPIO_AF2
#define PWM_SERVO_15_DRIVER CONCAT_BOARD_PARAM(PWMD, AUX_B3_TIM)
#define PWM_SERVO_15_CHANNEL (AUX_B3_TIM_CH-1)
#define PWM_SERVO_15_CONF CONCAT_BOARD_PARAM(pwmcfg, AUX_B3_TIM)
#endif

#ifndef USE_PWM16
#define USE_PWM16 0
#endif
#if USE_PWM16
#define PWM_SERVO_16 16
#define PWM_SERVO_16_GPIO PAL_PORT(LINE_AUX_B4)
#define PWM_SERVO_16_PIN PAL_PAD(LINE_AUX_B4)
#define PWM_SERVO_16_AF GPIO_AF2
#define PWM_SERVO_16_DRIVER CONCAT_BOARD_PARAM(PWMD, AUX_B4_TIM)
#define PWM_SERVO_16_CHANNEL (AUX_B4_TIM_CH-1)
#define PWM_SERVO_16_CONF CONCAT_BOARD_PARAM(pwmcfg, AUX_B4_TIM)
#endif

// servo index starting at 1 + regular servos + aux servos
// so NB = 1+8+8
#define ACTUATORS_PWM_NB 17


/**
 * DSHOT
 */
#ifdef DSHOT_TIM3_TELEMETRY_NUM
#define DSHOT_TIM3_TELEMETRY_DEV CONCAT_BOARD_PARAM(&SD, DSHOT_TIM3_TELEMETRY_NUM)
#else
#define DSHOT_TIM3_TELEMETRY_DEV NULL
#endif

#ifdef DSHOT_TIM1_TELEMETRY_NUM
#define DSHOT_TIM1_TELEMETRY_DEV CONCAT_BOARD_PARAM(&SD, DSHOT_TIM1_TELEMETRY_NUM)
#else
#define DSHOT_TIM1_TELEMETRY_DEV NULL
#endif

// macros for possible dshot telemetry
#define DSHOT_TLM_RX 1
#define DSHOT_TLM_AUX_RX 4

#ifndef USE_DSHOT_TIM3
#define USE_DSHOT_TIM3 1 // use SRVb for DShot by default
#endif




#if USE_DSHOT_TIM3 // Servo B1, B2, B3, B4 on TIM4

// Servo B1, B2, B3, B4 on TM4 are primary DSHOT connector
#define DSHOT_SERVO_1 1
#define DSHOT_SERVO_1_GPIO PAL_PORT(LINE_SRVB1)
#define DSHOT_SERVO_1_PIN PAL_PAD(LINE_SRVB1)
#define DSHOT_SERVO_1_AF AF_SRVB1
#define DSHOT_SERVO_1_DRIVER CONCAT_BOARD_PARAM(DSHOTD, SRVB1_TIM)
#define DSHOT_SERVO_1_CHANNEL SRVB1_TIM_CH

#define DSHOT_SERVO_2 2
#define DSHOT_SERVO_2_GPIO PAL_PORT(LINE_SRVB2)
#define DSHOT_SERVO_2_PIN PAL_PAD(LINE_SRVB2)
#define DSHOT_SERVO_2_AF AF_SRVB2
#define DSHOT_SERVO_2_DRIVER CONCAT_BOARD_PARAM(DSHOTD, SRVB2_TIM)
#define DSHOT_SERVO_2_CHANNEL SRVB2_TIM_CH

#define DSHOT_SERVO_3 3
#define DSHOT_SERVO_3_GPIO PAL_PORT(LINE_SRVB3)
#define DSHOT_SERVO_3_PIN PAL_PAD(LINE_SRVB3)
#define DSHOT_SERVO_3_AF AF_SRVB3
#define DSHOT_SERVO_3_DRIVER CONCAT_BOARD_PARAM(DSHOTD, SRVB3_TIM)
#define DSHOT_SERVO_3_CHANNEL SRVB3_TIM_CH

#define DSHOT_SERVO_4 4
#define DSHOT_SERVO_4_GPIO PAL_PORT(LINE_SRVB4)
#define DSHOT_SERVO_4_PIN PAL_PAD(LINE_SRVB4)
#define DSHOT_SERVO_4_AF AF_SRVB4
#define DSHOT_SERVO_4_DRIVER CONCAT_BOARD_PARAM(DSHOTD, SRVB4_TIM)
#define DSHOT_SERVO_4_CHANNEL SRVB4_TIM_CH

#define DSHOT_CONF_TIM3 1


#if DSHOT_BIDIR

#define DSHOT_CAPT_CONF3_DEF                     \
  .dma_capt_cfg = {                              \
    .gptd = &DSHOT1_BIDIR_GPT,                \
    .dma_streams = {DSHOTS_CAPTURE_STREAMS(3)},  \
    .dma_capture = &dshot3DmaCaptureBuffer,      \
    .dcache_memory_in_use = false,               \
  },
#else
#define DSHOT_CAPT_CONF3_DEF
#endif

#define DSHOT_CONF3_DEF {                 \
  .dma_stream = STM32_DMA_STREAM_ID_ANY,  \
  .dmamux = STM32_DMAMUX1_TIM3_UP,        \
  .pwmp = &PWMD3,                         \
  .tlm_sd = DSHOT_TIM3_TELEMETRY_DEV,     \
  .dma_buf = &dshot3DmaBuffer,            \
  DSHOT_CAPT_CONF3_DEF                    \
  .dcache_memory_in_use = false           \
}

#endif

#if USE_DSHOT_TIM1 // Servo A1, A2, A3, A4 on TIM1 only activated if needed

#define DSHOT_SERVO_5 5
#define DSHOT_SERVO_5_GPIO PAL_PORT(LINE_SRVA1)
#define DSHOT_SERVO_5_PIN PAL_PAD(LINE_SRVA1)
#define DSHOT_SERVO_5_AF AF_SRVA1
#define DSHOT_SERVO_5_DRIVER CONCAT_BOARD_PARAM(DSHOTD, SRVA1_TIM)
#define DSHOT_SERVO_5_CHANNEL SRVA1_TIM_CH

#define DSHOT_SERVO_6 6
#define DSHOT_SERVO_6_GPIO PAL_PORT(LINE_SRVA2)
#define DSHOT_SERVO_6_PIN PAL_PAD(LINE_SRVA2)
#define DSHOT_SERVO_6_AF AF_SRVA2
#define DSHOT_SERVO_6_DRIVER CONCAT_BOARD_PARAM(DSHOTD, SRVA2_TIM)
#define DSHOT_SERVO_6_CHANNEL SRVA2_TIM_CH

#define DSHOT_SERVO_7 7
#define DSHOT_SERVO_7_GPIO PAL_PORT(LINE_SRVA3)
#define DSHOT_SERVO_7_PIN PAL_PAD(LINE_SRVA3)
#define DSHOT_SERVO_7_AF AF_SRVA3
#define DSHOT_SERVO_7_DRIVER CONCAT_BOARD_PARAM(DSHOTD, SRVA3_TIM)
#define DSHOT_SERVO_7_CHANNEL SRVA3_TIM_CH

#define DSHOT_SERVO_8 8
#define DSHOT_SERVO_8_GPIO PAL_PORT(LINE_SRVA4)
#define DSHOT_SERVO_8_PIN PAL_PAD(LINE_SRVA4)
#define DSHOT_SERVO_8_AF AF_SRVA4
#define DSHOT_SERVO_8_DRIVER CONCAT_BOARD_PARAM(DSHOTD, SRVA4_TIM)
#define DSHOT_SERVO_8_CHANNEL SRVA4_TIM_CH

#define DSHOT_CONF_TIM1 1

#if DSHOT_BIDIR
#ifndef DSHOT2_BIDIR_GPT
#error "Select and activate DSHOT2_BIDIR_GPT for DSHOT_CONF1. Example: USE_GPT8=TRUE, DSHOT2_BIDIR_GPT=GPTD8"
#endif
#define DSHOT_CAPT_CONF1_DEF                     \
  .dma_capt_cfg = {                              \
    .gptd = &DSHOT2_BIDIR_GPT,                   \
    .dma_streams = {DSHOTS_CAPTURE_STREAMS(1)},  \
    .dma_capture = &dshot1DmaCaptureBuffer,      \
    .dcache_memory_in_use = false,               \
  },
#else
#define DSHOT_CAPT_CONF1_DEF
#endif

#define DSHOT_CONF1_DEF {                 \
  .dma_stream = STM32_DMA_STREAM_ID_ANY,  \
  .dmamux = STM32_DMAMUX1_TIM1_UP,        \
  .pwmp = &PWMD1,                         \
  .tlm_sd = DSHOT_TIM1_TELEMETRY_DEV,     \
  .dma_buf = &dshot1DmaBuffer,        \
  DSHOT_CAPT_CONF1_DEF                    \
  .dcache_memory_in_use = false           \
}

#endif

/**
 * UART2 (Modem with optional flow control on AUXa disabled by default)
 */
#define UART2_GPIO_PORT_TX  PAL_PORT(LINE_UART2_TX)
#define UART2_GPIO_TX       PAL_PAD(LINE_UART2_TX)
#define UART2_GPIO_PORT_RX  PAL_PORT(LINE_UART2_RX)
#define UART2_GPIO_RX       PAL_PAD(LINE_UART2_RX)
#define UART2_GPIO_AF       AF_UART2_TX
#ifndef UART2_HW_FLOW_CONTROL
#define UART2_HW_FLOW_CONTROL FALSE
#endif

/**
 * UART7 (GPS) and UART3 (Companion)
 * are configured as UART from ChibiOS board file by default
 */

#define UART3_GPIO_PORT_TX  PAL_PORT(LINE_UART3_TX)
#define UART3_GPIO_TX       PAL_PAD(LINE_UART3_TX)
#define UART3_GPIO_PORT_RX  PAL_PORT(LINE_UART3_RX)
#define UART3_GPIO_RX       PAL_PAD(LINE_UART3_RX)
#define UART3_GPIO_AF       AF_UART3_TX

#define UART7_GPIO_PORT_TX  PAL_PORT(LINE_UART7_TX)
#define UART7_GPIO_TX       PAL_PAD(LINE_UART7_TX)
#define UART7_GPIO_PORT_RX  PAL_PORT(LINE_UART7_RX)
#define UART7_GPIO_RX       PAL_PAD(LINE_UART7_RX)
#define UART7_GPIO_AF       AF_UART7_TX

/**
 * UART4 on AUXa (not configured by default)
 */

#define UART4_GPIO_PORT_TX  PAL_PORT(LINE_AUX_A1)
#define UART4_GPIO_TX       PAL_PAD(LINE_AUX_A1)
#define UART4_GPIO_PORT_RX  PAL_PORT(LINE_AUX_A2)
#define UART4_GPIO_RX       PAL_PAD(LINE_AUX_A2)
#define UART4_GPIO_AF       AUX_A1_UART_AF

/**
 * UART1 on SRVB (DSHOT telemetry)
 */

#define UART1_GPIO_PORT_RX  PAL_PORT(LINE_DSHOT_RX)
#define UART1_GPIO_RX       PAL_PAD(LINE_DSHOT_RX)
#define UART1_GPIO_AF       AF_DSHOT_RX

/**
 * SBUS / Spektrum port
 *
 * Recommended config:
 *
 * primary SBUS port is UART8, a.k.a. RC1 on Tawaki board
 * secondary port (in dual driver) is UART6, a.k.a. RC2 on Tawaki board
 *
 * primary Spektrum port is UART6, a.k.a. RC2 on Tawaki board
 * secondary port is UART8, a.k.a. RC1 on Tawaki board
 */

// In case, do dynamic config of UARTs
#ifndef USE_UART8_RX
#define USE_UART8_RX TRUE
#endif
#ifndef USE_UART8_TX // may be used in half duplex mode
#define USE_UART8_TX FALSE
#endif
// Tx and Rx are configured on the same pin, only one of them should be used
#define UART8_GPIO_PORT_TX  PAL_PORT(LINE_RC1)
#define UART8_GPIO_TX       PAL_PAD(LINE_RC1)
#define UART8_GPIO_PORT_RX  PAL_PORT(LINE_RC1)
#define UART8_GPIO_RX       PAL_PAD(LINE_RC1)
#define UART8_GPIO_AF       RC1_UART_AF

#ifndef USE_UART6_RX
#define USE_UART6_RX FALSE
#endif
#ifndef USE_UART6_TX
#define USE_UART6_TX TRUE
#endif
// Tx and Rx are configured on the same pin, only one of them should be used
#define UART6_GPIO_PORT_TX  PAL_PORT(LINE_RC2)
#define UART6_GPIO_TX       PAL_PAD(LINE_RC2)
#define UART6_GPIO_PORT_RX  PAL_PORT(LINE_RC2)
#define UART6_GPIO_RX       PAL_PAD(LINE_RC2)
#define UART6_GPIO_AF       RC2_USART_AF

/* The line that is pulled low at power up to initiate the bind process
 * PB1: AUXb4
 */
#define SPEKTRUM_BIND_PIN       PAL_PORT(LINE_AUX_B4)
#define SPEKTRUM_BIND_PIN_PORT  PAL_PAD(LINE_AUX_B4)

// no wait with chibios as the RTC oscillator takes longer to stabilize
#define SPEKTRUM_BIND_WAIT 30000

/**
 * PPM radio defines
 *
 * available on RC2
 */
#define RC_PPM_TICKS_PER_USEC 6
#define PPM_TIMER_FREQUENCY 6000000
#define PPM_CHANNEL CONCAT_BOARD_PARAM(ICU_CHANNEL_, RC2_TIM_CH)
#define PPM_TIMER CONCAT_BOARD_PARAM(ICUD, RC2_TIM)

/*
 * PWM input
 */
// PWM_INPUT 1 on PA0 (AUXa1)
#define PWM_INPUT1_ICU            ICUD2
#define PWM_INPUT1_CHANNEL        ICU_CHANNEL_1
#define PWM_INPUT1_GPIO_PORT      PAL_PORT(LINE_AUX_A1)
#define PWM_INPUT1_GPIO_PIN       PAL_PAD(LINE_AUX_A1)
#define PWM_INPUT1_GPIO_AF        GPIO_AF1

// PWM_INPUT 2 on PA1 (AUXa2)
#define PWM_INPUT2_ICU            ICUD5
#define PWM_INPUT2_CHANNEL        ICU_CHANNEL_2
#define PWM_INPUT2_GPIO_PORT      PAL_PORT(LINE_AUX_A2)
#define PWM_INPUT2_GPIO_PIN       PAL_PAD(LINE_AUX_A2)
#define PWM_INPUT2_GPIO_AF        GPIO_AF2

/**
 * I2C defines
 */
// Digital noise filter: 0 disabled, [0x1 - 0xF] enable up to n t_I2CCLK
#define STM32_CR1_DNF(n)          ((n & 0x0f) << 8)
// Timing register
#define I2C_FAST_400KHZ_DNF0_100NS_PCLK120MHZ_TIMINGR  (STM32_TIMINGR_PRESC(0U) | \
    STM32_TIMINGR_SCLDEL(11U) | STM32_TIMINGR_SDADEL(0U) | \
    STM32_TIMINGR_SCLH(63U)  | STM32_TIMINGR_SCLL(219U))
#define I2C_STD_100KHZ_DNF0_100NS_PCLK120MHZ_TIMINGR  (STM32_TIMINGR_PRESC(3U) | \
    STM32_TIMINGR_SCLDEL(7U) | STM32_TIMINGR_SDADEL(0U) | \
    STM32_TIMINGR_SCLH(117U)  | STM32_TIMINGR_SCLL(177U))


// Internal I2C (baro, magneto)

#ifndef I2C4_CLOCK_SPEED
#define I2C4_CLOCK_SPEED 400000
#endif

#if I2C4_CLOCK_SPEED == 400000
#define I2C4_CFG_DEF { \
  .timingr = I2C_FAST_400KHZ_DNF0_100NS_PCLK120MHZ_TIMINGR, \
  .cr1 = STM32_CR1_DNF(0), \
  .cr2 = 0 \
}
#elif I2C4_CLOCK_SPEED == 100000
#define I2C4_CFG_DEF { \
  .timingr = I2C_STD_100KHZ_DNF0_100NS_PCLK120MHZ_TIMINGR, \
  .cr1 = STM32_CR1_DNF(0), \
  .cr2 = 0 \
}
#else
#error "Unknown I2C4 clock speed"
#endif

// External I2C

#ifndef I2C2_CLOCK_SPEED
#define I2C2_CLOCK_SPEED 400000
#endif

#if I2C2_CLOCK_SPEED == 400000
#define I2C2_CFG_DEF { \
  .timingr = I2C_FAST_400KHZ_DNF0_100NS_PCLK120MHZ_TIMINGR, \
  .cr1 = STM32_CR1_DNF(0), \
  .cr2 = 0 \
}
#elif I2C2_CLOCK_SPEED == 100000
#define I2C2_CFG_DEF { \
  .timingr = I2C_STD_100KHZ_DNF0_100NS_PCLK120MHZ_TIMINGR, \
  .cr1 = STM32_CR1_DNF(0), \
  .cr2 = 0 \
}
#else
#error "Unknown I2C2 clock speed"
#endif

/**
 * SPI Config
 */

// Internal SPI (IMU)
#define SPI6_GPIO_AF          AF_SPI6_INTERNAL_CLK
#define SPI6_GPIO_PORT_MISO   PAL_PORT(LINE_SPI6_INTERNAL_MISO)
#define SPI6_GPIO_MISO        PAL_PAD(LINE_SPI6_INTERNAL_MISO)
#define SPI6_GPIO_PORT_MOSI   PAL_PORT(LINE_SPI6_INTERNAL_MOSI)
#define SPI6_GPIO_MOSI        PAL_PAD(LINE_SPI6_INTERNAL_MOSI)
#define SPI6_GPIO_PORT_SCK    PAL_PORT(LINE_SPI6_INTERNAL_CLK)
#define SPI6_GPIO_SCK         PAL_PAD(LINE_SPI6_INTERNAL_CLK)

// External SPI
#define SPI2_GPIO_AF          AF_SPI2_EXTERNAL_CLK
#define SPI2_GPIO_PORT_MISO   PAL_PORT(LINE_SPI2_EXTERNAL_MISO)
#define SPI2_GPIO_MISO        PAL_PAD(LINE_SPI2_EXTERNAL_MISO)
#define SPI2_GPIO_PORT_MOSI   PAL_PORT(LINE_SPI2_EXTERNAL_MOSI)
#define SPI2_GPIO_MOSI        PAL_PAD(LINE_SPI2_EXTERNAL_MOSI)
#define SPI2_GPIO_PORT_SCK    PAL_PORT(LINE_SPI2_EXTERNAL_CLK)
#define SPI2_GPIO_SCK         PAL_PAD(LINE_SPI2_EXTERNAL_CLK)

// SLAVE0 on SPI connector (NSS possible)
#define SPI_SELECT_SLAVE0_PORT  PAL_PORT(LINE_SPI2_EXTERNAL_CS)
#define SPI_SELECT_SLAVE0_PIN   PAL_PAD(LINE_SPI2_EXTERNAL_CS)
// SLAVE1 on AUXb1
#define SPI_SELECT_SLAVE1_PORT  PAL_PORT(LINE_AUX_B1)
#define SPI_SELECT_SLAVE1_PIN   PAL_PAD(LINE_AUX_B1)
// SLAVE2 on AUXb2
#define SPI_SELECT_SLAVE2_PORT  PAL_PORT(LINE_AUX_B2)
#define SPI_SELECT_SLAVE2_PIN   PAL_PAD(LINE_AUX_B2)
// SLAVE3 on AUXb3
#define SPI_SELECT_SLAVE3_PORT  PAL_PORT(LINE_AUX_B3)
#define SPI_SELECT_SLAVE3_PIN   PAL_PAD(LINE_AUX_B3)
// SLAVE4 on AUXb4
#define SPI_SELECT_SLAVE4_PORT  PAL_PORT(LINE_AUX_B4)
#define SPI_SELECT_SLAVE4_PIN   PAL_PAD(LINE_AUX_B4)
// SLAVE5 on PE4 (internal IMU)
#define SPI_SELECT_SLAVE5_PORT  PAL_PORT(LINE_SPI6_INTERNAL_CS)
#define SPI_SELECT_SLAVE5_PIN   PAL_PAD(LINE_SPI6_INTERNAL_CS)

/**
 * Baro
 *
 * Apparently needed for backwards compatibility
 * with the ancient onboard baro boards
 */
#ifndef USE_BARO_BOARD
#define USE_BARO_BOARD 0
#endif

/**
 * SDIO
 */
#define SDIO_D0_PORT  PAL_PORT(LINE_SDMMC1_D0)
#define SDIO_D0_PIN   PAL_PAD(LINE_SDMMC1_D0)
#define SDIO_D1_PORT  PAL_PORT(LINE_SDMMC1_D1)
#define SDIO_D1_PIN   PAL_PAD(LINE_SDMMC1_D1)
#define SDIO_D2_PORT  PAL_PORT(LINE_SDMMC1_D2)
#define SDIO_D2_PIN   PAL_PAD(LINE_SDMMC1_D2)
#define SDIO_D3_PORT  PAL_PORT(LINE_SDMMC1_D3)
#define SDIO_D3_PIN   PAL_PAD(LINE_SDMMC1_D3)
#define SDIO_CK_PORT  PAL_PORT(LINE_SDMMC1_CK)
#define SDIO_CK_PIN   PAL_PAD(LINE_SDMMC1_CK)
#define SDIO_CMD_PORT PAL_PORT(LINE_SDMMC1_CMD)
#define SDIO_CMD_PIN  PAL_PAD(LINE_SDMMC1_CMD)
#define SDIO_AF       AF_SDMMC1_CK
// bat monitoring for file closing
#define SDLOG_BAT_ADC CONCAT_BOARD_PARAM(ADCD, VBAT_MEAS_ADC)
#define SDLOG_BAT_CHAN CONCAT_BOARD_PARAM(ADC_CHANNEL_IN, VBAT_MEAS_ADC_INP)
// usb led status
#define SDLOG_USB_LED 4
#define SDLOG_USB_VBUS_PORT PAL_PORT(LINE_USB_VBUS)
#define SDLOG_USB_VBUS_PIN  PAL_PAD(LINE_USB_VBUS)


/*
 * Actuators for fixedwing
 */
 /* Default actuators driver */
#define DEFAULT_ACTUATORS "modules/actuators/actuators_pwm.h"
#define ActuatorDefaultSet(_x,_y) ActuatorPwmSet(_x,_y)
#define ActuatorsDefaultInit() ActuatorsPwmInit()
#define ActuatorsDefaultCommit() ActuatorsPwmCommit()

/**
 * For WS2812
 */
#define WS2812D1_GPIO PAL_PORT(LINE_AUX_A1)
#define WS2812D1_PIN  PAL_PAD(LINE_AUX_A1)
#define WS2812D1_AF 2
#define WS2812D1_CFG_DEF { \
  .dma_stream = STM32_DMA_STREAM_ID_ANY, \
  .dmamux = STM32_DMAMUX1_TIM5_UP,          \
  .dma_priority = STM32_PWM5_UP_DMA_PRIORITY, \
  .pwm_channel = 0, \
  .pwmp = &PWMD5 \
}

#endif /* CONFIG_TAWAKI_2_00_H */

