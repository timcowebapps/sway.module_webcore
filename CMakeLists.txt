# Запрашиваем минимальную версию CMake
cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

include("${CMAKE_CURRENT_SOURCE_DIR}/submodules/sway.module_core/cmakehelpers/custom_add_subdirectory.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/submodules/sway.module_core/cmakehelpers/custom_enable_cxx17.cmake")

# Мета-информация о проекте
set(META_WEBCORE_PRJNAME "module_webcore")
set(META_WEBCORE_LIBNAME "lib${META_WEBCORE_PRJNAME}")
set(META_WEBCORE_VERSION_MAJOR 0)
set(META_WEBCORE_VERSION_MINOR 1)
set(META_WEBCORE_VERSION_PATCH 0)
set(META_WEBCORE_VERSION ${META_WEBCORE_VERSION_MAJOR}.${META_WEBCORE_VERSION_MINOR}.${META_WEBCORE_VERSION_PATCH})

# Опции сборки
option(MODULE_WEBCORE_SHARED_LIB "Build shared library (.so)" OFF)
option(MODULE_WEBCORE_ENABLE_TESTS "Enable test builds" OFF)
option(MODULE_USE_EMSCRIPTEN "Using emscripten compiler" OFF)
option(CUSTOM_EMSCRIPTEN_ROOT_DIR "Emscripten root directory" OFF)
option(CUSTOM_BOOST_ROOT_DIR "Boost root directory" OFF)
option(CUSTOM_GTEST_ROOT_DIR "GTest root directory" OFF)

if (NOT DEFINED CMAKE_TOOLCHAIN_FILE AND MODULE_USE_EMSCRIPTEN)
    set(CMAKE_TOOLCHAIN_FILE "${CUSTOM_EMSCRIPTEN_ROOT_DIR}/cmake/Modules/Platform/Emscripten.cmake")
    include(${CMAKE_TOOLCHAIN_FILE})
endif ()

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build" FORCE)
endif ()

project(${META_WEBCORE_PRJNAME} VERSION ${META_WEBCORE_VERSION} LANGUAGES CXX)

# Подмодули
custom_add_subdirectory("libmodule_core" submodules/sway.module_core)

if (MODULE_USE_EMSCRIPTEN)
    set(CMAKE_CXX_COMPILER "${CUSTOM_EMSCRIPTEN_ROOT_DIR}/em++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --bind -Os")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_EMSCRIPTEN")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-unicode-whitespace \
        -Wno-unused-local-typedef -Wno-invalid-noreturn -Wno-unused-command-line-argument")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s WASM=1 -s MODULARIZE=1")
endif ()

# Определяем каталог вывода по умолчанию
if (CMAKE_BUILD_TYPE MATCHES Debug)
    set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/dbg)
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/dbg)
else ()
    set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
endif ()

set(MODULE_WEBCORE_DIR ${CMAKE_CURRENT_LIST_DIR})

# Добавляем пути для поиска хедеров
include_directories("${EMSCRIPTEN_PREFIX}/system/include")
include_directories("${MODULE_WEBCORE_DIR}/submodules/sway.module_core/lib/include")
include_directories("${MODULE_WEBCORE_DIR}/lib/include")

# Получаем пути ко всем хедерам и исходникам библиотеки
file(GLOB_RECURSE MODULE_WEBCORE_HEADERS "${MODULE_WEBCORE_DIR}/lib/include/*.*")
file(GLOB_RECURSE MODULE_WEBCORE_SOURCE "${MODULE_WEBCORE_DIR}/lib/src/*.*")

if (MODULE_WEBCORE_SHARED_LIB)
    add_executable(${META_WEBCORE_LIBNAME} ${MODULE_WEBCORE_SOURCE})
    set_target_properties(${META_WEBCORE_LIBNAME} PROPERTIES OUTPUT_NAME ${META_WEBCORE_PRJNAME})
    set_target_properties(${META_WEBCORE_LIBNAME} PROPERTIES SUFFIX ".${META_WEBCORE_VERSION}.js")
else ()
    add_library(${META_WEBCORE_LIBNAME} STATIC ${MODULE_WEBCORE_SOURCE})
    set_target_properties(${META_WEBCORE_LIBNAME} PROPERTIES OUTPUT_NAME ${META_WEBCORE_PRJNAME})
    set_target_properties(${META_WEBCORE_LIBNAME} PROPERTIES SUFFIX ".a.${META_WEBCORE_VERSION}")
endif ()

custom_enable_cxx17(${META_WEBCORE_LIBNAME})
target_link_libraries(${META_WEBCORE_LIBNAME})

# Добавляем построение тестов
if (MODULE_WEBCORE_ENABLE_TESTS)
    if (MODULE_WEBCORE_SHARED_LIB)
        message(STATUS "[${META_WEBCORE_PRJNAME}]: Tests are only allowed with a static lib")
    else ()
        message(STATUS "[${META_WEBCORE_PRJNAME}]:Tests have been enabled")
        add_subdirectory(lib/tests/google)
    endif ()
endif ()
