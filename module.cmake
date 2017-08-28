message(STATUS "Loading gui module...")

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

if (NOT CONFIGURED_ONCE)
	set(MODULE_GUI_SOURCE_DIR ${MODULE_GUI_DIR}/src)
endif()

include_directories(${MODULE_GUI_DIR}/include)
include_directories(${GTK3_INCLUDE_DIRS})

link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

add_library (aurorafw-gui SHARED ${MODULE_GUI_SOURCE_DIR}/Application.cpp
                                 ${MODULE_GUI_SOURCE_DIR}/Button.cpp
                                 ${MODULE_GUI_SOURCE_DIR}/Label.cpp
                                 ${MODULE_GUI_SOURCE_DIR}/Style.cpp
                                 ${MODULE_GUI_SOURCE_DIR}/Window.cpp)

target_link_libraries(aurorafw-gui ${GTK3_LIBRARIES})

set_target_properties(aurorafw-gui PROPERTIES OUTPUT_NAME aurorafw-gui
                                            COMPILE_FLAGS "`pkg-config --cflags --libs gtk+-3.0`")
