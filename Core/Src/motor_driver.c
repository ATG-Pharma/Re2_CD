/*
 * motor_driver.c
 *
 *  Created on: May 11, 2021
 *      Author: ATGDa
 */
#include "motor_driver.h"
#include "stm32f4xx.h"
#include "main.h"


TIM_HandleTypeDef htim4;
uint8_t i;



void Manual_Mode()
{
	// Forward rotation
	if(!(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_5)))// checks for button pressed or not
		 {
			while((!(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_5)))); // wait for button to be released
				 htim4.Instance->PSC =(PRESCALER+1);
				 for(i=0;i<=Dispense_Time;i++){
					 HAL_GPIO_WritePin(MOTOR_DIR_GPIO_Port, MOTOR_DIR_Pin, GPIO_PIN_RESET);// for motor rotation in clockwise direction
				 	 }
			 }
	else if(!(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_6)))// checks for button pressed or not
			{
			while((!(HAL_GPIO_ReadPin (GPIOA,GPIO_PIN_6)))); // wait for button to be released
				htim4.Instance->PSC =(PRESCALER+1);
				for(i=0;i<=Dispense_Time;i++){
				 HAL_GPIO_WritePin(MOTOR_DIR_GPIO_Port, MOTOR_DIR_Pin, GPIO_PIN_SET);// for motor rotation in clockwise direction
				}
			}
	else
		 {
			HAL_TIM_PWM_Stop_IT(&htim4,TIM_CHANNEL_1);
		 }
	// Reverse rotation


}

