/* osd_user_apply_menu_position  (FUN_a00d472c)
 *
 * Apply the menu position settings.
 * Name basis: derived - settings bytes +0x0D / +0x0E limited to 100, then osd_api_set_position
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d472c @ 0xa00d472c-0xa00d477c (20 words), flags -mcpu=v8 -O3 -g.
 * Leaf frame; the call is a tail call.
 * Source form: the real base address as a struct (not the mid-record labels); 16-bit clamp variables (the
 * constant 100 is built as an unsigned halfword); osd_api_set_position has its real (unsigned short, unsigned
 * short, unsigned char) prototype.
 */
#define MENU_POSITION_MAX 100                   /* largest accepted value of each position byte */

struct user_settings_record {
    unsigned char pad[0xd];
    unsigned char menu_position_a;              /* +0xD: first argument of osd_api_set_position */
    unsigned char menu_position_b;              /* +0xE: second argument */
};
extern struct user_settings_record user_settings;
extern void osd_api_set_position(unsigned short, unsigned short, unsigned char);

/* Place the menu layer from the two position bytes of the settings (+0xD, +0xE), each limited to 100. */
void osd_user_apply_menu_position(void)
{
    struct user_settings_record *settings = &user_settings;
    unsigned short position_a = settings->menu_position_a;
    unsigned short position_b = settings->menu_position_b;

    if (position_a > MENU_POSITION_MAX)
        position_a = MENU_POSITION_MAX;
    if (position_b > MENU_POSITION_MAX)
        position_b = MENU_POSITION_MAX;
    osd_api_set_position(position_a, position_b, 0);
}
