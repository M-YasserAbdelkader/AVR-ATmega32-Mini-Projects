/*************************************************************
 * @file      HKPD_interface.h
 * @author 	  Yasssr Mustafa
 * @brief 	  HKEYPAD Driver - HAL
 * @version   0.1
 * @date      2022-04-03
 * @copyright Copyright (c) 2022
 *************************************************************/
#ifndef HKPD_INTERFACE_H_
#define HKPD_INTERFACE_H_

#define HKPD_U8_NO_PRESSED_KEY	' '

/*************************************************************
 *  \fn     u8 HKPD_u8GetPresssedKey(void); 
 *  \brief  Get Pressed Key
 *  \param  None
 *  \return On Success, function returns the pressed Key or
 *          HKPD_U8_NO_PRESSED_KEY if no key is pressed 
*************************************************************/
u8 HKPD_u8GetPresssedKey(void);

#endif /* HKPD_INTERFACE_H_ */
