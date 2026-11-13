/* osd_take_request_bit2  (FUN_a00b5064)
 *
 * Return and clear request bit 2 of 0xA802B08E.
 * Returns: 1 when it was set
 * Note: Posted as menu event 0x83.
 * Name basis: descriptive - read by osd_run_task_post_redraw_event
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b5064 @ 0xa00b5064, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the return value is computed from the loaded byte before the masked byte is stored back.
 */
extern unsigned char osd_request_bits;

/* Return whether request bit 2 of osd_request_bits (mask 0x04) was set, and clear it. Read by
 * osd_run_task_post_redraw_event, which posts it as menu event 0x83. Returns 1 when the bit was set,
 * otherwise 0. */
int osd_take_request_bit2(void)
{
    int shifted;
    
    shifted = osd_request_bits >> 2;
    osd_request_bits = osd_request_bits & 0xfb;
    return shifted & 1;
}
