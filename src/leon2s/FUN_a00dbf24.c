/* FUN_a00dbf24 (leon2s 0xa00dbf24-0xa00dc034, 272 bytes), flags -mcpu=v8 -Os -g.
 * Leaf. Only when DAT_a8078832 is 0: clears the byte DAT_a807883e and adds to it, for four pairs of 4-bit
 * ring indices (wr, rd), wr - rd when wr >= rd and wr - rd + 0x10 otherwise. Pairs: DAT_a8078830[x] /
 * DAT_a8078828[x], DAT_a8078808[x] / DAT_a8078800[x] (x = DAT_a8078832, reloaded after the first store),
 * DAT_a80787ff / DAT_a80787fe and DAT_a80787fd / DAT_a80787fc.
 * Source forms: one static inline helper (wr, rd) used four times; the test is written wr >= rd with the
 * no-wrap arm first.
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a807883e;
extern unsigned char DAT_a8078828[];
extern unsigned char DAT_a8078830[];
extern unsigned char DAT_a8078800[];
extern unsigned char DAT_a8078808[];
extern unsigned char DAT_a80787fc;
extern unsigned char DAT_a80787fd;
extern unsigned char DAT_a80787fe;
extern unsigned char DAT_a80787ff;

static inline void add_used(unsigned char wr, unsigned char rd)
{
    if (wr >= rd)
        DAT_a807883e += wr - rd;
    else
        DAT_a807883e += wr - rd + 0x10;
}

void FUN_a00dbf24(void)
{
    if (DAT_a8078832 == 0) {
        DAT_a807883e = 0;
        add_used(DAT_a8078830[DAT_a8078832], DAT_a8078828[DAT_a8078832]);
        add_used(DAT_a8078808[DAT_a8078832], DAT_a8078800[DAT_a8078832]);
        add_used(DAT_a80787ff, DAT_a80787fe);
        add_used(DAT_a80787fd, DAT_a80787fc);
    }
}
