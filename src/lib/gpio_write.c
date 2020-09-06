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
 * @file gpio_write.c
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Source file for GPIO Read wrappers utilized in quanser-2dsfje project for ENG10032
 */

// Project Headers
#include <gpio.h>

// C Headers
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/**
	Write char value for a given GPIO pin
	@param path: the path to GPIO value file
    @param value: the value to write
	@return: the number of char written
**/
int gpio_write(const char path[], char value)
{
    int gpio;
    int n;

    if ((gpio = open(path, O_WRONLY)) == -1)
    {
        return -1;
    }

    lseek(gpio, 0, SEEK_SET);
    n = write(gpio, &value, sizeof value);

    close(gpio);
    return n;
}
