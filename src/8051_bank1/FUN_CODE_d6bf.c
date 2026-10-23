/* 8051_bank1 FUN_CODE_d6bf @ 0xd6bf  OPTIMIZE(8,SPEED) LARGE
 * Returns the first i in 0..5 with CODE[0xDC83 + i] == 0x30 (when XDATA 0xD511 is 0x20, tested in every round) or
 * CODE[0xDC7D + i] == 0x60 (other values); 0 when none matches.
 */
extern xdata unsigned char DAT_EXTMEM_d511;
extern code unsigned char DAT_CODE_dc83[];
extern code unsigned char DAT_CODE_dc7d[];

unsigned char FUN_CODE_d6bf(void)
{
    unsigned char i;

    i = 0;
    do {
        if (DAT_EXTMEM_d511 == 0x20) {
            if (DAT_CODE_dc83[i] == 0x30) break;
        } else {
            if (DAT_CODE_dc7d[i] == 0x60) break;
        }
        i++;
    } while (i != 6);

    if (i == 6) {
        i = 0;
    }
    return i;
}
