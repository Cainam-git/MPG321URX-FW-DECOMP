/* leon2m FUN_a00dddb8 @ 0xa00dddb8-0xa00ddf24 (91 words).
 * Writes the byte v to hardware register n: 1..5 -> 0xcf03c000..0xcf03c010, 6 -> 0xcf03c040, 7 -> 0xcf03c048,
 * 8..13 -> 0xcf03c450..0xcf03c478 (step 8), 14..17 -> 0xcf03cc00..0xcf03cc0c; other n do nothing.
 */
#define REG_cf03c000 (*(volatile unsigned int *)0xcf03c000)
#define REG_cf03c004 (*(volatile unsigned int *)0xcf03c004)
#define REG_cf03c008 (*(volatile unsigned int *)0xcf03c008)
#define REG_cf03c00c (*(volatile unsigned int *)0xcf03c00c)
#define REG_cf03c010 (*(volatile unsigned int *)0xcf03c010)
#define REG_cf03c040 (*(volatile unsigned int *)0xcf03c040)
#define REG_cf03c048 (*(volatile unsigned int *)0xcf03c048)
#define REG_cf03c450 (*(volatile unsigned int *)0xcf03c450)
#define REG_cf03c458 (*(volatile unsigned int *)0xcf03c458)
#define REG_cf03c460 (*(volatile unsigned int *)0xcf03c460)
#define REG_cf03c468 (*(volatile unsigned int *)0xcf03c468)
#define REG_cf03c470 (*(volatile unsigned int *)0xcf03c470)
#define REG_cf03c478 (*(volatile unsigned int *)0xcf03c478)
#define REG_cf03cc00 (*(volatile unsigned int *)0xcf03cc00)
#define REG_cf03cc04 (*(volatile unsigned int *)0xcf03cc04)
#define REG_cf03cc08 (*(volatile unsigned int *)0xcf03cc08)
#define REG_cf03cc0c (*(volatile unsigned int *)0xcf03cc0c)

void FUN_a00dddb8(unsigned char n, unsigned char v)
{
    switch (n) {
    case 1: REG_cf03c000 = v; break;
    case 2: REG_cf03c004 = v; break;
    case 3: REG_cf03c008 = v; break;
    case 4: REG_cf03c00c = v; break;
    case 5: REG_cf03c010 = v; break;
    case 6: REG_cf03c040 = v; break;
    case 7: REG_cf03c048 = v; break;
    case 8: REG_cf03c450 = v; break;
    case 9: REG_cf03c458 = v; break;
    case 10: REG_cf03c460 = v; break;
    case 11: REG_cf03c468 = v; break;
    case 12: REG_cf03c470 = v; break;
    case 13: REG_cf03c478 = v; break;
    case 14: REG_cf03cc00 = v; break;
    case 15: REG_cf03cc04 = v; break;
    case 16: REG_cf03cc08 = v; break;
    case 17: REG_cf03cc0c = v; break;
    }
}
