/* leon2m FUN_a0149978 @ 0xa0149978-0xa0149b8c (133 words).
 * For display channel ch (0..3; other values report "SYS remapping channel OOR" and use channel 0) and port p, with
 * k = FUN_a01421c4(FUN_a0142218(FUN_a0125198(p))): calls FUN_a012f43c(ch, k, 0). When bit 23 of word 0xa802e3d0 is
 * set and k is 0x71, FUN_a01328d4(ch, b & 3) follows with b = byte 0xa802e3ee + ch. For channel 0, bit 21 of
 * 0xa802e3d0 adds FUN_a012f43c(3, k, 0). Ends with a tail call of FUN_a0142ea8 with bits 12..15 of word 0 of the
 * channel's 0x78-byte record at 0xa802df30.
 */
struct Rec { unsigned int top : 16; unsigned int f12 : 4; unsigned int low : 12; unsigned char rest[0x74]; };
struct Sys { unsigned int flags; unsigned char p04[0x1a]; unsigned char m[4]; };
extern struct Rec DAT_a802df30[4];
extern struct Sys DAT_a802e3d0;
extern int FUN_a00df170();
extern char s_001a6dd8[];
extern unsigned char FUN_a0125198(unsigned char);
extern unsigned char FUN_a0142218(unsigned char);
extern unsigned char FUN_a01421c4(unsigned char);
extern void FUN_a012f43c(unsigned char, unsigned char, int);
extern void FUN_a01328d4(int, int);
extern void FUN_a0142ea8(unsigned int);

static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

static unsigned char kind(unsigned char p)
{
    return FUN_a01421c4(FUN_a0142218(FUN_a0125198(p)));
}

void FUN_a0149978(unsigned char ch, unsigned char p)
{
    unsigned char i;

    i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    FUN_a012f43c(i, kind(p), 0);
    if ((DAT_a802e3d0.flags & 0x800000) && kind(p) == 0x71) {
        switch (i) {
        case 0: FUN_a01328d4(0, DAT_a802e3d0.m[0] & 3); break;
        case 1: FUN_a01328d4(1, DAT_a802e3d0.m[1] & 3); break;
        case 2: FUN_a01328d4(2, DAT_a802e3d0.m[2] & 3); break;
        case 3: FUN_a01328d4(3, DAT_a802e3d0.m[3] & 3); break;
        }
    }
    if (i == 0 && (DAT_a802e3d0.flags & 0x200000))
        FUN_a012f43c(3, kind(p), 0);
    if (i < 4)
        FUN_a0142ea8(DAT_a802df30[i].f12);
}
