/* ldc_send_gain_table1_point  (FUN_a013a500)
 *
 * Send dimming command 0x51 with a sub-code byte and a 16-bit value (one point of gain table 1).
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts 0x51, sub-code in bits
 *   16..23, value in bits 0..15; the dimming program's handler changes one point of the table it prints as
 *   LDC_GainTable_ANV1; unused; the dimming program's handler of the command is ldc_cmd_set_gain_table1_point
 *   (fn_400018f0)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013a500 @ 0xa013a500, flags -mcpu=v8 -O3 -g.
 * Source form: the firmware's branch layout is written with gotos (loop, tail check, shared send block).
 * The tries counter is reused for the 16-bit value after the wait; the value is cut to its low 16 bits
 * with an unsigned shift pair.
 */

#define DIMMING_PORTAL 2            /* mailbox portal 2: the dimming (Tensilica) processor */
#define COMMAND_SLOT   0x20         /* byte offset of its command slot in the portal */
#define WAIT_TRIES     100          /* waits of timer_sleep_ticks(1) before the command is dropped */

extern void ipc_mailbox_read();
extern void ipc_mailbox_write();
extern int timer_sleep_ticks();

/*
 * Send command 0x51 to the dimming processor: change one point of its 5-point gain table ANV1 (handler
 * ldc_cmd_set_gain_table1_point). The command word is 0x51000000 | (sub_code & 0xff) << 16 | (value & 0xffff):
 * sub_code selects the point and whether x or y is changed, value is the new x or y. Nothing calls this routine.
 *
 * Wait for the dimming processor to take its previous command (the command slot reads 0): read the slot
 * once, then up to 100 times wait timer_sleep_ticks(1) (2 ticks) and read again. The command word is written
 * as soon as a read gives 0 (the read after the last wait counts too). If the slot never reads 0 nothing is
 * written and the command is lost; there is no result either way.
 */
void ldc_send_gain_table1_point(unsigned char sub_code, unsigned int value)
{
  unsigned int slot_word;
  int tries;
  slot_word = 0xffffffff;
  ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
  tries = WAIT_TRIES;
  if (slot_word == 0)
  {
    goto send;
  }
  do
  {
    timer_sleep_ticks(1);
    tries--;
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    if (tries == 0)
    {
      goto last_check;
    }
    if (slot_word == 0)
    {
      goto send;
    }
  }
  while (1);
  last_check:
  if (slot_word == 0)
  {
    goto send;
  }

  return;
  send:
  slot_word = (sub_code & 0xff) << 0x10;

  tries = (value << 0x10) >> 0x10;
  slot_word |= 0x51000000;
  slot_word |= tries;
  ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
}
