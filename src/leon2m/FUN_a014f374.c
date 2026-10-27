/* FUN_a014f374 (leon2m 0xa014f374-0xa014f3d8, 100 bytes, leaf), flags -mcpu=v8 -O3 -g -msoft-float.
 * Finds the index i of the first four-bit field of the halfword DAT_a802cc80 equal to c (the FUN_a014ead0 search)
 * and, when one exists, calls FUN_a0138674(i, v) as a tail call. Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a014f32c and FUN_a014f3d8. Source form: the
 * FUN_a014ead0 search is a static helper inlined here.
 */
extern unsigned short DAT_a802cc80;
extern void FUN_a0138674(unsigned char, unsigned short);
static unsigned char find(unsigned char c)
{
    unsigned char i;
    for (i = 0; i < 4; i++)
        if (((DAT_a802cc80 >> (i * 4)) & 0xf) == c)
            break;
    return i;
}
void FUN_a014f374(unsigned char c, unsigned short v)
{
    unsigned char i = find(c);
    if (i < 4)
        FUN_a0138674(i, v);
}
