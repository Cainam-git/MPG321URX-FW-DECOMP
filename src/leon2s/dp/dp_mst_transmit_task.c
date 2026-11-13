/* dp_mst_transmit_task  (FUN_a00dac08)
 *
 * Run the transmit side: send replies and up messages chunk by chunk, with time-outs.
 * Name basis: derived - state step for the current port; called from the MST service task
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dac08 @ 0xa00dac08-0xa00dae90 (162 words), flags -mcpu=v8 -Os -g.
 * Declared here: dp_mst_send_down_reply_step / dp_mst_send_up_message_step with an unsigned char result (btst
 * 0xff after the calls), dp_mst_get_reply_timeout / dp_mst_get_reply_timeout_copy with an unsigned short result
 * (sll/srl 16); dp_mst_get_reply_timeout_copy receives (reply_pending & 1, up_pending & 1).
 * Source forms: up_pending is set by an if/else inside the port == 0 test; the two groups of stores are static
 * inline helpers start_reply_wait() / start_up_wait(), each called after both call sites of its step routine
 * (firmware call sites 0xa00dacc0 and 0xa00dad3c, 0xa00dace4 and 0xa00dad80; the store tails are merged at
 * 0xa00dad54 and 0xa00dad98); status is an unsigned char; 'not_up = ~up_pending;' comes before
 * 'reply_flag = reply_pending != 0;' for the (reply_flag & not_up) test.
 */

#define TX_STATE_DOWN_REPLY   2     /* transmit states of the port: a down reply is being sent ... */
#define TX_STATE_UP_MESSAGE   4     /* ... or a message from the output (down reply or up request) */
#define RING_REPLY            2     /* dp_mst_get_ring_distance modes: the reply ring ... */
#define RING_UP               4     /* ... and the ring of messages from the output */
#define NO_PENDING_UP         0xff  /* dp_mst_find_up_message_end: no complete up message waiting */
#define STATUS_WORD           (0x258 / 4)
#define STATUS_BITS_BUSY      0x18  /* bits 3..4 of the status byte */

extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_reply_read_indexes[];
extern unsigned char dp_mst_message_state_reply_write_indexes[];
extern unsigned char dp_mst_message_state_up_wait_flags[];
extern unsigned char dp_mst_message_state_reply_wait_flags[];
extern unsigned int dp_mst_message_state_reply_ticks[];
extern unsigned int dp_mst_message_state_up_ticks[];
extern volatile unsigned int *dp_mst_msg_reg_blocks[];
extern unsigned char dp_mst_find_up_message_end(void);
extern unsigned char dp_mst_get_port_tx_state(void);
extern unsigned char dp_mst_get_ring_distance(unsigned char);
extern unsigned char dp_mst_send_down_reply_step(void);
extern unsigned char dp_mst_send_up_message_step(void);
extern unsigned short dp_mst_get_reply_timeout(void);
extern unsigned short dp_mst_get_reply_timeout_copy(unsigned int, unsigned int);
extern void dp_mst_advance_tx_index(unsigned char);
extern void dp_mst_clear_ready_bit(unsigned char);
extern unsigned int timer_get_ticks(void);

/* A down reply chunk was sent: wait for it, with the time of sending. */
static inline void start_reply_wait(void)
{
  dp_mst_message_state_reply_wait_flags[dp_mst_message_state_port] = 1;
  dp_mst_message_state_up_wait_flags[dp_mst_message_state_port] = 0;
  dp_mst_message_state_reply_ticks[dp_mst_message_state_port] = timer_get_ticks();
}
/* A chunk of a message from the output was sent: the same for the up side. */
static inline void start_up_wait(void)
{
  dp_mst_message_state_up_wait_flags[dp_mst_message_state_port] = 1;
  dp_mst_message_state_reply_wait_flags[dp_mst_message_state_port] = 0;
  dp_mst_message_state_up_ticks[dp_mst_message_state_port] = timer_get_ticks();
}

