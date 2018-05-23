cmake_minimum_required(VERSION 3.2)

if($ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION_BUILD $ENV{TRAVIS_BUILD_NUMBER})
else()
    set(VERSION_BUILD 0)
endif()

message(STATUS "VERSION_BUILD: " ${VERSION_BUILD})

project(graph_editor_pkg VERSION 0.0.${VERSION_BUILD})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")

add_executable(graph_editor ${SOURCE_PATH}/main.cpp)

add_executable(test_main ${PROJECT_SOURCE_DIR}/tests/test_main.cpp)

target_include_directories(graph_editor PRIVATE include)
target_include_directories(test_main PRIVATE include)

set_target_properties(
  graph_editor
  test_main

  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_compile_definitions(test_main PRIVATE BOOST_TEST_DYN_LINK)
target_link_libraries(test_main
  Boost::unit_test_framework
)

install(TARGETS graph_editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vladimir.englisbox@gmail.com)

include (CPack)

enable_testing()

add_test(tests test_main)
