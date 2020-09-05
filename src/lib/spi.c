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
 * @file spi.c
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Source file for SPI utilized in quanser-2dsfje project for ENG10032
 */

// Project Headers
#include <linux/spi/spidev.h>
#include <spi.h>

// C Headers
#include <stdio.h>
#include <stdint.h>


/*
* @brief Function that initiates SPI interface configuration
*
* This function tries to open the device and reads/writes all SPI interface comm values.
* This function asserts the error when a file reading/writing cannot be done and aborts the program calling OS abort() function
* @return int Greater than zero if the initialization is successful
* @param spiFrequencyRate SPI Speed to be written
*/
int spiInitiateComm(int spiFrequencyRate)
{
  // File descriptor for opening and gathering file data in SPI device
  int fileDescriptor;

  // SPI Configurations values
  uint8_t spiMode = SPI_MODE_0; // SPI Mode in zero -> CPOL = 0, CPHA = 0. Data sampling in uprising clock and altering in down clock.
  uint8_t bitsPerWord = BITS_PER_WORD; // 1 Byte
  uint8_t lsb = 0; // Bits. Starting from MSB, because lsb = 0.
  uint32_t spiSpeed = spiFrequencyRate; // SPI Speed

  // Opening the device first
  if((fileDescriptor = open(SPI_DEVICE_PATH,O_RDWR)) == DEVICE_READING_WRITING_ERROR)
  {
    fprintf(stderr,"<SPI ERROR> Cannot open device.\n");
    abort();
  }
  // Writes SPI mode
  if(ioctl(fileDescriptor,SPI_IOC_WR_MODE,&spiMode) == DEVICE_READING_WRITING_ERROR)
  {
    fprintf(stderr,"<SPI ERROR> Cannot write clock mode on device.\n");
    abort();
  }
  // Writing SPI Clock
  if(ioctl(fileDescriptor, SPI_IOC_WR_MAX_SPEED_HZ, &spiSpeed) == DEVICE_READING_WRITING_ERROR)
  {
    fprintf(stderr,"<SPI ERROR> Cannot write SPI Speed on device.\n");
    abort();
  }
  // Writing LSB on device
  if(ioctl(fileDescriptor, SPI_IOC_WR_LSB_FIRST, &lsb) == DEVICE_READING_WRITING_ERROR)
  {
    fprintf(stderr,"<SPI ERROR> Cannot write SPI lsb first on device.\n");
    abort();
  }
  // Writing bits per word value
  if(ioctl(fileDescriptor,SPI_IOC_WR_BITS_PER_WORD, &bitsPerWord) == DEVICE_READING_WRITING_ERROR)
  {
    fprintf(stderr,"<SPI ERROR> Cannot write bits per word value on device.\n");
    abort();
  }

  // All good. SPI is initialized
  return SPI_RETURN_SUCCESS;
}
