/*==============================================================================
Generated on: 2024-05-14 03:27:32.090429
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: NEUTRONRCF411SX1280
Manufacturer ID: NERC

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_NERC-NEUTRONRCF411SX1280.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-NERC-NEUTRONRCF411SX1280"
#define HW_MCU "STM32F411SX1280"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_ICM42688P
#define IMU_USE  IMU_USE_SPI_ICM42605
#define IMU_USE  IMU_USE_SPI_ICM20689
#define IMU_USE  IMU_USE_SPI_MPU6000
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"
#define OSD_USE  OSD_USE_MAX7456
#define USE_RX_SPI
#define USE_RX_EXPRESSLRS
#define USE_RX_EXPRESSLRS_TELEMETRY
#define USE_RX_SX1280
#define RX_CHANNELS_AETR
#define RX_SPI_DEFAULT_PROTOCOL  RX_SPI_EXPRESSLRS
#define RX_EXPRESSLRS_TIMER_INSTANCE  TIM5
#define RX_EXPRESSLRS_SPI_RESET_PIN  PB9
#define RX_EXPRESSLRS_SPI_BUSY_PIN  PA13
#define RX_SPI_CS  PA15
#define RX_SPI_EXTI  PC13
#define RX_SPI_BIND  PB2
#define RX_SPI_LED  PC15

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW0
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PC14
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
  #define HW_PIN_IMU_EXTI  PB6
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
  #define HW_OUT_COUNT     4
#endif
#ifndef HW_PIN_OUT_LIST
  #define HW_PIN_OUT_LIST {PB8,PA0,PB10,PB7}
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
  #define HW_PIN_BAT_V     PA1
#endif
#ifndef HW_PIN_BAT_I
  #define HW_PIN_BAT_I     PB0
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
#define HW_SERIAL_COUNT 2
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,PA3,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PB3,PB4,PB5} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 0
#define HW_PIN_I2C {  } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PA14
#define HW_PIN_LED_STRIP PB1
//#define HW_PIN_LED PC14
#define HW_PIN_ADC_BATT PA1
#define HW_PIN_ADC_CURR PB0
#define HW_PIN_FLASH_CS PA8
#define HW_PIN_OSD_CS PB12
#define HW_PIN_RX_SPI_CS PA15
#define HW_PIN_RX_SPI_EXTI PC13
#define HW_PIN_RX_SPI_BIND PB2
#define HW_PIN_RX_SPI_LED PC15
#define HW_PIN_RX_SPI_EXPRESSLRS_RESET PB9
#define HW_PIN_RX_SPI_EXPRESSLRS_BUSY PA13
#define HW_PIN_GYRO_EXTI PB6
#define HW_PIN_GYRO_CS PA4

//set statements
#define HW_SET_RX_SPI_BUS 3
#define HW_SET_RX_SPI_LED_INVERSION ON
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_DSHOT_BURST OFF
#define HW_SET_DSHOT_BITBANG OFF
#define HW_SET_MOTOR_PWM_PROTOCOL DSHOT600
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 165
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_LED_INVERSION 1
#define HW_SET_FLASH_SPI_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW0
#define HW_SET_GYRO_1_ALIGN_YAW -45


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F411SX1280 (S4SX) 4.3.0 Jun 12 2022 / 14:56:52 (6d17f3f) MSP API: 1.44
#mcu STM32F411

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_ACC_SPI_ICM42605
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42605
#define USE_GYRO_SPI_ICM20689
#define USE_ACC_SPI_ICM20689
#define USE_ACC_SPI_MPU6000
#define USE_GYRO_SPI_MPU6000
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456
#define USE_RX_SPI
#define USE_RX_EXPRESSLRS
#define USE_RX_EXPRESSLRS_TELEMETRY
#define USE_RX_SX1280
#define RX_CHANNELS_AETR
#define RX_SPI_DEFAULT_PROTOCOL         RX_SPI_EXPRESSLRS
#define RX_EXPRESSLRS_TIMER_INSTANCE    TIM5
#define RX_EXPRESSLRS_SPI_RESET_PIN     PB9
#define RX_EXPRESSLRS_SPI_BUSY_PIN      PA13
#define RX_SPI_CS                       PA15
#define RX_SPI_EXTI                     PC13
#define RX_SPI_BIND                     PB2
#define RX_SPI_LED                      PC15

board_name NEUTRONRCF411SX1280
manufacturer_id NERC

# resource
resource BEEPER 1 A14
resource MOTOR 1 B08
resource MOTOR 2 A00
resource MOTOR 3 B10
resource MOTOR 4 B07
resource LED_STRIP 1 B01
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource LED 1 C14
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 B03
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 B04
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource ADC_BATT 1 A01
resource ADC_CURR 1 B00
resource FLASH_CS 1 A08
resource OSD_CS 1 B12
resource RX_SPI_CS 1 A15
resource RX_SPI_EXTI 1 C13
resource RX_SPI_BIND 1 B02
resource RX_SPI_LED 1 C15
resource RX_SPI_EXPRESSLRS_RESET 1 B09
resource RX_SPI_EXPRESSLRS_BUSY 1 A13
resource GYRO_EXTI 1 B06
resource GYRO_CS 1 A04

# timer
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B08 AF2
# pin B08: TIM4 CH3 (AF2)
timer A00 AF1
# pin A00: TIM2 CH1 (AF1)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer B07 AF2
# pin B07: TIM4 CH2 (AF2)

# dma
dma ADC 1 0
# ADC 1: DMA2 Stream 0 Channel 0
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin B08 0
# pin B08: DMA1 Stream 7 Channel 2
dma pin A00 0
# pin A00: DMA1 Stream 5 Channel 3
dma pin B10 0
# pin B10: DMA1 Stream 1 Channel 3
dma pin B07 0
# pin B07: DMA1 Stream 3 Channel 2


# master
set rx_spi_bus = 3
set rx_spi_led_inversion = ON
set blackbox_device = SPIFLASH
set dshot_burst = OFF
set dshot_bitbang = OFF
set motor_pwm_protocol = DSHOT600
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 165
set beeper_inversion = ON
set beeper_od = OFF
set max7456_spi_bus = 2
set led_inversion = 1
set flash_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW0
set gyro_1_align_yaw = -45

*/
