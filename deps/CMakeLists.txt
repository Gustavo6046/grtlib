cmake_minimum_required(VERSION 2.8)


foreach(CURRENT_DEPENDENCY ${DEPENDENCIES})
    message(STATUS "*** Dependency: ${CURRENT_DEPENDENCY}")

    add_subdirectory("${CURRENT_DEPENDENCY}" "${CURRENT_DEPENDENCY}/bin")

    link_directories("${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DEPENDENCY}/bin/lib")

    message(STATUS "Added ${CURRENT_DEPENDENCY}:\nincluding ${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DEPENDENCY}/include/\nlinking ${CMAKE_CURRENT_SOURCE_DIR}/lib/")

endforeach()
