/* leon2m FUN_a0137fcc @ 0xa0137fcc-0xa013805c (36 words).
 * Sends the 4-byte buffer {mode, 0, 0, 0} with FUN_a01370dc(0x45, 4, buffer, 0) and calls FUN_a0137344(1). Then,
 * from the words w1 = 0xa802cba0 and w2 = 0xa802cba4, it stores four sums of byte pairs into out[0..3]:
 * out[0] = byte 0 + byte 1 of w1, out[1] = byte 2 + byte 3 of w1, out[2] and out[3] likewise from w2 (byte 0 is the
 * least significant). Same command pattern as FUN_a01381f0.
 */
extern int FUN_a01370dc();
extern void FUN_a0137344(int);
extern unsigned int DAT_a802cb9c[];

void FUN_a0137fcc(unsigned char mode, unsigned short *out)
{
    unsigned char buf[4] = {0};
    unsigned int w1, w2;

    buf[0] = mode;
    FUN_a01370dc(0x45, 4, buf, 0);
    FUN_a0137344(1);
    w1 = DAT_a802cb9c[1];
    w2 = DAT_a802cb9c[2];
    out[0] = (w1 & 0xff) + ((w1 >> 8) & 0xff);
    out[1] = ((w1 >> 16) & 0xff) + (w1 >> 24);
    out[2] = (w2 & 0xff) + ((w2 >> 8) & 0xff);
    out[3] = ((w2 >> 16) & 0xff) + (w2 >> 24);
}