/*
 * Transmit side of the MST service for the current port: send the next chunk of a down reply or of an up
 * request, or give up a chunk that stays unanswered too long. Called once per round by dp_mst_task; no
 * parameters, no result.
 *
 * Two kinds of work can be waiting: reply_pending (the reply ring of the port has entries: write index differs
 * from read index) and up_pending (port 0 only: dp_mst_find_up_message_end finds a complete up message).
 * status is the byte at word 0x258 of the port's message register block.
 *  - Nothing pending and bits 3..4 of status clear: return.
 *  - Bits 3..4 clear (so something is pending): the transmit state of the port decides. State 2 continues the
 *    down reply (dp_mst_send_down_reply_step), state 4 continues the up message (dp_mst_send_up_message_step).
 *    In the idle state a new message is started: the down reply when only replies are pending, otherwise the
 *    one whose ring has more entries (a tie goes to the reply). When the step routine returns non-zero the
 *    time of sending is stored and the port waits for that kind (start_reply_wait / start_up_wait).
 *  - Bits 3..4 set: nothing is sent. When the last down reply chunk was sent more than 3000 ticks ago and the
 *    port is waiting for it, the reply is given up (dp_mst_advance_tx_index(1)). Otherwise the same check for
 *    the up message (dp_mst_clear_ready_bit(1)).
 */
void dp_mst_transmit_task(void)
{
  unsigned char reply_pending;
  unsigned char up_pending;
  unsigned char tx_state;
  unsigned int reply_flag;
  unsigned int not_up;
  unsigned int now;
  unsigned char status;
  unsigned char k;
  reply_pending = dp_mst_message_state_reply_write_indexes[dp_mst_message_state_port] != dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port];
  if (dp_mst_message_state_port == 0)
  {
    if (dp_mst_find_up_message_end() != NO_PENDING_UP)
      up_pending = 1;
    else
      up_pending = 0;
  }
  else
    up_pending = 0;
  status = dp_mst_msg_reg_blocks[dp_mst_message_state_port][STATUS_WORD];
  if ((reply_pending | up_pending) == 0 && !(status & STATUS_BITS_BUSY))
    return;
  if (!(status & STATUS_BITS_BUSY))
  {
    tx_state = dp_mst_get_port_tx_state();
    if (tx_state == TX_STATE_DOWN_REPLY)
    {
      if (dp_mst_send_down_reply_step())
        start_reply_wait();
      return;
    }
    if (tx_state == TX_STATE_UP_MESSAGE)
    {
      if (dp_mst_send_up_message_step())
        start_up_wait();
      return;
    }
    not_up = ~up_pending;
    reply_flag = reply_pending != 0;
    if ((reply_flag & not_up) || (dp_mst_get_ring_distance(RING_REPLY) >= dp_mst_get_ring_distance(RING_UP)))
    {
      if (dp_mst_send_down_reply_step())
        start_reply_wait();
      return;
    }
    if (dp_mst_send_up_message_step())
      start_up_wait();
    return;
  }
  now = timer_get_ticks();
  k = dp_mst_message_state_port;
  if (((now - dp_mst_message_state_reply_ticks[k]) > dp_mst_get_reply_timeout()) && dp_mst_message_state_reply_wait_flags[k])
  {
    dp_mst_advance_tx_index(1);
    dp_mst_message_state_reply_wait_flags[dp_mst_message_state_port] = 0;
    return;
  }
  now = timer_get_ticks();
  k = dp_mst_message_state_port;
  if (((now - dp_mst_message_state_up_ticks[k]) > dp_mst_get_reply_timeout_copy(reply_pending, up_pending)) && dp_mst_message_state_up_wait_flags[k])
  {
    dp_mst_clear_ready_bit(1);
    dp_mst_message_state_up_wait_flags[dp_mst_message_state_port] = 0;
  }
}
