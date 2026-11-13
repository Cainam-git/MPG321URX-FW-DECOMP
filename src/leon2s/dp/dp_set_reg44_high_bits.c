/* dp_set_reg44_high_bits  (FUN_a00ae254)
 *
 * Write bits 4..7 of a value to register 0x44 and set bit 4 of register 0x40 when any of them is set.
 * Name basis: descriptive - depends on bit 0 of register 0x480
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ae254 @ 0xa00ae254, flags -mcpu=v8 -Os -g.
 * Source form: the bit-7 argument is (high & 0x80) != 0, which keeps the "and -16" in the parameter register and a
 * separate zero-extension for the later bit reads; the last write is an if/else with constant arguments.
 */
extern unsigned char dp_get_reg480_bit0(unsigned char);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);

/*
 * Write bits 4..7 of "value" into bits 4..7 of receiver register 0x44, then set bit 4 of register 0x40 to 1 when
 * any of those four bits is set, else 0. When bit 0 of register 0x480 is 1, bits 4..6 of register 0x44 are
 * cleared instead of taking the value; bit 7 is written in both cases.
 * dp_run_link_state calls it with 0xB0; ipc_dispatch_command also calls it.
 *   port: DP receiver
 *   value: only bits 4..7 are used
 */
void dp_set_reg44_high_bits(unsigned char port, unsigned int value)
{
    unsigned char high;

    high = value & 0xf0;
    dp_reg_update_bits(port, 0x44, 0x80, (high & 0x80) != 0);
    if (dp_get_reg480_bit0(port) == 1) {
        dp_reg_update_bits(port, 0x44, 0x40, 0);
        dp_reg_update_bits(port, 0x44, 0x20, 0);
        dp_reg_update_bits(port, 0x44, 0x10, 0);
    } else {
        dp_reg_update_bits(port, 0x44, 0x40, (high >> 6) & 1);
        dp_reg_update_bits(port, 0x44, 0x20, (high >> 5) & 1);
        dp_reg_update_bits(port, 0x44, 0x10, (high >> 4) & 1);
    }
    if (high)
        dp_reg_update_bits(port, 0x40, 0x10, 1);
    else
        dp_reg_update_bits(port, 0x40, 0x10, 0);
}
