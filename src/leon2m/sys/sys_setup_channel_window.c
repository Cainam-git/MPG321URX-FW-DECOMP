/* sys_setup_channel_window  (FUN_a013d918)
 *
 * Set up the output window of a channel.
 * Name basis: derived - window coordinates for the channel's picture window, then the follow-up blocks
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013d918 @ 0xa013d918-0xa013dbcc, flags -mcpu=v8 -O3 -g.
 * Source form: h, dx, dy are unsigned short (16-bit call arguments; with int the firmware's zero-extension and add
 * operand order are lost); word 0 is read through c; one combined `ch == 0 && (...)` test; the ch == 3 test is
 * written `if (ch == 3 && bit) m = 1; else m = 2;` (bb-reorder lays it out of line); dx and dy are cleared first.
 * The test `blk == 0xff` can never be true (blk has four bits); the compiler keeps it.
 */

/* Channel record: word 0 = port (bits 12..15) and picture window (bits 4..7); word +0x40 holds flags; the
   halfwords from +0x4A are the applied timing (names as in the shared list). */
struct Chan
{
  unsigned int w0;
  unsigned char p04[0x3c];
  unsigned int w40;
  unsigned char p44[6];
  unsigned short width;
  unsigned short width_2;
  unsigned short x_extra;
  unsigned short x_offset;
  unsigned short lines;
  unsigned short lines_part;
  unsigned short y_offset;
  unsigned short y_extra;
  unsigned short x_position;
  unsigned short y_position;
  unsigned char rest[0x1a];
};
/* The active panel timing row (panel_active_row); only the fields read here are named. */
struct RawRow
{
  unsigned char p00[8];
  unsigned short active_width;
  unsigned short active_lines;
  unsigned char p0c[0x1a];
  unsigned short hblank_part;
  unsigned short hblank_part2;
  unsigned char p2a[6];
  unsigned short h30;
  unsigned short h32;
};
extern struct Chan channel_records[4];
extern struct RawRow panel_active_row;
extern unsigned int sys_config;
extern unsigned char sys_config_byte_3;
extern void pq_block_set_window_regs(unsigned int, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);
extern void pq_block_set_four_regs(unsigned int, unsigned short, unsigned short, unsigned short, unsigned short);
extern unsigned char pq_get_selected_window(void);
extern void pq_select_window(unsigned char);
extern void pq_window_set_rect(unsigned short, unsigned short, unsigned short, unsigned short);
extern void pq_block_set_regs_d0_d1(unsigned char, unsigned char, unsigned char);
extern void pq_block_set_regs_d0_d1(unsigned char, unsigned char, unsigned char);

#define SYS_CONFIG_CHANNEL3_BIT 0x200000    /* bit 21 of sys_config word 0 */
#define SYS_CONFIG_BIT26        0x4000000   /* bit 26 of sys_config word 0 */
#define CHANNEL_FLAG_BIT30      0x40000000  /* bit 30 of channel record word +0x40 */
#define WINDOW_FIELD_4          0x40        /* window field (word 0 bits 4..7) equal to 4 */

/*
 * Program the picture block of channel ch with the channel's window values, then set the position rectangle of
 * its picture window.
 *
 *   ch  channel number 0..3
 *
 * 1. Two values for block registers 0xA0 and 0xBE (reg_a0, reg_be) are chosen. Channel 0, when word 0 bit 0,
 *    word +0x40 bit 30 or bit 26 of sys_config is set, takes them from the active panel row (hblank_part
 *    and the halfword at +0x30). Otherwise reg_a0 is 0x10 and reg_be is 2, except that channel 3 with bit 21
 *    of sys_config gets 1.
 * 2. pq_block_set_window_regs gets width, lines, x_extra, y_extra, reg_a0 and reg_be; pq_block_set_four_regs gets
 *    width_2, lines_part, x_offset and y_offset. The block is the channel's port.
 * 3. Unless the window field is 4, the channel's window is selected and its rectangle is written, then the
 *    window that was selected before is selected again. The rectangle is:
 *      channel 0 with word 0 bit 0: x_offset and y_offset each less the two margins of the row (hblank_part +
 *        hblank_part2, and +0x30 + +0x32), then width_2 and lines_part;
 *      channel 0 with sys_config_byte_3: 0, 0 and the row's active_width and active_lines;
 *      otherwise: x_position and y_position, each moved by dx (x_offset - x_extra, when width_2 is below width)
 *        or dy (y_offset - y_y_extra, when lines_part is below lines), then width_2 and lines_part.
 * 4. Channel 3 only: pq_block_set_regs_d0_d1 gets its port with 0x3f and 0xff when bit 21 of sys_config is set,
 *    with 0x30 and 0xc0 otherwise.
 * Called by sys_apply_pip_layout_and_windows, sys_api_rebuild_channel_window and input_channel_bring_up_task.
 */
