#include	"KEY.h"
#include "../../head_extern.h"
#include	"../motor/motor.h"
#include	"../comparator/comparator.h"
#include	"../led/led.h"
#include	"../hot/hot.h"
extern byte motor_state_temp;
extern byte hot_mode_temp;
byte char_cnt,char_cnt2;
void key_init(void)
{
	$ s1 IN,pull;
	 char_cnt=0;
	 char_cnt2=0;
}

void check_charging(void)
{
	if(hot_Ad>0 &&hot_Ad<10)
	{
		char_cnt++;
		if(char_cnt>100)
		{
			char_cnt=100;
			f_charging_full=1;
		}
	}
	else
	{
		
	}
	if(hot_Ad==0)
	{
		char_cnt2++;
		if(char_cnt2>100)
		{
			char_cnt2=100;
			f_charging_full=0;
		}	
	}
	else
	{
		char_cnt2=0;
	}
}
void key_scan(void)
{
	if(f_key_scan )
	{
		f_key_scan=0;
		if(hot_Ad<=10)
		{
			s1_even();
		}
		else
		{
			led_mode=0;
		}
//		check_charging();
	}
}
extern byte led_mode_temp;
void s1_even(void)
{
	if(s1==0)
	{
		if(S1_count<250)	S1_count++;
		if(S1_count>200 &&S1_count<210) //³¤°´
		{
			led_mode=0;
			S1_count=220;
				
		}
	}
	else
	{	
		if(S1_count>3 && S1_count<200)
		{
			led_mode++;
			if(led_mode>9)led_mode=1;
			led_mode_temp=99;
		}
		S1_count=0;
	
		work_time=0;
	}
}

