/* ldc_get_reply_byte2  (FUN_a013a824)
 *
 * Return the third byte of the dimming processor's reply word.
 * Returns: byte
 * Name basis: descriptive - mailbox portal 2 offset 0x4C; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013a824 @ 0xa013a824, flags -mcpu=v8 -O3 -g.
 * Source form: one unsigned int local, cleared before the read, gives the clear / load pair of the target; the
 * result is the expression (word & 0xff00) >> 8.
 */

#define DIMMING_PORTAL 2            /* mailbox portal 2: the dimming (Tensilica) processor */
#define BRIGHTNESS_STATUS_SLOT 0x4c /* word the dimming program posts its brightness status in (ldc_post_brightness_status) */

extern void ipc_mailbox_read();

/*
 * Read the brightness status word of the dimming processor (offset 0x4C of its mailbox portal) and return its
 * bits 8..15, the third byte counted from the top. Nothing calls this routine.
 */
unsigned int ldc_get_reply_byte2(void)
{
    unsigned int status_word;

    status_word = 0;
    ipc_mailbox_read(DIMMING_PORTAL, BRIGHTNESS_STATUS_SLOT, &status_word, 1);
    return (status_word & 0xff00) >> 8;
}
