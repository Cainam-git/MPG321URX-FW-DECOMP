/* osd_draw_ai_vision_switch  (FUN_a00b6994)
 *
 * Draw the AI Vision switch of the Gaming page; OFF while the picture state code is not 0.
 * Note: Value = bit 15 of settings word +0x174, shown only while sys_user_get_picture_state returns 0.
 * Name basis: derived - osd_draw_toggle_switch(2, ...); called by osd_draw_gaming_items
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b6994 @ 0xa00b6994, flags -mcpu=v8 -O3 -g.
 * Source form: both osd_draw_toggle_switch calls are tail calls (the first arm returns after its call).
 */
extern unsigned int user_settings_word_0x174;   /* settings word +0x174; bit 15 = the AI Vision switch */
extern void osd_draw_toggle_switch(unsigned char item, unsigned char on);
extern int sys_user_get_picture_state(void);

#define GAMING_ITEM_AI_VISION 2     /* item row of the Gaming page */
#define AI_VISION_BIT         0xf   /* bit of word +0x174 */

/* Draw the Gaming AI Vision switch (item row 2): OFF when sys_user_get_picture_state() is not 0, otherwise
 * the state of bit 15 of the settings word at +0x174. Called by osd_draw_gaming_items. */
void osd_draw_ai_vision_switch(void)
{
    if (sys_user_get_picture_state() != 0) {
        osd_draw_toggle_switch(GAMING_ITEM_AI_VISION, 0);
        return;
    }
    osd_draw_toggle_switch(GAMING_ITEM_AI_VISION, (user_settings_word_0x174 >> AI_VISION_BIT) & 1);
}
