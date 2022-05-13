/**********************************************************
 * @file        MADC_interface.h
 * @author      Yasser M. AbdelKader (m.abdelkader.yasser@gmail.com)
 * @brief       ADC Driver - MCAL
 * @version     0.1
 * @date        2022-04-22
 * @copyright   Copyright (c) 2022
 **********************************************************/
#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_


/** \defgroup copy_u8Channel Analog Channels */ 
/** @{ */
#define ADC0_SINGLE_ENDED_INPUT			0   /**< ADC0 */
#define ADC1_SINGLE_ENDED_INPUT			1   /**< ADC1 */
#define ADC2_SINGLE_ENDED_INPUT			2   /**< ADC2 */
#define ADC3_SINGLE_ENDED_INPUT			3   /**< ADC3 */
#define ADC4_SINGLE_ENDED_INPUT			4   /**< ADC4 */
#define ADC5_SINGLE_ENDED_INPUT			5   /**< ADC5 */
#define ADC6_SINGLE_ENDED_INPUT			6   /**< ADC6 */
#define ADC7_SINGLE_ENDED_INPUT			7   /**< ADC7 */
/** @} */


/**********************************************************
 *  \fn     void MADC_voidADCInit(void); 
 *  \brief  Intiate ADC Prephiral
 *  \param  None
 *  \return None
**********************************************************/
void MADC_voidADCInit(void);

/**********************************************************
 *  \fn     u16 MADC_u16GetChannelReading(u8 copy_u8Channel); 
 *  \brief  Get Channel Reading
 *  \param  copy_u8Channel ADC Channel to be read.
 *          it takes the following values:
 * \li \c   ADC0_SINGLE_ENDED_INPUT
 * \li \c   ADC1_SINGLE_ENDED_INPUT
 * \li \c   ADC2_SINGLE_ENDED_INPUT
 * \li \c   ADC3_SINGLE_ENDED_INPUT
 * \li \c   ADC4_SINGLE_ENDED_INPUT
 * \li \c   ADC5_SINGLE_ENDED_INPUT
 * \li \c   ADC6_SINGLE_ENDED_INPUT 
 * \li \c   ADC7_SINGLE_ENDED_INPUT
 * \return \c u16 reading of the channel
**********************************************************/
u16 MADC_u16GetChannelReading(u8 copy_u8Channel);

#endif /* INCLUDE_1_MCAL_5_ADC_MADC_INTERFACE_H_ */
