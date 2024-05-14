/*==============================================================================
Generated on: 2024-05-14 03:27:31.787564
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: AIRBOTG4AIO
Manufacturer ID: AIRB

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_AIRB-AIRBOTG4AIO.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-AIRB-AIRBOTG4AIO"
#define HW_MCU "STM32G47X"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define BARO_USE  BARO_USE_DPS310
#define IMU_USE  IMU_USE_SPI_ICM42688P
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW0FLIP
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PB5
#endif
#ifndef HW_LED_ON
  #define HW_LED_ON        1 //0:low is on, 1:high is on
#endif

//IMU SPI: (SPI1)
#ifndef HW_PIN_SPI_MISO
  #define HW_PIN_SPI_MISO  -1
#endif
#ifndef HW_PIN_SPI_MOSI
  #define HW_PIN_SPI_MOSI  -1
#endif
#ifndef HW_PIN_SPI_SCLK
  #define HW_PIN_SPI_SCLK  PA5
#endif
#ifndef HW_PIN_IMU_CS
  #define HW_PIN_IMU_CS    PB0
#endif
#ifndef HW_PIN_IMU_EXTI
  #define HW_PIN_IMU_EXTI  PC4
#endif

//BARO/MAG I2C: (I2C1)
#ifndef HW_PIN_I2C_SDA
  #define HW_PIN_I2C_SDA   PA13
#endif
#ifndef HW_PIN_I2C_SCL
  #define HW_PIN_I2C_SCL   PA14
#endif

//Outputs:
#ifndef HW_OUT_COUNT
  #define HW_OUT_COUNT     4
#endif
#ifndef HW_PIN_OUT_LIST
  #define HW_PIN_OUT_LIST {PA0,PA1,PA2,PA3}
#endif

//RC Receiver: (SERIAL1)
#ifndef HW_PIN_RCIN_RX
  #define HW_PIN_RCIN_RX   PA10
#endif
#ifndef HW_PIN_RCIN_TX
  #define HW_PIN_RCIN_TX   PA9
#endif
#ifndef HW_PIN_RCIN_INVERTER
  #define HW_PIN_RCIN_INVERTER  -1
#endif

//GPS: (SERIAL2)
#ifndef HW_PIN_GPS_RX
  #define HW_PIN_GPS_RX    PB4
#endif
#ifndef HW_PIN_GPS_TX
  #define HW_PIN_GPS_TX    PB3
#endif
#ifndef HW_PIN_GPS_INVERTER
  #define HW_PIN_GPS_INVERTER  -1
#endif

//Battery ADC voltage and current inputs:
#ifndef HW_PIN_BAT_V
  #define HW_PIN_BAT_V     PB2
#endif
#ifndef HW_PIN_BAT_I
  #define HW_PIN_BAT_I     PB1
#endif

const int HW_PIN_OUT[] = HW_PIN_OUT_LIST;

//Include Libraries
#include <Wire.h> //I2C communication
#include <SPI.h> //SPI communication
#include "madflight/hw_STM32/STM32_PWM.h" //Servo and oneshot

//Bus Setup
HardwareSerial *rcin_Serial = new HardwareSerial(HW_PIN_RCIN_RX, HW_PIN_RCIN_TX);
HardwareSerial gps_Serial(HW_PIN_GPS_RX, HW_PIN_GPS_TX);
typedef TwoWire HW_WIRETYPE; //define the class to use for I2C
HW_WIRETYPE *i2c = &Wire; //&Wire or &Wire1
SPIClass *spi = &SPI;

//Serial
#define HW_SERIAL_COUNT 5
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PB3,PB4,-1}, {3,-1,PB9,-1}, {4,PC10,PC11,-1}, {11,PB11,PB10,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 2
#define HW_PIN_SPI { {1,PA5,-1,-1}, {2,PB13,-1,-1} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PA13,PA14} } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PB7
#define HW_PIN_LED_STRIP PB6
//#define HW_PIN_LED PB5
#define HW_PIN_LED_2 PC15
#define HW_PIN_SPI_SDI PA6
#define HW_PIN_SPI_SDI_2 PB14
#define HW_PIN_SPI_SDO PA7
#define HW_PIN_SPI_SDO_2 PB15
#define HW_PIN_CAMERA_CONTROL PA15
#define HW_PIN_ADC_BATT PB2
#define HW_PIN_ADC_CURR PB1
#define HW_PIN_FLASH_CS PC6
#define HW_PIN_OSD_CS PA8
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_CS PB0

//set statements
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_DSHOT_BURST ON
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_PID_PROCESS_DENOM 2
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_FLASH_SPI_BUS 2
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW0FLIP
#define HW_SET_GYRO_1_ALIGN_PITCH 1800


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32G47X (SG47) 4.5.0 Jun  4 2023 / 14:46:36 (5e4d8efc5) MSP API: 1.46

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_DPS310
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACCGYRO_LSM6DVS16X
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

# config: YES

board_name AIRBOTG4AIO
manufacturer_id AIRB

#resource
resource BEEPER 1 B07
resource MOTOR 1 A00
resource MOTOR 2 A01
resource MOTOR 3 A02
resource MOTOR 4 A03
resource LED_STRIP 1 B06
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 B03
resource SERIAL_TX 4 C10
resource SERIAL_TX 11 B11
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 B04
resource SERIAL_RX 3 B09
resource SERIAL_RX 4 C11
resource SERIAL_RX 11 B10
resource I2C_SCL 1 A13
resource I2C_SDA 1 A14
resource LED 1 B05
resource LED 2 C15
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SDI 1 A06
resource SPI_SDI 2 B14
resource SPI_SDO 1 A07
resource SPI_SDO 2 B15
resource CAMERA_CONTROL 1 A15
resource ADC_BATT 1 B02
resource ADC_CURR 1 B01
resource FLASH_CS 1 C06
resource OSD_CS 1 A08
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 B00

# timer
timer B06 AF5
# pin B06: TIM8 CH1 (AF5)
timer A00 AF1
# pin A00: TIM2 CH1 (AF1)
timer A01 AF1
# pin A01: TIM2 CH2 (AF1)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)

# dma
dma SPI_SDO 1 7
# SPI_SDO 1: DMA1 Channel 8 Request 11
dma SPI_SDO 2 9
# SPI_SDO 2: DMA2 Channel 2 Request 13
dma SPI_SDI 1 6
# SPI_SDI 1: DMA1 Channel 7 Request 10
dma SPI_SDI 2 8
# SPI_SDI 2: DMA2 Channel 1 Request 12
dma SPI_TX 1 7
# SPI_TX 1: DMA1 Channel 8 Request 11
dma SPI_TX 2 9
# SPI_TX 2: DMA2 Channel 2 Request 13
dma SPI_RX 1 6
# SPI_RX 1: DMA1 Channel 7 Request 10
dma SPI_RX 2 8
# SPI_RX 2: DMA2 Channel 1 Request 12
dma ADC 1 10
# ADC 1: DMA2 Channel 3 Request 5
dma ADC 2 11
# ADC 2: DMA2 Channel 4 Request 36
dma pin B06 12
# pin B06: DMA2 Channel 5 Request 49
dma pin A00 1
# pin A00: DMA1 Channel 2 Request 56
dma pin A01 2
# pin A01: DMA1 Channel 3 Request 57
dma pin A02 3
# pin A02: DMA1 Channel 4 Request 74
dma pin A03 4
# pin A03: DMA1 Channel 5 Request 75

# feature
feature OSD
feature ESC_SENSOR

# serial
serial 2 1024 115200 57600 0 115200

# master
set baro_bustype = I2C
set baro_i2c_device = 1
set blackbox_device = SPIFLASH
set dshot_burst = ON
set current_meter = ADC
set battery_meter = ADC
set beeper_inversion = ON
set beeper_od = OFF
set pid_process_denom = 2
set max7456_spi_bus = 2
set flash_spi_bus = 2
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW0FLIP
set gyro_1_align_pitch = 1800

*/
