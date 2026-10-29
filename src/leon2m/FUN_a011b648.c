/* leon2m FUN_a011b648 @ 0xa011b648-0xa011bac0 (286 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a0146c14.
 * FUN_a011b648(mode, a, b, n, sel) uses the serial register port of side sel (0 or other) as FUN_a011bed8 does:
 * a += b * ARR_a802c9ca[sel]; start = DAT_a802c9a2[sel] - DAT_a802c9a0[sel] (16 bits); command 0x90 when mode == 1,
 * else 0x40; the 16-bit address a; then with c = DAT_a802c9a0[sel] and k = low byte of ARR_a802c9a8[sel]:
 * off = 0, n - c (k == 1) or (n - c) >> 1 (k == 2); off zero bytes, the c bytes start + i, and zero bytes for
 * i = c + off up to n, each through FUN_a011b3e8. Every port step is followed by a 160-nop delay loop.
 * Source form: the port helpers are static (FUN_a011b3e8 is defined here) and inlined; the body is written twice,
 * once for sel == 0 and once for the other side; start is computed before the address sum.
 * Compiler aid: the address writes sit under 'if (!(a & 0x10000))', which is always true for the 16-bit a; the
 * test emits no instructions, but it keeps the 16-bit zero extension of a apart from its two uses until combine,
 * which gives the firmware's 'sll 16; srl 16; and 0xff' sequence.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char DAT_a802c9a0[];
extern unsigned short DAT_a802c9a2[];
extern unsigned int ARR_a802c9a8[];
extern unsigned short ARR_a802c9ca[];

static void cmd(unsigned char sel, unsigned char c)
{
    int i;

    if (sel == 0)
        R(0xcf011780) = c;
    else
        R(0xcf011794) = c;
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}

static void addr16(unsigned char sel, unsigned short a)
{
    int i;

    if (!(a & 0x10000)) {
        if (sel == 0) {
            R(0xcf011784) = a & 0xff;
            R(0xcf011788) = a >> 8;
            R(0xcf00bfcc) = 0;
        } else {
            R(0xcf011798) = a & 0xff;
            R(0xcf01179c) = a >> 8;
            R(0xcf00c3cc) = 0;
        }
    }
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}

void FUN_a011b3e8(unsigned char sel, unsigned char v)
{
    int i;

    if (sel == 0)
        R(0xcf01178c) = v;
    else
        R(0xcf0117a0) = v;
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}

void FUN_a011b648(unsigned char mode, unsigned int a, unsigned int b, unsigned char n, unsigned char sel)
{
    unsigned char i, off;
    unsigned int k;
    unsigned short start;

    start = DAT_a802c9a2[sel] - DAT_a802c9a0[sel];
    b *= ARR_a802c9ca[sel];
    a += b;
    if (sel == 0) {
        if (mode == 1)
            cmd(0, 0x90);
        else
            cmd(0, 0x40);
        addr16(0, a);
        off = 0;
        k = (unsigned char)ARR_a802c9a8[0];
        if ((unsigned char)k != 0) {
            if ((unsigned char)k == 1)
                off = n - DAT_a802c9a0[0];
            else if ((unsigned char)k == 2)
                off = (n - DAT_a802c9a0[0]) >> 1;
        }
        for (i = 0; i < off; i++)
            FUN_a011b3e8(0, 0);
        for (i = 0; i < DAT_a802c9a0[0]; i++)
            FUN_a011b3e8(0, start + i);
        for (i = DAT_a802c9a0[0] + off; i < n; i++)
            FUN_a011b3e8(0, 0);
    } else {
        if (mode == 1)
            cmd(sel, 0x90);
        else
            cmd(sel, 0x40);
        addr16(sel, a);
        off = 0;
        k = (unsigned char)ARR_a802c9a8[sel];
        if ((unsigned char)k != 0) {
            if ((unsigned char)k == 1)
                off = n - DAT_a802c9a0[sel];
            else if ((unsigned char)k == 2)
                off = (n - DAT_a802c9a0[sel]) >> 1;
        }
        for (i = 0; i < off; i++)
            FUN_a011b3e8(sel, 0);
        for (i = 0; i < DAT_a802c9a0[sel]; i++)
            FUN_a011b3e8(sel, start + i);
        for (i = DAT_a802c9a0[sel] + off; i < n; i++)
            FUN_a011b3e8(sel, 0);
    }
}
