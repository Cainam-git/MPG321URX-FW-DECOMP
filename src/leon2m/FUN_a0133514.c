/* leon2m FUN_a0133514 @ 0xa0133514 (-mcpu=v8 -O2 -g)
 * Calls func_0x4008c4d0(0, 0x0C, &local, 1) with a zero-initialised 32-bit local and returns bits 8..15 of the
 * value written to it (ldub, zero-extended into %i0).
 */
extern int func_0x4008c4d0();

int FUN_a0133514(void)
{
    unsigned int local_c;

    local_c = 0;
    func_0x4008c4d0(0, 0xc, &local_c, 1);
    return (local_c >> 8) & 0xff;
}
