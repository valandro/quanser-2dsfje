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
 * @file pidController.c
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Source file for PID Controller utilized in quanser-2dsfje project for ENG10032
 */


// Project Headers
#include "pidController.h"

/*
* @brief Structure holding PID Controller data
*
* This structure is used to manage all PID Controller data. Gain variables are set here, for example.
*/
struct SPidController
{
  double Kp; /**Proportional Gain in PID Controller. */
  double Ki; /**Integral Gain in PID Controller. */
  double Kd; /**Derivative Gain in PID Controller. */
  double jointDesiredPosition; /**Variable that holds the desired position for the joint to go to. Is informed in the terminal by the user.*/
} pidController;

/*
* @brief Variable for setting gains in PID Controller
*
* This function sets a gain value for the PID Controller
* @param gainType Enumerator indicating which Gain the user wants to set.
* @param newGainValue Value to set the selected gain.
* @return void
*/
void set_gain_value(EPidControllerGains gainType, double newGainValue)
{
  switch(gainType)
  {
    case eKp:
    {
      pidController.Kp = newGainValue;
    }
    break;
    case eKi:
    {
      pidController.Ki = newGainValue;
    }
    break;
    case eKd:
    {
      pidController.Kd = newGainValue;
    }
    break;
    default:
    {
      printf("Unkown PID Controller gain type, cannot set gain value.\n");
    }
  }
}
