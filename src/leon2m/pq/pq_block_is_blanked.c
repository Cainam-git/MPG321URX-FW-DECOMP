/* pq_block_is_blanked  (FUN_a0104c34)
 *
 * Return whether a picture block is in a blanking mode.
 * Returns: 0 or 1
 * Name basis: derived - bits 0-1 of register 0x54 are non-zero
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0104c34 @ 0xa0104c34-0xa0104cb0 (31 words), flags -mcpu=v8 -O2 -g (the section default; -O3 -g
 * gives the same bytes).
 * Source form: a plain `for (i = 0; i < 4; i++)` loop with an early `return 1`; `i` is unsigned char; the
 * return type is unsigned char.
 */
extern unsigned char pq_block_read8(unsigned char blk, unsigned char reg);

#define ALL_BLOCKS 8          /* block 8: the "all blocks" code; pq_block_read8 reads block 0 for it */
#define BLK_BLANK_MODE 0x54   /* picture block register: blanking mode */
#define BLANK_MODE_MASK 3     /* bits 0..1 of BLK_BLANK_MODE */

/*
 * Return whether a picture block is in a blanking mode: bits 0..1 of BLK_BLANK_MODE are not both 0.
 * For block 8 (the "all blocks" code) the read is tried up to 4 times, returning 1 at the first nonzero read.
 *
 * Callers: GlobalModeHandler, panel_level_gen_set_target, sys_set_channel_port and sys_set_channel_path_mode.
 */
unsigned char pq_block_is_blanked(unsigned char blk)
{
    unsigned char i;
    if (blk == ALL_BLOCKS) {
        for (i = 0; i < 4; i++)
            if (pq_block_read8(ALL_BLOCKS, BLK_BLANK_MODE) & BLANK_MODE_MASK) return 1;
        return 0;
    }
    if (pq_block_read8(blk, BLK_BLANK_MODE) & BLANK_MODE_MASK) return 1;
    return 0;
}
