/* leon2m FUN_a0106b08 @ 0xa0106b08 (-mcpu=v8 -O2 -g)
 * This should produce the three bare calls and the register write sequence without the unnecessary do-while loop.
 */
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a0106920(unsigned char blk, unsigned char val);
extern void FUN_a010b6e4(void);
extern void FUN_4008e2a4(void);

#define REG_EAC8 (*(volatile unsigned int *)0xcf00eac8)
#define REG_E9C4 (*(volatile unsigned int *)0xcf00e9c4)

void FUN_a0106b08(unsigned char param)
{
    if (param <= 3) {
        FUN_a00f2298(param, 0x54, 0);
        FUN_a0106920(param, 1);
        FUN_4008e2a4();
        FUN_4008e2a4();
        FUN_4008e2a4();
        if (param == 0) {
            FUN_a010b6e4();
        }
        unsigned int tmp = REG_EAC8;
        REG_EAC8 &= ~0x10;
        REG_E9C4 &= ~0x80;
        REG_EAC8 = tmp & 0xff;
    }
}
