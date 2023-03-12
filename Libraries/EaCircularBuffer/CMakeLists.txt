include(${EA_CMAKE_DIR}/Libraries.cmake)

add_library(
    EaCircularBuffer
)

target_sources(
        EaCircularBuffer
    PRIVATE
        "EaCircularBuffer.c"
        "EaCircularBuffer.h"
)

target_include_directories(
        EaCircularBuffer
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS EaCircularBuffer
    EXPORT EaLibraries-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/EaCircularBuffer
    FILES_MATCHING PATTERN "*.h"
)
