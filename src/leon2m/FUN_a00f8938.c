/* leon2m FUN_a00f8938 @ 0xa00f8938-0xa00f896c (13 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a00f1d48(a & 0xff, 0x14, (u16)(x & ~1)); tail FUN_a00f1d48(a, 0x10, (u16)y). 3 params.
 * Source form: the & ~1 is a separate statement 'x &= ~1;' on the unsigned int param: in one expression fold-const
 * turns (u16)(x & ~1) into x & 0xfffe (sethi|or + and); as a statement the RTL keeps 'and -2' + the u16
 * zero-extension (sll/srl), and combine cannot fold them (0xfffe is not a simm13).
 * u16 / u8 parameters from the callee's prototype (its code masks %i0). Compiler aids: none.
 */
extern void FUN_a00f1d48(unsigned char, unsigned char, unsigned short);

void FUN_a00f8938(unsigned char a, unsigned int x, unsigned short y)
{
    x &= ~1;
    FUN_a00f1d48(a, 0x14, x);
    FUN_a00f1d48(a, 0x10, y);
}
