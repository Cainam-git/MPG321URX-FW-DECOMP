/* leon2s FUN_a00d65a0 @ 0xa00d65a0-0xa00d6624 (33 words).
 * x = func_0xa0fb6bb8(port, 0x9f); nothing more for port 1. Otherwise, for v = 0..3, tail-calls
 * func_0xa0fb6c00(port, 0x9f, x with bits 6-7 replaced by v); other v write nothing. One call per case in the source
 * (GCC merges them). The ret/restore epilogue at 0xa00d661c, reached by a branch, belongs to this function.
 */
extern unsigned char func_0xa0fb6bb8(unsigned char, unsigned int);
extern void func_0xa0fb6c00(unsigned char, unsigned int, unsigned char);

void FUN_a00d65a0(unsigned char port, unsigned char v)
{
    unsigned char x = func_0xa0fb6bb8(port, 0x9f);

    if (port == 1)
        return;
    switch (v) {
    case 0: func_0xa0fb6c00(port, 0x9f, x & 0x3f); break;
    case 1: func_0xa0fb6c00(port, 0x9f, (x & 0x3f) | 0x40); break;
    case 2: func_0xa0fb6c00(port, 0x9f, (x & 0x3f) | 0x80); break;
    case 3: func_0xa0fb6c00(port, 0x9f, x | 0xc0); break;
    }
}
