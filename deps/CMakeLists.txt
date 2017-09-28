cmake_minimum_required(VERSION 2.8)


list(APPEND DEPENDENCIES sfml)

foreach(CURRENT_DEPENDENCY ${DEPENDENCIES})
    message(STATUS "*** Dependency: ${CURRENT_DEPENDENCY}")
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DEPENDENCY} ${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DEPENDENCY}/bin)

    file(GLOB outLib "${CURRENT_DEPENDENCY}/bin/lib/*.dll"
        configure_file(${CURRENT_DEPENDENCY}/bin/${outLib} slib/${outLib} COPYONLY)
    )

    file(GLOB outLib "${CURRENT_DEPENDENCY}/bin/lib/*.so"
        configure_file(${CURRENT_DEPENDENCY}/bin/${outLib} slib/${outLib} COPYONLY)
    )

    message(STATUS "Added ${CURRENT_DEPENDENCY}:\nincluding ${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DEPENDENCY}/include/\nlinking ${CMAKE_CURRENT_SOURCE_DIR}/lib/")
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DEPENDENCY}/include/)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/)

endforeach()
