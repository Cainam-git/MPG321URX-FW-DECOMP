/* FUN_a00c224c (leon2s 0xa00c224c-0xa00c22a0, 84 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Shifts the bytes p[1..7] down to p[0..6]; then, with v = the old p[0]: p[7] = v + 1 when v != 0xff, else
 * p[6] is incremented and p[7] = 0. Called by FUN_a00c32f4, FUN_a00c3ae8 and FUN_a00c44e4.
 */
void FUN_a00c224c(unsigned char *p)
{
    unsigned char v = p[0];
    unsigned char i;

    for (i = 0; i < 7; i++)
        p[i] = p[i + 1];
    if (v != 0xff) {
        p[7] = v + 1;
    } else {
        p[6]++;
        p[7] = 0;
    }
}
