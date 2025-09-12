cmake_minimum_required(VERSION 3.16)
project(openFleetPilot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pthread")

# Source Files
file (GLOB SOURCES "src/*.cpp")

# Find libraries
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBPQXX REQUIRED libpqxx)
pkg_check_modules(YAMLCPP REQUIRED yaml-cpp)

# Executable target
# add_executable()

# Link libraries
target_link_libraries(fms ${LIBPQXX_LIBRARIES} ${YAMLCPP_LIBRARIES})
target_include_directories(fms PUBLIC ${LIBPQXX_INCLUDE_DIRS} ${YAMLCPP_INCLUDE_DIRS})