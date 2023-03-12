include(${EA_CMAKE_DIR}/Applications.cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(
        EaMultiThreadApplication
)

target_sources(
        EaMultiThreadApplication
        PRIVATE
            "Main.c"
            "Osal.c"
            "Osal.h"
)

 target_link_libraries(
     EaMultiThreadApplication
     PUBLIC
         EaCore
         EaCircularBuffer
 )



