#include "asm.h"
#include <string.h>

int64_t asm_add(int64_t a, int64_t b) {
  int64_t c;
  asm("movq %1, %0;\n\t"
	  "addq %2, %0;\n\t"
	  : "=r"(c)
	  : "r"(a), "r"(b)
	  );
	  return c;
}

int asm_popcnt(uint64_t x) {
  int64_t s = 0;
  asm volatile( 
               "POPCNT %[x], %[s]"
			   :[s] "=r"(s) 
			   :[x] "r"(x)
			   );
  return s;
}

void *asm_memcpy(void *dest, const void *src, size_t n) {
  asm volatile("mov %[src], %[dest];" :[dest]"=m"(dest) :[src] "m"(src) );
  return memcpy(dest, src, n);
}

int asm_setjmp(asm_jmp_buf env) {
  return setjmp(env);
}

void asm_longjmp(asm_jmp_buf env, int val) {
  longjmp(env, val);
}
