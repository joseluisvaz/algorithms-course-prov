#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int num1, int num2) {

  int remainder;

  while(true) {
    remainder = num1 % num2;
    if (remainder == 0)
      return num2;
    num1 = num2;
    num2 = remainder;
  }
}

int main() {
  int num1, num2;
  std::cin >> num1 >> num2;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(num1, num2) << std::endl;
  return 0;
}
