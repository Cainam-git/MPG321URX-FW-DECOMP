/* leon2m FUN_a01448fc @ 0xa01448fc-0xa014505c (472 words).
 * For channel ch (0..3; other values report "SYS remapping channel OOR" and use channel 0), with blk = bits
 * 12..15 of word 0 of its 0x78-byte record at 0xa802df30, returns t = byte 0x28 of entry blk of the 0x2a-byte table
 * at 0xa802e224 for t 0..0x27 (jump table at 0xe30a8) and 0x28 for larger t. For t = 2, 3, 8, 9, 0xe, 0xf, 0x14,
 * 0x15, 0x1c, 0x1d, 0x22 and 0x23 it returns t + 2 instead when FUN_a00fd820(blk) returns 0xb1 and
 * FUN_a0139114(FUN_a0142168(FUN_a012fc20())) returns 1.
 */
struct Rec { unsigned int top : 16; unsigned int f12 : 4; unsigned int low : 12; unsigned char rest[0x74]; };
struct Ent { unsigned char p[0x28]; unsigned char b28; unsigned char tail; };
extern struct Rec DAT_a802df30[4];
extern struct Ent DAT_a802e224[];
extern int FUN_a00df170();
extern char s_001a6dd8[];
extern unsigned char FUN_a00fd820(unsigned char);
extern unsigned char FUN_a012fc20(void);
extern unsigned char FUN_a0142168(unsigned char);
extern unsigned char FUN_a0139114(unsigned char);

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

static unsigned char test(unsigned char i)
{
    unsigned char r = 0;

    if (FUN_a00fd820(DAT_a802df30[i].f12) == 0xb1 && FUN_a0139114(FUN_a0142168(FUN_a012fc20())) == 1)
        r = 1;
    return r & 1;
}

unsigned char FUN_a01448fc(unsigned char ch)
{
    unsigned char i, r;

    i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    switch (DAT_a802e224[DAT_a802df30[i].f12].b28) {
    case 0x0: r = 0x0; break;
    case 0x1: r = 0x1; break;
    case 0x2: r = test(i) ? 0x4 : 0x2; break;
    case 0x3: r = test(i) ? 0x5 : 0x3; break;
    case 0x4: r = 0x4; break;
    case 0x5: r = 0x5; break;
    case 0x6: r = 0x6; break;
    case 0x7: r = 0x7; break;
    case 0x8: r = test(i) ? 0xa : 0x8; break;
    case 0x9: r = test(i) ? 0xb : 0x9; break;
    case 0xa: r = 0xa; break;
    case 0xb: r = 0xb; break;
    case 0xc: r = 0xc; break;
    case 0xd: r = 0xd; break;
    case 0xe: r = test(i) ? 0x10 : 0xe; break;
    case 0xf: r = test(i) ? 0x11 : 0xf; break;
    case 0x10: r = 0x10; break;
    case 0x11: r = 0x11; break;
    case 0x12: r = 0x12; break;
    case 0x13: r = 0x13; break;
    case 0x14: r = test(i) ? 0x16 : 0x14; break;
    case 0x15: r = test(i) ? 0x17 : 0x15; break;
    case 0x16: r = 0x16; break;
    case 0x17: r = 0x17; break;
    case 0x18: r = 0x18; break;
    case 0x19: r = 0x19; break;
    case 0x1a: r = 0x1a; break;
    case 0x1b: r = 0x1b; break;
    case 0x1c: r = test(i) ? 0x1e : 0x1c; break;
    case 0x1d: r = test(i) ? 0x1f : 0x1d; break;
    case 0x1e: r = 0x1e; break;
    case 0x1f: r = 0x1f; break;
    case 0x20: r = 0x20; break;
    case 0x21: r = 0x21; break;
    case 0x22: r = test(i) ? 0x24 : 0x22; break;
    case 0x23: r = test(i) ? 0x25 : 0x23; break;
    case 0x24: r = 0x24; break;
    case 0x25: r = 0x25; break;
    case 0x26: r = 0x26; break;
    case 0x27: r = 0x27; break;
    default: r = 0x28; break;
    }
    return r;
}
