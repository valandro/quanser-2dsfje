// Copyright (C) 2020 Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.


/**
 * @file decoder.c
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Source file for Decoder utilized in quanser-2dsfje project for ENG10032
 */

// Project headers
#include "decoder.h"
#include "spi_configuration_flags.h"
#include "gpio.h"

// C headers
#include <stdio.h>
#include <stdint.h>
#include <linux/spi/spidev.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

/** @brief File descriptor for opening and gathering file data in device. Initialized with -1 (invalid descriptor)*/
int file_descriptor = -1;

/**
* @brief Function that initiates Decoder and SPI interface configuration
*
* This function tries to open the device and reads/writes all Decoder/SPI interface comm values.
* This function asserts the error when a file reading/writing cannot be done and aborts the program calling OS abort() function
* @return int Greater than zero if the initialization is successful
**/
int decoder_init()
{
  // Init SPI Configurations values
  uint8_t spiMode = SPI_MODE_0; // SPI Mode in zero -> CPOL = 0, CPHA = 0. Data sampling in uprising clock and altering in down clock.
  uint8_t bitsPerWord = BITS_PER_WORD; // 1 Byte
  uint8_t lsb = 0; // Bits. Starting from MSB, because lsb = 0. This is important for counter reading later
  uint32_t spiSpeed = SPI_SPEED; // SPI Speed

  // Opening the device first
  if((file_descriptor = open(SPI_DEVICE_PATH,O_RDWR)) == DEVICE_READING_WRITING_ERROR)
  {
    printf("SPI ERROR: Cannot open device.\n");
    return DECODER_INIT_ERROR;
  }
  // Writes SPI mode
  if(ioctl(file_descriptor,SPI_IOC_WR_MODE,&spiMode) == DEVICE_READING_WRITING_ERROR)
  {
    printf("SPI ERROR: Cannot write clock mode on device.\n");
    return DECODER_INIT_ERROR;
  }
  // Writing SPI Clock
  if(ioctl(file_descriptor, SPI_IOC_WR_MAX_SPEED_HZ, &spiSpeed) == DEVICE_READING_WRITING_ERROR)
  {
    printf("SPI ERROR: Cannot write SPI Speed on device.\n");
    return DECODER_INIT_ERROR;
  }
  // Writing LSB on device
  if(ioctl(file_descriptor, SPI_IOC_WR_LSB_FIRST, &lsb) == DEVICE_READING_WRITING_ERROR)
  {
    printf("SPI ERROR: Cannot write SPI lsb first on device.\n");
    return DECODER_INIT_ERROR;
  }
  // Writing bits per word value
  if(ioctl(file_descriptor,SPI_IOC_WR_BITS_PER_WORD, &bitsPerWord) == DEVICE_READING_WRITING_ERROR)
  {
    printf("SPI ERROR: Cannot write bits per word value on device.\n");
    return DECODER_INIT_ERROR;
  }

  int ret;

  // Writing in MDR0 values for quadrature and modes
  ret = write_spi(WRITE_MDR0, (QUADRX1 | FREE_RUN | DISABLE_INDX | FILTER_2) );

  if(ret < 0)
  {
    printf("SPI ERROR: Cannot configure MDR0.\n");
    return DECODER_INIT_ERROR;
  }

  // Writing in MDR1 values for counter configuration
  ret = write_spi(WRITE_MDR1, (NO_FLAGS | BYTE_4 | EN_CNTR));

  if(ret < 0)
  {
    printf("SPI ERROR: Cannot configure MDR1.\n");
    return DECODER_INIT_ERROR;
  }

  // Clearing counter after init
  ret = clear_counter();
  if(ret < 0)
  {
    printf("SPI ERROR: Cannot clear counter data.\n");
    return DECODER_INIT_ERROR;
  }

  // All good. SPI/Decoder is initialized
  return DECODER_INIT_SUCCESS;
}


/**
* @brief Function starts master-slave transition from high to low
*
* Following datasheet: A high to low transition at the SS/ (Slave Select) input
*selects the LS7366R for serial bi-directional data transfer; a
*low to high transition disables serial data transfer and brings
*the MISO output to high impedance state. This allows for the
*accommodation of multiple slave units on the serial I/O.
* @return int Greater than zero if the initialization is successful
**/
int spi_start()
{
  if(gpio_write(SS_PATH,1) != 1)
  {
    printf("SPI ERROR: Cannot write SS value high for high-low transition.\n");
    return -1;
  }

  if(gpio_write(SS_PATH,0) != 1)
  {
    printf("SPI ERROR: Cannot write SS value low for high-low transition.\n");
    return -1;
  }

  return 1;
}


