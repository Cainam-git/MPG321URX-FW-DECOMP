/* oled_user_apply_task_bar  (FUN_a00dabc8)
 *
 * Apply the task bar detection setting, or 0 when the function is off.
 * Name basis: proven - oled_set_task_bar
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dabc8 @ 0xa00dabc8, flags -mcpu=v8 -O2 -g (section default; -O3 -g gives the same bytes).
 * Source form: the off case is written first, with its own call and return.
 */

/* The two bytes of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x1ea];
    unsigned char taskbar_detection;       /* +0x1EA: Taskbar Detection on (non-zero) or off */
    unsigned char taskbar_level;           /* +0x1EB: the Taskbar Detection level */
};
extern struct user_settings_record user_settings;
extern int oled_set_task_bar(int);

/*
 * Send the Taskbar Detection setting of the OLED Care menu to the OLED panel controller: the chosen
 * level when the detection is on, 0 when it is off.
 */
void oled_user_apply_task_bar(void)
{
    if (user_settings.taskbar_detection == 0) {
        oled_set_task_bar(0);
        return;
    }
    oled_set_task_bar(user_settings.taskbar_level);
}