void sys_setup_channel_window(unsigned char ch)
{
    struct Chan *c;
    unsigned int blk;
    unsigned int w0;
    unsigned short reg_a0;
    unsigned int reg_be;
    unsigned char saved_window;
    unsigned short dx;
    unsigned short dy;

    dx = 0;
    dy = 0;
    c = &channel_records[ch];
    w0 = c->w0;
    blk = (w0 >> 12) & 0xf;
    if (blk == 0xff)            /* never true: blk has four bits */
        return;
    if (ch == 0 && ((w0 & 1) || (c->w40 & CHANNEL_FLAG_BIT30) || (sys_config & SYS_CONFIG_BIT26))) {
        /* these cases take both values from the active panel row */
        reg_a0 = panel_active_row.hblank_part;
        reg_be = panel_active_row.h30;
    } else {
        reg_a0 = 0x10;
        if (ch == 3 && (sys_config & SYS_CONFIG_CHANNEL3_BIT))
            reg_be = 1;
        else
            reg_be = 2;
    }
    pq_block_set_window_regs(blk, channel_records[ch].width, channel_records[ch].lines, channel_records[ch].x_extra, channel_records[ch].y_extra, reg_a0, reg_be);
    pq_block_set_four_regs(blk, channel_records[ch].width_2, channel_records[ch].lines_part, channel_records[ch].x_offset, channel_records[ch].y_offset);
    if ((c->w0 & 0xf0) != WINDOW_FIELD_4) {
        /* window field 4 is skipped here, as in sys_set_channel_enable */
        saved_window = pq_get_selected_window();
        pq_select_window((c->w0 >> 4) & 0xf);
        /* a width_2 or lines_part below width or lines shifts the window by the difference of the offsets */
        if (channel_records[ch].width_2 < channel_records[ch].width)
            dx = channel_records[ch].x_offset - channel_records[ch].x_extra;
        if (channel_records[ch].lines_part < channel_records[ch].lines)
            dy = channel_records[ch].y_offset - channel_records[ch].y_extra;
        if (ch == 0 && (c->w0 & 1))
            pq_window_set_rect(channel_records[0].x_offset - (panel_active_row.hblank_part + panel_active_row.hblank_part2),
                         channel_records[0].y_offset - (panel_active_row.h30 + panel_active_row.h32),
                         channel_records[0].width_2, channel_records[0].lines_part);
        else if (ch == 0 && sys_config_byte_3)
            pq_window_set_rect(0, 0, panel_active_row.active_width, panel_active_row.active_lines);
        else
            pq_window_set_rect(channel_records[ch].x_position + dx, channel_records[ch].y_position + dy, channel_records[ch].width_2, channel_records[ch].lines_part);
        pq_select_window(saved_window);
    }
    if (ch == 3) {
        if (sys_config & SYS_CONFIG_CHANNEL3_BIT)
            pq_block_set_regs_d0_d1((channel_records[3].w0 >> 12) & 0xf, 0x3f, 0xff);
        else
            pq_block_set_regs_d0_d1((channel_records[3].w0 >> 12) & 0xf, 0x30, 0xc0);
    }
}
