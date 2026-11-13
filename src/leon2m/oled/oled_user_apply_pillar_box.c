/* oled_user_apply_pillar_box  (FUN_a00dab90)
 *
 * Apply the pillar box setting, or 0 when the function is off.
 * Name basis: proven - oled_set_pillar_box
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dab90 @ 0xa00dab90, flags -mcpu=v8 -O2 -g.
 * Source form: the off case is written first, with its own call and return.
 */

/* The two bytes of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x1ec];
    unsigned char boundary_detection;      /* +0x1EC: Boundary Detection on (non-zero) or off */
    unsigned char boundary_level;          /* +0x1ED: the Boundary Detection level */
};
extern struct user_settings_record user_settings;
extern int oled_set_pillar_box(int);

/*
 * Send the Boundary Detection setting of the OLED Care menu to the OLED panel controller: the chosen level when
 * the detection is on, 0 when it is off. The firmware's messages for the controller call it "pillar box".
 */
void oled_user_apply_pillar_box(void)
{
    if (user_settings.boundary_detection == 0) {
        oled_set_pillar_box(0);
        return;
    }
    oled_set_pillar_box(user_settings.boundary_level);
}
