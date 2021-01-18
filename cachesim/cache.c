#include "common.h"
#include <inttypes.h>
#include <assert.h>

void mem_read(uintptr_t block_num, uint8_t *buf);
void mem_write(uintptr_t block_num, const uint8_t *buf);

static uint64_t cycle_cnt = 0;

static uint8_t cache[1 << 20][64];
static uintptr_t tags[1 << 20];
static bool valid[1 << 20];


void cycle_increase(int n) { cycle_cnt += n; }

// TODO: implement the following functions

static int _delta, _group;

int cal_delta(uintptr_t addr) {
	return addr & ((1 << _delta) - 1);	
}

int cal_group(uintptr_t addr) {
	return (addr & ((1 << (_delta + _group)) - 1)) >> _delta;
}

int cal_tag(uintptr_t addr) {
	return addr >> (_delta + _group);

}

int cal_block(uintptr_t addr) {
	return addr >> BLOCK_WIDTH;
} 
int T;
uint32_t cache_read(uintptr_t addr) {
	T++;
	addr = (addr & ~0x3);
    printf("%d %lx ", T, addr);
	int delta = cal_delta(addr);
	int group = cal_group(addr);
	int tag = cal_tag(addr);
	group <<= 2;
	bool flag = false, p;
	for (int i = group; i < group + 4; i++)
		if (tags[i] == tag && valid[i]) {
			flag = true;
			p = i;
		}
	if (flag == false) {
		p = group + rand() % 4;
		mem_read(cal_block(addr), cache[p]);
		valid[p] = true;
		tags[p] = tag;
	}
	uint32_t ans = 0;
	for (int i = delta; i < delta + 4; i++) {
		ans = ans + ((uint32_t)cache[p][i] << (8 * (i - delta)));
		if (i >=64)assert(0);	
	}
	printf("%x\n", ans);
	return ans;
}

void cache_write(uintptr_t addr, uint32_t data, uint32_t wmask) {
	T++;
	if (addr == 0x161a3ec)assert(0);
	addr = (addr & ~0x3);
	printf("%d %lx %x %x\n", T, addr, data, wmask);
	int delta = cal_delta(addr);
	int group = cal_group(addr);
	int tag = cal_tag(addr);
	group <<= 2;
	bool flag = false, p;
	for (int i = group; i < group + 4; i++)
		if (tags[i] == tag && valid[i]) {
			flag = true;
			p = i;
		}
	if (flag == false) {
		p = group + rand() % 4;
		mem_read(cal_block(addr), cache[p]);
		valid[p] = true;
		tags[p] = tag;
	}
	/*
	int up = 0;
	switch(wmask) {
		case 0xff: up = 1; break;	
		case 0xffff: up = 2; break;
		case 0xffffffff: up = 4; break;
		default: printf("%8x\n", wmask), assert(0);
	}
*/
	for (int i = delta; i < delta + 4; i++) {
		if ((wmask & ((0xff) << (8 * (i - delta)))) != 0)
			cache[p][i] = (data & (0xff << (8 * (i - delta)))) >> 
													(8 * (i - delta));
		if (i >=64)assert(0);	
	}
}


int t = 0;
void init_cache(int total_size_width, int associativity_width) {
	t++;
	assert(t == 1);
	_delta = 6;
	_group = total_size_width - associativity_width - _delta;
	assert(total_size_width - _delta <= 20);
}

void display_statistic(void) {
}
