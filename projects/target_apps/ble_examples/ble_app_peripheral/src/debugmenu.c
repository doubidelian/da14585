#include "gui.h"
#include <stdlib.h>
#include "debugmenu.h"
#include "scaler.h"
#include "batty.h"
#include "key.h"
#include "dispatcher.h"
#include "param.h"
#include "audio.h"

static uint32 tick = 0;
void debug_menu_init_func(uint8 prev)
{
		gui_clear_screen();
}
int diff = 0;
static void gui_show_ad(scaler_info_t *sif)
{
	uint8 i = 0;
	char buf[16] = {0,};
	static float old_ad[4] = {0,};
	#if 1
	for(; i < 4; i++)
	{
			char buf[16] = {'a','d','0',':',0,};
			buf[2]=0x31 + i;
			//snprintf(buf+4,16,"%08d",sif->filter_ad);
			diff = abs(old_ad[i] - sif->adArrs[i]);
			if(diff > 100){
				//  format_weight(buf+4,16,sif->adArrs[i],1,8);
				snprintf(buf+4,12,"% 8d",(int)sif->adArrs[i]);
					
			}
			old_ad[i] = sif->adArrs[i];
			snprintf(buf+4,12,"% 8d",(int)sif->adArrs[i]);
			//format_weight(buf+4,16,sif->adArrs[i],1,8);
			LCD_P6x8Str(10,i*2 + 1,buf);
	}
	#endif
	//snprintf(buf,16,"%8d",sif->filter_ad);
	//LCD_P6x8Str(10,2 ,buf);
} 
void debug_menu_gui_func(void)
{

	scaler_info_t * sif = scaler_get_info();
	if(sif != NULL){
			gui_show_ad(sif);
	}
	return;
	tick++;
	if(tick % 10 == 0)
	{
			char buf[16] = {0,};
			snprintf(buf,16,"%4d",tick);
			LCD_P6x8Str(1,1,buf); 
	}

	
}
void debug_menu_key_event(key_msg_t* msg)
{
	if(msg->key == KEY_ZERO)
	{
			gui_show(MENU_MAIN);
	}
	else if(msg->key == KEY_PWR)
	{
			gui_show(MENU_MAIN);
	}
}
