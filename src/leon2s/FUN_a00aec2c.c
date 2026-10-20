/* FUN_a00aec2c (leon2s 0xa00aec2c-0xa00aec50, 36 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns 1 when bit 2 of word 0x2d (byte offset 0xb4) of the register block pointed to by DAT_a807dc04 is
 * set, else 0. Source form: a result byte that starts at 0, returned as r & 1.
 */
extern volatile unsigned int *DAT_a807dc04;

unsigned char FUN_a00aec2c(void)
{
    unsigned char r = 0;

    if (DAT_a807dc04[0x2d] & 4)
        r = 1;
    return r & 1;
}
