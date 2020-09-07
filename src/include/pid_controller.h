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
 * @file pidController.h
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Header file for PID Controller utilized in quanser-2dsfje project for ENG10032
 */

#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#define MOTOR_MAX_VOLTAGE_PID 27.0
#define ACCEPTABLE_PID_ERROR 0.02 // 2%
#define KP_GAIN 1
#define KI_GAIN 2
#define KD_GAIN 3

void set_desired_position(float desired_value);
void set_gain_value(int gainType, double newGainValue);
float run_pid_controller(float joint_current_position, float* pid_voltage_value);

 #endif //PIDCONTROLLER_H
