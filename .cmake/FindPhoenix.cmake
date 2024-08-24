if (NOT phoenix_FOUND)
    include(FetchContent)
    
    FetchContent_Declare(
        phoenix 
        GIT_REPOSITORY https://github.com/Nichevoya/Phoenix.git 
        GIT_TAG dev
    )
    
    FetchContent_GetProperties(phoenix)
    FetchContent_MakeAvailable(phoenix)
    
    if (NOT phoenix_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(phoenix)
        set(BUILD_EXEMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(${phoenix_SOURCE_DIR} ${phoenix_BINARY_DIR})
    endif()
endif()