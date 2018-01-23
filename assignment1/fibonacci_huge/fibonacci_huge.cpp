#include <iostream>
#include <cassert>
#include <random>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int get_pisano_period(int divisor) {
  int previous = 0;
  int current = 1;

  for(int i = 1; i < divisor * divisor; i++) {
    int next = (previous + current) % divisor;
    previous = current;
    current = next;

    if (previous == 0 && current == 1) {
      return i;
    }
  }
}

long long get_fibonacci_huge_fast(long long number, int divisor) {
  if (number <= 1) {
    return number;
  }

  long long remainder = number % get_pisano_period(divisor);

  long long previous = 0;
  long long current = 1;
  long long res =  remainder;

  for (int i = 2; i < remainder + 1; ++i) {
    res = (previous + current) % divisor;
    previous = current;
    current = res;
  }

  return res % divisor;
}

void test_solution() {

  static std::default_random_engine engine{};
  static std::uniform_int_distribution<int> dist{1,100};

  for(int i = 0; i < 10000; ++i){
    int test_number = dist(engine);
    int test_divisor = dist(engine);
    long long number_a = get_fibonacci_huge_naive(test_number, test_divisor);
    long long number_b = get_fibonacci_huge_fast(test_number, test_divisor);
    if (number_a != number_b) {
      std::cout << "test_number: " << test_number;
      std::cout << " test_divisor: " << test_divisor;
      std::cout << " response_naive: " << number_a;
      std::cout << " response_fast: " << number_b << std::endl;
    }
    assert(number_a == number_b);
  }
}

int main() {
    long long number;
    int divisor;
    std::cin >> number >> divisor;
    // test_solution();
    std::cout << get_fibonacci_huge_fast(number, divisor);
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
