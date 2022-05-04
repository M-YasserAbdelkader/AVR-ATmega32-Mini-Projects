/*************************************************************
 * @file 	  HKPD_private.h
 * @author 	  Yasssr Mustafa
 * @brief 	  HKEYPAD Driver - HAL
 * @version   0.1
 * @date      2022-04-03
 * @copyright Copyright (c) 2022
 *************************************************************/
#ifndef HKPD_PRIVATE_H_
#define HKPD_PRIVATE_H_

/*************************************************************
 * \def	COLUMN_NUMBER
 * defines the Number of columns
 * \def	ROW_NUMBER
 * defines the number of rows
 *************************************************************/
#define COLUMN_NUMBER	4
#define ROW_NUMBER		4

#define COLUMN_ARR	{HKPD_COL0_PIN,\
					 HKPD_COL1_PIN,\
					 HKPD_COL2_PIN,\
					 HKPD_COL3_PIN}

#define ROW_ARR		{HKPD_ROW0_PIN,\
					 HKPD_ROW1_PIN,\
					 HKPD_ROW2_PIN,\
					 HKPD_ROW3_PIN}

#define COLUMN_ACTIVE 		DIO_U8_OUTPUT_LOW	
#define COLUMN_INACTIVE		DIO_U8_OUTPUT_HIGH

#define KEY_PRESSED		0

#endif /* HKPD_PRIVATE_H_ */
