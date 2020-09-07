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
 * @file h_bridge.c
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Source file for H Bridge utilized in quanser-2dsfje project for ENG10032
 */

// Project Headers
#include <galileo2io.h>
#include <h_bridge.h>
#include <gpio.h>
#include <pwm.h>

// C Headers
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/**
	Read voltage on current_sensor_output, and return the current.
	@return: Eletrical current at the moment on current_sensor_output.
**/
double get_current_sensor()
{
    int fd;
    char data_str[80];
    double scale;
    int raw;
    double current;

    if((fd=open(CURRENT_SENSOR_PATH_RAW,O_RDONLY)) < 0)
    {
      printf("H_BRIDGE ERROR: Cannot open current sensor path.\n");
      return -1;
    }

    pgets(data_str, sizeof data_str, CURRENT_SENSOR_PATH_SCALE);
    scale = atof(data_str) / 1000.0;

		lseek(fd, 0, SEEK_SET);
		read(fd, data_str, sizeof data_str);
		raw = atoi(data_str);

		current = (raw * scale)/ 0.1;

    close(fd);

    return current;
}

/**
	Read voltage on thermal flag.
	@return: Return 0 to under 147ºCelsius, and 1 to equal or greater than 147ºCelsius.
**/
int get_thermal_flag()
{
	int fd;
  char data_str[80];
  double scale;
  int raw;
  double voltage;
  int returnInt;

  if((fd=open(THERMAL_FLAG_PATH_RAW,O_RDONLY)) < 0)
  {
    printf("H_BRIDGE ERROR: Cannot open thermal flag path.\n");
    return -1;
  }

  pgets(data_str,sizeof data_str,THERMAL_FLAG_PATH_SCALE);
  scale=atof(data_str)/1000.0;
	lseek(fd,0,SEEK_SET);
	read(fd,data_str,sizeof data_str);
	raw=atoi(data_str);

	voltage = (raw*scale);

	if(voltage < 0.7)
  {
    returnInt = THERMAL_FLAG_OFF;
  } else if(voltage > 3)
  {
	   returnInt = THERMAL_FLAG_ON;
  }	else
  {
	   returnInt = -1;
  }

  close(fd);

  return returnInt;
}

/**
*	Enables the H Bridge
* @return int Greater than zero if the initialization is successful
**/
int h_bridge_enable()
{
  if(gpio_write(H_BRIDGE_ENABLE_PIN, '1') > 0)
  {
    return 1;
  } else
  {
    return -1;
  }
}

/**
*	Disables the H Bridge
* @return int Greater than zero if the initialization is successful
**/
int h_bridge_disable()
{
  if(gpio_write(H_BRIDGE_ENABLE_PIN, '0') > 0)
  {
    return 1;
  } else
  {
    return -1;
  }
}

/**
*	@brief Set motor voltage
*
* Duty Cycle = A*Voltage + B
* 0          = A*(-27)   + B
* 1          = A*(27)    + B
*------------------------------
* A = 1 / 54 , B = 1 / 2
* @return int Greater than zero if the voltage setting was successful
* @param voltage Voltage value to be set into motor
**/
int h_bridge_set_motor_voltage(float voltage)
{
  // Check if desired voltage is valid
  if(voltage > MOTOR_MAX_VOLTAGE || voltage < -MOTOR_MAX_VOLTAGE)
  {
    printf("H_BRIDGE ERROR: Voltage applied is out of range.\n");
    return -1;
  }

  float duty_cycle = 0.0;

  duty_cycle = (1 / (2 * MOTOR_MAX_VOLTAGE)) * voltage + 0.5;

  // Setting PWM duty cycle value
  if(pwm_write_duty_cycle(PWM_DUTY_CYCLE_PATH, duty_cycle, PWM_PERIOD) <= 0)
  {
    printf("H_BRIDGE ERROR: Cannot write PWM duty cycle\n");
    return -1;
  }

  // PWM Duty cycle is set
  return 1;
}