/**
* @brief Function transitions master-slave to stop
*
* Following datasheet: A high to low transition at the SS/ (Slave Select) input
*selects the LS7366R for serial bi-directional data transfer; a
*low to high transition disables serial data transfer and brings
*the MISO output to high impedance state. This allows for the
*accommodation of multiple slave units on the serial I/O.
* @return int Greater than zero if the initialization is successful
**/
int spi_stop()
{
  if(gpio_write(SS_PATH,1) != 1)
  {
    printf("SPI ERROR: Cannot write SS value high for low-high transition.\n");
    return -1;
  }
  return 1;
}


/**
* @brief Function writes spi data on buffer
*
* @param op_code Opcode to be written
* @param write_data Data to be written
* @return int Greater than zero if the operation was successful
**/
int write_spi(unsigned char op_code, unsigned char write_data)
{
  // Starts SS transition to gather data
  if(spi_start() < 0)
  {
    return -1;
  }

  // Writing opcode, only one byte
  if (write(file_descriptor, &op_code, sizeof(op_code)) < 0)
  {
    printf("SPI ERROR: Cannot write opcode of SPI.\n");
    return -1;
  }

  // Writing data, only one byte
  if(write(file_descriptor, &write_data, sizeof(write_data)) < 0)
  {
    printf("SPI ERROR: Cannot write data of SPI.\n");
    return -1;
  }

  // Stops SS
  if(spi_stop() < 0)
  {
    return -1;
  }

  return 1;
}


/**
* @brief Function reads spi data on buffer
* Reads always 4 bytes from the buffer
*
* @return int Greater than zero if the operation was successful
**/
int read_spi(unsigned char *data)
{

  for (i = 0; i < sizeof(4 * sizeof(unsigned char)); i++)
  {
      if (read(file_descriptor, &data[i], 1) < 0)
      {
        printf("SPI ERROR: Cannot read data of counter.\n");
        return -1;
      }
  }

  return 1;
}


/**
* @brief Function clears counter data on buffer
* @return int Greater than zero if the operation was successful
**/
int clear_counter()
{
  // Starts SS transition to gather data
  if(spi_start() < 0)
  {
    return -1;
  }

  // Writing data, only one byte
  unsigned char op_code = CLR_CNTR;
  if(write(file_descriptor, &op_code, sizeof(op_code)) < 0)
  {
    return -1;
  }

  // Stops SS
  if(spi_stop() < 0)
  {
    return -1;
  }

  return 1;
}

/**
* @brief Function reads counter data on buffer
* @return int Returns the count of data read by the counter buffer
**/
int decoder_read_counter()
{
  // Starts SS transition to gather data
  if(spi_start() < 0)
  {
    return -1;
  }

  // Start the counter read with a opcode indicating a read operation in the counter
  unsigned char op_code = READ_CNTR;
  if (write(file_descriptor, &op_code, sizeof(op_code)) < 0)
  {
    printf("SPI ERROR: Cannot write opcode of SPI when reading counter.\n");
    return -1;
  }

  // Read counter data
  unsigned char counter_data[4];

  int i = 0;
  for (i = 0; i < sizeof(4 * sizeof(unsigned char)); i++)
  {
      if (read(file_descriptor, &counter_data[i], 1) < 0)
      {
        printf("SPI ERROR: Cannot read data of counter.\n");
        return -1;
      }
  }

  // Stops SS
  if(spi_stop() < 0)
  {
    return -1;
  }

  // Align bits to gather counter data performing bitwise OR operations
  // Implicit casting padding unsigned char (8-bits) to unsigned int (32-bits)
  // Real data => unsigned char (8-bits)
  // After casting => 00000000 00000000 00000000 data (32bits)
  // Shift for aligning bits => data[0] >> 24 => data 00000000 00000000 00000000
  // data[1] >> 16 => 00000000 data 00000000 00000000
  // data[2] >> 8 => 00000000 00000000 data 00000000
  unsigned int counter_byte_1 = counter_data[3];
  unsigned int counter_byte_2 = counter_data[2] << 8;
  unsigned int counter_byte_3 = counter_data[1] << 16;
  unsigned int counter_byte_4 = counter_data[0] << 24;

  return counter_byte_1 | counter_byte_2 | counter_byte_3 | counter_byte_4;
}
