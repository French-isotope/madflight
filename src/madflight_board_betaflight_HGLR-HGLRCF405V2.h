/*==============================================================================
Generated on: 2024-05-14 03:27:31.986535
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: HGLRCF405V2
Manufacturer ID: HGLRC

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_HGLR-HGLRCF405V2.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-HGLR-HGLRCF405V2"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define BARO_USE  BARO_USE_BMP280
#define BARO_USE  BARO_USE_DPS310
#define OSD_USE  OSD_USE_MAX7456
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW270
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PC13
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
  #define HW_PIN_IMU_EXTI  PC4
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
  #define HW_PIN_OUT_LIST {PC6,PC7,PC8,PC9,PA15,PA8,PB10,PB11}
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
  #define HW_PIN_GPS_RX    PA3
#endif
#ifndef HW_PIN_GPS_TX
  #define HW_PIN_GPS_TX    PA2
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
#define HW_SERIAL_COUNT 5
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1}, {3,PC10,PC11,-1}, {4,PA0,PA1,-1}, {5,PC12,PD2,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PB3,PB4,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB6,PB7} } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PB8
#define HW_PIN_PPM PA3
#define HW_PIN_LED_STRIP PB1
//#define HW_PIN_LED PC13
#define HW_PIN_ESCSERIAL PC11
#define HW_PIN_ADC_BATT PC2
#define HW_PIN_ADC_RSSI PC3
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_FLASH_CS PC0
#define HW_PIN_OSD_CS PA13
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_USB_DETECT PB12

//set statements
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 1
#define HW_SET_ADC_DEVICE 1
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_FLASH_SPI_BUS 3
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW270


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.4.2 May 31 2023 / 22:53:28 (23d066d) MSP API: 1.45

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_MAX7456
#define USE_FLASH
#define USE_FLASH_W25Q128FV

board_name HGLRCF405V2
manufacturer_id HGLRC

# resources
resource BEEPER 1 B08
resource MOTOR 1 C06
resource MOTOR 2 C07
resource MOTOR 3 C08
resource MOTOR 4 C09
resource MOTOR 5 A15
resource MOTOR 6 A08
resource MOTOR 7 B10
resource MOTOR 8 B11
resource PPM 1 A03
resource LED_STRIP 1 B01
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 C10
resource SERIAL_TX 4 A00
resource SERIAL_TX 5 C12
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource SERIAL_RX 3 C11
resource SERIAL_RX 4 A01
resource SERIAL_RX 5 D02
resource I2C_SCL 1 B06
resource I2C_SDA 1 B07
resource LED 1 C13
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 B03
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 B04
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource ESCSERIAL 1 C11
resource ADC_BATT 1 C02
resource ADC_RSSI 1 C03
resource ADC_CURR 1 C01
resource FLASH_CS 1 C00
resource OSD_CS 1 A13
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 A04
resource USB_DETECT 1 B12

# timer
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer A15 AF1
# pin A15: TIM2 CH1 (AF1)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer B11 AF1
# pin B11: TIM2 CH4 (AF1)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)

# dma
dma ADC 1 0
# ADC 1: DMA2 Stream 0 Channel 0
dma pin A03 0
# pin A03: DMA1 Stream 1 Channel 6
dma pin C06 1
# pin C06: DMA2 Stream 2 Channel 7
dma pin C07 1
# pin C07: DMA2 Stream 3 Channel 7
dma pin C08 1
# pin C08: DMA2 Stream 4 Channel 7
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin A15 0
# pin A15: DMA1 Stream 5 Channel 3
dma pin A08 1
# pin A08: DMA2 Stream 1 Channel 6
dma pin B11 0
# pin B11: DMA1 Stream 7 Channel 3
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5

# feature
feature LED_STRIP
feature OSD

# master
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_bustype = I2C
set baro_i2c_device = 1
set adc_device = 1
set blackbox_device = SPIFLASH
set current_meter = ADC
set battery_meter = ADC
set beeper_inversion = ON
set beeper_od = OFF
set max7456_spi_bus = 2
set flash_spi_bus = 3
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW270

*/
