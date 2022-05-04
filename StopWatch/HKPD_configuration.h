/*************************************************************
 * @file 	HKPD_configuration.h
 * @author 	Yasssr Mustafa
 * @brief 	HKEYPAD Driver - HAL
 * @version 0.1
 * @date 2022-04-03
 * @copyright Copyright (c) 2022
 *************************************************************/
#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

/*************************************************************
 * \def 	HKPD_PORT
 * Keypad Port
 * \param	DIO_U8_PORTA
 * \param	DIO_U8_PORTB
 * \param	DIO_U8_PORTC
 * \param	DIO_U8_PORTD 
*************************************************************/
#define HKPD_PORT		DIO_U8_PORTA


/*************************************************************
 * \def 	HKPD_ARR
 * Defines the desired key values
*************************************************************/
#define HKPD_ARR	{{'1', '2', '3', ' '}\
					,{'4', '5', '6', ' '}\
					,{'7', '8', '9', 'S'}\
					,{'L', '0', 'R', 'E'}}

/*************************************************************
 * \def HKPD_COL0_PIN
 * KeyPad Column 0
 * \def HKPD_COL1_PIN
 * KeyPad Column 1
 * \def HKPD_COL2_PIN
 * KeyPad Column 2
 * \def HKPD_COL3_PIN
 * KeyPad Column 3
 * \def HKPD_ROW0_PIN
 * KeyPad ROW 0
 * \def HKPD_ROW1_PIN
 * KKeyPad ROW 1
 * \def HKPD_ROW2_PIN
 * KeyPad Row 2
 * \def HKPD_ROW3_PIN
 * KeyPad Row 3
 *************************************************************/
/*************************************************************
 * \param DIO_U8_PIN0
 * \param DIO_U8_PIN1
 * \param DIO_U8_PIN2
 * \param DIO_U8_PIN3
 * \param DIO_U8_PIN4
 * \param DIO_U8_PIN5
 * \param DIO_U8_PIN6
 * \param DIO_U8_PIN7
 *************************************************************/
#define HKPD_COL0_PIN	DIO_U8_PIN0
#define HKPD_COL1_PIN	DIO_U8_PIN1
#define HKPD_COL2_PIN	DIO_U8_PIN2
#define HKPD_COL3_PIN	DIO_U8_PIN3

#define HKPD_ROW0_PIN	DIO_U8_PIN4
#define HKPD_ROW1_PIN	DIO_U8_PIN5
#define HKPD_ROW2_PIN	DIO_U8_PIN6
#define HKPD_ROW3_PIN	DIO_U8_PIN7

#endif /* CONFIGURATION_H_ */
