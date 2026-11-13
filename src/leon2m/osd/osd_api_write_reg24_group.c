/* osd_api_write_reg24_group  (FUN_a0146370)
 *
 * Write a 24-bit value to register group 0..3 of a menu layer.
 * Name basis: derived - forwards to osd_write_reg24_group; selector 0..3 = groups 0xA0, 0xB0, 0xC0, 0xC1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146370, flags -mcpu=v8 -O2 -g (section default).
 * A switch with one tail call per case.
 */
#define GROUP_0 0xa0                    /* the four register group codes of osd_write_reg24_group */
#define GROUP_1 0xb0
#define GROUP_2 0xc0
#define GROUP_2_OFF 0xc1

extern void osd_write_reg24_group(unsigned int group, unsigned int value, unsigned char layer);

/* Write a 24-bit value to register group 0..3 of a menu layer: the group number is turned into the group code
 * 0xA0, 0xB0, 0xC0 or 0xC1 and osd_write_reg24_group is called. Other group numbers do nothing.
 *   group: 0..3
 *   value: the value
 *   layer: menu layer number
 * Called by osd_setup_window_full, osd_draw_factory_info_page, osd_draw_factory_menu, ShowLogo, osd_set_layout and others.
 */
void osd_api_write_reg24_group(unsigned char group, unsigned int value, unsigned char layer)
{
    switch (group) {
    case 0:
        osd_write_reg24_group(GROUP_0, value, layer);
        break;
    case 1:
        osd_write_reg24_group(GROUP_1, value, layer);
        break;
    case 2:
        osd_write_reg24_group(GROUP_2, value, layer);
        break;
    case 3:
        osd_write_reg24_group(GROUP_2_OFF, value, layer);
        break;
    }
}
