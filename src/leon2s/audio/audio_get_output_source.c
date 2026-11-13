/* audio_get_output_source  (FUN_a0089f84)
 *
 * Return the source id routed to one audio output.
 *   out: audio output 0..8
 * Returns: source id
 * Name basis: derived - byte table 0xA8076690 written by audio_set_output_source
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0089f84 @ 0xa0089f84 (-mcpu=v8 -Os -g)
 */
extern unsigned char audio_output_sources[];

/*
 * Return the source id routed to audio output out (0..8): the entry of audio_output_sources that
 * audio_set_output_source wrote last.
 */
unsigned char audio_get_output_source(unsigned int out)
{
  return audio_output_sources[(out & 0xff)];
}
