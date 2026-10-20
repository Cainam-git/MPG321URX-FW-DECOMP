/* leon2m FUN_a00dee6c @ 0xa00dee6c-0xa00deea4 (14 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/14 mismatches.
 * Code facts: ROM read func_0x4008c250(0xc00b0014); if bit 0 is set, *out = (u8)func_0x4008c250(
 * 0xc00b0000) and returns 1, else returns 0 (UART-style status then data read).
 * Fixes vs the autoc draft (50.00): BEHAVIOUR: the second read is at 0xc00b0000 (fw 'mov %l0,%o0'
 * with %l0 = sethi only), the draft re-read the status and stored a constant 0. Aids: none.
 */
extern unsigned int func_0x4008c250(unsigned int);

int FUN_a00dee6c(unsigned char *out)
{
    if (func_0x4008c250(0xc00b0014) & 1) {
        *out = func_0x4008c250(0xc00b0000);
        return 1;
    }
    return 0;
}
