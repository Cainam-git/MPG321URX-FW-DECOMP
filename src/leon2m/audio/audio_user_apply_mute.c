/* audio_user_apply_mute  (FUN_a00d48cc)
 *
 * Apply the mute setting.
 * Name basis: derived - sys_api_set_pin9_and_notify
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d48cc @ 0xa00d48cc-0xa00d4910 (17 words), flags -mcpu=v8 -O3 -g.
 * Source form: the value is limited with 'if (mute > 1) mute = 1;' (the firmware keeps that compare and the move
 * of 1) and the word is written back unconditionally; the argument is read back from the stored word. Word 0 is
 * accessed as a plain word with the 0x800 mask, as in ddc_handle_request. The call is a tail call.
 */

#define SETTINGS_AUDIO_MUTE_BIT  11     /* bit 11 of settings word 0: the mute setting (0x800) */

struct user_settings_record { unsigned int word_0x0; };
extern struct user_settings_record user_settings;
extern void audio_api_set_mute(unsigned char);

/*
 * Pass the mute setting (bit 11 of the first word of the user settings) on to audio_api_set_mute.
 * ddc_handle_request sets and clears this bit when a DDC/CI Set VCP 0x8D (audio mute) arrives, and clears it
 * for Set VCP 0x62 (volume).
 * Called from ddc_handle_request and APPActionDispatcher.
 */
void audio_user_apply_mute(void)
{
  unsigned char mute = (user_settings.word_0x0 >> SETTINGS_AUDIO_MUTE_BIT) & 1;

  if (mute > 1)
    mute = 1;
  user_settings.word_0x0 = (user_settings.word_0x0 & ~0x800) | (mute << SETTINGS_AUDIO_MUTE_BIT);
  audio_api_set_mute((user_settings.word_0x0 >> SETTINGS_AUDIO_MUTE_BIT) & 1);
}
