/* 8051_bank1 FUN_CODE_c03f @ 0xc03f..0xc0a1 (98 B)  Options: OPTIMIZE(8,SPEED) LARGE.
 * Copies bits 0..3 of m into bits 0..3 of XDATA 0xA1E7 (one set-or-clear per bit), then writes
 * (reg & 0xF0) | 0xA1E7 back to XDATA 0xF021 and 0xF022 (0xA1E7 is read once and kept in R6).
 * Only caller: the command switch FUN_CODE_224f (command 0x09 with its byte 1, command 0x0A with 0).
 * One C function: the else branch of bit 3 (0xC081) runs straight into the 0xF021 / 0xF022 update at 0xC085, and
 * the SJMP at 0xC07F jumps over that else branch. Nothing else calls 0xC07F or 0xC085.
 * m is copied to R5 at entry; the first test reads R7 only in the LARGE build.
 */
extern unsigned char xdata DAT_EXTMEM_a1e7, DAT_EXTMEM_f021, DAT_EXTMEM_f022;

void FUN_CODE_c03f(unsigned char m)
{
    if (m & 0x01) DAT_EXTMEM_a1e7 |= 0x01; else DAT_EXTMEM_a1e7 &= ~0x01;
    if (m & 0x02) DAT_EXTMEM_a1e7 |= 0x02; else DAT_EXTMEM_a1e7 &= ~0x02;
    if (m & 0x04) DAT_EXTMEM_a1e7 |= 0x04; else DAT_EXTMEM_a1e7 &= ~0x04;
    if (m & 0x08) DAT_EXTMEM_a1e7 |= 0x08; else DAT_EXTMEM_a1e7 &= ~0x08;
    DAT_EXTMEM_f021 = (DAT_EXTMEM_f021 & 0xf0) | DAT_EXTMEM_a1e7;
    DAT_EXTMEM_f022 = (DAT_EXTMEM_f022 & 0xf0) | DAT_EXTMEM_a1e7;
}
