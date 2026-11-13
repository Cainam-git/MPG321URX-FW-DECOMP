/* sys_set_channel_path_mode  (FUN_a0142418)
 *
 * Apply mode 0..4 to the signal path block of path 0 or 1, or switch the block off.
 * Name basis: descriptive - mode 0 switches the block off; other modes load an entry of the ROM mode table at
 *   0x1A6CB4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142418 @ 0xa0142418-0xa0142518, flags -mcpu=v8 -O3 -g.
 * Source form: the channel-to-block map is a static helper (r preset to 3, a switch for 0 and 1) whose result is
 * masked with '& 3' after the helper. Mode 0 returns right after its own sys_path_block_enable call; one call
 * with the last argument chosen by mode would compile to one shared call instead of the firmware's two.
 */
/* The tables are in ROM at 0x1A6CB4: 16 bytes per mode, indexed by mode. */
struct Rec;
struct Chan { unsigned int w0; };       /* channel record, word 0: port = bits 12..15, path = bits 1..3 */
struct Mode { struct Rec *record, *coefs_a, *coefs_b; unsigned short reg36_value; unsigned char reg48_bit5; };
extern const struct Mode sys_channel_path_modes[];
extern struct Chan *sys_find_channel_by_path(unsigned char id);
extern unsigned char pq_block_is_blanked(unsigned char);
extern void panel_wait_sync_pulse(void);
extern void sys_path_block_set_record(unsigned int blk, struct Rec *r);
extern void sys_path_block_set_coefficients(unsigned int blk, struct Rec *a, struct Rec *b);
extern void sys_path_block_set_reg36(unsigned int blk, unsigned int v);
extern void sys_path_block_set_reg48_bit5(unsigned int blk, unsigned char b);
extern void sys_path_block_enable(unsigned int blk, unsigned char b2, unsigned char on);

#define NO_PATH_BLOCK 3             /* path ids other than 0 and 1 have no signal path block */

/* Signal path block of path id ch: 0 and 1 are their own blocks, anything else is NO_PATH_BLOCK. */
static unsigned char path_block_of(unsigned char ch)
{
    unsigned char r = NO_PATH_BLOCK;

    switch (ch) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 1;
        break;
    }
    return r;
}

/*
 * Set up the signal path block of path 0 or 1 for a path mode, or switch it off.
 *
 *   ch    path id (0 or 1); it also finds the channel record whose path field (word 0 bits 1..3) equals it.
 *         Any other value does nothing.
 *   mode  0 switches the block off. Other values pick the row `mode` of the ROM table sys_channel_path_modes
 *         (1..4).
 *
 * If the channel's port is not in a blanking mode, panel_wait_sync_pulse is called first. A mode other than 0 then
 * loads the row's mode record, its two coefficient records, its register 0x36 value and its register 0x48
 * bit 5 value into the block and switches the block on.
 * Called by sys_mode_apply_converter_setup, sys_api_set_channel_scaling_mode and sys_api_config.
 */
void sys_set_channel_path_mode(unsigned char ch, int mode)
{
    struct Chan *chan = sys_find_channel_by_path(ch);
    unsigned int path_block = path_block_of(ch) & 3;

    if (path_block == NO_PATH_BLOCK)
        return;
    if (!pq_block_is_blanked((chan->w0 >> 12) & 0xf))
        panel_wait_sync_pulse();
    if (mode == 0) {
        sys_path_block_enable(path_block, (chan->w0 >> 12) & 0xf, 0);
        return;
    }
    sys_path_block_set_record(path_block, sys_channel_path_modes[mode].record);
    sys_path_block_set_coefficients(path_block, sys_channel_path_modes[mode].coefs_a, sys_channel_path_modes[mode].coefs_b);
    sys_path_block_set_reg36(path_block, sys_channel_path_modes[mode].reg36_value);
    sys_path_block_set_reg48_bit5(path_block, sys_channel_path_modes[mode].reg48_bit5);
    sys_path_block_enable(path_block, (chan->w0 >> 12) & 0xf, 1);
}
