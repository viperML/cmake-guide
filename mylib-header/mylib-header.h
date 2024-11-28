#include <iostream>

template <typename T> class Matrix {
public:
  Matrix<T>(size_t m, size_t n) { this->ptr = new T[n * m]; }
  ~Matrix<T>() { delete[] this->ptr; }

private:
  T *ptr;
};
