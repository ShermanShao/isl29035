/***********************************************************************************************************************
 * File Name    : isl29035.h
 * Description  : Contains data structures and functions used in i2c_sensor.h/c
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
 * SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2019 Renesas Electronics Corporation. All rights reserved.
 ***********************************************************************************************************************/


#ifndef I2C_SENSOR_H_
#define I2C_SENSOR_H_

#define ONE_BYTE                0x01
#define TWO_BYTE                0x02

#define MEASURE_PAYLOAD_SIZE    0x03        //measurement enable data length
#define ACCELERO_DELAY          0xC8
#define SENSOR_READ_DELAY       0x03
#define ENABLE_BIT              0x08
#define DATA_REGISTERS          0x06

/* Accelerometer internal register whichever consumed here */
#define DEVICE_ID_REG           0x00
#define DEVICE_SIGNATURE        0xE5
#define DEVICE_POWER_CTL_REG    0x2D
#define DEVICE_AXIS_DATA        0x32
#define SENSOR_DATA_SIZE        0x06

//ISL29035
#define ISL29035_ID_REG           0x00
#define ISL29035_SIGNATURE        0xE5
#define ISL29035_POWER_CTL_REG    0x2D
#define ISL29035_AXIS_DATA        0x32

#define ISL29035_DATA_SIZE        0x06

#define ISL29035_I2C_ADDR       (0x44)
#define ISL29035_I2C_INTF       (0)

#define CONFIG_ISL29035_MODE_ALS                    1
#define CONFIG_ISL29035_LUX_RANGE_1K                1
#define CONFIG_ISL29035_INTEGRATION_TIME_6500         1

/* Register address */
#define ISL29035_COMMAND_I_REG      0x00
#define ISL29035_OPMODE_SHIFT       5
#define ISL29035_OPMODE_MASK        (7 << ISL29035_OPMODE_SHIFT)
#define ISL29035_INT_BIT_SHIFT      2
#define ISL29035_INT_BIT_MASK       (1 << ISL29035_INT_BIT_SHIFT)
#define ISL29035_INT_PRST_SHIFT     0
#define ISL29035_INT_PRST_MASK      (3 << ISL29035_INT_BIT_SHIFT)

#define ISL29035_OPMODE_OFF     0
#define ISL29035_OPMODE_ALS_ONCE    1
#define ISL29035_OPMODE_IR_ONCE     2
#define ISL29035_OPMODE_ALS_CONT    5
#define ISL29035_OPMODE_IR_CONT     6

#define ISL29035_COMMAND_II_REG     0x01
#define ISL29035_LUX_RANGE_SHIFT    0
#define ISL29035_LUX_RANGE_MASK     (3 << ISL29035_LUX_RANGE_SHIFT)
#define ISL29035_ADC_RES_SHIFT      2
#define ISL29035_ADC_RES_MASK       (3 << ISL29035_ADC_RES_SHIFT)

#define ISL29035_DATA_LSB_REG       0x02
#define ISL29035_DATA_MSB_REG       0x03
#define ISL29035_INT_LT_LSB_REG     0x04
#define ISL29035_INT_LT_MSB_REG     0x05
#define ISL29035_INT_HT_LSB_REG     0x06
#define ISL29035_INT_HT_MSB_REG     0x07

#define ISL29035_REG_DEVICE_ID      0x0F
#define ISL29035_DEVICE_ID_SHIFT    0x03
#define ISL29035_DEVICE_ID_MASK     (0x7 << ISL29035_DEVICE_ID_SHIFT)
#define ISL29035_DEVICE_ID          0x5
#define ISL29035_BOUT_SHIFT         0x07
#define ISL29035_BOUT_MASK          (0x01 << ISL29035_BOUT_SHIFT)

#define ISL29035_CHIP_ID          (0x28)
//#define ISL29035_CHIP_ID          (0x2C)

#if CONFIG_ISL29035_MODE_ALS
    #define ISL29035_ACTIVE_OPMODE      ISL29035_OPMODE_ALS_CONT
    #define ISL29035_ACTIVE_CHAN        SENSOR_CHAN_LIGHT
