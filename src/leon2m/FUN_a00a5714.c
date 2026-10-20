/* leon2m FUN_a00a5714 @ 0xa00a5714  (-mcpu=v8 -O3 -g)
 * Draws a fixed frame of eleven blocks relative to the position (x, y) with FUN_a00b32e4(a, b, colour, column,
 * row, width, char): colour 0x12AA blocks at x+1 (rows y, y+1, y+3) and x+0xB (row y+4), colour 0x89AE blocks at
 * x+3, x+0xC and x (rows y, y+1, y+4), colour 0x8A2 blocks at x, x+0xD and x+4 (rows y, y+1, y+2, y+4).
 * FUN_a00b32e4 takes (u8, u8, u16 colour, u16 column, u8 row, u8 width, u8 char); the 7th argument is passed on
 * the stack.
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
