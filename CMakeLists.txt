#--------------------------------------------------------------------------------
# CMake version
#--------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

#--------------------------------------------------------------------------------
# Project directories
#--------------------------------------------------------------------------------

set(MODULE_WEBCORE_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(MODULE_WEBCORE_LIST_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(MODULE_WEBCORE_CMAKE_DIR "${MODULE_WEBCORE_ROOT_DIR}/submodules/sway.module_core/cmake_modules")
set(MODULE_WEBCORE_LIB_DIR "${MODULE_WEBCORE_ROOT_DIR}/lib")
set(MODULE_WEBCORE_BIN_DIR "${CMAKE_SOURCE_DIR}/bin")

set(SYSTEM_INC_DIR "/opt/X11/include")
set(SYSTEM_LIB_DIR "/opt/X11/lib")

#--------------------------------------------------------------------------------
# Include CMake modules
#--------------------------------------------------------------------------------

include("${MODULE_WEBCORE_CMAKE_DIR}/options.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/set_output_dir.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/add_submodule.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/project_metadata.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/enable_cxx17.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/enable_coverage.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/modules/logger.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/modules/create_object_library.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/modules/create_interface.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/modules/compiler/clang/create_library.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/modules/compiler/emscripten/setup.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/modules/compiler/emscripten/create_library.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/modules/compiler/emscripten/gen_target_name.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/modules/compiler/emscripten/set_optimization.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/modules/compiler/emscripten/set_environment.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/modules/compiler/emscripten/set_compilation.cmake")
include("${MODULE_WEBCORE_CMAKE_DIR}/modules/compiler/emscripten/set_modularize.cmake")

#--------------------------------------------------------------------------------
# Options
#--------------------------------------------------------------------------------

set_glob_options()

option(MODULE_WEBCORE_SHARED_LIB "Build shared library (.so)" OFF)
option(MODULE_WEBCORE_ENABLE_TESTS "Enable test builds" OFF)
option(CUSTOM_EMSCRIPTEN_ROOT_DIR "Emscripten root directory" OFF)
option(CUSTOM_BOOST_ROOT_DIR "Boost root directory" OFF)
option(CUSTOM_GTEST_ROOT_DIR "GTest root directory" OFF)

#--------------------------------------------------------------------------------
# [EMSCRIPTEN]: Setup
#--------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  emscripten_setup()
endif()

#--------------------------------------------------------------------------------
# Project
#--------------------------------------------------------------------------------

project_metadata("module_webcore" 0.1.0)
project(${MODULE_WEBCORE_PROJ_NAME} VERSION ${MODULE_WEBCORE_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=default -fPIE")

#---------------------------------------------------------------------------------
# Submodules
#---------------------------------------------------------------------------------

add_submodule("module_core" submodules/sway.module_core)

#--------------------------------------------------------------------------------
# Executable output path
#--------------------------------------------------------------------------------

set_output_dir(${MODULE_WEBCORE_BIN_DIR})

#---------------------------------------------------------------------------------
# Include project headers
#---------------------------------------------------------------------------------

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  include_directories("/usr/local/include/c++/v1")
endif()

include_directories("${SYSTEM_INC_DIR}")
include_directories("${MODULE_WEBCORE_LIST_DIR}/lib/cxx/include")
include_directories("${MODULE_WEBCORE_LIST_DIR}/submodules/sway.module_core/lib/cxx/include")

#---------------------------------------------------------------------------------
# Library
#---------------------------------------------------------------------------------

add_subdirectory(lib/cxx)

#---------------------------------------------------------------------------------
# Tests
#---------------------------------------------------------------------------------

if (MODULE_WEBCORE_ENABLE_TESTS)
    if (MODULE_WEBCORE_SHARED_LIB)
        message(STATUS "[${META_WEBCORE_PRJNAME}]: Tests are only allowed with a static lib")
    else ()
        message(STATUS "[${META_WEBCORE_PRJNAME}]: Tests have been enabled")
        add_subdirectory(lib/cxx/tests/google)
    endif ()
endif ()
