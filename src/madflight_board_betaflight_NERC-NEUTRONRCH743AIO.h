/*==============================================================================
Generated on: 2024-05-14 03:27:32.094718
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: NEUTRONRCH743AIO
Manufacturer ID: NERC

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_NERC-NEUTRONRCH743AIO.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-NERC-NEUTRONRCH743AIO"
#define HW_MCU "STM32H743"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW90
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED       PE3
#endif
#ifndef HW_LED_ON
  #define HW_LED_ON        1 //0:low is on, 1:high is on
#endif

//IMU SPI: (SPI1)
#ifndef HW_PIN_SPI_MISO
  #define HW_PIN_SPI_MISO  PA6
#endif
#ifndef HW_PIN_SPI_MOSI
  #define HW_PIN_SPI_MOSI  PD7
#endif
#ifndef HW_PIN_SPI_SCLK
  #define HW_PIN_SPI_SCLK  PA5
#endif
#ifndef HW_PIN_IMU_CS
  #define HW_PIN_IMU_CS    PC15
#endif
#ifndef HW_PIN_IMU_EXTI
  #define HW_PIN_IMU_EXTI  PB2
#endif

//BARO/MAG I2C: (I2C2)
#ifndef HW_PIN_I2C_SDA
  #define HW_PIN_I2C_SDA   PB10
#endif
#ifndef HW_PIN_I2C_SCL
  #define HW_PIN_I2C_SCL   PB11
#endif

//Outputs:
#ifndef HW_OUT_COUNT
  #define HW_OUT_COUNT     8
#endif
#ifndef HW_PIN_OUT_LIST
  #define HW_PIN_OUT_LIST {PB0,PB1,PA0,PA1,PA2,PA3,PD12,PD13}
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
#define HW_SERIAL_COUNT 7
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PD5,PD6,-1}, {3,PD8,PD9,-1}, {4,PB9,PB8,-1}, {6,PC6,PC7,-1}, {7,PE8,PE7,-1}, {8,PE1,PE0,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 4
#define HW_PIN_SPI { {1,PA5,PA6,PD7}, {2,PB13,PB14,PB15}, {3,PB3,PB4,PB5}, {4,PE12,PE13,PE14} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 2
#define HW_PIN_I2C { {1,PB6,PB7}, {2,PB10,PB11} } // {INDEX,SCL,SDA}

//other pins
#define HW_PIN_BEEPER PA15
#define HW_PIN_LED_STRIP PA8
//#define HW_PIN_LED PE3
#define HW_PIN_LED_2 PE4
#define HW_PIN_ADC_BATT PC0
#define HW_PIN_ADC_RSSI PC5
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_ADC_EXT PC4
#define HW_PIN_SDIO_CK PC12
#define HW_PIN_SDIO_CMD PD2
#define HW_PIN_SDIO_D0 PC8
#define HW_PIN_SDIO_D1 PC9
#define HW_PIN_SDIO_D2 PC10
#define HW_PIN_SDIO_D3 PC11
#define HW_PIN_PINIO PC3
#define HW_PIN_PINIO_2 PD10
#define HW_PIN_PINIO_3 PD11
#define HW_PIN_OSD_CS PB12
#define HW_PIN_GYRO_EXTI PB2
#define HW_PIN_GYRO_EXTI_2 PE15
#define HW_PIN_GYRO_CS PC15
#define HW_PIN_GYRO_CS_2 PE11
#define HW_PIN_USB_DETECT PE2

//set statements
#define HW_SET_GYRO_TO_USE BOTH
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_BARO_BUSTYPE I2C
#define HW_SET_BARO_I2C_DEVICE 2
#define HW_SET_SERIALRX_PROVIDER CRSF
#define HW_SET_BLACKBOX_DEVICE SDCARD
#define HW_SET_DSHOT_BIDIR ON
#define HW_SET_MOTOR_PWM_PROTOCOL DSHOT600
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 100
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_SDIO_USE_4BIT_WIDTH ON
#define HW_SET_SDIO_DEVICE 1
#define HW_SET_MAX7456_SPI_BUS 2
#define HW_SET_PINIO_CONFIG 129,1,1,1
#define HW_SET_PINIO_BOX 0,40,41,42
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_SENSOR_ALIGN CW90
#define HW_SET_GYRO_1_ALIGN_YAW 900
#define HW_SET_GYRO_2_SPIBUS 4


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32H743 (SH74) 4.3.0 Aug 10 2021 / 12:14:35 (8ca4fdc58) MSP API: 1.44

board_name NEUTRONRCH743AIO
manufacturer_id NERC

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_BMI270

# resources
resource BEEPER 1 A15
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 A00
resource MOTOR 4 A01
resource MOTOR 5 A02
resource MOTOR 6 A03
resource MOTOR 7 D12
resource MOTOR 8 D13
resource LED_STRIP 1 A08
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 D05
resource SERIAL_TX 3 D08
resource SERIAL_TX 4 B09
resource SERIAL_TX 6 C06
resource SERIAL_TX 7 E08
resource SERIAL_TX 8 E01
resource SERIAL_RX 1 A10
resource SERIAL_RX 2 D06
resource SERIAL_RX 3 D09
resource SERIAL_RX 4 B08
resource SERIAL_RX 6 C07
resource SERIAL_RX 7 E07
resource SERIAL_RX 8 E00
resource I2C_SCL 1 B06
resource I2C_SCL 2 B10
resource I2C_SDA 1 B07
resource I2C_SDA 2 B11
resource LED 1 E03
resource LED 2 E04
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 B03
resource SPI_SCK 4 E12
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 B04
resource SPI_MISO 4 E13
resource SPI_MOSI 1 D07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 B05
resource SPI_MOSI 4 E14
resource ADC_BATT 1 C00
resource ADC_RSSI 1 C05
resource ADC_CURR 1 C01
resource ADC_EXT 1 C04
resource SDIO_CK 1 C12
resource SDIO_CMD 1 D02
resource SDIO_D0 1 C08
resource SDIO_D1 1 C09
resource SDIO_D2 1 C10
resource SDIO_D3 1 C11
resource PINIO 1 C03
resource PINIO 2 D10
resource PINIO 3 D11
resource OSD_CS 1 B12
resource GYRO_EXTI 1 B02
resource GYRO_EXTI 2 E15
resource GYRO_CS 1 C15
resource GYRO_CS 2 E11
resource USB_DETECT 1 E02

# timer
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer A00 AF2
# pin A00: TIM5 CH1 (AF2)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer A02 AF2
# pin A02: TIM5 CH3 (AF2)
timer A03 AF2
# pin A03: TIM5 CH4 (AF2)
timer D12 AF2
# pin D12: TIM4 CH1 (AF2)
timer D13 AF2
# pin D13: TIM4 CH2 (AF2)
timer D14 AF2
# pin D14: TIM4 CH3 (AF2)
timer D15 AF2
# pin D15: TIM4 CH4 (AF2)
timer E05 AF4
# pin E05: TIM15 CH1 (AF4)
timer E06 AF4
# pin E06: TIM15 CH2 (AF4)
timer A08 AF1
# pin A08: TIM1 CH1 (AF1)
timer A15 AF1
# pin A15: TIM2 CH1 (AF1)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer B08 AF1
# pin B08: TIM16 CH1 (AF1)
timer B09 AF1
# pin B09: TIM17 CH1 (AF1)

# dma
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
dma TIMUP 4 1
# TIMUP 4: DMA1 Stream 1 Request 32
dma TIMUP 5 0
# TIMUP 5: DMA1 Stream 0 Request 59
dma TIMUP 8 0
# TIMUP 8: DMA1 Stream 0 Request 51
dma pin B00 0
# pin B00: DMA1 Stream 0 Request 25
dma pin B01 1
# pin B01: DMA1 Stream 1 Request 26
dma pin A00 2
# pin A00: DMA1 Stream 2 Request 55
dma pin A01 3
# pin A01: DMA1 Stream 3 Request 56
dma pin A02 4
# pin A02: DMA1 Stream 4 Request 57
dma pin A03 5
# pin A03: DMA1 Stream 5 Request 58
dma pin D12 6
# pin D12: DMA1 Stream 6 Request 29
dma pin D13 7
# pin D13: DMA1 Stream 7 Request 30
dma pin D14 12
# pin D14: DMA2 Stream 4 Request 31
dma pin E05 0
# pin E05: DMA1 Stream 0 Request 105
dma pin A08 14
# pin A08: DMA2 Stream 6 Request 11
dma pin A15 0
# pin A15: DMA1 Stream 0 Request 18
dma pin C07 0
# pin C07: DMA1 Stream 0 Request 48
dma pin C06 0
# pin C06: DMA1 Stream 0 Request 47
dma pin B08 0
# pin B08: DMA1 Stream 0 Request 109
dma pin B09 0
# pin B09: DMA1 Stream 0 Request 111

# feature
feature RX_SERIAL
feature TELEMETRY
feature LED_STRIP
feature OSD
feature ESC_SENSOR

# serial
serial 1 2 115200 57600 0 115200
serial 2 1 19200 57600 0 115200
serial 3 8192 115200 57600 0 115200
serial 5 64 115200 57600 0 115200
serial 7 1024 115200 57600 0 115200

# master
set gyro_to_use = BOTH
set mag_bustype = I2C
set mag_i2c_device = 1
set baro_bustype = I2C
set baro_i2c_device = 2
set serialrx_provider = CRSF
set blackbox_device = SDCARD
set dshot_bidir = ON
set motor_pwm_protocol = DSHOT600
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 100
set beeper_inversion = ON
set beeper_od = OFF
set sdio_use_4bit_width = ON
set sdio_device = 1
set max7456_spi_bus = 2
set pinio_config = 129,1,1,1
set pinio_box = 0,40,41,42
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_sensor_align = CW90
set gyro_1_align_yaw = 900
set gyro_2_spibus = 4

*/
