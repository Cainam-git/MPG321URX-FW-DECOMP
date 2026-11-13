/* input_setup_converter_port  (FUN_a0104a34)
 *
 * Set the converter port bits for a channel from its input registers.
 * Name basis: descriptive - step of bring-up state 8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0104a34 @ 0xa0104a34, flags -mcpu=v8 -O3 -g.
 * Source form: input_block_get_reg8c_bit7 is declared with ONE argument (the firmware leaves %o1 unset) and its
 * result is tested as a byte; input_block_set_sync_source takes (unsigned char, unsigned short, unsigned char);
 * the 'if' arm of the final test is the '| 0xf' one (the firmware falls through into it). volatile only on the
 * hardware registers (macro R).
 */
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern unsigned char input_block_get_reg8c_bit7(unsigned char port);
extern unsigned char input_measure_read8(unsigned char blk, unsigned char reg);
extern void input_measure_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_block_set_sync_source(unsigned char port, unsigned short line_rate, unsigned char on);
#define R(a) (*(volatile unsigned int *)(a))

/*
 * Step of bring-up state 8 for a channel's input block. It runs for every channel in that state; the refresh
 * rate plays no part.
 *
 *   port       input block of the channel
 *   f8         not used
 *   line_rate  line rate of the channel (timing field 0, channel record +6); passed on to
 *              input_block_set_sync_source
 *   f4         not used
 *
 * 1. When the low nibble of register 4 is 0 or 1, bit 5 of register 3 is clear and bits 0..1 of register 0x54
 *    read 1, bit 6 of the hardware register 0xCF012804 is set.
 * 2. input_block_set_sync_source(port, line_rate, 1).
 * 3. Bit 7 of the hardware register 0xCF011658 is set.
 * 4. Register 1 of the measure block: its low nibble is set to 0xF when bit 7 of register 0x8C of the block is
 *    set, and cleared otherwise.
 * 5. The hardware register 0xCF01136C is cleared.
 *
 * Called from input_channel_bring_up_task.
 */
void input_setup_converter_port(unsigned char port, int f8, unsigned short line_rate, int f4)
{
    if ((input_capture_read8(port, 4) & 0xf) <= 1) {
        if (!(input_capture_read8(port, 3) & 0x20)) {
            if ((input_capture_read8(port, 0x54) & 3) == 1)
                R(0xcf012804) |= 0x40;
        }
    }
    input_block_set_sync_source(port, line_rate, 1);
    R(0xcf011658) |= 0x80;
    if (input_block_get_reg8c_bit7(port))
        input_measure_write8(port, 1, input_measure_read8(port, 1) | 0xf);
    else
        input_measure_write8(port, 1, input_measure_read8(port, 1) & 0xf0);
    R(0xcf01136c) = 0;
}
