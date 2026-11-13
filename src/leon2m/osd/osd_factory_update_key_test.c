/* osd_factory_update_key_test  (FUN_a009eaf8)
 *
 * Show the front key just pressed in the factory key test and note when all passed.
 * Note: Calls osd_factory_show_pressed_key, then osd_factory_show_keys_passed when all six key bits (0x3F) are
 *   set.
 * Name basis: derived - callees osd_factory_show_pressed_key / osd_factory_show_keys_passed; no table
 *   reference found
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009eaf8, flags -mcpu=v8 -O3 -g.
 * Source form: the callees' results are int and dropped; the tick value is stored as an unsigned short.
 */
extern unsigned char factory_record_key_test_bits;      /* factory record +0x10 */
extern unsigned short osd_last_key_ticks;
extern int osd_factory_show_pressed_key(void);
extern int osd_factory_show_keys_passed(void);
extern int timer_api_get_ticks16(void);

#define KEY_TEST_ALL_KEYS 0x3f                  /* all six key bits set */

/*
 * Handle a front key press in the factory key test: show the key that was pressed (the routine also records it
 * in the key test bits of the factory record), report when all six keys have been seen and note the time of the
 * press in osd_last_key_ticks.
 *
 * No table refers to this routine.
 */
void osd_factory_update_key_test(void)
{
    osd_factory_show_pressed_key();
    if (factory_record_key_test_bits == KEY_TEST_ALL_KEYS) {
        osd_factory_show_keys_passed();
    }
    osd_last_key_ticks = timer_api_get_ticks16();
}
