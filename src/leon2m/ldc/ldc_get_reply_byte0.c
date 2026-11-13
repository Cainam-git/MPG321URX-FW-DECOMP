/* ldc_get_reply_byte0  (FUN_a013a884)
 *
 * Return the top byte of the dimming processor's reply word.
 * Returns: byte
 * Name basis: descriptive - mailbox portal 2 offset 0x4C; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013a884 @ 0xa013a884, flags -mcpu=v8 -O2 -g.
 * Source form: the word is cleared before the read; the result is the unsigned char cast of word >> 24.
 */

#define DIMMING_PORTAL 2            /* mailbox portal 2: the dimming (Tensilica) processor */
#define BRIGHTNESS_STATUS_SLOT 0x4c /* word the dimming program posts its brightness status in (ldc_post_brightness_status) */

extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern int dbg_printf();

/*
 * Read the brightness status word of the dimming processor (offset 0x4C of its mailbox portal) and return its
 * bits 24..31, the top byte. Nothing calls this routine.
 */
unsigned char ldc_get_reply_byte0(void)
{
    unsigned int status_word = 0;
    ipc_mailbox_read(DIMMING_PORTAL, BRIGHTNESS_STATUS_SLOT, &status_word, 1);
    return (unsigned char)(status_word >> 24);
}
