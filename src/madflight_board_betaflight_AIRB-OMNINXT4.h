/*==============================================================================
Generated on: 2024-05-14 03:27:31.798311
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: OMNINXT4
Manufacturer ID: AIRB

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_AIRB-OMNINXT4.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-AIRB-OMNINXT4"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6500
#define IMU_USE  IMU_USE_SPI_MPU6000
#define BARO_USE  BARO_USE_SPI_LPS
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"
#define OSD_USE  OSD_USE_MAX7456

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW0
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PB2
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
  #define HW_PIN_IMU_CS    PB12
#endif
#ifndef HW_PIN_IMU_EXTI
  #define HW_PIN_IMU_EXTI  -1
#endif

//BARO/MAG I2C: (I2C1)
#ifndef HW_PIN_I2C_SDA
  #define HW_PIN_I2C_SDA   PB8
#endif
#ifndef HW_PIN_I2C_SCL
  #define HW_PIN_I2C_SCL   PB9
#endif

//Outputs:
#ifndef HW_OUT_COUNT
  #define HW_OUT_COUNT     4
#endif
#ifndef HW_PIN_OUT_LIST
  #define HW_PIN_OUT_LIST {PB5,PB4,PB0,PB1}
#endif

//RC Receiver: (SERIAL1)
#ifndef HW_PIN_RCIN_RX
  #define HW_PIN_RCIN_RX   PB7
#endif
#ifndef HW_PIN_RCIN_TX
  #define HW_PIN_RCIN_TX   PB6
#endif
#ifndef HW_PIN_RCIN_INVERTER
  #define HW_PIN_RCIN_INVERTER  -1
#endif

//GPS: (SERIAL2)
#ifndef HW_PIN_GPS_RX
  #define HW_PIN_GPS_RX    PA3
#endif
#ifndef HW_PIN_GPS_TX
  #define HW_PIN_GPS_TX    PA2
#endif
#ifndef HW_PIN_GPS_INVERTER
  #define HW_PIN_GPS_INVERTER  PC5
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
#define HW_PIN_SERIAL { {1,PB6,PB7,-1}, {2,PA2,PA3,PC5}, {3,PB10,PB11,-1}, {4,PA0,PA1,-1}, {5,-1,PD2,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PC3}, {3,PC10,PC11,PC12} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB8,PB9} } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PC13
#define HW_PIN_PPM PB7
#define HW_PIN_LED_STRIP PA9
//#define HW_PIN_LED PB2
#define HW_PIN_ESCSERIAL PB7
#define HW_PIN_CAMERA_CONTROL PB15
#define HW_PIN_ADC_BATT PC0
#define HW_PIN_ADC_RSSI PC4
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_ADC_EXT PA4
#define HW_PIN_BARO_CS PA10
#define HW_PIN_FLASH_CS PC14
#define HW_PIN_OSD_CS PA15
#define HW_PIN_GYRO_CS PB12
#define HW_PIN_GYRO_CS_2 PA8

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_BARO_SPI_DEVICE 2
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_DSHOT_BURST ON
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_DASHBOARD_I2C_BUS 1
#define HW_SET_FLASH_SPI_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_2_SPIBUS 1
#define HW_SET_GYRO_2_SENSOR_ALIGN CW270
#define HW_SET_GYRO_2_ALIGN_YAW 2700


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.1.0 Oct 16 2019 / 11:57:16 (c37a7c91a) MSP API: 1.42
# manufacturer_id: AIRB   board_name: OMNINXT4   custom defaults: NO

#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_GYRO_SPI_MPU6000
#define USE_ACC_SPI_MPU6000
#define USE_BARO
#define USE_BARO_SPI_LPS
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

board_name OMNINXT4
manufacturer_id AIRB

# resources
resource BEEPER 1 C13
resource MOTOR 1 B05
resource MOTOR 2 B04
resource MOTOR 3 B00
resource MOTOR 4 B01
resource PPM 1 B07
resource LED_STRIP 1 A09
resource SERIAL_TX 1 B06
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_TX 4 A00
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 B07
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 A01
resource SERIAL_RX 5 D02
resource SERIAL_RX 6 C07
resource INVERTER 2 C05
resource I2C_SCL 1 B08
resource I2C_SDA 1 B09
resource LED 1 B02
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 C03
resource SPI_MOSI 3 C12
resource ESCSERIAL 1 B07
resource CAMERA_CONTROL 1 B15
resource ADC_BATT 1 C00
resource ADC_RSSI 1 C04
resource ADC_CURR 1 C01
resource ADC_EXT 1 A04
resource BARO_CS 1 A10
resource FLASH_CS 1 C14
resource OSD_CS 1 A15
resource GYRO_CS 1 B12
resource GYRO_CS 2 A08

# timer
timer B05 AF2
# pin B05: TIM3 CH2 (AF2)
timer B04 AF2
# pin B04: TIM3 CH1 (AF2)
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer B09 AF3
# pin B09: TIM11 CH1 (AF3)
timer B08 AF3
# pin B08: TIM10 CH1 (AF3)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)
timer A09 AF1
# pin A09: TIM1 CH2 (AF1)
timer B15 AF9
# pin B15: TIM12 CH2 (AF9)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer A02 AF3
# pin A02: TIM9 CH1 (AF3)
timer A03 AF3
# pin A03: TIM9 CH2 (AF3)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer B11 AF1
# pin B11: TIM2 CH4 (AF1)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer A10 AF1
# pin A10: TIM1 CH3 (AF1)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B05 0
# pin B05: DMA1 Stream 5 Channel 5
dma pin B04 0
# pin B04: DMA1 Stream 4 Channel 5
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin C08 1
# pin C08: DMA2 Stream 4 Channel 7
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2
dma pin A09 0
# pin A09: DMA2 Stream 6 Channel 0
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin B10 0
# pin B10: DMA1 Stream 1 Channel 3
dma pin B11 0
# pin B11: DMA1 Stream 7 Channel 3
dma pin A00 0
# pin A00: DMA1 Stream 2 Channel 6
dma pin A01 0
# pin A01: DMA1 Stream 4 Channel 6
dma pin C06 0
# pin C06: DMA2 Stream 2 Channel 0
dma pin C07 1
# pin C07: DMA2 Stream 3 Channel 7
dma pin A10 0
# pin A10: DMA2 Stream 6 Channel 0

# feature
feature RX_SERIAL
feature LED_STRIP
feature OSD

# serial
serial 0 64 115200 57600 0 115200
serial 4 1024 115200 57600 0 115200

# master
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_spi_device = 2
set blackbox_device = SPIFLASH
set dshot_burst = ON
set current_meter = ADC
set battery_meter = ADC
set beeper_inversion = ON
set beeper_od = OFF
set system_hse_mhz = 8
set max7456_spi_bus = 2
set dashboard_i2c_bus = 1
set flash_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_2_spibus = 1
set gyro_2_sensor_align = CW270
set gyro_2_align_yaw = 2700

*/
