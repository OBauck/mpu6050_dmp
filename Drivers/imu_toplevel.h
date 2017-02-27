#ifndef IMU_H__
#define IMU_H__
#include "imu.h"

void imu_init(void);
void imu_periodic(void);
void imu_get_values(Axis3f *gyro);


#endif // IMU_H__
