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
    extern void pwm_init();
    extern void pwm_stop();
    extern int pwm_frequency_to_period(const int frequency);
    extern int pwm_write_enable(const char path[], const int enable);
    extern int pwm_write_period(const char path[], const int period);
    extern int pwm_write_duty_cycle(const char path[], const float duty_cycle, const int period);

#ifdef __cplusplus
};
#endif

#endif