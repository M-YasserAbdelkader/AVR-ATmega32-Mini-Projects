/**********************************************************
 * @file        MADC_program.c
 * @author      Yasser M. AbdelKader (m.abdelkader.yasser@gmail.com)
 * @brief       ADC Driver - MCAL
 * @version     0.1
 * @date        2022-04-22
 * @copyright   Copyright (c) 2022
 **********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MADC_interface.h"
#include "MADC_register.h"
#include "MADC_configuration.h"
#include "MADC_private.h"

void MADC_voidADCInit(void)
{
/* Select ADC Reference Voltage */
#if ADC_REFERENCE_VOLTAGE == ADC_AREF

	CLR_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS0);
	CLR_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS1);

#elif ADC_REFERENCE_VOLTAGE == ADC_AVCC

	SET_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS0);
	CLR_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS1);

#elif ADC_REFERENCE_VOLTAGE == ADC_INTERNAL_2_56V

	SET_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS0);
	SET_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_REFS1);

#else
#error "Wrong Reference Voltage Selection"
#endif

/* Adjust Result  */
#if ADC_RESULT_ADJUST == ADC_LEFT_ADJUST

	SET_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_ADLAR);

#elif ADC_RESULT_ADJUST == ADC_RIGHT_ADJUST

	CLEAR_BIT(ADC_U8_ADMUX_REGISTER, ADC_ADMUX_ADLAR);

#else
#error "Wrong Adjust Result Selection"
#endif


	/*  Disable Auto Triggering (Not Configurable for now ) */ 
	CLR_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADATE);

	/* Set Prescaler */
	ADC_U8_ADCSRA_REGISTER &= ADC_PRESCALAR_MUSK;
	ADC_U8_ADCSRA_REGISTER |= ADC_PRESCALER;

	/* Enable Prescaler */
	SET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADEN);

}


u16 MADC_u16GetChannelReading(u8 copy_u8Channel)
{

	if (copy_u8Channel < ADC0_SINGLE_ENDED_INPUT || copy_u8Channel > ADC7_SINGLE_ENDED_INPUT)
	{
		/** \todo Handle the case as Error Input  */
	}
	else
	{
		
		ADC_U8_ADMUX_REGISTER &= ADC_CHANNEL_REGISTER_MUSK;
		ADC_U8_ADMUX_REGISTER |=copy_u8Channel;
		
		/* Start Conversiotn */
		SET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADSC);
		
		/* Polling Till converstion is complete */
		while (GET_BIT(ADC_U8_ADCSRA_REGISTER, ADC_ADCSRA_ADSC) == 1);
	}
	
#if ADC_RESULT_ADJUST == ADC_LEFT_ADJUST

	return ADC_U8_ADCH_REGISTER;

#elif ADC_RESULT_ADJUST == ADC_RIGHT_ADJUST
	return ADC_U16_ADCL_REGISTER;
#else
#error "Wrong Adjust Result Select"
#endif
}

