/* leon2m FUN_a00d40c8 @ 0xa00d40c8-0xa00d4108 (16 words), flags -mcpu=v8 -O3 -g.
 * Code facts: v = FUN_a0145660(ch, 0x14) (u16 timing getter, src/leon2m/FUN_a0145660.c id 20 = byte +0x26); clamp
 * v to 0x3f; tail FUN_a0145808(ch, 0x14, v, 1) (the matching setter).
 * Source form: a plain u16 clamp 'if (v > 0x3f) v = 0x3f'; u8 channel param, u16 callee prototypes.
 * Compiler aids: none.
 */
extern unsigned short FUN_a0145660(unsigned char, unsigned int);
extern void FUN_a0145808(unsigned char, unsigned int, unsigned short, int);

void FUN_a00d40c8(unsigned char ch)
{
    unsigned short v = FUN_a0145660(ch, 0x14);

    if (v > 0x3f)
        v = 0x3f;
    FUN_a0145808(ch, 0x14, v, 1);
}
