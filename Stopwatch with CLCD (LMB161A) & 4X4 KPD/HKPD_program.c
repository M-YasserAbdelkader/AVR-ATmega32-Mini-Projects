/*************************************************************
 * @file      HKPD_program.c
 * @author 	  Yasssr Mustafa
 * @brief 	  HKEYPAD Driver - HAL
 * @version   0.1
 * @date      2022-04-03
 * @copyright Copyright (c) 2022
 *************************************************************/ 

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "HKPD_interface.h"
#include "HKPD_private.h"
#include "HKPD_configuration.h"


u8 HKPD_u8GetPresssedKey(void)
{
	static u8 Local_u8KPDArr[4][4] = HKPD_ARR;
	u8 Local_u8PressedKey = HKPD_U8_NO_PRESSED_KEY; 
	u8 Local_u8PinState;
	u8 Local_u8ColumnIndex;	
	u8 Local_u8RowIndex;
	static u8 Local_u8KPDColumnArr[COLUMN_NUMBER] = COLUMN_ARR;
	static u8 Local_u8KPDRowArr[ROW_NUMBER] = ROW_ARR;
	
	for (Local_u8ColumnIndex = 0; Local_u8ColumnIndex < COLUMN_NUMBER; ++Local_u8ColumnIndex)
	{
		/** @brief Activate Current Column */
		MDIO_voidSetPinValue(HKPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIndex], COLUMN_ACTIVE);

		for (Local_u8RowIndex = 0; Local_u8RowIndex < ROW_NUMBER; ++Local_u8RowIndex)
		{
			/** @brief Read the current row */
			Local_u8PinState = MDIO_u8GetPinValue(HKPD_PORT, Local_u8KPDRowArr[Local_u8RowIndex]);


			/** @brief Check Key State */
			if (Local_u8PinState == KEY_PRESSED)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];

				/** @brief Polling (Busy waiting) till key is released */
				while(Local_u8PinState == KEY_PRESSED)
				{
					Local_u8PinState = MDIO_u8GetPinValue(HKPD_PORT, Local_u8KPDRowArr[Local_u8RowIndex]);
				}
				
				/** @brief returns  Keypad value */
				return Local_u8PressedKey;
			}

		}
		/** @brief De-activate Current Column */
		MDIO_voidSetPinValue(HKPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIndex], COLUMN_INACTIVE);
	}
	/** @brief returns  HKPD_U8_NO_PRESSED_KEY */
	return	Local_u8PressedKey;
}
