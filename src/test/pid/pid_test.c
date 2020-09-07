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

// Project Headers
#include <gpio.h>
#include <pwm.h>
#include <pid_controller.h>
#include <decoder.h>
#include <h_bridge.h>

// C Headers
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <float.h>
#include <time.h>

int main(int argc,char * argv[])
{
  // Initialize PID, PWM, H Bridge, Decoder
  if(pwm_init() < 0)
  {
    printf("Error: Cannot init PWM on pid.");
    return -1;
  }

  set_gain_value(KP_GAIN, 10);
  set_gain_value(KI_GAIN, 0);
  set_gain_value(KD_GAIN, 0);

  if(h_bridge_enable() < 0)
  {
    printf("Error: Cannot init H Bridge on pid.");
    return -1;
  }

  if(decoder_init() < 0)
  {
    printf("Error: Cannot init Decoder on pid.");
    return -1;
  }

  float pid_error = FLT_MAX;
  float* pid_voltage_value_return = NULL;
  float joint_current_position = 0.0;
  // Run PID Controller until 2% Error
  while(pid_error > ACCEPTABLE_PID_ERROR)
  {
    // Read current joint position
    joint_current_position = get_decoder_position_radians();
    if(joint_current_position < 0)
    {
      printf("Error: Cannot read joint position.");
      return -1;
    }

    // Run PID Controller
    pid_error = run_pid_controller(joint_current_position , pid_voltage_value_return);

    // Set Motor voltage
    h_bridge_set_motor_voltage(*pid_voltage_value_return);

    // PID Sampling 100Hz
    usleep(10000);
  }

  if(pwm_stop() < 0)
  {
    printf("Error: Cannot stop PWM on pid.");
    return -1;
  }

  if(h_bridge_disable() < 0)
  {
    printf("Error: Cannot stop H Bridge on pid.");
    return -1;
  }

  if(decoder_end() < 0)
  {
    printf("Error: Cannot stop Decoder on pid.");
    return -1;
  }


  return 0;
}
