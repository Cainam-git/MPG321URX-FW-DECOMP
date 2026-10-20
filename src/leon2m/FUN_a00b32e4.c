/* leon2m FUN_a00b32e4 @ 0xa00b32e4  (-mcpu=v8 -O3 -g)
 * Draws a run of n character cells in one colour: FUN_a0146ab0(colour, 0) selects the colour, then n calls of
 * FUN_a0146b20(1, column, row, 1, char, 0). dir == 1 runs horizontally from (x, y) (column x + k), any other dir
 * runs vertically (row y + k). inc != 0 draws the characters ch, ch + 1, ...; inc == 0 repeats ch.
 * Parameters: (u8 dir, u8 inc, u16 colour, u16 x, u8 y, u8 n, u8 ch); ch is the 7th argument, passed on the stack.
 * Called from many menu drawing routines (for example FUN_a00a5714, FUN_a00ad460, FUN_a00a8bc0).
 * Source form: the inc test sits inside each loop; the compiler unswitches it into four loops.
 */
extern void FUN_a0146ab0(unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00b32e4(unsigned char dir, unsigned char inc, unsigned short colour, unsigned short x, unsigned char y,
                  unsigned char n, unsigned char ch)
{
    unsigned char k;

    FUN_a0146ab0(colour, 0);
    if (dir == 1) {
        for (k = 0; k < n; k++) {
            if (inc)
                FUN_a0146b20(1, x + k, y, 1, ch + k, 0);
            else
                FUN_a0146b20(1, x + k, y, 1, ch, 0);
        }
    } else {
        for (k = 0; k < n; k++) {
            if (inc)
                FUN_a0146b20(1, x, y + k, 1, ch + k, 0);
            else
                FUN_a0146b20(1, x, y + k, 1, ch, 0);
        }
    }
}
