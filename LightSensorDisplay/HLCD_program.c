/*************************************************************
 * @file HLCD_program.c
 * @author Yasser Mustafa
 * @brief LCD Driver - HAL Layer
 * @version 0.1
 * @date 2022-04-10
 * @copyright Copyright (c) 2022
 *************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "HLCD_interface.h"
#include "HLCD_private.h"
#include "HLCD_register.h"
#include "HLCD_configuration.h"
#include <util/delay.h>
void HLCD_voidInit(void)
{
	/** \brief initialize ports and pins */
	MDIO_voidSetPortDirection(HLCD_DATA_PORT, HLCD_PORT_OUTPUT);
	MDIO_voidSetPinDirection(HLCD_CNTL_PORT, HLCD_RS_PIN, HLCD_PIN_OUTPUT);
	MDIO_voidSetPinDirection(HLCD_CNTL_PORT, HLCD_RW_PIN, HLCD_PIN_OUTPUT);
	MDIO_voidSetPinDirection(HLCD_CNTL_PORT, HLCD_E_PIN, HLCD_PIN_OUTPUT);

	/** \brief wait for more than 30 mSec */
	_delay_ms(40);

	/** \brief Function Set */
	HLCD_voidSendCommand(CONC_BIT(0, 0, 1, 1, NUMBER_OF_LINES, FONT_SIZE, 0, 0));

	/** \brief Display ON|OFF */
	HLCD_voidSendCommand(CONC_BIT(0, 0, 0, 0, 1, DISPLAY_CONTROL, CURSOR_DISPLAY, CURSOR_BLINK));


	/** \brief Display Clear */
	HLCD_voidSendCommand(CLEAR_DISPLAY_COMMAND);


}


void HLCD_voidSendDATA(u8 copy_u8Data)
{
	/*set RS pin for data*/
	MDIO_voidSetPinValue(HLCD_CNTL_PORT, HLCD_RS_PIN, RS_PIN_DISPLAY_DATA);

	/*clear RW pin for write */
	MDIO_voidSetPinValue(HLCD_CNTL_PORT, HLCD_RW_PIN, RW_PIN_WRITE_OPERATION);

	/*send data*/
	MDIO_voidSetPortValue(HLCD_DATA_PORT, copy_u8Data);

	/*Send Enable pulse*/
	MDIO_voidSetPinValue(HLCD_CNTL_PORT, HLCD_E_PIN, E_PIN_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(HLCD_CNTL_PORT, HLCD_E_PIN, E_PIN_LOW);
}

void HLCD_voidSendCommand(u8 copy_u8Command)
{
	/*clear RS pin for command*/
	MDIO_voidSetPinValue(HLCD_CNTL_PORT, HLCD_RS_PIN, RS_PIN_INSTRUCTION_CODE);

	/*clear RW pin for write */
	MDIO_voidSetPinValue(HLCD_CNTL_PORT, HLCD_RW_PIN, RW_PIN_WRITE_OPERATION);

	/*send command*/
	MDIO_voidSetPortValue(HLCD_DATA_PORT, copy_u8Command);

	/*Send Enable pulse*/
	MDIO_voidSetPinValue(HLCD_CNTL_PORT, HLCD_E_PIN, E_PIN_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(HLCD_CNTL_PORT, HLCD_E_PIN, E_PIN_LOW);
}


void HLCD_voidSendString(const u8* copy_pcString)
{
	u8 Local_u8Counter = 0;
	while(copy_pcString[Local_u8Counter] != '\0')
	{
		HLCD_voidSendDATA(copy_pcString[Local_u8Counter]);
		Local_u8Counter ++;
	}
}


void HLCD_voidGoToXY(u8 copy_u8XPos, u8 copy_u8YPos)
{
	u8 Local_u8Address = (copy_u8XPos*0x40) + copy_u8YPos;

	HLCD_voidSendCommand(Local_u8Address +127);

}


void HLCD_voidWriteSpecialCharacter(u8* copy_pu8Pattern, u8 copy_u8PatternNumber, u8 copy_u8XPos, u8 copy_u8YPos)
{
	u8 Local_u8Iterator;
	u8 Local_u8CGRAMAddress = copy_u8PatternNumber * NUMBER_OF_CHARACTERS;


	/*Send CG RAM ADDRESS command */
	HLCD_voidSendCommand(Local_u8CGRAMAddress+64);

	/*Write the pattern into CG RAM*/
	for (Local_u8Iterator = 0; Local_u8Iterator < NUMBER_OF_CHARACTERS; ++Local_u8Iterator) {
		HLCD_voidSendDATA(copy_pu8Pattern[Local_u8Iterator]	);
	}
	HLCD_voidGoToXY(copy_u8XPos, copy_u8YPos);


	/*Display the pattern written in the CG RAM*/
	HLCD_voidSendDATA(copy_u8PatternNumber);
}

void HLCD_voidWriteNumber(u32 copy_u32Number)
{
	u32 local_u32Multiblier = 1;
	while (copy_u32Number%(local_u32Multiblier*10) != copy_u32Number)
	{
		local_u32Multiblier *= 10;
	}
	while (local_u32Multiblier != 0)
	{
		HLCD_voidSendDATA((u8)(copy_u32Number/local_u32Multiblier)+'0');
		copy_u32Number %=  local_u32Multiblier;
		local_u32Multiblier /= 10; 
	}
	
}



