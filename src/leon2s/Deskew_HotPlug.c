/* leon2s Deskew_HotPlug @ 0xa0077e7c (-mcpu=v8 -Os)
 * Prints the format DAT_a0067400 with phyidx & 0xff (FUN_a0073044), then for phyidx 0..3 sets bit phyidx of byte
 * 0xA80788D2 (switch); other values change nothing.
 */
extern int FUN_a0073044(const char *fmt, ...); /* 0xa0073044 */
extern unsigned char DAT_a80788d2;        /* 0xa80788d2 */
extern const char DAT_a0067400[];

void Deskew_HotPlug(int phyidx)
{
    phyidx &= 0xff;
    FUN_a0073044(DAT_a0067400, phyidx);
    switch (phyidx) {
        case 0: DAT_a80788d2 |= 1; break;
        case 1: DAT_a80788d2 |= 2; break;
        case 2: DAT_a80788d2 |= 4; break;
        case 3: DAT_a80788d2 |= 8; break;
    }
}
