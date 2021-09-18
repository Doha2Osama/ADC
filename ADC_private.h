/*File Name:ADC_private.h
Author:DohaOsama
Date:19/9/2021 
version 1.1
*/
#ifndef ADC_PRIVATE

#define ADC_PRIVATE

#define ADC_ADMUX (*(volatile u8*)(0x27))//ADC multiplexer seection register

#define 	ADMUX_MUX0    0

#define 	ADMUX_MUX1    1

#define 	ADMUX_MUX2    2    

#define 	ADMUX_MUX3    3

#define 	ADMUX_MUX4    4

#define 	ADMUX_ADLAR   5

#define     ADMUX_REFS0   6

#define     ADMUX_REFS1   7

#define ADC_ADCSRA (*(volatile u8*)(0x26))//ADC control and status register

#define ADCSRA_ADPS0      0

#define ADCSRA_ADPS1      1

#define ADCSRA_ADPS2      2

#define ADCSRA_ADIE       3

#define ADCSRA_ADIF       4

#define ADCSRA_ADATE      5

#define ADCSRA_ADSC       6

#define ADCSRA_ADEN       7

#define ADC_ADCL (*(volatile u8*)(0x24))//ADC low register

#define ADC_ADCH (*(volatile u8*)(0x25))//ADC high register

#define ADC_ADC (*(volatile u16*)(0x24))//ADC register



#define ADC_AREF 		  0

#define ADC_AVCC 		  1

#define ADC_InternalVOLt  3

#define LEFT              1

#define RIGHT             0

#define TURNON			  0

#define TURNOFF			  1

#define DIV_BY_2          1

#define DIV_BY_4          2

#define DIV_BY_8          3

#define DIV_BY_16         4

#define DIV_BY_32         5

#define DIV_BY_64         6

#define DIV_BY_128        7

#define ADC_PRES_MASK     0xF8

#define ADC_ADMUX_MASK    0xE0

#endif