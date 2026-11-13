/* input_block_is_interlaced  (FUN_a01211d4)
 *
 * Return the interlace flag of the signal on an input block.
 * Returns: 0 or 1
 * Name basis: descriptive - flag taken from one of three registers depending on the block's source
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01211d4 @ 0xa01211d4, flags -mcpu=v8 -O2 -g.
 * Source form: the '& 4' is in each arm (both firmware arms end in 'and %o0,4,%o0' before the shared compare);
 * a '(flag & 4) != 0' after the join becomes srl/and. The callees return unsigned char.
 */
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern unsigned char input_measure_read8(unsigned char blk, unsigned char reg);
extern unsigned char reg_blockset6_read8(unsigned char instance, unsigned char reg);

/*
 * Return bit 2 of a status register of the block. Which register depends on bits 0..1 of capture register 4:
 *
 *   both set          bit 2 of register 0x8F of block 0 or 1 of register block set 6 (bit 0 of capture
 *                     register 3 picks the block)
 *   otherwise         0 when bit 5 of capture register 3 is set; else bit 2 of measure register 0x11
 *
 * The same test is repeated inline in input_block_check_signal.
 *
 *   blk  input block
 *
 * Called from input_channel_bring_up_task.
 */
unsigned int input_block_is_interlaced(unsigned char blk)
{
    unsigned char reg4 = input_capture_read8(blk, 4);
    unsigned int flag;

    if ((reg4 & 3) == 3) {
        unsigned char reg3 = input_capture_read8(blk, 3);
        flag = reg_blockset6_read8(reg3 & 1, 0x8f) & 4;
    } else {
        unsigned char reg3 = input_capture_read8(blk, 3);
        if (reg3 & 0x20)
            return 0;
        flag = input_measure_read8(blk, 0x11) & 4;
    }
    return flag != 0;
}
