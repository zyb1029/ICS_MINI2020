#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define N 10000000

static bool not_prime[N];
static int  primes[N];
static int tot = 0;
static int k = 0;
int *sieve(int n) {
  assert(n + 1 < N);

  for (int i = 2; i <= n; i += 2) {
	  if (not_prime[i] == false) primes[tot++] = i;
	  if (not_prime[i + 1] == false) primes[tot++] = i + 1;
	  k = i * primes[0];
	  for (int j = 0; j < tot && k <= n; j += 2) {
		  not_prime[k] = true;
		  not_prime[k + primes[j]] = true;
		  k = i * primes[j + 1];
		  not_prime[k] = true;
		  not_prime[k + primes[j]] = true;
		  if ((i + 1) % primes[j] == 0) break;
		  k = i * primes[j + 2];
	  }	  
  }
  if (primes[tot - 1] > n)tot--;
  primes[tot] = 0;
  return primes;
}
