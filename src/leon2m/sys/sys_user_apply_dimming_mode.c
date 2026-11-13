/* sys_user_apply_dimming_mode  (FUN_a00d9120)
 *
 * Send the dimming mode for the current state and re-apply the picture table.
 * Name basis: descriptive - ldc_api_set_dimming_mode, a frame wait, then a table load
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d9120 @ 0xa00d9120-0xa00d91fc (55 words), flags -mcpu=v8 -O3 -g.
 * Source form: each of the four status cases has its own body. Shared case labels give a range test instead of
 * the firmware's case tree.
 */

/* The two fields of the user settings record read here. */
struct user_settings_record {
    unsigned char pad0[0x15b];
    unsigned char night_vision;                 /* +0x15B: the Night Vision setting */
    unsigned char pad15c[0x174 - 0x15c];
    unsigned int word_0x174;                    /* +0x174 */
};
extern struct user_settings_record user_settings;
extern unsigned char sys_api_get_channel_port_flag9(int);
extern unsigned char sys_api_get_channel_port_flag6(int);
extern unsigned char ipc_api_get_status_field(void);
extern void ldc_api_set_dimming_mode(unsigned char);
extern void panel_wait_sync_pulse(void);
extern void pq_apply_table_entry_both_channels(unsigned char);

#define MAIN_CHANNEL 0                          /* channel 0: the main picture */

/*
 * Pick the dimming mode and the picture table entry for the present state and apply both.
 *
 * Dimming mode 0 and table entry 0 are used when the port of the main picture has flag bit 9 set, or has flag
 * bit 6 set while the mailbox status field reads 1 to 4 (4 also stands for an out-of-range field). In these
 * two cases the wait for a sync pulse is skipped.
 *
 * Otherwise the Night Vision setting decides: with value 4, or with bit 15 of settings word +0x174 set, dimming
 * mode 2 and table entry 0; else dimming mode 0 and the table entry of the Night Vision value.
 * Between the two steps it waits for one sync pulse of the panel (panel_wait_sync_pulse).
 */
void sys_user_apply_dimming_mode(void)
{
  if (sys_api_get_channel_port_flag9(MAIN_CHANNEL) == 1) {
    ldc_api_set_dimming_mode(0);
    pq_apply_table_entry_both_channels(0);
    return;
  }
  if (sys_api_get_channel_port_flag6(MAIN_CHANNEL) == 1) {
    switch (ipc_api_get_status_field()) {
    case 1: ldc_api_set_dimming_mode(0); pq_apply_table_entry_both_channels(0); return;
    case 2: ldc_api_set_dimming_mode(0); pq_apply_table_entry_both_channels(0); return;
    case 3: ldc_api_set_dimming_mode(0); pq_apply_table_entry_both_channels(0); return;
    case 4: ldc_api_set_dimming_mode(0); pq_apply_table_entry_both_channels(0); return;
    }
    /* Status 0: fall through to the Night Vision setting. */
  }
  if (user_settings.night_vision == 4 || (user_settings.word_0x174 & 0x8000)) {
    ldc_api_set_dimming_mode(2);
    panel_wait_sync_pulse();
    pq_apply_table_entry_both_channels(0);
    return;
  }
  ldc_api_set_dimming_mode(0);
  panel_wait_sync_pulse();
  pq_apply_table_entry_both_channels(user_settings.night_vision);
}
