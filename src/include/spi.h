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
 * @file spi.h
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Header file for SPI  utilized in quanser-2dsfje project for ENG10032
 */
#ifndef SPI_H
#define SPI_H


#define SPI_DEVICE_PATH "/dev/spidev1.0"
#define DEVICE_READING_WRITING_ERROR -1
#define SPI_RETURN_SUCCESS 1
#define BITS_PER_WORD 8

#ifdef __cplusplus
extern "C"
{
#endif

extern int spiInitiateComm(int spiFrequencyRate);


#ifdef __cplusplus
};
#endif

#endif //SPI_H
