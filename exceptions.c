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

#include <stdlib.h>
#include <assert.h>

#include "exceptions.h"

uint32_t exc_type(void *exc) {
    return *(uint32_t *)exc;
}

void exc_free(void *exc) {
    switch (exc_type(exc)) {
        case EXC_APP_SPECIFIC:
            free(exc);
        case EXC_OUT_OF_MEM:
            return;
    };
}

typedef struct app_specific_t {
    uint32_t type;
    const char *app_name;
    void *exc;
} app_specific_t;

void *exc_app_specific(const char *app_name, void *exc) {
    app_specific_t *out = malloc(sizeof(app_specific_t));
    out->type = EXC_APP_SPECIFIC;
    out->app_name = app_name;
    out->exc = exc;
    return out;
}

bool exc_app_specific_is_from(void *exc, const char *app_name) {
    assert(exc_type(exc) == EXC_APP_SPECIFIC);
    /* This is not a mistake, every app_name for a given app should refer to 
       the same memory location. */
    return ((app_specific_t *)exc)->app_name == app_name;
}

void *exc_app_specific_unpack(void *exc) {
    assert(exc_type(exc) == EXC_APP_SPECIFIC);
    return ((app_specific_t *)exc)->exc;
}

uint32_t oom = EXC_OUT_OF_MEM;

void *exc_out_of_mem() {
    return &oom;
}
