#include <iostream>

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

int get_pisano_period(int m) {
  int previous = 0;
  int current = 1;

  for(int i = 1; i < m * m; i++) {
    int next = (previous + current) % m;
    previous = current;
    current = next;

    if (previous == 0 && current == 1) {
      return i;
    }
  }
}

int main() {
    long long n, m;
    std::cout << get_pisano_period(5);
    //std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
