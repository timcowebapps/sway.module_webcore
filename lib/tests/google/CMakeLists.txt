# Мета-информация о проекте
set(META_WEBCORE_PRJNAME_TESTS "module_webcore_tests")
set(META_WEBCORE_EXENAME_TESTS "${META_WEBCORE_PRJNAME_TESTS}")

project(${META_WEBCORE_PRJNAME_TESTS} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

#--------------------------------------------------------------------------------
# Set dependency paths
#--------------------------------------------------------------------------------

set(GTEST_ROOT "${GLOB_GTEST_ROOT_DIR}")
set(GTEST_INC_DIR "${GTEST_ROOT}/include")
set(GTEST_SRC_DIR "${GTEST_ROOT}/src")

#--------------------------------------------------------------------------------
# Include dependency headers
#--------------------------------------------------------------------------------

include_directories("${GTEST_INC_DIR}")

find_package(Threads REQUIRED)

# Получаем пути ко всем исходникам с тестами
file(GLOB MODULE_WEBCORE_SOURCE_TESTS "${PROJECT_SOURCE_DIR}/*.spec.cpp")

add_executable(${META_WEBCORE_EXENAME_TESTS} ${MODULE_WEBCORE_SOURCE_TESTS} "${GTEST_SRC_DIR}/gtest_main.cc")
target_link_libraries(${META_WEBCORE_EXENAME_TESTS} module_core_obj libmodule_webcore ${GLOB_GTEST_LIB_DIR}/libgtest.a ${CMAKE_DL_LIBS})

add_custom_command(TARGET ${META_WEBCORE_EXENAME_TESTS} POST_BUILD COMMAND ${META_WEBCORE_EXENAME_TESTS})
