/**********************************************************
 * @file        MADC_register.h
 * @author      Yasser M. AbdelKader (m.abdelkader.yasser@gmail.com)
 * @brief       ADC Driver - MCAL 
 * @version     0.1
 * @date        2022-04-22
 * @copyright   Copyright (c) 2022
 **********************************************************/
#ifndef MADC_REGISTER_H_
#define MADC_REGISTER_H_

#define ADC_U8_ADMUX_REGISTER			*((volatile u8 *)	0x27)

/*
 * Reference Selection Bits
 * options:
 * REFS0 = 0	REFS1 = 0	---> AREF, Internal Vref turned off
 * REFS0 = 1	REFS1 = 0	---> AVCC with external capactor at AREF
 * REFS0 = 0	REFS1 = 1	---> Reserved
 * REFS0 = 1	REFS1 = 1	---> Internal 2.56V Reference Voltage with Capacitor at AREF
 */
#define ADC_ADMUX_REFS0				6
#define ADC_ADMUX_REFS1				7

/*
 * ADC Left Adjust Result
 * options:
 * ADLAR = 0 --->	right adjust the result
 * ADLAR = 1 --->	left adjust the result
 */
#define ADC_ADMUX_ADLAR				5


#define ADC_U8_ADCSRA_REGISTER			*((volatile u8 *)	0x26)

/*
 * ADC Enable
 * options:
 * ADEN = 0	---> TURN OFF ADC
 * ADEN = 1	---> TURN ON ADC
 */
#define ADC_ADCSRA_ADEN				7

/*
 * ADC Start Conversion
 * Option:
 * Write one to start conversion
 */
#define ADC_ADCSRA_ADSC				6

/*
 * ADC Auto Trigger Enable
 * Options:
 * ADATE: 1 --> Auto Trigger Enable
 * ADATE: 0 --> Auto Trigger Disable
 */
#define ADC_ADCSRA_ADATE			5

/*
 * ADC Intrrupt Flag
 */
#define ADC_ADCSRA_ADIF				4

/*
 * ADC Intrrupt Enable
 * Options:
 * ADIE = 1 ---> Interrupt Enable
 * ADIE = 0 ---> Interrupt Disable
 */
#define ADC_ADCSRA_ADIE				3

#define ADC_ADCSRA_ADPS2			2
#define ADC_ADCSRA_ADPS1			1
#define ADC_ADCSRA_ADPS0			0


#define ADC_U8_ADCH_REGISTER			*((volatile u8 *)	0x25)

#define ADC_U8_ADCL_REGISTER			*((volatile u8 *)	0x24)
#define ADC_U16_ADCL_REGISTER			*((volatile u16 *)	0x24)

#define ADC_PRESCALAR_MUSK  0b11111000
#define ADC_CHANNEL_REGISTER_MUSK 0b11100000


#endif /* INCLUDE_1_MCAL_5_ADC_MADC_REGISTER_H_ */
