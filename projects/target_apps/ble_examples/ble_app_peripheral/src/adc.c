#include "adc.h"
#include "platform.h"
#include "cs1237.h"

static adc_config_t adc_configs[MAX_CHAN_NR];


adc_err_t adc_read(uint8_t chan, ad_channel_t *info)
{
    
		if(CS1237_ReadAD(chan,info) == 0)
		{
			 return ADC_ERR_BUSY;
		}
    return ADC_ERR_NONE;
}


adc_err_t adc_config(uint8_t chan, adc_config_t *config)
{
   CS1237_Init(AD_HZ_40);
	 return ADC_ERR_NONE;
}


adc_err_t adc_ready(uint8_t chan)
{
	  if(CS1237_Ready(chan))
		{
			 return ADC_ERR_NONE;
		}
    return ADC_ERR_BUSY;
}
adc_err_t adc_power(uint8_t chan, uint8_t en)
{
		CS1237_Power(chan,en);
		return ADC_ERR_NONE;
}