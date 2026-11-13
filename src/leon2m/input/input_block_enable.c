/* input_block_enable  (FUN_a0120998)
 *
 * Switch an input block on or off.
 * Name basis: derived - register 0x88 and two control bits; used when a channel's port is switched
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0120998 @ 0xa0120998, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the callees are declared unprototyped (void, no parameter list) and the routine has six
 * parameters; the last two are passed on to the third call (extra5, extra6), as in the firmware, which hands
 * its incoming %o4/%o5 on.
 */
extern void input_measure_update_bits();
extern void pq_block_write8();

/*
 * Write the block's control values for "on" (enable non-zero) or "off" (enable zero):
 *
 *               picture block reg 0x88   measure reg 0x1C bit 5   measure reg 1 bit 1
 *   on          0x11                     cleared                  set
 *   off         0x10                     set                      cleared
 *
 *   blk     input block
 *   enable  non-zero: on; zero: off
 *
 * Called from sys_enable_channel_port.
 */
void input_block_enable(unsigned char blk, unsigned char enable, unsigned int extra3, unsigned int extra4,
                        unsigned int extra5, unsigned int extra6)
{
    if (enable != 0) {
        pq_block_write8(blk, 0x88, 0x11);
        input_measure_update_bits(blk, 0x1c, 0x20, 0);
        input_measure_update_bits(blk, 1, 2, 1, extra5, extra6);
        return;
    }
    pq_block_write8(blk, 0x88, 0x10);
    input_measure_update_bits(blk, 0x1c, 0x20, 1);
    input_measure_update_bits(blk, 1, 2, 0, extra5, extra6);
}
