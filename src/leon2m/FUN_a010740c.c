/* leon2m FUN_a010740c @ 0xa010740c-0xa0107554 (-mcpu=v8 -O3 -g). No direct callers found.
 * Parameters (c, a, b). By c, writes the register pairs 0xcf00e9f8 / 0xcf00eab8 and 0xcf00e9fc / 0xcf00eabc and
 * updates 0xcf00e9e8, then copies 0xcf00e9e8 to 0xcf00eaa8:
 * c = 0: 0x10 to e9f8 and eab8, clears bit 3 and sets bit 0 of e9e8; c = 1: the same with 0x90;
 * c = 2: 0 to e9f8 and eab8, ((a & 3) << 4) | (b & 7) to e9fc and eabc, sets bit 3 of e9e8;
 * c = 3: 0xf4 to e9f8 and eab8, e9e8 = (e9e8 & 0xf) | ((a & 0xf) << 4), then clears bit 3 and sets bit 0;
 * other c: clears bits 0 and 3 of e9e8.
 * Source form: in the c = 2 case, (a & 3) << 4 is computed into its own variable before the two stores of 0.
 */
#define R1E8 (*(volatile unsigned int *)0xcf00e9e8)
#define R1F8 (*(volatile unsigned int *)0xcf00e9f8)
#define R1FC (*(volatile unsigned int *)0xcf00e9fc)
#define R2A8 (*(volatile unsigned int *)0xcf00eaa8)
#define R2B8 (*(volatile unsigned int *)0xcf00eab8)
#define R2BC (*(volatile unsigned int *)0xcf00eabc)

void FUN_a010740c(unsigned int c, unsigned int a, unsigned int b)
{
    unsigned int x;
    unsigned int y;

    switch (c) {
    case 0:
        R1F8 = 0x10;
        R2B8 = 0x10;
        R1E8 &= ~8u;
        R1E8 |= 1;
        R2A8 = R1E8;
        break;
    case 1:
        R1F8 = 0x90;
        R2B8 = 0x90;
        R1E8 &= ~8u;
        R1E8 |= 1;
        R2A8 = R1E8;
        break;
    case 2:
        y = (a & 3) << 4;
        R1F8 = 0;
        R2B8 = 0;
        x = y | (b & 7);
        R1FC = x;
        R2BC = x;
        R1E8 |= 8;
        R2A8 = R1E8;
        break;
    case 3:
        R1F8 = 0xf4;
        R2B8 = 0xf4;
        R1E8 &= 0xf;
        R1E8 |= (a & 0xf) << 4;
        R1E8 &= ~8u;
        R1E8 |= 1;
        R2A8 = R1E8;
        break;
    default:
        R1E8 &= ~9u;
        R2A8 = R1E8;
        break;
    }
}
