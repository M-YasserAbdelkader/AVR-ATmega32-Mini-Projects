/***************************************/
/*	AUTHOR		: Yasser Mustafa Ahmed
 * 	Description	: DIO DRIVER
 *	DATE		: 03 JAN 2022
 *	VERSION		: V01
 ****************************************/

#ifndef INCLUDE_MCAL_DIO_PRIVATE_H_
#define INCLUDE_MCAL_DIO_PRIVATE_H_

/***********************************************************************/
 /* PORT A Register Mapping	*/
/***********************************************************************/
#define DIO_U8_PORTA_REG	*((volatile u8 *)	0x3B)
#define	DIO_U8_DDRA_REG		*((volatile u8 *)	0x3A)
#define DIO_U8_PINA_REG		*((volatile u8 *)	0x39)

/***********************************************************************/
 /* PORT B Register Mapping	*/
/***********************************************************************/
#define DIO_U8_PORTB_REG	*((volatile u8 *)	0x38)
#define	DIO_U8_DDRB_REG		*((volatile u8 *)	0x37)
#define DIO_U8_PINB_REG		*((volatile u8 *)	0x36)

/***********************************************************************/
 /* PORT C Register Mapping	*/
/***********************************************************************/
#define DIO_U8_PORTC_REG	*((volatile u8 *)	0x35)
#define	DIO_U8_DDRC_REG		*((volatile u8 *)	0x34)
#define DIO_U8_PINC_REG		*((volatile u8 *)	0x33)

/***********************************************************************/
 /* PORT D Register Mapping	*/
/***********************************************************************/
#define DIO_U8_PORTD_REG	*((volatile u8 *)	0x32)
#define	DIO_U8_DDRD_REG		*((volatile u8 *)	0x31)
#define DIO_U8_PIND_REG		*((volatile u8 *)	0x30)

/***********************************************************************/
/***********************************************************************/


#endif /* INCLUDE_MCAL_DIO_PRIVATE_H_ */
