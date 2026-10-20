/* leon2m FUN_a014737c @ 0xa014737c-0xa01474b0 (77 words).
 * For display channel ch (0..3; other values report "SYS remapping channel OOR" and use record 0) whose bits 4..7 in
 * word 0 of its 0x78-byte record at 0xa802df30 are not 4: keeps byte 0xa802b7b4 (FUN_a00f6cf4), passes bits 4..7 to
 * FUN_a00f63bc, calls FUN_a00f7894 with the 3-byte structure {a, b, m} passed by value, where m is 4,
 * 8 or 0x20 for mode 0, 1 or 3 and 0x10 otherwise, then passes the kept value to FUN_a00f63bc again.
 */
struct Chan { unsigned int hi24 : 24; unsigned int f4 : 4; unsigned int lo4 : 4; unsigned char rest[0x74]; };
struct Arg { unsigned char a, b, m; };
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170();
extern char s_001a6dd8[];
extern unsigned char FUN_a00f6cf4(void);
extern void FUN_a00f63bc(unsigned char);
extern void FUN_a00f7894(struct Arg);

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

void FUN_a014737c(unsigned char ch, unsigned char mode, unsigned char a, unsigned char b)
{
    unsigned char i, m, old;
    struct Arg s;

    i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    if (DAT_a802df30[i].f4 != 4) {
        switch (mode) {
        case 0: m = 4; break;
        case 1: m = 8; break;
        case 3: m = 0x20; break;
        default: m = 0x10; break;
        }
        old = FUN_a00f6cf4();
        s.m = m;
        s.b = b;
        s.a = a;
        FUN_a00f63bc(DAT_a802df30[i].f4);
        FUN_a00f7894(s);
        FUN_a00f63bc(old);
    }
}
