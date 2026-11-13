/* osd_take_request_bit0  (FUN_a00b5030)
 *
 * Return and clear request bit 0 of 0xA802B08E.
 * Returns: 1 when it was set
 * Note: Posted as menu event 0x82.
 * Name basis: descriptive - read by osd_run_task_post_redraw_event
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b5030 @ 0xa00b5030, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the result and the local are unsigned char; the byte is read once into the local.
 */
extern unsigned char osd_request_bits;

/* Return whether request bit 0 of osd_request_bits (mask 0x01) was set, and clear it. Read by
 * osd_run_task_post_redraw_event, which posts it as menu event 0x82. Returns 1 when the bit was set,
 * otherwise 0. */
unsigned char osd_take_request_bit0(void)

{
  unsigned char request;
  
  request = osd_request_bits;
  osd_request_bits = osd_request_bits & 0xfe;
  return request & 1;
}
