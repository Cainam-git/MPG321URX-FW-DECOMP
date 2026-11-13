/* ldc_is_reply_byte_set  (FUN_a013a7f4)
 *
 * Return whether the low byte of the dimming processor's reply word is non-zero.
 * Returns: 0 or 1
 * Name basis: descriptive - mailbox portal 2 offset 0x4C; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013a7f4 @ 0xa013a7f4, flags -mcpu=v8 -O2 -g.
 * Source form: the two unused parameters of the decompiled routine are kept; the result is the comparison of the
 * low byte of the word with zero, converted to unsigned int.
 */

#define DIMMING_PORTAL 2            /* mailbox portal 2: the dimming (Tensilica) processor */
#define BRIGHTNESS_STATUS_SLOT 0x4c /* word the dimming program posts its brightness status in (ldc_post_brightness_status) */

extern int ipc_mailbox_read();

/*
 * Read the brightness status word of the dimming processor (offset 0x4C of its mailbox portal) and return 1 when
 * its low byte is not zero, else 0. Nothing calls this routine; the arguments are not used.
 */
unsigned int ldc_is_reply_byte_set(unsigned int unused_1, unsigned int unused_2)

{
  unsigned int status_word;

  status_word = 0;
  ipc_mailbox_read(DIMMING_PORTAL, BRIGHTNESS_STATUS_SLOT, &status_word, 1);
  return (unsigned int)((unsigned char)status_word != '\0');
}
