/* leon2m FUN_a0123384 @ 0xa0123384-0xa01234b4 (76 words).
 * Hardware register sequence: 0xcf03c548 |= 0xc; 0xcf011814 = 0; then paged writes, each saving 0xcf03d024,
 * writing the page number there, writing the value to register (0x7600 + reg) of the 0xcf000000 | (n << 2)
 * window and restoring the saved low byte to 0xcf03d024: (page 0xc, reg 0x14, 0x44), (0xc, 0x12, 0x11),
 * (0, 0x03, 0xfb), (0xc, 0x11, 1); a 0x400-pass nop delay; (0xc, 0x11, 0); finally prints s_001a3090
 * "Vx1RxPowerOff\r\n" with FUN_a00df170 (tail call). Called by FUN_a00fd558 and FUN_a011d194.
 * Source form: the paged write is an inlined static helper with a local base 0x7600 (the firmware builds the
 * window address at run time, as in FUN_a0122e80). Compiler aid: the delay loop body is the documented
 * __asm__("nop"). volatile: hardware registers only.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern int FUN_a00df170(const char *fmt, ...);
extern const char s_001a3090[];

static void pwr(unsigned int page, unsigned int reg, unsigned int val)
{
    unsigned int x = R(0xcf03d024);
    unsigned int base = 0x7600;

    R(0xcf03d024) = page;
    R(0xcf000000 | ((base + reg) << 2)) = val;
    R(0xcf03d024) = x & 0xff;
}

void FUN_a0123384(void)
{
    unsigned short i;

    R(0xcf03c548) |= 0xc;
    R(0xcf011814) = 0;
    pwr(0xc, 0x14, 0x44);
    pwr(0xc, 0x12, 0x11);
    pwr(0, 0x03, 0xfb);
    pwr(0xc, 0x11, 1);
    for (i = 0; i < 0x400; i++)
        __asm__("nop");
    pwr(0xc, 0x11, 0);
    FUN_a00df170(s_001a3090);
}
