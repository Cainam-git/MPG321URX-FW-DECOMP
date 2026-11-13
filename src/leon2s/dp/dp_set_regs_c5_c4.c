/* dp_set_regs_c5_c4  (FUN_a00aea3c)
 *
 * Write registers 0xC5 and 0xC4 of a port.
 * Name basis: descriptive - set by a command from the main processor
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aea3c @ 0xa00aea3c (-mcpu=v8 -Os -g)
 * Source form: parameters 4 to 6 are handed on to the second write, whose declaration has no parameter list.
 */
extern int dp_reg_write8();

/*
 * Write value_c5 to register 0xC5 and value_c4 to register 0xC4 of a DP receiver. Called for mailbox command
 * 0x27, which carries the three bytes.
 *   port: DP receiver (0 or 1)
 * The last three parameters carry no value of their own; they are only handed on to dp_reg_write8.
 */
void dp_set_regs_c5_c4(unsigned char port, unsigned char value_c5, unsigned char value_c4, unsigned int arg4,
                       unsigned int arg5, unsigned int arg6)
{
    dp_reg_write8(port, 0xc5, value_c5);
    dp_reg_write8(port, 0xc4, value_c4, arg4, arg5, arg6);
    return;
}
