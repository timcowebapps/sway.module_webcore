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

Активируем PATH и переменные окружения EMSDK в текущем терминале

```console
source ~/Documents/emsdk/emsdk_env.sh
em++ --clear-cache
```

Конфигурируем проект для сборки

```console
cmake ./../
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
