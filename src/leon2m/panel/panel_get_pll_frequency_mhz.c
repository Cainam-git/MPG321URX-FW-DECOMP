/* panel_get_pll_frequency_mhz  (FUN_a0102fd0)
 *
 * Compute a clock generator's frequency in MHz from its programmed value and post-divider; print it.
 * Returns: MHz, 0 for an unknown generator number
 * Note: Inverse of panel_set_pll_frequency; nothing is measured. The FRC divider is read under the shared
 *   lock.
 * Name basis: derived - prints 'clock %d = %ld'; reads the value and post-divider registers that
 *   panel_set_pll_frequency writes: value * 2^divider * 12 MHz / 2^17
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0102fd0 @ 0xa0102fd0, flags -mcpu=v8 -O3 -g (jump table included).
 * Source forms the exact build depends on:
 *  - the FRC case has its own copy of the lock loop (t-- inside the loop, unsigned short counter) and claims the
 *    lock once more after the loop;
 *  - the product is (unsigned long long)value * (unsigned char)(1 << divider) * 12000000, divided by
 *    131072000000 in one __udivdi3 call; the result is held in an unsigned int and returned as unsigned short.
 */
#define R(a) (*(volatile unsigned int *)(a))                          /* 8-bit register in a 32-bit word */
#define VALUE24(a) (((R((a) + 8) << 8 | R((a) + 4)) << 8) | R(a))     /* 24-bit value, low byte at a */

/* The value registers of the clock generators (see panel_set_pll_frequency) and one more, 0xCF012BC4. */
#define GPLL_DISPM_VALUE  0xcf012884
#define GPLL_DISP1_VALUE  0xcf0128c4
#define GPLL_DISP2_VALUE  0xcf012904
#define GPLL_DISP3_VALUE  0xcf012944
#define GPLL_FRC_VALUE    0xcf012984
#define CLOCK13_VALUE     0xcf012bc4    /* no post-divider */

#define GPLL_DIVIDERS     R(0xcf014740) /* post-dividers of DISPM (bits 7..6) .. DISP3 (bits 1..0) */
#define GPLL_FRC_DIVIDER  R(0xcf014744) /* post-divider of FRC (bits 7..6) */

/* Word shared with another processor, used as a lock (see panel_set_pll_frequency). */
#define SHARED_LOCK R(0xcf03c840)
#define LOCK_FREE         0
#define LOCK_HELD_HERE    1
#define LOCK_HELD_OTHER   2

/* MHz = value * 2^divider * 12 MHz / 2^17, in Hz: value * 2^divider * 12000000 / (2^17 * 10^6). */
#define GPLL_REF_HZ       12000000
#define FRACTION_TIMES_MHZ 131072000000ULL

extern unsigned long long __udivdi3(unsigned long long, unsigned long long);
extern int dbg_printf();

/*
 * Return the frequency of a clock generator in MHz, and print it as "clock <id> = <MHz>".
 *
 *   id  0..4 as in panel_set_pll_frequency (DISPM, DISP1, DISP2, DISP3, FRC), or 13; any other id gives 0
 *
 * It reads the generator's 24-bit value and post-divider, the registers panel_set_pll_frequency writes, and
 * applies the inverse of that routine's formula. The FRC divider is read under the shared lock.
 *
 * Callers: drv_PanelLimitation compares the DISPM or FRC result with the row's clock limits; sys_frc_setup_lock
 * computes line counts from the DISPM and FRC clocks; panel_vx1_measure_lane_clock reads DISPM, FRC, DISP2 or
 * DISP3.
 */
unsigned short panel_get_pll_frequency_mhz(unsigned char id)
{
    unsigned int value = 0, divider = 0;
    unsigned short tries;
    unsigned int mhz;
    switch (id) {
    case 0: value = VALUE24(GPLL_DISPM_VALUE); divider = GPLL_DIVIDERS >> 6; break;
    case 1: value = VALUE24(GPLL_DISP1_VALUE); divider = (GPLL_DIVIDERS >> 4) & 3; break;
    case 2: value = VALUE24(GPLL_DISP2_VALUE); divider = (GPLL_DIVIDERS >> 2) & 3; break;
    case 3: value = VALUE24(GPLL_DISP3_VALUE); divider = GPLL_DIVIDERS & 3; break;
    case 4:
        value = VALUE24(GPLL_FRC_VALUE);
        tries = 0xffff;
        do {
            if (SHARED_LOCK != LOCK_HELD_OTHER) SHARED_LOCK = LOCK_HELD_HERE;
            if (SHARED_LOCK == LOCK_HELD_HERE) break;
            tries--;
        } while (tries != 0xffff);
        SHARED_LOCK = LOCK_HELD_HERE;
        divider = (GPLL_FRC_DIVIDER & 0xff) >> 6;
        SHARED_LOCK = LOCK_FREE;
        break;
    case 13: value = VALUE24(CLOCK13_VALUE); break;
    }
    mhz = __udivdi3((unsigned long long)value * (unsigned char)(1 << divider) * GPLL_REF_HZ, FRACTION_TIMES_MHZ);
    dbg_printf("clock %d = %ld\r\n", id, mhz);
    return mhz;
}
