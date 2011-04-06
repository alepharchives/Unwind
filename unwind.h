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

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <setjmp.h>
#include <string.h>

extern jmp_buf ex_buf__;
extern void *last_exc__;

#define THROW(e) \
    last_exc__ = e; \
    longjmp(ex_buf__, 0)

#define RETHROW \
    longjmp(ex_buf__, 0)

#define OPEN_EXCEPTION_SCOPE \
    jmp_buf prev_buf__; \
    memcpy(prev_buf__, ex_buf__, sizeof(jmp_buf)); \
    int jmp_out__ = setjmp(ex_buf__); \
    if (jmp_out__ == 0)

#define CLOSE_EXCEPTION_SCOPE \
    memcpy(ex_buf__, prev_buf__, sizeof(jmp_buf));

#define IF_EXCEPTION \
    if (jmp_out__ != 0)

#define TRY \
    { \
        OPEN_EXCEPTION_SCOPE

#define EXCEPT(e) \
        CLOSE_EXCEPTION_SCOPE \
        IF_EXCEPTION { \
            void *e = last_exc__; \

#define END_TRY \
        } \
    }

#define AFTER \
    { \
        OPEN_EXCEPTION_SCOPE

#define THEN \
        CLOSE_EXCEPTION_SCOPE

#define END_AFTER \
        IF_EXCEPTION { \
            RETHROW; \
        } \
    }

#endif
