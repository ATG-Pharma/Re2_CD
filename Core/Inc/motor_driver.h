/*
 * motor_driver.h
 *
 *  Created on: May 11, 2021
 *      Author: ATG
 */

#ifndef INC_MOTOR_DRIVER_H_
#define INC_MOTOR_DRIVER_H_
// option 1
// user input, for now we are predefining this value
#define Entered_Dispense_Time 1// user input
#define Entered_Volume_Dispense 0.5 // user input
#define Dispense_Time (Entered_Dispense_Time*1000)

////constant parameters
#define Volume_Per_Revolution 1.59 // constant value dependent on Stepper motor data sheet and cartridge design
#define PPR 6400// constant value

////  algorithm to calculate RPM of stepper motor from the user input data
#define Required_Rotation_For_Entered_Volume (Entered_Volume_Dispense/Volume_Per_Revolution)
#define Required_Rotation_InDegree = Required_Rotation_For_Entered_Volume*360
#define RPM (Required_Rotation_For_Entered_Volume/(Entered_Dispense_Time/60))
//
//// algorithm to achieve the RPM calculated from the user input by controlling prescaler and PWM frequency
#define Required_PWM_Freq  ((RPM*PPR)/60)
#define PRESCALER  ((320000/50)/Required_PWM_Freq)
#define Rev_Per_Min = ((TIM_CLOCKSOURCE_INTERNAL*60)/((htim4.Prescaler)(htim4.period+1)(PPR)))


//option 2
//void dispense(int volume,int time)
//{
//    int  Required_Rotation_For_Entered_Volume = (int) (volume/Volume_Per_Revolution);
//	int Required_Rotation_InDegree = (int) (Required_Rotation_For_Entered_Volume*360);
//	int RPM = (int) (Required_Rotation_For_Entered_Volume/(time/60));
//	HAL_Delay(100);
//	int Required_PWM_Freq= (int)((RPM*PPR)/60);
//	int PRESCALER = (int)((320000/50)/Required_PWM_Freq);
//}
#endif /* INC_MOTOR_DRIVER_H_ */
