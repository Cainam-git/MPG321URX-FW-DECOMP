/* ldc_send_init_led_drivers  (FUN_a0139d38)
 *
 * Send dimming command 0x22 with the value 1: the dimming program sets up the LED drivers.
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts command 0x22; unused; the
 *   dimming program's handler of the command is ldc_cmd_init_led_drivers (fn_400013a0)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0139d38
 * Source form: the wait is a while loop with the count test after the re-read.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ms);

#define DIMMING_PORTAL 2                        /* mailbox portal 2: the dimming processor */
#define COMMAND_SLOT   0x20                     /* its command slot; 0 = free */
#define WAIT_TRIES     100                      /* checks of the slot, 1 tick apart */

/*
 * Post command 0x22 with the value 1 (word 0x22000001). If the command slot is not 0 it is checked again up to
 * 100 times, waiting 1 tick before each check; if it never becomes 0 nothing is sent. The dimming program
 * answers this command by setting up its LED driver chips (docs/MAP.md); nothing in the image calls this
 * routine or stores its address.
 */
void ldc_send_init_led_drivers(void)
{
    unsigned int slot_word = 0xffffffff;
    int tries = WAIT_TRIES;
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    while (slot_word != 0) { tries--; timer_sleep_ticks(1); ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1); if (tries == 0) break; }
    if (slot_word == 0) { slot_word = 0x22000001; ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1); }
}
