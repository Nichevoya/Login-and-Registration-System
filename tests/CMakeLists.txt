# ------------------------------ configuration ----------------------------- 

if (UNIX)
    add_definitions(-DUNIX)
    set(COMPILATION_FLAGS
        -std=c++20 
        -Wall -Wextra -Werror -Wpedantic -g ${COMPILATION_FLAGS_FROM_BUILD_TYPE} 
    )
    set(LARS_TEST_BINARY "lars.tests.app")

elseif(WIN32)
    add_definitions(-DWIN32)
    set(COMPILATION_FLAGS
        /std:c++20 
        /W4 /Zi ${COMPILATION_FLAGS_FROM_BUILD_TYPE} 
    )
    set(LARS_TEST_BINARY "lars.tests")

endif()

set(INCLUDE_DIRECTORIES 
    "${CMAKE_SOURCE_DIR}/build/_deps/cxxopts-src/include/"
    "${CMAKE_SOURCE_DIR}/build/_deps/phoenix-src/source/"
    "${CMAKE_SOURCE_DIR}/source/"
)

set(LIBRARY_LINK_FLAGS 
    phoenixStatic 
    Catch2::Catch2WithMain 
)

set(LARS_TEST_MODULES 

)

file(GLOB_RECURSE LARS_TEST_HEADERS "./*.hpp")
file(GLOB_RECURSE LARS_TEST_SOURCES "./*.cpp")

add_executable(${LARS_TEST_BINARY} 
    ${LARS_TEST_HEADERS}
    ${LARS_TEST_SOURCES}
)

# ------------------------------- build order ------------------------------ 

add_dependencies(${LARS_TEST_BINARY} ${LIBRARY_LINK_FLAGS} ${LARS_TEST_MODULES})

# ---------------------------- compilation flags --------------------------- 

target_compile_options(${LARS_TEST_BINARY} PRIVATE 
    ${COMPILATION_FLAGS}
)

# ----------------------------- link libraries ----------------------------- 

target_link_libraries(${LARS_TEST_BINARY} PRIVATE 
    ${LIBRARY_LINK_FLAGS}
)

# ----------------------------- header include ----------------------------- 

target_include_directories(${LARS_TEST_BINARY} PRIVATE 
    ${INCLUDE_DIRECTORIES}
)

# ---------------------------- target properties --------------------------- 

set_target_properties(${LARS_TEST_BINARY} PROPERTIES 
    LINKER_LANGUAGE CXX
)