#include <stdio.h>
#include <stdbool.h>

#define N 10000000
#define M 1000000

static bool not_prime[N];
static int primes[M];

static int tot = 0;
static int k = 0;
int *sieve(int n) {

  for (int i = 2; i <= n; i += 4) {
	  if (not_prime[i] == false) primes[tot++] = i;
	  if (not_prime[i + 1] == false) primes[tot++] = i + 1;
	  k = i * primes[0];
	  for (int j = 0; j < tot && k <= n; j++) {
		  not_prime[k] = true;
		  not_prime[k + primes[j]] = true;
		  if ((i + 1) % primes[j] == 0) break;
		  k = i * primes[j + 1];
	  }	  
	  if (not_prime[i + 2] == false) primes[tot++] = i + 2;
	  k = (i + 2) * primes[0];
	  for (int j = 0; j < tot && k <= n; j++) {
		  not_prime[k] = true;
		  if ((i + 2) % primes[j] == 0) break;
		  k = (i + 2) * primes[j + 1];
	  }
	  if (not_prime[i + 3] == false) primes[tot++] = i + 3;
	  k = (i + 3) * primes[0];
	  for (int j = 0; j < tot && k <= n; j++) {
		  not_prime[k] = true;
		  if ((i + 3) % primes[j] == 0) break;
		  k = (i + 3) * primes[j + 1];
	  }
  }
  if (primes[tot - 1] >= n) tot--;
  if (primes[tot - 1] >= n) tot--;
  if (primes[tot - 1] >= n) tot--;
  primes[tot] = 0;
  return primes;
}
