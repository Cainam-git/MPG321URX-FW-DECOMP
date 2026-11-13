/* sys_user_swap_pip_sources  (FUN_a00d934c)
 *
 * Swap the sources of the main and the second picture.
 * Name basis: derived - exchanges settings bytes +0x1E and +0x20, then re-selects the sources
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d934c @ 0xa00d934c-0xa00d93c8 (31 words), flags -mcpu=v8 -O3 -g.
 * Source form: both bytes are read first and stored back swapped (+0x1E first, then +0x20). The test is written
 * 'cur == old' so that the compare keeps the firmware's operand order. The final call takes no arguments and is
 * a tail call.
 */
/* The fields of the user settings record used here. */
struct user_settings_record {
  unsigned char pad0[0x1e];
  unsigned char input_source;       /* +0x1E: the selected input source */
  unsigned char pad1f;
  unsigned char second_source;      /* +0x20: source of the second picture */
  unsigned char pad21[0xa8 - 0x21];
  unsigned int gaming_flags;        /* +0xA8 */
  unsigned int word_0xac;           /* +0xAC */
};
extern struct user_settings_record user_settings;
extern void audio_user_update_routing(void);
extern void sys_user_reset_display_path(void);
extern void audio_api_set_mute(unsigned char);
extern void sys_api_select_channel_source(int channel, unsigned char source);

#define GAMING_FLAG_BIT14 0x4000

/*
 * Exchange the main source (+0x1E) and the second source (+0x20) of the settings. Bit 17 of the word at +0xAC
 * is set in every case. When the two sources were equal nothing else happens. Otherwise the display path is
 * set up again (sys_user_reset_display_path), the mute is set when bit 14 of gaming_flags is set, the new
 * second source is selected for channel 1 and audio_user_update_routing runs.
 */
void sys_user_swap_pip_sources(void)
{
  struct user_settings_record *p = &user_settings;
  unsigned char old = p->input_source;
  unsigned char cur = p->second_source;

  p->word_0xac |= 0x20000;
  p->input_source = cur;
  p->second_source = old;
  if (cur == old)
    return;
  sys_user_reset_display_path();
  if (p->gaming_flags & GAMING_FLAG_BIT14)
    audio_api_set_mute(1);
  sys_api_select_channel_source(1, p->second_source);
  audio_user_update_routing();
}
