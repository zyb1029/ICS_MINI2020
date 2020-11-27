#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define N 10000000

static bool not_prime[N];
static int primes[N];

static int tot = 0;
static int k = 0;
static int p = 0;

int *sieve(int n) {
  assert(n + 1 < N);

  for (int i = 2; i <= n; i += 2)
	  not_prime[i] = true;
	   
 // for (int i = 3; i <= n; i += 6)
//	  not_prime[i] = true;

  if (n >= 2) primes[tot++] = 2;
 // if (n >= 3) primes[tot++] = 3;

  for (int i = 3; i <= n; i = i + 2) {
	if (not_prime[i] == false) {
		primes[tot++] = i;
		for (int j = i; j <= n; j += i + i) {
			not_prime[j] = true;
		}
	}
	i = i + 4;
	if (not_prime[i] == false) {
		primes[tot++] = i;
		for (int j = i; j <= n; j += i + i) {
			not_prime[j] = true;
		}
	}
  }
  primes[tot] = 0;
  return primes;
}
