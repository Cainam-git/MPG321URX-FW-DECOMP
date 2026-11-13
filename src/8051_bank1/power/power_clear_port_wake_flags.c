/* power_clear_port_wake_flags  (FUN_CODE_d351)
 *
 * Clear the wake flags of all four input ports before standby.
 * Note: Only on chip id 0x20.
 * Name basis: descriptive - same register writes as power_test_port_wake_flag for ports 0..3; part of
 *   CMD_SYS_POWERSAVING
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d351 @ 0xd351..0xd385 (52 B)  OPTIMIZE(8,SPEED), small function.
 * The 'small' keyword is part of the build. The read and write-back of the flag register is one statement
 * (volatile byte assigned to itself).
 */
#define CHIP_ID_20 0x20  /* chip variant with the per-port wake flags */

extern unsigned char volatile xdata reg_chip_id, reg_port_wake_select, DAT_EXTMEM_7e7a;

/*
 * Clear the wake flags of the four input ports (ports 0..3). Only done on chip id 0x20.
 * For each port the select register gets the port's low bit and the bit 4 places higher, then the
 * flag register 0x7E7A is read and written back unchanged. The caller is ipc_run_command.
 */
void power_clear_port_wake_flags(void) small
{
    unsigned char port;

    if (reg_chip_id == CHIP_ID_20) {
        port = 0;
        do {
            reg_port_wake_select = (1 << port) | (0x10 << port);
            DAT_EXTMEM_7e7a = DAT_EXTMEM_7e7a;
        } while (++port != 4);
    }
}
