#ifndef END_COURSE_SENSORS_H
#define END_COURSE_SENSORS_H

#ifdef __cplusplus
extern "C"
{
#endif

#define ELB_1 1
#define ELB_2 2

#define END_REACHED 1
#define END_NOT_REACHED 0

extern int read_end_course_sensors(int sensor);

#ifdef __cplusplus
};
#endif

#endif