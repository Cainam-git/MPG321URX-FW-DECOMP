/* leon2m FUN_a00df3d0 @ 0xa00df3d0-0xa00df420 (20 words).
 * Writes the character c: a '\n' is first preceded by FUN_a00df3d0('\r') (a recursive call); then waits until
 * bit 5 of func_0x4008c250(0xc00b0014) is set and writes c with func_0x4008c25c(0xc00b0000, c).
 */
extern unsigned int func_0x4008c250(unsigned int);
extern void func_0x4008c25c(unsigned int, signed char);

void FUN_a00df3d0(signed char c)
{
    if (c == '\n')
        FUN_a00df3d0('\r');
    while (!(func_0x4008c250(0xc00b0014) & 0x20))
        ;
    func_0x4008c25c(0xc00b0000, c);
}
