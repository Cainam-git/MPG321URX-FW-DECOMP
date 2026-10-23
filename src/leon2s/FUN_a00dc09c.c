/* FUN_a00dc09c (leon2s 0xa00dc09c-0xa00dc0a8, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns the byte DAT_a8078852.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. Same block of
 * one-statement accessors as FUN_a00dc034..FUN_a00dc09c.
 */
extern unsigned char DAT_a8078852;

unsigned char FUN_a00dc09c(void)
{
    return DAT_a8078852;
}
