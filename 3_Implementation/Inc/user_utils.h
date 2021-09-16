/**
 * @file user_utils.h
 * @author Soumya
 * @brief Definations of delay
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef USER_UTILS_H_INCLUDED
#define USER_UTILS_H_INCLUDED
#include "config.h"
#include "util/delay.h"

/**
 * @brief Function to generate delay in micro seconds
 *
 * @param[in] delay_time Delay in Micro seconds
 *
 */
void delay_ms(uint32_t delay_time);


#endif // USER_UTILS_H_INCLUDED
