/* 8051_bank1 FUN_CODE_c4ee @ 0xc4ee (86 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Returns 0 unless FUN_CODE_78ba() returns 1. Then the lowest set bit of the request byte XDATA 0xA758 picks the
 * result (bit 0 -> 1, bit 1 -> 2, bit 2 -> 3, bit 3 -> 4, bit 4 -> 5, none -> 0) and 0xA758 is cleared.
 * Only caller FUN_CODE_cd4b, which prints the CEC request for the codes 1, 2, 3 and 5.
 * LARGE: the result r lives in XDATA 0xA473 and is read back for the return.
 */
extern unsigned char xdata DAT_EXTMEM_a758;
extern unsigned char FUN_CODE_78ba(void);

unsigned char FUN_CODE_c4ee(void)
{
    unsigned char r, v;

    r = 0;
    if (FUN_CODE_78ba() == 1) {
        v = DAT_EXTMEM_a758;
        if (v & 0x01) r = 1;
        else if (v & 0x02) r = 2;
        else if (v & 0x04) r = 3;
        else if (v & 0x08) r = 4;
        else if (v & 0x10) r = 5;
        DAT_EXTMEM_a758 = 0;
    }
    return r;
}
