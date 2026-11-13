/* dp_set_reg40_bit7  (FUN_a00ae378)
 *
 * Set bit 7 of register 0x40 of a port.
 * Name basis: descriptive - read, OR 0x80, write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ae378 @ 0xa00ae378 (-mcpu=v8 -Os -g)
 * Source form: the value is written as (value | 0xffffff80) & 0xff; the unused parameters 4 to 6 are passed on to
 * the write routine, whose declaration has no parameter list.
 */
extern int dp_reg_read8();
extern int dp_reg_write8();

/*
 * Read register 0x40 of a DP receiver and write it back with bit 7 set.
 *   port: DP receiver (0 or 1)
 * Called from dp_run_link_state. The other parameters carry no value of their own; they are only handed on to
 * dp_reg_write8.
 */
void dp_set_reg40_bit7(unsigned int port, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                       unsigned int arg5, unsigned int arg6)
{
    unsigned int value;

    port = port & 0xff;
    value = dp_reg_read8(port, 0x40);
    dp_reg_write8(port, 0x40, (value | 0xffffff80) & 0xff, arg4, arg5, arg6);
    return;
}
