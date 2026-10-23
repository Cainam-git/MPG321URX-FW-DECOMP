/* leon2s FUN_a00ad478 @ 0xa00ad478-0xa00ad5a4, -mcpu=v8 -Os -g.
 * (u8 on), void. k = 1 when on != 0, else 8. FUN_a00acff4() when (u8)FUN_a00ad3e0(0) == 1 or
 * (u8)FUN_a00ad3e0(1) == 1. Writes 0x30 to 0xcf0132d8, k * 9 to 0xcf0132c4, k * 15 to 0xcf0132c8 and 1 to
 * 0xcf0132cc. For record r = 0, 1 of ARR_a807dc18 (0x12c bytes each) whose byte +0x11e is 1: FUN_a00ad054(1),
 * FUN_a00ad060(r). Then FUN_a00acff4(); for the same records bit r of DAT_a8079315 is cleared; last, 1 is
 * written to 0xcf0132c0.
 */
struct Port { unsigned char pad[0x11e]; unsigned char b11e; unsigned char rest[0x12c - 0x11f]; };
extern struct Port ARR_a807dc18[];
extern unsigned char DAT_a8079315;
extern int FUN_a00ad3e0(int);
extern void FUN_a00acff4(void);
extern void FUN_a00ad054(unsigned char);
extern void FUN_a00ad060(unsigned char);

#define REG_CF0132C0 (*(volatile unsigned int *)0xcf0132c0)
#define REG_CF0132C4 (*(volatile unsigned int *)0xcf0132c4)
#define REG_CF0132C8 (*(volatile unsigned int *)0xcf0132c8)
#define REG_CF0132CC (*(volatile unsigned int *)0xcf0132cc)
#define REG_CF0132D8 (*(volatile unsigned int *)0xcf0132d8)

void FUN_a00ad478(unsigned char on)
{
    unsigned char k;

    k = on ? 1 : 8;
    if ((FUN_a00ad3e0(0) & 0xff) == 1 || (FUN_a00ad3e0(1) & 0xff) == 1)
        FUN_a00acff4();
    REG_CF0132D8 = 0x30;
    REG_CF0132C4 = k * 9;
    REG_CF0132C8 = k * 15;
    REG_CF0132CC = 1;
    if (ARR_a807dc18[0].b11e == 1) {
        FUN_a00ad054(1);
        FUN_a00ad060(0);
    }
    if (ARR_a807dc18[1].b11e == 1) {
        FUN_a00ad054(1);
        FUN_a00ad060(1);
    }
    FUN_a00acff4();
    if (ARR_a807dc18[0].b11e == 1)
        DAT_a8079315 &= ~1;
    if (ARR_a807dc18[1].b11e == 1)
        DAT_a8079315 &= ~2;
    REG_CF0132C0 = 1;
}
