/* pq_block_update_bits  (FUN_a00f232c)
 *
 * Set or clear bits of a register of one picture block, or of all eight.
 * Name basis: proven - block base addresses from the ROM table at 0x19A2EC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f232c @ 0xa00f232c, flags -mcpu=v8 -O3 -g.
 */
/* Register access: base 0xcf000000, offset shifted left by 2. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short pq_block_reg_bases[8];

#define ALL_BLOCKS 8          /* block_index value that means all eight blocks */
#define LAST_BLOCK_INDEX 7    /* highest block index */
#define SET_BITS 1            /* set_flag value that ORs the mask in */

/*
 * Set or clear bits (bit_mask) in a register (reg_offset) of one picture block, or of all eight.
 * block_index == ALL_BLOCKS (8) applies to blocks 0..7; block_index > 7 does nothing.
 * set_flag == SET_BITS (1) ORs bit_mask in, otherwise clears the bits.
 * The low byte of the register is written back.
 * Register bases are in pq_block_reg_bases.
 */
void pq_block_update_bits(unsigned char block_index, unsigned char reg_offset, unsigned char bit_mask, unsigned char set_flag)
{
    unsigned char i; unsigned char reg_value;
    if (block_index == ALL_BLOCKS) {
        for (i = 0; i <= LAST_BLOCK_INDEX; i++) {
            reg_value = R(pq_block_reg_bases[i] + reg_offset);
            if (set_flag == SET_BITS) reg_value |= bit_mask; else reg_value &= ~bit_mask;
            R(pq_block_reg_bases[i] + reg_offset) = (unsigned char)reg_value;
        }
    } else if (block_index <= LAST_BLOCK_INDEX) {
        reg_value = R(pq_block_reg_bases[block_index] + reg_offset);
        if (set_flag == SET_BITS) reg_value |= bit_mask; else reg_value &= ~bit_mask;
        R(pq_block_reg_bases[block_index] + reg_offset) = (unsigned char)reg_value;
    }
}
