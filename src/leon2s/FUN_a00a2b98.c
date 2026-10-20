/* FUN_a00a2b98 (leon2s 0xa00a2b98-0xa00a2bec, 84 bytes, leaf), flags -mcpu=v8 -Os -g.
 * For both 0x34-byte port records ARR_a807db00[0..1] (u8 counter): in the register block pointed to by record
 * word 0, clears the upper halfword of word 0x2d (offset 0xb4) and the low byte of word 0x2e (offset 0xb8).
 * Returns 0.
 */
struct Port34 { volatile unsigned int *blk; unsigned char rest[0x30]; };
extern struct Port34 ARR_a807db00[];

int FUN_a00a2b98(void)
{
    unsigned char i;

    for (i = 0; i <= 1; i++) {
        volatile unsigned int *r = ARR_a807db00[i].blk;
        r[0x2d] &= 0xffff;
        r[0x2e] &= ~0xff;
    }
    return 0;
}
