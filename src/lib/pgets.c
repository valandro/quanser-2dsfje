/*
  pgets.c: Gets a string from a file, given its path.

  Copyright (c) 2016 Walter Fetter Lages <w.fetter@ieee.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    You can also obtain a copy of the GNU General Public License
    at <http://www.gnu.org/licenses>.

*/

/**
 * @file pgets.c
 * @author Walter Fetter Lages
 * @date Sept 2020
 * @brief Source file for pgets functions utilized in quanser-2dsfje project for ENG10032
 */

// Project Headers
#include <galileo2io.h>

// C Headers
#include <fcntl.h>
#include <unistd.h>

char *pgets(char *s,int size,const char path[])
{
	int fd;

	if((fd=open(path, O_RDONLY)) ==-1) return NULL;
	read(fd, s, size);
	close(fd);
	return s;
}
