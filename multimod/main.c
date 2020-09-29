#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

uint64_t multimod(uint64_t, uint64_t, uint64_t);

void test(uint64_t a, uint64_t b, uint64_t m) {
  #define U64 "%" PRIu64
  printf(U64 " * " U64 " mod " U64 " = " U64 "\n", a, b, m, multimod(a, b, m));
  if (miltimod(a, b, m) != a * b % m)assert(0);
}

int main() {
  test(4,5,6);
  test(123, 456, 789);
  test(123, 456, -1ULL);
  test(-2ULL, -2ULL, -1ULL); // should be 1
}
