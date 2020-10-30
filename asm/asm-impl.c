#include "asm.h"

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
			  :"memory"
			  );
  return dest;
}

int asm_setjmp(asm_jmp_buf env) {
  int p = 0;
  asm volatile("mov %[env], %%rcx;\n\t"
               "mov (%%rsp), %%rdx\n\t"
			   "mov %%rdx, (%%rcx);\n\t"
			   "mov %%rbx, 8(%%rcx);\n\t"
			   "mov %%rsp, 16(%%rcx);\n\t"
			   "mov %%rbp, 24(%%rcx);\n\t"
			   "mov %%rsi, 32(%%rcx);\n\t"
			   "mov %%rdi, 40(%%rcx);\n\t"
			   "mov %%eax, 48(%%rcx);\n\t"
			   "xor %%eax, %%eax"
			   :
			   :[env] "m"(env)
			   : "memory"
			   );
              
  return p;
}

void asm_longjmp(asm_jmp_buf env, int val) {
  asm volatile("mov %[env], %%rdx;\n\t"
			   "mov %[val], %%rax;\n\t"
			   "mov (%%rdx), %%rcx;\n\t"
			   "mov 8(%%rdx), %%rbx;\n\t"
			   "mov 16(%%rdx), %%rsp;\n\t"
			   "mov 24(%%rdx), %%rbp;\n\t"
			   "mov 32(%%rdx), %%rsi;\n\t"
			   "mov 40(%%rdx), %%rdi;\n\t"
			   "mov 48(%%rdx), %%rbx;\n\t"
			   "mov %%rcx, (%%rsp);\n\t"
			   "ret"
			   :
			   :[env] "m"(env), [val] "m"(val)
			   );
}
