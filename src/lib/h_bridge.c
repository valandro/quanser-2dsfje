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

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <galileo2io.h>
#include <HBridge.h>

/**
	Read voltage on current_sensor_output, and return the current.
	@return: Eletrical current at the moment on current_sensor_output.
**/
double getCurrentSensor()
{
        int fd;
        char data_str[80];
        double scale;
        int raw;
        double current;

        if((fd=open("/sys/bus/iio/devices/iio:device0/in_voltage0_raw",O_RDONLY)) < 0)
        {
                perror("Opening in_voltage0raw:");
                return -1;
        }

        pgets(data_str,sizeof data_str,"/sys/bus/iio/devices/iio:device0/in_voltage0_scale");
        scale=atof(data_str)/1000.0;

		lseek(fd,0,SEEK_SET);
		read(fd,data_str,sizeof data_str);
		raw=atoi(data_str);

		current = (raw*scale)/0.1;

        close(fd);

        return current;
}

/**
	Read voltage on thermal flag.
	@return: Return 0 to under 147ºCelsius, and 1 to equal or greater than 147ºCelsius.
**/

int getThermalFlag()
{
	int fd;
        char data_str[80];
        double scale;
        int raw;
        double voltage;
        int returnInt;

        if((fd=open("/sys/bus/iio/devices/iio:device0/in_voltage1_raw",O_RDONLY)) < 0)
        {
                perror("Opening in_voltage1raw:");
                return -1;
        }

        pgets(data_str,sizeof data_str,"/sys/bus/iio/devices/iio:device0/in_voltage1_scale");
        scale=atof(data_str)/1000.0;

		lseek(fd,0,SEEK_SET);
		read(fd,data_str,sizeof data_str);
		raw=atoi(data_str);

		voltage = (raw*scale);

		if(voltage < 0.7)
			returnInt = THERMAL_FLAG_OFF;
		else
			if(voltage > 3)
				returnInt = THERMAL_FLAG_ON;
			else
				returnInt = -1;

        close(fd);

        return returnInt;
}
