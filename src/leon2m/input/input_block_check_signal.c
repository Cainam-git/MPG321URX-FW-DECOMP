/* input_block_check_signal  (FUN_a01215e8)
 *
 * Run the register checks that decide whether the signal of a block can be matched.
 * Returns: 0 or 1
 * Name basis: descriptive - registers 4, 3, 0x56 and 0x8F with a delay; used by the mode match
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01215e8 @ 0xa01215e8, flags -mcpu=v8 -O3 -g.
 * Source form: 'flag' is an unsigned int holding 0 or 1 and is tested as 'if (flag & 1)', which gives the
 * firmware's word compare 'cmp %g1,0'; with an unsigned char flag the compiler emits 'btst 0xff' (one word
 * more) and a plain 'if (flag)' on a wider flag lets jump threading skip the test. The '& 1' changes nothing
 * on a 0/1 value. The interlace test is written out inline, as in input_block_is_interlaced.
 */
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern unsigned char input_measure_read8(unsigned char blk, unsigned char reg);
extern unsigned char reg_blockset6_read8(unsigned char instance, unsigned char reg);
extern void input_capture_update_bits(unsigned char, unsigned char, unsigned char, unsigned char);
extern void timer_sleep_ticks(unsigned int);

/*
 * Prepare the capture registers of an input block before the signal is matched against the mode table:
 *
 * 1. Clear bit 0 of register 0x56.
 * 2. When bits 0..1 of register 4 are not both set and bit 6 of register 0 is set, clear bit 6 of register 0
 *    and call timer_sleep_ticks(0x78).
 * 3. Work out the same flag as input_block_is_interlaced (0 when bit 5 of register 3 is set and bits 0..1 of
 *    register 4 are not both set) and copy it into bit 2 of register 0.
 *
 *   port  input block
 *
 * Does not depend on the refresh rate. Called from input_match_port_mode.
 */
void input_block_check_signal(unsigned char port)
{
    unsigned int masked;
    unsigned int flag;

    input_capture_update_bits(port, 0x56, 1, 0);
    if ((input_capture_read8(port, 4) & 3) != 3) {
        if ((input_capture_read8(port, 0) & 0x40) != 0) {
            input_capture_update_bits(port, 0, 0x40, 0);
            timer_sleep_ticks(0x78);
        }
    }
    if ((input_capture_read8(port, 4) & 3) == 3) {
        masked = reg_blockset6_read8(input_capture_read8(port, 3) & 1, 0x8f) & 4;
        flag = masked != 0;
    } else if (input_capture_read8(port, 3) & 0x20) {
        flag = 0;
    } else {
        masked = input_measure_read8(port, 0x11) & 4;
        flag = masked != 0;
    }
    if (flag & 1)
        input_capture_update_bits(port, 0, 4, 1);
    else
        input_capture_update_bits(port, 0, 4, 0);
}
