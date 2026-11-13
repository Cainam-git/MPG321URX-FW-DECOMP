/* sys_dsc_dec_set_pll  (FUN_a00a5148)
 *
 * Program a DSC decoder clock synthesiser from a pixel clock.
 *   mode: 0 or 1
 *   clk: clock in kHz
 * Name basis: descriptive - mode 0: 24-bit value to 0xCF0140C4..CC plus range shift in 0xCF014744; mode 1:
 *   0xCF014104..10C
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a5148 @ 0xa00a5148-0xa00a535c (532 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the division by 1000 is written as `fraction /= 125` before `clk *= 10` and `fraction / 8` in the sum (the
 *    same value for an unsigned number); it fixes the order of the reciprocal multiply and the clk * 10 steps;
 *  - the two read-modify-writes of the range register each have their own lock/unlock pair.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Shared byte with the 8051 (its XDATA 0xF210), used here as a lock around writes to the range register.
   This processor writes 2 to take it and 0 to release it, and does not write while it reads 1. */
#define SHARED_LOCK            0xcf03c840
#define LOCK_FREE              0
#define LOCK_BUSY              1
#define LOCK_HELD_HERE         2

/* Clock synthesiser 0: the 24-bit frequency word, one byte per register, and its range field. */
#define PLL0_FREQ_LOW          0xcf0140c4
#define PLL0_FREQ_MID          0xcf0140c8
#define PLL0_FREQ_HIGH         0xcf0140cc
#define PLL0_RANGE_REG         0xcf014744
#define PLL0_RANGE_MASK        0x30       /* bits 4..5: how many times the clock was halved */
#define PLL0_RANGE_SHIFT       4

/* Clock synthesiser 1: the 24-bit frequency word. */
#define PLL1_FREQ_LOW          0xcf014104
#define PLL1_FREQ_MID          0xcf014108
#define PLL1_FREQ_HIGH         0xcf01410c

/* Take the shared lock: up to 0x10000 tries, each claiming it unless it reads LOCK_BUSY, until it
   reads LOCK_HELD_HERE; then it is claimed once more whatever the outcome. */
static inline void lock(void)
{
    unsigned short tries = 0xffff;

    do {
        if (R(SHARED_LOCK) != LOCK_BUSY)
            R(SHARED_LOCK) = LOCK_HELD_HERE;
        if (R(SHARED_LOCK) == LOCK_HELD_HERE)
            break;
    } while (tries--);
    R(SHARED_LOCK) = LOCK_HELD_HERE;
}

static inline void unlock(void)
{
    R(SHARED_LOCK) = LOCK_FREE;
}

/*
 * Program the frequency word of one of the two clock synthesisers of the DSC decoder.
 *
 *   mode  0: synthesiser 0, 1: synthesiser 1; other values do nothing
 *   clk   the clock; for mode 0 the pixel clock in kHz
 *
 * Mode 0: a clock above 479999 kHz is halved once (up to 959999), twice (up to 1919999) or three times, and the
 * number of halvings goes into the range field. The frequency word is clk * 2^15 / 3000, computed as
 * clk * 10 + clk * 2768 / 3000 (2768 = 0xAD0).
 * Mode 1: the frequency word is clk * 2^17 / 12 (= clk * 2^15 / 3), with no range.
 *
 * Called with mode 0 by sys_dsc_dec_calc_pixel_clock.
 */
void sys_dsc_dec_set_pll(int mode, unsigned int clk)
{
    unsigned char halvings;
    unsigned int freq_word, fraction;

    switch (mode) {
    case 0:
        halvings = 0;
        if (clk > 479999) {
            if (clk <= 959999) {
                clk >>= 1;
                halvings = 1;
            } else if (clk <= 1919999) {
                clk >>= 2;
                halvings = 2;
            } else {
                clk >>= 3;
                halvings = 3;
            }
        }
        fraction = clk * 0xad0 / 3;
        fraction /= 125;
        clk *= 10;
        freq_word = clk + fraction / 8;
        R(PLL0_FREQ_LOW) = freq_word & 0xff;
        R(PLL0_FREQ_MID) = (freq_word >> 8) & 0xff;
        R(PLL0_FREQ_HIGH) = (freq_word >> 16) & 0xff;
        lock();
        R(PLL0_RANGE_REG) &= ~PLL0_RANGE_MASK;
        unlock();
        lock();
        R(PLL0_RANGE_REG) |= halvings << PLL0_RANGE_SHIFT;
        unlock();
        break;
    case 1:
        freq_word = (clk << 17) / 12;
        R(PLL1_FREQ_LOW) = freq_word & 0xff;
        R(PLL1_FREQ_MID) = (freq_word >> 8) & 0xff;
        R(PLL1_FREQ_HIGH) = (freq_word >> 16) & 0xff;
        break;
    }
}
