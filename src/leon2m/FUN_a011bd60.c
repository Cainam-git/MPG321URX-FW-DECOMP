/* FUN_a011bd60: writes n 16-bit values from p to the serial register port of side sel (0 or other).
 * Register set of side 0 / other: command 0xcf011780 / 0xcf011794, address bytes 0xcf011784+0xcf011788 /
 * 0xcf011798+0xcf01179c, strobe 0xcf00bfcc / 0xcf00c3cc (written 0), data byte 0xcf01178c / 0xcf0117a0; each
 * write is followed by a 160-nop delay loop. Sequence: command 0x70, address a + b * ARR_a802c9ca[sel] (16 bits),
 * then for each of the n values (u8 count) its low byte and its high byte through FUN_a011b3e8.
 * Caller: FUN_a0146ab0. The command/address helper is the same sequence as FUN_a011c6c8 (static, inlined);
 * FUN_a011b3e8 is defined here because GCC inlines it at -O3.
 * Exact form: b *= ARR_a802c9ca[sel] as its own statement (keeps the product in b's register); the helper takes
 * sel as unsigned int. Compiler aid: the empty statement 'if (a) { }' in the helper emits no instructions; as in
 * FUN_a011c6c8 it keeps the firmware's 16-bit narrowing of the address before the second register block.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned short ARR_a802c9ca[];

static void cmdaddr(unsigned int sel, unsigned char c, unsigned short a)
{
    int i;

    if (sel == 0)
        R(0xcf011780) = c;
    else
        R(0xcf011794) = c;
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
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

void FUN_a011bd60(unsigned int a, unsigned int b, unsigned char n, unsigned short *p, unsigned char sel)
{
    unsigned char i;

    b *= ARR_a802c9ca[sel];
    cmdaddr(sel, 0x70, a + b);
    for (i = 0; i < n; i++) {
        FUN_a011b3e8(sel, *p);
        FUN_a011b3e8(sel, *p >> 8);
        p++;
    }
}
