/* power_test_wake_status_type11  (FUN_CODE_d6e7)
 *
 * Report the status bits checked for wake-source types 11 and 12.
 * Returns: 1 when all three bits are set
 * Name basis: descriptive - standby wake check cases 11/12; regs 0x5407..0x5409
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d6e7 @ 0xd6e7  Options: OPTIMIZE(8,SPEED) (also with REGFILE(R.ORC)).
 * Source form: each of the two bytes is turned into a 0/1 char first, then the two are ANDed. The temp for the
 * bit 6 test gives the firmware's ANL A,#40H / JZ; 'if (x & 0x40)' gives JNB ACC.6.
 */
extern unsigned char xdata DAT_EXTMEM_5407, DAT_EXTMEM_5408, DAT_EXTMEM_5409;

/*
 * Return 1 when bit 6 of XDATA 0x5407 is set and the bytes at 0x5408 and 0x5409 are both non-zero.
 * Used by the standby wake check; what the three bytes hold is not shown.
 */
bit power_test_wake_status_type11(void)
{
    unsigned char nonzero_5409, nonzero_5408;
    unsigned char bit6;

    bit6 = DAT_EXTMEM_5407 & 0x40;
    if (bit6 != 0) {
        nonzero_5409 = DAT_EXTMEM_5409 ? 1 : 0;
        nonzero_5408 = DAT_EXTMEM_5408 ? 1 : 0;
        if (nonzero_5408 & nonzero_5409) return 1;
    }
    return 0;
}
