/* input_block_set_config  (FUN_a01207f4)
 *
 * Store the 12-byte configuration of an input block.
 * Name basis: derived - table at 0xA8027AAC; called from System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01207f4 @ 0xa01207f4, flags -mcpu=v8 -O3 -g.
 * Source form: a plain structure assignment; the entries have 4-byte alignment, so the compiler copies them as
 * three ld/st pairs.
 */

/* One entry of input_block_configs (12 bytes). */
struct input_block_config {
    unsigned int word_0;
    unsigned int word_4;                    /* 1: selects the other scale in input_block_measure_vfreq and the
                                               other register value in input_block_set_sync_thresholds */
    unsigned int word_8;
};
extern struct input_block_config input_block_configs[];

/*
 * Copy a three-word configuration into entry blk of input_block_configs.
 *
 * Called four times from System_Initialize. Word 0 is read by input_block_power, word 4 by input_block_measure_vfreq,
 * input_block_measure_pixel_clock and input_block_set_sync_thresholds.
 */
void input_block_set_config(unsigned char blk, struct input_block_config *config)
{
    input_block_configs[blk] = *config;
}
