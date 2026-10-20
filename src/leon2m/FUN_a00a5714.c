/* leon2m FUN_a00a5714 @ 0xa00a5714  (-mcpu=v8 -O3 -g)
 * Eleven calls of FUN_a00b32e4(a, b, c, p, q, n, value) with p and q relative to the parameters (x, y): c = 0x12AA at
 * p = x+1 (q = y, y+1, y+3) and p = x+0xB (q = y+4), c = 0x89AE at p = x+3, x+0xC and x (q = y, y+1, y+4), c = 0x8A2
 * at p = x, x+0xD and x+4 (q = y, y+1, y+2, y+4). FUN_a00b32e4 takes (u8, u8, u16, u16, u8, u8, u8); the 7th argument
 * is passed on the stack.
 * Callers: FUN_a00b7f9c+0xE0.
 */
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00a5714(unsigned short x, unsigned char y)
{
    FUN_a00b32e4(1, 1, 0x12aa, x + 1, y, 2, 0);
    FUN_a00b32e4(1, 0, 0x12aa, x + 1, y + 1, 1, 2);
    FUN_a00b32e4(1, 0, 0x12aa, x + 1, y + 3, 1, 3);
    FUN_a00b32e4(1, 1, 0x89ae, x + 3, y, 0xb, 0);
    FUN_a00b32e4(1, 1, 0x89ae, x + 0xc, y + 1, 2, 0xb);
    FUN_a00b32e4(1, 1, 0x89ae, x, y + 4, 4, 0xd);
    FUN_a00b32e4(1, 1, 0x12aa, x + 0xb, y + 4, 3, 4);
    FUN_a00b32e4(1, 0, 0x8a2, x, y, 1, 1);
    FUN_a00b32e4(0, 0, 0x8a2, x, y + 1, 3, 7);
    FUN_a00b32e4(0, 0, 0x8a2, x + 0xd, y + 2, 2, 8);
    FUN_a00b32e4(1, 0, 0x8a2, x + 4, y + 4, 7, 6);
}
