/* panel_set_pll_frequency  (FUN_a01026e8)
 *
 * Program one of the display clock generators for a frequency.
 * Name basis: proven - GPLL programmer: post-divider and n = f * 2^17 / 12 MHz, under a hardware semaphore;
 *   prints
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01026e8 @ 0xa01026e8, flags -mcpu=v8 -O3 -g. Real size 0x884 bytes (the jump table sits inside).
 * Source forms the exact build depends on:
 *  - lock() and unlock() are static functions that gcc inlines; the try counter is an unsigned short tested
 *    with --tries != 0xffff;
 *  - pll_value is computed in 64 bits ((unsigned long long)divided * 0x20000 / 12000000, a __udivdi3 call);
 *  - every case is its own copy; the FRC case reads its divider field under the lock into its own unsigned char.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Word shared with another processor, used as a lock around writes to the clock registers. This program
   writes 1 to take it and does not write while it reads 2; 0 releases it. */
#define SHARED_LOCK R(0xcf03c840)
#define LOCK_FREE         0
#define LOCK_HELD_HERE    1
#define LOCK_HELD_OTHER   2

/* The five clock generators. Each has a 24-bit value (three byte registers from the address given, written
   with reg_write24_bytes_settle) and a control register 0x10 above it. */
#define GPLL_DISPM_VALUE  0xcf012884
#define GPLL_DISP1_VALUE  0xcf0128c4
#define GPLL_DISP2_VALUE  0xcf012904
#define GPLL_DISP3_VALUE  0xcf012944
#define GPLL_FRC_VALUE    0xcf012984
#define GPLL_DISPM_CTRL   R(0xcf012894)
#define GPLL_DISP1_CTRL   R(0xcf0128d4)
#define GPLL_DISP2_CTRL   R(0xcf012914)
#define GPLL_DISP3_CTRL   R(0xcf012954)
#define GPLL_FRC_CTRL     R(0xcf012994)
#define GPLL_CTRL_LOAD    0x20          /* written to the control register before the new value */

/* Post-divider fields: 2 bits per generator. DISPM bits 7..6, DISP1 5..4, DISP2 3..2, DISP3 1..0 of the
   first register; FRC bits 7..6 of the second. */
#define GPLL_DIVIDERS     R(0xcf014740)
#define GPLL_FRC_DIVIDER  R(0xcf014744)

/* One bit per generator (DISPM bit 0 .. DISP3 bit 3), set before a new value is written; FRC uses bit 0 of
   its own register. */
#define GPLL_REG_12444    R(0xcf012444)
#define GPLL_FRC_REG_12440 R(0xcf012440)
/* One bit per generator (DISPM bit 0 .. DISP3 bit 3, FRC bit 4), cleared before a new value is written. */
#define GPLL_REG_1477C    R(0xcf01477c)

/* Upper limits of the post-divider steps, in Hz. */
#define FREQ_LIMIT_DIV1   470000000
#define FREQ_LIMIT_DIV2   940000000
#define FREQ_LIMIT_DIV4   1870000000
#define GPLL_REF_HZ       12000000      /* value = frequency * 2^17 / 12 MHz */
#define GPLL_FRACTION     0x20000       /* 2^17 */

enum { GPLL_DISPM = 0, GPLL_DISP1 = 1, GPLL_DISP2 = 2, GPLL_DISP3 = 3, GPLL_FRC = 4 };

extern int dbg_printf();
extern unsigned int reg_read24_bytes(unsigned int);
extern void reg_write24_bytes_settle(unsigned int, unsigned int);
extern unsigned long long __udivdi3(unsigned long long, unsigned long long);

/* Take the shared lock: up to 65536 tries, each claiming it unless the other side holds it, until it reads
   LOCK_HELD_HERE; after the last try it is claimed whatever the outcome. */
static void lock(void)
{
    unsigned short tries = 0xffff;
    do {
        if (SHARED_LOCK != LOCK_HELD_OTHER) SHARED_LOCK = LOCK_HELD_HERE;
        if (SHARED_LOCK == LOCK_HELD_HERE) break;
    } while (--tries != 0xffff);
    SHARED_LOCK = LOCK_HELD_HERE;
}
static void unlock(void) { SHARED_LOCK = LOCK_FREE; }

/*
 * Set one clock generator to a frequency.
 *
 *   generator     GPLL_DISPM, GPLL_DISP1, GPLL_DISP2, GPLL_DISP3 or GPLL_FRC; any other value only computes
 *   frequency_hz  the wanted frequency in Hz
 *
 * The frequency is first halved until it is below 470 MHz (post-divider 2^0 .. 2^3), then turned into the
 * generator value: divided frequency * 2^17 / 12 MHz. The firmware prints "GPLL_<name> = <divided frequency>
 * (x 2^<post-divider>)". When the generator already holds that value and that post-divider nothing is written;
 * otherwise it prints "--><name>" and programs the generator.
 *
 * Callers: panel_output_setup_path, panel_output_setup_clock, pq_block_blank_with_color and
 * panel_set_clock_from_row set DISPM to the output clock, DISP1 and DISP2 to half of it and DISP3 to a quarter;
 * the two clock correction steps set DISPM alone; FRCConfigPostFRC sets the FRC clock;
 * input_bring_up_set_pixel_clock and panel_calc_output_pixel_clock pass a generator number of their own;
 * startup_bring_up_system sets DISPM and FRC to 960 MHz. panel_get_pll_frequency_mhz turns the value back into MHz.
 */
