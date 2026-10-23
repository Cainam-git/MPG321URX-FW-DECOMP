/* leon2m FUN_a01118cc @ 0xa01118cc-0xa01129e4 (1094 words), flags -mcpu=v8 -O3 -g. Leaf function.
 * a (switch, jump table at 0xb17e0, 0-20; larger values do nothing) selects a group of bits in the hardware
 * registers 0xcf013428-0xcf013460; b (tested as an if/else chain, mostly 1, 2 or 4) selects which of them is set.
 * Each case first clears its bits in every register of the group, then sets the bits for b. Groups 0, 2, 4 and 5
 * also write a 2-bit field of 0xcf011d8c (b == 7: 3, b == 3 or 6 (group 0) / b == 3: 1, otherwise 0; the masks are
 * 0xfc, 0xf3, 0xcf, 0x3f), group 6 sets bit 5 of 0xcf01ea40 for b == 3 or 6 and clears it otherwise.
 * Groups 9-16 access 0xcf013428 only between c840_wait_set() and c840_clear(): c840_wait_set() loops up to 65536
 * times, writing 1 to 0xcf03c840 whenever it does not read 2 and leaving the loop once it reads 1, then writes 1;
 * c840_clear() writes 0 to 0xcf03c840. Called from FUN_a0112db0 and FUN_a01131d4.
 * Source form: the two static helpers are inlined into every case; the counter is an unsigned short starting at
 * 0xffff in a do/while (n--) loop (a while (n--) loop starts the register at 0xfffe); the 0xcf011d8c / 0xcf01ea40
 * write is a second if/else chain after the first one.
 */
#define REG_cf03c840 (*(volatile unsigned int *)0xcf03c840)
#define REG_cf011d8c (*(volatile unsigned int *)0xcf011d8c)
#define REG_cf013428 (*(volatile unsigned int *)0xcf013428)
#define REG_cf01342c (*(volatile unsigned int *)0xcf01342c)
#define REG_cf013430 (*(volatile unsigned int *)0xcf013430)
#define REG_cf013434 (*(volatile unsigned int *)0xcf013434)
#define REG_cf013438 (*(volatile unsigned int *)0xcf013438)
#define REG_cf01343c (*(volatile unsigned int *)0xcf01343c)
#define REG_cf013440 (*(volatile unsigned int *)0xcf013440)
#define REG_cf013444 (*(volatile unsigned int *)0xcf013444)
#define REG_cf013448 (*(volatile unsigned int *)0xcf013448)
#define REG_cf01344c (*(volatile unsigned int *)0xcf01344c)
#define REG_cf013450 (*(volatile unsigned int *)0xcf013450)
#define REG_cf013454 (*(volatile unsigned int *)0xcf013454)
#define REG_cf013458 (*(volatile unsigned int *)0xcf013458)
#define REG_cf01345c (*(volatile unsigned int *)0xcf01345c)
#define REG_cf013460 (*(volatile unsigned int *)0xcf013460)
#define REG_cf01ea40 (*(volatile unsigned int *)0xcf01ea40)

static void c840_wait_set(void)
{
    unsigned short n = 0xffff;

    do {
        if (REG_cf03c840 != 2)
            REG_cf03c840 = 1;
        if (REG_cf03c840 == 1)
            break;
    } while (n--);
    REG_cf03c840 = 1;
}

static void c840_clear(void)
{
    REG_cf03c840 = 0;
}

