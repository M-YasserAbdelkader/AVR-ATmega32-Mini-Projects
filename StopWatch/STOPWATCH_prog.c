#include "STD_TYPES.h"
#include "STOPWATCH_interface.h"
#include "HLCD_interface.h"
#include "HKPD_interface.h"
#include "DIO_interface.h"

void STOPWATCH_voidInit(void)
{
    MDIO_voidInit();
    HLCD_voidInit();
    HLCD_voidSendString("00:00:00");
}
u8 STOPWATCH_u8AdjustClockHand(void)
{
    u8 local_u8StartFlag = 0;
    u8 local_u8PressedKey = HKPD_U8_NO_PRESSED_KEY;
    static u8 local_u8HandHour = 0;
    HLCD_voidGoToXY(0, local_u8HandHour * 3);
    do
    {
        local_u8PressedKey = HKPD_u8GetPresssedKey();
        if ((local_u8PressedKey >= '0') && (local_u8PressedKey <= '9'))
        {
            /* Write number to LCD */
            HLCD_voidSendDATA(local_u8PressedKey);

            /* Shift cursor position to the left to maintain its position */
            HLCD_voidSendCommand(SHIFT_LEFT);
        }
        else if (local_u8PressedKey == 'R')
        {
            HLCD_voidGoToXY(0, (local_u8HandHour * 3) + 1);
        }
        else if (local_u8PressedKey == 'L')
        {
            HLCD_voidGoToXY(0, local_u8HandHour * 3);
        }
        else if (local_u8PressedKey == START)
        {
            /* Raise Start Flag and exit adjusting mode */
            local_u8StartFlag = 1;
            break;
        }
    } while (local_u8PressedKey != ENTER);
    if (local_u8HandHour < 2)
    {
        /* Adjust Next Clock Hand */
        local_u8HandHour++;
    }
    else
    {
        /* Return Clock Hands To Hours index  */
        local_u8HandHour = 0;
    }
    return local_u8StartFlag;
}

u8 STOPWATCH_u8CalculateClockHand(u8 copy_u8ClockHand)
{
    u8 local_u8ClockHand = 0;
    HLCD_voidGoToXY(0, copy_u8ClockHand * 3);
    local_u8ClockHand = HLCD_u8ReadCharacter();
    local_u8ClockHand -= '0';
    local_u8ClockHand *= 10;
    HLCD_voidGoToXY(0, copy_u8ClockHand * 3 + 1);
    local_u8ClockHand += (HLCD_u8ReadCharacter() - '0');
    return local_u8ClockHand; 

}

void STOPWATCH_u8DisplayNumber(u8 copy_u8Number)
{
    HLCD_voidWriteNumber(copy_u8Number/10);
    HLCD_voidWriteNumber(copy_u8Number%10);
}
