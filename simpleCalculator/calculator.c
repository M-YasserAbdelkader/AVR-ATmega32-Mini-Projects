/*************************************************************
 * @file      calculator.c
 * @author 	  Yasssr Mustafa
 * @brief
 * @version   0.1
 * @date      2022-04-03
 * @copyright Copyright (c) 2022
 *************************************************************/

#include "STD_TYPES.h"
#include "calculator.h"
#include "DIO_interface.h"
#include "HLCD_interface.h"


static u8 CALC_u8Keys[3] = {UP_PIN, DOWN_PIN, ENTER_PIN};

u8 CALC_u8EnterDigit(u8 *local_pu8Digits, u8 local_u8DigitsNum)
{
    u8 local_u8Digit = NO_PRESSED_KEY;
    u8 local_u8Index = 1;
    /* Loop Till Enter is Pressed */
    do
    {
        local_u8Digit = CALC_getPressedKey();
        switch (local_u8Digit)
        {
        case UP_PIN: if(local_u8Index == local_u8DigitsNum - 1)
        {
        	local_u8Index = 0;
        }
        else
        {
        	++local_u8Index;
        }

            break;
        case DOWN_PIN: if(local_u8Index == 0)
        {
        	local_u8Index = local_u8DigitsNum - 1;
        }
        else
        {
        	--local_u8Index;
        }

            break;
        }
        
        /* Update Number on LCD */
        HLCD_voidSendDATA(local_pu8Digits[local_u8Index]);
        HLCD_voidSendCommand(0b00010000);
    } while (local_u8Digit != ENTER_PIN);

    return local_pu8Digits[local_u8Index] - '0';
}


u8 CALC_u8EnterOperation(u8 *copy_pu8Operations)
{
    u8 local_u8Opearation = NO_PRESSED_KEY;
    u8 local_u8Index = 0;

    /* Loop Till Enter is Pressed */
    do
    {
        local_u8Opearation = CALC_getPressedKey();
        switch (local_u8Opearation)
        {
        case UP_PIN:
            ++local_u8Index;
            break;
        case DOWN_PIN:
            --local_u8Index;
            break;
        }
        /* Update Operation on LCD */
        HLCD_voidSendDATA(copy_pu8Operations[local_u8Index % 4]);
        HLCD_voidSendCommand(0b00010000);

    } while (local_u8Opearation != ENTER_PIN);
    return copy_pu8Operations[local_u8Index % 4];
}

u8 CALC_getPressedKey(void)
{
    u8 local_u8PressedKey = 1;
    u8 local_u8Key;
    while (local_u8PressedKey == 1)
    {
        for (local_u8Key = 0; local_u8Key < 3; local_u8Key++)
        {
            local_u8PressedKey = MDIO_u8GetPinValue(BUTTONS_PORT, CALC_u8Keys[local_u8Key]);

            /*  if a key is pressed, loop till key is released */
            if (local_u8PressedKey == 0)
            {
                while (MDIO_u8GetPinValue(BUTTONS_PORT, CALC_u8Keys[local_u8Key]) == 0)
                    ;
                break;
            }
        }
    }
    return CALC_u8Keys[local_u8Key];
}

void CALC_voidInit()
{
    for (u8 local_u8Key = 0; local_u8Key < 3; local_u8Key++)
    {
        MDIO_voidSetPinDirection(BUTTONS_PORT, CALC_u8Keys[local_u8Key], DIO_U8_INTIAL_INPUT);
        MDIO_voidSetPinValue(BUTTONS_PORT, CALC_u8Keys[local_u8Key], DIO_U8_INPUT_PULLUP);
    }
    HLCD_voidInit();
    HLCD_voidSendDATA('1');
    HLCD_voidSendDATA('+');
    HLCD_voidSendDATA('1');
    
}
