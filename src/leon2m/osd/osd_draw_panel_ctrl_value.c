/* osd_draw_panel_ctrl_value  (FUN_a008abe0)
 *
 * Draw the panel controller's register value in factory menu field 0x15.
 * Note: Value from oled_get_lum_mode (I2C device 0x60, register 0x1E).
 * Name basis: derived - docs/MAP.md: panel controller at I2C address 0x60
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008abe0, flags -mcpu=v8 -O2 -g.
 * Tail call; oled_get_lum_mode returns an unsigned short and takes no argument.
 */

#define FACTORY_ITEM_PANEL_NPC 0x15             /* factory menu item 21 */

extern unsigned short oled_get_lum_mode(void);
extern void osd_draw_factory_number(unsigned char, unsigned short);

/* Draw the luminance mode read back from the panel controller in factory menu item 21 (PANEL_NPC). */
void osd_draw_panel_ctrl_value(void)
{
  osd_draw_factory_number(FACTORY_ITEM_PANEL_NPC, oled_get_lum_mode());
}
