/* osd_setup_window_full  (FUN_a008a4a8)
 *
 * Run the full menu window set-up sequence, including tables, and wait three sync pulses.
 * Note: No direct caller.
 * Name basis: descriptive - code only: calls the OSD window helpers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008a4a8, flags -mcpu=v8 -O2 -g.
 * Source forms: the callees whose results are unused are declared void, which gives the firmware's argument
 * set-up for the two osd_api_enable(0, 0) calls (clr %o0 before the call, clr %o1 in the delay slot); the
 * assignment arg1 = 0 before the font_load_layout0_glyphs call produces the firmware's clr %i0.
 */

extern void osd_api_enable(int, int);                 /* 0xa0146dc0 */
extern void osd_api_set_cell_size_mode(int, int);                 /* 0xa0146298 */
extern void osd_api_set_layer_byte_pair(int, int, int);            /* 0xa0146354 */
extern int osd_api_cell_count_plus_one(int, int);                  /* 0xa0146194 */
extern void osd_api_write_reg24_group(int, int, int);            /* 0xa0146370 */
extern void font_load_layout0_glyphs(void);                     /* 0xa00a28bc */
extern void osd_api_set_window_enable(int, int, int);            /* 0xa0146c40 */
extern void osd_api_set_size_in_cells(int, int, int);            /* 0xa014613c */
extern void osd_api_set_position(int, int, int);            /* 0xa0146518 */
extern void osd_api_write_reg_cc(int, int);                 /* 0xa0146ab0 */
extern void panel_wait_sync_pulse(void);                  /* 0x4008e2a4 */
extern void osd_api_reset_layer(int, int, int, int, int, int); /* 0xa0146108 */

/*
 * Full window set-up of a menu layer: set cell size mode 4 and a 24 x 37 cell size, load the layout 0 glyphs,
 * then set the window enable, size, position and register 0xCC/0xCD value, wait three sync pulses and reset the
 * layer. The shorter variant is osd_setup_window_short. Nothing calls this routine directly.
 *   arg1..arg6: passed on to osd_api_reset_layer; arg1 is replaced by 0 first
 */
void osd_setup_window_full(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{
    int cells_plus_one;

    osd_api_enable(0, 0);
    osd_api_set_cell_size_mode(4, 0);
    osd_api_set_layer_byte_pair(0x18, 0x24, 0);
    cells_plus_one = osd_api_cell_count_plus_one(0x18, 0x25);
    osd_api_write_reg24_group(0, (unsigned short)cells_plus_one, 0);
    arg1 = 0;
    font_load_layout0_glyphs();
    osd_api_enable(0, 0);
    osd_api_set_window_enable(8, 0, 0);
    osd_api_set_size_in_cells(0x18, 0x25, 0);
    osd_api_set_position(1, 0x62, 0);
    osd_api_write_reg_cc(0x790, 0);
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    osd_api_reset_layer(arg1, arg2, arg3, arg4, arg5, arg6);
}
