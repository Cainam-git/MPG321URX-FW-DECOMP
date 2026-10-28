/* 8051_bank1 FUN_CODE_7df1 @ 0x7df1 (325 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_7df1(wn, wbuf, rn, rbuf): parameters in the LARGE block XDATA 0xA4CE (wn 0xA4CE..0xA4CF, wbuf
 * 0xA4D0..0xA4D2, rn 0xA4D3..0xA4D4, rbuf 0xA4D5..0xA4D7); locals m 0xA4D8, addr 0xA4D9..0xA4DC, i.
 * XDATA 0xF0E6 = (0xF0E6 & 0x0C) | 0x41 (through m); addr = wn + rn - 1 (16-bit sum as a long);
 * 0xF0F4 = (low byte of wn << 5) | 0x13; 0xF0EB / 0xF0EC / 0xF0ED = addr >> 16, addr >> 8, addr & 0xFF;
 * 0xF0EE = wbuf[0]; 0xF1C0 = 0x82; wbuf[1..wn-1] are written to 0xF1C3; 0xF1C0 = 0x84; 0xF1C8 = 0x81;
 * 0xF0E5 = 1, then waits until bit 0 of 0xF0E5 is clear. When rn > 0: 0xF1C8 = 0x82, one read of 0xF1C8 into m,
 * then rn reads of 0xF1C8 into rbuf[0..rn-1]. Ends with 0xF1C0 = 0x80 and 0xF1C8 = 0x80.
 * Callers: FUN_CODE_7765 (0x78A4), FUN_CODE_b456 (0xB4CA).
 * volatile on the 0xF0xx / 0xF1xx registers: hardware registers (0xF0E5 is polled, 0xF1C3 / 0xF1C8 are written and
 *   read repeatedly at one address), as in FUN_CODE_a41f and FUN_CODE_c5f0. Because 0xF0E6 is volatile, Keil
 *   reads m back after storing it ('MOVX @DPTR,A; MOVX A,@DPTR' before 'ORL A,#41H').
 * Source form: 'm = 0xF0E6 & 0x0C; m |= 0x41;' as two statements; 'addr & 0xff' for the low byte (the value goes
 *   through R7 like the two shifted bytes; '(unsigned char)addr' stores it straight from A).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e6;
extern unsigned char volatile xdata DAT_EXTMEM_f0f4, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0ee;
extern unsigned char volatile xdata DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c3;
extern unsigned char volatile xdata DAT_EXTMEM_f1c8;
extern unsigned char volatile xdata DAT_EXTMEM_f0e5;

void FUN_CODE_7df1(unsigned int wn, unsigned char *wbuf, unsigned int rn, unsigned char *rbuf)
{
    unsigned int i;
    unsigned char m;
    unsigned long addr;

    m = DAT_EXTMEM_f0e6 & 0x0c;
    m |= 0x41;
    DAT_EXTMEM_f0e6 = m;
    addr = wn + rn - 1;
    DAT_EXTMEM_f0f4 = ((unsigned char)wn << 5) | 0x13;
    DAT_EXTMEM_f0eb = addr >> 16;
    DAT_EXTMEM_f0ec = addr >> 8;
    DAT_EXTMEM_f0ed = addr & 0xff;
    DAT_EXTMEM_f0ee = wbuf[0];
    DAT_EXTMEM_f1c0 = 0x82;
    for (i = 1; i < wn; i++)
        DAT_EXTMEM_f1c3 = wbuf[i];
    DAT_EXTMEM_f1c0 = 0x84;
    DAT_EXTMEM_f1c8 = 0x81;
    DAT_EXTMEM_f0e5 = 0x01;
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 0x01))
        ;
    if (rn > 0) {
        DAT_EXTMEM_f1c8 = 0x82;
        m = DAT_EXTMEM_f1c8;
        for (i = 0; i < rn; i++)
            rbuf[i] = DAT_EXTMEM_f1c8;
    }
    DAT_EXTMEM_f1c0 = 0x80;
    DAT_EXTMEM_f1c8 = 0x80;
}
