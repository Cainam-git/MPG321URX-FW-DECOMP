/* audio_find_outputs_of_source  (FUN_a0089f98)
 *
 * Return a mask of the audio outputs that use a given source.
 *   source: audio source id (4/6 DP, 8/10 HDMI 2.0, 12/14 HDMI 2.1)
 * Returns: output bit mask
 * Name basis: derived - loops outputs 0..8 through audio_get_output_source
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0089f98 @ 0xa0089f98 (-mcpu=v8 -Os -g)
 * The call takes the loop counter copy (idx), not the parameter. The loop runs until the counter reaches 8
 * inclusive (9 iterations).
 */
extern int audio_get_output_source(unsigned char out);

#define AUDIO_OUTPUTS 9                         /* audio outputs 0..8 */

/*
 * Return a mask with bit n set for every audio output n (0..8) whose source is source.
 *   source: audio source id (4/6 DP, 8/10 HDMI 2.0, 12/14 HDMI 2.1)
 */
unsigned short audio_find_outputs_of_source(unsigned char source)
{
    unsigned short mask = 0;
    unsigned char counter = 0;
    unsigned char out;

    do {
        out = counter;
        if ((audio_get_output_source(out) & 0xff) == (source & 0xff)) {
            mask |= (unsigned short)(1 << out);
        }
        counter++;
    } while ((counter & 0xff) <= AUDIO_OUTPUTS - 1);

    return mask;
}
