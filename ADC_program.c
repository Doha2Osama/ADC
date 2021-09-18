/*
File Name:ADC_program
Author:DohaOsama
Date:18/9/2021
Description:ADC Driver 
version 1.0
*/
#include "../../LIB/STD_TYPES.h"//library  contains all datatypes needed in this program
#include "../../LIB/BIT_MATH.h"//library contains clear and set and get and toggle bit it will be used in this program 
#include "ADC_interface.h"//it is a header file that contain functions prototypes and some definitions and it will be very important to the user
#include "ADC_private.h"//it is a header file that contains information very important in the program but it is not important for the user
#include "ADC_config.h"//it is a header file that make the ADC_program to be flexible for all users
void ADC_voidInit(void)
{
	//select voltage reference 
	#if  ADC_REFERENCEVOLT==ADC_AREF
		CLEAR_BIT(ADC_ADMUX,ADMUX_REFS0);
		CLEAR_BIT(ADC_ADMUX,ADMUX_REFS1);
	#elif ADC_REFERENCEVOLT==ADC_AVCC
		SET_BIT(ADC_ADMUX,ADMUX_REFS0);
		CLEAR_BIT(ADC_ADMUX,ADMUX_REFS1);
	#elif ADC_REFERENCEVOLT==ADC_InternalVOLt
		SET_BIT(ADC_ADMUX,ADMUX_REFS0);
		SET_BIT(ADC_ADMUX,ADMUX_REFS1);	
	#endif
	//activate the left adjust
	#if  ADC_ADJUST==LEFT
		SET_BIT(ADC_ADMUX,ADMUX_ADLAR);
	#elif  ADC_ADJUST==RIGHT
		CLEAR_BIT(ADC_ADMUX,ADMUX_ADLAR);
	#endif	
	//enable peripheral
	#if  ADC_PERIPHERAL==TURNON
		SET_BIT(ADC_ADCSRA,ADCSRA_ADEN);
	#elif  ADC_PERIPHERAL==TURNOFF
		CLEAR_BIT(ADC_ADCSRA,ADCSRA_ADEN);
	#endif
	//set the prescaler 
	    ADC_ADCSRA&=ADC_PRES_MASK;
		ADC_ADCSRA|=ADC_PRESC;
}
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
		ADC_ADMUX&=ADC_ADMUX_MASK;
		//set the required channel
		ADC_ADMUX|=Copy_u8Channel;
		//start conversion
		SET_BIT(ADC_ADCSRA,ADCSRA_ADSC);
		//Polling untiL the conversion complete flag is set
		while(GET_BIT(ADC_ADCSRA,ADCSRA_ADIF)==0);
		SET_BIT(ADC_ADCSRA,ADCSRA_ADIF);
		//Return the reading
		return ADC_ADC;
			
	
	
}