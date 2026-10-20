/* leon2m FUN_a00f37d0 @ 0xa00f37d0 (-mcpu=v8 -O3 -g)
 * Writes the byte v to the hardware register 0xCF01281C, then passes v to the function pointer at
 * DAT_a802b770 + 0xC when the flag byte DAT_a802b770 is set and the pointer is non-null.
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

void FUN_a00f37d0(unsigned char v)
{
    *(volatile unsigned int *)0xcf01281c = v;
    if (DAT_a802b770.on && DAT_a802b770.fc)
        DAT_a802b770.fc(v);
}
