/* leon2m FUN_a00ddae4 @ 0xa00ddae4-0xa00ddbe0 (63 words).
 * Returns the low byte of hardware register n (1..8: 0xcf03cf14..0xcf03cf30, 9: 0xcf03cf54, 10: 0xcf03cf58);
 * n = 0 and n > 10 return 0xff. Cases 1..10 are listed before case 0; v is an unsigned char.
 */
#define REG_cf03cf14 (*(volatile unsigned int *)0xcf03cf14)
#define REG_cf03cf18 (*(volatile unsigned int *)0xcf03cf18)
#define REG_cf03cf1c (*(volatile unsigned int *)0xcf03cf1c)
#define REG_cf03cf20 (*(volatile unsigned int *)0xcf03cf20)
#define REG_cf03cf24 (*(volatile unsigned int *)0xcf03cf24)
#define REG_cf03cf28 (*(volatile unsigned int *)0xcf03cf28)
#define REG_cf03cf2c (*(volatile unsigned int *)0xcf03cf2c)
#define REG_cf03cf30 (*(volatile unsigned int *)0xcf03cf30)
#define REG_cf03cf54 (*(volatile unsigned int *)0xcf03cf54)
#define REG_cf03cf58 (*(volatile unsigned int *)0xcf03cf58)

unsigned char FUN_a00ddae4(unsigned char n)
{
    unsigned char v;

    switch (n) {
    case 1: v = REG_cf03cf14; break;
    case 2: v = REG_cf03cf18; break;
    case 3: v = REG_cf03cf1c; break;
    case 4: v = REG_cf03cf20; break;
    case 5: v = REG_cf03cf24; break;
    case 6: v = REG_cf03cf28; break;
    case 7: v = REG_cf03cf2c; break;
    case 8: v = REG_cf03cf30; break;
    case 9: v = REG_cf03cf54; break;
    case 10: v = REG_cf03cf58; break;
    case 0: v = -1; break;
    default: v = -1; break;
    }
    return v;
}
