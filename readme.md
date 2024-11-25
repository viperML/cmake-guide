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

You can find more documentation in the CMake files.