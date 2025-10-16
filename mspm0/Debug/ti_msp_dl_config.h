/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define GPIO_HFXT_PORT                                                     GPIOA
#define GPIO_HFXIN_PIN                                             DL_GPIO_PIN_5
#define GPIO_HFXIN_IOMUX                                         (IOMUX_PINCM10)
#define GPIO_HFXOUT_PIN                                            DL_GPIO_PIN_6
#define GPIO_HFXOUT_IOMUX                                        (IOMUX_PINCM11)
#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_0 */
#define PWM_0_INST                                                         TIMA1
#define PWM_0_INST_IRQHandler                                   TIMA1_IRQHandler
#define PWM_0_INST_INT_IRQN                                     (TIMA1_INT_IRQn)
#define PWM_0_INST_CLK_FREQ                                             10000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_0_C0_PORT                                                 GPIOA
#define GPIO_PWM_0_C0_PIN                                         DL_GPIO_PIN_17
#define GPIO_PWM_0_C0_IOMUX                                      (IOMUX_PINCM39)
#define GPIO_PWM_0_C0_IOMUX_FUNC                     IOMUX_PINCM39_PF_TIMA1_CCP0
#define GPIO_PWM_0_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_0_C1_PORT                                                 GPIOA
#define GPIO_PWM_0_C1_PIN                                         DL_GPIO_PIN_16
#define GPIO_PWM_0_C1_IOMUX                                      (IOMUX_PINCM38)
#define GPIO_PWM_0_C1_IOMUX_FUNC                     IOMUX_PINCM38_PF_TIMA1_CCP1
#define GPIO_PWM_0_C1_IDX                                    DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                         (19999U)



/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_FREQUENCY                                           40000000
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_40_MHZ_115200_BAUD                                      (21)
#define UART_0_FBRD_40_MHZ_115200_BAUD                                      (45)





/* Port definition for Pin Group LED1 */
#define LED1_PORT                                                        (GPIOB)

/* Defines for PIN_22: GPIOB.22 with pinCMx 50 on package pin 21 */
#define LED1_PIN_22_PIN                                         (DL_GPIO_PIN_22)
#define LED1_PIN_22_IOMUX                                        (IOMUX_PINCM50)
/* Port definition for Pin Group ENCODER1A */
#define ENCODER1A_PORT                                                   (GPIOA)

/* Defines for A1: GPIOA.21 with pinCMx 46 on package pin 17 */
// groups represented: ["KEY","ENCODER1A"]
// pins affected: ["KEY1","KEY2","KEY3","KEY4","A1"]
#define GPIO_MULTIPLE_GPIOA_INT_IRQN                            (GPIOA_INT_IRQn)
#define GPIO_MULTIPLE_GPIOA_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define ENCODER1A_A1_IIDX                                   (DL_GPIO_IIDX_DIO21)
#define ENCODER1A_A1_PIN                                        (DL_GPIO_PIN_21)
#define ENCODER1A_A1_IOMUX                                       (IOMUX_PINCM46)
/* Port definition for Pin Group ENCODER1B */
#define ENCODER1B_PORT                                                   (GPIOB)

/* Defines for B1: GPIOB.18 with pinCMx 44 on package pin 15 */
#define ENCODER1B_B1_PIN                                        (DL_GPIO_PIN_18)
#define ENCODER1B_B1_IOMUX                                       (IOMUX_PINCM44)
/* Port definition for Pin Group ENCODER2A */
#define ENCODER2A_PORT                                                   (GPIOB)

/* Defines for A2: GPIOB.23 with pinCMx 51 on package pin 22 */
// groups represented: ["KEY","ENCODER2A"]
// pins affected: ["KEY5","KEY6","A2"]
#define GPIO_MULTIPLE_GPIOB_INT_IRQN                            (GPIOB_INT_IRQn)
#define GPIO_MULTIPLE_GPIOB_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define ENCODER2A_A2_IIDX                                   (DL_GPIO_IIDX_DIO23)
#define ENCODER2A_A2_PIN                                        (DL_GPIO_PIN_23)
#define ENCODER2A_A2_IOMUX                                       (IOMUX_PINCM51)
/* Port definition for Pin Group ENCODER2B */
#define ENCODER2B_PORT                                                   (GPIOB)

/* Defines for B2: GPIOB.26 with pinCMx 57 on package pin 28 */
#define ENCODER2B_B2_PIN                                        (DL_GPIO_PIN_26)
#define ENCODER2B_B2_IOMUX                                       (IOMUX_PINCM57)
/* Port definition for Pin Group TB6612 */
#define TB6612_PORT                                                      (GPIOA)

