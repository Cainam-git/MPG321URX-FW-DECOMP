/* leon2m FUN_a012629c @ 0xa012629c-0xa0126310 (29 words).
 * Finds the index i (0..7, 8 when none) of the lowest set bit of the byte m = 1, takes entry i of the table of
 * 3-byte entries at 0x001a4371 and fills out: halfword +0 = FUN_a00de444(entry byte 0), byte +2 = entry byte 2,
 * byte +3 = entry byte 1. No direct callers (address taken). The search runs on a byte variable initialised to 1;
 * GCC keeps the loop, so the firmware computes i = 0 at run time. Byte +3 is stored before byte +2 in the source.
 */
struct Ent3 { unsigned char b0, b1, b2; };
struct Out { unsigned short h0; unsigned char b2, b3; };
extern unsigned short FUN_a00de444(unsigned char n);
extern const struct Ent3 DAT_001a4371[];

void FUN_a012629c(struct Out *out)
{
    unsigned char m = 1;
    unsigned char i;

    for (i = 0; i <= 7; i++) {
        if (m & 1)
            break;
        m >>= 1;
    }
    out->h0 = FUN_a00de444(DAT_001a4371[i].b0);
    out->b3 = DAT_001a4371[i].b1;
    out->b2 = DAT_001a4371[i].b2;
}
