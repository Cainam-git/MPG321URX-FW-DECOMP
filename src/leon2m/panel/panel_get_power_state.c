/* panel_get_power_state  (FUN_a0141ae8)
 *
 * Return the state of the panel power sequencer.
 * Returns: state
 * Name basis: derived - byte at 0xA802E110
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141ae8 @ 0xa0141ae8, flags -mcpu=v8 -O2 -g.
 * Source form: a direct read of the extern byte.
 */
extern unsigned char panel_power_state;

/*
 * Return the state byte of the panel power sequencer: 1 off, 2..5 the steps of switching on, 6 on, 7..9 the steps
 * of switching off (see panel_request_power). input_channel_bring_up_task calls it.
 */
unsigned char panel_get_power_state(void)
{
    return panel_power_state;
}
