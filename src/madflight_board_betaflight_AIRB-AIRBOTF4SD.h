/*==============================================================================
Generated on: 2024-05-14 03:27:31.783421
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: AIRBOTF4SD
Manufacturer ID: AIRB

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_AIRB-AIRBOTF4SD.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-AIRB-AIRBOTF4SD"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6500
#define IMU_USE  IMU_USE_SPI_MPU6000
#define BARO_USE  BARO_USE_SPI_BMP280
#define OSD_USE  OSD_USE_MAX7456
#define BB_USE  BB_USE_SDCARD
#define BARO_USE  BARO_USE_BMP280
#define BARO_USE  BARO_USE_BMP085
#define BARO_USE  BARO_USE_MS5611
#define BARO_USE  BARO_USE_SPI_BMP280

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW270
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
  #define HW_PIN_SPI_MISO  PA6
#endif
#ifndef HW_PIN_SPI_MOSI
  #define HW_PIN_SPI_MOSI  PA7
#endif
#ifndef HW_PIN_SPI_SCLK
  #define HW_PIN_SPI_SCLK  PA5
#endif
#ifndef HW_PIN_IMU_CS
  #define HW_PIN_IMU_CS    PB13
#endif
#ifndef HW_PIN_IMU_EXTI
  #define HW_PIN_IMU_EXTI  PC4
#endif

//BARO/MAG I2C: (I2C2)
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
  #define HW_PIN_OUT_LIST {PB0,PB1,PA3,PA2,PA1,PA8}
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
  #define HW_PIN_BAT_V     PC2
#endif
#ifndef HW_PIN_BAT_I
  #define HW_PIN_BAT_I     PC1
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
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {3,PB10,PB11,-1}, {4,PA0,PA1,-1}, {6,PC6,PC7,PD2} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 2
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {3,PC10,PC11,PC12} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 0
#define HW_PIN_I2C {  } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PB4
#define HW_PIN_PPM PB14
#define HW_PIN_PWM PB14
#define HW_PIN_PWM_2 PB15
#define HW_PIN_PWM_3 PC6
#define HW_PIN_PWM_4 PC7
#define HW_PIN_PWM_5 PC8
#define HW_PIN_PWM_6 PC9
#define HW_PIN_LED_STRIP PB6
//#define HW_PIN_LED PB5
#define HW_PIN_ESCSERIAL PB14
#define HW_PIN_ADC_BATT PC2
#define HW_PIN_ADC_RSSI PA0
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_BARO_CS PC13
#define HW_PIN_SDCARD_CS PB3
#define HW_PIN_SDCARD_DETECT PC0
#define HW_PIN_PINIO PC8
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_CS PB13
#define HW_PIN_GYRO_CS_2 PA4
#define HW_PIN_USB_DETECT PC5

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 2
#define HW_SET_BARO_SPI_DEVICE 1
#define HW_SET_BLACKBOX_DEVICE SDCARD
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SDCARD_DETECT_INVERTED ON
#define HW_SET_SDCARD_MODE SPI
#define HW_SET_SDCARD_SPI_BUS 3
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_DASHBOARD_I2C_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW270
#define HW_SET_GYRO_1_ALIGN_YAW 2700
#define HW_SET_GYRO_2_SPIBUS 1
#define HW_SET_GYRO_2_SENSOR_ALIGN CW270
#define HW_SET_GYRO_2_ALIGN_YAW 2700


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.1.0 Oct 16 2019 / 11:57:16 (c37a7c91a) MSP API: 1.42

#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_ACC_SPI_MPU6000
#define USE_GYRO_SPI_MPU6000
#define USE_BARO
#define USE_BARO_SPI_BMP280
#define USE_MAX7456
#define USE_SDCARD
#define USE_BARO_BMP280
#define USE_BARO_BMP085
#define USE_BARO_MS5611
#define USE_BARO_SPI_BMP280

board_name AIRBOTF4SD
manufacturer_id AIRB

# resources
resource BEEPER 1 B04
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 A03
resource MOTOR 4 A02
resource MOTOR 5 A01
resource MOTOR 6 A08
resource PPM 1 B14
resource PWM 1 B14
resource PWM 2 B15
resource PWM 3 C06
resource PWM 4 C07
resource PWM 5 C08
resource PWM 6 C09
resource LED_STRIP 1 B06
resource SERIAL_TX 1 A09
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 A00
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 A01
resource SERIAL_RX 6 C07
resource INVERTER 6 D02
resource LED 1 B05
resource SPI_SCK 1 A05
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 3 C12
resource ESCSERIAL 1 B14
resource ADC_BATT 1 C02
resource ADC_RSSI 1 A00
resource ADC_CURR 1 C01
resource BARO_CS 1 C13
resource SDCARD_CS 1 B03
resource SDCARD_DETECT 1 C00
resource PINIO 1 C08
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 B13
resource GYRO_CS 2 A04
resource USB_DETECT 1 C05

# timer
timer B14 AF9
# pin B14: TIM12 CH1 (AF9)
timer B15 AF9
# pin B15: TIM12 CH2 (AF9)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer A03 AF1
# pin A03: TIM2 CH4 (AF1)
timer A02 AF1
# pin A02: TIM2 CH3 (AF1)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)

# dma
dma SPI_TX 3 0
# SPI_TX 3: DMA1 Stream 5 Channel 0
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin C06 0
# pin C06: DMA2 Stream 2 Channel 0
dma pin C07 0
# pin C07: DMA2 Stream 2 Channel 0
dma pin C08 0
# pin C08: DMA2 Stream 2 Channel 0
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin A03 1
# pin A03: DMA1 Stream 6 Channel 3
dma pin A02 0
# pin A02: DMA1 Stream 1 Channel 3
dma pin A01 0
# pin A01: DMA1 Stream 4 Channel 6
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2

# feature
feature RX_SERIAL

# master
set mag_bustype = I2C
set mag_i2c_device = 2
set baro_spi_device = 1
set blackbox_device = SDCARD
set beeper_inversion = ON
set beeper_od = OFF
set sdcard_detect_inverted = ON
set sdcard_mode = SPI
set sdcard_spi_bus = 3
set system_hse_mhz = 8
set dashboard_i2c_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW270
set gyro_1_align_yaw = 2700
set gyro_2_spibus = 1
set gyro_2_sensor_align = CW270
set gyro_2_align_yaw = 2700

*/
