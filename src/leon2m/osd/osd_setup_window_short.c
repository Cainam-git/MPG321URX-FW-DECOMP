/* osd_setup_window_short  (FUN_a008a434)
 *
 * Run the short menu window set-up sequence and wait three sync pulses.
 * Note: No direct caller; osd_setup_window_full is the longer variant.
 * Name basis: descriptive - code only: calls the OSD window helpers FUN_a0146xxx
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008a434, flags -mcpu=v8 -O2 -g.
 * Source form: the callees are declared without a parameter list (as the decompiler had them); param_3 is
 * passed as an unsigned short and param_2 as its low byte where the calls take them so.
 */

extern void osd_api_reset_layer();
extern void osd_api_set_size_in_cells();
extern void osd_api_set_position();
extern void osd_api_write_reg_cc(unsigned short value, unsigned char arg);
extern void osd_api_set_window_enable();
extern void osd_api_enable();
extern void panel_wait_sync_pulse();

/*
 * Short window set-up of a menu layer: switch it off, set its window enable, size, position and register
 * 0xCC/0xCD value, wait three sync pulses, then reset the layer. The longer variant is osd_setup_window_full.
 * Nothing calls this routine directly.
 *   columns:      number of columns (low byte passed on)
 *   rows:         number of rows (low byte passed to the size call)
 *   cc_value:     value for registers 0xCC/0xCD (low 16 bits); also passed on to osd_api_reset_layer
 *   arg4..arg6:   passed on to osd_api_reset_layer after rows and cc_value; its first argument is 0
 */
void osd_setup_window_short(unsigned char columns, unsigned int rows, unsigned int cc_value, unsigned int arg4,
                            unsigned int arg5, unsigned int arg6)
{
  osd_api_enable(0, 0);
  osd_api_set_window_enable(8, 0, 0);
  osd_api_set_size_in_cells(columns, rows & 0xff, 0);
  osd_api_set_position(1, 0x62, 0);
  osd_api_write_reg_cc(cc_value & 0xffff, 0);
  panel_wait_sync_pulse();
  panel_wait_sync_pulse();
  panel_wait_sync_pulse();
  osd_api_reset_layer(0, rows, cc_value, arg4, arg5, arg6);
}
