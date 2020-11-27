#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define N 10000000

static bool not_prime[N];
static int primes[N];

static int tot = 0;
static int k = 0;
int *sieve(int n) {
  assert(n + 1 < N);
   
  for (int i = 2; i <= n; i++) {
	if (not_prime[i] == false) {
		primes[tot++] = i;
		if (i > 3) k = i << 1;
		else k = i;
		for (int j = i; j <= n; j += k)
			not_prime[j] = true;
	}
  }
  primes[tot] = 0;
  return primes;
}
