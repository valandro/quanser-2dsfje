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
 * @file pwm.c
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Source file for PWM functions utilized in quanser-2dsfje project for ENG10032
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include <pwm.h>

/**
 	Setup PWM for initialization
    \see See pwm.h for all constant values.
**/
void pwm_init()
{
    pwm_write_enable(PWM_ENABLE_PATH, 1);
    pwm_write_period(PWM_PERIOD_PATH, PWM_PERIOD);
    pwm_write_duty_cycle(PWM_DUTY_CYCLE_PATH, 0.5, PWM_PERIOD);
}

/**
 	This function stop the PWM signal gerenation by writing '0' into enable
    \see See pwm.h for checking PWM_ENABLE_PATH value.
**/
void pwm_stop()
{
    pwm_write_enable(PWM_ENABLE_PATH, 0);
}

/**
	Convert frequency Hz to Period ns
	@param frequency: the frequency in Hz
	@return: the period in nano-seconds
**/
int pwm_frequency_to_period(const int frequency)
{
    return (int)(1000000000 / frequency);
}

/**
    Writes enable value to the pwm pin
    @param path: the path to pwm file
    @param enable: the enable value (int), either 1 or 0
    @return: the number of bytes written
**/
int pwm_write_enable(const char path[], const int enable)
{
    int pwm;
    int n;
    char flag;

    if (enable == 1)
    {
        flag = '1';
    }
    else if (enable == 0)
    {
        flag = '0';
    } else {
        return -1;
    }

    if ((pwm = open(path, O_WRONLY)) == -1)
    {
        return -1;
    }

    lseek(pwm, 0, SEEK_SET);
    n = write(pwm, &flag, sizeof flag);

    close(pwm);
    return n;
}

/**
    Writes periods (ns) to the pwm
    @param path: the path to pwm file
    @param period: the period in nano-seconds
    @return: the number of bytes written
**/
int pwm_write_period(const char path[], const int period)
{
    int pwm;
    int n;
    char data[80];

    if ((pwm = open(path, O_WRONLY)) == -1)
    {
        return -1;
    }

    snprintf(data, sizeof data, "%d", period);

    lseek(pwm, 0, SEEK_SET);
    n = write(pwm, &data, sizeof data);

    close(pwm);
    return n;
}

/**
    Writes periods (ns) to the pwm
    @param path: the path to pwm duty_cycle file
    @param duty_cycle: the percentage of duty cycle from 0.0 until 1.0
    @param period: the period in nano-seconds
    @return: the number of bytes written
**/
int pwm_write_duty_cycle(const char path[], const float duty_cycle, const int period)
{
    int pwm;
    int n;
    char data[80];

    if ((pwm = open(path, O_WRONLY)) == -1)
    {
        return -1;
    }

    snprintf(data, sizeof data, "%d", (int)(duty_cycle * period));

    lseek(pwm, 0, SEEK_SET);
    n = write(pwm, &data, sizeof data);

    close(pwm);
    return n;
}
