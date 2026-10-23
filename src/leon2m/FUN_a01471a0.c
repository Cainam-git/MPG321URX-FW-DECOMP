/* leon2m FUN_a01471a0 @ 0xa01471a0-0xa014737c (119 words).
 * For channel ch (0..3; other values report "SYS remapping channel OOR" and use channel 0) whose bits 4..7
 * in word 0 of its 0x78-byte record at 0xa802df30 are not 4: passes those bits to FUN_a00f63bc, then dispatches on
 * item (jump table at 0xe3398) with value v: items 0..8 tail-call FUN_a00f6d80, FUN_a00f6dd8, FUN_a00f6e30,
 * FUN_a00f6e88, FUN_a00f6ecc, FUN_a00f6f10, FUN_a00f6f54, FUN_a00f6f7c and FUN_a00f6f94 with v; item 9
 * FUN_a0150a98(v); items 10..12 FUN_a0150b08(0..2, v); item 13 FUN_a00f6834(8, v); item 15 FUN_a0150b8c(m & 7) with
 * m = v for v 0..5 and 6 otherwise (jump table at 0xe3380). Item 14 and items above 15 do nothing.
 */
struct Chan { unsigned int hi24 : 24; unsigned int f4 : 4; unsigned int lo4 : 4; unsigned char rest[0x74]; };
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170();
extern char s_001a6dd8[];
extern void FUN_a00f63bc(unsigned char);
extern void FUN_a00f6d80(unsigned char);
extern void FUN_a00f6dd8(unsigned char);
extern void FUN_a00f6e30(unsigned char);
extern void FUN_a00f6e88(unsigned char);
extern void FUN_a00f6ecc(unsigned char);
extern void FUN_a00f6f10(unsigned char);
extern void FUN_a00f6f54(unsigned char);
extern void FUN_a00f6f7c(unsigned char);
extern void FUN_a00f6f94(unsigned char);
extern void FUN_a0150a98(unsigned char);
extern void FUN_a0150b08(int, unsigned char);
extern void FUN_a00f6834(int, unsigned char);
extern void FUN_a0150b8c(int);

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

void FUN_a01471a0(unsigned char ch, unsigned char item, unsigned char v)
{
    unsigned char i, m;

    i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    if (DAT_a802df30[i].f4 == 4)
        return;
    FUN_a00f63bc(DAT_a802df30[i].f4);
    if (i == 0xff)
        return;
    switch (item) {
    case 0: FUN_a00f6d80(v); break;
    case 1: FUN_a00f6dd8(v); break;
    case 2: FUN_a00f6e30(v); break;
    case 3: FUN_a00f6e88(v); break;
    case 4: FUN_a00f6ecc(v); break;
    case 5: FUN_a00f6f10(v); break;
    case 6: FUN_a00f6f54(v); break;
    case 7: FUN_a00f6f7c(v); break;
    case 8: FUN_a00f6f94(v); break;
    case 9: FUN_a0150a98(v); break;
    case 10: FUN_a0150b08(0, v); break;
    case 11: FUN_a0150b08(1, v); break;
    case 12: FUN_a0150b08(2, v); break;
    case 13: FUN_a00f6834(8, v); break;
    case 15:
        switch (v) {
        case 0: m = 0; break;
        case 1: m = 1; break;
        case 2: m = 2; break;
        case 3: m = 3; break;
        case 4: m = 4; break;
        case 5: m = 5; break;
        default: m = 6; break;
        }
        FUN_a0150b8c(m & 7);
        break;
    }
}
