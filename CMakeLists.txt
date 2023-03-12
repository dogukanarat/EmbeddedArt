cmake_minimum_required(VERSION 3.6)

project(
    EmbeddedArt
    VERSION 0.1
    LANGUAGES C CXX
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(EA_SCRIPT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Scripts")
set(EA_CMAKE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

include(GNUInstallDirs)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# if (CMAKE_BUILD_TYPE STREQUAL "Debug")
#     message("====== Building with coverage flags")

#     set(GCC_COVERAGE_COMPILE_FLAGS "--coverage -g -O0")
#     set(GCC_COVERAGE_LINK_FLAGS    "--coverage -g")

#     set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
#     set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
#     set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
# else(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     message("====== Building without coverage flags")
# endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

add_subdirectory(Externals)
add_subdirectory(Libraries)
add_subdirectory(Applications)

enable_testing()

add_subdirectory(Tests)
