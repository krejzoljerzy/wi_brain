/*
 * @brief NXP LPCXpresso 11U14 board file
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
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

#include "board.h"
#include "retarget.h"

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/* System oscillator rate and clock rate on the CLKIN pin */
const uint32_t OscRateIn = 12000000;
const uint32_t ExtRateIn = 0;

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/* Sends a character on the UART */
void Board_UARTPutChar(char ch)
{
#if defined(DEBUG_UART)
	Chip_UART_SendBlocking(DEBUG_UART, &ch, 1);
#endif
}

/* Gets a character from the UART, returns EOF if no character is ready */
int Board_UARTGetChar(void)
{
#if defined(DEBUG_UART)
	uint8_t data;

	if (Chip_UART_Read(DEBUG_UART, &data, 1) == 1) {
		return (int) data;
	}
#endif
	return EOF;
}

/* Outputs a string on the debug UART */
void Board_UARTPutSTR(char *str)
{
#if defined(DEBUG_UART)
	while (*str != '\0') {
		Board_UARTPutChar(*str++);
	}
#endif
}

/* Initialize debug output via UART for board */
void Board_Debug_Init(void)
{
#if defined(DEBUG_UART)
	Chip_IOCON_PinMuxSet(LPC_IOCON, 0, 18, IOCON_FUNC1 | IOCON_MODE_INACT); /* PIO0_18 used for RXD */
	Chip_IOCON_PinMuxSet(LPC_IOCON, 0, 19, IOCON_FUNC1 | IOCON_MODE_INACT); /* PIO0_19 used for TXD */

	/* Setup UART for 115.2K8N1 */
	Chip_UART_Init(LPC_USART);
	Chip_UART_SetBaud(LPC_USART, 115200);
	Chip_UART_ConfigData(LPC_USART, (UART_LCR_WLEN8 | UART_LCR_SBS_1BIT));
	Chip_UART_SetupFIFOS(LPC_USART, (UART_FCR_FIFO_EN | UART_FCR_TRG_LEV2));
	Chip_UART_TXEnable(LPC_USART);
#endif
}

/* Initializes board LED(s) */
static void Board_LED_Init(void)
{
	/* Set the PIO_7 as output */
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, GPIO_LED1_PORT, GPIO_LED1_PIN);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, GPIO_LED2_PORT, GPIO_LED2_PIN);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, GPIO_LED3_PORT, GPIO_LED3_PIN);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, GPIO_LED4_PORT, GPIO_LED4_PIN);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, GPIO_LED5_PORT, GPIO_LED5_PIN);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, GPIO_LED6_PORT, GPIO_LED6_PIN);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, GPIO_LED7_PORT, GPIO_LED7_PIN);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, GPIO_LED8_PORT, GPIO_LED8_PIN);
}

/* Sets the state of a board LED to on or off */
void Board_LED_Set(uint8_t LEDNumber)
{
	if(LEDNumber && LEDS_LED1) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED1_PORT, GPIO_LED1_PIN, 0);
	}
	if(LEDNumber && LEDS_LED2) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED2_PORT, GPIO_LED2_PIN, 0);
	}
	if(LEDNumber && LEDS_LED3) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED3_PORT, GPIO_LED3_PIN, 0);
	}
	if(LEDNumber && LEDS_LED4) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED4_PORT, GPIO_LED4_PIN, 0);
	}
	if(LEDNumber && LEDS_LED5) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED5_PORT, GPIO_LED5_PIN, 0);
	}
	if(LEDNumber && LEDS_LED6) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED6_PORT, GPIO_LED6_PIN, 0);
	}
	if(LEDNumber && LEDS_LED7) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED7_PORT, GPIO_LED7_PIN, 0);
	}
	if(LEDNumber && LEDS_LED8) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED8_PORT, GPIO_LED8_PIN, 0);
	}
}

/* Sets the state of a board LED to on or off */
void Board_LED_Clr(uint8_t LEDNumber)
{
	if(LEDNumber && LEDS_LED1) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED1_PORT, GPIO_LED1_PIN, 1);
	}
	if(LEDNumber && LEDS_LED2) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED2_PORT, GPIO_LED2_PIN, 1);
	}
	if(LEDNumber && LEDS_LED3) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED3_PORT, GPIO_LED3_PIN, 1);
	}
	if(LEDNumber && LEDS_LED4) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED4_PORT, GPIO_LED4_PIN, 1);
	}
	if(LEDNumber && LEDS_LED5) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED5_PORT, GPIO_LED5_PIN, 1);
	}
	if(LEDNumber && LEDS_LED6) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED6_PORT, GPIO_LED6_PIN, 1);
	}
	if(LEDNumber && LEDS_LED7) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED7_PORT, GPIO_LED7_PIN, 1);
	}
	if(LEDNumber && LEDS_LED8) {
		Chip_GPIO_SetPinState(LPC_GPIO, GPIO_LED8_PORT, GPIO_LED8_PIN, 1);
	}
}

void Board_LED_Toggle(uint8_t LEDNumber)
{
	if(LEDNumber && LEDS_LED1) {
		Chip_GPIO_SetPinToggle(LPC_GPIO, GPIO_LED1_PORT, GPIO_LED1_PIN);
	}
	if(LEDNumber && LEDS_LED2) {
		Chip_GPIO_SetPinToggle(LPC_GPIO, GPIO_LED2_PORT, GPIO_LED2_PIN);
	}
	if(LEDNumber && LEDS_LED3) {
		Chip_GPIO_SetPinToggle(LPC_GPIO, GPIO_LED3_PORT, GPIO_LED3_PIN);
	}
	if(LEDNumber && LEDS_LED4) {
		Chip_GPIO_SetPinToggle(LPC_GPIO, GPIO_LED4_PORT, GPIO_LED4_PIN);
	}
	if(LEDNumber && LEDS_LED5) {
		Chip_GPIO_SetPinToggle(LPC_GPIO, GPIO_LED5_PORT, GPIO_LED5_PIN);
	}
	if(LEDNumber && LEDS_LED6) {
		Chip_GPIO_SetPinToggle(LPC_GPIO, GPIO_LED6_PORT, GPIO_LED6_PIN);
	}
	if(LEDNumber && LEDS_LED7) {
		Chip_GPIO_SetPinToggle(LPC_GPIO, GPIO_LED7_PORT, GPIO_LED7_PIN);
	}
	if(LEDNumber && LEDS_LED8) {
		Chip_GPIO_SetPinToggle(LPC_GPIO, GPIO_LED8_PORT, GPIO_LED8_PIN);
	}
}

/* Set up and initialize all required blocks and functions related to the
   board hardware */
void Board_Init(void)
{
	/* Sets up DEBUG UART */
	DEBUGINIT();

	/* Initialize GPIO */
	Chip_GPIO_Init(LPC_GPIO);

	/* Initialize UART */
	//UART_init();
	/* Initialize LEDs */
	Board_LED_Init();
}


