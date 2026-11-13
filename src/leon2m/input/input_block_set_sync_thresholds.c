/* input_block_set_sync_thresholds  (FUN_a0120848)
 *
 * Write the two threshold fields of an input block.
 * Name basis: descriptive - registers 0x29 and 0x1B; second value shifted for configuration type 1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0120848 @ 0xa0120848, flags -mcpu=v8 -O3 -g.
 * Source form: an old-style (K&R) definition with blk and a as unsigned char and b as int: the parameters are
 * extended at each use, and the shifted b keeps its bits above bit 7 until each byte argument is formed.
 */
struct input_block_config { unsigned int word_0, word_4, word_8; };
extern struct input_block_config input_block_configs[];
extern void input_measure_write8(unsigned char blk, unsigned char reg, unsigned char val);

#define ALL_INPUT_BLOCKS 8                  /* blk value for "all of the blocks 0..7" */

/*
 * Write registers 0x29 and 0x1B of an input block (or of each of the blocks 0..7).
 *
 *   blk    input block, or 8 for all blocks 0..7
 *   high   goes into bits 5..7 of register 0x1B
 *   low    bits 5..7 go into register 0x29 (bit 2 of it is set when word 4 of the block's configuration
 *          is 1); bits 1..4 go into bits 1..4 of register 0x1B
 *
 * When word 4 of the configuration of block 0 is 1, low is shifted left by 3 first.
 *
 * Called from input_load_block_source_registers. input_blocks_init contains the same code for blk 8 with high = 1 and low = 4.
 */
void input_block_set_sync_thresholds(blk, high, low)
unsigned char blk, high;
int low;
{
    unsigned char i = 0;

    if (input_block_configs[0].word_4 == 1)
        low = (unsigned char)low << 3;
    if (blk == ALL_INPUT_BLOCKS) {
        for (; i <= 7; i++) {
            if (input_block_configs[i].word_4 == 1)
                input_measure_write8(i, 0x29, (low & 0xe0) | 4);
            else
                input_measure_write8(i, 0x29, low & 0xe0);
            input_measure_write8(i, 0x1b, (high << 5) | (low & 0x1e));
        }
    } else {
        if (input_block_configs[blk].word_4 == 1)
            input_measure_write8(blk, 0x29, (low & 0xe0) | 4);
        else
            input_measure_write8(blk, 0x29, low & 0xe0);
        input_measure_write8(blk, 0x1b, (high << 5) | (low & 0x1e));
    }
}
