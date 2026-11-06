/* leon2m FUN_a011c6c8 @ 0xa011c6c8-0xa011c77c (45 words).
 * Writes 0x90 to hardware register 0xcf011780 (sel 0) or 0xcf011794 (other sel), waits in a delay loop, then writes
 * the low byte of v to 0xcf011784 / 0xcf011798 and the high byte to 0xcf011788 / 0xcf01179c, writes 0 to 0xcf00bfcc
 * (sel 0) or 0xcf00c3cc (other sel) and waits again. Source form: v is copied into the unsigned int local w right
 * before the second sel test; that copy gives the firmware's 16-bit narrowing of v (sll/srl) before the second
 * register block (with the uses of v in each arm GCC drops it).
 */
#define REG(a) (*(volatile unsigned int *)(a))

void FUN_a011c6c8(unsigned short v, unsigned char sel)
{
    int i;
    unsigned int w;

    if (sel == 0)
        REG(0xcf011780) = 0x90;
    else
        REG(0xcf011794) = 0x90;
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
    w = v;
    if (sel == 0) {
        REG(0xcf011784) = w & 0xff;
        REG(0xcf011788) = w >> 8;
        REG(0xcf00bfcc) = 0;
    } else {
        REG(0xcf011798) = w & 0xff;
        REG(0xcf01179c) = w >> 8;
        REG(0xcf00c3cc) = 0;
    }
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}
