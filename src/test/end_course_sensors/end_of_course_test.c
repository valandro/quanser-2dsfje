#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <gpio.h>
#include <end_course_sensors.h>

int main(int argc,char * argv[]) {
    printf("1. Test ELB1 REACHED...\n");
    // Write '0' at ELB1
    int res = 0;
    res = gpio_write("/sys/class/gpio/gpio14/value", '0');
    if (res == -1) {
        printf("ERROR: error writing 0 at ELB1 sensor.\n");
        return -1;
    }
    //when read_end_courses_sensors(ELB1)
    int elb1 = read_end_course_sensors(ELB_1);
    //then
    (elb1 == END_REACHED) ? printf("SUCCESS\n") : printf("FAILED\n");

    printf("2. Test ELB1 NOT REACHED...\n");

    // Write '1' at ELB1
    res = 0;
    res = gpio_write("/sys/class/gpio/gpio14/value", '1');
    if (res == -1) {
        printf("ERROR: error writing 1 at ELB1 sensor.\n");
        return -1;
    }
    //when read_end_courses_sensors(ELB1)
    elb1 = read_end_course_sensors(ELB_1);
    //then
    (elb1 == END_NOT_REACHED) ? printf("SUCCESS\n") : printf("FAILED\n");

    printf("3. Test ELB2 REACHED...\n");
    // Write '0' at ELB2
    res = 0;
    res = gpio_write("/sys/class/gpio/gpio13/value", '0');
    if (res == -1) {
        printf("ERROR: error writing 0 at ELB2 sensor.\n");
        return -1;
    }
    //when read_end_courses_sensors(ELB2) 
    int elb2 = read_end_course_sensors(ELB_2);
    //then
    (elb2 == END_REACHED) ? printf("SUCCESS\n") : printf("FAILED\n");

    printf("4. Test ELB2 NOT REACHED...\n");
    // Write '1' at ELB2
    res = 0;
    res = gpio_write("/sys/class/gpio/gpio13/value", '1');
    if (res == -1) {
        printf("ERROR: error writing 1 at ELB2 sensor.\n");
        return -1;
    }
    //when read_end_courses_sensors(ELB2) 
    elb2 = read_end_course_sensors(ELB_2);
    //then
    (elb1 == END_NOT_REACHED) ? printf("SUCCESS\n") : printf("FAILED\n");

    return 0;
}