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
cmake -DCUSTOM_GTEST_ROOT_DIR=/Users/apriori85/Documents/Third-party/googletest -DMODULE_WEBCORE_ENABLE_TESTS=ON ../
```

Запускаем сборку

```console
cmake --build ./
```


[license-svg]: https://img.shields.io/github/license/mashape/apistatus.svg
[license-url]: LICENSE

