# Мета-информация о проекте
set(META_WEBCORE_PRJNAME_TESTS "module_webcore_tests")
set(META_WEBCORE_EXENAME_TESTS "${META_WEBCORE_PRJNAME_TESTS}")

project(${META_WEBCORE_PRJNAME_TESTS} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(GTest_ROOT "${CUSTOM_GTEST_ROOT_DIR}")
set(GTEST_INCLUDE_DIR "${GTest_ROOT}/googletest/include")
set(GTEST_LIBRARY_DIR "${GTest_ROOT}/build/lib")

find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})

# Получаем пути ко всем исходникам с тестами
file(GLOB MODULE_WEBCORE_SOURCE_TESTS "${PROJECT_SOURCE_DIR}/*.spec.cpp")

add_executable(${META_WEBCORE_EXENAME_TESTS} ${MODULE_WEBCORE_SOURCE_TESTS} "${GTest_ROOT}/googletest/src/gtest_main.cc")
target_link_libraries(${META_WEBCORE_EXENAME_TESTS} libmodule_core libmodule_webcore ${GTEST_LIBRARY_DIR}/libgtest.a ${CMAKE_DL_LIBS})

add_custom_command(TARGET ${META_WEBCORE_EXENAME_TESTS} POST_BUILD COMMAND ${META_WEBCORE_EXENAME_TESTS})
