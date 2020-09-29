#include<stdint.h>

uint64_t ksc(uint64_t a, uint64_t b, uint64_t m) {
	uint64_t ans = 0;
	while(b) {
		if(b & 1) ans = ans + a;
		if (ans > m) ans = ans - m;
		a = a + a;
		if (a > m) a = a - m;
		b = b >> 1;
	}
	return ans;
}
uint64_t multimod(uint64_t a, uint64_t b, uint64_t m) {
  return ksc(a, b, m); // buggy
}
