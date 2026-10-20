/* leon2m FUN_a00de1fc @ 0xa00de1fc-0xa00de444 (146 words).
 * Writes the bytes a and b to a pair of hardware registers selected by n: 1..5 -> 0xcf03c2c0.. / 0xcf03c31c..,
 * 6, 7 -> 0xcf03c2d4, 0xcf03c2d8 / 0xcf03c338, 0xcf03c33c, 8..13 -> 0xcf03c4c0.. / 0xcf03c4e0..,
 * 14..17 -> 0xcf03cc80.. / 0xcf03ccc0.. (step 4 within each group); other n do nothing.
 */
#define REG_cf03c2c0 (*(volatile unsigned int *)0xcf03c2c0)
#define REG_cf03c2c4 (*(volatile unsigned int *)0xcf03c2c4)
#define REG_cf03c2c8 (*(volatile unsigned int *)0xcf03c2c8)
#define REG_cf03c2cc (*(volatile unsigned int *)0xcf03c2cc)
#define REG_cf03c2d0 (*(volatile unsigned int *)0xcf03c2d0)
#define REG_cf03c2d4 (*(volatile unsigned int *)0xcf03c2d4)
#define REG_cf03c2d8 (*(volatile unsigned int *)0xcf03c2d8)
#define REG_cf03c31c (*(volatile unsigned int *)0xcf03c31c)
#define REG_cf03c320 (*(volatile unsigned int *)0xcf03c320)
#define REG_cf03c324 (*(volatile unsigned int *)0xcf03c324)
#define REG_cf03c328 (*(volatile unsigned int *)0xcf03c328)
#define REG_cf03c32c (*(volatile unsigned int *)0xcf03c32c)
#define REG_cf03c338 (*(volatile unsigned int *)0xcf03c338)
#define REG_cf03c33c (*(volatile unsigned int *)0xcf03c33c)
#define REG_cf03c4c0 (*(volatile unsigned int *)0xcf03c4c0)
#define REG_cf03c4c4 (*(volatile unsigned int *)0xcf03c4c4)
#define REG_cf03c4c8 (*(volatile unsigned int *)0xcf03c4c8)
#define REG_cf03c4cc (*(volatile unsigned int *)0xcf03c4cc)
#define REG_cf03c4d0 (*(volatile unsigned int *)0xcf03c4d0)
#define REG_cf03c4d4 (*(volatile unsigned int *)0xcf03c4d4)
#define REG_cf03c4e0 (*(volatile unsigned int *)0xcf03c4e0)
#define REG_cf03c4e4 (*(volatile unsigned int *)0xcf03c4e4)
#define REG_cf03c4e8 (*(volatile unsigned int *)0xcf03c4e8)
#define REG_cf03c4ec (*(volatile unsigned int *)0xcf03c4ec)
#define REG_cf03c4f0 (*(volatile unsigned int *)0xcf03c4f0)
#define REG_cf03c4f4 (*(volatile unsigned int *)0xcf03c4f4)
#define REG_cf03cc80 (*(volatile unsigned int *)0xcf03cc80)
#define REG_cf03cc84 (*(volatile unsigned int *)0xcf03cc84)
#define REG_cf03cc88 (*(volatile unsigned int *)0xcf03cc88)
#define REG_cf03cc8c (*(volatile unsigned int *)0xcf03cc8c)
#define REG_cf03ccc0 (*(volatile unsigned int *)0xcf03ccc0)
#define REG_cf03ccc4 (*(volatile unsigned int *)0xcf03ccc4)
#define REG_cf03ccc8 (*(volatile unsigned int *)0xcf03ccc8)
#define REG_cf03cccc (*(volatile unsigned int *)0xcf03cccc)

void FUN_a00de1fc(unsigned char n, unsigned char a, unsigned char b)
{
    switch (n) {
    case 1:
        REG_cf03c2c0 = a;
        REG_cf03c31c = b;
        break;
    case 2:
        REG_cf03c2c4 = a;
        REG_cf03c320 = b;
        break;
    case 3:
        REG_cf03c2c8 = a;
        REG_cf03c324 = b;
        break;
    case 4:
        REG_cf03c2cc = a;
        REG_cf03c328 = b;
        break;
    case 5:
        REG_cf03c2d0 = a;
        REG_cf03c32c = b;
        break;
    case 6:
        REG_cf03c2d4 = a;
        REG_cf03c338 = b;
        break;
    case 7:
        REG_cf03c2d8 = a;
        REG_cf03c33c = b;
        break;
    case 8:
        REG_cf03c4c0 = a;
        REG_cf03c4e0 = b;
        break;
    case 9:
        REG_cf03c4c4 = a;
        REG_cf03c4e4 = b;
        break;
    case 10:
        REG_cf03c4c8 = a;
        REG_cf03c4e8 = b;
        break;
    case 11:
        REG_cf03c4cc = a;
        REG_cf03c4ec = b;
        break;
    case 12:
        REG_cf03c4d0 = a;
        REG_cf03c4f0 = b;
        break;
    case 13:
        REG_cf03c4d4 = a;
        REG_cf03c4f4 = b;
        break;
    case 14:
        REG_cf03cc80 = a;
        REG_cf03ccc0 = b;
        break;
    case 15:
        REG_cf03cc84 = a;
        REG_cf03ccc4 = b;
        break;
    case 16:
        REG_cf03cc88 = a;
        REG_cf03ccc8 = b;
        break;
    case 17:
        REG_cf03cc8c = a;
        REG_cf03cccc = b;
        break;
    }
}
