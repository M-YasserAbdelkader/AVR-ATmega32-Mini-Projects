/*************************************************************
 * @file calculator.h
 * @author 	  Yasssr Mustafa
 * @brief 	  
 * @version   0.1
 * @date      2022-04-03
 * @copyright Copyright (c) 2022
 *************************************************************/ 

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#define BUTTONS_PORT     DIO_U8_PORTA
#define UP_PIN           DIO_U8_PIN0
#define DOWN_PIN         DIO_U8_PIN1
#define ENTER_PIN        DIO_U8_PIN2

#define NO_PRESSED_KEY 3

u8 CALC_u8EnterDigit(u8* copy_pu8Digits, u8 copy_u8DigitsNum);
u8 CALC_u8EnterOperation(u8* copy_pu8Operations);

u8 CALC_getPressedKey(void);

void CALC_voidInit();

#endif /* CALCULATOR_H_ */
