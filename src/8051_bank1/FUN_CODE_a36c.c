/* 8051_bank1 FUN_CODE_a36c @ 0xa36c..0xa41f (179 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_a36c(off, n, src): copies n bytes from the generic pointer src to XDATA 0xA800 + off. When off + n is
 * above 0x800 it passes the format at CODE 0xC4BB ("KeyDetArray OOR\r\n") to FUN_CODE_2820, returns when off is
 * already 0x800 or more, and otherwise cuts n to 0x800 - off.
 * LARGE parameters: off at XDATA 0xA4A9, n at 0xA4AB, src at 0xA4AD; local p (generic pointer) at 0xA4B0; i stays in
 * R6:R7. Both pointers advance with ?C?ILDIX (+1) and the byte moves with ?C?CLDPTR / ?C?CSTPTR ('*p++ = *src++').
 * Caller: FUN_CODE_1c3c (command 7, FUN_CODE_a36c(b2 + w, n, buf)).
 */
extern unsigned char xdata DAT_EXTMEM_a800[];
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_a36c(unsigned int off, unsigned int n, unsigned char *src)
{
    unsigned char *p;
    unsigned int i;
    if (off + n > 0x800) {
        FUN_CODE_2820((void code *)0xc4bb);
        if (off >= 0x800) return;
        n = 0x800 - off;
    }
    p = &DAT_EXTMEM_a800[off];
    for (i = 0; i < n; i++) *p++ = *src++;
}