#elif CONFIG_ISL29035_MODE_IR
    #define ISL29035_ACTIVE_OPMODE      ISL29035_OPMODE_IR_CONT
    #define ISL29035_ACTIVE_CHAN        SENSOR_CHAN_IR
#endif

#define ISL29035_ACTIVE_OPMODE_BITS     \
    (ISL29035_ACTIVE_OPMODE << ISL29035_OPMODE_SHIFT)

#if CONFIG_ISL29035_LUX_RANGE_1K
    #define ISL29035_LUX_RANGE_IDX      0
    #define ISL29035_LUX_RANGE      1000
#elif CONFIG_ISL29035_LUX_RANGE_4K
    #define ISL29035_LUX_RANGE_IDX      1
    #define ISL29035_LUX_RANGE      4000
#elif CONFIG_ISL29035_LUX_RANGE_16K
    #define ISL29035_LUX_RANGE_IDX      2
    #define ISL29035_LUX_RANGE      16000
#elif CONFIG_ISL29035_LUX_RANGE_64K
    #define ISL29035_LUX_RANGE_IDX      3
    #define ISL29035_LUX_RANGE      64000
#endif

#define ISL29035_LUX_RANGE_BITS         \
    (ISL29035_LUX_RANGE_IDX << ISL29035_LUX_RANGE_SHIFT)

#if CONFIG_ISL29035_INTEGRATION_TIME_26
    #define ISL29035_ADC_RES_IDX        3
#elif CONFIG_ISL29035_INTEGRATION_TIME_410
    #define ISL29035_ADC_RES_IDX        2
#elif CONFIG_ISL29035_INTEGRATION_TIME_6500
    #define ISL29035_ADC_RES_IDX        1
#elif CONFIG_ISL29035_INTEGRATION_TIME_105K
    #define ISL29035_ADC_RES_IDX        0
#endif

#define ISL29035_ADC_RES_BITS           \
    (ISL29035_ADC_RES_IDX << ISL29035_ADC_RES_SHIFT)


/** Error code definitions */
#define ISL29035_OK                         (0)
#define ISL29035_E_NULL_PTR                 (-1)
#define ISL29035_E_COM_FAIL                 (-2)
#define ISL29035_E_DEV_NOT_FOUND            (-3)


#define ISL29035_LUX_RANGE_1000        (0)
#define ISL29035_LUX_RANGE_4000        (1)
#define ISL29035_LUX_RANGE_16000       (2)
#define ISL29035_LUX_RANGE_64000       (3)

#define ISL29035_ADC_RES_65536         (16)
#define ISL29035_ADC_RES_4096          (12)
#define ISL29035_ADC_RES_256           (8)
#define ISL29035_ADC_RES_16            (4)

/*****************************************************************************/
/* type definitions */
typedef int8_t (*isl29035_com_fptr_t)(uint8_t dev_addr, uint8_t reg_addr,
        uint8_t *data, uint16_t len);

typedef void (*isl29035_delay_fptr_t)(uint32_t period);

struct isl29035_dev {
    /*! Chip Id */
    uint8_t chip_id;
    /*! Device Id */
    uint8_t id;
    /*! 0 - I2C , 1 - SPI Interface */
    uint8_t interface;

    uint8_t adc_res;

    uint8_t adc_range;

    uint8_t adc_mode;
};
fsp_err_t isl29035_init(struct isl29035_dev *dev, char *bus_name);
fsp_err_t isl29035_configure(struct isl29035_dev *dev);
fsp_err_t isl29035_read_als_data(struct isl29035_dev *dev, double *als_val);

/*
 * function declarations
 */

void isl29035_deinit(void);
fsp_err_t isl29035_set_mode(struct isl29035_dev *dev);
fsp_err_t isl29035_set_range(struct isl29035_dev *dev);
fsp_err_t isl29035_set_res(struct isl29035_dev *dev);
fsp_err_t isl29035_get_regs(uint8_t reg_addr, uint8_t *data, uint16_t len, const struct isl29035_dev *dev);
fsp_err_t isl29035_set_regs(uint8_t reg_addr, uint8_t *data, uint16_t len, const struct isl29035_dev *dev);

#endif /* I2C_SENSOR_H_ */
