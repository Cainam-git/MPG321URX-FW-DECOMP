/* dp_clear_reg3d0_value  (FUN_a00ac5a4)
 *
 * Wait for DP receiver status bit 6 of register 0xC1, then clear registers 0x3D0..0x3D2.
 *   port_arg: DP receiver
 * Name basis: descriptive - mailbox command 0x2B; counterpart of dp_read_reg3d0_value
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ac5a4 @ 0xa00ac5a4, flags -mcpu=v8 -Os -g.
 * Source form: the wait loop tests the value returned by the register read; the port is masked inside the loop.
 */
extern int dp_reg_read8(unsigned int, int);
extern void dp_reg_write8(unsigned int, int, int);
extern void dp_reg_update_bits(unsigned int, int, int, int);

/*
 * Wait until bit 6 of receiver register 0xC1 is set (no time limit), then, with bit 7 of register 0xC1 set,
 * write 0 to registers 0x3D2, 0x3D1 and 0x3D0 and clear bit 7 of 0xC1 again. Mailbox command 0x2B calls it
 * (it also clears bit 7 of register 0x223 through dp_clear_reg223_bit7); dp_read_reg3d0_value reads the
 * three registers back.
 *   port_arg: DP receiver
 */
void dp_clear_reg3d0_value(unsigned int port_arg)
{
    unsigned int port;
    unsigned int status;

    do {
        port = port_arg & 0xff;
        status = dp_reg_read8(port, 0xc1);
    } while ((status & 0x40) == 0);

    dp_reg_update_bits(port, 0xc1, 0x80, 1);
    dp_reg_write8(port, 0x3d2, 0);
    dp_reg_write8(port, 0x3d1, 0);
    dp_reg_write8(port, 0x3d0, 0);
    dp_reg_update_bits(port, 0xc1, 0x80, 0);
}
