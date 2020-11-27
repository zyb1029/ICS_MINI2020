#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define N 10000000

static bool not_prime[N];
static int primes[N];

static int tot = 0;
int *sieve(int n) {
  assert(n + 1 < N);

  for (int i = 2; i <= n; i += 2)
	  not_prime[i] = true;
	   
  for (int i = 3; i <= n; i += 3)
	  not_prime[i] = true;

  if (n >= 2) primes[tot++] = 2;
  if (n >= 3) primes[tot++] = 3;

  for (int i = 5; i <= n; i++) {
	if (not_prime[i] == false) {
		primes[tot++] = i;
		for (int j = i; j <= n; j += 6 * i) {
			not_prime[j] = true;
			not_prime[j + (i << 2)] = true;
		}
	}
  }
  primes[tot] = 0;
  return primes;
}
