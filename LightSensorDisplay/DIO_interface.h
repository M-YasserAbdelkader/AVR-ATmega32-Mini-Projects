/***************************************/
/*	AUTHOR		: Yasser Mustafa Ahmed
 * 	Description	: DIO DRIVER
 *	DATE		: 03 JAN 2022
 *	VERSION		: V01
 ****************************************/

#ifndef INCLUDE_MCAL_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_INTERFACE_H_

#define DIO_U8_PORTA	0
#define DIO_U8_PORTB	1
#define DIO_U8_PORTC	2
#define DIO_U8_PORTD	3

#define DIO_U8_PIN0		0
#define DIO_U8_PIN1		1
#define DIO_U8_PIN2		2
#define DIO_U8_PIN3		3
#define DIO_U8_PIN4		4
#define DIO_U8_PIN5		5
#define DIO_U8_PIN6		6
#define DIO_U8_PIN7		7

#define DIO_U8_OUTPUT	1
#define	DIO_U8_INPUT	0

#define DIO_U8_INTIAL_OUTPUT		1
#define	DIO_U8_INTIAL_INPUT			0

#define DIO_U8_OUTPUT_HIGH			1
#define DIO_U8_OUTPUT_LOW			0

#define DIO_U8_INPUT_PULLUP			1
#define	DIO_U8_INPUT_FLOATING		0

/****************************************************************************************/
/*	Function: MDIO_voidInit																*/
/*	I/P Parameters: Nothing																*/
/*	Returns: Nothing																	*/
/*Description: This Function Initialize Direction and Value for all Pins				*/
/****************************************************************************************/
void MDIO_voidInit(void);

/****************************************************************************************/
/*	Function: MDIO_voidSetPinDirection													*/
/*	I/P Parameters: Port ID, Pin ID, Pin Direction										*/
/*	Returns: Nothing																	*/
/*Description: This Function Sets the direction of a Given pin							*/
/****************************************************************************************/
/*	Options																				*/
/*	copy_u8PortID: DIO_U8_PORTA, DIO_U8_PORTB, DIO_U8_PORTC, DIO_U8_PORTD					*/
/*	copy_u8PinID: From: DIO_U8_PIN0	 	To: 		DIO_U8_PIN7							*/
/*	copy_u8PinDirection: DIO_U8_OUTPUT, DIO_U8_INPUT										*/
/****************************************************************************************/
void MDIO_voidSetPinDirection(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinDirection);

/****************************************************************************************/
/*	Function: MDIO_voidSetPinValue														*/
/*	I/P Parameters: Port ID, Pin ID, Pin Value											*/
/*	Returns: Nothing																	*/
/*Description: This Function Sets the value of a Given pin								*/
/****************************************************************************************/
/*	Options*/
/*	copy_u8PortID: DIO_U8_PORTA, DIO_U8_PORTB, DIO_U8_PORTC, DIO_U8_PORTD					*/
/*	copy_u8PinID: From: DIO_U8_PIN0	 	To: 		DIO_U8_PIN7							*/
/*	copy_u8PinValue:DIO_U8_OUTPUT_HIGH, DIO_U8_OUTPUT_LOW									*/
/****************************************************************************************/
void MDIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinValue);

/****************************************************************************************/
/*	Function: MDIO_u8GetPinValue														*/
/*	I/P Parameters: Port ID, Pin ID														*/
/*	Returns: it returns u8 Value of the given Pin										*/
/****************************************************************************************/
/*Options																				*/
/*	copy_u8PortID: DIO_U8_PORTA, DIO_U8_PORTB, DIO_U8_PORTC, DIO_U8_PORTD				*/
/*	copy_u8PinID: From: DIO_U8_PIN0	 	To: 		DIO_U8_PIN7							*/
/****************************************************************************************/
u8 MDIO_u8GetPinValue(u8 copy_u8PortID, u8 copy_u8PinID);

/****************************************************************************************/
/*	Function: MDIO_voidSetPortDirection													*/
/*	I/P: Port ID, Port Direction														*/
/*	Return: Nothing																		*/
/****************************************************************************************/
/*	Options																				*/
/*	copy_u8PortID: DIO_U8_PORTA, DIO_U8_PORTB, DIO_U8_PORTC, DIO_U8_PORTD				*/
/*	copy_u8PortDirection: Set the direction in HEX Format								*/
/****************************************************************************************/
void MDIO_voidSetPortDirection(u8 copy_u8PortID, u8 copy_PortDirection);

/****************************************************************************************/
/*	Function: MDIO_voidSetPortValue													*/
/*	I/P: Port ID, Port Value														*/
/*	Return: Nothing																		*/
/****************************************************************************************/
/*	Options																				*/
/*	copy_u8PortID: DIO_U8_PORTA, DIO_U8_PORTB, DIO_U8_PORTC, DIO_U8_PORTD				*/
/*	copy_u8PortDirection: Set the Value in HEX Format									*/
/****************************************************************************************/
void MDIO_voidSetPortValue(u8 copy_u8PortID, u8 copy_PortValue);

#endif /* INCLUDE_MCAL_DIO_INTERFACE_H_ */
