cmake_minimum_required(VERSION 3.2)

if($ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION_BUILD $ENV{TRAVIS_BUILD_NUMBER})
else()
    set(VERSION_BUILD 0)
endif()

message(STATUS "VERSION_BUILD: " ${VERSION_BUILD})

project(graph_editor_pkg VERSION 0.0.${VERSION_BUILD})

set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")

add_executable(graph_editor ${SOURCE_PATH}/main.cpp)

target_include_directories(graph_editor PRIVATE include)

set_target_properties(
  graph_editor

  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -W1 -Wall -Wextra
)

install(TARGETS graph_editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vladimir.englisbox@gmail.com)

include (CPack)