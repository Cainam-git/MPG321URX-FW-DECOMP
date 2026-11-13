/* ipc_8051_service  (FUN_a0136d08)
 *
 * Flush the outgoing queue and poll the incoming slots once.
 * Name basis: derived - ipc_8051_tx_queue_flush, then ipc_8051_poll_messages; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0136d08, flags -mcpu=v8 -O2 -g. Both callees are declared without a prototype, as the firmware's own
 * calls need; the six parameters are passed on to the second call.
 */
extern int ipc_8051_poll_messages();
extern int ipc_8051_tx_queue_flush();

/*
 * One service step of the 8051 mailbox: push waiting messages out (ipc_8051_tx_queue_flush), then check the incoming
 * slots (ipc_8051_poll_messages). Nothing in the firmware calls this routine.
 *   pass_1 .. pass_6: handed on unchanged to ipc_8051_poll_messages
 */
void ipc_8051_service(unsigned int pass_1,unsigned int pass_2,unsigned int pass_3,unsigned int pass_4,
                 unsigned int pass_5,unsigned int pass_6)

{
  ipc_8051_tx_queue_flush();
  ipc_8051_poll_messages(pass_1,pass_2,pass_3,pass_4,pass_5,pass_6);
  return;
}
