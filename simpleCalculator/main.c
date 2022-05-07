/*************************************************************
 * @file      main.c
 * @author 	  Yasssr Mustafa
 * @brief 	  Simple calculator app using Keypad (1 X 4)
 *            and character LCD
 * @version   0.1
 * @date      2022-04-03
 * @copyright Copyright (c) 2022
 *************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "HLCD_interface.h"
#include "calculator.h"

u8 CALC_u8ArrDigits[10] = {'0', '1', '2', '3', '4',
                           '5', '6', '7', '8', '9'};
u8 CALC_u8ArrOperations[4] = {'+', '-', '*', '/'};
void main(void)
{

    u8 local_u8FirstDigit = 1;
    u8 local_u8SecondDigit = 1;
    u8 local_u8Operation = '+';
    /* Initiate calculator */

    while (1)
    {

        CALC_voidInit();
        /* Enter First Number */
        HLCD_voidGoToXY(0, 0);
        local_u8FirstDigit = CALC_u8EnterDigit(CALC_u8ArrDigits, 10);

        /* Enter Operation */
        HLCD_voidGoToXY(0, 1);
        local_u8Operation = CALC_u8EnterOperation(CALC_u8ArrOperations);

        /* Enter Second Number */
        HLCD_voidGoToXY(0, 2);
        if (local_u8Operation == '/')
        {
            local_u8SecondDigit = CALC_u8EnterDigit(CALC_u8ArrDigits + 1, 9);
        }
        else
        {
            local_u8SecondDigit = CALC_u8EnterDigit(CALC_u8ArrDigits, 10);
        }

        HLCD_voidGoToXY(0, 3);
        HLCD_voidSendDATA('=');
        switch (local_u8Operation)
        {
        case '+':
            HLCD_voidWriteNumber((u32)local_u8FirstDigit + (u32)local_u8SecondDigit);
            break;
        case '-':
            HLCD_voidWriteNumber((u32)local_u8FirstDigit - (u32)local_u8SecondDigit);
            break;
        case '*':
            HLCD_voidWriteNumber((u32)local_u8FirstDigit * (u32)local_u8SecondDigit);
            break;
        case '/':
            HLCD_voidWriteNumber((u32)local_u8FirstDigit / (u32)local_u8SecondDigit);
            break;
        }
        while (CALC_getPressedKey() != ENTER_PIN)
            ;
    }
}
