/* ldc_send_command  (FUN_a01393f0)
 *
 * Send a dimming command with a sub-code and a 16-bit value.
 * Name basis: derived - generic form: waits for mailbox portal 2 slot 0x20, then posts command, sub-code and
 *   value
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01393f0 @ 0xa01393f0 (-mcpu=v8 -O3 -g)
 * Required form: the zero test before the loop jumps straight to the write (goto build), followed by a do-while
 * with the count and slot tests at the bottom; this gives the target's early check and the closing b,a.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ms);

#define DIMMING_PORTAL 2                        /* mailbox portal 2: the dimming processor */
#define COMMAND_SLOT   0x20                     /* its command slot; 0 = free */
#define WAIT_TRIES     100                      /* checks of the slot, 1 tick apart */

/*
 * Post one command word to the command slot of the dimming processor: command in bits 24..31, sub_code in bits
 * 16..23, value in bits 0..15. If the slot is not 0 (the previous command is not taken yet) it is checked again
 * up to 100 times, waiting 1 tick before each check. If the slot never becomes 0 nothing is sent and no error
 * is reported.
 * Called by dbg_send_ldc_command and ldc_api_set_zone_grid.
 */
void ldc_send_command(unsigned int command, unsigned int sub_code, unsigned short value)
{
    unsigned int slot_word = 0xffffffff;
    int tries = WAIT_TRIES;
    
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    
    if (slot_word == 0) goto build;
    
    do {
        timer_sleep_ticks(1);
        tries--;
        ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    } while (tries != 0 && slot_word != 0);
    
    if (slot_word == 0) {
build:
        slot_word = (command << 24) | ((sub_code & 0xff) << 16) | (value & 0xffff);
        ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    }
}
