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
cmake -DCMAKE_BUILD_TYPE=Release -DCUSTOM_GTEST_ROOT_DIR=/Users/apriori85/Documents/Third-party/googletest -DMODULE_WEBCORE_ENABLE_TESTS=ON ../
```

Запускаем сборку

```console
cmake --build ./
```

## Разное

```console
~/Documents/emsdk/emsdk list
~/Documents/emsdk/emsdk install sdk-incoming-64bit
~/Documents/emsdk/emsdk activate --build=Release sdk-incoming-64bit binaryen-master-64bit
```

[license-svg]: https://img.shields.io/github/license/mashape/apistatus.svg
[license-url]: LICENSE
