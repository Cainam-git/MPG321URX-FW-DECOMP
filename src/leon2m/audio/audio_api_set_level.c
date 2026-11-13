/* audio_api_set_level  (FUN_a014398c)
 *
 * Convert a 10-bit value to an audio level and send it to the input processor.
 * Name basis: derived - v * 20914 / 1023 + 1; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014398c @ 0xa014398c, flags -mcpu=v8 -O3 -g.
 * Source form: a forward with one expression; the division is signed (smul by 0x80200803, rd %y, add, sra 9) and
 * the result is truncated to 16 bits; the firmware makes it a tail call (the caller's return address is handed
 * on), followed by the nop that belongs to such a call sequence.
 */
extern void ipc_set_audio_level(unsigned char a, unsigned short b);

#define AUDIO_LEVEL_SCALE_NUM 20914     /* level at the top of the range (1023) is 20914 + 1 */
#define AUDIO_VALUE_MAX       1023      /* 10-bit input value */

/*
 * Turn a value 0..1023 into the level value * 20914 / 1023 + 1 (so 1..20915) and send it with
 * ipc_set_audio_level(0, level). audio_api_set_level_percent ends in the same call and the same arithmetic.
 * Nothing in the firmware calls this routine and no stored address points at it.
 */
void audio_api_set_level(unsigned short value)
{
    ipc_set_audio_level(0, value * AUDIO_LEVEL_SCALE_NUM / AUDIO_VALUE_MAX + 1);
}
