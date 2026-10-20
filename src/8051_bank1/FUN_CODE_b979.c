/* 8051_bank1 FUN_CODE_b979 @ 0xb979 (123 B, byte-exact with OPTIMIZE(8,SPEED) LARGE), register bank 3 ('using 3').
 * Clears bit 0x0B (BITS_21_3). While bit 0 of XDATA 0xDCD8 is set: the byte at 0xDCD9 is stored to
 * XDATA 0xA548 + i for i = 0 .. 0x10 (i counts up), or to XDATA 0xA547 once i reaches 0x11. Then XDATA 0xDCDB =
 * XDATA[0xA54B] + 1 when more than 3 bytes were stored, else 0. When the high nibble of XDATA 0xA548 is 0x9:
 * FUN_CODE_34c8(0, 0xA548, 0); when it is 0x8: FUN_CODE_34c8(1, 0xA548, 0) (generic pointer 01 A5 48; the third
 * argument goes to 34c8's LARGE parameter byte 0xA55D). Caller: FUN_CODE_c1c1 (LCALL at 0xC1DE). Same code as FUN_CODE_b8fd except the third
 * 34c8 argument (0 here, 1 there) and the XDATA bytes (0xDCC8 / 0xDCC9 / 0xDCCB there).
 * Source form: 0xDCD8 and 0xDCD9 are one 2-byte object (Keil reaches the second byte with INC DPTR); with
 * separate externs Keil reads 0xDCD9 once before the i test. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_dcd8[2];
extern unsigned char xdata DAT_EXTMEM_dcdb;
extern unsigned char xdata DAT_EXTMEM_a547;
extern unsigned char xdata DAT_EXTMEM_a548[];
extern bit BITS_21_3;
extern void FUN_CODE_34c8(unsigned char sel, unsigned char *p, unsigned char n);

void FUN_CODE_b979(void) using 3
{
    unsigned char i;
    i = 0;
    BITS_21_3 = 0;
    while (DAT_EXTMEM_dcd8[0] & 0x01) {
        if (i < 0x11) DAT_EXTMEM_a548[i++] = DAT_EXTMEM_dcd8[1];
        else DAT_EXTMEM_a547 = DAT_EXTMEM_dcd8[1];
    }
    if (i > 3) DAT_EXTMEM_dcdb = DAT_EXTMEM_a548[3] + 1;
    else DAT_EXTMEM_dcdb = 0;
    if ((DAT_EXTMEM_a548[0] & 0xf0) == 0x90) FUN_CODE_34c8(0, DAT_EXTMEM_a548, 0);
    else if ((DAT_EXTMEM_a548[0] & 0xf0) == 0x80) FUN_CODE_34c8(1, DAT_EXTMEM_a548, 0);
}
