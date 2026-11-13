/* sys_latch_status_state  (FUN_a011337c)
 *
 * Derive a 0..2 state from the status bits and latch it one-hot.
 * Name basis: descriptive - bits 0..2 of 0xCF01345C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011337c, flags -mcpu=v8 -O3 -g. Leaf.
 * Source forms the exact build depends on:
 *  - every test in the first switch is an if / else-if chain on a fresh register read; only the last chain
 *    (the default case) ends with an explicit 'else state = 0';
 *  - case order 0, 2, 5, 3, 4, 1, 13, 14, default in the first switch and 0, 2, 1 in the last;
 *  - lock() and unlock() are static functions, the same pair as in Set_INTERNAL_1_INPUT_Path; R is volatile.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define SHARED_LOCK R(0xcf03c840)       /* lock shared between the two processors */
#define LOCK_FREE       0
#define LOCK_HELD_HERE  1
#define LOCK_HELD_OTHER 2

#define STATUS_REG_0        0xcf01345c  /* selector 0; its bits 0..2 also receive the result */
#define STATUS_REG_1        0xcf013444  /* selectors 1, 3 and 5 test bits 4..6 of this and of the */
#define STATUS_REG_3        0xcf01344c  /* two registers that follow it */
#define STATUS_REG_5        0xcf013454
#define STATUS_REG_2        0xcf013448  /* selectors 2 and 4 test bits 0..1 */
#define STATUS_REG_4        0xcf013450
#define STATUS_READ_REG     0xcf013428  /* the other selectors: read under SHARED_LOCK, ... */
#define STATUS_SECOND_REG   0xcf013430  /* ... then the same bit of this register */
#define STATUS_THIRD_REG    0xcf013438  /* only bit 6 of it, for selectors other than 13 and 14 */

/* Result of the tests, and the value it is written as in bits 0..2 of STATUS_REG_0. */
enum { STATE_0 = 0, STATE_1 = 1, STATE_2 = 2 };
#define LATCH_STATE_0  1
#define LATCH_STATE_2  2
#define LATCH_STATE_1  4

static void lock(void)
{
    unsigned short t = 0xffff;
    do {
        if (SHARED_LOCK != LOCK_HELD_OTHER) SHARED_LOCK = LOCK_HELD_HERE;
        if (SHARED_LOCK == LOCK_HELD_HERE) break;
    } while (--t != 0xffff);
    SHARED_LOCK = LOCK_HELD_HERE;
}
static void unlock(void) { SHARED_LOCK = LOCK_FREE; }

/*
 * Read the status bits that belong to `sel`, reduce them to a state 0, 1 or 2, and store that state as a
 * single set bit (1, 4 or 2) in bits 0..2 of STATUS_REG_0, keeping the other bits.
 *
 *   sel  which group of status bits to read: 0..5 each have their own register (see the case labels);
 *        13 tests bit 3 and 14 tests bit 4 of the shared registers; every other value tests bit 6
 *
 * Within a group the first bit that is set decides: the first bit gives state 0, the second state 2, the third
 * (where there is one) state 1. If no bit is set the state stays 0 and the bits 0..2 are written as for state 0.
 * The shared registers are read under SHARED_LOCK. Called with 3 and 0x10 from pq_read_zone_color_averages,
 * and through sys_api_latch_status_state.
 */
void sys_latch_status_state(unsigned char sel)
{
    unsigned char state = STATE_0;
    unsigned int shared;

    switch (sel) {
    case 0:
        if (R(STATUS_REG_0) & 1) state = 0;
        else if (R(STATUS_REG_0) & 2) state = 2;
        else if (R(STATUS_REG_0) & 4) state = 1;
        break;
    case 2:
        if (R(STATUS_REG_2) & 1) state = 0;
        else if (R(STATUS_REG_2) & 2) state = 2;
        break;
    case 5:
        if (R(STATUS_REG_5) & 0x10) state = 0;
        else if (R(STATUS_REG_5) & 0x20) state = 2;
        else if (R(STATUS_REG_5) & 0x40) state = 1;
        break;
    case 3:
        if (R(STATUS_REG_3) & 0x10) state = 0;
        else if (R(STATUS_REG_3) & 0x20) state = 2;
        else if (R(STATUS_REG_3) & 0x40) state = 1;
        break;
    case 4:
        if (R(STATUS_REG_4) & 1) state = 0;
        else if (R(STATUS_REG_4) & 2) state = 2;
        break;
    case 1:
        if (R(STATUS_REG_1) & 0x10) state = 0;
        else if (R(STATUS_REG_1) & 0x20) state = 2;
        else if (R(STATUS_REG_1) & 0x40) state = 1;
        break;
    case 13:
        lock();
        shared = R(STATUS_READ_REG);
        unlock();
        if (shared & 8) state = 0;
        else if (R(STATUS_SECOND_REG) & 8) state = 2;
        break;
    case 14:
        lock();
        shared = R(STATUS_READ_REG);
        unlock();
        if (shared & 0x10) state = 0;
        else if (R(STATUS_SECOND_REG) & 0x10) state = 2;
        break;
    default:
        lock();
        shared = R(STATUS_READ_REG);
        unlock();
        if (shared & 0x40) state = 0;
        else if (R(STATUS_SECOND_REG) & 0x40) state = 2;
        else if (R(STATUS_THIRD_REG) & 0x40) state = 1;
        else state = 0;
        break;
    }
    /* Latch the state one-hot. */
    switch (state) {
    case 0: R(STATUS_REG_0) = (R(STATUS_REG_0) & 0xf8) | LATCH_STATE_0; break;
    case 2: R(STATUS_REG_0) = (R(STATUS_REG_0) & 0xf8) | LATCH_STATE_2; break;
    case 1: R(STATUS_REG_0) = (R(STATUS_REG_0) & 0xf8) | LATCH_STATE_1; break;
    }
}