/* Defines for AIN1: GPIOA.14 with pinCMx 36 on package pin 7 */
#define TB6612_AIN1_PIN                                         (DL_GPIO_PIN_14)
#define TB6612_AIN1_IOMUX                                        (IOMUX_PINCM36)
/* Defines for AIN2: GPIOA.15 with pinCMx 37 on package pin 8 */
#define TB6612_AIN2_PIN                                         (DL_GPIO_PIN_15)
#define TB6612_AIN2_IOMUX                                        (IOMUX_PINCM37)
/* Defines for BIN1: GPIOA.12 with pinCMx 34 on package pin 5 */
#define TB6612_BIN1_PIN                                         (DL_GPIO_PIN_12)
#define TB6612_BIN1_IOMUX                                        (IOMUX_PINCM34)
/* Defines for BIN2: GPIOA.13 with pinCMx 35 on package pin 6 */
#define TB6612_BIN2_PIN                                         (DL_GPIO_PIN_13)
#define TB6612_BIN2_IOMUX                                        (IOMUX_PINCM35)
/* Port definition for Pin Group SENSOR */
#define SENSOR_PORT                                                      (GPIOA)

/* Defines for A: GPIOA.24 with pinCMx 54 on package pin 25 */
#define SENSOR_A_PIN                                            (DL_GPIO_PIN_24)
#define SENSOR_A_IOMUX                                           (IOMUX_PINCM54)
/* Defines for B: GPIOA.25 with pinCMx 55 on package pin 26 */
#define SENSOR_B_PIN                                            (DL_GPIO_PIN_25)
#define SENSOR_B_IOMUX                                           (IOMUX_PINCM55)
/* Defines for C: GPIOA.26 with pinCMx 59 on package pin 30 */
#define SENSOR_C_PIN                                            (DL_GPIO_PIN_26)
#define SENSOR_C_IOMUX                                           (IOMUX_PINCM59)
/* Defines for D: GPIOA.27 with pinCMx 60 on package pin 31 */
#define SENSOR_D_PIN                                            (DL_GPIO_PIN_27)
#define SENSOR_D_IOMUX                                           (IOMUX_PINCM60)
/* Defines for E: GPIOA.22 with pinCMx 47 on package pin 18 */
#define SENSOR_E_PIN                                            (DL_GPIO_PIN_22)
#define SENSOR_E_IOMUX                                           (IOMUX_PINCM47)
/* Port definition for Pin Group SENSOR2 */
#define SENSOR2_PORT                                                     (GPIOB)

/* Defines for L: GPIOB.24 with pinCMx 52 on package pin 23 */
#define SENSOR2_L_PIN                                           (DL_GPIO_PIN_24)
#define SENSOR2_L_IOMUX                                          (IOMUX_PINCM52)
/* Defines for R: GPIOB.25 with pinCMx 56 on package pin 27 */
#define SENSOR2_R_PIN                                           (DL_GPIO_PIN_25)
#define SENSOR2_R_IOMUX                                          (IOMUX_PINCM56)
/* Defines for KEY1: GPIOA.28 with pinCMx 3 on package pin 35 */
#define KEY_KEY1_PORT                                                    (GPIOA)
#define KEY_KEY1_IIDX                                       (DL_GPIO_IIDX_DIO28)
#define KEY_KEY1_PIN                                            (DL_GPIO_PIN_28)
#define KEY_KEY1_IOMUX                                            (IOMUX_PINCM3)
/* Defines for KEY2: GPIOA.31 with pinCMx 6 on package pin 39 */
#define KEY_KEY2_PORT                                                    (GPIOA)
#define KEY_KEY2_IIDX                                       (DL_GPIO_IIDX_DIO31)
#define KEY_KEY2_PIN                                            (DL_GPIO_PIN_31)
#define KEY_KEY2_IOMUX                                            (IOMUX_PINCM6)
/* Defines for KEY3: GPIOA.8 with pinCMx 19 on package pin 54 */
#define KEY_KEY3_PORT                                                    (GPIOA)
#define KEY_KEY3_IIDX                                        (DL_GPIO_IIDX_DIO8)
#define KEY_KEY3_PIN                                             (DL_GPIO_PIN_8)
#define KEY_KEY3_IOMUX                                           (IOMUX_PINCM19)
/* Defines for KEY4: GPIOA.9 with pinCMx 20 on package pin 55 */
#define KEY_KEY4_PORT                                                    (GPIOA)
#define KEY_KEY4_IIDX                                        (DL_GPIO_IIDX_DIO9)
#define KEY_KEY4_PIN                                             (DL_GPIO_PIN_9)
#define KEY_KEY4_IOMUX                                           (IOMUX_PINCM20)
/* Defines for KEY5: GPIOB.6 with pinCMx 23 on package pin 58 */
#define KEY_KEY5_PORT                                                    (GPIOB)
#define KEY_KEY5_IIDX                                        (DL_GPIO_IIDX_DIO6)
#define KEY_KEY5_PIN                                             (DL_GPIO_PIN_6)
#define KEY_KEY5_IOMUX                                           (IOMUX_PINCM23)
/* Defines for KEY6: GPIOB.7 with pinCMx 24 on package pin 59 */
#define KEY_KEY6_PORT                                                    (GPIOB)
#define KEY_KEY6_IIDX                                        (DL_GPIO_IIDX_DIO7)
#define KEY_KEY6_PIN                                             (DL_GPIO_PIN_7)
#define KEY_KEY6_IOMUX                                           (IOMUX_PINCM24)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_SYSCTL_CLK_init(void);
void SYSCFG_DL_PWM_0_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_UART_0_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
