/* sys_set_key_modes_for_menu  (FUN_a0091094)
 *
 * Set the key repeat and long-press rules for the current menu state.
 * Note: Menu closed or message shown: no repeat, long press on 0x49, 0x42 long = 0x43; menus: repeat on
 *   0x45..0x48.
 * Name basis: derived - calls sys_set_key_repeat / _long_press / _long_press_alt by osd_get_menu_state
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0091094 @ 0xa0091094-0xa00911a0 (67 words), flags -mcpu=v8 -O3 -g.
 * Code facts: s = word osd_menu_state. If s is 0, 0x10b, 0x10c, 0x10d, 0x10e, 0x10f or 0x110 (the
 * first two tests are branch-free subx flags joined by orcc): sys_set_key_repeat(0xff, 0);
 * sys_set_key_long_press(0x49, 1); tail sys_set_key_long_press_alt(0x42, 0x43). Else if s - 0x108 < 2: sys_set_key_repeat for
 * 0x45, 0x46, 0x47, 0x48 (each with 1), tail sys_set_key_long_press_alt(0xff, 0). Else: sys_set_key_repeat for 0x47,
 * 0x48, 0x45, 0x46, tail sys_set_key_long_press_alt(0xff, 0). void, no params.
 * The tail callee sys_set_key_long_press_alt takes 2 arguments (it overwrites %o2).
 * Source form: the positive '||' test with that arm FIRST. Aids: none.
 */
extern unsigned int osd_menu_state;
extern void sys_set_key_repeat(unsigned char, unsigned char);
extern void sys_set_key_long_press(unsigned char, unsigned char);
extern void sys_set_key_long_press_alt(unsigned char, unsigned char);

#define KEY_ID_ALL 0xff                 /* key event code meaning every key */
#define KEY_UP     0x45                 /* the four arrow keys */
#define KEY_DOWN   0x46
#define KEY_LEFT   0x47
#define KEY_RIGHT  0x48

/*
 * Set the key rules for the screen the menu is on (osd_menu_state).
 *
 * Menu closed (0) or state 0x10B..0x110: no key repeats; key 0x49 acts only on a long press; key 0x42 sends
 * 0x43 when held long.
 * States 0x108 and 0x109: the four arrow keys repeat; no key sends a second code.
 * Every other state: the same, the arrow keys are set in the order 0x47, 0x48, 0x45, 0x46.
 * The settings of earlier calls that this routine does not touch (the long-press rule of key 0x49, the
 * blocked keys) stay as they are.
 */
void sys_set_key_modes_for_menu(void)
{
    if (osd_menu_state == 0 || osd_menu_state == 0x10b || osd_menu_state == 0x10c ||
        osd_menu_state == 0x10d || osd_menu_state == 0x10e || osd_menu_state == 0x10f ||
        osd_menu_state == 0x110) {
        sys_set_key_repeat(KEY_ID_ALL, 0);
        sys_set_key_long_press(0x49, 1);
        sys_set_key_long_press_alt(0x42, 0x43);
    } else if (osd_menu_state - 0x108 < 2) {
        sys_set_key_repeat(KEY_UP, 1);
        sys_set_key_repeat(KEY_DOWN, 1);
        sys_set_key_repeat(KEY_LEFT, 1);
        sys_set_key_repeat(KEY_RIGHT, 1);
        sys_set_key_long_press_alt(KEY_ID_ALL, 0);
    } else {
        sys_set_key_repeat(KEY_LEFT, 1);
        sys_set_key_repeat(KEY_RIGHT, 1);
        sys_set_key_repeat(KEY_UP, 1);
        sys_set_key_repeat(KEY_DOWN, 1);
        sys_set_key_long_press_alt(KEY_ID_ALL, 0);
    }
}
