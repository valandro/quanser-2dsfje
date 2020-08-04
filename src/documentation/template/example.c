// Copyright (C) 2020 Gustavo Francisco, Lucas Valandro, Lucas Tansini
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
 * @file example.c
 * @author Gustavo Francisco, Lucas Valandro, Lucas Tansini
 * @date 08 Aug 2020
 * @brief Template C source file example of doxygen utilization for generating documentation.
 */

 #include <stdio.h>

/**
 * @brief This function returns the power of two of a desired number.
 * Detailed description should go here.
 * Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor
 * incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco
 * @param iNumberInput integer
 */
int powerOfTwo(int iNumberInput) {
  return iNumberInput*iNumberInput;
}

/**
 * @brief Main program entry.
 *
 * Detailed description should go here.
 * Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor
 * incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco
 * @param Receives arguments from user
 */
int main(int argv, char* argc[] ) {

  printf("Hello, World!\n.");
  return 0;
}
