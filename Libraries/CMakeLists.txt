add_subdirectory(EaCore)
add_subdirectory(EaCircularBuffer)

install(
    EXPORT EaLibraries-config
    NAMESPACE EaLibraries::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
