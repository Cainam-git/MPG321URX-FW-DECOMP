/* dp_tx_refresh_reg73  (FUN_a008996c)
 *
 * Refresh register 0x73 of a DP output on a timer while bit 0 of reg 0x7B is set.
 *   port: DP output 0..4
 * Name basis: descriptive - timed read and rewrite of register 0x73 using the 8-byte records 0xA807CD04
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: each arm stores rewritten_ticks itself (the compiler merges the two tails); one shared store
 * after the if/else schedules the arguments of the first dp_tx_reg_read8(port, 0x73) call in the other order.
 */
/* 8-byte pacing record of one DP output (dp_tx_pacing_records), as in DPTX_SetBrilliantMode. */
struct pacing_record {
    unsigned char enabled;              /* 0: this output is skipped by DPTX_SetBrilliantMode */
    unsigned char updated;              /* set to 1 when DPTX_SetBrilliantMode wrote the registers */
    unsigned short updated_ticks;       /* timer_get_ticks() at that moment */
    unsigned char rewritten;            /* set to 1 when register 0x73 was written back */
    unsigned char byte_0x05;
    unsigned short rewritten_ticks;     /* timer_get_ticks() when register 0x73 was last written or read */
};

extern struct pacing_record dp_tx_pacing_records[];
extern unsigned char dp_tx_reg_read8(unsigned int, unsigned short);
extern void dp_tx_reg_write8(unsigned char, unsigned short, unsigned char);
extern unsigned int timer_get_ticks(void);

#define TX_REG_PACE_C        0x7b       /* DPTX_SetBrilliantMode sets bit 0 of it after an update */
#define TX_REG_0x73          0x73
#define REWRITE_DELAY_TICKS  40         /* after the pacing update */
#define REREAD_PERIOD_TICKS  100        /* between reads once register 0x73 was written back */

/*
 * Timed handling of register 0x73 of a DP output, only while bit 0 of register 0x7B is set.
 *
 *   port: DP output 0..4
 *
 * After DPTX_SetBrilliantMode marked the record as updated and more than 40 ticks passed, the value of
 * register 0x73 is written back to itself and the record is marked as rewritten. From then on register 0x73
 * is read again whenever more than 100 ticks passed since the last access.
 */
void dp_tx_refresh_reg73(unsigned char port)
{
    struct pacing_record *record;

    if (!(dp_tx_reg_read8(port, TX_REG_PACE_C) & 1))
        return;
    record = &dp_tx_pacing_records[port];
    if (record->rewritten) {
        if (timer_get_ticks() - record->rewritten_ticks <= REREAD_PERIOD_TICKS)
            return;
        dp_tx_reg_read8(port, TX_REG_0x73);
        record->rewritten_ticks = timer_get_ticks();
    } else {
        if (!record->updated)
            return;
        if (timer_get_ticks() - record->updated_ticks <= REWRITE_DELAY_TICKS)
            return;
        dp_tx_reg_write8(port, TX_REG_0x73, dp_tx_reg_read8(port, TX_REG_0x73));
        record->rewritten = 1;
        record->updated = 0;
        record->rewritten_ticks = timer_get_ticks();
    }
}
