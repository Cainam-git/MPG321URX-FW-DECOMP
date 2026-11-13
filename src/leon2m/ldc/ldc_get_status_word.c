/* ldc_get_status_word  (FUN_a013a8ac)
 *
 * Return the status word of the dimming processor's mailbox.
 * Returns: word
 * Name basis: descriptive - mailbox portal 2 offset 0x10; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013a8ac @ 0xa013a8ac, flags -mcpu=v8 -O2 -g.
 * Source form: the word is cleared before the read and returned as read.
 */

#define DIMMING_PORTAL 2            /* mailbox portal 2: the dimming (Tensilica) processor */
#define RESULT_SLOT    0x10         /* word read back by this routine; its meaning is not shown */

extern int ipc_mailbox_read();

/*
 * Read the word at offset 0x10 of the dimming processor's mailbox portal and return it. Nothing calls this routine.
 */
unsigned int ldc_get_status_word(void)
{
    unsigned int slot_word;

    slot_word = 0;
    ipc_mailbox_read(DIMMING_PORTAL, RESULT_SLOT, &slot_word, 1);
    return slot_word;
}
