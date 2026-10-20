/* 8051_bank1 FUN_CODE_db7d @ 0xdb7d  MATCH (OPTIMIZE(7,SPEED))
 * Returns 1 (in C) when param_1 == 0 and bit 6 of xdata 0xDCB0 is set, or when param_1 != 0 and bit 7 of
 * 0xDCB0 is set; otherwise returns 0. Assigning the masked byte to the temporary tmp before the test makes Keil
 * emit ANL A,#mask followed by JZ, as in the firmware, instead of a JNB ACC.x bit test.
 */
extern unsigned char xdata DAT_EXTMEM_dcb0; // 0xdcb0

// Function at 0xdb7d
bit FUN_CODE_db7d(char param_1) // returns bit in C
{
    unsigned char tmp;
    if (param_1 == 0) {
        tmp = DAT_EXTMEM_dcb0 & 0x40;
        if (tmp != 0) {
            return 1;
        }
    } else {
        tmp = DAT_EXTMEM_dcb0 & 0x80;
        if (tmp != 0) {
            return 1;
        }
    }
    return 0;
}
