/* reg_read_list_word  (FUN_a00a6544)
 *
 * Read a 32-bit register of the first block of a register list.
 *   param_1: list
 *   param_3: offset
 * Returns: register word
 * Name basis: derived - address 0xCE000000 | (block base of list 0xA00B4DA0[id] + offset)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a6544 @ 0xa00a6544-0xa00a657c (56 bytes, 14 words, leaf), flags -mcpu=v8 -Os -g.
 * reg_block_lists is a table of pointers to u16 block bases (read with lduh). Only the read of the hardware word
 * at 0xce000000 is volatile. The second parameter is not used.
 */
extern unsigned short *reg_block_lists[];

/*
 * Read a 32-bit register of the first block of a register list.
 *   list:   list number (low byte used); picks the table reg_block_lists[list]
 *   unused: not used
 *   offset: register offset from the block base
 * The block base is the first 16-bit value of that table. The word read is at 0xCE000000 | (base + offset).
 */
unsigned int reg_read_list_word(unsigned int list, unsigned char unused, unsigned short offset)
{
  return *(volatile unsigned int *)((*reg_block_lists[list & 0xff] + offset) | 0xce000000);
}
