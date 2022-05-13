/*************************************************************
 * @file HLCD_configuration.h
 * @author Yasser Mustafa
 * @brief LCD Driver - HAL Layer
 * @version 0.1
 * @date 2022-04-10
 * @copyright Copyright (c) 2022
 *************************************************************/
#ifndef HLCD_CONFIGURATION_H_
#define HLCD_CONFIGURATION_H_


/*
 * \def 
 *
 * DIO_U8_PORTA
 * DIO_U8_PORTB
 * DIO_U8_PORTC
 * DIO_U8_PORTD
 */
#define	HLCD_DATA_PORT	DIO_U8_PORTC

/**********************************************/
/**********************************************/

/**
 * \def HLCD_CNTL_PORT
 *
 * DIO_U8_PORTA
 * DIO_U8_PORTB
 * DIO_U8_PORTC
 * DIO_U8_PORTD
 */
#define HLCD_CNTL_PORT	DIO_U8_PORTD

/*
 * Options:
 *
 * DIO_U8_PIN0
 * DIO_U8_PIN1
 * DIO_U8_PIN2
 * DIO_U8_PIN3
 * DIO_U8_PIN4
 * DIO_U8_PIN5
 * DIO_U8_PIN6
 * DIO_U8_PIN7
 */
#define HLCD_RS_PIN		DIO_U8_PIN0

/*
 * Options:
 *
 * DIO_U8_PIN0
 * DIO_U8_PIN1
 * DIO_U8_PIN2
 * DIO_U8_PIN3
 * DIO_U8_PIN4
 * DIO_U8_PIN5
 * DIO_U8_PIN6
 * DIO_U8_PIN7
 */
#define HLCD_RW_PIN		DIO_U8_PIN1

/*
 * Options:
 *
 * DIO_U8_PIN0
 * DIO_U8_PIN1
 * DIO_U8_PIN2
 * DIO_U8_PIN3
 * DIO_U8_PIN4
 * DIO_U8_PIN5
 * DIO_U8_PIN6
 * DIO_U8_PIN7
 */
#define	HLCD_E_PIN		DIO_U8_PIN2



/*
 * Options:
 *
 * 0 ---> 1 line display
 * 1 ---> 2 line display
 */
#define	NUMBER_OF_LINES		1

/*
 * options:
 *
 * 0 ---> 5 X 7 dots
 * 1 ---> 5 X 10 dots
 */
#define FONT_SIZE			0

/*
 * Options:
 *
 * 0 ---> Display is OFF
 * 1 ---> Display is ON
 */
#define DISPLAY_CONTROL		1

/*
 * Options:
 *
 * 0 ---> Cursor is OFF
 * 1 ---> Cursor is ON
 */
#define CURSOR_DISPLAY		0

/*
 * Options:
 * 0 --> Cursor Blinking is OFF
 * 1 --> Cursor Blinking is ON
 */
#define CURSOR_BLINK		0






#endif /* HLCD_CONFIGURATION_H_ */
