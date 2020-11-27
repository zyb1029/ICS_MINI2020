#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define N 10000000

static bool not_prime[N];
static int  primes[N];
static int tot = 0;

int *sieve(int n) {
  assert(n + 1 < N);

  for (int i = 2; i <= n; i++) {
	  if (not_prime[i] == false) primes[tot++] = i;
	  for (int j = 0; j < tot && i * primes[j] <= n; j++) {
		  not_prime[i * primes[j]] = true;
		  if (i % primes[j] == 0) break;
	  }	  
  }
  primes[tot] = 0;
  return primes;
}
