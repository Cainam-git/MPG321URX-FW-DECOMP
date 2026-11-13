/* sys_set_channel_window_size  (FUN_a013d684)
 *
 * Compute the window size of a channel from its timing and program it.
 * Name basis: derived - width from the channel record with a margin, rounded to a multiple of 8; then the size
 *   registers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013d684 @ 0xa013d684-0xa013d918, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the port selection is `sel = 0;` followed by a switch with the cases 0..3 and no default (the firmware's
 *    compare tree has root 1 and a 4-node list; the compiler then copies the second call block into each case);
 *  - the ch 1 step is written with channel_records[ch] again (the address becomes base + 0x78);
 *  - 120u and 102u: the firmware multiplies unsigned (umul);
 *  - the second sys_frc_set_port_size call is a tail call.
 */
/* Channel record. Word 0: port = bits 12..15. Halfwords from +0x48 on are the applied timing (field names as in
   the shared list: htotal, width, width_2, x_extra, x_offset, lines, lines_part, y_offset, y_extra,
   x_position, y_position). */
struct Chan {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x48 - 0x04];
    unsigned short htotal, width, width_2, x_extra, x_offset, lines, lines_part, y_offset, y_extra, x_position, y_position, h5e;
    unsigned char p60[0x78 - 0x60];
};
extern struct Chan channel_records[4];
extern unsigned char sys_config_byte_3, device_settings_pip_mode;
extern unsigned short panel_active_row_htotal;
extern void sys_frc_set_port_size_first(unsigned char sel, unsigned short a, unsigned short b, unsigned short c);
extern void sys_frc_set_port_size_second(unsigned char sel, unsigned short a, unsigned short b);

#define MIN_GAP_CHANNEL0 0xd0       /* smallest htotal - width_2 of channel 0 */
#define MIN_GAP_OTHERS   0xe0       /* the same for the other channels */

/*
 * Work out the total width (htotal) of channel ch from its width_2, then pass the channel's size values to the
 * frame-rate converter registers of its port.
 *
 *   ch  channel number 0..3
 *
 * Channel 0 with sys_config_byte_3 set and no picture-in-picture (mode 0) takes the horizontal total of the
 * active panel row. Every other case computes htotal in this order: width_2 plus 20 percent; for channel 1 a
 * further 2 percent; at least MIN_GAP_CHANNEL0 (channel 0) or MIN_GAP_OTHERS (others) above width_2; then
 * rounded up to a multiple of 8.
 * The port field of the record (0..3, anything else counts as 0) selects the register pair: first
 * x_position and y_position go to sys_frc_set_port_size_first (lines_part is passed too, but that routine
 * takes two values), then width and lines go to sys_frc_set_port_size_second.
 * Called by sys_apply_pip_layout_and_windows (all four channels), sys_api_rebuild_channel_window,
 * sys_api_update_channel_window_size and input_channel_bring_up_task.
 */
void sys_set_channel_window_size(unsigned char ch)
{
    unsigned char lim = MIN_GAP_CHANNEL0;
    unsigned char sel;

    if (ch == 0 && sys_config_byte_3 != 0 && device_settings_pip_mode == 0) {
        channel_records[ch].htotal = panel_active_row_htotal;
    } else {
        channel_records[ch].htotal = channel_records[ch].width_2 * 120u / 100;
        if (ch == 1)
            channel_records[ch].htotal = channel_records[ch].htotal * 102u / 100;
        if (ch != 0)
            lim = MIN_GAP_OTHERS;
        if ((int)(channel_records[ch].htotal - channel_records[ch].width_2) < lim)
            channel_records[ch].htotal = channel_records[ch].width_2 + lim;
        if (channel_records[ch].htotal & 7)
            channel_records[ch].htotal = (channel_records[ch].htotal >> 3) * 8 + 8;
    }
    sel = 0;
    switch (channel_records[ch].u.b.port) {
    case 0: sel = 0; break;
    case 1: sel = 1; break;
    case 2: sel = 2; break;
    case 3: sel = 3; break;
    }
    sys_frc_set_port_size_first(sel & 3, channel_records[ch].x_position, channel_records[ch].y_position, channel_records[ch].lines_part);
    sel = 0;
    switch (channel_records[ch].u.b.port) {
    case 0: sel = 0; break;
    case 1: sel = 1; break;
    case 2: sel = 2; break;
    case 3: sel = 3; break;
    }
    sys_frc_set_port_size_second(sel & 3, channel_records[ch].width, channel_records[ch].lines);
}
