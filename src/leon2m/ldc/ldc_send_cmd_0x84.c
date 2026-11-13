/* ldc_send_cmd_0x84  (FUN_a013a8d4)
 *
 * Send dimming command 0x84 with a 16-bit value and a byte.
 *   value: 16-bit value, bits 0..15 of the command word
 *   byte_value: byte, bits 16..23 of the command word
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts the word 0x84 << 24 | byte
 *   << 16 | value; called from System_Initialize with (0x400, 0x16)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013a8d4 @ 0xa013a8d4, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the u16 value is the first parameter and the byte the second (the swapped order gives other code);
 * the control flow keeps the firmware's goto layout.
 */
extern void ipc_mailbox_read();
extern void ipc_mailbox_write();
extern int timer_sleep_ticks();
/*
 * Send command 0x84 to the dimming processor (the Tensilica core) through mailbox portal 2.
 *
 *   value       16-bit value, goes into bits 0..15 of the command word
 *   byte_value  goes into bits 16..23; the command number 0x84 is in bits 24..31
 *
 * Portal 2 offset 0x20 is the command slot; a new command is written only when it reads 0. The slot
 * is read up to 101 times with a one-tick sleep between reads. If it never reads 0 the command is dropped
 * without any report. Called once, from System_Initialize, with (0x400, 0x16).
 */
void ldc_send_cmd_0x84(unsigned int value, unsigned char byte_value)
{
  unsigned int slot_word;
  int tries_left;
  slot_word = 0xffffffff;                       /* any non-zero value: "busy" until a read says 0 */
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
  slot_word = (byte_value & 0xff) << 0x10;
  tries_left = (value << 0x10) >> 0x10;         /* the value as 16 bits; tries_left is reused as scratch */
  slot_word |= 0x84000000;
  slot_word |= tries_left;
  ipc_mailbox_write(2, 0x20, &slot_word, 1);
}
