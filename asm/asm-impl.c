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
  asm volatile("mov %[src], %%rsi;\n\t"
			   "mov %[dest], %%rdi;\n\t"
			   "mov %[n], %%rcx;\n\t"
			   "rep movsb"
			  :
			  :[src] "r"(src), [dest] "r"(dest), [n] "r"(n)
			  );
  return dest;
}

int asm_setjmp(asm_jmp_buf env) {
  asm volatile("mov %[env], %%rcx;\n\t"
               "mov (%%esp), %%edx\n\t"
			   :[env] "m"(env)
			   );
              
  return 0;
}

void asm_longjmp(asm_jmp_buf env, int val) {
 // longjmp(env, val);
}
