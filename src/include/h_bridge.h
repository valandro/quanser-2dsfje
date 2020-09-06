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
 * @file h_bridge.h
 * @author Lucas Augusto Tansini, Lucas Valandro da Rocha, Gustavo Francisco
 * @date Sept 2020
 * @brief Header file for H Brige header utilized in quanser-2dsfje project for ENG10032
 */

#ifndef H_BRIDGE
#define H_BRIDGE

#ifdef __cplusplus
extern "C"
{
#endif

#define THERMAL_FLAG_OFF 0
#define THERMAL_FLAG_ON 1

extern double getCurrentSensor();
extern int getThermalFlag();

#ifdef __cplusplus
};
#endif

#endif // H_BRIDGE
