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
    pwm_write_period(PWM_PERIOD_PATH, PWM_PERIOD);
    // pwm_write_duty_cycle(PWM_DUTY_CYCLE_PATH, 0.5, PWM_PERIOD);
    // pwm_write_enable(PWM_ENABLE_PATH, 1);
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
    else
    {
        flag = '0';
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
