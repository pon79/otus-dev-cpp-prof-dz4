cmake_minimum_required(VERSION 3.20)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(print_ip LANGUAGES CXX VERSION ${PROJECT_VESRION})

set(CMAKE_CXX_STANDARD 20 CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(print_ip main.cpp print_ip.h)

# ======== GOOGLE_TEST start ===========
#enable_testing()
#include(GoogleTest)

#add_executable(test_print_ip test_print_ip.cpp)
#target_link_libraries(test_print_ip
#    gtest
#    gtest_main
#)

#gtest_discover_tests(test_print_ip)

# ======== GOOGLE_TEST end ===========

if (MSVC)
    target_compile_options(print_ip PRIVATE
        /W4
    )
else ()
    target_compile_options(print_ip PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS print_ip RUNTIME DESTINATION bin)


# ======== DEB pack start ===========
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT pon79job@gmail.com)

include(CPack)
# ======== DEB pack end ===========
