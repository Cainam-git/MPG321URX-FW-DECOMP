/* power_test_port_wake_flag  (FUN_CODE_d4b0)
 *
 * Report whether input port n has raised its wake flag.
 *   port: port 0..3
 * Returns: 1 when the flag was set
 * Note: Only on chip id 0x20.
 * Name basis: descriptive - standby wake check cases 1..6; write-back of 0x7E7A after a set bit
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d4b0 @ 0xd4b0 (49 B)  Options: OPTIMIZE(7,SPEED) (also level 8).
 * The three XDATA bytes are volatile: 0x7E7A is read twice and written back unchanged.
 * Source form: the 0x10 term is computed first into a local.
 */
#define CHIP_ID_20 0x20  /* chip variant with the per-port wake flags */

extern unsigned char volatile xdata reg_chip_id, reg_port_wake_select, DAT_EXTMEM_7e7a;

/*
 * Return 1 when input port 'port' (0..3) has its wake flag set. Only on chip id 0x20.
 * The port is chosen by writing its select bits to reg_port_wake_select; the flag is bit 0 of the register at
 * XDATA 0x7E7A, which is written back unchanged after a set flag is seen.
 * Part of the standby wake check.
 */
bit power_test_port_wake_flag(unsigned char port)
{
    unsigned char high_bit;

    if (reg_chip_id == CHIP_ID_20) {
        high_bit = 0x10 << port;
        reg_port_wake_select = (1 << port) | high_bit;
        if (DAT_EXTMEM_7e7a & 1) {
            DAT_EXTMEM_7e7a = DAT_EXTMEM_7e7a;
            return 1;
        }
    }
    return 0;
}
