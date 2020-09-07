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
#include <pid_controller.h>

// C Headers
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <float.h>
#include <time.h>
#include <math.h>

int main(int argc,char * argv[])
{
  set_gain_value(KP_GAIN, 0.9);
  set_gain_value(KI_GAIN, 0.05);
  set_gain_value(KD_GAIN, 0.01);

  float pid_error = FLT_MAX;

  // Starting with 10
  float current_position_test = 0;

  // Setting desired position to 100
  set_desired_position(3.141519);

  // Not used
  float pid_voltage_return_dummy;
  
  int interations = 0;
  
  printf("Initial position %f, desired position 3.141519 \n", current_position_test);

  while(fabs(pid_error) > ACCEPTABLE_PID_ERROR)
  {
	interations++;
    pid_error = run_pid_controller(current_position_test, &pid_voltage_return_dummy);
    printf("PID Error after one PID run: %f.\n", fabs(pid_error));
    float teste = pid_voltage_return_dummy;

    // Simulating position advance
    current_position_test += teste;
  }
  printf("Final position: %f \n", current_position_test);
  printf("PID Successfully ended executing with error < 2%, attempts %d.\n",interations);
  return 0;
}
