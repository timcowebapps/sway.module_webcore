#---------------------------------------------------------------------------------
# Project directories
#---------------------------------------------------------------------------------

set(SYSTEM_INC_DIR "/opt/X11/include")
set(SYSTEM_LIB_DIR "/opt/X11/lib")

#---------------------------------------------------------------------------------
# [Emscripten]: Setup
#---------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  emscripten_setup()
endif()

#---------------------------------------------------------------------------------
# Include project headers
#---------------------------------------------------------------------------------

include_directories("${SYSTEM_INC_DIR}")
include_directories("${MODULE_WEBCORE_LIST_DIR}/lib/cxx/include")
include_directories("${MODULE_WEBCORE_LIST_DIR}/submodules/sway.module_core/lib/cxx/include")

#---------------------------------------------------------------------------------
# Find the project headers, sources
#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------
# Find packages
#---------------------------------------------------------------------------------

if(GLOB_EMSCRIPTEN_PLATFORM)
  # Empty
else()
  find_package(X11 REQUIRED)
endif()

#---------------------------------------------------------------------------------
# Create object
#---------------------------------------------------------------------------------

# Определяем целевую библиотеку, если она не определена
if(NOT DEFINED MODULE_WEBCORE_LIB_TARGET OR "${MODULE_WEBCORE_LIB_TARGET}" STREQUAL "")
  set(MODULE_WEBCORE_LIB_TARGET "module_webcore")
endif()

if(NOT DEFINED MODULE_WEBCORE_OBJ_TARGET OR "${MODULE_WEBCORE_OBJ_TARGET}" STREQUAL "")
  set(MODULE_WEBCORE_OBJ_TARGET "${MODULE_WEBCORE_LIB_TARGET}_obj")
endif()

if(NOT TARGET ${MODULE_WEBCORE_OBJ_TARGET})
  create_object_library(${MODULE_WEBCORE_OBJ_TARGET} "${MODULE_WEBCORE_ROOT_DIR}/lib/cxx/src/*.*" TRUE)
  # enable_cxx17("${MODULE_WEBCORE_OBJ_TARGET}")
endif()

#---------------------------------------------------------------------------------
# Build libraries
#---------------------------------------------------------------------------------

if(NOT MODULE_WEBCORE_LIB_TYPE STREQUAL "object")
  if(GLOB_EMSCRIPTEN_PLATFORM)
    # Отладочная информация
    message(STATUS "DEBUG: Before create_emscripten_library call")
    message(STATUS "DEBUG: MODULE_WEBCORE_LIB_TARGET = ${MODULE_WEBCORE_LIB_TARGET}")
    message(STATUS "DEBUG: MODULE_WEBCORE_ENVIRONMENT = ${MODULE_WEBCORE_ENVIRONMENT}")
    message(STATUS "DEBUG: MODULE_WEBCORE_COMPILATION = ${MODULE_WEBCORE_COMPILATION}")
    
    # Проверяем количество аргументов
    set(ARG_COUNT 4)
    message(STATUS "DEBUG: Calling create_emscripten_library with ${ARG_COUNT} arguments")

    # Проверяем, что object target существует
    if(NOT TARGET ${MODULE_WEBCORE_OBJ_TARGET})
      message(FATAL_ERROR "Object target ${MODULE_WEBCORE_OBJ_TARGET} does not exist")
    endif()

    create_emscripten_library(${MODULE_WEBCORE_LIB_TARGET} ${MODULE_WEBCORE_ENVIRONMENT} ${MODULE_WEBCORE_COMPILATION} OUTPUT_TARGET_NAME_LIST)
    foreach(target IN LISTS OUTPUT_TARGET_NAME_LIST)
      target_link_libraries(${target} module_core_obj -lpng -lz)
      target_link_options(${target} PUBLIC 
        "SHELL:-s STRICT=1"
        "SHELL:-s MODULARIZE=1"
        "SHELL:-s ALLOW_TABLE_GROWTH=1"
        "SHELL:-s EXPORT_NAME=\"create_webcore_module\""
        "SHELL:-s EXPORTED_RUNTIME_METHODS=@${MODULE_WEBCORE_LIB_DIR}/runtime-exports.json")

      # Отладочная информация
      message(STATUS "DEBUG: GLOB_EMSCRIPTEN_USE_BINDINGS = ${GLOB_EMSCRIPTEN_USE_BINDINGS}")
      message(STATUS "DEBUG: MODULE_WEBCORE_LIB_DIR = ${MODULE_WEBCORE_LIB_DIR}")

      if(NOT GLOB_EMSCRIPTEN_USE_BINDINGS)
        message(STATUS "DEBUG: Adding EXPORTED_FUNCTIONS for target: ${target}")
        target_link_options(${target} PUBLIC "SHELL:-s EXPORTED_FUNCTIONS=@${MODULE_WEBCORE_LIB_DIR}/exports.json")
      else()
        message(STATUS "DEBUG: Skipping EXPORTED_FUNCTIONS - using bindings")
      endif()

      printf_link_options(${target})
    endforeach()
  else()
    create_clang_library(${MODULE_WEBCORE_LIB_TARGET} "${MODULE_WEBCORE_ROOT_DIR}/lib/cxx/src/*.*")
  endif()
endif()
