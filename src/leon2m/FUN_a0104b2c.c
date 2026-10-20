/* leon2m FUN_a0104b2c @ 0xa0104b2c-0xa0104c34 (66 words).
 * Calls FUN_a00f2298(blk, 0x54, 1), then writes val to hardware registers chosen by blk (jump table): 1, 2 and 3
 * write 0xcf013900, 0xcf013a00 and 0xcf013b00; 6 writes 0xcf01b000 and sets bit 7 of 0xcf01b07c; 7 writes 0xcf01b100
 * and sets bit 7 of 0xcf01b17c; 8 writes all six registers and sets both bits; 0 and every other value write
 * 0xcf013800. Called from FUN_a011d194.
 */
#define REG_cf013800 (*(volatile unsigned int *)0xcf013800)
#define REG_cf013900 (*(volatile unsigned int *)0xcf013900)
#define REG_cf013a00 (*(volatile unsigned int *)0xcf013a00)
#define REG_cf013b00 (*(volatile unsigned int *)0xcf013b00)
#define REG_cf01b000 (*(volatile unsigned int *)0xcf01b000)
#define REG_cf01b07c (*(volatile unsigned int *)0xcf01b07c)
#define REG_cf01b100 (*(volatile unsigned int *)0xcf01b100)
#define REG_cf01b17c (*(volatile unsigned int *)0xcf01b17c)

extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);

void FUN_a0104b2c(unsigned char blk, unsigned char val)
{
    FUN_a00f2298(blk, 0x54, 1);
    switch (blk) {
    case 0:
    default:
        REG_cf013800 = val;
        break;
    case 1:
        REG_cf013900 = val;
        break;
    case 2:
        REG_cf013a00 = val;
        break;
    case 3:
        REG_cf013b00 = val;
        break;
    case 6:
        REG_cf01b000 = val;
        REG_cf01b07c |= 0x80;
        break;
    case 7:
        REG_cf01b100 = val;
        REG_cf01b17c |= 0x80;
        break;
    case 8:
        REG_cf013800 = val;
        REG_cf013900 = val;
        REG_cf013a00 = val;
        REG_cf013b00 = val;
        REG_cf01b000 = val;
        REG_cf01b100 = val;
        REG_cf01b07c |= 0x80;
        REG_cf01b17c |= 0x80;
        break;
    }
}
