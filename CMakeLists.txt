# Запрашиваем минимальную версию CMake
cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

include(${CMAKE_CURRENT_SOURCE_DIR}/modules/sway.module_core/cmakehelpers/custom_add_subdirectory.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/modules/sway.module_core/cmakehelpers/custom_enable_cxx17.cmake)

# Мета-информация о проекте
set(META_PROJECT_NAME module_webcore)
set(META_LIB_NAME lib${META_PROJECT_NAME})
set(META_VERSION_MAJOR 0)
set(META_VERSION_MINOR 1)
set(META_VERSION_PATCH 0)
set(META_VERSION ${META_VERSION_MAJOR}.${META_VERSION_MINOR}.${META_VERSION_PATCH})
set(META_LANGUAGES C CXX)

project(${META_PROJECT_NAME} VERSION ${META_VERSION} LANGUAGES ${META_LANGUAGES})

set(EMSCRIPTEN_PREFIX "/home/bonus85/Documents/emsdk/emscripten/incoming")
set(EMSCRIPTEN_TOOLCHAIN_PATH "${EMSCRIPTEN_PREFIX}/system")

custom_add_subdirectory(core)

set(CMAKE_CXX_COMPILER "${EMSCRIPTEN_PREFIX}/emcc")
# set(CMAKE_CXX_FLAGS_INIT "-s WASM=1")
# set(CMAKE_CXX_FLAGS_RELEASE_INIT "-DNDEBUG -O3")

# Определяем каталог вывода по умолчанию
if(CMAKE_BUILD_TYPE MATCHES Debug)
	set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/dbg)
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/dbg)
else()
	set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
endif()

set(MODULE_DIR ${CMAKE_CURRENT_LIST_DIR})

# Добавляем пути для поиска хедеров
include_directories("${EMSCRIPTEN_TOOLCHAIN_PATH}/include")
include_directories(${MODULE_DIR}/include)
include_directories(${MODULE_DIR}/modules/sway.module_core/include)

# Получаем пути ко всем хедерам и исходникам библиотеки
file(GLOB_RECURSE MODULE_HEADERS ${MODULE_DIR}/include/*.*)
file(GLOB_RECURSE MODULE_SOURCES ${MODULE_DIR}/src/*.*)

# Добавляем в проект цель для сборки статической библиотеки
add_library(${META_LIB_NAME} STATIC ${MODULE_SOURCES})
set_target_properties(${META_LIB_NAME} PROPERTIES OUTPUT_NAME ${META_PROJECT_NAME})
set_target_properties(${META_LIB_NAME} PROPERTIES PREFIX "")
set_target_properties(${META_LIB_NAME} PROPERTIES SUFFIX ".a.${META_VERSION}")

custom_enable_cxx17(${META_LIB_NAME})

target_link_libraries(${META_LIB_NAME} libmodule_core)
