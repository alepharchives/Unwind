/*
    Copyright (C) 2011 Unwind authors,
    
    This file is part of Unwind.
    
    Unwind is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Unwind is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdbool.h>

#define EXC_APP_SPECIFIC 1
#define EXC_OUT_OF_MEM 2

uint32_t exc_type(void *);
void exc_free(void *);

void *exc_app_specific(const char *, void *);
bool exc_app_specific_is_from(void *, const char *);
void *exc_app_specific_unpack(void *);

void *exc_out_of_mem();
