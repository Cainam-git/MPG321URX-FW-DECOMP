/* sys_set_timed_limits_ch0  (FUN_CODE_dec2)
 *
 * Store the first value pair (top, bottom) of the timed toggle / ramp record.
 *   top: toggle: first register value; ramp: top end
 *   bottom: toggle: hold time of that value in units of 100 ticks; ramp: bottom end
 * Name basis: descriptive - mailbox command 0x19; limits[0] of the record 0xA735 used by sys_run_timed_ramp
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dec2 @ 0xdec2  OPTIMIZE(7,SPEED)
 * Source form: a two-byte array at 0xA73C gives one MOV DPTR,#0xA73C, then MOVX @DPTR,A / INC DPTR / MOVX @DPTR,A.
 */
xdata unsigned char sys_timed_limits[2] _at_ 0xa73c;

/*
 * Store the first pair of the timed toggle / ramp record at 0xA735 (limits[0] in sys_run_timed_ramp): top at
 * 0xA73C, bottom at 0xA73D. For the toggle, top is the first register value and bottom its hold time in units of
 * 100 ticks; for the ramp, they are the two ends of channel 0. Only caller: ipc_run_command, mailbox command 0x19,
 * with arg2 and arg3 (bits 16..23 and 24..31 of the command word).
 */
void sys_set_timed_limits_ch0(unsigned char top, unsigned char bottom) {
    sys_timed_limits[0] = top;
    sys_timed_limits[1] = bottom;
}
