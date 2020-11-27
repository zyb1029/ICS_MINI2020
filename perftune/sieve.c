#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#define N 10000020

static bool not_prime[N];
static int primes[M];

static int tot = 0;
static int k = 0;

int *sieve(int n) {
  assert(n + 1 < N);
  for (int i = 2; i <= n; i += 6) {
	  not_prime[i] = true;
	  not_prime[i + 2] = true;
  }

  for (int i = 3; i <= n; i += 6)
      not_prime[i] = true;

  if (n >= 2) primes[tot++] = 2;
  if (n >= 3) primes[tot++] = 3;

  for (int i = 5; i <= n; i = i + 4) {
	if (not_prime[i] == false) {
		primes[tot++] = i;
		k = i * 12;
		for (int j = i; j <= n; j += k) {
			not_prime[j] = true;
			not_prime[j + 6] = true;
		}
		for (int j = 5 * i; j <= n; j += k) {
			not_prime[j] = true;
			not_prime[j + 6] = true;
		}
	}
	i = i + 2;
	if (not_prime[i] == false) {
		k = i * 6;
		primes[tot++] = i;
		for (int j = i; j <= n; j += k) {
			not_prime[j] = true;
		}
		for (int j = 5 * i; j <= n; j += k) {
			not_prime[j] = true;
		}
	}
  }
  primes[tot] = 0;
  return primes;
}
