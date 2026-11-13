/* audio_api_set_level_percent  (FUN_a0147a14)
 *
 * Convert a percentage to an audio level and send it to the input processor.
 * Name basis: derived - x scaled by 1023/100 and 20914/1023, plus 1; called from the menu code
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147a14 @ 0xa0147a14, flags -mcpu=v8 -O3 -g.
 * Source form: the first step is an unsigned division stored in an unsigned short; the second is a signed division
 * whose result is truncated to unsigned short; the firmware makes the final call a tail call.
 */
extern void ipc_set_audio_level(unsigned char a, unsigned short b);

#define AUDIO_LEVEL_SCALE_NUM 20914     /* level at the top of the range (1023) is 20914 + 1 */
#define AUDIO_VALUE_MAX       1023      /* 10-bit value that stands for 100 percent */

/*
 * Turn a percentage 0..100 into a 10-bit value, (percent * 1023 + 50) / 100 (rounded), then into the level
 * value * 20914 / 1023 + 1, and send it with ipc_set_audio_level(0, level). Called by App_Initialize, audio_user_apply_level
 * and audio_user_toggle_source.
 */
void audio_api_set_level_percent(unsigned char percent)
{
    unsigned short value = (unsigned int)(percent * AUDIO_VALUE_MAX + 50) / 100;

    ipc_set_audio_level(0, value * AUDIO_LEVEL_SCALE_NUM / AUDIO_VALUE_MAX + 1);
}
