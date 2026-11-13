/* panel_wait_sync_pulse  (FUN_a002e2a4)
 *
 * Wait for one pulse of status bit 0xCF00EE1C.7 (polarity from 0xCF00ED58.4), 100-tick limit.
 * Note: Sleeps 41 ticks instead when the wait is switched off.
 * Name basis: derived - code only: polarity-aware edge wait with tick time limits; 61 callers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002e2a4 @ 0xa002e2a4-0xa002e3c4 (72 words, including the unreachable ret/restore tail at 0xa002e3bc),
 * flags -mcpu=v8 -O3 -g.
 * Source form: each wait loop tests the time in the loop condition and the sync level in the body with 'break'
 * (with both tests in one '&&' condition the 0xcf00ec00 high part of the address is reused in the else arm and the
 * loop temporaries take other registers).
 */
#define REG(a) (*(volatile unsigned int *)(a))

/* Registers of the output timing block. */
#define OUTPUT_TIMING_CTRL     0xcf00ed40   /* bit 0 set: output timing running (panel_output_apply_timing) */
#define OUTPUT_SYNC_POLARITY   0xcf00ed58   /* bit 4: polarity of the sync status bit */
#define OUTPUT_SYNC_STATUS     0xcf00ee1c   /* bit 7: present level of the sync signal */

#define TIMING_RUNNING         0x01
#define SYNC_INVERTED          0x10
#define SYNC_LEVEL             0x80

#define FALLBACK_SLEEP_TICKS   0x28         /* timer_sleep_ticks waits this + 1 = 41 ticks */
#define FIRST_EDGE_LIMIT       50           /* ticks */
#define SECOND_EDGE_LIMIT      100          /* ticks, counted from the same start */

extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short);
extern void timer_sleep_ticks(unsigned short);

/*
 * Wait for the next pulse of the output's sync signal.
 *
 * With the polarity bit clear it waits until the sync bit reads 0 (at most 50 ticks) and then until it reads 1
 * again (until 100 ticks after the start), so it returns just after a rising edge; with the polarity bit set the
 * levels are the other way round. Neither wait reports a time-out: the routine simply returns.
 *
 * When the output timing is not running there is no pulse to wait for; it then sleeps a fixed 41 ticks instead.
 * Called from many places that change the picture or the panel set-up.
 */
void panel_wait_sync_pulse(void)
{
    unsigned short start;

    if (!(REG(OUTPUT_TIMING_CTRL) & TIMING_RUNNING)) {
        timer_sleep_ticks(FALLBACK_SLEEP_TICKS);
        return;
    }
    if (!(REG(OUTPUT_SYNC_POLARITY) & SYNC_INVERTED)) {
        /* Wait for the bit to drop, then for it to rise. */
        start = timer_get_ticks16();
        while (timer_ticks_since(start) < FIRST_EDGE_LIMIT) {
            if (!(REG(OUTPUT_SYNC_STATUS) & SYNC_LEVEL))
                break;
        }
        while (timer_ticks_since(start) < SECOND_EDGE_LIMIT) {
            if (REG(OUTPUT_SYNC_STATUS) & SYNC_LEVEL)
                break;
        }
    } else {
        /* Polarity bit set: the same two waits with the levels the other way round. */
        start = timer_get_ticks16();
        while (timer_ticks_since(start) < FIRST_EDGE_LIMIT) {
            if (REG(OUTPUT_SYNC_STATUS) & SYNC_LEVEL)
                break;
        }
        while (timer_ticks_since(start) < SECOND_EDGE_LIMIT) {
            if (!(REG(OUTPUT_SYNC_STATUS) & SYNC_LEVEL))
                break;
        }
    }
}
