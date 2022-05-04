/***************************************/
/*	AUTHOR		: Yasser Mustafa Ahmed
 * 	Description	: DIO DRIVER
 *	DATE		: 03 JAN 2022
 *	VERSION		: V01
 ****************************************/

/************************************************************************/
/*	Library Directives													*/
/************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/************************************************************************/
/*	DIO Directives														*/
/************************************************************************/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_configuration.h"

/****************************************************************************************/
/*	Function: MDIO_voidInit																*/
/*	I/P Parameters: Nothing																*/
/*	Returns: Nothing																	*/
/*Description: This Function Initialize Direction and Value for all Pins				*/
/****************************************************************************************/
void MDIO_voidInit(void)
{
	/*Set All Port A Pins Direction Due to Pre-Configuration			*/
	DIO_U8_DDRA_REG = CONC_BIT( DIO_U8_PA7_INTIAL_DIRECTION,
								DIO_U8_PA6_INTIAL_DIRECTION,
								DIO_U8_PA5_INTIAL_DIRECTION,
								DIO_U8_PA4_INTIAL_DIRECTION,
								DIO_U8_PA3_INTIAL_DIRECTION,
								DIO_U8_PA2_INTIAL_DIRECTION,
								DIO_U8_PA1_INTIAL_DIRECTION,
								DIO_U8_PA0_INTIAL_DIRECTION);

	/*Set All Port B Pins Direction Due to Pre-Configuration			*/
	DIO_U8_DDRB_REG = CONC_BIT( DIO_U8_PB7_INTIAL_DIRECTION,
								DIO_U8_PB6_INTIAL_DIRECTION,
								DIO_U8_PB5_INTIAL_DIRECTION,
								DIO_U8_PB4_INTIAL_DIRECTION,
								DIO_U8_PB3_INTIAL_DIRECTION,
								DIO_U8_PB2_INTIAL_DIRECTION,
								DIO_U8_PB1_INTIAL_DIRECTION,
								DIO_U8_PB0_INTIAL_DIRECTION);

	/*Set All Port C Pins Direction Due to Pre-Configuration			*/
	DIO_U8_DDRC_REG = CONC_BIT( DIO_U8_PC7_INTIAL_DIRECTION,
								DIO_U8_PC6_INTIAL_DIRECTION,
								DIO_U8_PC5_INTIAL_DIRECTION,
								DIO_U8_PC4_INTIAL_DIRECTION,
								DIO_U8_PC3_INTIAL_DIRECTION,
								DIO_U8_PC2_INTIAL_DIRECTION,
								DIO_U8_PC1_INTIAL_DIRECTION,
								DIO_U8_PC0_INTIAL_DIRECTION);

	/*Set All Port D Pins Direction Due to Pre-Configuration			*/
	DIO_U8_DDRD_REG = CONC_BIT( DIO_U8_PD7_INTIAL_DIRECTION,
								DIO_U8_PD6_INTIAL_DIRECTION,
								DIO_U8_PD5_INTIAL_DIRECTION,
								DIO_U8_PD4_INTIAL_DIRECTION,
								DIO_U8_PD3_INTIAL_DIRECTION,
								DIO_U8_PD2_INTIAL_DIRECTION,
								DIO_U8_PD1_INTIAL_DIRECTION,
								DIO_U8_PD0_INTIAL_DIRECTION);

	/*Set All Port A Pins Values Due to Pre-Configuration				*/
	DIO_U8_PORTA_REG = CONC_BIT(DIO_U8_PA7_INTIAL_VALUE,
								DIO_U8_PA6_INTIAL_VALUE,
								DIO_U8_PA5_INTIAL_VALUE,
								DIO_U8_PA4_INTIAL_VALUE,
								DIO_U8_PA3_INTIAL_VALUE,
								DIO_U8_PA2_INTIAL_VALUE,
								DIO_U8_PA1_INTIAL_VALUE,
								DIO_U8_PA0_INTIAL_VALUE);

	/*Set All Port B Pins Values Due to Pre-Configuration				*/
	DIO_U8_PORTB_REG = CONC_BIT(DIO_U8_PB7_INTIAL_VALUE,
								DIO_U8_PB6_INTIAL_VALUE,
								DIO_U8_PB5_INTIAL_VALUE,
								DIO_U8_PB4_INTIAL_VALUE,
								DIO_U8_PB3_INTIAL_VALUE,
								DIO_U8_PB2_INTIAL_VALUE,
								DIO_U8_PB1_INTIAL_VALUE,
								DIO_U8_PB0_INTIAL_VALUE);

	/*Set All Port C Pins Values Due to Pre-Configuration				*/
	DIO_U8_PORTC_REG = CONC_BIT(DIO_U8_PC7_INTIAL_VALUE,
								DIO_U8_PC6_INTIAL_VALUE,
								DIO_U8_PC5_INTIAL_VALUE,
								DIO_U8_PC4_INTIAL_VALUE,
								DIO_U8_PC3_INTIAL_VALUE,
								DIO_U8_PC2_INTIAL_VALUE,
								DIO_U8_PC1_INTIAL_VALUE,
								DIO_U8_PC0_INTIAL_VALUE);
	/*Set All Port D Pins Values Due to Pre-Configuration				*/
	DIO_U8_PORTD_REG = CONC_BIT(DIO_U8_PD7_INTIAL_VALUE,
								DIO_U8_PD6_INTIAL_VALUE,
								DIO_U8_PD5_INTIAL_VALUE,
								DIO_U8_PD4_INTIAL_VALUE,
								DIO_U8_PD3_INTIAL_VALUE,
								DIO_U8_PD2_INTIAL_VALUE,
								DIO_U8_PD1_INTIAL_VALUE,
								DIO_U8_PD0_INTIAL_VALUE);


}

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
void MDIO_voidSetPinDirection(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinDirection)
{
	/*Input Validation*/
	if(	(copy_u8PortID > DIO_U8_PORTD)	||	(copy_u8PortID < DIO_U8_PORTA)	||
		 (copy_u8PinID > DIO_U8_PIN7)	||	(copy_u8PinID < DIO_U8_PIN0))
	{

	}
	else
	{
		switch(copy_u8PortID)
		{
			case DIO_U8_PORTA:
								switch(copy_u8PinDirection) //Check On Direction
								{
									case DIO_U8_OUTPUT:	SET_BIT(DIO_U8_DDRA_REG,copy_u8PinID);	break; //Set Pin to Output Mode
									case DIO_U8_INPUT:	CLR_BIT(DIO_U8_DDRA_REG,copy_u8PinID);	break; //Set Pin to Input Mode
								}
								break;
			case DIO_U8_PORTB:
								switch(copy_u8PinDirection)
								{
									case DIO_U8_OUTPUT:	SET_BIT(DIO_U8_DDRB_REG,copy_u8PinID);	break;
									case DIO_U8_INPUT:	CLR_BIT(DIO_U8_DDRB_REG,copy_u8PinID);	break;
								}
								break;
			case DIO_U8_PORTC:
								switch(copy_u8PinDirection)
								{
									case DIO_U8_OUTPUT:	SET_BIT(DIO_U8_DDRC_REG,copy_u8PinID);	break;
									case DIO_U8_INPUT:	CLR_BIT(DIO_U8_DDRC_REG,copy_u8PinID);	break;
								}
								break;

			case DIO_U8_PORTD:
								switch(copy_u8PinDirection)
								{
									case DIO_U8_OUTPUT:	SET_BIT(DIO_U8_DDRD_REG,copy_u8PinID);	break;
									case DIO_U8_INPUT:	CLR_BIT(DIO_U8_DDRD_REG,copy_u8PinID);	break;
								}
								break;

		}
	}
}

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
void MDIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinValue)
{
	/*Input Validation*/
	if(((copy_u8PortID > DIO_U8_PORTD)	|| (copy_u8PortID < DIO_U8_PORTA)) ||
		(copy_u8PinID > DIO_U8_PIN7) 	||	(copy_u8PinID < DIO_U8_PIN0))
	{

	}
	else
	{
		switch(copy_u8PortID)
		{
			case DIO_U8_PORTA:
								switch(copy_u8PinValue)
								{
									case DIO_U8_OUTPUT_HIGH:	SET_BIT(DIO_U8_PORTA_REG, copy_u8PinID);	break;
									case DIO_U8_OUTPUT_LOW:		CLR_BIT(DIO_U8_PORTA_REG, copy_u8PinID); break;
								}
								break;
			case DIO_U8_PORTB:
								switch(copy_u8PinValue)
								{
									case DIO_U8_OUTPUT_HIGH:	SET_BIT(DIO_U8_PORTB_REG, copy_u8PinID);	break;
									case DIO_U8_OUTPUT_LOW:		CLR_BIT(DIO_U8_PORTB_REG, copy_u8PinID); break;
								}
								break;
			case DIO_U8_PORTC:
								switch(copy_u8PinValue)
								{
									case DIO_U8_OUTPUT_HIGH:	SET_BIT(DIO_U8_PORTC_REG, copy_u8PinID);	break;
									case DIO_U8_OUTPUT_LOW:		CLR_BIT(DIO_U8_PORTC_REG, copy_u8PinID); break;
								}
								break;
			case DIO_U8_PORTD:
								switch(copy_u8PinValue)
								{
									case DIO_U8_OUTPUT_HIGH:	SET_BIT(DIO_U8_PORTD_REG, copy_u8PinID);	break;
									case DIO_U8_OUTPUT_LOW:		CLR_BIT(DIO_U8_PORTD_REG, copy_u8PinID); break;
								}
								break;
		}
	}
}

