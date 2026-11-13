/* osd_flip_low_blue_light_setting  (FUN_a00b6d94)
 *
 * Flip the Low Blue Light setting, redraw its switch and save the mode slot.
 * Note: Turning it on clears settings byte +0x178; sets the settings-changed request (bit 1 of 0xA802B08E).
 * Name basis: proven - only caller osd_toggle_low_blue_light; bit 4 of +0x11C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b6d94 @ 0xa00b6d94-0xa00b6e1c (34 words), flags -mcpu=v8 -O3 -g.
 * Source form: the Low Blue Light bit is a 1-bit bit-field of the word at +0x11C, as the firmware tests and
 * flips it in place. The non-zero result of sys_user_get_picture_state is the first if arm.
 */
#define PROFESSIONAL_ITEM_LOW_BLUE_LIGHT 1      /* item number of the switch among the Professional items */
#define OSD_REQUEST_SETTINGS_CHANGED     0x02   /* bit 1 of osd_request_bits */

/* The part of the user settings record used here. */
struct user_settings_record {
    unsigned char pad[0x11c];
    unsigned int  word_0x11c_high : 27,
                  low_blue_light  : 1,          /* bit 4 of the word at +0x11C */
                  word_0x11c_low  : 4;
    unsigned char pad120[0x58];
    unsigned char byte_0x178;                   /* cleared when Low Blue Light is turned on */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern int sys_user_get_picture_state(void);
extern void osd_draw_toggle_switch(unsigned char, unsigned char);
extern void sys_user_save_mode_slot(void);

/* Toggle Low Blue Light, redraw its switch (drawn off when sys_user_get_picture_state is non-zero), save the
   mode slot and request a settings-changed event. */
void osd_flip_low_blue_light_setting(void)
{
    if (user_settings.low_blue_light)
        user_settings.low_blue_light = 0;
    else {
        user_settings.low_blue_light = 1;
        user_settings.byte_0x178 = 0;
    }
    if (sys_user_get_picture_state())
        osd_draw_toggle_switch(PROFESSIONAL_ITEM_LOW_BLUE_LIGHT, 0);
    else
        osd_draw_toggle_switch(PROFESSIONAL_ITEM_LOW_BLUE_LIGHT, user_settings.low_blue_light);
    sys_user_save_mode_slot();
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
