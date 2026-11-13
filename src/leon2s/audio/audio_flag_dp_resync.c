/* audio_flag_dp_resync  (FUN_a008ae18)
 *
 * Mark a DP audio source for a fresh FIFO set-up.
 *   receiver: DP receiver 0/1
 * Name basis: descriptive - bit idx of 0xA8078B31, handled and cleared by audio_check_dp_fifo_unmute
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008ae18 @ 0xa008ae18 (-mcpu=v8 -Os -g).
 * The shift is on the unsigned char parameter: load byte, 'sll' of 1, or, store.
 */
extern unsigned char audio_dp_resync_flag;

/*
 * Set bit "receiver" of audio_dp_resync_flag, which asks for a fresh FIFO set-up of that DP receiver's audio.
 *   receiver: DP receiver 0 or 1
 * Called by audio_update_dp_32k_mode.
 */
void audio_flag_dp_resync(unsigned char receiver)
{
    audio_dp_resync_flag = (unsigned char)((1 << receiver) | audio_dp_resync_flag);
    return;
}