/****************************************************************************************/
/*	Function: MDIO_u8GetPinValue														*/
/*	I/P Parameters: Port ID, Pin ID														*/
/*	Returns: it returns u8 Value of the given Pin										*/
/****************************************************************************************/
/*Options																				*/
/*	copy_u8PortID: DIO_U8_PORTA, DIO_U8_PORTB, DIO_U8_PORTC, DIO_U8_PORTD				*/
/*	copy_u8PinID: From: DIO_U8_PIN0	 	To: 		DIO_U8_PIN7							*/
/****************************************************************************************/
u8 MDIO_u8GetPinValue(u8 copy_u8PortID, u8 copy_u8PinID)
{
	u8 local_u8PinValue = 2;
	if(	(copy_u8PortID > DIO_U8_PORTD)	||	(copy_u8PortID < DIO_U8_PORTA)	||
		(copy_u8PinID > DIO_U8_PIN7)	||	(copy_u8PinID < DIO_U8_PIN0))
	{

	}
	else
	{

		switch(copy_u8PortID)
		{
		case DIO_U8_PORTA:	local_u8PinValue = GET_BIT(DIO_U8_PINA_REG,copy_u8PinID); break;
		case DIO_U8_PORTB:	local_u8PinValue = GET_BIT(DIO_U8_PINB_REG,copy_u8PinID); break;
		case DIO_U8_PORTC:	local_u8PinValue = GET_BIT(DIO_U8_PINC_REG,copy_u8PinID); break;
		case DIO_U8_PORTD:	local_u8PinValue = GET_BIT(DIO_U8_PIND_REG,copy_u8PinID); break;
		}
	}
	return local_u8PinValue;

}

