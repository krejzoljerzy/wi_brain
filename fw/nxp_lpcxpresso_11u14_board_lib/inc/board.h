/*
 * @brief LPCXpresso 11U14 board file
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2012
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#ifndef __BOARD_H_
#define __BOARD_H_

#include "chip.h"
/* board_api.h is included at the bottom of this file after DEBUG setup */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup BOARD_NXP_XPRESSO_11U14 NXP LPC11U14 LPCXpresso board support software API functions
 * @ingroup LPCOPEN_11XX_BOARD_XPRESSO_11U14
 * The board support software API functions provide some simple abstracted
 * functions used across multiple LPCOpen board examples. See @ref BOARD_COMMON_API
 * for the functions defined by this board support layer.<br>
 * @{
 */

/** @defgroup BOARD_NXP_XPRESSO_11U14_OPTIONS BOARD: NXP LPC11U14 LPCXpresso board build options
 * This board has options that configure its operation at build-time.<br>
 * @{
 */

/** Define DEBUG_ENABLE to enable IO via the DEBUGSTR, DEBUGOUT, and
    DEBUGIN macros. If not defined, DEBUG* functions will be optimized
	out of the code at build time.
 */
//#define DEBUG_ENABLE

/** Define DEBUG_SEMIHOSTING along with DEBUG_ENABLE to enable IO support
    via semihosting. You may need to use a C library that supports
	semihosting with this option.
 */
//#define DEBUG_SEMIHOSTING

/** Board UART used for debug output and input using the DEBUG* macros. This
    is also the port used for Board_UARTPutChar, Board_UARTGetChar, and
	Board_UARTPutSTR functions.
 */
#define DEBUG_UART LPC_USART

/**
 * @}
 */

/* Board name */
#define BOARD_NXP_XPRESSO_11U14

/**
 * LED defines
 */
#define LEDS_LED1           0x01
#define LEDS_LED2           0x02
#define LEDS_LED3           0x04
#define LEDS_LED4           0x08
#define LEDS_LED5           0x10
#define LEDS_LED6           0x20
#define LEDS_LED7           0x40
#define LEDS_LED8           0x80
#define LEDS_NO_LEDS        0x00

/**
 *  GPIO defines
 *  WARNING! Pin reserved due to ADC
 *  pin escape routine
 */

#define GPIO_RESERVED_PIN 10
#define GPIO_RESERVED_PORT 2
#define GPIO_LED1_PORT		2
#define GPIO_LED1_PIN		1
#define GPIO_LED2_PORT		0
#define GPIO_LED2_PIN		4
#define GPIO_LED3_PORT		1
#define GPIO_LED3_PIN		9
#define GPIO_LED4_PORT		3
#define GPIO_LED4_PIN		4
#define GPIO_LED5_PORT		2
#define GPIO_LED5_PIN		4
#define GPIO_LED6_PORT		2
#define GPIO_LED6_PIN		5
#define GPIO_LED7_PORT		0
#define GPIO_LED7_PIN		6
#define GPIO_LED8_PORT		2
#define GPIO_LED8_PIN		9

 /**
  * Battery measurement ADC pins
  */
#define ADC_PORT 1
#define ADC_PIN 10

/**
 *  General use PWM outputs
 */
#define PWM_0_PORT	1
#define PWM_0_PIN	1
#define PWM_1_PORT	1
#define PWM_1_PIN	2
#define PWM_10_PORT 0
#define PWM_10_PIN	8
#define PWM_11_PORT	0
#define PWM_11_PIN	9

/**
 *  PWM used for H bridge driving
 */
#define MOTORA_PORT	1
#define MOTORA_PIN	3
#define MOTORB_PORT	1
#define MOTORB_PIN	4

/**
 * UART defines
 */
#define UART_BAUDRATE		9600
/**
 * @brief	Initialize buttons on the board
 * @return	Nothing
 */
void Board_Buttons_Init(void);

/**
 * @brief	Get button status
 * @return	status of button
 */
uint32_t Buttons_GetStatus(void);

/**
 * @brief	Initialize Joystick
 * @return	Nothing
 */
void Board_Joystick_Init(void);

/**
 * @brief	Get Joystick status
 * @return	status of Joystick
 */
uint8_t Joystick_GetStatus(void);

/**
 * @}
 */

#include "board_api.h"

#ifdef __cplusplus
}
#endif

#endif /* __BOARD_H_ */
