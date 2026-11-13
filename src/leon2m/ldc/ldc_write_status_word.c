/* ldc_write_status_word  (FUN_a013a728)
 *
 * Write the word at offset 0x38 of the dimming processor's mailbox, which it reads as a channel mask.
 * Note: Its one caller sends -1 while menu layer 0 or 1 is on, else 0; the dimming program lifts the ADIM
 *   value of each masked channel to 32.
 * Name basis: derived - direct write to mailbox portal 2 offset 0x38, no wait; ldc_adim_raise_masked_channels
 *   in the dimming program tests one bit of the word per channel
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013a728 @ 0xa013a728, flags -mcpu=v8 -O2 -g.
 * Source form: the argument is copied into a local word first; its address goes to the write routine.
 */

#define DIMMING_PORTAL 2            /* mailbox portal 2: the dimming (Tensilica) processor */
#define STATUS_SLOT    0x38         /* byte offset of the word the dimming program reads as a channel bit mask */

extern int ipc_mailbox_write();

/*
 * Write one word at offset 0x38 of the dimming processor's mailbox portal, without waiting for anything.
 * The dimming program reads this word as a bit mask of channels (ldc_adim_raise_masked_channels and
 * ldc_pdim_raise_masked_channels). Its callers send -1 (all bits set) while menu layer 0 or 1 is switched on and
 * 0 otherwise, and only when that value has changed (ldc_report_menu_layer_change, the main-loop task).
 */
void ldc_write_status_word(unsigned int status)
{
    unsigned int status_word;
    status_word = status;
    ipc_mailbox_write(DIMMING_PORTAL, STATUS_SLOT, &status_word, 1);
}