/****************************************************************************************/
/*	Function: MDIO_voidSetPortDirection													*/
/*	I/P: Port ID, Port Direction														*/
/*	Return: Nothing																		*/
/****************************************************************************************/
/*	Options																				*/
/*	copy_u8PortID: DIO_U8_PORTA, DIO_U8_PORTB, DIO_U8_PORTC, DIO_U8_PORTD				*/
/*	copy_u8PortDirection: Set the direction in HEX Format								*/
/****************************************************************************************/
void MDIO_voidSetPortDirection(u8 copy_u8PortID, u8 copy_PortDirection)
{
	if((copy_u8PortID > DIO_U8_PORTD)	||	(copy_u8PortID < DIO_U8_PORTA))
	{

	}
	else
	{
		switch(copy_u8PortID)
		{
		case DIO_U8_PORTA:	DIO_U8_DDRA_REG = copy_PortDirection; break;
		case DIO_U8_PORTB:	DIO_U8_DDRB_REG = copy_PortDirection; break;
		case DIO_U8_PORTC:	DIO_U8_DDRC_REG = copy_PortDirection; break;
		case DIO_U8_PORTD:	DIO_U8_DDRD_REG = copy_PortDirection; break;
		}
	}
}

/****************************************************************************************/
/*	Function: MDIO_voidSetPortValue													*/
/*	I/P: Port ID, Port Value														*/
/*	Return: Nothing																		*/
/****************************************************************************************/
/*	Options																				*/
/*	copy_u8PortID: DIO_U8_PORTA, DIO_U8_PORTB, DIO_U8_PORTC, DIO_U8_PORTD				*/
/*	copy_u8PortDirection: Set the Value in HEX Format									*/
/****************************************************************************************/
void MDIO_voidSetPortValue(u8 copy_u8PortID, u8 copy_PortValue)
{
	if((copy_u8PortID > DIO_U8_PORTD)	||	(copy_u8PortID < DIO_U8_PORTA))
	{

	}
	else
	{
		switch(copy_u8PortID)
		{
		case DIO_U8_PORTA:	DIO_U8_PORTA_REG = copy_PortValue; break;
		case DIO_U8_PORTB:	DIO_U8_PORTB_REG = copy_PortValue; break;
		case DIO_U8_PORTC:	DIO_U8_PORTC_REG = copy_PortValue; break;
		case DIO_U8_PORTD:	DIO_U8_PORTD_REG = copy_PortValue; break;
		}
	}
}

/****************************************************************************************/
/*	Function: MDIO_u8GetPortValue														*/
/*	I/P Parameters: Port ID																*/
/*	Returns: it returns u8 Value of the given PORT										*/
/****************************************************************************************/
/*Options																				*/
/*	copy_u8PortID: DIO_U8_PORTA, DIO_U8_PORTB, DIO_U8_PORTC, DIO_U8_PORTD				*/
/****************************************************************************************/
u8 MDIO_u8GetPortValue(u8 copy_u8PortID)
{
	u8 local_u8PortValue = 0;
	if((copy_u8PortID > DIO_U8_PORTD)	||	(copy_u8PortID < DIO_U8_PORTA))
	{

	}
	else
	{
		switch(copy_u8PortID)
		{
		case DIO_U8_PORTA:	local_u8PortValue = DIO_U8_PINA_REG ; break;
		case DIO_U8_PORTB:	local_u8PortValue = DIO_U8_PINB_REG; break;
		case DIO_U8_PORTC:	local_u8PortValue = DIO_U8_PINC_REG; break;
		case DIO_U8_PORTD:	local_u8PortValue = DIO_U8_PIND_REG; break;
		}
	}

	return local_u8PortValue;
}




