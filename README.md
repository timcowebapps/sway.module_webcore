# sway.module_webcore
[![License][license-svg]][license-url]

## Клонирование проекта

```console
git clone --recursive https://github.com/timcogames/sway.module_webcore.git
```

## Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

Конфигурируем проект для сборки

#### для Google тестов

```console
cmake -D CMAKE_BUILD_TYPE=Debug \
      -D GLOB_GTEST_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/googletest/googletest \
      -D GLOB_GTEST_LIB_DIR=/Users/<USER_NAME>/Documents/Third-party/googletest/build/lib \
      -D MODULE_CORE_LIB_TYPE=object \
      -D MODULE_CORE_ENABLE_TESTS=OFF \
      -D MODULE_WEBCORE_ENABLE_TESTS=ON \
      ../

cmake -D CMAKE_BUILD_TYPE=Release \
      -D GLOB_EMSCRIPTEN_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/emsdk/upstream/emscripten \
      -D GLOB_EMSCRIPTEN_PLATFORM=ON \
      -D GLOB_EMSCRIPTEN_USE_BINDINGS=ON \
      -D GLOB_GTEST_ROOT_DIR= \
      -D GLOB_GMOCK_ROOT_DIR= \
      -D GLOB_GTEST_LIB_DIR= \
      -D GLOB_GMOCK_LIB_DIR= \
      -D MODULE_CORE_ENVIRONMENT=web \
      -D MODULE_CORE_COMPILATION=async \
      -D MODULE_WEBCORE_ENVIRONMENT=web \
      -D MODULE_WEBCORE_COMPILATION=async \
      -D MODULE_WEBCORE_LIB_TYPE=shared \
      -D MODULE_WEBCORE_ENABLE_TESTS=OFF \
      -D MODULE_WEBCORE_ENABLE_EXAMPLES=OFF \
      ../
```

Запускаем сборку

```console
cmake --build ./
```

[license-svg]: https://img.shields.io/github/license/mashape/apistatus.svg
[license-url]: LICENSE

