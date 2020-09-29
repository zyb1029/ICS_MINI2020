#include<stdint.h>

uint64_t quick_mod(uint64_t a, uint64_t b) {
	while(1) {
		if (b > a) return a;
		if ((b << 1) > a || b >= (1ULL<<63) ) {
			break;
		}
		b = b << 1;
	}
	while(b) {
		if (a >= b) a -= b;	
		b = b >> 1;
	}
	return a;
}
uint64_t add(uint64_t a, uint64_t b, uint64_t m, uint64_t p) {
	if (a + b < a) return quick_mod(a + b, m) + p;
	else return quick_mod(a + b, m);
}
uint64_t ksc(uint64_t a, uint64_t b, uint64_t m, uint64_t p) {
	uint64_t ans = 0;
	while(b) {
		if (b & 1) ans = add(ans, a, m, p); 
		a = add(a, a, m, p);
		b = b >> 1;
	}
	return ans;
}
uint64_t multimod(uint64_t a, uint64_t b, uint64_t m) {
  a = quick_mod(a, m);
  p = quick_mod(-1ULL, m);
  p = quick_mod(p + 1, m);
  return ksc(a, b, m, p); // buggy
}
