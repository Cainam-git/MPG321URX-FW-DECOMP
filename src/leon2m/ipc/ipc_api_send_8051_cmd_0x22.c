/* ipc_api_send_8051_cmd_0x22  (FUN_a0147c48)
 *
 * Send command 0x22 with one value to the 8051.
 * Name basis: descriptive - tail call to the 8051 command sender; unused
 *
 * Matching notes
 * --------------
 * FUN_a0147c48 (leon2m 0xa0147c48-0xa0147c5c, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Tail call of ipc_8051_switch_control_bit; the nop after it is the -g line nop. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word.
 */
extern void ipc_8051_switch_control_bit(unsigned char);

/*
 * Forward on to ipc_8051_switch_control_bit, which sends command 0x22 to the 8051.
 *   on  passed on unchanged: non-zero clears bit 3 of 0xF1EB and sets it in 0xF1E0, 0 does the reverse
 * Nothing in the image refers to this routine.
 */
void ipc_api_send_8051_cmd_0x22(unsigned char on)
{
    ipc_8051_switch_control_bit(on);
}
