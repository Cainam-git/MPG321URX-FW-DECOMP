/* FUN_a008a9b0 (leon2s 0xa008a9b0-0xa008a9ec, 60 bytes, leaf), flags -mcpu=v8 -Os -g.
 * When hardware register 0xcf011014 is non-zero: writes 0 to 0xcf011014 and 0xcf011048 and 0xc6 to 0xcf011058
 * and 0xcf01105c (the registers that FUN_a008a974 sets).
 */
#define REG_1014 (*(volatile unsigned int *)0xcf011014)
#define REG_1048 (*(volatile unsigned int *)0xcf011048)
#define REG_1058 (*(volatile unsigned int *)0xcf011058)
#define REG_105C (*(volatile unsigned int *)0xcf01105c)

void FUN_a008a9b0(void)
{
    if (REG_1014 != 0) {
        REG_1014 = 0;
        REG_1048 = 0;
        REG_1058 = 0xc6;
        REG_105C = 0xc6;
    }
}
