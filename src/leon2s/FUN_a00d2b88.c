/* FUN_a00d2b88 (leon2s 0xa00d2b88-0xa00d2c38, 176 bytes), flags -mcpu=v8 -Os -g.
 * Leaf function returning a 0/1 change flag. The flag is set when the byte DAT_a8078c34 is 1 (which is then
 * cleared), when the byte DAT_a8078c38 is 0 or 4, and for each of three copies whose source differs from
 * the stored copy, which is then updated: word +4 of DAT_a807d548 into DAT_a8078c2c, halfword +0x1c of
 * DAT_a807d548 into DAT_a8078c28, halfword DAT_a80779dc into DAT_a80766ac.
 * Source forms: DAT_a807d548 is a structure (one base register for +4 and +0x1c); the 0/4 test is an
 * if/else-if pair; the result is an unsigned char returned as r & 1.
 */
struct rec_d548 {
    unsigned int w0;
    unsigned int w4;
    unsigned char _8[0x14];
    unsigned short h1c;
};
extern struct rec_d548 DAT_a807d548;
extern unsigned char DAT_a8078c34;
extern unsigned char DAT_a8078c38;
extern unsigned int DAT_a8078c2c;
extern unsigned short DAT_a8078c28;
extern unsigned short DAT_a80779dc;
extern unsigned short DAT_a80766ac;

unsigned char FUN_a00d2b88(void)
{
    unsigned char r = 0;

    if (DAT_a8078c34 == 1) {
        DAT_a8078c34 = 0;
        r = 1;
    }
    if (DAT_a8078c38 == 0)
        r = 1;
    else if (DAT_a8078c38 == 4)
        r = 1;
    if (DAT_a807d548.w4 != DAT_a8078c2c) {
        DAT_a8078c2c = DAT_a807d548.w4;
        r = 1;
    }
    if (DAT_a807d548.h1c != DAT_a8078c28) {
        DAT_a8078c28 = DAT_a807d548.h1c;
        r = 1;
    }
    if (DAT_a80766ac != DAT_a80779dc) {
        DAT_a80766ac = DAT_a80779dc;
        r = 1;
    }
    return r & 1;
}
