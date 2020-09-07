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
#include <h_bridge.h>
#include <galileo2io.h>
#include <pwm.h>

// C Headers
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char * argv[]) {
    printf("1. Test h_bridge_disable()...\n");
    int n = h_bridge_disable();
    if (n <= 0) 
    {
        printf("ERROR: cannot disable h bridge.\n");
        return -1; 
    }
    
    char result = gpio_read(H_BRIDGE_ENABLE_PIN);

    (result == '0') ? printf("SUCCESS\n") : printf("FAILED\n");

    printf("2. Test h_bridge_enable()...\n");
    n = h_bridge_enable();
    if (n <= 0) 
    {
        printf("ERROR: cannot disable h bridge.\n");
        return -1; 
    }
    
    result = gpio_read(H_BRIDGE_ENABLE_PIN);

    (result == '1') ? printf("SUCCESS\n") : printf("FAILED\n");
    
    printf("3. Test h_bridge_set_motor_voltage()...\n");
    printf("3.1 Assert VOLTAGE > MOTOR_MAX_VOLTAGE...\n");
    n = h_bridge_set_motor_voltage(MOTOR_MAX_VOLTAGE + 1.0);

    (n == -1) ? printf("SUCCESS\n") : printf("FAILED\n");

    printf("3.2 Assert VOLTAGE < -MOTOR_MAX_VOLTAGE...\n");
    n = h_bridge_set_motor_voltage(-MOTOR_MAX_VOLTAGE - 1.0);

    (n == -1) ? printf("SUCCESS\n") : printf("FAILED\n");

    printf("3.3 Assert VOLTAGE configured to +15V...\n");
    n = h_bridge_set_motor_voltage(15.0);

    if (n < 0)
    {
        printf("ERROR: cannot write voltage to h bridge.\n");
        return -1; 
    }

    // Assert duty cycle
    int duty_cycle;
    char duty_cycle_value[8];
    if ((duty_cycle = open(PWM_DUTY_CYCLE_PATH, O_RDONLY)) == -1)
    {
        printf("ERROR: opening duty_cycle file.\n");
        return -1;
    }

    lseek(duty_cycle, 0, SEEK_SET);
    read(duty_cycle, &duty_cycle_value, sizeof duty_cycle_value);

    (strcmp("777777", duty_cycle_value)) ? printf("SUCCESS\n") : printf("FAILED\n");
    close(duty_cycle);

    return 0;
}