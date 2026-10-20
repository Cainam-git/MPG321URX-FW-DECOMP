/* leon2m FUN_a00f3528 @ 0xa00f3528 (-mcpu=v8 -O3 -g)
 * Returns a 16-bit value: from the function pointer at DAT_a802b770 + 8 when the flag byte DAT_a802b770 is set and
 * the pointer is non-null, otherwise the register pair at 0xCF012820 read with FUN_a00f3078.
 * DAT_a802b770 is a 0x24-byte record (flag byte, then function pointers at +4..+0x20) that FUN_a00f32d8 copies in.
 * Two early returns (not one variable) give the firmware's register use after the calls.
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
extern unsigned int FUN_a00f3078(volatile unsigned int *p);

unsigned short FUN_a00f3528(void)
{
    if (DAT_a802b770.on && DAT_a802b770.f8)
        return DAT_a802b770.f8();
    return FUN_a00f3078((volatile unsigned int *)0xcf012820);
}
