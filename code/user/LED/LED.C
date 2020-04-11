#include	"led.h"
#include "../../head_extern.h"
#include	"../key/key.h"
#include	"../motor/motor.h"
byte char_mode,char_mode_temp;
void led_init(void)
{ 
	$ led_r out,high;
	led_r=led_off;
	$ led_g out,high;
	led_g=led_off;
	$ led_b out,high;
	led_b=led_off;
	char_mode_temp=99;
	char_mode=0;

}
byte r_num,g_num,b_num,step,r_maxnum,g_maxnum,b_maxnum;
byte pwm_time2,pwm_time,pwm_time3,led_mode_temp;
void led_pwm(void)
{
	if(pwm_time<r_num)
	{
		led_r=led_on;
	}
	else if(pwm_time<100)
	{
		led_r=led_off;
	}
	else
	{
		pwm_time=0;
	}

	if(pwm_time2<g_num)
	{
		led_g=led_on;
	}
	else if(pwm_time2<100)
	{
		led_g=led_off;
	}
	else
	{
		pwm_time2=0;
	}
	if(pwm_time3<b_num)
	{
		led_b=led_on;
	}
	else if(pwm_time3<100)
	{
		led_b=led_off;
	}
	else
	{
		pwm_time3=0;
	}
}

void led_mode1(void)
{
	if(led_mode_temp !=led_mode)
	{
		led_mode_temp=led_mode;
		led_r=0;
		led_g=0;
		led_b=0;
		pwm_time=0;
		pwm_time2=0;
		pwm_time3=0;
		led_time=0;
		r_num=0;
		g_num=0;
		b_num=0;
		led_r=0;
		led_g=0;
		led_b=0;
		r_maxnum=40;
		g_maxnum=0;
		b_maxnum=0;
		step=0;
	}
	if(led_time>10)
	{
		led_time=0;
		if(step==0) //ºì
		{
			r_num++;
			if(r_num>101)
			{
				step++;
			}
			if(g_num) g_num--;
			if(b_num) b_num--;
		}
		else if(step==1) //ÂÌ
		{
			g_num++;
			if(g_num>101)
			{
				step++;
			}
			if(r_num) r_num--;
			if(b_num) b_num--;	
		}
		else if(step==2) //À¶
		{
			b_num++;
			if(b_num>101)
			{
				step++;
			}
			if(r_num) r_num--;
			if(g_num) g_num--;	
		}
		else if(step==3) //ºì
		{
			r_num++;
			if(r_num>101)
			{
				step++;
			}
			if(b_num) b_num--;
			if(g_num) g_num--;	
		}
		else if(step==4) //À¶ÂÌ
		{
			g_num++;
			b_num++;
			if(g_num>101 && b_num>101)
			{
				step=0;
			}
			if(r_num) r_num--;
		}
	
	}
	led_pwm();
}
void led_mode2(void)
{
	if(led_mode_temp !=led_mode)
	{
		led_mode_temp=led_mode;
		led_r=0;
		led_g=0;
		led_b=0;
		led_time=0;
	}
	if(led_time<200)
	{
		led_r=led_on;
		led_g=led_off;
		led_b=led_off;
	}
	else if(led_time<400)
	{
		led_r=led_off;
		led_g=led_on;
		led_b=led_off;
	}
	else if(led_time<600)
	{
		led_r=led_off;
		led_g=led_off;
		led_b=led_on;
	}
	else if(led_time<800)
	{
		led_r=led_on;
		led_g=led_on;
		led_b=led_on;
	}
	else if(led_time<1000)
	{
		led_r=led_on;
		led_g=led_on;
		led_b=led_off;
	}
	else if(led_time<1200)
	{
		led_r=led_off;
		led_g=led_on;
		led_b=led_on;
	}
	else if(led_time<1400)
	{
		led_r=led_on;
		led_g=led_off;
		led_b=led_on;
	}
	else
	{
		led_time=0;
	}
}

