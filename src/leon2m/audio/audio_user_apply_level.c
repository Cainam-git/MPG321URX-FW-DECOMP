/* audio_user_apply_level  (FUN_a00d4970)
 *
 * Apply the audio level setting, limited to 100.
 * Name basis: derived - sys_api_send_percent_level
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4970 @ 0xa00d4970, flags -mcpu=v8 -Os -g.
 * Source form: the local is a copy of the setting that is replaced by 100 inside the if; the routine ends with an
 * explicit return and has a blank line between the header and the brace.
 */

#define AUDIO_LEVEL_MAX  100    /* highest level sent, in percent */

extern unsigned char user_settings_audio_level;     /* user settings +0x10: the audio level */
extern int audio_api_set_level_percent();

/*
 * Send the audio level of the user settings (byte +0x10) to audio_api_set_level_percent as a percentage, cut
 * down to 100 when the stored value is larger.
 */
void audio_user_apply_level(void)

{
  unsigned char level;
  
  level = user_settings_audio_level;
  if (AUDIO_LEVEL_MAX < user_settings_audio_level) {
    level = AUDIO_LEVEL_MAX;
  }
  audio_api_set_level_percent(level);
  return;
}
