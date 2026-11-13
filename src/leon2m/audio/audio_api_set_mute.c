/* audio_api_set_mute  (FUN_a01479ec)
 *
 * Mute or unmute the sound.
 * Name basis: derived - gpio_write_pin(9, ...), then command 0x91 with 1 or 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01479ec @ 0xa01479ec, flags -mcpu=v8 -O2 -g.
 * Source form: an if with a return inside, then the other call; the callees are declared without prototypes.
 */
extern int audio_unmute_outputs();
extern int audio_mute_outputs();

/*
 * Mute the sound when mute is not zero, unmute it when it is zero (audio_mute_outputs drives the mute pin high and
 * tells the input processor, audio_unmute_outputs drives it low and tells it).
 */
void audio_api_set_mute(unsigned char mute)

{
  if (mute != '\0') {
    audio_mute_outputs();
    return;
  }
  audio_unmute_outputs();
  return;
}
