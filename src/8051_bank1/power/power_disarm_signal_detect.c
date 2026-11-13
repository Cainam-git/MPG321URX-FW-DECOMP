/* power_disarm_signal_detect  (FUN_CODE_de71)
 *
 * Write 0x88 to the two registers 0xD507 / 0xD508 after a failed signal check.
 * Name basis: descriptive - regs 0xD507/0xD508 = 0x88 on the failure path of power_check_sync_input_alt;
 *   power_arm_signal_detect writes 0x37 to both before the check
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de71 @ 0xde71  OPTIMIZE(7,SPEED)
 * Two plain assignments: two MOVX stores, each with its own DPTR load.
 */
#define DETECT_LEVEL_AFTER_FAIL 0x88    /* power_arm_signal_detect writes 0x37 before the check */

extern xdata unsigned char DAT_EXTMEM_d507;
extern xdata unsigned char DAT_EXTMEM_d508;

/*
 * Write 0x88 to the two registers at XDATA 0xD507 and 0xD508. power_check_sync_input_alt calls it when its
 * signal check fails; before that check, power_arm_signal_detect has set both to 0x37. Nothing else in the
 * program writes these two registers.
 */
void power_disarm_signal_detect(void)
{
    DAT_EXTMEM_d507 = DETECT_LEVEL_AFTER_FAIL;
    DAT_EXTMEM_d508 = DETECT_LEVEL_AFTER_FAIL;
}
