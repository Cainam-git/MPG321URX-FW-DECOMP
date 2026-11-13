/* audio_unmute_outputs  (FUN_a0124f24)
 *
 * Unmute the sound: drive the mute pin low and tell the input processor.
 * Note: The routine is built with six parameters; the first is unused and the others are handed on to
 *   ipc_set_audio_mute, which reads none of them.
 * Name basis: derived - gpio_write_pin(9, 0x20, 0xFE), then ipc_set_audio_mute(0) (mailbox command 0x91)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124f24 @ 0xa0124f24, flags -mcpu=v8 -O2 -g.
 * Source form: the six parameters are kept because the routine hands parameters 2 to 6 on to ipc_set_audio_mute
 * unchanged (its callers declare none).
 */
extern int ipc_set_audio_mute();
extern int gpio_write_pin();

/*
 * Unmute the audio: write level 0xfe (bit 0 clear: low) to mask 0x20 (pin 5) of GPIO port 9, then call
 * ipc_set_audio_mute with 0. audio_mute_outputs does the same with level 1 and argument 1.
 * Parameters 2 to 6 are passed on to ipc_set_audio_mute as they came in; parameter 1 is not used.
 * Called by sys_run_app_timer_task, uart_cmd_set_second_source and audio_api_set_mute.
 */
void audio_unmute_outputs(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                          unsigned int arg5, unsigned int arg6)
{
    gpio_write_pin(9, 0x20, 0xfe);
    ipc_set_audio_mute(0, arg2, arg3, arg4, arg5, arg6);
}
