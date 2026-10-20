/* leon2m FUN_a0132b8c @ 0xa0132b8c-0xa0132bfc (28 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * When byte 0xa802cb93 is 1: copies the first n bytes of the area 0xa802de40 to dst (n = byte 0xa802cb92, read
 * again on every step), clears byte 0xa802cb93 and returns 1. Otherwise returns 0. The result is returned as
 * (r & 1). FUN_a0132cd4 is the same with the bytes 0xa802cb8f / 0xa802cb8e.
 */
extern unsigned char DAT_a802cb93, DAT_a802cb92;
extern unsigned char DAT_a802de40[];

unsigned char FUN_a0132b8c(unsigned char *dst)
{
    unsigned char r = 0;
    unsigned char i;

    if (DAT_a802cb93 == 1) {
        for (i = 0; i < DAT_a802cb92; i++)
            dst[i] = DAT_a802de40[i];
        DAT_a802cb93 = 0;
        r = 1;
    }
    return r & 1;
}
