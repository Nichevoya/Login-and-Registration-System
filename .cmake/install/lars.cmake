install(TARGETS ${LARS_BINARY} DESTINATION bin)

# ---------------------------- Packaging support --------------------------- 
set(CPACK_PACKAGE_NAME ${LARS_BINARY})
set(CPACK_PACKAGE_VENDOR "Isaak Nicolas")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "LARS is a simple system which allow the user to register an account and login with the registered credentials. It is a command line application and several command are predefined.")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")

set(CPACK_GENERATOR "TGZ;DEB;ZIP")
set(CPACK_SOURCE_IGNORE_FILES
    /.git
    /.vscode
    /dist
    /.*build.*
    /\\\\.DS_Store
)

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Isaak Nicolas <isaak.nicolas@epitech.eu>")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "A simple, cross-platform, login and registration system.")
set(CPACK_DEBIAN_PACKAGE_LICENSE "MIT")

include(CPack)
