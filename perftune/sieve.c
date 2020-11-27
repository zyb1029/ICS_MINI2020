#include <stdbool.h>
#include <stdio.h>

#define N 10000000
#define M 1000000

static bool not_prime[N];
static int primes[M];

static int tot = 0;
static int k = 0;
static int p = 0;

int *sieve(int n) {

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
		k = (i << 2) + (i << 1);
		for (int j = i; j <= n; j += k) {
			not_prime[j] = true;
		}
		for (int j = 5 * i; j <= n; j += k) {
			not_prime[j] = true;
		}
	}
	i = i + 2;
	if (not_prime[i] == false) {
		k = (i << 2) + (i << 1);
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
