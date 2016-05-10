#include "atmel_start.h"
#include "atmel_start_pins.h"

int main(void)
{
	system_init();
	
	// initialize pins for RGB LED
	gpio_set_pin_direction(PA04,GPIO_DIRECTION_OUT);
	gpio_set_pin_level(PA04,true);
	gpio_set_pin_direction(PA05,GPIO_DIRECTION_OUT);
	gpio_set_pin_level(PA05,true);
	gpio_set_pin_direction(PA03,GPIO_DIRECTION_OUT);
	gpio_set_pin_level(PA03,true);
	
	// initialize pins for serial communication
	gpio_set_pin_direction(SCK,GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(CONV,GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(SDI,GPIO_DIRECTION_IN);

	
	TIMER_0_example();
	
	

	/* Replace with your application code */
	while(1) {
}