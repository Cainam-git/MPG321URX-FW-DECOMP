/* leon2m FUN_a00f36b8 @ 0xa00f36b8  MATCH (-mcpu=v8 -O3 -g -msoft-float)
 * Reads the 13-bit count c = FUN_a00f21f0(blk, 0x12) & 0x1FFF and, comparing (float)c with 3840.0 and 1920.0
 * (soft-float calls), writes 0xA (above 3840), 0xB (above 1920) or 0xC to the hardware register 0xCF012844.
 * Clears bit 5 of 0xCF012804, stores c << 13 in DAT_a802b794 (-1 when c is 0 or 0x1FFF), writes val to the
 * register pair 0xCF012820 (FUN_a00f308c), and passes (blk, val) to the function pointer at DAT_a802b770 + 4 when
 * the flag byte DAT_a802b770 is set and the pointer is non-null (record described in FUN_a00f3528).
 * Callers: FUN_a00f42b8, FUN_a0121714. The float conversion is written from (int)c.
 */
#define R(a) (*(volatile unsigned int *)(a))

struct hooks {
    unsigned char on;
    void (*f4)(unsigned char, unsigned short);
    unsigned int (*f8)(void);
    void (*fc)(unsigned char);
    unsigned int (*f10)(void);
    void *f14, *f18, *f1c, *f20;
};
extern struct hooks DAT_a802b770;
extern int DAT_a802b794;
extern unsigned short FUN_a00f21f0(unsigned char blk, unsigned char reg);
extern void FUN_a00f308c(volatile unsigned int *r, unsigned int v);

void FUN_a00f36b8(unsigned char blk, unsigned short val)
{
    unsigned short c = FUN_a00f21f0(blk, 0x12) & 0x1fff;
    float f = (int)c;

    if (f > 3840.0f)
        R(0xcf012844) = 0xa;
    else if (f > 1920.0f)
        R(0xcf012844) = 0xb;
    else
        R(0xcf012844) = 0xc;
    R(0xcf012804) &= ~0x20;
    if (c == 0x1fff || c == 0)
        DAT_a802b794 = -1;
    else
        DAT_a802b794 = c << 13;
    FUN_a00f308c((volatile unsigned int *)0xcf012820, val);
    if (DAT_a802b770.on && DAT_a802b770.f4)
        DAT_a802b770.f4(blk, val);
}
