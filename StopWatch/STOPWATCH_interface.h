#ifndef STOP_WATCH_INTERFACE_
#define STOP_WATCH_INTERFACE_

#define ENTER 'E'
#define START 'S'

void STOPWATCH_voidInit(void);

void STOPWATCH_voidSetHours(void);
void STOPWATCH_voidSetMins(void);
void STOPWATCH_voidSetSecs(void);

u8 STOPWATCH_u8AdjustClockHand(void);

u8 STOPWATCH_u8CalculateClockHand(u8 copy_u8ClockHand);

void STOPWATCH_u8DisplayNumber(u8 copy_u8Number);


#define SHIFT_LEFT  0b00010000
#endif