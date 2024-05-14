/*==============================================================================
Generated on: 2024-05-14 03:27:32.207928
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: YUPIF4
Manufacturer ID: YUPF

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_YUPF-YUPIF4.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-YUPF-YUPIF4"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_FAST_KALMAN
#define IMU_USE  IMU_USE_SPI_MPU6500
#define IMU_USE  IMU_USE_SPI_ICM20689
#define OSD_USE  OSD_USE_MAX7456
#define BB_USE  BB_USE_SDCARD

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW90
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PB6
#endif
#ifndef HW_LED_ON
  #define HW_LED_ON        1 //0:low is on, 1:high is on
#endif

//IMU SPI: (SPI1)
#ifndef HW_PIN_SPI_MISO
  #define HW_PIN_SPI_MISO  PA6
#endif
#ifndef HW_PIN_SPI_MOSI
  #define HW_PIN_SPI_MOSI  PA7
#endif
#ifndef HW_PIN_SPI_SCLK
  #define HW_PIN_SPI_SCLK  PA5
#endif
#ifndef HW_PIN_IMU_CS
  #define HW_PIN_IMU_CS    PA4
#endif
#ifndef HW_PIN_IMU_EXTI
  #define HW_PIN_IMU_EXTI  PNONE
#endif

//BARO/MAG I2C: (I2C1)
#ifndef HW_PIN_I2C_SDA
  #define HW_PIN_I2C_SDA   -1
#endif
#ifndef HW_PIN_I2C_SCL
  #define HW_PIN_I2C_SCL   -1
#endif

//Outputs:
#ifndef HW_OUT_COUNT
  #define HW_OUT_COUNT     6
#endif
#ifndef HW_PIN_OUT_LIST
  #define HW_PIN_OUT_LIST {PA0,PA1,PA2,PA3,PB0,PB7}
#endif

//RC Receiver: (SERIAL1)
#ifndef HW_PIN_RCIN_RX
  #define HW_PIN_RCIN_RX   PA10
#endif
#ifndef HW_PIN_RCIN_TX
  #define HW_PIN_RCIN_TX   PA9
#endif
#ifndef HW_PIN_RCIN_INVERTER
  #define HW_PIN_RCIN_INVERTER  PB12
#endif

//GPS: (SERIAL3)
#ifndef HW_PIN_GPS_RX
  #define HW_PIN_GPS_RX    PB11
#endif
#ifndef HW_PIN_GPS_TX
  #define HW_PIN_GPS_TX    PB10
#endif
#ifndef HW_PIN_GPS_INVERTER
  #define HW_PIN_GPS_INVERTER  -1
#endif

//Battery ADC voltage and current inputs:
#ifndef HW_PIN_BAT_V
  #define HW_PIN_BAT_V     PC1
#endif
#ifndef HW_PIN_BAT_I
  #define HW_PIN_BAT_I     PC2
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
#define HW_SERIAL_COUNT 4
#define HW_PIN_SERIAL { {1,PA9,PA10,PB12}, {3,PB10,PB11,-1}, {6,PC6,PC7,PB15}, {11,PB0,PB1,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 2
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {3,PC10,PC11,PC12} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 0
#define HW_PIN_I2C {  } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PC9
#define HW_PIN_PPM PC8
#define HW_PIN_LED_STRIP PB7
//#define HW_PIN_LED PB6
#define HW_PIN_LED_2 PB4
#define HW_PIN_LED_3 PB5
#define HW_PIN_ESCSERIAL PC8
#define HW_PIN_CAMERA_CONTROL PB7
#define HW_PIN_ADC_BATT PC1
#define HW_PIN_ADC_RSSI PC0
#define HW_PIN_ADC_CURR PC2
#define HW_PIN_SDCARD_CS PA15
#define HW_PIN_SDCARD_DETECT PD2
#define HW_PIN_OSD_CS PA14
#define HW_PIN_GYRO_EXTI PNONE
#define HW_PIN_GYRO_CS PA4

//set statements
#define HW_SET_BLACKBOX_DEVICE NONE
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 150
#define HW_SET_SDCARD_DETECT_INVERTED ON
#define HW_SET_SDCARD_MODE SPI
#define HW_SET_SDCARD_SPI_BUS 3
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_MAX7456_SPI_BUS 1
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW90
#define HW_SET_GYRO_1_ALIGN_YAW 900


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.2.0 Feb  2 2020 / 14:39:25 (30bf9e809f) MSP API: 1.43

#define USE_GYRO
#define USE_GYRO_FAST_KALMAN
#define USE_GYRO_SPI_MPU6500
#define USE_GYRO_SPI_ICM20689
#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_ACC_SPI_ICM20689
#define USE_MAX7456
#define USE_SDCARD

board_name YUPIF4
manufacturer_id YUPF

# resources
resource BEEPER 1 C09
resource MOTOR 1 A00
resource MOTOR 2 A01
resource MOTOR 3 A02
resource MOTOR 4 A03
resource MOTOR 5 B00
resource MOTOR 6 B07
resource PPM 1 C08
resource LED_STRIP 1 B07
resource SERIAL_TX 1 A09
resource SERIAL_TX 3 B10
resource SERIAL_TX 6 C06
resource SERIAL_TX 11 B00
resource SERIAL_RX 1 A10
resource SERIAL_RX 3 B11
resource SERIAL_RX 6 C07
resource SERIAL_RX 11 B01
resource INVERTER 1 B12
resource INVERTER 6 B15
resource LED 1 B06
resource LED 2 B04
resource LED 3 B05
resource SPI_SCK 1 A05
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 3 C12
resource ESCSERIAL 1 C08
resource CAMERA_CONTROL 1 B07
resource ADC_BATT 1 C01
resource ADC_RSSI 1 C00
resource ADC_CURR 1 C02
resource SDCARD_CS 1 A15
resource SDCARD_DETECT 1 D02
resource OSD_CS 1 A14
# Disabling GYRO_EXTI since gyro and OSD are on same SPI bus
# resource GYRO_EXTI 1 C04
resource GYRO_EXTI 1 NONE
resource GYRO_CS 1 A04

# timer
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer A02 AF1
# pin A02: TIM2 CH3 (AF1)
timer A03 AF1
# pin A03: TIM2 CH4 (AF1)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer C09 AF2
# pin C09: TIM3 CH4 (AF2)
timer B14 AF9
# pin B14: TIM12 CH1 (AF9)

# dma
dma SPI_TX 3 0
# SPI_TX 3: DMA1 Stream 5 Channel 0
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin C08 0
# pin C08: DMA2 Stream 2 Channel 0
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin A01 0
# pin A01: DMA1 Stream 4 Channel 6
dma pin A02 0
# pin A02: DMA1 Stream 1 Channel 3
dma pin A03 1
# pin A03: DMA1 Stream 6 Channel 3
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin C09 0
# pin C09: DMA1 Stream 2 Channel 5

# feature
feature OSD

# master
set blackbox_device = NONE
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 150
set sdcard_detect_inverted = ON
set sdcard_mode = SPI
set sdcard_spi_bus = 3
set system_hse_mhz = 8
set max7456_spi_bus = 1
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW90
set gyro_1_align_yaw = 900

*/
