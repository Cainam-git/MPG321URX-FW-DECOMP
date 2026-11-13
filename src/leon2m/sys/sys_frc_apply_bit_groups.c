/* sys_frc_apply_bit_groups  (FUN_a01118cc)
 *
 * Clear and set the register bit groups of the frame-rate converter for a setting.
 * Name basis: descriptive - some under the wait / set / clear sequence on 0xCF03C840
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01118cc @ 0xa01118cc-0xa01129e4 (1094 words), flags -mcpu=v8 -O3 -g. Leaf function; the switch
 * becomes the jump table at 0xb17e0 (groups 0..20).
 * Source forms the exact build depends on:
 *  - the two static helpers lock() and unlock() are inlined into every case;
 *  - the try counter in lock() is an unsigned short starting at 0xffff in a do/while (n--) loop (a while (n--)
 *    loop starts the register at 0xfffe);
 *  - the FRC_REG_1D8C / REG_CF01EA40 write is a second if/else chain after the first one.
 */

/* Lock shared between the two processors (as in panel_set_pll_frequency). */
#define SHARED_LOCK     (*(volatile unsigned int *)0xcf03c840)
#define LOCK_FREE       0
#define LOCK_HELD_HERE  1
#define LOCK_HELD_OTHER 2

/* Two fields per group: sys_frc_switch_mode clears this register before it applies groups 0..5. */
#define FRC_REG_1D8C (*(volatile unsigned int *)0xcf011d8c)

/* The bit group registers. Most groups have one bit in each of three registers; value 1, 2 or 4 sets it in
   the first, second or third (0xCF013428 / 0xCF013430 / 0xCF013438, or 0xCF01342C / 0xCF013434 / 0xCF01343C). */
#define REG_CF013428 (*(volatile unsigned int *)0xcf013428)     /* only touched under SHARED_LOCK */
#define REG_CF01342C (*(volatile unsigned int *)0xcf01342c)
#define REG_CF013430 (*(volatile unsigned int *)0xcf013430)
#define REG_CF013434 (*(volatile unsigned int *)0xcf013434)
#define REG_CF013438 (*(volatile unsigned int *)0xcf013438)
#define REG_CF01343C (*(volatile unsigned int *)0xcf01343c)
#define REG_CF013440 (*(volatile unsigned int *)0xcf013440)
#define REG_CF013444 (*(volatile unsigned int *)0xcf013444)
#define REG_CF013448 (*(volatile unsigned int *)0xcf013448)
#define REG_CF01344C (*(volatile unsigned int *)0xcf01344c)
#define REG_CF013450 (*(volatile unsigned int *)0xcf013450)
#define REG_CF013454 (*(volatile unsigned int *)0xcf013454)
#define REG_CF013458 (*(volatile unsigned int *)0xcf013458)
#define REG_CF01345C (*(volatile unsigned int *)0xcf01345c)
#define REG_CF013460 (*(volatile unsigned int *)0xcf013460)
#define REG_CF01EA40 (*(volatile unsigned int *)0xcf01ea40)     /* bit 7 is read by pq_pivot_is_enabled */

/* Take the shared lock: up to 0x10000 tries, each claiming it when the other processor does not hold it and
   stopping once it reads LOCK_HELD_HERE; after the last try it is claimed whatever the outcome. */
static void lock(void)
{
    unsigned short n = 0xffff;

    do {
        if (SHARED_LOCK != LOCK_HELD_OTHER)
            SHARED_LOCK = LOCK_HELD_HERE;
        if (SHARED_LOCK == LOCK_HELD_HERE)
            break;
    } while (n--);
    SHARED_LOCK = LOCK_HELD_HERE;
}

static void unlock(void)
{
    SHARED_LOCK = LOCK_FREE;
}

