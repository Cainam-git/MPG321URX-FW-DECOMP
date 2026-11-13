/* panel_output_pulse_rate_update  (FUN_a010b6e4)
 *
 * Set bits 10 and 14 of register 0xF0 of both output halves, wait for two sync pulses, clear them.
 * Name basis: descriptive - bits 10 and 14 of 0xD00300F0 / 0xD00380F0; two calls of panel_wait_sync_pulse;
 *   called by pq_block_show for block 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010b6e4, flags -mcpu=v8 -O3 -g.
 * Source form: every step is its own read-modify-write on a volatile word (not one '|= 0x4400'); void(void).
 */
#define OUTPUT_HALF0_REG_F0 (*(volatile unsigned int *)0xd00300f0)
#define OUTPUT_HALF1_REG_F0 (*(volatile unsigned int *)0xd00380f0)

#define BIT_10 0x400
#define BIT_14 0x4000

extern void panel_wait_sync_pulse(void);

/*
 * Set bit 10 and then bit 14 in register 0xF0 of both output halves (0xD00300F0 and 0xD00380F0, first half
 * before second half), call the ROM routine panel_wait_sync_pulse twice, then clear bit 10 and bit 14 in the same
 * order. Takes no input.
 * Called by pq_block_show (pq_block_show) for block 0, after pq_block_set_output_path.
 */
void panel_output_pulse_rate_update(void)
{
    OUTPUT_HALF0_REG_F0 |= BIT_10;
    OUTPUT_HALF1_REG_F0 |= BIT_10;
    OUTPUT_HALF0_REG_F0 |= BIT_14;
    OUTPUT_HALF1_REG_F0 |= BIT_14;
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    OUTPUT_HALF0_REG_F0 &= ~BIT_10;
    OUTPUT_HALF1_REG_F0 &= ~BIT_10;
    OUTPUT_HALF0_REG_F0 &= ~BIT_14;
    OUTPUT_HALF1_REG_F0 &= ~BIT_14;
}
