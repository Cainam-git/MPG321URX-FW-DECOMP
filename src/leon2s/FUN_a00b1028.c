/* leon2s FUN_a00b1028 @ 0xa00b1028-0xa00b115c, -mcpu=v8 -Os -g.
 * (u8 port, u8 flag), void. FUN_a00b0540(port). When (u8)FUN_a008d800() > 0x81: bit 7 of 0xcf0147f0 is set
 * and DAT_a8078768[0..4] = 0, 2, 4, 6, 5. FUN_a0083e34 gets FUN_a00aba4c() (flag != 0) or byte +0x119 of the
 * 0x12c-byte record ARR_a807dc18[port]. Then FUN_a00b0e54(), FUN_a00a7058(port, 0x3e, 1, 0),
 * FUN_a00b05e8(port, 1), FUN_a00ad478(0), bits 3, 4 and 6 of 0xcf00f21c cleared, FUN_a00afbbc(port),
 * FUN_a00a6c98(port, 0x20, 2, 1) and (.., 0), FUN_a00a7058(port, 0x3e, 1, 1), FUN_a00b0518(port), and
 * DAT_a807de71 = 0.
 * Source form: the byte stores in the order 1, 2, 0, 3, 4.
 */
struct Port { unsigned char pad[0x119]; unsigned char b119; unsigned char rest[0x12c - 0x11a]; };
extern struct Port ARR_a807dc18[];
extern unsigned char DAT_a8078768[];
extern unsigned char DAT_a807de71;
extern void FUN_a00b0540(unsigned char);
extern unsigned char FUN_a008d800(void);
extern unsigned int FUN_a00aba4c(void);
extern void FUN_a0083e34(unsigned char);
extern void FUN_a00b0e54(void);
extern void FUN_a00a7058(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00b05e8(unsigned char, unsigned char);
extern void FUN_a00ad478(unsigned char);
extern void FUN_a00afbbc(unsigned char);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00b0518(unsigned char);

#define REG_CF0147F0 (*(volatile unsigned int *)0xcf0147f0)
#define REG_CF00F21C (*(volatile unsigned int *)0xcf00f21c)

void FUN_a00b1028(unsigned char port, unsigned char flag)
{
    FUN_a00b0540(port);
    if (FUN_a008d800() > 0x81) {
        REG_CF0147F0 |= 0x80;
        DAT_a8078768[1] = 2;
        DAT_a8078768[2] = 4;
        DAT_a8078768[0] = 0;
        DAT_a8078768[3] = 6;
        DAT_a8078768[4] = 5;
    }
    if (flag)
        FUN_a0083e34(FUN_a00aba4c());
    else
        FUN_a0083e34(ARR_a807dc18[port].b119);
    FUN_a00b0e54();
    FUN_a00a7058(port, 0x3e, 1, 0);
    FUN_a00b05e8(port, 1);
    FUN_a00ad478(0);
    REG_CF00F21C &= ~0x58;
    FUN_a00afbbc(port);
    FUN_a00a6c98(port, 0x20, 2, 1);
    FUN_a00a6c98(port, 0x20, 2, 0);
    FUN_a00a7058(port, 0x3e, 1, 1);
    FUN_a00b0518(port);
    DAT_a807de71 = 0;
}
