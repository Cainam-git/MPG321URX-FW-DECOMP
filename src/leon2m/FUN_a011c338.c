/* FUN_a011c338: writes the n bytes p[0..n-1] (u8 count) through the serial register port of side sel (0 or
 * other). Register set of side 0 / other: command 0xcf011780 / 0xcf011794, address bytes 0xcf011784+0xcf011788 /
 * 0xcf011798+0xcf01179c, strobe 0xcf00bfcc / 0xcf00c3cc (written 0), data byte 0xcf01178c / 0xcf0117a0; each
 * step is followed by a 160-nop delay loop. Command 0x90 when mode == 1, else 0x40; address
 * a + b * ARR_a802c9ca[sel] (16 bits); then the bytes through FUN_a011b3e8. Caller: FUN_a0146af4.
 * The command and address steps are static helpers and FUN_a011b3e8 is defined here; GCC inlines them at -O3.
 * Compiler aid: the empty statement 'if (a) { }' in the address helper emits no instructions; as in FUN_a011c6c8
 * it keeps the firmware's 16-bit narrowing of the address before the register writes.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

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

    if (a) {
    }
    if (sel == 0) {
        R(0xcf011784) = a & 0xff;
        R(0xcf011788) = a >> 8;
        R(0xcf00bfcc) = 0;
    } else {
        R(0xcf011798) = a & 0xff;
        R(0xcf01179c) = a >> 8;
        R(0xcf00c3cc) = 0;
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

void FUN_a011c338(unsigned char mode, unsigned int a, unsigned int b, unsigned char n, unsigned char *p,
                  unsigned char sel)
{
    unsigned char i;

    b *= ARR_a802c9ca[sel];
    a += b;
    if (mode == 1)
        cmd(sel, 0x90);
    else
        cmd(sel, 0x40);
    addr16(sel, a);
    for (i = 0; i < n; i++)
        FUN_a011b3e8(sel, p[i]);
}
