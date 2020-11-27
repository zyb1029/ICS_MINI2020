#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define N 10000000
#define M 1000000

static bool not_prime[N];
static int primes[M];

static int tot = 0;
static int k = 0;
int *sieve(int n) {
  assert(n + 1 < N);

  for (int i = 2; i <= n; i ++) {
	  if (not_prime[i] == false) primes[tot++] = i;
	  k = i * primes[0];
	  for (int j = 0; j < tot && k <= n; j++) {
		  not_prime[k] = true;
		  if (i % primes[j] == 0) break;
		  k = i * primes[j + 1];
	  }	  
	  if (not_prime[i + 1] == false) primes[tot++] = i + 1;
	  k = (i + 1) * primes[0];
	  for (int j = 0; j < tot && k <= n; j++) {
		  not_prime[k] = true;
		  if ((i + 1) % primes[j] == 0) break;
		  k = (i + 1) * primes[j + 1];
	  }
  }
  primes[tot] = 0;
  return primes;
}
