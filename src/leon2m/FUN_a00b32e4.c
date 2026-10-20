/* leon2m FUN_a00b32e4 @ 0xa00b32e4  (-mcpu=v8 -O3 -g)
 * Calls FUN_a0146ab0(c, 0) once, then FUN_a0146b20(1, p, q, 1, value, 0) n times, for k = 0..n-1: dir == 1 passes p =
 * x + k and q = y, any other dir passes p = x and q = y + k. inc != 0 passes ch + k as the value, inc == 0 passes ch
 * each time. Parameters: (u8 dir, u8 inc, u16 c, u16 x, u8 y, u8 n, u8 ch); ch is the 7th argument, passed on the
 * stack. Callers include FUN_a00a5714, FUN_a00ad460 and FUN_a00a8bc0.
 * Source form: the inc test sits inside each loop; the compiler unswitches it into four loops.
 */
extern void FUN_a0146ab0(unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00b32e4(unsigned char dir, unsigned char inc, unsigned short c, unsigned short x, unsigned char y,
                  unsigned char n, unsigned char ch)
{
    unsigned char k;

    FUN_a0146ab0(c, 0);
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
