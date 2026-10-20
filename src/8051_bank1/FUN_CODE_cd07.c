/* 8051_bank1 FUN_CODE_cd07 @ 0xcd07..0xcd4b (68 B)  Byte-exact with OPTIMIZE(8,SPEED) over 0xCD07..0xCD4B.
 * Computes the Timer 0 reload 0x10000 - FUN_CODE_dbf6() twice (32-bit), stores its low byte in XDATA 0xA773 and
 * its high byte (division by 256 with ?C?ULDIV) in 0xA772, then tail-jumps to FUN_CODE_9975(1, 4800).
 * FUN_CODE_ce4b copies 0xA773 / 0xA772 into TL0 / TH0. Callers: FUN_CODE_b06f (0xB0FF), FUN_CODE_ce4b,
 * FUN_CODE_d987 (0xD987).
 * The difference is held in a 32-bit local: a direct 'DAT_EXTMEM_a773 = 0x10000 - FUN_CODE_dbf6();' is narrowed
 * by Keil to CPL / INC on the low byte.
 * FUN_CODE_9975 is a LARGE function: R7 = first parameter, the 32-bit second parameter goes to its XDATA block at
 * 0xA4BA (?C?LSTKXDATA with the inline constant 00 00 12 C0).
 */
extern unsigned char xdata DAT_EXTMEM_a773, DAT_EXTMEM_a772;
extern unsigned long FUN_CODE_dbf6(void);
extern void FUN_CODE_9975(unsigned char a, unsigned long b) large;

void FUN_CODE_cd07(void)
{
    unsigned long t;

    t = 0x10000 - FUN_CODE_dbf6();
    DAT_EXTMEM_a773 = t;
    t = 0x10000 - FUN_CODE_dbf6();
    DAT_EXTMEM_a772 = t / 256;
    FUN_CODE_9975(1, 4800);
}
