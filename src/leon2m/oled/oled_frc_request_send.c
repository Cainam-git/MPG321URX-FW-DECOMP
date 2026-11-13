/* oled_frc_request_send  (FUN_a01295d0)
 *
 * Request that the chosen refresh-rate row is sent to the panel.
 * Name basis: derived - bit 0x400 of the handler's state word
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01295d0 @ 0xa01295d0-0xa01295e4 (5 words), flags -mcpu=v8 -O2 -g. A leaf that Ghidra's function
 * list did not contain; it has its own entry in symbols/leon2m.functions.json.
 */
extern unsigned short oled_frc_state;

#define FRC_SEND_REQUEST 0x400  /* "send request" flag of the handler's state halfword */

/*
 * Ask oled_frc_task to send the stored row index to the OLED panel controller again: sets the request flag.
 * APPActionDispatcher calls it right after SYSAPI_GetPanelParamStruct.
 */
void oled_frc_request_send(void)
{
    oled_frc_state |= FRC_SEND_REQUEST;
}
