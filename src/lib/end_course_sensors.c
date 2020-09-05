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