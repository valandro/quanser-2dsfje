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
 * @file end_course_sensors.c
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Source file for End of Course Sensors utilized in quanser-2dsfje project for ENG10032
 */

#include <gpio.h>
#include <end_course_sensors.h>

/*
    Paths to GPIO (Gen2)
*/
static const char gpio_path[2][29] = {
    "/sys/class/gpio/gpio14/value", // ELB1
    "/sys/class/gpio/gpio13/value"  //ELB2
};

/**
	Read data from the end of course sensor specified.
	@param sensor: Elbow's sensor.
	@return: Flag if sensor already reached the end of course or not.
**/
int read_end_course_sensors(int sensor)
{
    char value;

    if (sensor != ELB_1 && sensor != ELB_2)
    {
        // Invalid sensor identifier
        return -1;
    }

    value = gpio_read(gpio_path[sensor]);

    return value == '1' ? END_NOT_REACHED : END_REACHED;
}
