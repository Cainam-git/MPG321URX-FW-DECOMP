/* input_is_timing_out_of_range  (FUN_a013ba14)
 *
 * Return 1 when a port's line rate or refresh rate is outside the accepted range.
 * Returns: 1 out of range, 0 in range or for one of fourteen listed mode ids
 * Note: Ranges: line rate 0x96..0x1964 (100 Hz units), refresh rate 0xC8..0x992 (tenths of Hz). The bring-up
 *   task copies the result to channel flag bit 29.
 * Name basis: derived - range tests on channel record +6 and +8; the caller sets channel flag bit 29 on 1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013ba14 @ 0xa013ba14-0xa013bb50 (79 words), flags -mcpu=v8 -O3 -g.
 * Source form: the first pair of mode ids is one '(mode_id == 0x5b01 || mode_id == 0x5c01) == 0' test (gcc folds only
 * that pair into the fw xor/subx/orcc store-flag; a '!(...)' gives De Morgan addx/btst); the other 12 ids are
 * separate 'goto listed' tests into ONE shared 'is_listed = 1' block (the fw single 'mov 1' block; else-if arms give
 * separate blocks and the last one is if-converted); the line-rate range is two ifs (one || is folded into a range
 * test); 'if (refresh_rate >= 0x993) return 1; return 0;' (fw subx). The flag 'int is_listed' is tested
 * 'if (is_listed & 1)': a plain 'if (is_listed)' lets jump bypassing thread the flag away, and an unsigned char
 * flag gives 'btst 0xff' instead of the fw 'cmp %g1, 0'. Same 'b & 1' flag lever as in input_block_check_signal. Aids: none
 * (no volatile, no asm, no hint).
 */
/* The channel record, up to the fields used here: line rate (100 Hz units), refresh rate (tenths of Hz), mode id. */
struct channel_record_timing {
    unsigned char pad_0[6];
    unsigned short line_rate;       /* +6 */
    unsigned short refresh_rate;    /* +8 */
    unsigned char pad_0a[0x3c - 0x0a];
    unsigned short mode_id;         /* +0x3c: id of the matched row of input_mode_table */
};
extern struct channel_record_timing *sys_find_channel_by_port(unsigned char port);

/*
 * Test the matched mode id and the measured line rate and refresh rate of a port; the result is flag bit 29 of its channel.
 *
 *   port   port number (looked up in the channel records)
 *
 * Returns 0 when the mode id of the channel (the id of the mode-table row input_match_port_mode matched) is one
 * of the fourteen ids 0x5b01, 0x5c01, 0x5d01, 0x800, 0x5f01, 0x6001, 0x6101, 0x5800, 0x5900, 0x2200, 0x5700,
 * 0x5a00, 0x6301, 0x6201 (the same list as input_is_mode_id_listed). Otherwise returns 1 when the line rate is
 * outside 0x96..0x1964 or the refresh rate is outside 0xc8..0x992, and 0 when both are inside.
 *
 * Called by input_channel_bring_up_task right after input_match_port_mode; it sets bit 29 of the channel flags
 * (+0x70) when the result is 1 and clears it when 0.
 */
unsigned char input_is_timing_out_of_range(unsigned char port)
{
    struct channel_record_timing *record = sys_find_channel_by_port(port);
    unsigned short mode_id = sys_find_channel_by_port(port)->mode_id;
    int is_listed;
    if ((mode_id == 0x5b01 || mode_id == 0x5c01) == 0) {
        if (mode_id == 0x5d01)
            goto listed;
        if (mode_id == 0x800)
            goto listed;
        if (mode_id == 0x5f01)
            goto listed;
        if (mode_id == 0x6001)
            goto listed;
        if (mode_id == 0x6101)
            goto listed;
        if (mode_id == 0x5800)
            goto listed;
        if (mode_id == 0x5900)
            goto listed;
        if (mode_id == 0x2200)
            goto listed;
        if (mode_id == 0x5700)
            goto listed;
        if (mode_id == 0x5a00)
            goto listed;
        if (mode_id == 0x6301)
            goto listed;
        if (mode_id == 0x6201)
            goto listed;
        is_listed = 0;
        goto done;
    }
listed:
    is_listed = 1;
done:
    if (is_listed & 1)
        return 0;
    if (record->line_rate <= 0x95)
        return 1;
    if (record->line_rate > 0x1964)
        return 1;
    if (record->refresh_rate <= 0xc7)
        return 1;
    if (record->refresh_rate >= 0x993)
        return 1;
    return 0;
}
