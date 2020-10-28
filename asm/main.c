#include "asm.h"
#include <assert.h>
#include <stdio.h>

int main() {
  asm_jmp_buf buf;
  int r = asm_setjmp(buf);
  if (r == 0) {
    assert(asm_add(1234, 5678) == 6912);
    assert(asm_popcnt(0x0123456789abcdefULL) == 32);
    // TODO: add more tests here.
	int a[100], n = 15, b[100];
	for (int i = 0; i < n; i++) a[i] = rand();
	asm_memcpy(b, a, n * sizeof(int));
	for (int i = 0; i < n; i++) assert(a[i] == b[i]);
    asm_longjmp(buf, 123);
  } else {
    assert(r == 123);
    printf("PASSED.\n");
  }
}
