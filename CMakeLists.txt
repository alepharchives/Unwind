#    Copyright (C) 2011 Unwind authors,
#
#    This file is part of Unwind.
#
#    Unwind is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Unwind is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.
#
#    You should have received a copy of the GNU Lesser General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(UnwindSources unwind exceptions)

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}")

ADD_LIBRARY(unwind_static STATIC ${UnwindSources})
SET_TARGET_PROPERTIES(unwind_static PROPERTIES LINKER_LANGUAGE C)

ADD_LIBRARY(unwind SHARED ${UnwindSources})
SET_TARGET_PROPERTIES(unwind PROPERTIES LINKER_LANGUAGE C)
