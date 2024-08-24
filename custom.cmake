# ---------------------------------- build --------------------------------- 

if(CMAKE_BUILD_TYPE STREQUAL "Validation")
    add_compile_definitions(-DVALIDATION)
    if (UNIX)
        set(COMPILATION_FLAGS_FROM_BUILD_TYPE -O3)
    
    elseif(WIN32)
        set(COMPILATION_FLAGS_FROM_BUILD_TYPE /Ox)
    
    endif()
endif()
