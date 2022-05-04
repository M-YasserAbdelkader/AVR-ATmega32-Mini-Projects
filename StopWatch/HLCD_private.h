/*************************************************************
 * @file HLCD_private.h
 * @author Yasser Mustafa
 * @brief LCD Driver - HAL Layer
 * @version 0.1
 * @date 2022-04-10
 * @copyright Copyright (c) 2022
 *************************************************************/

#ifndef INCLUDE_3_HAL_2_HLCD_HLCD_PRIVATE_H_
#define INCLUDE_3_HAL_2_HLCD_HLCD_PRIVATE_H_

#define RS_PIN_DISPLAY_DATA			1
#define	RS_PIN_INSTRUCTION_CODE		0

#define	RW_PIN_READ_OPERATION		1
#define	RW_PIN_WRITE_OPERATION		0


#define E_PIN_HIGH					1
#define E_PIN_LOW					0

#define HLCD_PORT_OUTPUT			0xff

#define HLCD_PIN_OUTPUT				1


#define NUMBER_OF_CHARACTERS		8

#define CLEAR_DISPLAY_COMMAND       1
#define RETURN_HOME 0b00000010


#endif /* INCLUDE_3_HAL_2_HLCD_HLCD_PRIVATE_H_ */
