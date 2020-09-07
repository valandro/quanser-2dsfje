// Copyright (C) 2020 Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.


/**
 * @file pid_ontroller.c
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Source file for PID Controller utilized in quanser-2dsfje project for ENG10032
 **/


// Project Headers
#include <pid_controller.h>

// C Headers
#include <stdio.h>

/**
* @brief Structure holding PID Controller data
*
* This structure is used to manage all PID Controller data. Gain variables are set here, for example.
**/
struct SPidController
{
  double Kp; /**Proportional Gain in PID Controller. */
  double Ki; /**Integral Gain in PID Controller. */
  double Kd; /**Derivative Gain in PID Controller. */
  double joint_desired_position; /**Variable that holds the desired position for the joint to go to. Is informed in the terminal by the user.*/
  double integral_sum_of_errors; /** Variable that holds all erro sum for integral part of PID calculation.*/
  double previous_error; /** Previous error, for derivative calculation. */
} pidController;

/**
* @brief Variable for setting gains in PID Controller
*
* This function sets a gain value for the PID Controller
* @param gain_type Enumerator indicating which Gain the user wants to set.
* @param new_gain_value Value to set the selected gain.
* @return void
**/
void set_gain_value(int gain_type, double new_gain_value)
{
  pidController.previous_error = 0.0;
  switch(gain_type)
  {
    case KP_GAIN:
    {
      pidController.Kp = new_gain_value;
    }
    break;
    case KI_GAIN:
    {
      pidController.Ki = new_gain_value;
    }
    break;
    case KD_GAIN:
    {
      pidController.Kd = new_gain_value;
    }
    break;
    default:
    {
      printf("Unkown PID Controller gain type, cannot set gain value.\n");
    }
  }
}

/**
* @brief Variable for sets PID target value
*
* This function sets a gain value for the PID Controller
* @param desired_value Target value position to PID controller.
* @return void
**/
void set_desired_position(float desired_value)
{
  pidController.joint_desired_position = desired_value;
}

/**
* @brief Runs PID Controller
*
* This function runs PID controller in order to reach the target value position set in PID data structure.
* @param joint_current_position Value of the current join position in radians
* @param pid_voltage_value Value of the PID Voltage value to be applie on motor
* @return float Error between desired position and current position
**/
float run_pid_controller(float joint_current_position, float* pid_voltage_value)
{
    float error = pidController.joint_desired_position - joint_current_position;
    float proportional_part = 0.0;
    float derivatide_part = 0.0;
    float integral_part = 0.0;

	
    pidController.integral_sum_of_errors += error;

    proportional_part = pidController.Kp * error;
    derivatide_part = pidController.Kd * (error - pidController.previous_error);
    integral_part = pidController.Ki * pidController.integral_sum_of_errors;

    // Calculates the Voltage according to errors and PID parts
    float pid_controller_target_voltage = proportional_part + derivatide_part + integral_part;

    // Saturate the PID Voltage value
    if(pid_controller_target_voltage < -MOTOR_MAX_VOLTAGE_PID)
    {
      pid_controller_target_voltage = -MOTOR_MAX_VOLTAGE_PID;
    } else if (pid_controller_target_voltage > MOTOR_MAX_VOLTAGE_PID)
    {
      pid_controller_target_voltage = MOTOR_MAX_VOLTAGE_PID;
    }

    *pid_voltage_value = pid_controller_target_voltage;
    
    pidController.previous_error = error;
    // Return PID error
    return error;
}
