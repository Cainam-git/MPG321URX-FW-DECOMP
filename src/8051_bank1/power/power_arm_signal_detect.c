/* power_arm_signal_detect  (FUN_CODE_de66)
 *
 * Set the two signal detector levels used for the standby signal check.
 * Name basis: descriptive - regs 0xD507/0xD508 = 0x37 before the check in power_check_sync_input_alt
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de66 @ 0xde66  OPTIMIZE(7,SPEED)
 * The two plain assignments compile to two MOVX stores, each with its own immediate DPTR load, as in the firmware.
 */
extern xdata unsigned char DAT_EXTMEM_d507;
extern xdata unsigned char DAT_EXTMEM_d508;

/* Write 0x37 to the registers at 0xD507 and 0xD508. */
void power_arm_signal_detect(void) {
    DAT_EXTMEM_d507 = 0x37;
    DAT_EXTMEM_d508 = 0x37;
}
