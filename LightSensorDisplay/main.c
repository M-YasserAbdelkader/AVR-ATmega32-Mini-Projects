/*
 * main.c
 *
 *  Created on: Apr 23, 2022
 *      Author: yasse
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "HLCD_interface.h"
#include "MADC_interface.h"


#include "util/delay.h"

void main(void)
{
	MDIO_voidSetPortDirection(DIO_U8_PORTB, 0xff);
	u8 local_u8LedNumber = 0;
	u16 local_u16LghtSensor = 0;
	HLCD_voidInit();
	MADC_voidADCInit();
	while(1)
	{
		local_u16LghtSensor = MADC_u16GetChannelReading(ADC0_SINGLE_ENDED_INPUT);
		local_u8LedNumber = 4-((u32)local_u16LghtSensor*4UL)/255UL;
		HLCD_voidGoToXY(1, 0);
		HLCD_voidSendString("LED Number:");
		HLCD_voidWriteNumber(local_u8LedNumber);
		local_u16LghtSensor = ((u32)local_u16LghtSensor*100UL)/255UL;
		HLCD_voidGoToXY(0, 1);
		HLCD_voidSendString("Intensity:");
		for(u8 local_u8LedNumberCounter = 0; local_u8LedNumberCounter < local_u8LedNumber; local_u8LedNumberCounter++)
		{
			MDIO_voidSetPinValue(DIO_U8_PORTB, local_u8LedNumberCounter, DIO_U8_OUTPUT_HIGH);
		}
		HLCD_voidWriteNumber(local_u16LghtSensor);
		HLCD_voidSendDATA('%');

		_delay_ms(2000);
		HLCD_voidSendCommand(1);
		MDIO_voidSetPortValue(DIO_U8_PORTB, 0x00);
	}
}

