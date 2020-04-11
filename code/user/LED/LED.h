void led_init(void);
void led_even(void);
void red_even(void);
void blue_even(void);
void led_breathing(void);
void led_blue_pwm(void);
void led_data_init(void);
void hot_led(void);

#define led_on	0
#define led_off 1

led_r equ pa.4 
led_g equ pa.3	
led_b equ pb.7