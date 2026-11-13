/* ipc_api_clear_audio_level_steps  (FUN_a014e758)
 *
 * Ask the input processor to clear the audio level step registers.
 * Name basis: derived - tail call to the command 0x95 sender; mailbox command 0x95, whose handler in the input
 *   program shows the meaning
 *
 * Matching notes
 * --------------
 * FUN_a014e758 (leon2m 0xa014e758-0xa014e768, 16 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Tail call of ipc_clear_audio_level_steps ('mov %o7, %g1; call; mov %g1, %o7'); the nop after it is the -g line nop.
 */
extern void ipc_clear_audio_level_steps(void);

/*
 * Forward on to ipc_clear_audio_level_steps, which sends mailbox command 0x95 to the input processor.
 * Called by sys_latch_unit_event_ch0 (sys_latch_unit_event_ch0).
 */
void ipc_api_clear_audio_level_steps(void)
{
    ipc_clear_audio_level_steps();
}
