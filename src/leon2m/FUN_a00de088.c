/* leon2m FUN_a00de088 @ 0xa00de088-0xa00de1fc: register setter switch.
 * Writes the byte v to hardware register n (1: 0xcf03c014, 2: 0xcf03c018, 3: 0xcf03c01c, 4: 0xcf03c020, 5:
 * 0xcf03c024, 6: 0xcf03c044, 7: 0xcf03c04c, 8: 0xcf03c454, 9: 0xcf03c45c, 10: 0xcf03c464, 11: 0xcf03c46c, 12:
 * 0xcf03c474, 13: 0xcf03c47c, 14: 0xcf03cc40, 15: 0xcf03cc44, 16: 0xcf03cc48, 17: 0xcf03cc4c); other n do nothing.
 */
#define REG_cf03c014 (*(volatile unsigned int *)0xcf03c014)
#define REG_cf03c018 (*(volatile unsigned int *)0xcf03c018)
#define REG_cf03c01c (*(volatile unsigned int *)0xcf03c01c)
#define REG_cf03c020 (*(volatile unsigned int *)0xcf03c020)
#define REG_cf03c024 (*(volatile unsigned int *)0xcf03c024)
#define REG_cf03c044 (*(volatile unsigned int *)0xcf03c044)
#define REG_cf03c04c (*(volatile unsigned int *)0xcf03c04c)
#define REG_cf03c454 (*(volatile unsigned int *)0xcf03c454)
#define REG_cf03c45c (*(volatile unsigned int *)0xcf03c45c)
#define REG_cf03c464 (*(volatile unsigned int *)0xcf03c464)
#define REG_cf03c46c (*(volatile unsigned int *)0xcf03c46c)
#define REG_cf03c474 (*(volatile unsigned int *)0xcf03c474)
#define REG_cf03c47c (*(volatile unsigned int *)0xcf03c47c)
#define REG_cf03cc40 (*(volatile unsigned int *)0xcf03cc40)
#define REG_cf03cc44 (*(volatile unsigned int *)0xcf03cc44)
#define REG_cf03cc48 (*(volatile unsigned int *)0xcf03cc48)
#define REG_cf03cc4c (*(volatile unsigned int *)0xcf03cc4c)

void FUN_a00de088(unsigned char n, unsigned char v)
{
    switch (n) {
    case 1: REG_cf03c014 = v; break;
    case 2: REG_cf03c018 = v; break;
    case 3: REG_cf03c01c = v; break;
    case 4: REG_cf03c020 = v; break;
    case 5: REG_cf03c024 = v; break;
    case 6: REG_cf03c044 = v; break;
    case 7: REG_cf03c04c = v; break;
    case 8: REG_cf03c454 = v; break;
    case 9: REG_cf03c45c = v; break;
    case 10: REG_cf03c464 = v; break;
    case 11: REG_cf03c46c = v; break;
    case 12: REG_cf03c474 = v; break;
    case 13: REG_cf03c47c = v; break;
    case 14: REG_cf03cc40 = v; break;
    case 15: REG_cf03cc44 = v; break;
    case 16: REG_cf03cc48 = v; break;
    case 17: REG_cf03cc4c = v; break;
    }
}
