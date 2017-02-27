/* Copyright (c) 2015 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

/** @file
 * @defgroup tw_sensor_example main.c
 * @{
 * @ingroup nrf_twi_example
 * @brief TWI Sensor Example main file.
 *
 * This file contains the source code for a sample application using TWI.
 *
 */

#include <stdio.h>
#include "boards.h"
#include "app_util_platform.h"
#include "app_uart.h"
#include "app_error.h"
#include "nrf_drv_twi.h"
#include "nrf_delay.h"

#include "i2cdev.h"
#include "imu_toplevel.h"

//default pins are:
//SCL: SCL_PIN 3
//SDA: SDA_PIN 4
//INT: INT_IMU 31

/**
 * @brief Function for main application entry.
 */
int main(void)
{
	//RTT logging

	NRF_LOG_INIT();
	NRF_LOG_PRINTF("MPU6050 DMP example\r\n");

	i2cdev_initialize();
    i2cdev_enable(true);
	imu_init();

    while(true)
    {
		imu_periodic();
		nrf_delay_ms(10);
    }
}

/** @} */
