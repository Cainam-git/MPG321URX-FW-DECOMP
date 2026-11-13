/* ipc_is_dp_rx_condition_pending  (FUN_a01393bc)
 *
 * Ask the input processor to report whether a DisplayPort receiver port has a pending condition.
 * Returns: reply byte
 * Name basis: derived - command 0x31 through the mailbox portal 1 sender; unused; mailbox command 0x31, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01393bc @ 0xa01393bc (-mcpu=v8 -O2 -g).
 * Source form: the decompiler's form is kept: the return value is built with CONCAT44 from the second parameter
 * and the reply byte, and the routine takes two unused parameters.
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4, uint;
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern unsigned char ipc_reply_result_byte;
extern void ipc_send_command();
extern int ipc_wait_reply();

#define IPC_CMD_CHECK_DP_RX_SERVICE 0x31        /* mailbox command 0x31 */
#define IPC_SEND_NO_WAIT            0           /* do not wait for the reply slot */

/*
 * Ask the input processor with mailbox command 0x31 whether a DisplayPort receiver port is ready for service,
 * and return its answer: 1 when port 0 or port 1 is connected with its record flag set, else 0. When the
 * answer is 1 the input processor also pulses a register bit (see docs/MAILBOX.md).
 * Both parameters are unused; the command has one data byte, 0.
 */
int ipc_is_dp_rx_condition_pending(undefined4 unused_1, undefined4 unused_2)

{
  undefined1 msg[1];
  
  msg[0] = 0;
  ipc_send_command(IPC_CMD_CHECK_DP_RX_SERVICE,1,msg,IPC_SEND_NO_WAIT);
  ipc_wait_reply(1);
  return CONCAT44(unused_2,(uint)ipc_reply_result_byte);
}
