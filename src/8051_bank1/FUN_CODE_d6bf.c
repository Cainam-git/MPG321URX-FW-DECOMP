/* 8051_bank1 FUN_CODE_d6bf @ 0xd6bf  MATCH (OPTIMIZE(8,SPEED) LARGE, judged with the LARGE memory model) */
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
