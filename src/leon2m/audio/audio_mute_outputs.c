/* audio_mute_outputs  (FUN_a0124f44)
 *
 * Mute the sound: drive the mute pin high and tell the input processor.
 * Note: The routine is built with six parameters; the first is unused and the others are handed on to
 *   ipc_set_audio_mute, which reads none of them.
 * Name basis: derived - gpio_write_pin(9, 0x20, 1), then ipc_set_audio_mute(1) (mailbox command 0x91)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124f44 @ 0xa0124f44, flags -mcpu=v8 -O2 -g.
 * Source form: the six parameters are kept because the routine hands parameters 2 to 6 on to ipc_set_audio_mute
 * unchanged (its callers declare none).
 */
extern int ipc_set_audio_mute();
extern int gpio_write_pin();

/*
 * Mute the audio: write level 1 (high) to mask 0x20 (pin 5) of GPIO port 9, then call ipc_set_audio_mute with 1.
 * audio_unmute_outputs does the same with level 0xfe and argument 0.
 * Parameters 2 to 6 are passed on to ipc_set_audio_mute as they came in; parameter 1 is not used.
 * Called by SYSAPI_PowerOff, SYSAPI_PowerSaving, audio_api_set_mute and many routines of the main program.
 */
void audio_mute_outputs(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                        unsigned int arg5, unsigned int arg6)
{
    gpio_write_pin(9, 0x20, 1);
    ipc_set_audio_mute(1, arg2, arg3, arg4, arg5, arg6);
}
