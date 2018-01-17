#include <iostream>
#include <cassert>

int gcd_naive(int num1, int num2) {
  int current_gcd = 1;
  for (int d = 2; d <= num1 && d <= num2; d++) {
    if (num1 % d == 0 && num2 % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int num1, int num2) {
  int remainder;
  while (true) {
    remainder = num1 % num2;
    if (remainder == 0)
      return num2;
    num1 = num2;
    num2 = remainder;
  }
}

int gcd_recursive(int num1, int num2) {
  if (num2 == 0) return num1;
  return gcd_recursive(num2, num1 % num2);
}

void test_solution() {
  int num1;
  int num2;

  for (int i = 0; i < 20; ++i) {
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;
    assert(gcd_naive(num1, num2) == gcd_fast(num1, num2));
  }
}

/*int main() {
  int num1, num2;
  std::cin >> num1 >> num2;
  //std::cout << gcd_naive(a, b) << std::endl;
  test_solution();
  std::cout << gcd_recursive(num1, num2) << std::endl;
  return 0;
}*/
