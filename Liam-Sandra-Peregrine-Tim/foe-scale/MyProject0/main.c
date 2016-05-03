#include "atmel_start.h"
#include "atmel_start_pins.h"

int main(void)
{
	system_init();
	gpio_set_pin_direction(PA04,GPIO_DIRECTION_OUT);
	gpio_set_pin_level(PA04,false);
	gpio_set_pin_direction(PA05,GPIO_DIRECTION_OUT);
	gpio_set_pin_level(PA05,false);
	gpio_set_pin_direction(PA03,GPIO_DIRECTION_OUT);
	gpio_set_pin_level(PA03,true);
	
	
	/* Replace with your application code */
	while(1) {
	}
}
