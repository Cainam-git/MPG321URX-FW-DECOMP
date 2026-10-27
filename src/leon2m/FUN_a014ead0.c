/* FUN_a014ead0 (leon2m 0xa014ead0-0xa014eb14, 68 bytes, leaf), flags -mcpu=v8 -O3.
 * Returns the index (0..3) of the first four-bit field of the halfword DAT_a802cc80 (lowest first) that equals c,
 * or 4 when none does. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It
 * lies between FUN_a014eaa8 and FUN_a014eb14.
 */
extern unsigned short DAT_a802cc80;

unsigned char FUN_a014ead0(unsigned char c)
{
    unsigned char i;

    for (i = 0; i < 4; i++)
        if (((DAT_a802cc80 >> (i * 4)) & 0xf) == c)
            break;
    return i;
}
