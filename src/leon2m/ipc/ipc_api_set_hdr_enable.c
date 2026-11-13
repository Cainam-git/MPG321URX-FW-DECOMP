/* ipc_api_set_hdr_enable  (FUN_a014e03c)
 *
 * Ask the input processor to switch the HDR curve service on or off.
 * Name basis: derived - tail call to the command 0x7A sender on mailbox portal 1; unused; mailbox command
 *   0x7A, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e03c @ 0xa014e03c-0xa014e050 (5 words), flags -mcpu=v8 -O2 -g.
 * Tail call of ipc_set_hdr_enable: the caller's return address is handed on, so the callee returns straight to this
 * routine's caller. The last word is the nop the compiler places behind such a call sequence.
 */
extern void ipc_set_hdr_enable(unsigned char);

/*
 * Forward on to ipc_set_hdr_enable (mailbox command 0x7A).
 *   enable  non-zero switches the HDR curve service of the input processor on, 0 off
 * Nothing in the firmware calls this routine and no stored address points at it.
 */
void ipc_api_set_hdr_enable(unsigned char enable)
{
    ipc_set_hdr_enable(enable);
}