void panel_set_pll_frequency(unsigned char generator, unsigned int frequency_hz)
{
    unsigned int divided, pll_value;
    unsigned char post_divider;         /* log2 of the division */
    if (frequency_hz < FREQ_LIMIT_DIV1) { post_divider = 0; divided = frequency_hz; }
    else if (frequency_hz < FREQ_LIMIT_DIV2) { post_divider = 1; divided = frequency_hz >> 1; }
    else if (frequency_hz < FREQ_LIMIT_DIV4) { post_divider = 2; divided = frequency_hz >> 2; }
    else { post_divider = 3; divided = frequency_hz >> 3; }
    pll_value = (unsigned long long)divided * GPLL_FRACTION / GPLL_REF_HZ;
    switch (generator) {
    case GPLL_DISPM:
        dbg_printf("GPLL_DISPM = %ld (x 2^%d)\r\n", divided, post_divider);
        if (reg_read24_bytes(GPLL_DISPM_VALUE) == pll_value && ((GPLL_DIVIDERS >> 6) & 3) == post_divider) break;
        dbg_printf("-->GPLL_DISPM\r\n");
        lock(); GPLL_REG_12444 |= 1; unlock();
        lock(); GPLL_REG_1477C &= ~1; unlock();
        GPLL_DIVIDERS &= ~0xc0;
        GPLL_DIVIDERS |= post_divider << 6;
        GPLL_DISPM_CTRL = GPLL_CTRL_LOAD;
        reg_write24_bytes_settle(GPLL_DISPM_VALUE, pll_value);
        break;
    case GPLL_DISP1:
        dbg_printf("GPLL_DISP1 = %ld (x 2^%d)\r\n", divided, post_divider);
        if (reg_read24_bytes(GPLL_DISP1_VALUE) == pll_value && ((GPLL_DIVIDERS >> 4) & 3) == post_divider) break;
        dbg_printf("-->GPLL_DISP1\r\n");
        lock(); GPLL_REG_12444 |= 2; unlock();
        lock(); GPLL_REG_1477C &= ~2; unlock();
        GPLL_DIVIDERS &= ~0x30;
        GPLL_DIVIDERS |= post_divider << 4;
        GPLL_DISP1_CTRL = GPLL_CTRL_LOAD;
        reg_write24_bytes_settle(GPLL_DISP1_VALUE, pll_value);
        break;
    case GPLL_DISP2:
        dbg_printf("GPLL_DISP2 = %ld (x 2^%d)\r\n", divided, post_divider);
        if (reg_read24_bytes(GPLL_DISP2_VALUE) == pll_value && ((GPLL_DIVIDERS >> 2) & 3) == post_divider) break;
        dbg_printf("-->GPLL_DISP2\r\n");
        lock(); GPLL_REG_12444 |= 4; unlock();
        lock(); GPLL_REG_1477C &= ~4; unlock();
        GPLL_DIVIDERS &= ~0x0c;
        GPLL_DIVIDERS |= post_divider << 2;
        GPLL_DISP2_CTRL = GPLL_CTRL_LOAD;
        reg_write24_bytes_settle(GPLL_DISP2_VALUE, pll_value);
        break;
    case GPLL_DISP3:
        dbg_printf("GPLL_DISP3 = %ld (x 2^%d)\r\n", divided, post_divider);
        if (reg_read24_bytes(GPLL_DISP3_VALUE) == pll_value && (GPLL_DIVIDERS & 3) == post_divider) break;
        dbg_printf("-->GPLL_DISP3\r\n");
        lock(); GPLL_REG_12444 |= 8; unlock();
        lock(); GPLL_REG_1477C &= ~8; unlock();
        GPLL_DIVIDERS &= ~3;
        GPLL_DIVIDERS |= post_divider;
        GPLL_DISP3_CTRL = GPLL_CTRL_LOAD;
        reg_write24_bytes_settle(GPLL_DISP3_VALUE, pll_value);
        break;
    case GPLL_FRC:
        dbg_printf("GPLL_FRC = %ld (x 2^%d)\r\n", divided, post_divider);
        if (reg_read24_bytes(GPLL_FRC_VALUE) == pll_value) {
            unsigned char current_divider;
            /* The FRC divider register is read and written only under the lock. */
            lock(); current_divider = (unsigned char)GPLL_FRC_DIVIDER >> 6; unlock();
            if (current_divider == post_divider) break;
        }
        dbg_printf("-->GPLL_FRC\r\n");
        GPLL_FRC_REG_12440 |= 1;
        lock(); GPLL_REG_1477C &= ~0x10; unlock();
        lock(); GPLL_FRC_DIVIDER &= ~0xc0; unlock();
        lock(); GPLL_FRC_DIVIDER |= post_divider << 6; unlock();
        GPLL_FRC_CTRL = GPLL_CTRL_LOAD;
        reg_write24_bytes_settle(GPLL_FRC_VALUE, pll_value);
        break;
    }
}
