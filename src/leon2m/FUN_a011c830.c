/* leon2m FUN_a011c830 @ 0xa011c830-0xa011c8e4 (45 words).
 * Template FUN_a011c6c8: Writes 0x90, then the two bytes of v and 0 to one of two register sets, with a delay loop
 * before and after.
 * This function is the same code as FUN_a011c6c8 (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0x90 -> 0x70
 */
#define REG(a) (*(volatile unsigned int *)(a))

void FUN_a011c830(unsigned short v, unsigned char sel)
{
    int i;

    if (sel == 0)
        REG(0xcf011780) = 0x70;
    else
        REG(0xcf011794) = 0x70;
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
    if (v) {
    }
    if (sel == 0) {
        REG(0xcf011784) = v & 0xff;
        REG(0xcf011788) = v >> 8;
        REG(0xcf00bfcc) = 0;
    } else {
        REG(0xcf011798) = v & 0xff;
        REG(0xcf01179c) = v >> 8;
        REG(0xcf00c3cc) = 0;
    }
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}