void led_even(void)
{
//	hot_Ad=121;
	if(hot_Ad<2)  //Î´³äµç
	{
		char_mode=1;
		if(char_mode != char_mode_temp)
		{
			char_mode_temp=char_mode;
			led_mode_temp=99;
		}
		switch(led_mode)
		{
			case 0:
				led_r=led_off;
				led_g=led_off;
				led_b=led_off;
				break;
			case 1:
				led_mode2();
				break;
			case 2:
				led_mode1();
				break;
			case 3:
				if(led_mode_temp !=led_mode)
				{
					led_mode_temp=led_mode;
				led_time=0;
				}
				if(led_time<100)
				{
					led_r=led_on;
					led_g=led_off;
					led_b=led_off;
				}
				else if(led_time<150)
				{
					led_r=led_off;
					led_g=led_off;
					led_b=led_off;
				}
				else
				{
					led_time=0;
				}
				break;
			case 4:
				if(led_mode_temp !=led_mode)
				{
					led_mode_temp=led_mode;
					led_time=0;
				}
				if(led_time<100)
				{
					led_r=led_off;
					led_g=led_on;
					led_b=led_off;
				}
				else if(led_time<150)
				{
					led_r=led_off;
					led_g=led_off;
					led_b=led_off;
				}
				else
				{
					led_time=0;
				}
				break;
			case 5:
				if(led_mode_temp !=led_mode)
				{
					led_mode_temp=led_mode;
					led_time=0;
				}
				if(led_time<100)
				{
					led_r=led_off;
					led_g=led_off;
					led_b=led_on;
				}
				else if(led_time<150)
				{
					led_r=led_off;
					led_g=led_off;
					led_b=led_off;
				}
				else
				{
					led_time=0;
				}
				break;
			case 6:
				if(led_mode_temp !=led_mode)
				{
					led_mode_temp=led_mode;
					led_time=0;
				}
				if(led_time<100)
				{
					led_r=led_on;
					led_g=led_on;
					led_b=led_on;
				}
				else if(led_time<150)
				{
					led_r=led_off;
					led_g=led_off;
					led_b=led_off;
				}
				else
				{
					led_time=0;
				}
				break;
			case 7:
				if(led_mode_temp !=led_mode)
				{
					led_mode_temp=led_mode;
					led_time=0;
				}
				if(led_time<100)
				{
					led_r=led_on;
					led_g=led_on;
					led_b=led_off;
				}
				else if(led_time<150)
				{
					led_r=led_off;
					led_g=led_off;
					led_b=led_off;
				}
				else
				{
					led_time=0;
				}
				break;
			case 8:
				if(led_mode_temp !=led_mode)
				{
					led_mode_temp=led_mode;
					led_time=0;
				}
				if(led_time<100)
				{
					led_r=led_off;
					led_g=led_on;
					led_b=led_on;
				}
				else if(led_time<150)
				{
					led_r=led_off;
					led_g=led_off;
					led_b=led_off;
				}
				else
				{
					led_time=0;
				}
				break;
			case 9:
				if(led_mode_temp !=led_mode)
				{
					led_mode_temp=led_mode;
					led_time=0;
				}
				if(led_time<100)
				{
					led_r=led_on;
					led_g=led_off;
					led_b=led_on;
				}
				else if(led_time<150)
				{
					led_r=led_off;
					led_g=led_off;
					led_b=led_off;
				}
				else
				{
					led_time=0;
				}
				break;
		}
	}
	else if(hot_Ad<10) //³äÂú
	{
		char_mode=2;
		if(char_mode != char_mode_temp)
		{
			char_mode_temp=char_mode;
			led_mode_temp=99;
		}
		led_r=led_off;
		led_g=led_off;
		led_b=led_off;
	}
	else	//³äµçÖÐ
	{
		char_mode=3;
		if(char_mode != char_mode_temp)
		{
			char_mode_temp=char_mode;
			led_mode_temp=99;
		}
		led_mode2();
	}
}