/*
 * Apply one byte of a sys_frc_bit_group_table row: clear the bits of one group, then set the bits that `value`
 * selects.
 *
 *   group  0..20; a larger number does nothing
 *   value  the table byte; mostly 1, 2 or 4 (one of three bits), in groups 0, 2, 4, 5 and 6 also 3, 6 or 7.
 *          A value that the group does not list leaves its bits cleared.
 *
 * Called from startup_init_display_clocks (groups 0..20, at start-up) and sys_frc_switch_mode (groups 0..5).
 *
 * Every case runs the same two phases: (1) clear all bits of the group, (2) set the bits for the value. Groups
 * 0, 2, 4 and 5 then set a 2-bit field of FRC_REG_1D8C (value 7: 3, value 3 (and 6 in group 0): 1, else 0);
 * group 6 sets bit 5 of 0xCF01EA40 for value 3 or 6 and clears it otherwise. Groups 9 to 16 change 0xCF013428
 * only while they hold SHARED_LOCK.
 *
 *   group  bits cleared                          value -> bits set
 *   0      3440: 0,1,2,5; 3444: 2                1 2 4 -> 3440 bit 0/1/2; 3 -> 0+5; 6 -> 2+5; 7 -> 0+5, 3444 bit 2
 *   1      3444: 4..6                            1 2 4 -> bit 4/5/6
 *   2      3448: 0,1,5; 344C: 2                  1 2 -> 3448 bit 0/1; 3 -> 0+5; 7 -> 0+5, 344C bit 2
 *   3      344C: 4..6                            1 2 4 -> bit 4/5/6
 *   4      3450: 0,1,5; 3454: 2                  as group 2 with 3450 / 3454
 *   5      3454: 4..6; 3458: 1,6                 1 2 4 -> 3454 bit 4/5/6; 3 -> 3454 bit 4, 3458 bit 1;
 *                                                7 -> 3454 bit 4, 3458 bits 1+6
 *   6      3460: 0,2,5                           1 4 -> bit 0/2; 3 -> 0+5; 6 -> 2+5
 *   7      345C: 0..2                            1 2 4 -> bit 0/1/2
 *   8, 17..20  bit 4 / 1 / 2 / 3 / 0 of 342C, 3434, 343C   1 2 4 -> that bit in 342C / 3434 / 343C (18: no 343C)
 *   9      3428 bit 0                            1 -> 3428 bit 0
 *   10..16 bit 1 / 2 / 7 / 3 / 4 / 5 / 6 of 3428, 3430, 3438 (13 and 14: no 3438)
 *                                                1 2 4 -> that bit in 3428 / 3430 / 3438
 * (Register numbers are the low four hex digits of 0xCF01xxxx.)
 */
