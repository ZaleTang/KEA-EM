#ifndef _GETSIG_H
#define _GETSIG_H


//获取各通道AD值
#define AD0 adc_once(ADC_CHANNEL_AD4,ADC_8BIT)
#define AD1 adc_once(ADC_CHANNEL_AD5,ADC_8BIT)
#define AD2 adc_once(ADC_CHANNEL_AD6,ADC_8BIT)
#define AD3 adc_once(ADC_CHANNEL_AD7,ADC_8BIT)
#define AD5 adc_once(ADC_CHANNEL_AD15,ADC_8BIT)
#define AD4 adc_once(ADC_CHANNEL_AD14,ADC_8BIT)

void getsig(uint16_t *a);

#endif