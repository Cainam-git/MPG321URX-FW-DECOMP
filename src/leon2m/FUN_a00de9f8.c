/* leon2m FUN_a00de9f8 @ 0xa00de9f8-0xa00deb64: register getter switch.
 * Returns the low byte of hardware register n (0: 0xcf03c8c0, 1: 0xcf03c8c4, 2: 0xcf03c8c8, 3: 0xcf03c8cc, 4:
 * 0xcf03c8d0, 5: 0xcf03c8d4, 6: 0xcf03c8d8, 7: 0xcf03c8dc, 8: 0xcf03c8e0, 9: 0xcf03c8e4, 10: 0xcf03c8e8, 11:
 * 0xcf03c8ec, 12: 0xcf03c8f0, 13: 0xcf03c8f4, 14: 0xcf03c8f8, 15: 0xcf03c8fc); other n return 0.
 */
#define REG_cf03c8c0 (*(volatile unsigned int *)0xcf03c8c0)
#define REG_cf03c8c4 (*(volatile unsigned int *)0xcf03c8c4)
#define REG_cf03c8c8 (*(volatile unsigned int *)0xcf03c8c8)
#define REG_cf03c8cc (*(volatile unsigned int *)0xcf03c8cc)
#define REG_cf03c8d0 (*(volatile unsigned int *)0xcf03c8d0)
#define REG_cf03c8d4 (*(volatile unsigned int *)0xcf03c8d4)
#define REG_cf03c8d8 (*(volatile unsigned int *)0xcf03c8d8)
#define REG_cf03c8dc (*(volatile unsigned int *)0xcf03c8dc)
#define REG_cf03c8e0 (*(volatile unsigned int *)0xcf03c8e0)
#define REG_cf03c8e4 (*(volatile unsigned int *)0xcf03c8e4)
#define REG_cf03c8e8 (*(volatile unsigned int *)0xcf03c8e8)
#define REG_cf03c8ec (*(volatile unsigned int *)0xcf03c8ec)
#define REG_cf03c8f0 (*(volatile unsigned int *)0xcf03c8f0)
#define REG_cf03c8f4 (*(volatile unsigned int *)0xcf03c8f4)
#define REG_cf03c8f8 (*(volatile unsigned int *)0xcf03c8f8)
#define REG_cf03c8fc (*(volatile unsigned int *)0xcf03c8fc)

unsigned char FUN_a00de9f8(unsigned char n)
{
    unsigned char v = 0;

    switch (n) {
    case 0: v = REG_cf03c8c0; break;
    case 1: v = REG_cf03c8c4; break;
    case 2: v = REG_cf03c8c8; break;
    case 3: v = REG_cf03c8cc; break;
    case 4: v = REG_cf03c8d0; break;
    case 5: v = REG_cf03c8d4; break;
    case 6: v = REG_cf03c8d8; break;
    case 7: v = REG_cf03c8dc; break;
    case 8: v = REG_cf03c8e0; break;
    case 9: v = REG_cf03c8e4; break;
    case 10: v = REG_cf03c8e8; break;
    case 11: v = REG_cf03c8ec; break;
    case 12: v = REG_cf03c8f0; break;
    case 13: v = REG_cf03c8f4; break;
    case 14: v = REG_cf03c8f8; break;
    case 15: v = REG_cf03c8fc; break;
    }
    return v;
}