void FUN_a01118cc(unsigned char a, unsigned char b)
{
    switch (a) {
    case 0:
        REG_cf013440 &= ~0x27;
        REG_cf013444 &= ~4;
        if (b == 1)
            REG_cf013440 |= 1;
        else if (b == 2)
            REG_cf013440 |= 2;
        else if (b == 4)
            REG_cf013440 |= 4;
        else if (b == 3)
            REG_cf013440 |= 0x21;
        else if (b == 6)
            REG_cf013440 |= 0x24;
        else if (b == 7) {
            REG_cf013440 |= 0x21;
            REG_cf013444 |= 4;
        }
        if (b == 7)
            REG_cf011d8c = (REG_cf011d8c & 0xfc) | 3;
        else if (b == 3 || b == 6)
            REG_cf011d8c = (REG_cf011d8c & 0xfc) | 1;
        else
            REG_cf011d8c &= 0xfc;
        break;
    case 1:
        REG_cf013444 &= ~0x70;
        if (b == 1)
            REG_cf013444 |= 0x10;
        else if (b == 2)
            REG_cf013444 |= 0x20;
        else if (b == 4)
            REG_cf013444 |= 0x40;
        break;
    case 2:
        REG_cf013448 &= ~0x23;
        REG_cf01344c &= ~4;
        if (b == 1)
            REG_cf013448 |= 1;
        else if (b == 2)
            REG_cf013448 |= 2;
        else if (b == 3)
            REG_cf013448 |= 0x21;
        else if (b == 7) {
            REG_cf013448 |= 0x21;
            REG_cf01344c |= 4;
        }
        if (b == 7)
            REG_cf011d8c = (REG_cf011d8c & 0xf3) | 0xc;
        else if (b == 3)
            REG_cf011d8c = (REG_cf011d8c & 0xf3) | 4;
        else
            REG_cf011d8c &= 0xf3;
        break;
    case 3:
        REG_cf01344c &= ~0x70;
        if (b == 1)
            REG_cf01344c |= 0x10;
        else if (b == 2)
            REG_cf01344c |= 0x20;
        else if (b == 4)
            REG_cf01344c |= 0x40;
        break;
    case 4:
        REG_cf013450 &= ~0x23;
        REG_cf013454 &= ~4;
        if (b == 1)
            REG_cf013450 |= 1;
        else if (b == 2)
            REG_cf013450 |= 2;
        else if (b == 3)
            REG_cf013450 |= 0x21;
        else if (b == 7) {
            REG_cf013450 |= 0x21;
            REG_cf013454 |= 4;
        }
        if (b == 7)
            REG_cf011d8c = (REG_cf011d8c & 0xcf) | 0x30;
        else if (b == 3)
            REG_cf011d8c = (REG_cf011d8c & 0xcf) | 0x10;
        else
            REG_cf011d8c &= 0xcf;
        break;
    case 5:
        REG_cf013454 &= ~0x70;
        REG_cf013458 &= ~0x42;
        if (b == 1)
            REG_cf013454 |= 0x10;
        else if (b == 2)
            REG_cf013454 |= 0x20;
        else if (b == 4)
            REG_cf013454 |= 0x40;
        else if (b == 3) {
            REG_cf013454 |= 0x10;
            REG_cf013458 |= 2;
        }
        else if (b == 7) {
            REG_cf013454 |= 0x10;
            REG_cf013458 |= 0x42;
        }
        if (b == 7)
            REG_cf011d8c = (REG_cf011d8c & 0x3f) | 0xc0;
        else if (b == 3)
            REG_cf011d8c = (REG_cf011d8c & 0x3f) | 0x40;
        else
            REG_cf011d8c &= 0x3f;
        break;
    case 6:
        REG_cf013460 &= ~0x25;
        if (b == 1)
            REG_cf013460 |= 1;
        else if (b == 4)
            REG_cf013460 |= 4;
        else if (b == 3)
            REG_cf013460 |= 0x21;
        else if (b == 6)
            REG_cf013460 |= 0x24;
        if (b == 3 || b == 6)
            REG_cf01ea40 |= 0x20;
        else
            REG_cf01ea40 &= ~0x20;
        break;
    case 7:
        REG_cf01345c &= ~7;
        if (b == 1)
            REG_cf01345c |= 1;
        else if (b == 2)
            REG_cf01345c |= 2;
        else if (b == 4)
            REG_cf01345c |= 4;
        break;
    case 8:
        REG_cf01342c &= ~0x10;
        REG_cf013434 &= ~0x10;
        REG_cf01343c &= ~0x10;
        if (b == 1)
            REG_cf01342c |= 0x10;
        else if (b == 2)
            REG_cf013434 |= 0x10;
        else if (b == 4)
            REG_cf01343c |= 0x10;
        break;
    case 9:
        c840_wait_set();
        REG_cf013428 &= ~1;
        c840_clear();
        if (b == 1) {
            c840_wait_set();
            REG_cf013428 |= 1;
            c840_clear();
        }
        break;
    case 10:
        c840_wait_set();
        REG_cf013428 &= ~2;
        c840_clear();
        REG_cf013430 &= ~2;
        REG_cf013438 &= ~2;
        if (b == 1) {
            c840_wait_set();
            REG_cf013428 |= 2;
            c840_clear();
        }
        else if (b == 2)
            REG_cf013430 |= 2;
        else if (b == 4)
            REG_cf013438 |= 2;
        break;
    case 11:
        c840_wait_set();
        REG_cf013428 &= ~4;
        c840_clear();
        REG_cf013430 &= ~4;
        REG_cf013438 &= ~4;
        if (b == 1) {
            c840_wait_set();
            REG_cf013428 |= 4;
            c840_clear();
        }
        else if (b == 2)
            REG_cf013430 |= 4;
        else if (b == 4)
            REG_cf013438 |= 4;
        break;
    case 12:
        c840_wait_set();
        REG_cf013428 &= ~0x80;
        c840_clear();
        REG_cf013430 &= ~0x80;
        REG_cf013438 &= ~0x80;
        if (b == 1) {
            c840_wait_set();
            REG_cf013428 |= 0x80;
            c840_clear();
        }
        else if (b == 2)
            REG_cf013430 |= 0x80;
        else if (b == 4)
            REG_cf013438 |= 0x80;
        break;
    case 13:
        c840_wait_set();
        REG_cf013428 &= ~8;
        c840_clear();
        REG_cf013430 &= ~8;
        if (b == 1) {
            c840_wait_set();
            REG_cf013428 |= 8;
            c840_clear();
        }
        else if (b == 2)
            REG_cf013430 |= 8;
        break;
    case 14:
        c840_wait_set();
        REG_cf013428 &= ~0x10;
        c840_clear();
        REG_cf013430 &= ~0x10;
        if (b == 1) {
            c840_wait_set();
            REG_cf013428 |= 0x10;
            c840_clear();
        }
        else if (b == 2)
            REG_cf013430 |= 0x10;
        break;
    case 15:
        c840_wait_set();
        REG_cf013428 &= ~0x20;
        c840_clear();
        REG_cf013430 &= ~0x20;
        REG_cf013438 &= ~0x20;
        if (b == 1) {
            c840_wait_set();
            REG_cf013428 |= 0x20;
            c840_clear();
        }
        else if (b == 2)
            REG_cf013430 |= 0x20;
        else if (b == 4)
            REG_cf013438 |= 0x20;
        break;
    case 16:
        c840_wait_set();
        REG_cf013428 &= ~0x40;
        c840_clear();
        REG_cf013430 &= ~0x40;
        REG_cf013438 &= ~0x40;
        if (b == 1) {
            c840_wait_set();
            REG_cf013428 |= 0x40;
            c840_clear();
        }
        else if (b == 2)
            REG_cf013430 |= 0x40;
        else if (b == 4)
            REG_cf013438 |= 0x40;
        break;
    case 17:
        REG_cf01342c &= ~2;
        REG_cf013434 &= ~2;
        REG_cf01343c &= ~2;
        if (b == 1)
            REG_cf01342c |= 2;
        else if (b == 2)
            REG_cf013434 |= 2;
        else if (b == 4)
            REG_cf01343c |= 2;
        break;
    case 18:
        REG_cf01342c &= ~4;
        REG_cf013434 &= ~4;
        if (b == 1)
            REG_cf01342c |= 4;
        else if (b == 2)
            REG_cf013434 |= 4;
        break;
    case 19:
        REG_cf01342c &= ~8;
        REG_cf013434 &= ~8;
        REG_cf01343c &= ~8;
        if (b == 1)
            REG_cf01342c |= 8;
        else if (b == 2)
            REG_cf013434 |= 8;
        else if (b == 4)
            REG_cf01343c |= 8;
        break;
    case 20:
        REG_cf01342c &= ~1;
        REG_cf013434 &= ~1;
        REG_cf01343c &= ~1;
        if (b == 1)
            REG_cf01342c |= 1;
        else if (b == 2)
            REG_cf013434 |= 1;
        else if (b == 4)
            REG_cf01343c |= 1;
        break;
    }
}
