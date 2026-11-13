/* pq_block_show  (FUN_a0106b08)
 *
 * Switch a picture block's output on, wait three sync pulses and switch the colour-fill path off.
 * Note: Blocks 0..3 only; block 0 also gets the rate update pulse.
 * Name basis: derived - register 0x54 = 0, output path on, three sync pulse waits, rate update pulse for block
 *   0, colour-fill path off (bit 7 of 0xCF00E9C4)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0106b08 @ 0xa0106b08, flags -mcpu=v8 -O3 -g.
 * Source form: the three waits are separate statements; the colour-fill steps at the end are written out here
 * (the same steps as pq_set_color_fill_enable(0)), with the saved word cut to its low byte at the write.
 */
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void pq_block_set_output_path(unsigned char blk, unsigned char val);
extern void panel_output_pulse_rate_update(void);
extern void panel_wait_sync_pulse(void);   /* panel_wait_sync_pulse: wait for one sync pulse */

#define PQ_GAMMA_REG_EAC8 (*(volatile unsigned int *)0xcf00eac8)   /* bit 4 cleared while the fill bit changes */
#define COLOR_FILL_CTRL (*(volatile unsigned int *)0xcf00e9c4)     /* bit 7: the colour-fill path */

#define BLK_BLANK_MODE 0x54
#define OUTPUT_PATH_ON 1

/*
 * Switch a picture block's output on (blocks 0..3; any other block: nothing is done).
 *
 * Steps: BLK_BLANK_MODE = 0, output path on (pq_block_set_output_path(block, 1)), three sync pulse waits; for
 * block 0 also panel_output_pulse_rate_update. Last, the colour-fill path is switched off as in
 * pq_set_color_fill_enable(0): bit 4 of PQ_GAMMA_REG_EAC8 is cleared, bit 7 of COLOR_FILL_CTRL cleared, and the
 * saved low byte written back (bit 4 as before, bits 8..31 cleared).
 *
 * Callers: input_bring_up_set_pixel_clock and input_channel_bring_up_task.
 */
void pq_block_show(unsigned char block)
{
    if (block <= 3) {
        pq_block_write8(block, BLK_BLANK_MODE, 0);
        pq_block_set_output_path(block, OUTPUT_PATH_ON);
        panel_wait_sync_pulse();
        panel_wait_sync_pulse();
        panel_wait_sync_pulse();
        if (block == 0) {
            panel_output_pulse_rate_update();
        }
        /* Colour-fill path off. */
        unsigned int gamma_reg_value = PQ_GAMMA_REG_EAC8;
        PQ_GAMMA_REG_EAC8 &= ~0x10;
        COLOR_FILL_CTRL &= ~0x80;
        PQ_GAMMA_REG_EAC8 = gamma_reg_value & 0xff;
    }
}
