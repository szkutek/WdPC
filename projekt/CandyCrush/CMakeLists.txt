cmake_minimum_required(VERSION 3.6)
project(CandyCrush C)
# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})
# Link the target to the GTK+ libraries

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/main.c)
set(GUI src/gui/gui.h src/gui/gui.c)
set(MODEL src/model/model.h src/model/model.c)
add_executable(CandyCrush ${SOURCE_FILES} ${GUI} ${MODEL})
target_link_libraries(CandyCrush ${GTK3_LIBRARIES})