#define io_clear(8bit_ptr, offset, bitno) ((8bit_ptr)[(offset)] & ~(1 << (bitno)))
#define io_set(8bit_ptr, offset, bitno) ((8bit_ptr)[(offset)] | (1 << (bitno)))
