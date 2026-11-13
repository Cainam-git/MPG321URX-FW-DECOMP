/* SetThemeMode  (FUN_a0087a14)
 *
 * Apply the picture theme preset mode to one or both channels.
 *   mode: theme preset
 * Note: Preset table of 0x20-byte entries at ROM 0xFF710.
 * Name basis: proven - prints 'SetThemeMode = %d -> HDR_Type = %d' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0087a14 @ 0xa0087a14-0xa0087d5c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - both bit-31 tests go through the static helper bit_set(w, mask) ('(w & mask) != 0'), inlined;
 *  - the first byte is read as t[mode].value[0], the others through r = t + mode;
 *  - each of the two rounds is 'if (!bit_set(..)) { pq_api_config_ace; pq_api_load_ace_table; }' followed by the
 *    two level table loads.
 */

/* One picture theme preset (0x20 bytes): the picture item values, then the three tables it loads. */
struct theme_preset {
    unsigned char value[0x14];  /* +0: picture item values; bytes 0..13 and 16 are used, not in item order */
    const void *ace_table;      /* +0x14: table for pq_api_load_ace_table (loaded unless auto level is on) */
    const void *level_table;    /* +0x18: first level table */
    const void *level_table_2;  /* +0x1C: second level table */
};
extern const struct theme_preset pq_theme_mode_presets[];
extern int dbg_printf(const char *fmt, ...);
extern int sys_user_get_picture_state(void);
extern void pq_api_set_window_item(unsigned char ch, unsigned char item, unsigned char v);
extern void pq_api_config_ace(unsigned char ch, unsigned char mode, unsigned char a, unsigned char b);
extern void pq_api_load_ace_table(unsigned char ch, const void *p);
extern void pq_api_load_level_table(unsigned char ch, const void *p);
extern void pq_api_load_level_table_second(unsigned char ch, const void *p);
extern unsigned char input_is_port_used(unsigned char port);

struct user_settings_record {
    unsigned char p000[0x11c];
    unsigned int professional_flags;    /* +0x11C: switches of the Professional modes */
};
extern struct user_settings_record user_settings;

#define PRO_FLAG_AUTO_LEVEL 0x80000000  /* +0x11C bit 31: automatic level; when set the ACE table is not loaded */
#define MAIN_CHANNEL 0
#define SECOND_CHANNEL 1

static int bit_set(unsigned int w, unsigned int mask)
{
    return (w & mask) != 0;
}

/*
 * Apply theme preset 'mode' (an index into pq_theme_mode_presets) to channel 0 and, when input_is_port_used(1)
 * says port 1 is in use (PiP / PBP mode not off), to channel 1 with the same values.
 *
 * Picture items 0..13 and 15 are written with pq_api_set_window_item. Preset bytes 0..5 go to items 0..5; then
 * byte 8 -> item 6, 6 -> 7, 7 -> 8, 0xC -> 9, 0xB -> 10, 0xA -> 11, 9 -> 12, 0xD -> 13 and 0x10 -> 15.
 * The ACE table is loaded (after pq_api_config_ace(ch, 2, 0, 0)) only when automatic level is off (professional
 * flags bit 31 clear); the two level tables are always loaded. The print gives the mode and the picture state.
 *
 * Callers: pq_user_apply_theme_mode, UserSetProMode, UserSetGameMode.
 */
void SetThemeMode(unsigned char mode)
{
    const struct theme_preset *t, *r;
    unsigned char item0, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10, item11, item12, item13, item15;

    dbg_printf("SetThemeMode = %d -> HDR_Type = %d\r\n", mode, sys_user_get_picture_state());
    t = pq_theme_mode_presets;
    item0 = t[mode].value[0];
    pq_api_set_window_item(MAIN_CHANNEL, 0, item0);
    r = t + mode;
    item1 = r->value[1];
    pq_api_set_window_item(MAIN_CHANNEL, 1, item1);
    item2 = r->value[2];
    pq_api_set_window_item(MAIN_CHANNEL, 2, item2);
    item3 = r->value[3];
    pq_api_set_window_item(MAIN_CHANNEL, 3, item3);
    item4 = r->value[4];
    pq_api_set_window_item(MAIN_CHANNEL, 4, item4);
    item5 = r->value[5];
    pq_api_set_window_item(MAIN_CHANNEL, 5, item5);
    item6 = r->value[8];
    pq_api_set_window_item(MAIN_CHANNEL, 6, item6);
    item7 = r->value[6];
    pq_api_set_window_item(MAIN_CHANNEL, 7, item7);
    item8 = r->value[7];
    pq_api_set_window_item(MAIN_CHANNEL, 8, item8);
    item9 = r->value[0xc];
    pq_api_set_window_item(MAIN_CHANNEL, 9, item9);
    item10 = r->value[0xb];
    pq_api_set_window_item(MAIN_CHANNEL, 10, item10);
    item11 = r->value[0xa];
    pq_api_set_window_item(MAIN_CHANNEL, 11, item11);
    item12 = r->value[9];
    pq_api_set_window_item(MAIN_CHANNEL, 12, item12);
    item13 = r->value[0xd];
    pq_api_set_window_item(MAIN_CHANNEL, 13, item13);
    item15 = r->value[0x10];
    pq_api_set_window_item(MAIN_CHANNEL, 15, item15);
    if (!bit_set(user_settings.professional_flags, PRO_FLAG_AUTO_LEVEL)) {
        pq_api_config_ace(MAIN_CHANNEL, 2, 0, 0);
        pq_api_load_ace_table(MAIN_CHANNEL, r->ace_table);
    }
    pq_api_load_level_table(MAIN_CHANNEL, r->level_table);
    pq_api_load_level_table_second(MAIN_CHANNEL, r->level_table_2);
    if (input_is_port_used(SECOND_CHANNEL) != 1)
        return;
    pq_api_set_window_item(SECOND_CHANNEL, 0, item0);
    pq_api_set_window_item(SECOND_CHANNEL, 1, item1);
    pq_api_set_window_item(SECOND_CHANNEL, 2, item2);
    pq_api_set_window_item(SECOND_CHANNEL, 3, item3);
    pq_api_set_window_item(SECOND_CHANNEL, 4, item4);
    pq_api_set_window_item(SECOND_CHANNEL, 5, item5);
    pq_api_set_window_item(SECOND_CHANNEL, 6, item6);
    pq_api_set_window_item(SECOND_CHANNEL, 7, item7);
    pq_api_set_window_item(SECOND_CHANNEL, 8, item8);
    pq_api_set_window_item(SECOND_CHANNEL, 9, item9);
    pq_api_set_window_item(SECOND_CHANNEL, 10, item10);
    pq_api_set_window_item(SECOND_CHANNEL, 11, item11);
    pq_api_set_window_item(SECOND_CHANNEL, 12, item12);
    pq_api_set_window_item(SECOND_CHANNEL, 13, item13);
    pq_api_set_window_item(SECOND_CHANNEL, 15, item15);
    if (!bit_set(user_settings.professional_flags, PRO_FLAG_AUTO_LEVEL)) {
        pq_api_config_ace(SECOND_CHANNEL, 2, 0, 0);
        pq_api_load_ace_table(SECOND_CHANNEL, r->ace_table);
    }
    pq_api_load_level_table(SECOND_CHANNEL, r->level_table);
    pq_api_load_level_table_second(SECOND_CHANNEL, r->level_table_2);
}
