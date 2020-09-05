#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <gpio.h>
#include <pwm.h>

int main(int argc,char * argv[]) {
    printf("1. Test pwm_init()...\n");
    //when pwm_init() called
    pwm_init();
    //then
    //assert period writed
    printf("1.1 Assert PWM_PERIOD...\n");
    int period;
    char period_value[8];
    if ((period = open(PWM_PERIOD_PATH, O_RDONLY)) == -1)
    {
        printf("ERROR: opening period file.\n");
        return -1;
    }

    lseek(period, 0, SEEK_SET);
    read(period, &period_value, sizeof period_value);

    close(period);
    (atoi(period_value) == PWM_PERIOD) ? printf("SUCCESS\n") : printf("FAILED\n");

    //assert duty_cycle initial writed
    printf("1.2 Assert PWM_DUTY_CYCLE...\n");
    int duty_cycle;
    char duty_cycle_value[8];
    if ((duty_cycle = open(PWM_DUTY_CYCLE_PATH, O_RDONLY)) == -1)
    {
        printf("ERROR: opening duty_cycle file.\n");
        return -1;
    }

    lseek(duty_cycle, 0, SEEK_SET);
    read(duty_cycle, &duty_cycle_value, sizeof duty_cycle_value);

    close(duty_cycle);
    (atoi(duty_cycle_value) == (int)(PWM_PERIOD * 0.5)) ? printf("SUCCESS\n") : printf("FAILED\n");

    //assert PWM ENABLED writed
    printf("1.3 Assert PWM_ENABLED...\n");
    int enabled;
    char pwm_enabled_value;
    if ((enabled = open(PWM_ENABLE_PATH, O_RDONLY)) == -1)
    {
        printf("ERROR: opening duty_cycle file.\n");
        return -1;
    }

    lseek(enabled, 0, SEEK_SET);
    read(enabled, &pwm_enabled_value, sizeof pwm_enabled_value);

    close(enabled);
    (pwm_enabled_value == '1') ? printf("SUCCESS\n") : printf("FAILED\n");

    printf("2. Test pwm_stop()...\n");
    //when pwm_stop() called
    pwm_stop();
    //then
    //assert PWM ENABLED writed
    if ((enabled = open(PWM_ENABLE_PATH, O_RDONLY)) == -1)
    {
        printf("ERROR: opening duty_cycle file.\n");
        return -1;
    }

    lseek(enabled, 0, SEEK_SET);
    read(enabled, &pwm_enabled_value, sizeof pwm_enabled_value);

    close(enabled);
    (pwm_enabled_value == '0') ? printf("SUCCESS\n") : printf("FAILED\n");

    printf("3. Test pwm_frequency_to_period()...\n");
    //when pwm_frequency_to_period() called with 1K Hz
    period = pwm_frequency_to_period(1000);
    //then
    (PWM_PERIOD == period) ? printf("SUCCESS\n") : printf("FAILED\n");
    
    printf("4. Test pwm_write_enable()...\n");
    printf("4.1 Assert Invalid value...\n");
    //when pwm_write_enable() with invalid value
    int n = pwm_write_enable(PWM_ENABLE_PATH, 20);
    //then
    (n == -1) ? printf("SUCCESS\n") : printf("FAILED\n");
    printf("4.2 Assert enable...\n");
    //when pwm_write_enable() with 1 value
    n = pwm_write_enable(PWM_ENABLE_PATH, 1);
    if (n != 1) {
        printf("ERROR: writing enable file.\n");
        return -1;
    }

    if ((enabled = open(PWM_ENABLE_PATH, O_RDONLY)) == -1)
    {
        printf("ERROR: opening enable file.\n");
        return -1;
    }

    lseek(enabled, 0, SEEK_SET);
    read(enabled, &pwm_enabled_value, sizeof pwm_enabled_value);

    close(enabled);
    (pwm_enabled_value == '1') ? printf("SUCCESS\n") : printf("FAILED\n");

    printf("4.3 Assert disabled...\n");
    //when pwm_write_enable() with 1 value
    n = pwm_write_enable(PWM_ENABLE_PATH, 0);
    if (n != 1) {
        printf("ERROR: writing enable file.\n");
        return -1;
    }

    if ((enabled = open(PWM_ENABLE_PATH, O_RDONLY)) == -1)
    {
        printf("ERROR: opening enable file.\n");
        return -1;
    }

    lseek(enabled, 0, SEEK_SET);
    read(enabled, &pwm_enabled_value, sizeof pwm_enabled_value);

    close(enabled);
    (pwm_enabled_value == '0') ? printf("SUCCESS\n") : printf("FAILED\n");

    return 0;
}