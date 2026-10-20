/* leon2m FUN_a0139040 @ 0xa0139040-0xa0139114 (53 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a013dbcc. Maps mode
 * 0/1/2/3 to the command byte 2/3/4/5 (other modes leave it 0), sends the 4-byte buffer {byte, 0, 0, 0} with
 * FUN_a01370dc(0x71, 4, buf, 0) and runs FUN_a0137344(1). Then splits the words +4..+0x10 of the record at
 * 0xa802cb9c into halfwords (low half first) and stores them into out[0..7] (word +4 to out[0..1], +8 to out[6..7],
 * +0xc to out[2..3], +0x10 to out[4..5], written in that order). Same switch as FUN_a01381f0.
 */
struct Rcb9c { unsigned int w0, w4, w8, wc, w10; };
extern struct Rcb9c DAT_a802cb9c;
extern void FUN_a01370dc(int, int, unsigned char *, int);
extern void FUN_a0137344(int);

void FUN_a0139040(unsigned char mode, unsigned short *out)
{
    unsigned char buf[4] = {0};

    switch (mode) {
    case 1: buf[0] = 3; break;
    case 2: buf[0] = 4; break;
    case 3: buf[0] = 5; break;
    case 0: buf[0] = 2; break;
    }
    FUN_a01370dc(0x71, 4, buf, 0);
    FUN_a0137344(1);
    out[0] = DAT_a802cb9c.w4;
    out[1] = DAT_a802cb9c.w4 >> 16;
    out[6] = DAT_a802cb9c.w8;
    out[7] = DAT_a802cb9c.w8 >> 16;
    out[2] = DAT_a802cb9c.wc;
    out[3] = DAT_a802cb9c.wc >> 16;
    out[4] = DAT_a802cb9c.w10;
    out[5] = DAT_a802cb9c.w10 >> 16;
}
