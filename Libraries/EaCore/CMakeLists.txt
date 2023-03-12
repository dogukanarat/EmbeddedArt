include(${EA_CMAKE_DIR}/Libraries.cmake)

add_library(
    EaCore
)

target_sources(
        EaCore
    PRIVATE
        "EaCommon.c"
        "EaCommon.h"
        "EaUtilities.c"
        "EaUtilities.h"
)

target_include_directories(
        EaCore
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS EaCore
    EXPORT EaLibraries-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/EaCore
    FILES_MATCHING PATTERN "*.h"
)
