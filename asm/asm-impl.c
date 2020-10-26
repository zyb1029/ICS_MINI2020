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
  int s = 0;
  for (int i = 0; i < 64; i++) {
     asm ("mov 1, %%rax;\n\t"
		"and %0, %%rax;\n\t"
		"add 1, %2;\n\t"
		"add %%eax, %2;"
		:"=m"(x)
	    :"m"(x), "m"(s) 
		:"memory","%eax"
		);
  }
  return s;
}

void *asm_memcpy(void *dest, const void *src, size_t n) {
  return memcpy(dest, src, n);
}

int asm_setjmp(asm_jmp_buf env) {
  return setjmp(env);
}

void asm_longjmp(asm_jmp_buf env, int val) {
  longjmp(env, val);
}
