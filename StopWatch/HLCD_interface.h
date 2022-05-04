/*************************************************************
 * @file HLCD_interface.h
 * @author Yasser Mustafa
 * @brief LCD Driver - HAL Layer
 * @version 0.1
 * @date 2022-04-10
 * @copyright Copyright (c) 2022
 *************************************************************/

#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_

/*************************************************************
 *  \fn     void HLCD_voidInit(void); 
 *  \brief  Intialize LCD
 *  \param  None
 *  \return None 
*************************************************************/
void HLCD_voidInit(void);

/*************************************************************
 *  \fn     void HLCD_voidSendCommand(u8 copy_u8Command);
 *  \brief  Send Command to LCD
 *  \param  copy_u8Command 
 *  \return None 
*************************************************************/
void HLCD_voidSendCommand(u8 copy_u8Command);

/*************************************************************
 *  \fn     void HLCD_voidSendDATA(u8 copy_u8Data);
 *  \brief  Send Data to LCD
 *  \param  copy_u8Data a u8 character
 *  \return None 
*************************************************************/
void HLCD_voidSendDATA(u8 copy_u8Data);

/*************************************************************
 *  \fn     void HLCD_voidSendString(const char* Copy_pcString);
 *  \brief  write a string to LCD
 *  \param  Copy_pcString a pointer to a string of characters  
 *  \return None 
*************************************************************/
void HLCD_voidSendString(const u8* Copy_pcString);

/*************************************************************
 *  \fn     void HLCD_voidGoToXY(u8 copy_u8XPos, u8 copy_u8YPos);
 *  \brief  write a string to LCD
 *  \param  copy_u8XPos a u8 number from 0 to 15 representing x position 
 *  \param  copy_u8YPos  a u8 number from 0 to 1 representing y position  
 *  \return None 
*************************************************************/
void HLCD_voidGoToXY(u8 copy_u8XPos, u8 copy_u8YPos);

void HLCD_voidWriteSpecialCharacter(u8* copy_pu8Pattern, u8 copy_u8PatternNumber, u8 copy_u8XPos, u8 copy_u8YPos);

void HLCD_voidWriteNumber(u32 copy_u32Number);

u8 HLCD_u8GetBusyFlag(void);

u8 HLCD_u8GetAddress(void);

u8 HLCD_u8ReadCharacter(void);
#endif /* HLCD_INTERFACE_H_ */
