/* leon2m FUN_a00ddf24 @ 0xa00ddf24-0xa00de088: register getter switch.
 * Returns the low byte of hardware register n (1: 0xcf03c000, 2: 0xcf03c004, 3: 0xcf03c008, 4: 0xcf03c00c, 5:
 * 0xcf03c010, 6: 0xcf03c040, 7: 0xcf03c048, 8: 0xcf03c450, 9: 0xcf03c458, 10: 0xcf03c460, 11: 0xcf03c468, 12:
 * 0xcf03c470, 13: 0xcf03c478, 14: 0xcf03cc00, 15: 0xcf03cc04, 16: 0xcf03cc08, 17: 0xcf03cc0c); other n return 0.
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

unsigned char FUN_a00ddf24(unsigned char n)
{
    unsigned char v = 0;

    switch (n) {
    case 1: v = REG_cf03c000; break;
    case 2: v = REG_cf03c004; break;
    case 3: v = REG_cf03c008; break;
    case 4: v = REG_cf03c00c; break;
    case 5: v = REG_cf03c010; break;
    case 6: v = REG_cf03c040; break;
    case 7: v = REG_cf03c048; break;
    case 8: v = REG_cf03c450; break;
    case 9: v = REG_cf03c458; break;
    case 10: v = REG_cf03c460; break;
    case 11: v = REG_cf03c468; break;
    case 12: v = REG_cf03c470; break;
    case 13: v = REG_cf03c478; break;
    case 14: v = REG_cf03cc00; break;
    case 15: v = REG_cf03cc04; break;
    case 16: v = REG_cf03cc08; break;
    case 17: v = REG_cf03cc0c; break;
    }
    return v;
}
