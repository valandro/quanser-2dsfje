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
 * @file end_course_sensors.h
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Header file for End of Course Sensors Header utilized in quanser-2dsfje project for ENG10032
 */

#ifndef END_COURSE_SENSORS_H
#define END_COURSE_SENSORS_H

#ifdef __cplusplus
extern "C"
{
#endif

#define ELB_1 0
#define ELB_2 1

#define END_REACHED 1
#define END_NOT_REACHED 0

extern int read_end_course_sensors(int sensor);

#ifdef __cplusplus
};
#endif

#endif
