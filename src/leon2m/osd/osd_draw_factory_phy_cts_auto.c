/* osd_draw_factory_phy_cts_auto  (FUN_a008ac90)
 *
 * Draw ON or OFF for the factory menu item "PHY CTS AUTO" (saved setting 2)
 * Note: Nothing calls it directly; the same drawing is inlined in osd_draw_factory_menu.
 * Name basis: proven - docs/MAP.md: item 24 = PHY CTS AUTO = setting 2; ROM 'OFF'/'ON'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008ac90, flags -mcpu=v8 -O3 -g.
 */

extern const unsigned char osd_factory_layout_phy_cts_auto;
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern unsigned short nvram_get_device_setting(unsigned int);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);

#define DEVICE_SETTING_PHY_CTS_AUTO 2           /* index passed to nvram_get_device_setting */
#define PHY_CTS_AUTO_VALUE_ROW      0x14

/*
 * Draw "ON " or "OFF" (a length byte of 3 comes first in each text) in the value field of factory menu item 24,
 * PHY CTS AUTO, for device setting 2. The column is the first byte of the item's layout entry plus 11.
 */
void osd_draw_factory_phy_cts_auto(void)
{
    osd_api_set_glyph_write_address(0xd3, 0);
    if (nvram_get_device_setting(DEVICE_SETTING_PHY_CTS_AUTO) != 0)
        osd_draw_text(0, osd_factory_layout_phy_cts_auto + 0xb, PHY_CTS_AUTO_VALUE_ROW, 3, "\003" "ON ", 0);
    else
        osd_draw_text(0, osd_factory_layout_phy_cts_auto + 0xb, PHY_CTS_AUTO_VALUE_ROW, 3, "\003" "OFF", 0);
}
