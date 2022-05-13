/**********************************************************
 * @file        MADC_private.h
 * @author      Yasser M. AbdelKader (m.abdelkader.yasser@gmail.com)
 * @brief       ADC Driver - MCAL
 * @version     0.1
 * @date        2022-04-22
 * @copyright   Copyright (c) 2022
 **********************************************************/
#ifndef MADC_PRIVATE_H_
#define MADC_PRIVATE_H_

/** \defgroup ADC_REFERENCE_VOLTAGE Refrence Voltages paramters */
/** @{ */
#define ADC_AREF            1  /**< AREF, Internal Vref turned on */
#define ADC_AVCC            2  /**< AVCC with external capacitor at VREF */
#define ADC_INTERNAL_2_56V  3  /**< Internal 2.56V voltage reference */
/** @} */

/** \defgroup ADC_RESULT_ADJUST Result Adjust Values */ 
/** @{ */
#define ADC_LEFT_ADJUST     1  /**< Left Adjust Result */
#define ADC_RIGHT_ADJUST    2  /**< Right Adjust Result */
/** @} */



/** \defgroup ADC_PRESCALER ADC Division Factors */
/** @{ */
#define DIVISION_FACTOR_2       1   /**< Division Factor: 2 */
#define DIVISION_FACTOR_4       2   /**< Division Factor: 4 */
#define DIVISION_FACTOR_8       3   /**< Division Factor: 8 */
#define DIVISION_FACTOR_16      4   /**< Division Factor: 16 */
#define DIVISION_FACTOR_32      5   /**< Division Factor: 32 */
#define DIVISION_FACTOR_64      6   /**< Division Factor: 64 */
#define DIVISION_FACTOR_128     7   /**< Division Factor: 128 */
/** @} */
#endif /* INCLUDE_1_MCAL_5_ADC_MADC_PRIVATE_H_ */
