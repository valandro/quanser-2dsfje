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
 * @file decoder.h
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Header file for Decoder utilized in quanser-2dsfje project for ENG10032
 */
 #ifndef DECODER_H
 #define DECODER_H


#define SPI_DEVICE_PATH "/dev/spidev1.0"
#define SS_PATH "/sys/class/gpio/gpio10/value"
#define DEVICE_READING_WRITING_ERROR -1
#define DECODER_INIT_SUCCESS 1
#define DECODER_INIT_ERROR -1
#define BITS_PER_WORD 8
#define SPI_SPEED 8000000

#ifdef __cplusplus
extern "C"
{
#endif

 /*
 extern int read_spi_reg()
 extern int write_spi_Reg()
 */
extern int decoder_init();
extern int spi_start();
extern int spi_stop();
extern int write_spi(unsigned char op_code, unsigned char write_data);
extern int clear_counter();
extern int decoder_read_counter();

#ifdef __cplusplus
};
#endif

#endif //DECODER_H
