/* leon2m FUN_a00a5908 @ 0xa00a5908-0xa00a5e68 (346 words), flags -mcpu=v8 -O3 -g.
 * Callers: FUN_a00a5e68, FUN_a00a6b98, FUN_a00b5d10, FUN_a00b8e7c.
 * FUN_a00a5908(x, y, mode): c = 0x11; for mode != 2, c = 0x16 and FUN_a0146a80(x, y + i, c, 0x796, 0) runs for
 * i = 0..c-1. Then 27 calls of FUN_a00b32e4(a, b, colour, p, q, n, id) (u8, u8, u16, u16, u8, u8, u8; the 7th
 * argument on the stack) with p relative to x and q relative to y or to c + y (colours 0x592, 0x9aaa, 0x9aae,
 * 0x9faa, 0xa29a, 0x3092, 0x8a2, ids 9..0x28 and 1..8, n = c - 7 and c - 6 in two calls). For mode 1 it then
 * calls FUN_a0146b50(0x101, 0), FUN_a0146b6c(2, 0) and FUN_a00b9750(x, y).
 * Source form: the loop limit and FUN_a0146a80's third argument are the variable c (cmp 0x16; bcs). x, y, c and mode
 * are spilled by the register allocator and reloaded from their stack slots.
 * Compiler aid: the dead store 'i = 0;' after the loop emits no instructions; it changes the register allocation
 * at the start (x is truncated from %i0 directly instead of being reloaded from its stack slot).
 */
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern void FUN_a00b9750(unsigned short, unsigned short);

void FUN_a00a5908(unsigned short x, unsigned short y, unsigned char mode)
{
    unsigned char c, i;

    c = 0x11;
    if (mode != 2) {
        c = 0x16;
        for (i = 0; i < c; i++)
            FUN_a0146a80(x, i + y, c, 0x796, 0);
        i = 0;
    }
    FUN_a00b32e4(1, 1, 0x592, x + 2, y + 2, 2, 9);
    FUN_a00b32e4(1, 0, 0x592, x + 1, c + y - 5, 1, 0xb);
    FUN_a00b32e4(1, 0, 0x592, x + 4, c + y - 4, 1, 0xc);
    FUN_a00b32e4(1, 0, 0x592, x + 0x12, c + y - 3, 1, 0xd);
    FUN_a00b32e4(0, 1, 0x592, x + 0x13, c + y - 4, 2, 0xe);
    FUN_a00b32e4(1, 1, 0x9aaa, x + 1, y, 3, 0xd);
    FUN_a00b32e4(1, 1, 0x9aaa, x, y + 1, 3, 0x10);
    FUN_a00b32e4(1, 1, 0x9aaa, x, y + 2, 2, 0x13);
    FUN_a00b32e4(1, 1, 0x9aae, x + 4, y, 0xf, 0x11);
    FUN_a00b32e4(1, 1, 0x9faa, x + 0x13, y, 3, 0x15);
    FUN_a00b32e4(1, 1, 0x9faa, x + 0x13, y + 1, 3, 0x18);
    FUN_a00b32e4(1, 1, 0xa29a, x + 0x13, y + 2, 3, 0x1b);
    FUN_a00b32e4(1, 1, 0x9aaa, x + 0x13, y + 3, 3, 0x1e);
    FUN_a00b32e4(1, 1, 0x9aaa, x + 0x13, y + 4, 3, 0x21);
    FUN_a00b32e4(1, 1, 0x9faa, x, c + y - 4, 2, 0x24);
    FUN_a00b32e4(1, 1, 0x9faa, x, c + y - 3, 2, 0x26);
    FUN_a00b32e4(1, 1, 0x9faa, x, c + y - 2, 1, 0x28);
    FUN_a00b32e4(1, 1, 0x3092, x + 2, c + y - 5, 2, 0x10);
    FUN_a00b32e4(1, 1, 0x3092, x + 2, c + y - 4, 2, 0x12);
    FUN_a00b32e4(1, 1, 0x3092, x + 2, c + y - 3, 1, 0x14);
    FUN_a00b32e4(1, 1, 0x3092, x + 1, c + y - 2, 1, 0x15);
    FUN_a00b32e4(1, 0, 0x8a2, x, y, 1, 1);
    FUN_a00b32e4(0, 0, 0x8a2, x, y + 3, c - 7, 7);
    FUN_a00b32e4(0, 0, 0x8a2, x + 0x15, y + 5, c - 6, 8);
    FUN_a00b32e4(1, 0, 0x8a2, x, c + y - 1, 1, 3);
    FUN_a00b32e4(1, 0, 0x8a2, x + 1, c + y - 1, 0x14, 6);
    FUN_a00b32e4(1, 0, 0x8a2, x + 0x15, c + y - 1, 1, 4);
    if (mode == 1) {
        FUN_a0146b50(0x101, 0);
        FUN_a0146b6c(2, 0);
        FUN_a00b9750(x, y);
    }
}
