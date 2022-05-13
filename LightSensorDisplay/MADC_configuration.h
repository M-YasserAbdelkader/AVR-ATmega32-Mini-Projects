/**********************************************************
 * @file        MADC_configuration.h
 * @author      Yasser M. AbdelKader (m.abdelkader.yasser@gmail.com)
 * @brief       ADC Driver - MCAL
 * @version     0.1
 * @date        2022-04-22
 * @copyright   Copyright (c) 2022
 **********************************************************/
#ifndef MADC_CONFIGURATION_H_
#define MADC_CONFIGURATION_H_

/**********************************************************************
 * \def     ADC_REFERENCE_VOLTAGE
 * \brief   Select Voltage reference
 * \details The following options are availble:
 * \arg \c  ADC_AREF            AREF, Internal Vref turned on
 * \arg \c  ADC_AVCC            AVCC with external capacitor at VREF
 * \arg \c  ADC_INTERNAL_2_56V  Internal 2.56V voltage reference
 *                              with external capacitor at AREF
 **********************************************************************/
#define ADC_REFERENCE_VOLTAGE       ADC_AVCC

/**********************************************************************
 * \def     ADC_RESULT_ADJUST
 * \brief   Adjust result
 * 
 * \details if no more than 8-bit precision is requered, select ADC_LEFT_ADJUST. 
 *          if all 10-bit precision is requered, select ADC_RIGHT_ADJUST.
 * \details The following options are availble:
 * 
 * \arg \c  ADC_LEFT_ADJUST   Left Adjust Result
 * \arg \c  ADC_RIGHT_ADJUST  Right Adjust Result
 **********************************************************************/
#define ADC_RESULT_ADJUST           ADC_LEFT_ADJUST

/**********************************************************************
 * \def     ADC_PRESCALER
 * \brief   ADC Prescaler Select
 * 
 * \details determine the division factor between the XTAL frequency
 *          and the input clock to the ADC
 * \details The following options are availble:
 * 
 * \arg \c  DIVISION_FACTOR_2       Division Factor: 2
 * \arg \c  DIVISION_FACTOR_4       Division Factor: 4
 * \arg \c  DIVISION_FACTOR_8       Division Factor: 8
 * \arg \c  DIVISION_FACTOR_16      Division Factor: 16
 * \arg \c  DIVISION_FACTOR_32      Division Factor: 32
 * \arg \c  DIVISION_FACTOR_64      Division Factor: 64
 * \arg \c  DIVISION_FACTOR_128     Division Factor: 128
 **********************************************************************/
#define ADC_PRESCALER               DIVISION_FACTOR_16

#endif /* MADC_CONFIGURATION_H_ */
