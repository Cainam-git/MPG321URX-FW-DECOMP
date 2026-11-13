/* power_clear_sequence_table  (FUN_CODE_dcbb)
 *
 * Clear the 18-byte table of pending pin sequence steps.
 * Name basis: descriptive - table 0xA6AF stepped by power_apply_cut_list with the pin set/clear routine
 *   gpio_set_port_bits
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dcbb @ 0xdcbb
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Source form: the LARGE model gives the firmware's loop test MOV A,R7 / CJNE A,#12H (SMALL gives CJNE R7,#12H), and
 * 'index != POWER_CUT_TABLE_BYTES' keeps the indexed form ('index < ...' becomes INC DPTR / DJNZ).
 */
#define POWER_CUT_TABLE_BYTES 0x12   /* six 3-byte pin entries */

extern unsigned char xdata power_cut_table[];

/* Set all 18 bytes of power_cut_table to zero. Only caller: sys_main. */
void power_clear_sequence_table(void)
{
    unsigned char index;
    for (index = 0; index != POWER_CUT_TABLE_BYTES; index++) power_cut_table[index] = 0;
}
