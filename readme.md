# cmake-guide

This repository exposes 2 C++ packages that use CMake:

- `mylib`, a regular library
- `myapp`, a regular application that depends on `mylib`

The library exports the proper CMake targets, such that it can be linked to from
the application using `find_package(mylib REQUIRED)`.

First, select some directory to use as a prefix to install the library. For
example, if you cloned this repo at `~/src/cmake-guide`, a nice option is to
use `~/src/cmake-guide/out` as the prefix.

To build and install the library:

```
~/src/cmake-guide/mylib 
$ cmake -B build -DCMAKE_INSTALL_PREFIX=../out 
$ cd build
$ make all install
```

To use the library from the app:

```
~/src/cmake-guide/myapp
$ export CMAKE_PREFIX_PATH=../out
$ cmake -B build
$ make
```

- `CMAKE_INSTALL_PREFIX` controls where `make install` will install the library.
- `CMAKE_PREFIX_PATH` controls where `cmake` looks for libraries.

Please read the CMake files:

- [./mylib/CMakeLists.txt](./mylib/CMakeLists.txt)
- [./mylib/mylib-config.cmake](./mylib/mylib-config.cmake)
- [./myapp/CMakeLists.txt](./myapp/CMakeLists.txt)

### Documentation

- https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/
- https://www.foonathan.net/2016/03/cmake-install/
- https://www.youtube.com/watch?v=eC9-iRN2b04
