/* FUN_a008a974 (leon2s 0xa008a974-0xa008a9b0, 60 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Writes 0xff to hardware register 0xcf011014, sets bits 5 and 6 of 0xcf011048, and writes the byte v to
 * 0xcf011058 and 0xcf01105c. FUN_a008a9b0 writes the same registers.
 */
#define REG_1014 (*(volatile unsigned int *)0xcf011014)
#define REG_1048 (*(volatile unsigned int *)0xcf011048)
#define REG_1058 (*(volatile unsigned int *)0xcf011058)
#define REG_105C (*(volatile unsigned int *)0xcf01105c)

void FUN_a008a974(unsigned char v)
{
    REG_1014 = 0xff;
    REG_1048 |= 0x60;
    REG_1058 = v;
    REG_105C = v;
}
