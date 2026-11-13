/* ldc_send_cmd_0x42  (FUN_a013aa38)
 *
 * Send dimming command 0x42 with a one-byte value.
 * Name basis: descriptive - waits for mailbox portal 2 slot 0x20 to be free, then posts command 0x42
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013aa38 @ 0xa013aa38, flags -mcpu=v8 -O3 -g.
 * Source form: the byte is widened into a short local first, and the goto layout is the firmware's (the
 * 'continue' on a busy slot, the separate last check); other shapes give other code.
 */
extern void ipc_mailbox_read();
extern void ipc_mailbox_write();
extern int timer_sleep_ticks();

/*
 * Send command 0x42 with a one-byte value to the dimming processor (the Tensilica core) through mailbox
 * portal 2, slot 0x20.
 *
 *   value    the value; goes into bits 0..7 of the command word, the command number 0x42 is in bits 24..31
 *
 * The slot is written only when it reads 0. It is read up to 101 times with a one-tick sleep between reads;
 * if it never reads 0 the command is dropped without any report. Same wait as ldc_send_cmd_0x84.
 * Called from ldc_api_set_dimming_mode with the value 1, for modes 1 and 2.
 */
void ldc_send_cmd_0x42(unsigned char value)
{
  short value_short;
  unsigned int slot_word;
  int tries_left;
  slot_word = 0xffffffff;                       /* any non-zero value: "busy" until a read says 0 */
  value_short = value & 0xff;
  ipc_mailbox_read(2, 0x20, &slot_word, 1);
  tries_left = 100;
  if (slot_word == 0)
  {
    goto send;
  }
  do
  {
    timer_sleep_ticks(1);
    tries_left--;
    ipc_mailbox_read(2, 0x20, &slot_word, 1);
    if (tries_left == 0)
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

  goto done;                                    /* still busy after all tries: give up */
  send:
  slot_word = value_short | 0x42000000;

  ipc_mailbox_write(2, 0x20, &slot_word, 1);
  done:
  return;

}
