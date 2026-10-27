/* FUN_a014f32c (leon2m 0xa014f32c-0xa014f374, 72 bytes, leaf), flags -mcpu=v8 -O3 -g -msoft-float.
 * Returns 1 when none of the four four-bit fields of the halfword DAT_a802cc80 equals c, otherwise 0. Nothing in
 * the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a014f208 and
 * FUN_a014f374. Source form: the limit 4 is kept in a local for the final compare, so GCC emits 'cmp 4; subx' (i >=
 * 4) instead of folding it to i > 3.
 */
extern unsigned short DAT_a802cc80;
int FUN_a014f32c(unsigned char c)
{
    unsigned char i, n = 4;
    for (i = 0; i < 4; i++)
        if (((DAT_a802cc80 >> (i * 4)) & 0xf) == c)
            break;
    return i >= n;
}
