/* leon2s FUN_a00ae3e4 @ 0xa00ae3e4-0xa00ae5e4, -mcpu=v8 -Os -g.
 * (port), void. Twice: takes the hardware word 0xcf03c840 (writes 2 unless it reads 1, until it reads 2 or
 * 0x10000 tries pass, then writes 2), sets bits 3 and 5 of 0xcf00780c (first time) or bit 0 of 0xcf02d100
 * (second time) and writes 0 to 0xcf03c840. Then for v = 0xf1, 0xf9, 0xf3, 0xfb, 0xf5, 0xfd:
 * FUN_a00a78fc(0, 0x13, v) and FUN_a00a6c00(port, 0xca.. 0xcf, FUN_a00a78b4(0, 0x14)); last the tail call
 * FUN_a00a6c00(port, 0xd6, 0x7f).
 * Source form: the take step is one static inline helper used twice (same loop as FUN_a00a4ec4).
 */
extern void FUN_a00a78fc(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a00a78b4(unsigned char, unsigned short);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);

#define R780C (*(volatile unsigned int *)0xcf00780c)
#define RD100 (*(volatile unsigned int *)0xcf02d100)
#define R840 (*(volatile unsigned int *)0xcf03c840)

static inline void sem_take(void)
{
    unsigned short n = 0xffff;

    do {
        if (R840 != 1)
            R840 = 2;
        if (R840 == 2)
            break;
    } while (n--);
    R840 = 2;
}

void FUN_a00ae3e4(unsigned int port)
{
    sem_take();
    R780C |= 0x28;
    R840 = 0;
    sem_take();
    RD100 |= 1;
    R840 = 0;
    FUN_a00a78fc(0, 0x13, 0xf1);
    FUN_a00a6c00(port, 0xca, FUN_a00a78b4(0, 0x14));
    FUN_a00a78fc(0, 0x13, 0xf9);
    FUN_a00a6c00(port, 0xcb, FUN_a00a78b4(0, 0x14));
    FUN_a00a78fc(0, 0x13, 0xf3);
    FUN_a00a6c00(port, 0xcc, FUN_a00a78b4(0, 0x14));
    FUN_a00a78fc(0, 0x13, 0xfb);
    FUN_a00a6c00(port, 0xcd, FUN_a00a78b4(0, 0x14));
    FUN_a00a78fc(0, 0x13, 0xf5);
    FUN_a00a6c00(port, 0xce, FUN_a00a78b4(0, 0x14));
    FUN_a00a78fc(0, 0x13, 0xfd);
    FUN_a00a6c00(port, 0xcf, FUN_a00a78b4(0, 0x14));
    FUN_a00a6c00(port, 0xd6, 0x7f);
}
