/* sys_set_timed_limits_ch1  (FUN_CODE_decb)
 *
 * Store the second value pair (top, bottom) of the timed toggle / ramp record.
 *   top: toggle: second register value; ramp: top end
 *   bottom: toggle: hold time of that value in units of 100 ticks; ramp: bottom end
 * Name basis: descriptive - mailbox command 0x1A; limits[1] of the record 0xA735 used by sys_run_timed_ramp
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_decb @ 0xdecb  OPTIMIZE(7,SPEED)
 * Source form: one volatile xdata pointer, stepped on between the two stores, gives MOV DPTR,#0xA73E; MOV A,R7;
 * MOVX @DPTR,A; INC DPTR; MOV A,R5; MOVX @DPTR,A; RET.
 */
#define TIMED_LIMITS_1 0xa73e   /* limits[1] of the timed record at 0xA735: top, then bottom */

/*
 * Store the second pair of the timed toggle / ramp record at 0xA735 (limits[1] in sys_run_timed_ramp): top at
 * 0xA73E, bottom at 0xA73F. For the toggle, top is the second register value and bottom its hold time in units of
 * 100 ticks; for the ramp, they are the two ends of channel 1. Only caller: ipc_run_command, mailbox command 0x1A,
 * with arg2 and arg3 (bits 16..23 and 24..31 of the command word). Twin of sys_set_timed_limits_ch0.
 */
void sys_set_timed_limits_ch1(unsigned char top, unsigned char bottom) {
    volatile unsigned char xdata *limit = (volatile unsigned char xdata *)TIMED_LIMITS_1;
    *limit = top;
    limit++;
    *limit = bottom;
}
