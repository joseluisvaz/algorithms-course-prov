#include <iostream>
#include <cassert>
//#include "../gcd/gcd.h"

long long lcm_naive(int num1, int num2) {
  for (long l = 1; l <= (long long) num1 * num2; ++l)
    if (l % num1 == 0 && l % num2 == 0)
      return l;

  return (long long) num1 * num2;
}

int gcd_recursive(int num1, int num2) {
  if (num2 == 0) return num1;
  return gcd_recursive(num2, num1 % num2);
}

long long lcm_fast(int num1, int num2) {
  return ((long long) num1 * num2) / gcd_recursive(num1, num2);
}

void test_solution_lcm() {
  int num1;
  int num2;

  for (int i = 0; i < 20; ++i) {
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;
    assert(lcm_naive(num1, num2) == lcm_fast(num1, num2));
  }
}

int main() {
  int num1, num2;
  //test_solution_lcm();
  std::cin >> num1 >> num2;
  std::cout << lcm_fast(num1, num2) << std::endl;
  return 0;
}
