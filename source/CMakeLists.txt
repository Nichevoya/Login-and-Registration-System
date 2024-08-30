# ------------------------------ configuration ----------------------------- 

if (UNIX)
    add_definitions(-DUNIX)
    set(COMPILATION_FLAGS
        -std=c++20 
        # -fsanitize=address -fsanitize=leak 
        -Wall -Wextra -Werror -Wpedantic -g 
        ${COMPILATION_FLAGS_FROM_BUILD_TYPE} 
    )
    set(LARS_BINARY "lars.app")

elseif(WIN32)
    add_definitions(-DWIN32)
    set(COMPILATION_FLAGS
        /std:c++20 
        /W4 /Zi 
        ${COMPILATION_FLAGS_FROM_BUILD_TYPE} 
    )
    set(LARS_BINARY "lars")

endif()

set(INCLUDE_DIRECTORIES 
    "${CMAKE_SOURCE_DIR}/build/_deps/cxxopts-src/include"
    "${CMAKE_SOURCE_DIR}/build/_deps/phoenix-src/source"
)

set(BINARY_LINK_FLAGS
    # -fsanitize=address 
    # -fsanitize=leak 
    # -static-libasan 
)

set(LIBRARY_LINK_FLAGS 
    phoenixStatic 
)

file(GLOB_RECURSE HEADERS "./*.hpp")
file(GLOB_RECURSE SOURCES "./*.cpp")

add_executable(${LARS_BINARY}
    ${HEADERS}
    ${SOURCES}
)

# ---------------------------- compilation flags --------------------------- 

target_compile_options(${LARS_BINARY} PRIVATE 
    ${COMPILATION_FLAGS}
)

# ------------------------------- link binary ------------------------------ 

target_link_options(${LARS_BINARY} PRIVATE 
    ${BINARY_LINK_FLAGS}
)

# ----------------------------- link libraries ----------------------------- 

target_link_libraries(${LARS_BINARY} PRIVATE 
    ${LIBRARY_LINK_FLAGS}
)

# ----------------------------- header include ----------------------------- 

target_include_directories(${LARS_BINARY} PRIVATE 
    ${INCLUDE_DIRECTORIES}
)

# ---------------------------- target properties --------------------------- 

set_target_properties(${LARS_BINARY} PROPERTIES 
    LINKER_LANGUAGE CXX 
)

# --------------------------------- package -------------------------------- 
include("${CMAKE_SOURCE_DIR}/.cmake/install/lars.cmake")
