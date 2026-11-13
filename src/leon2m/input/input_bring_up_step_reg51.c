/* input_bring_up_step_reg51  (FUN_a00f0380)
 *
 * Step register 0x51 of a picture block up or down by flag bits.
 * Name basis: descriptive - stores the flags; special cases for counts 0 and 300
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f0380 @ 0xa00f0380, flags -mcpu=v8 -O3 -g.
 * Source form: the two halves are separate if blocks that can both run in one call, exactly as written; the result
 * is returned as 'moved_up & 1'.
 */

extern unsigned char input_bring_up_reg51_flags;
extern unsigned char input_bring_up_reg51_value;
extern unsigned char pq_block_read8(unsigned char blk, unsigned char reg);
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);

/*
 * One step on register 0x51 of the picture block blk: write it one higher or one lower than it reads now.
 *
 *   blk    picture block
 *   count  retry count of the caller; 0 starts a series, 300 ends it
 *   flags  bit 0 = step up, bit 1 = step down; kept in input_bring_up_reg51_flags for the next call
 *
 * Count 0: the value read is kept in input_bring_up_reg51_value, then both halves below can step it.
 * Count 300: the kept value is written back.
 * Otherwise the flags of the previous call choose what runs. With bit 1 of the previous flags set, the new
 * flags step the register up (bit 0 set; returns 1) or down (not below 0). With bit 0 of the previous
 * flags set, the register goes down (bit 1 of the new flags; returns 1) or up. The two halves can both run
 * in one call.
 * Returns 1 when one of the steps named "returns 1" above was made.
 * Called by input_bring_up_lock_port, with register 0x8e of the port as the flags.
 */
unsigned char input_bring_up_step_reg51(unsigned char blk, unsigned short count, unsigned char flags)
{
    unsigned char value = pq_block_read8(blk, 0x51);
    unsigned char moved = 0;

    if ((input_bring_up_reg51_flags & 2) || count == 0) {
        if (count == 0) {
            input_bring_up_reg51_value = value;
            if ((flags & 2) && value != 0)
                pq_block_write8(blk, 0x51, value - 1);
        } else if (count == 300) {
            pq_block_write8(blk, 0x51, input_bring_up_reg51_value);
        } else if (flags & 1) {
            pq_block_write8(blk, 0x51, value + 1);
            moved = 1;
        } else if (value != 0) {
            pq_block_write8(blk, 0x51, value - 1);
        }
    }
    if ((input_bring_up_reg51_flags & 1) || count == 0) {
        if (count == 0) {
            input_bring_up_reg51_value = value;
            if (flags & 1)
                pq_block_write8(blk, 0x51, value + 1);
        } else if (count == 300) {
            pq_block_write8(blk, 0x51, input_bring_up_reg51_value);
        } else if (!(flags & 2)) {
            pq_block_write8(blk, 0x51, value + 1);
        } else {
            pq_block_write8(blk, 0x51, value - 1);
            moved = 1;
        }
    }
    input_bring_up_reg51_flags = flags;
    return moved & 1;
}
