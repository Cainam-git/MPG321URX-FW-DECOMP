/* FUN_a013d670 (leon2m 0xa013d670-0xa013d684, 20 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 1 when the byte DAT_a802e1a7 is not 0, else 0 (cmp %g0; addx). Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a013d1b4 and FUN_a013d684. Source form:
 * 'return DAT_a802e1a7 != 0;'.
 */
extern unsigned char DAT_a802e1a7;

int FUN_a013d670(void)
{
    return DAT_a802e1a7 != 0;
}
