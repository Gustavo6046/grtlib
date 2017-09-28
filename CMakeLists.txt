# Recommended generator directory: generated
cmake_minimum_required(VERSION 3.5)


message(STATUS "=== CONFIGURING grtlib ===")
project(grtlib)

list(APPEND DEPENDENCIES sfml)


include_directories(${CMAKE_SOURCE_DIR})

message(STATUS "=== CONFIGURING DEPENDENCIES ===")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps")

# Credits to https://stackoverflow.com/a/31010221/5129091
macro(use_cxx11)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
  endif ()
endmacro(use_cxx11)

# make sure cmake never fails on Win32, even if OpenSSH
# or some other program with SH bundled is installed.
if(WIN32)
    set(CMAKE_SH CMAKE_SH-NOTFOUND CACHE STRING "Location of the Unix shell executable. Not valid for Windows (use CMAKE_SH-NOTFOUND instead).")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/)
use_cxx11()

file(GLOB grtlib_src "*.cpp")
file(GLOB grtlib_headers "*.h")

if(CMAKE_BUILD_TYPE EQUAL "DEBUG")
    set(sfml-graphics sfml-graphics-d)
    set(sfml-window sfml-window-d)
    set(sfml-system sfml-system-d)

else()
    set(sfml-graphics sfml-graphics)
    set(sfml-window sfml-window)
    set(sfml-system sfml-system)

endif()

set(PREFIX_NAME "")

add_executable(grtlib_test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_library(grtlib ${grtlib_headers})
set_target_properties(grtlib PROPERTIES PREFIX "")

foreach(indivsrc ${grtlib_src})
    target_sources(grtlib_test PUBLIC ${indivsrc})
    target_sources(grtlib PUBLIC ${indivsrc})
endforeach()

target_link_libraries(grtlib_test PUBLIC ${sfml-graphics} ${sfml-window} ${sfml-system})
target_link_libraries(grtlib PUBLIC ${sfml-graphics} ${sfml-window} ${sfml-system})


foreach(CURRENT_DEPENDENCY ${DEPENDENCIES})
    target_include_directories(grtlib_test BEFORE PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/deps/${CURRENT_DEPENDENCY}/include")
    target_include_directories(grtlib BEFORE PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/deps/${CURRENT_DEPENDENCY}/include")

    add_custom_command(TARGET grtlib_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/deps/${CURRENT_DEPENDENCY}/bin/lib/
            "${CMAKE_CURRENT_SOURCE_DIR}/bin/"
    )

    add_custom_command(TARGET grtlib_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove
            ${CMAKE_CURRENT_SOURCE_DIR}/deps/${CURRENT_DEPENDENCY}/bin/lib/*.a
            ${CMAKE_CURRENT_SOURCE_DIR}/deps/${CURRENT_DEPENDENCY}/bin/lib/*.la
            ${CMAKE_CURRENT_SOURCE_DIR}/deps/${CURRENT_DEPENDENCY}/bin/lib/*.lai
            ${CMAKE_CURRENT_SOURCE_DIR}/deps/${CURRENT_DEPENDENCY}/bin/lib/*.lib
    )

endforeach()
