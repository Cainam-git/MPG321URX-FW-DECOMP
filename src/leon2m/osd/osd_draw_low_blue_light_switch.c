/* osd_draw_low_blue_light_switch  (FUN_a00b6d58)
 *
 * Draw the Low Blue Light switch, shown off while HDR is active.
 * Note: Value = bit 4 of settings word +0x11C.
 * Name basis: proven - osd_draw_toggle_switch row 1 of the Professional items (Pro Mode, Low Blue Light, Image
 *   Enhancement)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b6d58 @ 0xa00b6d58 (-mcpu=v8 -O3 -g)
 * Both draw calls are tail calls; sys_user_get_picture_state takes no argument.
 */
#define PROFESSIONAL_ITEM_LOW_BLUE_LIGHT 1      /* item number of the switch among the Professional items */
#define LOW_BLUE_LIGHT_BIT 4                    /* bit of settings word +0x11C */

extern unsigned int user_settings_professional_flags;   /* settings word +0x11C */
extern void osd_draw_toggle_switch(unsigned char item, unsigned char on);
extern int sys_user_get_picture_state(void);

/* Draw the switch off whenever sys_user_get_picture_state returns non-zero; otherwise it shows the setting. */
void osd_draw_low_blue_light_switch(void)
{
    if (sys_user_get_picture_state() != 0) {
        osd_draw_toggle_switch(PROFESSIONAL_ITEM_LOW_BLUE_LIGHT, 0);
        return;
    }
    osd_draw_toggle_switch(PROFESSIONAL_ITEM_LOW_BLUE_LIGHT, (user_settings_professional_flags >> LOW_BLUE_LIGHT_BIT) & 1);
}
