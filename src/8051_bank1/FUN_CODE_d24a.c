/* 8051_bank1 FUN_CODE_d24a @ 0xd24a  OPTIMIZE(7,SPEED)
 * Runs in register bank 3 (`using 3`, MOV PSW,#0x18). When bit 7 of XDATA 0xD90B is set it writes
 * (FUN_CODE_d6bf() + 1) | 0x40 to 0xD929, 0x60 to 0xF04C, 0xC0 to 0xA773 and 0xE0 to 0xA772, and loads Timer 1
 * with TH1 = 0x98, TL1 = 0xC3. The test written as `(x & 0x80) ^ 0x80` with an empty then-branch produces the
 * target's ANL A,#0x80 / XRL A,#0x80 / JNZ.
 */
sfr TL1 = 0x8B;
sfr TH1 = 0x8D;

extern xdata unsigned char DAT_EXTMEM_d90b;
extern xdata unsigned char DAT_EXTMEM_d929;
extern xdata unsigned char DAT_EXTMEM_f04c;
extern xdata unsigned char DAT_EXTMEM_a773;
extern xdata unsigned char DAT_EXTMEM_a772;

unsigned char FUN_CODE_d6bf(void);  // at 0xd6bf

void FUN_CODE_d24a(void) using 3 {
    if ((DAT_EXTMEM_d90b & 0x80) ^ 0x80) {
        // skip body
    } else {
        DAT_EXTMEM_d929 = (FUN_CODE_d6bf() + 1) | 0x40;
        DAT_EXTMEM_f04c = 0x60;
        DAT_EXTMEM_a773 = 0xc0;
        DAT_EXTMEM_a772 = 0xe0;
        TL1 = 0xc3;
        TH1 = 0x98;
    }
}
