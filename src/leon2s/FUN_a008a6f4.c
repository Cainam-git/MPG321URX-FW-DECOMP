/* leon2s FUN_a008a6f4 @ 0xa008a6f4 (-mcpu=v8 -Os -g)
 * Writes fixed values to the registers 0xCF0110C0, C4, D4, D8, DC, E0, E4, C8 and CC (in that order), then sets
 * 0xCF011024 = (0xCF011024 & 0x3F) | 0x40, 0xCF011100 = (0xCF011100 & 0x1F) | 0xE0 and clears bit 7 of 0xCF0114B4.
 * Each register is accessed through a volatile 32-bit macro.
 */
typedef unsigned int uint;

#define REG_cf0110c0 (*(volatile uint *)0xcf0110c0)
#define REG_cf0110c4 (*(volatile uint *)0xcf0110c4)
#define REG_cf0110d4 (*(volatile uint *)0xcf0110d4)
#define REG_cf0110d8 (*(volatile uint *)0xcf0110d8)
#define REG_cf0110dc (*(volatile uint *)0xcf0110dc)
#define REG_cf0110e0 (*(volatile uint *)0xcf0110e0)
#define REG_cf0110e4 (*(volatile uint *)0xcf0110e4)
#define REG_cf0110c8 (*(volatile uint *)0xcf0110c8)
#define REG_cf0110cc (*(volatile uint *)0xcf0110cc)
#define REG_cf011024 (*(volatile uint *)0xcf011024)
#define REG_cf011100 (*(volatile uint *)0xcf011100)
#define REG_cf0114b4 (*(volatile uint *)0xcf0114b4)

void FUN_a008a6f4(void)
{
    REG_cf0110c0 = 0xf4;
    REG_cf0110c4 = 4;
    REG_cf0110d4 = 0;
    REG_cf0110d8 = 0x18;
    REG_cf0110dc = 0x50;
    REG_cf0110e0 = 0xf0;
    REG_cf0110e4 = 0x54;
    REG_cf0110c8 = 0;
    REG_cf0110cc = 0x3f;
    REG_cf011024 = (REG_cf011024 & 0x3f) | 0x40;
    REG_cf011100 = (REG_cf011100 & 0x1f) | 0xe0;
    REG_cf0114b4 = REG_cf0114b4 & ~0x80;
}
