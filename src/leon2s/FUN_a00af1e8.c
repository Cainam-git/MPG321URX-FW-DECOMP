/* FUN_a00af1e8 (leon2s, 0xa00af1e8-0xa00af320, 78 words). Flags -mcpu=v8 -Os -g.
 Code facts: twin of FUN_a00af320. If (u8)FUN_a00ad784(port) == 0 return 0. Reads regs 0xc, 0xd, 0x10, 0x11 through the index/data pair
 (a6c00(port,0x70,0), a6c00(port,0x73,idx), a6bb8(port,0x7a)); num = (r0 << 8) + r1, div = (r2 << 8) + r3 (u16, joined with add);
 returns the u8 quotient num / div, or 0 when div == 0.
 Fixes vs draft: BEHAVIOUR the draft returned num (not 0) when div == 0; bytes joined with + (fw add, not or); u8 result variable
 (an unsigned int result puts the quotient in %l1, fw %i0). Aids: none.
 */
extern int FUN_a00ad784(unsigned int);
extern unsigned int FUN_a00a6bb8(unsigned int, unsigned short);
extern void FUN_a00a6c00(unsigned int, unsigned short, unsigned int);

unsigned char FUN_a00af1e8(char param_1)
{
    unsigned short num;
    unsigned short div;
    unsigned int r0, r1, r2, r3;
    unsigned char result;

    if ((FUN_a00ad784(param_1 & 0xff) & 0xff) == 0) {
        return 0;
    }

    FUN_a00a6c00(param_1 & 0xff, 0x70, 0);
    FUN_a00a6c00(param_1 & 0xff, 0x73, 0xc);
    r0 = FUN_a00a6bb8(param_1 & 0xff, 0x7a);
    FUN_a00a6c00(param_1 & 0xff, 0x70, 0);
    FUN_a00a6c00(param_1 & 0xff, 0x73, 0xd);
    r1 = FUN_a00a6bb8(param_1 & 0xff, 0x7a);
    FUN_a00a6c00(param_1 & 0xff, 0x70, 0);
    FUN_a00a6c00(param_1 & 0xff, 0x73, 0x10);
    r2 = FUN_a00a6bb8(param_1 & 0xff, 0x7a);
    FUN_a00a6c00(param_1 & 0xff, 0x70, 0);
    FUN_a00a6c00(param_1 & 0xff, 0x73, 0x11);
    r3 = FUN_a00a6bb8(param_1 & 0xff, 0x7a);

    div = ((r2 & 0xff) << 8) + (r3 & 0xff);
    num = ((r0 & 0xff) << 8) + (r1 & 0xff);

    result = 0;
    if (div != 0) {
        result = num / div;
    }
    return result;
}
