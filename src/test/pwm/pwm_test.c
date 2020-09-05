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
    (atoi(period_value) == PWM_PERIOD) ? printf("SUCESS\n") : printf("FAILED\n");

    return 0;
}