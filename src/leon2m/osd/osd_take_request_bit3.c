/* osd_take_request_bit3  (FUN_a00b5048)
 *
 * Return and clear request bit 3 of 0xA802B08E.
 * Returns: 1 when it was set
 * Note: Posted as menu event 0x81.
 * Name basis: descriptive - read by osd_run_task_post_redraw_event
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b5048 @ 0xa00b5048, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the byte is loaded once into an unsigned int local that feeds both the 'and' for the store and
 * the shift for the return value; this gives the firmware's sequence of load, and, shift, store.
 */
extern unsigned char osd_request_bits;

/* Return whether request bit 3 of osd_request_bits (mask 0x08) was set, and clear it. Read by
 * osd_run_task_post_redraw_event, which posts it as menu event 0x81. Returns 1 when the bit was set,
 * otherwise 0. */
unsigned int osd_take_request_bit3(void)
{
    unsigned int request = osd_request_bits;
    unsigned int shifted = request >> 3;
    osd_request_bits = request & 0xf7;
    return shifted & 1;
}
