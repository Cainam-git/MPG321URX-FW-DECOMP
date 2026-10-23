/* 8051_bank1 FUN_CODE_c544 @ 0xc544..0xc59a (86 bytes)  set the boot / wake byte for the Big chip.
 * Options: OPTIMIZE(8,SPEED) LARGE
 * (v and w are LARGE-model XDATA 0xA473 / 0xA474). Keys: 'v' is unsigned char and 'v << 8' is int arithmetic (fw: R6 = v,
 * R5 = R4 = sign of bit 7, R7 = 0); a 'char' parameter adds a second sign extension, a long cast gives ?C?LSHL.
 * What the code does (code facts): reads the 32-bit word at mailbox offset 0xB8 (FUN_CODE_a4e9(0xB8, &w, 1): AHB
 *   0x9F0A01B8, the Main <-> helper portal), replaces bits 15..8 with v and writes it back (FUN_CODE_b228(0xB8, &w, 1),
 *   tail call). Because 'v << 8' is a signed int, a v >= 0x80 would also set bits 31..16; the callers pass 1, 2 and
 *   the wake word.
 * Callers (code): FUN_CODE_3fe7 at start-up c544(1) (0x4075) and c544(2) if 0xF0DD bit 2 was set (0x4082), and on
 *   every wake-up c544(wake word) (0x42E2) right before run state 0xA770 = 2.
 * Big chip side: start-up WAIT 1 FUN_a0133564 reads the same word through portal 0 offset 0xB8 and returns
 *   (word >> 8) & 0xFF, i.e. exactly this byte (FUN_a015266c waits on it without timeout; the exact
 *   release condition is in FUN_a015266c, not re-read here).
 * Timing: the Big chip leaves WAIT 1 only after this call, which FUN_CODE_3fe7 makes after FUN_CODE_0b0d and
 *   after it restarted the tick stamps 0xA35A / 0xA35C (grace call of FUN_CODE_7b5a). So the 15000-tick ring-1 limit counts from
 *   about the moment the Big chip is released, and covers its whole start-up up to the first main-loop call of FUN_a002ced8.
 */
extern void FUN_CODE_a4e9(unsigned char off, unsigned long *dst, unsigned char n);
extern void FUN_CODE_b228(unsigned char off, unsigned long *src, unsigned char n);
void FUN_CODE_c544(unsigned char v)
{
    unsigned long w;
    FUN_CODE_a4e9(0xb8, &w, 1);
    w = (w & 0xffff00ff) | (v << 8);
    FUN_CODE_b228(0xb8, &w, 1);
}
