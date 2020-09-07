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
 * @file pwm.h
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Header file for PWM header utilized in quanser-2dsfje project for ENG10032
 */

#ifndef PWM_H
#define PWM_H

#define PWM_PERIOD 1000000
#define PWM_ENABLE_PATH "/sys/class/pwm/pwmchip0/pwm3/enable"
#define PWM_PERIOD_PATH "/sys/class/pwm/pwmchip0/device/pwm_period"
#define PWM_DUTY_CYCLE_PATH "/sys/class/pwm/pwmchip0/pwm3/duty_cycle"

#ifdef __cplusplus
extern "C"
{
#endif
    extern int pwm_init();
    extern int pwm_stop();
    extern int pwm_frequency_to_period(const int frequency);
    extern int pwm_write_enable(const char path[], const int enable);
    extern int pwm_write_period(const char path[], const int period);
    extern int pwm_write_duty_cycle(const char path[], const float duty_cycle, const int period);

#ifdef __cplusplus
};
#endif

#endif
