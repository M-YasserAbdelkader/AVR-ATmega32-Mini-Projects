/*************************************************************
 * @file main.c
 * @author Yasser Mustafa
 * @brief Stop watch project
 * @version 0.1
 * @date 2022-04-14
 * @copyright Copyright (c) 2022
 *************************************************************/
#include "STD_TYPES.h"
#include "STOPWATCH_interface.h"
#include "HKPD_interface.h"
#include "HLCD_interface.h"
#include "util/delay.h"
void main(void)
{
    u8 local_u8StartFlag = 0;
    u8 local_u8arrClock[3] = {0};
    u8 local_u8Character[2][8] = {{0x11, 0x1D, 0x1D, 0x15, 0x0E, 0x04, 0x1F, 0x11},
                                  {0x00, 0x06, 0x06, 0x04, 0x1F, 0x04, 0x1F, 0x11}};

    /* Initiate Stop Watch */
    STOPWATCH_voidInit();

    while (1)
    {
        /* Adjust Stop Watch Hands till Start is pressed*/
        STOPWATCH_voidInit();
        do
        {
            local_u8StartFlag = STOPWATCH_u8AdjustClockHand();
        } while (local_u8StartFlag == 0);

        /* Set Hours, mins and seconds values */
        for (u8 local_u8HandsCounter = 0; local_u8HandsCounter < 3; local_u8HandsCounter++)
        {
            local_u8arrClock[local_u8HandsCounter] = STOPWATCH_u8CalculateClockHand(local_u8HandsCounter);
        }

        //     Adjust Mins and Secs to be < 60
        for (u8 local_u8HandCounter = 2; local_u8HandCounter > 0; local_u8HandCounter--)
        {
            local_u8arrClock[local_u8HandCounter - 1] += local_u8arrClock[local_u8HandCounter] / 60;
            local_u8arrClock[local_u8HandCounter] %= 60;
        }

        //     Display Clock in correct Form
        for (u8 local_u8HandsCounter = 0; local_u8HandsCounter < 3; local_u8HandsCounter++)
        {
            HLCD_voidGoToXY(0, local_u8HandsCounter * 3);
            STOPWATCH_u8DisplayNumber(local_u8arrClock[local_u8HandsCounter]);
        }
        //     Start Stop Watch
        HLCD_voidSendCommand(0b00001100);
        for (u8 local_u8Hours = 0; local_u8Hours <= local_u8arrClock[0]; local_u8Hours++)
        {
            HLCD_voidGoToXY(0, 0);
            STOPWATCH_u8DisplayNumber(local_u8arrClock[0] - local_u8Hours);
            for (u8 local_u8Mins = 0; local_u8Mins <= local_u8arrClock[1]; local_u8Mins++)
            {
                HLCD_voidGoToXY(0, 3);
                STOPWATCH_u8DisplayNumber(local_u8arrClock[1] - local_u8Mins);
                for (u8 local_u8Secs = 0; local_u8Secs <= local_u8arrClock[2]; local_u8Secs++)
                {
                    HLCD_voidGoToXY(0, 6);
                    STOPWATCH_u8DisplayNumber(local_u8arrClock[2] - local_u8Secs);
                    _delay_ms(1000);
                }
                local_u8arrClock[2] = 59;
            }
            local_u8arrClock[1] = 59;
        }
        HLCD_voidWriteSpecialCharacter(local_u8Character[0], 0, 1, 25);
        HLCD_voidWriteSpecialCharacter(local_u8Character[0], 0, 1, 24);
        HLCD_voidWriteSpecialCharacter(local_u8Character[0], 0, 1, 23);
        HLCD_voidWriteSpecialCharacter(local_u8Character[0], 0, 1, 22);
        HLCD_voidWriteSpecialCharacter(local_u8Character[0], 0, 1, 21);
        HLCD_voidGoToXY(0, 19);
        HLCD_voidSendString("***TIME!***");
        for (u8 i = 0; i < 16; i++)
        {
            HLCD_voidSendCommand(0b0011000);
            _delay_ms(100);
        }
        u8 local_u8PressedKey = HKPD_u8GetPresssedKey();
       for (u8 j = 0; j < 15; j++)
        {
            for (u8 i = 0; i < 2; i++)
            {
                HLCD_voidWriteSpecialCharacter(local_u8Character[i], i, 1, 25);
                HLCD_voidWriteSpecialCharacter(local_u8Character[i], i, 1, 24);
                HLCD_voidWriteSpecialCharacter(local_u8Character[i], i, 1, 23);
                HLCD_voidWriteSpecialCharacter(local_u8Character[i], i, 1, 22);
                HLCD_voidWriteSpecialCharacter(local_u8Character[i], i, 1, 21);
                _delay_ms(100);
            }
            
        }
    }
}
