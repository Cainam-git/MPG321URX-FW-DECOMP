/* 8051_bank1 FUN_CODE_9339 @ 0x9339 (245 B, byte-exact with OPTIMIZE(8,SPEED) LARGE), register bank 3 ('using 3').
 * LARGE locals: n at XDATA 0xA548, buf[17] at 0xA549..0xA559, h at 0xA55A. Clears n, bit 0x0B (BITS_21_3) and h.
 * While bit 0 of XDATA 0xDCD8 is set, the byte at 0xDCD9 is read and stored to buf[n++] while n < 0x11, else to
 * XDATA 0xA547. XDATA 0xDCDB = buf[3] + 1 when n > 3, else 0. Sets bit 0 of XDATA 0xDCDC and waits until it reads 0.
 * h = buf[0] & 0xF0: 0x90 -> FUN_CODE_147a(0, buf, 0); 0x10 or 0x50 -> FUN_CODE_147a(2, buf, 0); 0x80 ->
 * FUN_CODE_147a(1, buf, 0); 0x00 or 0x40 -> FUN_CODE_147a(3, buf, 0); other values: XDATA 0xDCDB = 0 (the third
 * argument goes to 147a's LARGE parameter byte 0xA55F). Sets BITS_21_3 when n is 0; while BITS_21_3 is clear it
 * writes 0 and then 1 to XDATA 0xDCDA and, when XDATA 0xD511 is 0x20, sets bit 2 of 0xDCDA.
 * Caller: FUN_CODE_c1c1 (LCALL at 0xC1D9). Same code as FUN_CODE_914b except the third 147a argument (0 here, 1 there)
 * and the XDATA bytes 0xDCC8..0xDCCC there.
 * Source forms: 0xDCD8 / 0xDCD9 are one 2-byte object (INC DPTR in the twin functions FUN_CODE_b8fd / FUN_CODE_b979);
 * the wait loop tests an int-typed value (ANL A,#01H / JNZ). No aids.
 */
extern unsigned char xdata DAT_EXTMEM_dcd8[2];
extern unsigned char xdata DAT_EXTMEM_dcda, DAT_EXTMEM_dcdb, DAT_EXTMEM_dcdc;
extern unsigned char xdata DAT_EXTMEM_a547;
extern unsigned char xdata DAT_EXTMEM_d511;
extern bit BITS_21_3;
extern void FUN_CODE_147a(unsigned char sel, unsigned char *p, unsigned char n);

void FUN_CODE_9339(void) using 3
{
    unsigned char n;
    unsigned char buf[17];
    unsigned char h;
    n = 0;
    BITS_21_3 = 0;
    h = 0;
    while (DAT_EXTMEM_dcd8[0] & 0x01) {
        if (n < 0x11) buf[n++] = DAT_EXTMEM_dcd8[1];
        else DAT_EXTMEM_a547 = DAT_EXTMEM_dcd8[1];
    }
    if (n > 3) DAT_EXTMEM_dcdb = buf[3] + 1;
    else DAT_EXTMEM_dcdb = 0;
    DAT_EXTMEM_dcdc |= 0x01;
    while ((unsigned int)(DAT_EXTMEM_dcdc & 0x01)) ;
    h = buf[0] & 0xf0;
    if (h == 0x90) FUN_CODE_147a(0, buf, 0);
    else if (h == 0x10 || h == 0x50) FUN_CODE_147a(2, buf, 0);
    else if (h == 0x80) FUN_CODE_147a(1, buf, 0);
    else if (h == 0x00 || h == 0x40) FUN_CODE_147a(3, buf, 0);
    else DAT_EXTMEM_dcdb = 0;
    if (n == 0) BITS_21_3 = 1;
    if (!BITS_21_3) {
        DAT_EXTMEM_dcda = 0;
        DAT_EXTMEM_dcda = 1;
        if (DAT_EXTMEM_d511 == 0x20) DAT_EXTMEM_dcda |= 0x04;
    }
}
