#include <cstdlib>
#include <iostream>

#include <mylib.h>
#include <mylib-header.h>

int main() {
  auto res = mylib::do_stuff();
  std::cout << "Result: " << res << std::endl;

  auto m = Matrix<double>(2, 2);

  return EXIT_SUCCESS;
}
