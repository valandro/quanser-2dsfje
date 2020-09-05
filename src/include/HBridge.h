#ifndef READ_AD_CURRENT
#define READ_AD_CURRENT

#ifdef __cplusplus
extern "C"
{
#endif

#define THERMAL_FLAG_OFF 0
#define THERMAL_FLAG_ON 1

extern double getCurrentSensor();
extern int getThermalFlag();

#ifdef __cplusplus
};
#endif

#endif
