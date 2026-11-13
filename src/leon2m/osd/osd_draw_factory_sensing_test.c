/* osd_draw_factory_sensing_test  (FUN_a008ac00)
 *
 * Draw ON or OFF for the factory menu item "Sensing Test" (saved setting 0x10)
 * Note: Nothing calls it directly; the same drawing is inlined in osd_draw_factory_menu.
 * Name basis: derived - draws ROM 'OFF'/'ON' at item 23, whose label is 'Sensing Test' in
 *   osd_draw_factory_menu
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008ac00, flags -mcpu=v8 -O3 -g.
 */

extern const unsigned char osd_factory_layout_sensing_test;
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern unsigned short nvram_get_device_setting(unsigned int);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);

#define DEVICE_SETTING_SENSING_TEST 0x10        /* index passed to nvram_get_device_setting */
#define SENSING_TEST_VALUE_ROW      0x13

/*
 * Draw "ON " or "OFF" (a length byte of 3 comes first in each text) in the value field of factory menu item 23,
 * Sensing Test, for device setting 0x10. The column is the first byte of the item's layout entry plus 11.
 */
void osd_draw_factory_sensing_test(void)
{
    osd_api_set_glyph_write_address(0xf7, 0);
    if (nvram_get_device_setting(DEVICE_SETTING_SENSING_TEST) != 0)
        osd_draw_text(0, osd_factory_layout_sensing_test + 0xb, SENSING_TEST_VALUE_ROW, 3, "\003" "ON ", 0);
    else
        osd_draw_text(0, osd_factory_layout_sensing_test + 0xb, SENSING_TEST_VALUE_ROW, 3, "\003" "OFF", 0);
}
