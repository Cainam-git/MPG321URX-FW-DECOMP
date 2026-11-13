/* ldc_send_direct_pwm  (FUN_a01398bc)
 *
 * Send dimming command 0x60 with a one-byte value: 1 switches direct PWM on, any other value off.
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts command 0x60; the dimming
 *   program's handler prints 'LED AS3824 Direct PWM'; only caller ldc_set_direct_pwm_off; the dimming
 *   program's handler of the command is ldc_cmd_set_direct_pwm (fn_40001994)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01398bc @ 0xa01398bc, flags -mcpu=v8 -O3 -g.
 * Source form: the firmware's branch layout is written with gotos (loop, tail check, shared send block).
 * The byte is first widened to a short (value16) and then ORed into the word.
 */

#define DIMMING_PORTAL 2            /* mailbox portal 2: the dimming (Tensilica) processor */
#define COMMAND_SLOT   0x20         /* byte offset of its command slot in the portal */
#define WAIT_TRIES     100          /* waits of timer_sleep_ticks(1) before the command is dropped */

extern void ipc_mailbox_read();
extern void ipc_mailbox_write();
extern int timer_sleep_ticks();

/*
 * Send command 0x60 (direct PWM switch) to the dimming processor. The command word is 0x60000000 | value
 * (command in bits 24..31, value in bits 0..15). value 1 switches direct PWM on, any other value switches it
 * off (the dimming processor's handler ldc_cmd_set_direct_pwm; it acts only for LED driver types 0 and 1).
 * Caller: ldc_set_direct_pwm_off, which passes 1 for its argument 0 and 0 for its argument 1.
 *
 * Wait for the dimming processor to take its previous command (the command slot reads 0): read the slot
 * once, then up to 100 times wait timer_sleep_ticks(1) (2 ticks) and read again. The command word is written
 * as soon as a read gives 0 (the read after the last wait counts too). If the slot never reads 0 nothing is
 * written and the command is lost; there is no result either way.
 */
void ldc_send_direct_pwm(unsigned char value)
{
  short value16;
  unsigned int slot_word;
  int tries;
  slot_word = 0xffffffff;
  value16 = value & 0xff;
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
    if (slot_word != 0)
    {
      continue;
    }
    goto send;
  }
  while (1);
  last_check:
  if (slot_word == 0)
  {
    goto send;
  }

  goto done;
  send:
  slot_word = value16 | 0x60000000;

  ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
  done:
  return;

}
