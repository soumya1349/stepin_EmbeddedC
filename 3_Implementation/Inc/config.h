/**
 * @file project_config.h
 * @author Soumya
 * @brief  Configuration of port
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CONFIG_H
#define CONFIG_H
#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */

#define LED_PORT (PORTB)    /**< LED Port Number */
#define LED_PIN1  (PORTB0)   /**< LED Pin number  */
#define LED_PIN2 (PORTB1)



#endif // PROJECT_CONFIG_H_INCLUDED
