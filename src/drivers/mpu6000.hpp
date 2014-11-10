#ifndef MPU6000_HPP_
#define MPU6000_HPP_

#include <hal.h>

#include <sensor/gyroscope.hpp>
#include <sensor/accelerometer.hpp>

#define MPU6000_AUX_VDDIO          0x01   // R/W
#define MPU6000_SMPLRT_DIV         0x19   // R/W
#define MPU6000_CONFIG             0x1A   // R/W
#define MPU6000_GYRO_CONFIG        0x1B   // R/W
#define MPU6000_ACCEL_CONFIG       0x1C   // R/W
#define MPU6000_FF_THR             0x1D   // R/W
#define MPU6000_FF_DUR             0x1E   // R/W
#define MPU6000_MOT_THR            0x1F   // R/W
#define MPU6000_MOT_DUR            0x20   // R/W
#define MPU6000_ZRMOT_THR          0x21   // R/W
#define MPU6000_ZRMOT_DUR          0x22   // R/W
#define MPU6000_FIFO_EN            0x23   // R/W
#define MPU6000_I2C_MST_CTRL       0x24   // R/W
#define MPU6000_I2C_SLV0_ADDR      0x25   // R/W
#define MPU6000_I2C_SLV0_REG       0x26   // R/W
#define MPU6000_I2C_SLV0_CTRL      0x27   // R/W
#define MPU6000_I2C_SLV1_ADDR      0x28   // R/W
#define MPU6000_I2C_SLV1_REG       0x29   // R/W
#define MPU6000_I2C_SLV1_CTRL      0x2A   // R/W
#define MPU6000_I2C_SLV2_ADDR      0x2B   // R/W
#define MPU6000_I2C_SLV2_REG       0x2C   // R/W
#define MPU6000_I2C_SLV2_CTRL      0x2D   // R/W
#define MPU6000_I2C_SLV3_ADDR      0x2E   // R/W
#define MPU6000_I2C_SLV3_REG       0x2F   // R/W
#define MPU6000_I2C_SLV3_CTRL      0x30   // R/W
#define MPU6000_I2C_SLV4_ADDR      0x31   // R/W
#define MPU6000_I2C_SLV4_REG       0x32   // R/W
#define MPU6000_I2C_SLV4_DO        0x33   // R/W
#define MPU6000_I2C_SLV4_CTRL      0x34   // R/W
#define MPU6000_I2C_SLV4_DI        0x35   // R
#define MPU6000_I2C_MST_STATUS     0x36   // R
#define MPU6000_INT_PIN_CFG        0x37   // R/W
#define MPU6000_INT_ENABLE         0x38   // R/W
#define MPU6000_INT_STATUS         0x3A   // R
#define MPU6000_ACCEL_XOUT_H       0x3B   // R
#define MPU6000_ACCEL_XOUT_L       0x3C   // R
#define MPU6000_ACCEL_YOUT_H       0x3D   // R
#define MPU6000_ACCEL_YOUT_L       0x3E   // R
#define MPU6000_ACCEL_ZOUT_H       0x3F   // R
#define MPU6000_ACCEL_ZOUT_L       0x40   // R
#define MPU6000_TEMP_OUT_H         0x41   // R
#define MPU6000_TEMP_OUT_L         0x42   // R
#define MPU6000_GYRO_XOUT_H        0x43   // R
#define MPU6000_GYRO_XOUT_L        0x44   // R
#define MPU6000_GYRO_YOUT_H        0x45   // R
#define MPU6000_GYRO_YOUT_L        0x46   // R
#define MPU6000_GYRO_ZOUT_H        0x47   // R
#define MPU6000_GYRO_ZOUT_L        0x48   // R
#define MPU6000_EXT_SENS_DATA_00   0x49   // R
#define MPU6000_EXT_SENS_DATA_01   0x4A   // R
#define MPU6000_EXT_SENS_DATA_02   0x4B   // R
#define MPU6000_EXT_SENS_DATA_03   0x4C   // R
#define MPU6000_EXT_SENS_DATA_04   0x4D   // R
#define MPU6000_EXT_SENS_DATA_05   0x4E   // R
#define MPU6000_EXT_SENS_DATA_06   0x4F   // R
#define MPU6000_EXT_SENS_DATA_07   0x50   // R
#define MPU6000_EXT_SENS_DATA_08   0x51   // R
#define MPU6000_EXT_SENS_DATA_09   0x52   // R
#define MPU6000_EXT_SENS_DATA_10   0x53   // R
#define MPU6000_EXT_SENS_DATA_11   0x54   // R
#define MPU6000_EXT_SENS_DATA_12   0x55   // R
#define MPU6000_EXT_SENS_DATA_13   0x56   // R
#define MPU6000_EXT_SENS_DATA_14   0x57   // R
#define MPU6000_EXT_SENS_DATA_15   0x58   // R
#define MPU6000_EXT_SENS_DATA_16   0x59   // R
#define MPU6000_EXT_SENS_DATA_17   0x5A   // R
#define MPU6000_EXT_SENS_DATA_18   0x5B   // R
#define MPU6000_EXT_SENS_DATA_19   0x5C   // R
#define MPU6000_EXT_SENS_DATA_20   0x5D   // R
#define MPU6000_EXT_SENS_DATA_21   0x5E   // R
#define MPU6000_EXT_SENS_DATA_22   0x5F   // R
#define MPU6000_EXT_SENS_DATA_23   0x60   // R
#define MPU6000_MOT_DETECT_STATUS  0x61   // R
#define MPU6000_I2C_SLV0_DO        0x63   // R/W
#define MPU6000_I2C_SLV1_DO        0x64   // R/W
#define MPU6000_I2C_SLV2_DO        0x65   // R/W
#define MPU6000_I2C_SLV3_DO        0x66   // R/W
#define MPU6000_I2C_MST_DELAY_CTRL 0x67   // R/W
#define MPU6000_SIGNAL_PATH_RESET  0x68   // R/W
#define MPU6000_MOT_DETECT_CTRL    0x69   // R/W
#define MPU6000_USER_CTRL          0x6A   // R/W
#define MPU6000_PWR_MGMT_1         0x6B   // R/W
#define MPU6000_PWR_MGMT_2         0x6C   // R/W
#define MPU6000_FIFO_COUNTH        0x72   // R/W
#define MPU6000_FIFO_COUNTL        0x73   // R/W
#define MPU6000_FIFO_R_W           0x74   // R/W
#define MPU6000_WHO_AM_I           0x75   // R

class MPU6000 : public Gyroscope, public Accelerometer {
public:
  MPU6000(SPIDriver *spid, const SPIConfig *spicfg);

  void init() override;
  gyroscope_reading_t readGyro() override;
  accelerometer_reading_t readAccel() override;

private:
  uint8_t readRegister(uint8_t reg);
  void writeRegister(uint8_t reg, uint8_t val);

  SPIDriver *spid;
  const SPIConfig *spicfg;
};

#endif
