/*==============================================================================
Generated on: 2024-05-14 03:27:32.193859
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: TRANSTECF411HD
Manufacturer ID: TTRH

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_TTRH-TRANSTECF411HD.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-TTRH-TRANSTECF411HD"
#define HW_MCU "STM32F411"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW90
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PA14
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
  #define HW_PIN_IMU_EXTI  PA1
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
  #define HW_PIN_OUT_LIST {PB0,PB1,PB10,PB9}
#endif

//RC Receiver: (SERIAL1)
#ifndef HW_PIN_RCIN_RX
  #define HW_PIN_RCIN_RX   PA10
#endif
#ifndef HW_PIN_RCIN_TX
  #define HW_PIN_RCIN_TX   PA9
#endif
#ifndef HW_PIN_RCIN_INVERTER
  #define HW_PIN_RCIN_INVERTER  PC13
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
  #define HW_PIN_BAT_V     PA0
#endif
#ifndef HW_PIN_BAT_I
  #define HW_PIN_BAT_I     PB4
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
#define HW_PIN_SERIAL { {1,PA9,PA10,PC13}, {2,PA2,PA3,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 1
#define HW_PIN_SPI { {1,PA5,PA6,PA7} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 0
#define HW_PIN_I2C {  } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PB6
#define HW_PIN_LED_STRIP PA8
//#define HW_PIN_LED PA14
#define HW_PIN_ADC_BATT PA0
#define HW_PIN_ADC_CURR PB4
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PA1
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_USB_DETECT PC15

//set statements
#define HW_SET_MAG_HARDWARE NONE
#define HW_SET_BARO_HARDWARE NONE
#define HW_SET_SERIALRX_PROVIDER SBUS
#define HW_SET_BLACKBOX_DEVICE NONE
#define HW_SET_DSHOT_IDLE_VALUE 600
#define HW_SET_DSHOT_BURST ON
#define HW_SET_MOTOR_PWM_PROTOCOL DSHOT300
#define HW_SET_MOTOR_POLES 12
#define HW_SET_ALIGN_BOARD_ROLL 180
#define HW_SET_VBAT_MAX_CELL_VOLTAGE 435
#define HW_SET_CURRENT_METER NONE
#define HW_SET_BATTERY_METER ADC
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_YAW_MOTORS_REVERSED ON
#define HW_SET_SMALL_ANGLE 90
#define HW_SET_PID_PROCESS_DENOM 1
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW90
#define HW_SET_GYRO_1_ALIGN_YAW 900
#define HW_SET_MAX7456_SPI_BUS 0
#define HW_SET_SBUS_BAUD_FAST OFF


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F411 (S411) 4.1.1 Oct 25 2019 / 21:10:52 (3a8a2f725) MSP API: 1.42

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000

board_name TRANSTECF411HD
manufacturer_id TTRH

# name: TransTEC

# resources
resource BEEPER 1 B06
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 B10
resource MOTOR 4 B09
resource LED_STRIP 1 A08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 A03
resource INVERTER 1 C13
resource LED 1 A14
resource SPI_SCK 1 A05
resource SPI_MISO 1 A06
resource SPI_MOSI 1 A07
resource ADC_BATT 1 A00
resource ADC_CURR 1 B04
resource OSD_CS 1 B12
resource GYRO_EXTI 1 A01
resource GYRO_CS 1 A04
resource USB_DETECT 1 C15

# timer
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer B10 AF1
# pin B10: TIM2 CH3 (AF1)
timer B09 AF2
# pin B09: TIM4 CH4 (AF2)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)

# dma
dma ADC 1 1
# ADC 1: DMA2 Stream 4 Channel 0
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin B10 0
# pin B10: DMA1 Stream 1 Channel 3
dma pin A08 0
# pin A08: DMA2 Stream 6 Channel 0

# feature
feature RX_SERIAL
feature LED_STRIP

# beacon
beacon RX_SET

# serial
serial 0 64 115200 57600 0 115200
serial 1 1 115200 57600 0 115200

# aux
aux 0 0 2 1300 2100 0 0
aux 1 1 2 1300 1700 0 0
aux 2 13 1 1700 2100 0 0

# led
led 0 0,0::C:1
led 1 1,0::C:1
led 2 2,0::C:1
led 3 3,0::C:1
led 4 4,0::C:1
led 5 5,0::C:1
led 6 6,0::C:1
led 7 7,0::C:1
led 8 8,0::C:1

# master
set mag_hardware = NONE
set baro_hardware = NONE
set serialrx_provider = SBUS
set blackbox_device = NONE
set dshot_idle_value = 600
set dshot_burst = ON
set motor_pwm_protocol = DSHOT300
set motor_poles = 12
set align_board_roll = 180
set vbat_max_cell_voltage = 435
set current_meter = NONE
set battery_meter = ADC
set beeper_inversion = ON
set beeper_od = OFF
set yaw_motors_reversed = ON
set small_angle = 90
set pid_process_denom = 1
set system_hse_mhz = 8
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW90
set gyro_1_align_yaw = 900
set max7456_spi_bus = 0
set sbus_baud_fast = OFF

*/
