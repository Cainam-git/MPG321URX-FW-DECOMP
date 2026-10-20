/* leon2m FUN_a0124828 @ 0xa0124828  MATCH (-mcpu=v8 -O2 -g)
 * Returns 1 when the low byte of func_0x4008cd38(13, 32) is 1, else 0. '(r & 0xff) == 1' produces the
 * and / xor 1 / cmp / 'subx %g0, -1' sequence. The function takes no parameters and returns int; this avoids the
 * extra clr / or instructions of a 64-bit return.
 */
/* 0x4008cd38 - external function called with (0xd, 0x20) */
extern int func_0x4008cd38(int, int);

int FUN_a0124828(void)
{
    int r;
    r = func_0x4008cd38(0xd, 0x20);
    return (r & 0xff) == 1;
}
