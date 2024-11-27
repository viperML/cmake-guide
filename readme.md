# cmake-guide

This repository exposes 2 C++ packages that use CMake:

- `mylib`, a regular library
- `myapp`, a regular application that depends on `mylib`

The library exports the proper CMake targets, such that it can be linked to from
the application using `find_package(mylib REQUIRED)`.

Additionally, the library is also prepared to be used with `add_subdirectory`,
requiring no changes to the targets to link to.

---

Building as an external package (useful for packaging):

```
$ pushd mylib
$ cmake -B build -DCMAKE_INSTALL_PREFIX=../out
$ cd build
$ make all install
$ popd

$ pushd myapp
$ CMAKE_PREFIX_PATH=../out cmake -B build -DUSE_EXTERNAL_MYLIB=ON
$ cd build
$ make all
```

---

Building as a subproject (useful for development):
```
$ pushd myapp
$ cmake -B build
$ make all
```

### Documentation

Please read the CMake files:

- [./mylib/CMakeLists.txt](./mylib/CMakeLists.txt)
- [./mylib/mylib-config.cmake](./mylib/mylib-config.cmake)
- [./myapp/CMakeLists.txt](./myapp/CMakeLists.txt)

- https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/
- https://www.foonathan.net/2016/03/cmake-install/
- https://www.youtube.com/watch?v=eC9-iRN2b04
