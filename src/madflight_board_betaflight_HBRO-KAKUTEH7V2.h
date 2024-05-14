/*==============================================================================
Generated on: 2024-05-14 03:27:31.976582
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: KAKUTEH7V2
Manufacturer ID: HBRO

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_HBRO-KAKUTEH7V2.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-HBRO-KAKUTEH7V2"
#define HW_MCU "STM32H743"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define BARO_USE  BARO_USE_BMP280
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25N01G"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW0
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PC2
#endif
#ifndef HW_LED_ON
  #define HW_LED_ON        1 //0:low is on, 1:high is on
#endif

//IMU SPI: (SPI4)
#ifndef HW_PIN_SPI_MISO
  #define HW_PIN_SPI_MISO  PE5
#endif
#ifndef HW_PIN_SPI_MOSI
  #define HW_PIN_SPI_MOSI  PE6
#endif
#ifndef HW_PIN_SPI_SCLK
  #define HW_PIN_SPI_SCLK  PE2
#endif
#ifndef HW_PIN_IMU_CS
  #define HW_PIN_IMU_CS    PE4
#endif
#ifndef HW_PIN_IMU_EXTI
  #define HW_PIN_IMU_EXTI  PE1
#endif

//BARO/MAG I2C: (I2C1)
#ifndef HW_PIN_I2C_SDA
  #define HW_PIN_I2C_SDA   PB6
#endif
#ifndef HW_PIN_I2C_SCL
  #define HW_PIN_I2C_SCL   PB7
#endif

//Outputs:
#ifndef HW_OUT_COUNT
  #define HW_OUT_COUNT     8
#endif
#ifndef HW_PIN_OUT_LIST
  #define HW_PIN_OUT_LIST {PB0,PB1,PB3,PB10,PA0,PA2,PC8,PC9}
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
  #define HW_PIN_GPS_RX    PD6
#endif
#ifndef HW_PIN_GPS_TX
  #define HW_PIN_GPS_TX    PD5
#endif
#ifndef HW_PIN_GPS_INVERTER
  #define HW_PIN_GPS_INVERTER  -1
#endif

//Battery ADC voltage and current inputs:
#ifndef HW_PIN_BAT_V
  #define HW_PIN_BAT_V     PC0
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
#define HW_SERIAL_COUNT 6
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PD5,PD6,-1}, {3,PD8,PD9,-1}, {4,PD1,PD0,-1}, {6,PC6,PC7,-1}, {7,-1,PE7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {4,PE2,PE5,PE6} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB6,PB7} } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PC13
#define HW_PIN_LED_STRIP PD12
//#define HW_PIN_LED PC2
#define HW_PIN_CAMERA_CONTROL PE9
#define HW_PIN_ADC_BATT PC0
#define HW_PIN_ADC_RSSI PC5
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_FLASH_CS PA4
#define HW_PIN_PINIO PE13
#define HW_PIN_PINIO_2 PB11
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PE1
#define HW_PIN_GYRO_CS PE4
#define HW_PIN_USB_DETECT PA8

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_VBAT_SCALE 109
#define HW_SET_IBATA_SCALE 168
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_FLASH_SPI_BUS 1
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_DASHBOARD_I2C_BUS 1
#define HW_SET_PINIO_CONFIG 129,129,1,1
#define HW_SET_PINIO_BOX 0,40,255,255
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 4


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32H743 (SH74) 4.3.0 Apr 25 2022 / 01:08:20 (9d71184) MSP API: 1.44

#mcu STM32H743

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_BMI270
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_W25N01G
#define USE_MAX7456

board_name KAKUTEH7V2
manufacturer_id  HBRO

# resources
resource BEEPER 1 C13
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 B03
resource MOTOR 4 B10
resource MOTOR 5 A00
resource MOTOR 6 A02
resource MOTOR 7 C08
resource MOTOR 8 C09
resource LED_STRIP 1 D12
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 D05
resource SERIAL_TX 3 D08
resource SERIAL_TX 4 D01
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 D06
resource SERIAL_RX 3 D09
resource SERIAL_RX 4 D00
resource SERIAL_RX 6 C07
resource SERIAL_RX 7 E07
resource I2C_SCL 1 B06
resource I2C_SDA 1 B07
resource LED 1 C02
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 4 E02
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 4 E05
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 4 E06
resource CAMERA_CONTROL 1 E09
resource ADC_BATT 1 C00
resource ADC_RSSI 1 C05
resource ADC_CURR 1 C01
resource FLASH_CS 1 A04
resource PINIO 1 E13
resource PINIO 2 B11
resource OSD_CS 1 B12
resource GYRO_EXTI 1 E01
resource GYRO_CS 1 E04
resource USB_DETECT 1 A08

# timer
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B03 AF1
# pin B03: TIM2 CH2 (AF1)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer D12 AF2
# pin D12: TIM4 CH1 (AF2)
timer E09 AF1
# pin E09: TIM1 CH1 (AF1)

# dma
dma SPI_TX 1 13
# SPI_TX 1: DMA2 Stream 5 Request 38
dma ADC 1 8
# ADC 1: DMA2 Stream 0 Request 9
dma ADC 3 9
# ADC 3: DMA2 Stream 1 Request 115
dma TIMUP 1 0
# TIMUP 1: DMA1 Stream 0 Request 15
dma TIMUP 2 0
# TIMUP 2: DMA1 Stream 0 Request 22
dma TIMUP 3 2
# TIMUP 3: DMA1 Stream 2 Request 27
dma TIMUP 4 0
# TIMUP 4: DMA1 Stream 0 Request 32
dma TIMUP 5 0
# TIMUP 5: DMA1 Stream 0 Request 59
dma TIMUP 8 1
# TIMUP 8: DMA1 Stream 1 Request 51
dma pin B00 0
# pin B00: DMA1 Stream 0 Request 25
dma pin B01 1
# pin B01: DMA1 Stream 1 Request 26
dma pin B03 2
# pin B03: DMA1 Stream 2 Request 19
dma pin B10 3
# pin B10: DMA1 Stream 3 Request 20
dma pin A00 4
# pin A00: DMA1 Stream 4 Request 55
dma pin A02 5
# pin A02: DMA1 Stream 5 Request 57
dma pin C08 6
# pin C08: DMA1 Stream 6 Request 49
dma pin C09 7
# pin C09: DMA1 Stream 7 Request 50
dma pin D12 14
# pin D12: DMA2 Stream 6 Request 29
dma pin E09 12
# pin E09: DMA2 Stream 4 Request 11

# feature
feature RX_SERIAL
feature TELEMETRY
feature OSD

# serial
serial 0 1 115200 57600 0 115200
serial 1 1 115200 57600 0 115200
serial 5 64 115200 57600 0 115200
serial 6 1024 115200 57600 0 115200

# master
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_bustype = I2C
set baro_i2c_device = 1
set serialrx_provider = SBUS
set blackbox_device = SPIFLASH
set current_meter = ADC
set battery_meter = ADC
set vbat_scale = 109
set ibata_scale = 168
set beeper_inversion = ON
set beeper_od = OFF
set flash_spi_bus = 1
set max7456_spi_bus = 2
set dashboard_i2c_bus = 1
set pinio_config = 129,129,1,1
set pinio_box = 0,40,255,255
set gyro_1_bustype = SPI
set gyro_1_spibus = 4

*/
