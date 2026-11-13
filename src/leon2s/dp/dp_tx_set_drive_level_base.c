/* dp_tx_set_drive_level_base  (FUN_a00ab548)
 *
 * Store the base swing and pre-emphasis values of one lane of a DP output.
 *   selector: output | lane << 4
 *   swing
 *   pre_emphasis: pre-emphasis
 * Name basis: derived - 16-byte records 0xA80792B4 read by dp_tx_set_drive_levels; mailbox command 0x59
 *
 * Matching notes
 * --------------
 * FUN_a00ab548 (leon2s), flags -mcpu=v8 -Os -g. Leaf.
 */
/* Record of 16 bytes per output; dp_tx_set_drive_levels adds table values to the base values and writes the
 * sums into the first and third group. */
struct dp_tx_drive_record {
    unsigned char swing[4];                     /* +0 */
    unsigned char base_swing[4];                /* +4: stored here */
    unsigned char pre_emphasis[4];              /* +8 */
    unsigned char base_pre_emphasis[4];         /* +0xC: stored here */
};
extern struct dp_tx_drive_record dp_tx_drive_level_records[];

/*
 * Store the base swing and base pre-emphasis of one lane of one output.
 *   selector: output in the low nibble, lane in the high nibble
 *   swing: base swing
 *   pre_emphasis: base pre-emphasis
 * Does nothing when the output is above 4.
 */
void dp_tx_set_drive_level_base(unsigned char selector, unsigned char swing, unsigned char pre_emphasis)
{
    unsigned char output = selector & 0xf;
    unsigned char lane = selector >> 4;

    if (output <= 4) {
        dp_tx_drive_level_records[output].base_swing[lane] = swing;
        dp_tx_drive_level_records[output].base_pre_emphasis[lane] = pre_emphasis;
    }
}
