#include "config.h"
#include "blinky.h"
void change_led1_state(uint8_t state)
{
	LED_PORT = (state << LED_PIN1);
}
void change_led2_state(uint8_t state)
{
	LED_PORT = (state << LED_PIN2);
}