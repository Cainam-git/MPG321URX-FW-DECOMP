/* leon2m FUN_a00f3580 @ 0xa00f3580 (-mcpu=v8 -O3 -g)
 * Returns a byte: from the function pointer at DAT_a802b770 + 0x10 when the flag byte DAT_a802b770 is set and the
 * pointer is non-null, otherwise the low 6 bits of the hardware register 0xCF01281C.
 * DAT_a802b770 is the 0x24-byte record described in FUN_a00f3528.
 */
struct hooks {
    unsigned char on;
    void *f4;
    unsigned int (*f8)(void);
    void (*fc)(unsigned char);
    unsigned int (*f10)(void);
    void *f14, *f18, *f1c, *f20;
};
extern struct hooks DAT_a802b770;

unsigned char FUN_a00f3580(void)
{
    if (DAT_a802b770.on && DAT_a802b770.f10)
        return DAT_a802b770.f10();
    return *(volatile unsigned int *)0xcf01281c & 0x3f;
}
