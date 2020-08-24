#include <iostream>
#include <iomanip>

int main() {
  std::cout << "ValuableJauntySupercollider" << std::endl;

  size_t const L = 1;
  size_t const M = 2;
  size_t const N = 3;
  unsigned a3[L][M][N] = {
    { { 0x000, 0x001, 0x002, }, { 0x010, 0x011, 0x012, }, },
//    { { 0x100, 0x101, 0x102, }, { 0x110, 0x111, 0x112, }, },
//    { { 0x200, 0x201, 0x202, }, { 0x210, 0x211, 0x212, }, },
  };
  size_t a3_l = sizeof(a3);
  size_t a3_e = a3_l / sizeof(unsigned);

  for (size_t l = 0; l < L; ++l) {
    for (size_t m = 0; m < M; ++m) {
      for (size_t n = 0; n < N; ++n) {
        std::cout << std::setw(3)
                  << std::setfill('0')
                  << std::hex
                  << a3[l][m][n]
                  << std::endl;
      }
    }
  }
  std::putchar('\n');

  unsigned * vp = reinterpret_cast<unsigned *>(a3);
  for (size_t n = 0; n < a3_e; ++n) {
    unsigned v = *vp++;
    std::cout << std::setw(3)
              << std::setfill('0')
              << std::hex
              << v
              << ' ';
  }
  std::cout << '\n' << std::endl;

  int ry[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
  size_t ry_e = sizeof(ry) / sizeof(ry[0]);

  for (size_t r_ = 0; r_ < ry_e; ++r_) {
    std::cout << std::setw(2)
              << std::setfill(' ')
              << r_
              << ": "
              << std::setw(8)
              << ry[r_]
              << std::endl;
//    printf("%2zu: %8d\n", r_, ry[r_]);
  }
  std::cout << '\n' << std::endl;

  for (size_t r_ = 0; r_ < ry_e; ++r_) {
    std::cout << std::setw(2)
              << std::setfill(' ')
              << r_
              << ": "
              << std::setw(8)
              << r_[ry]
              << std::endl;
//    printf("%2zu: %8d\n", r_, r_[ry]);
  }
  std::cout << '\n' << std::endl;

  return 0;
}
