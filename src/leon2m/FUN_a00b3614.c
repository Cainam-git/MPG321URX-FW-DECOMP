/* leon2m FUN_a00b3614 @ 0xa00b3614 (-mcpu=v8 -O3 -g)
 * a > 3 is reduced by 4; y = a * 2 + 5 (16 bits). For i = 0 and 1 calls FUN_a0146b20(0, i + 4, y, 1, k, 0) with
 * k = 0 when on is 0, else k = i + 0x1c. Callers: FUN_a00ad970, FUN_a00adaf4.
 * Source form: one loop with the on test inside; GCC's loop unswitching makes the two loop copies, and the
 * resulting block order gives the firmware's register choice ('!on' arm first).
 */
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00b3614(unsigned char a, unsigned char on)
{
    unsigned char i;
    unsigned short y;

    if (a > 3)
        a -= 4;
    y = a * 2 + 5;
    for (i = 0; i < 2; i++)
        if (!on)
            FUN_a0146b20(0, i + 4, y, 1, 0, 0);
        else
            FUN_a0146b20(0, i + 4, y, 1, i + 0x1c, 0);
}