void sys_frc_apply_bit_groups(unsigned char group, unsigned char value)
{
    switch (group) {
    case 0:
        REG_CF013440 &= ~0x27;
        REG_CF013444 &= ~4;
        if (value == 1)
            REG_CF013440 |= 1;
        else if (value == 2)
            REG_CF013440 |= 2;
        else if (value == 4)
            REG_CF013440 |= 4;
        else if (value == 3)
            REG_CF013440 |= 0x21;
        else if (value == 6)
            REG_CF013440 |= 0x24;
        else if (value == 7) {
            REG_CF013440 |= 0x21;
            REG_CF013444 |= 4;
        }
        /* Bits 0..1 of FRC_REG_1D8C. */
        if (value == 7)
            FRC_REG_1D8C = (FRC_REG_1D8C & 0xfc) | 3;
        else if (value == 3 || value == 6)
            FRC_REG_1D8C = (FRC_REG_1D8C & 0xfc) | 1;
        else
            FRC_REG_1D8C &= 0xfc;
        break;
    case 1:
        REG_CF013444 &= ~0x70;
        if (value == 1)
            REG_CF013444 |= 0x10;
        else if (value == 2)
            REG_CF013444 |= 0x20;
        else if (value == 4)
            REG_CF013444 |= 0x40;
        break;
    case 2:
        REG_CF013448 &= ~0x23;
        REG_CF01344C &= ~4;
        if (value == 1)
            REG_CF013448 |= 1;
        else if (value == 2)
            REG_CF013448 |= 2;
        else if (value == 3)
            REG_CF013448 |= 0x21;
        else if (value == 7) {
            REG_CF013448 |= 0x21;
            REG_CF01344C |= 4;
        }
        /* Bits 2..3 of FRC_REG_1D8C. */
        if (value == 7)
            FRC_REG_1D8C = (FRC_REG_1D8C & 0xf3) | 0xc;
        else if (value == 3)
            FRC_REG_1D8C = (FRC_REG_1D8C & 0xf3) | 4;
        else
            FRC_REG_1D8C &= 0xf3;
        break;
    case 3:
        REG_CF01344C &= ~0x70;
        if (value == 1)
            REG_CF01344C |= 0x10;
        else if (value == 2)
            REG_CF01344C |= 0x20;
        else if (value == 4)
            REG_CF01344C |= 0x40;
        break;
    case 4:
        REG_CF013450 &= ~0x23;
        REG_CF013454 &= ~4;
        if (value == 1)
            REG_CF013450 |= 1;
        else if (value == 2)
            REG_CF013450 |= 2;
        else if (value == 3)
            REG_CF013450 |= 0x21;
        else if (value == 7) {
            REG_CF013450 |= 0x21;
            REG_CF013454 |= 4;
        }
        /* Bits 4..5 of FRC_REG_1D8C. */
        if (value == 7)
            FRC_REG_1D8C = (FRC_REG_1D8C & 0xcf) | 0x30;
        else if (value == 3)
            FRC_REG_1D8C = (FRC_REG_1D8C & 0xcf) | 0x10;
        else
            FRC_REG_1D8C &= 0xcf;
        break;
    case 5:
        REG_CF013454 &= ~0x70;
        REG_CF013458 &= ~0x42;
        if (value == 1)
            REG_CF013454 |= 0x10;
        else if (value == 2)
            REG_CF013454 |= 0x20;
        else if (value == 4)
            REG_CF013454 |= 0x40;
        else if (value == 3) {
            REG_CF013454 |= 0x10;
            REG_CF013458 |= 2;
        }
        else if (value == 7) {
            REG_CF013454 |= 0x10;
            REG_CF013458 |= 0x42;
        }
        /* Bits 6..7 of FRC_REG_1D8C. */
        if (value == 7)
            FRC_REG_1D8C = (FRC_REG_1D8C & 0x3f) | 0xc0;
        else if (value == 3)
            FRC_REG_1D8C = (FRC_REG_1D8C & 0x3f) | 0x40;
        else
            FRC_REG_1D8C &= 0x3f;
        break;
    case 6:
        REG_CF013460 &= ~0x25;
        if (value == 1)
            REG_CF013460 |= 1;
        else if (value == 4)
            REG_CF013460 |= 4;
        else if (value == 3)
            REG_CF013460 |= 0x21;
        else if (value == 6)
            REG_CF013460 |= 0x24;
        if (value == 3 || value == 6)
            REG_CF01EA40 |= 0x20;
        else
            REG_CF01EA40 &= ~0x20;
        break;
    case 7:
        REG_CF01345C &= ~7;
        if (value == 1)
            REG_CF01345C |= 1;
        else if (value == 2)
            REG_CF01345C |= 2;
        else if (value == 4)
            REG_CF01345C |= 4;
        break;
    case 8:
        REG_CF01342C &= ~0x10;
        REG_CF013434 &= ~0x10;
        REG_CF01343C &= ~0x10;
        if (value == 1)
            REG_CF01342C |= 0x10;
        else if (value == 2)
            REG_CF013434 |= 0x10;
        else if (value == 4)
            REG_CF01343C |= 0x10;
        break;
    /* Groups 9 to 16: 0xCF013428 under the shared lock, each change on its own. */
    case 9:
        lock();
        REG_CF013428 &= ~1;
        unlock();
        if (value == 1) {
            lock();
            REG_CF013428 |= 1;
            unlock();
        }
        break;
    case 10:
        lock();
        REG_CF013428 &= ~2;
        unlock();
        REG_CF013430 &= ~2;
        REG_CF013438 &= ~2;
        if (value == 1) {
            lock();
            REG_CF013428 |= 2;
            unlock();
        }
        else if (value == 2)
            REG_CF013430 |= 2;
        else if (value == 4)
            REG_CF013438 |= 2;
        break;
    case 11:
        lock();
        REG_CF013428 &= ~4;
        unlock();
        REG_CF013430 &= ~4;
        REG_CF013438 &= ~4;
        if (value == 1) {
            lock();
            REG_CF013428 |= 4;
            unlock();
        }
        else if (value == 2)
            REG_CF013430 |= 4;
        else if (value == 4)
            REG_CF013438 |= 4;
        break;
    case 12:
        lock();
        REG_CF013428 &= ~0x80;
        unlock();
        REG_CF013430 &= ~0x80;
        REG_CF013438 &= ~0x80;
        if (value == 1) {
            lock();
            REG_CF013428 |= 0x80;
            unlock();
        }
        else if (value == 2)
            REG_CF013430 |= 0x80;
        else if (value == 4)
            REG_CF013438 |= 0x80;
        break;
    case 13:
        lock();
        REG_CF013428 &= ~8;
        unlock();
        REG_CF013430 &= ~8;
        if (value == 1) {
            lock();
            REG_CF013428 |= 8;
            unlock();
        }
        else if (value == 2)
            REG_CF013430 |= 8;
        break;
    case 14:
        lock();
        REG_CF013428 &= ~0x10;
        unlock();
        REG_CF013430 &= ~0x10;
        if (value == 1) {
            lock();
            REG_CF013428 |= 0x10;
            unlock();
        }
        else if (value == 2)
            REG_CF013430 |= 0x10;
        break;
    case 15:
        lock();
        REG_CF013428 &= ~0x20;
        unlock();
        REG_CF013430 &= ~0x20;
        REG_CF013438 &= ~0x20;
        if (value == 1) {
            lock();
            REG_CF013428 |= 0x20;
            unlock();
        }
        else if (value == 2)
            REG_CF013430 |= 0x20;
        else if (value == 4)
            REG_CF013438 |= 0x20;
        break;
    case 16:
        lock();
        REG_CF013428 &= ~0x40;
        unlock();
        REG_CF013430 &= ~0x40;
        REG_CF013438 &= ~0x40;
        if (value == 1) {
            lock();
            REG_CF013428 |= 0x40;
            unlock();
        }
        else if (value == 2)
            REG_CF013430 |= 0x40;
        else if (value == 4)
            REG_CF013438 |= 0x40;
        break;
    /* Groups 17 to 20: one bit in each of 0xCF01342C / 0xCF013434 / 0xCF01343C. */
    case 17:
        REG_CF01342C &= ~2;
        REG_CF013434 &= ~2;
        REG_CF01343C &= ~2;
        if (value == 1)
            REG_CF01342C |= 2;
        else if (value == 2)
            REG_CF013434 |= 2;
        else if (value == 4)
            REG_CF01343C |= 2;
        break;
    case 18:
        REG_CF01342C &= ~4;
        REG_CF013434 &= ~4;
        if (value == 1)
            REG_CF01342C |= 4;
        else if (value == 2)
            REG_CF013434 |= 4;
        break;
    case 19:
        REG_CF01342C &= ~8;
        REG_CF013434 &= ~8;
        REG_CF01343C &= ~8;
        if (value == 1)
            REG_CF01342C |= 8;
        else if (value == 2)
            REG_CF013434 |= 8;
        else if (value == 4)
            REG_CF01343C |= 8;
        break;
    case 20:
        REG_CF01342C &= ~1;
        REG_CF013434 &= ~1;
        REG_CF01343C &= ~1;
        if (value == 1)
            REG_CF01342C |= 1;
        else if (value == 2)
            REG_CF013434 |= 1;
        else if (value == 4)
            REG_CF01343C |= 1;
        break;
    }
}
