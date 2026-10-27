/* FUN_a008b58c (leon2m 0xa008b58c-0xa008b5e0, 84 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the halfword (0x4e >> (4 - n)) >> s for n below 4, otherwise (0x4e << (n - 4)) >> s, n the byte
 * DAT_a802afb9 and s the byte DAT_a802afb8. Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between FUN_a008b380 and FUN_a008b5e0. Source form: an unsigned short result variable
 * set in each arm.
 */
extern unsigned char DAT_a802afb9, DAT_a802afb8;
unsigned short FUN_a008b58c(void)
{
    unsigned short r;
    if (DAT_a802afb9 < 4)
        r = (0x4e >> (4 - DAT_a802afb9)) >> DAT_a802afb8;
    else
        r = (0x4e << (DAT_a802afb9 - 4)) >> DAT_a802afb8;
    return r;
}
