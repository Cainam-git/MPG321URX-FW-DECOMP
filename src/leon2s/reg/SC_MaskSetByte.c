/* SC_MaskSetByte  (SC_MaskSetByte)
 *
 * Write masked bits to a register of one or all blocks of a register list.
 *   id: list
 *   n: block, or count = all
 *   off: register
 *   mask
 *   val: bits
 * Name basis: proven - original name printed ('SC_MaskSetByte wrong access %d!!!'); lists 0xA00B4DA0 (HDMI,
 *   DP, TX blocks)
 *
 * Matching notes
 * --------------
 * leon2s SC_MaskSetByte @ 0xa00a6440-0xa00a6544 (-mcpu=v8 -Os -g)
 * Source form: mask and val are unsigned char parameters (callers pass them zero-extended) and both stores are
 * written as (unsigned char) conversions of the whole expression, so GCC narrows the operations and keeps no
 * extension of mask or val.
 */
extern unsigned short *reg_block_lists[];
extern unsigned char reg_block_list_counts[];
extern int dbg_printf(const char *, ...);

#define REG(a) (*(volatile unsigned int *)((a) * 4 | 0xcf000000))

#define WRONG_ACCESS_CODE 99            /* the number printed with the error text */

/*
 * Replace the bits selected by mask in register off of one block, or of every block, of a register list.
 *
 *   id    which list (reg_block_lists[id], reg_block_list_counts[id] entries; each entry is the offset of a block)
 *   n     block number to write; the value equal to the entry count writes every block (entries 0 to n-1)
 *   off   register offset inside the block
 *   mask  bits to clear
 *   val   bits to set after the clear (the new byte is (old & ~mask) | val, low eight bits)
 *
 * The register address is ((entry + off) * 4) | 0xCF000000. An n above the entry count prints
 * "SC_MaskSetByte wrong access 99!!!" and writes nothing.
 */
void SC_MaskSetByte(unsigned char id, unsigned char n, unsigned short off, unsigned char mask, unsigned char val)
{
    unsigned char i;
    volatile unsigned int *r;

    if (n == reg_block_list_counts[id]) {
        for (i = 0; i < n; i++)
            REG(reg_block_lists[id][i] + off) = (unsigned char)(REG(reg_block_lists[id][i] + off) & ~mask | val);
    } else if (n < reg_block_list_counts[id]) {
        r = &REG(reg_block_lists[id][n] + off);
        *r = (unsigned char)(val | (*r & ~mask));
    } else {
        dbg_printf("SC_MaskSetByte wrong access %d!!!\r\n", WRONG_ACCESS_CODE);
    }
}
