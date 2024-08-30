if (NOT cxxopts_FOUND)
    include(FetchContent)
    
    FetchContent_Declare(
        cxxopts 
        GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git 
        GIT_TAG v3.1.1
    )
    
    FetchContent_GetProperties(cxxopts)
    FetchContent_MakeAvailable(cxxopts)
    
    if (NOT cxxopts_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(cxxopts)
        set(BUILD_EXEMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(${cxxopts_SOURCE_DIR} ${cxxopts_BINARY_DIR})
    endif()
endif()