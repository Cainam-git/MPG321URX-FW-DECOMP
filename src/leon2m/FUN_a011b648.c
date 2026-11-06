/* leon2m FUN_a011b648 @ 0xa011b648-0xa011bac0 (286 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a0146c14.
 * FUN_a011b648(mode, a, b, n, sel) writes the register set of side sel (0: 0xcf011780.., other: 0xcf011794..) in
 * the same sequence as FUN_a011bed8: a += b * ARR_a802c9ca[sel]; start = DAT_a802c9a2[sel] - DAT_a802c9a0[sel]
 * (16 bits); 0x90 (mode == 1) or 0x40 to 0xcf011780 / 0xcf011794; the low and high byte of a to 0xcf011784 and
 * 0xcf011788 / 0xcf011798 and 0xcf01179c and 0 to 0xcf00bfcc / 0xcf00c3cc; then with c = DAT_a802c9a0[sel] and
 * k = low byte of ARR_a802c9a8[sel]: off = 0, n - c (k == 1) or (n - c) >> 1 (k == 2); off zero bytes, the c bytes
 * start + i, and zero bytes for i = c + off up to n, each through FUN_a011b3e8. Every register step is followed by
 * a 160-nop delay loop.
 * Source form: the step helpers are the firmware's own FUN_a011b4b0 (command byte) and FUN_a011b428 (address bytes
 * v & 0xff, (v >> 8) & 0xff, (v >> 16) & 0xff), defined here with FUN_a011b3e8 and inlined at -O3; the address is
 * the unsigned short addr = a, so the third register gets 0 (sll/srl 16 at 0xa011b6bc / 0xa011b83c); the body is
 * written twice, once for sel == 0 and once for the other side; start is computed before the address sum.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char DAT_a802c9a0[];
extern unsigned short DAT_a802c9a2[];
extern unsigned int ARR_a802c9a8[];
extern unsigned short ARR_a802c9ca[];

void FUN_a011b428(unsigned char c, unsigned int v)
{
    int i;

    if (c == 0) {
        *(volatile unsigned int *)0xcf011784 = v & 0xff;
        *(volatile unsigned int *)0xcf011788 = (v >> 8) & 0xff;
        *(volatile unsigned int *)0xcf00bfcc = (v >> 16) & 0xff;
    } else {
        *(volatile unsigned int *)0xcf011798 = v & 0xff;
        *(volatile unsigned int *)0xcf01179c = (v >> 8) & 0xff;
        *(volatile unsigned int *)0xcf00c3cc = (v >> 16) & 0xff;
    }
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}

void FUN_a011b4b0(unsigned char c, unsigned char v)
{
    int i;

    if (c == 0)
        R(0xcf011780) = v;
    else
        R(0xcf011794) = v;
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
    unsigned short addr;

    start = DAT_a802c9a2[sel] - DAT_a802c9a0[sel];
    b *= ARR_a802c9ca[sel];
    a += b;
    addr = a;
    if (sel == 0) {
        if (mode == 1)
            FUN_a011b4b0(0, 0x90);
        else
            FUN_a011b4b0(0, 0x40);
        FUN_a011b428(0, addr);
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
            FUN_a011b4b0(sel, 0x90);
        else
            FUN_a011b4b0(sel, 0x40);
        FUN_a011b428(sel, addr);
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
