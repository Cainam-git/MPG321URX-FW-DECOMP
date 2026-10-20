/* 8051_bank1 FUN_CODE_a775 @ 0xa775 (164 B, byte-exact with OPTIMIZE(8,SPEED) LARGE).
 * FUN_CODE_a775(m, x, d): LARGE parameters m (XDATA 0xA4B3) and d (0xA4B4); x stays in R5 and is passed on to
 * FUN_CODE_c389; local v (unsigned long) at 0xA4B5..0xA4B8.
 *   m bit 2: XDATA 0xF054 |= 0x80, 0xF0F9 = 0xEA, 0xF0F6 |= 0x80, 0xF0FA = 0xF0, 0xF02C |= 0x40.
 *   m bit 3: XDATA 0xF035 = 0xEA, 0xF032 |= 0x80, 0xF036 = 0xF0, 0xF02C |= 0x80.
 *   m bit 4: XDATA 0xF071 = 0xEA, 0xF06E |= 0x80, 0xF072 = 0xF0, 0xF030 |= 0x40.
 * Then FUN_CODE_c389(m, x), v = d * 1200 (?C?LIMUL) and the tail call FUN_CODE_9975(m, v) (v goes to 9975's LARGE
 * parameter block at 0xA4BA). Caller: LCALL at 0x239D with three byte arguments. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_f054, DAT_EXTMEM_f0f9, DAT_EXTMEM_f0f6, DAT_EXTMEM_f0fa, DAT_EXTMEM_f02c;
extern unsigned char xdata DAT_EXTMEM_f035, DAT_EXTMEM_f032, DAT_EXTMEM_f036;
extern unsigned char xdata DAT_EXTMEM_f071, DAT_EXTMEM_f06e, DAT_EXTMEM_f072, DAT_EXTMEM_f030;
extern void FUN_CODE_c389(unsigned char m, unsigned char v);
extern void FUN_CODE_9975(unsigned char a, unsigned long b) large;

void FUN_CODE_a775(unsigned char m, unsigned char x, unsigned char d)
{
    unsigned long v;
    if (m & 0x04) {
        DAT_EXTMEM_f054 |= 0x80;
        DAT_EXTMEM_f0f9 = 0xea;
        DAT_EXTMEM_f0f6 |= 0x80;
        DAT_EXTMEM_f0fa = 0xf0;
        DAT_EXTMEM_f02c |= 0x40;
    }
    if (m & 0x08) {
        DAT_EXTMEM_f035 = 0xea;
        DAT_EXTMEM_f032 |= 0x80;
        DAT_EXTMEM_f036 = 0xf0;
        DAT_EXTMEM_f02c |= 0x80;
    }
    if (m & 0x10) {
        DAT_EXTMEM_f071 = 0xea;
        DAT_EXTMEM_f06e |= 0x80;
        DAT_EXTMEM_f072 = 0xf0;
        DAT_EXTMEM_f030 |= 0x40;
    }
    FUN_CODE_c389(m, x);
    v = (unsigned long)d * 1200;
    FUN_CODE_9975(m, v);
}
