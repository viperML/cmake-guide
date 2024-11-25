#include <cstdlib>
#include <iostream>
#include <mylib.h>

int main() {
  auto res = mylib::do_stuff();
  std::cout << "Result: " << res << std::endl;

  return EXIT_SUCCESS;
}
