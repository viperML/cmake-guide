with import <nixpkgs> { };
mkShell {
  packages = [
    cmake
    neocmakelsp
    ninja
    clang-tools
  ];

  env = {
    CMAKE_EXPORT_COMPILE_COMMANDS = true;
  };
}
