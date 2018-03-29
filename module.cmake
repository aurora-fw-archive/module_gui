# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
# A Powerful General Purpose Framework
# More information in: https://aurora-fw.github.io/
#
# Copyright (C) 2017 Aurora Framework, All rights reserved.
#
# This file is part of the Aurora Framework. This framework is free
# software; you can redistribute it and/or modify it under the terms of
# the GNU Lesser General Public License version 3 as published by the
# Free Software Foundation and appearing in the file LICENSE included in
# the packaging of this file. Please review the following information to
# ensure the GNU Lesser General Public License version 3 requirements
# will be met: https://www.gnu.org/licenses/lgpl-3.0.html.

message(STATUS "Loading gui module...")

find_package(PkgConfig REQUIRED)

#if(NOT PKG_CONFIG_FOUND)
#	ExternalProject_Add(googletest
#	GIT_REPOSITORY    https://github.com/aurora-fw/external_pkg-config.git
#	GIT_TAG           pkg-config-0.29
#	SOURCE_DIR        "${CMAKE_BINARY_DIR}/googletest-src"
#	BINARY_DIR        "${CMAKE_BINARY_DIR}/googletest-build"
#	CONFIGURE_COMMAND ""
#	BUILD_COMMAND     ""
#	INSTALL_COMMAND   ""
#	TEST_COMMAND      ""
#	)
#endif()

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

if (NOT CONFIGURED_ONCE)
	set(AURORAFW_MODULE_GUI_SOURCE_DIR ${AURORAFW_MODULE_GUI_DIR}/src)
endif()

include_directories(${AURORAFW_MODULE_GUI_DIR}/include)
include_directories(${GTK3_INCLUDE_DIRS})

link_directories(${GTK3_LIBRARY_DIRS})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GTK3_CFLAGS_OTHER}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GTK3_CFLAGS_OTHER}")

file(GLOB_RECURSE AURORAFW_MODULE_GUI_SOURCE ${AURORAFW_MODULE_GUI_SOURCE_DIR}/*.cpp)

add_library (aurorafw-gui SHARED ${AURORAFW_MODULE_GUI_SOURCE})

foreach(_var_listlib ${GTK3_LIBRARIES})
	list(APPEND FULL_PATH_GTK3_LIBRARIES "${GTK3_LIBDIR}/lib${_var_listlib}.${AURORAFW_LIBRARY_EXT}")
endforeach()


target_link_libraries(aurorafw-gui aurorafw-corelib ${FULL_PATH_GTK3_LIBRARIES})

#set_target_properties(aurorafw-gui PROPERTIES OUTPUT_NAME aurorafw-gui
#											COMPILE_FLAGS "`pkg-config --cflags --libs gtk+-3.0`")
