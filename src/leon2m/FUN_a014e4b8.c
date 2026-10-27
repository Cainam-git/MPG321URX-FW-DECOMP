/* leon2m FUN_a014e4b8
 * For channel ch (0..3, mapped by the inlined switch remap(); other values report "SYS remapping channel OOR"
 * and use channel 0), with blk = bits 12..15 of word 0 of its 0x78-byte record at 0xa802df30 and t = byte 0x28 of entry blk of the 0x2a-byte table at
 * 0xa802e224: writes register 0x37 = 0x16 (FUN_a00f1ad4), bit 0x80 of register 0x4a = 1 unless t <= 1, 0x1a or 0x1b
 * (FUN_a00f1b5c), register 0x36 = 0 and then 1, waits 20 (func_0x4008d1a0), and polls bit 0 of register 0x36 until
 * it reads 0, at most while func_0x4008d588 has advanced by less than 100. On time-out it returns 0. Otherwise it
 * stores (0x41:0x40) << 3 in *a, 0x3d:0x3c in *b, (0x3f:0x3e) << 3 in *c and 0x39:0x38 in *d (high:low register
 * bytes read with FUN_a00f1a90), calls FUN_a00f25f8(blk, 0x4c) and returns 1 when *a >= 300 and *b >= 200.
 * Source form: the shifted values are written '(h | low) * 8' (the shift form swaps the 'or' operands); the result is
 * an unsigned char r, 0 unless the poll succeeded, returned as 'r & 1' through one exit (the exit keeps the 'and').
 */
struct Rec { unsigned int top : 16; unsigned int f12 : 4; unsigned int low : 12; unsigned char rest[0x74]; };
struct Ent { unsigned char p[0x28]; unsigned char b28; unsigned char tail; };
extern struct Rec DAT_a802df30[4];
extern struct Ent DAT_a802e224[];
extern int FUN_a00df170();
extern char s_001a6dd8[];
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void FUN_a00f25f8(unsigned char blk, unsigned char reg);
extern void func_0x4008d1a0(int ms);
extern unsigned short func_0x4008d588(void);

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

unsigned char FUN_a014e4b8(unsigned char ch, unsigned short *a, unsigned short *b, unsigned short *c, unsigned short *d)
{
    unsigned char i, blk, t, done, x = 1;
    unsigned char r;
    unsigned short t0;
    unsigned int h;

    i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    blk = DAT_a802df30[i].f12;
    t = DAT_a802e224[blk].b28;
    if (t > 1 && t != 0x1a && t != 0x1b)
        x = 0;
    FUN_a00f1ad4(blk, 0x37, 0x16);
    if (x)
        FUN_a00f1b5c(blk, 0x4a, 0x80, 0);
    else
        FUN_a00f1b5c(blk, 0x4a, 0x80, 1);
    done = 0;
    FUN_a00f1ad4(blk, 0x36, 0);
    FUN_a00f1ad4(blk, 0x36, 1);
    func_0x4008d1a0(20);
    t0 = func_0x4008d588();
    do {
        if (!(FUN_a00f1a90(blk, 0x36) & 1)) {
            done = 1;
            break;
        }
    } while (func_0x4008d588() - t0 < 100);
    r = 0;
    if (done) {
        h = FUN_a00f1a90(blk, 0x41) << 8;
        *a = (h | FUN_a00f1a90(blk, 0x40)) * 8;
        h = FUN_a00f1a90(blk, 0x3d) << 8;
        *b = h | FUN_a00f1a90(blk, 0x3c);
        h = FUN_a00f1a90(blk, 0x3f) << 8;
        *c = (h | FUN_a00f1a90(blk, 0x3e)) * 8;
        h = FUN_a00f1a90(blk, 0x39) << 8;
        *d = h | FUN_a00f1a90(blk, 0x38);
        FUN_a00f25f8(blk, 0x4c);
        r = 1;
        if (*a < 300 || *b < 200)
            r = 0;
    }
    return r & 1;
}
