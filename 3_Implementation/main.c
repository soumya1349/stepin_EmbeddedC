

#include <avr/interrupt.h>
#include "config.h"

#include "user_utils.h"
#include "blinky.h"
#include "Temp_sensor.h"
#include "UART.h"
unsigned volatile FLAG1 =0 ,FLAG2 =0;
/**
 * @brief Initialize all the Peripherals and pin configurations
 *
 */

void peripheral_init(void)
{
	/* Configure Pin */
	DDRB |= (1 << DDB0);
	DDRB |= (1 << DDB1);

    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN)|(7<<ADPS0);

	DDRD&=~(1 << PD2);
	PORTD |=(1<<PD2);
	DDRD&=~(1 << PD3);
    PORTD |=(1<<PD3);

	EICRA|=(1<<ISC00)|(1<<ISC10);
	EIMSK |= (1<<INT0)|(1<<INT1);
	sei();
}


int main(void)
{
	/* Initialize Peripherals */
	peripheral_init();
 uint16_t temp;
 unsigned int ch;
	while(1)
	{
	    if(FLAG1==1)
        {
        change_led1_state(LED_ON);
		delay_ms(LED_ON_TIME);
        if(FLAG2==1)
        {
          change_led2_state(LED_ON);
          delay_ms(LED_ON_TIME);
          temp = ReadADC(0);
          delay_ms(200);
          //Display the temperature provided by temperature sensor
          if(temp>=0 && temp<=200)
            ch=20;
          if(temp>=210 && temp<=500)
            ch=25;
          if(temp>=510 && temp<=700)
            ch=29;
          if(temp>=710 && temp<=1024)
             ch=33;
          USARTWriteChar(ch);
          delay_ms(200);

        }
        else
        {
          change_led2_state(LED_OFF);
          delay_ms(LED_OFF_TIME);
        }
        }
        else
        {
        change_led1_state(LED_OFF);
		delay_ms(LED_OFF_TIME);
        }
	}
	return 0;
}

ISR(INT0_vect)
{
  FLAG1 =1;
}
ISR (INT1_vect)
{
    FLAG2 =1;
}
