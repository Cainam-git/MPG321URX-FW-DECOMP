/* osd_is_item_enabled  (FUN_a00aa520)
 *
 * Return 1 when an item of the open tab can be selected.
 *   sel: item index
 * Returns: 1 enabled, 0 greyed out
 * Note: Page from byte 0xA802B08F; tests depend on HDR, PIP/PBP and other settings.
 * Name basis: derived - called by every item step handler; disabled items are drawn with attribute 0x292
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aa520 @ 0xa00aa520, flags -mcpu=v8 -O3 -g.
 * Source form: old-style (K&R) definition of the byte parameter (zero-extended at each use); osd_list_id tested
 * with an if/else-if chain; the bit 31 test as w >> 31 on an unsigned word; the tests that stay branches in the
 * firmware (byte +0x178 / item 1, pip_pbp_mode == 2 / item 4, list 7) are nested ifs, the others && conditions.
 */
/* The fields of the user settings record that this routine reads. */
struct user_settings_head {
    unsigned char pad_0x0[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = single picture */
    unsigned char pad_0x20[0xa8 - 0x20];
    unsigned int gaming_flags;                  /* +0xA8: bit 11 = Professional (1) / Game (0) */
    unsigned char pad_0xac[0xb0 - 0xac];
    unsigned int blur_free_mode;                /* +0xB0 */
    unsigned char pad_0xb4[0x11c - 0xb4];
    unsigned int word_0x11c;                    /* +0x11C: bit 31 tested */
    unsigned char pad_0x120[0x174 - 0x120];
    unsigned int word_0x174;                    /* +0x174: bit 15 = the AI Vision switch */
    unsigned char byte_0x178;
    unsigned char pad_0x179[0x181 - 0x179];
    unsigned char pro_mode;                     /* +0x181 */
};
extern struct user_settings_head user_settings;
extern unsigned char osd_list_id;
extern int sys_user_get_picture_state(void);
extern unsigned char input_user_has_rate_mode(void);

#define GAMING_FLAG_PRO_MODE   0x800            /* gaming_flags bit 11 */
#define WORD_0X174_AI_VISION   0x8000

/*
 * Tell whether an item of the open item list can be selected; 0 means the item is drawn greyed out and is
 * skipped.
 *
 *   item  item row in the list
 *
 * The answer depends on the list that is open (osd_list_id) and on settings; every item not named below is
 * enabled. Let picture = sys_user_get_picture_state() != 0 and pro_range = (pro_mode - 4 <= 2 and the Pro flag
 * in gaming_flags is set), that is Professional mode 4..6.
 *   list 0       item 2 disabled when picture.
 *   list 1       items 1 and 2 disabled when picture; item 1 also when the AI Vision switch is on;
 *                item 6 when pip_pbp_mode is not 0.
 *   lists 2, 12  item 1 disabled when picture or pro_range.
 *   list 3       item 0 disabled when bit 31 of word_0x11c is set, or blur_free_mode is not 0 and
 *                input_user_has_rate_mode(), or picture; items 1 and 3 when pro_range or picture; item 1
 *                also when byte_0x178 is not 0; item 4 when pip_pbp_mode is 2; item 5 when pip_pbp_mode
 *                is not 0.
 *   list 7       item 6 disabled when pip_pbp_mode is not 0; item 7 when blur_free_mode is not 0 and
 *                input_user_has_rate_mode().
 * The number of an item list is the number of its tab (3 Image, 5 PIP/PBP, 7 Settings).
 *
 * Called by the step handlers of every item list (about 45 callers).
 */
unsigned char osd_is_item_enabled(item)
unsigned char item;
{
    if (osd_list_id == 0) {
        if (sys_user_get_picture_state() && item == 2)
            return 0;
    } else if (osd_list_id == 1) {
        if (sys_user_get_picture_state() && (item == 1 || item == 2))
            return 0;
        if ((user_settings.word_0x174 & WORD_0X174_AI_VISION) && item == 1)
            return 0;
        if (user_settings.pip_pbp_mode && item == 6)
            return 0;
    } else if (osd_list_id == 2 || osd_list_id == 12) {
        if (item == 1) {
            if (sys_user_get_picture_state())
                return 0;
            if ((unsigned char)(user_settings.pro_mode - 4) <= 2 && (user_settings.gaming_flags & GAMING_FLAG_PRO_MODE))
                return 0;
        }
    } else if (osd_list_id == 3) {
        if ((user_settings.word_0x11c >> 31 || (user_settings.blur_free_mode != 0 && input_user_has_rate_mode()) || sys_user_get_picture_state()) && item == 0)
            return 0;
        if ((unsigned char)(user_settings.pro_mode - 4) <= 2 && (user_settings.gaming_flags & GAMING_FLAG_PRO_MODE) && (item == 1 || item == 3))
            return 0;
        if (user_settings.byte_0x178)
            if (item == 1)
                return 0;
        if (sys_user_get_picture_state() && (item == 1 || item == 3))
            return 0;
        if (user_settings.pip_pbp_mode == 2)
            if (item == 4)
                return 0;
        if (user_settings.pip_pbp_mode && item == 5)
            return 0;
    } else if (osd_list_id == 6) {
    } else if (osd_list_id == 7) {
        if (user_settings.pip_pbp_mode)
            if (item == 6)
                return 0;
        if (user_settings.blur_free_mode == 0)
            return 1;
        if (!input_user_has_rate_mode())
            return 1;
        if (item == 7)
            return 0;
    }
    return 1;
}
