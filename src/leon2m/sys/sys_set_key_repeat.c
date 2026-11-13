/* sys_set_key_repeat  (FUN_a008ec48)
 *
 * Turn auto-repeat on or off for one key, or for all keys with id 0xFF.
 *   key: key event code, 0xFF = all
 *   on: 1 = on
 * Note: Mask 0xA802AFDC; delays set by sys_set_key_repeat_delay/_interval.
 * Name basis: derived - mode 1 in sys_scan_keys_post_event: fires again after the delay, then every interval
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008ec48 @ 0xa008ec48, flags -mcpu=v8 -O3 -g.
 * The table search keeps two loop counters, an unsigned int i and the unsigned-char-truncated idx; a single
 * 'unsigned char i' for-loop gives other code. Callers: App_Initialize and sys_set_key_modes_for_menu.
 * sys_set_key_long_press and sys_set_key_blocked are the same code with another mask.
 */
extern unsigned char sys_key_code_table[];
extern unsigned short sys_key_repeat_mask;

#define KEY_ID_ALL 0xff                 /* key event code meaning every key */

/*
 * Turn auto-repeat on or off for one key, or for all keys with KEY_ID_ALL.
 *
 *   key  key event code (0x40..0x4E), KEY_ID_ALL for all keys
 *   on   1 sets the rule, any other value clears it
 *
 * sys_key_repeat_mask holds one bit per entry of sys_key_code_table, bit 0 being entry 0. For KEY_ID_ALL all 16 bits are
 * first set (on == 1) or cleared; then the table is searched for the entry whose second byte is the key code.
 * Entry 0 and a code that is not in the table change nothing more, so KEY_ID_ALL ends here.
 * Called by sys_set_key_modes_for_menu and App_Initialize.
 */
void sys_set_key_repeat(unsigned char key, unsigned char on)
{
    unsigned int i;
    unsigned int idx;           /* table entry found; 16 (not found) wraps to 0 below */

    key &= 0xff;

    if (key == KEY_ID_ALL) {
        if ((on & 0xff) == 1) {
            sys_key_repeat_mask = 0xffff;
        } else {
            sys_key_repeat_mask = 0;
        }
    }

    i = 0;
    idx = 0;
    do {
        if (sys_key_code_table[idx * 2 + 1] == key)
            break;
        i++;
        idx = (unsigned char)i;
    } while (idx <= 15);

    idx &= 0xf;
    if (idx == 0)
        return;

    if ((on & 0xff) == 1) {
        sys_key_repeat_mask |= (1 << idx);
    } else {
        sys_key_repeat_mask &= ~(1 << idx);
    }
}
