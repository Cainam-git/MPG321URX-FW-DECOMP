/* leon2m FUN_a0105af8 @ 0xa0105af8-0xa0105c0c (69 words), flags -mcpu=v8 -O3 -g -msoft-float
 * (the float arithmetic is libgcc soft-float calls; plain -O3 -g does not match).
 * Code facts: q = (u16)FUN_a0120a18(p) * (u16)FUN_a00f25f8(p, 0x4c) / 1000 (unsigned, umul by 0x10624dd3). f =
 * (float)v[0] (short, __floatsisf = FUN_a0155c40), + 65536.0f if v[0] < 0 (__addsf3 = FUN_a015578c, constant at
 * 0x19a2d0); f *= (float)(u16)v[1]; f *= (float)(u16)FUN_a0120b38(p) (__mulsf3 = FUN_a0155830); f /= 1000.0f twice
 * (__divsf3 = FUN_a0155a18, constant at 0x19aba0 loaded once); n = (unsigned)f (__fixunssfsi = FUN_a01551bc). Tail
 * call FUN_a00f232c(p, 0x91, 4, q / n <= 14 ? 1 : 0). void.
 * The FUN_a0155xxx callees are libgcc soft-float helpers, so the source is float arithmetic built with -msoft-float.
 * Source form: the product is one expression of the two u16-returning calls (the firmware zero-extends the first
 * result before the second call); the three callees return u16 (their retl/ret ends in sll/srl or lduh). Compiler
 * aids: none.
 */
extern void FUN_a00f232c(unsigned char, unsigned int, unsigned int, unsigned int);
extern unsigned short FUN_a00f25f8(unsigned char, unsigned char);
extern unsigned short FUN_a0120a18(unsigned char);
extern unsigned short FUN_a0120b38(unsigned char);

void FUN_a0105af8(unsigned char p, short *v)
{
    unsigned int q;
    float f;

    q = (unsigned int)(FUN_a0120a18(p) * FUN_a00f25f8(p, 0x4c)) / 1000;
    f = v[0];
    if (v[0] < 0)
        f += 65536.0f;
    f = f * (unsigned short)v[1];
    f = f * FUN_a0120b38(p);
    f = f / 1000.0f;
    f = f / 1000.0f;
    if (q / (unsigned int)f <= 14)
        FUN_a00f232c(p, 0x91, 4, 1);
    else
        FUN_a00f232c(p, 0x91, 4, 0);
}
