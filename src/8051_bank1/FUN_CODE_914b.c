/* 8051_bank1 FUN_CODE_914b @ 0x914b (248 B, OPTIMIZE(8,SPEED) LARGE), register bank 3 ('using 3').
 * LARGE locals: n at XDATA 0xA548, buf[17] at 0xA549..0xA559, h at 0xA55A. Clears n, bit 0x0B (BITS_21_3) and h.
 * While bit 0 of XDATA 0xDCC8 is set, the byte at 0xDCC9 is read and stored to buf[n++] while n < 0x11, else to
 * XDATA 0xA547. XDATA 0xDCCB = buf[3] + 1 when n > 3, else 0. Sets bit 0 of XDATA 0xDCCC and waits until it reads 0.
 * h = buf[0] & 0xF0: 0x90 -> FUN_CODE_147a(0, buf, 1); 0x10 or 0x50 -> FUN_CODE_147a(2, buf, 1); 0x80 ->
 * FUN_CODE_147a(1, buf, 1); 0x00 or 0x40 -> FUN_CODE_147a(3, buf, 1); other values: XDATA 0xDCCB = 0 (the third
 * argument goes to 147a's LARGE parameter byte 0xA55F). Sets BITS_21_3 when n is 0; while BITS_21_3 is clear it
 * writes 0 and then 1 to XDATA 0xDCCA and, when XDATA 0xD511 is 0x20, sets bit 2 of 0xDCCA.
 * Caller: FUN_CODE_c1c1 (LCALL at 0xC1FB). Same code as FUN_CODE_9339 except the third 147a argument (1 here, 0 there)
 * and the XDATA bytes 0xDCD8..0xDCDC there.
 * Source forms: 0xDCC8 / 0xDCC9 are one 2-byte object (INC DPTR in the twin functions FUN_CODE_b8fd / FUN_CODE_b979);
 * the wait loop tests an int-typed value (ANL A,#01H / JNZ). No aids.
 */
extern unsigned char xdata DAT_EXTMEM_dcc8[2];
extern unsigned char xdata DAT_EXTMEM_dcca, DAT_EXTMEM_dccb, DAT_EXTMEM_dccc;
extern unsigned char xdata DAT_EXTMEM_a547;
extern unsigned char xdata DAT_EXTMEM_d511;
extern bit BITS_21_3;
extern void FUN_CODE_147a(unsigned char sel, unsigned char *p, unsigned char n);

void FUN_CODE_914b(void) using 3
{
    unsigned char n;
    unsigned char buf[17];
    unsigned char h;
    n = 0;
    BITS_21_3 = 0;
    h = 0;
    while (DAT_EXTMEM_dcc8[0] & 0x01) {
        if (n < 0x11) buf[n++] = DAT_EXTMEM_dcc8[1];
        else DAT_EXTMEM_a547 = DAT_EXTMEM_dcc8[1];
    }
    if (n > 3) DAT_EXTMEM_dccb = buf[3] + 1;
    else DAT_EXTMEM_dccb = 0;
    DAT_EXTMEM_dccc |= 0x01;
    while ((unsigned int)(DAT_EXTMEM_dccc & 0x01)) ;
    h = buf[0] & 0xf0;
    if (h == 0x90) FUN_CODE_147a(0, buf, 1);
    else if (h == 0x10 || h == 0x50) FUN_CODE_147a(2, buf, 1);
    else if (h == 0x80) FUN_CODE_147a(1, buf, 1);
    else if (h == 0x00 || h == 0x40) FUN_CODE_147a(3, buf, 1);
    else DAT_EXTMEM_dccb = 0;
    if (n == 0) BITS_21_3 = 1;
    if (!BITS_21_3) {
        DAT_EXTMEM_dcca = 0;
        DAT_EXTMEM_dcca = 1;
        if (DAT_EXTMEM_d511 == 0x20) DAT_EXTMEM_dcca |= 0x04;
    }
}
