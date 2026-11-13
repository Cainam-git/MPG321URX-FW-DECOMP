/* dp_read_reg3d0_value  (FUN_a00ac620)
 *
 * Return the 24-bit value of DP receiver registers 0x3D0..0x3D2.
 *   port: DP receiver
 * Returns: 24-bit value
 * Name basis: descriptive - mailbox command 0x7C reply
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ac620 @ 0xa00ac620, flags -mcpu=v8 -Os -g.
 * Source form: the three bytes are joined with + (as the firmware adds them), not |.
 */
extern unsigned int dp_reg_read8(unsigned char, unsigned short);

/*
 * Return the 24-bit value held in receiver registers 0x3D0 (low byte), 0x3D1 and 0x3D2 (high byte).
 * Mailbox command 0x7C replies with it; dp_clear_reg3d0_value clears the three registers.
 *   port: DP receiver
 */
unsigned int dp_read_reg3d0_value(unsigned char port)
{
    unsigned int value;

    value = (dp_reg_read8(port, 0x3d2) & 0xff) << 16;
    value += (dp_reg_read8(port, 0x3d1) & 0xff) << 8;
    return value + (dp_reg_read8(port, 0x3d0) & 0xff);
}
