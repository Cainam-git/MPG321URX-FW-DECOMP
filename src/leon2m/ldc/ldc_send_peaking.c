/* ldc_send_peaking  (FUN_a01397f4)
 *
 * Send dimming command 0x82 (peaking off or on) with a mode byte, only when the byte has changed.
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts command 0x82; last value
 *   kept at 0xA802A45A; the dimming program's handler of the command is ldc_cmd_set_peaking (fn_4000165c)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01397f4 @ 0xa01397f4 (-mcpu=v8 -O3 -g)
 * Same code as ldc_send_ldc_mode with other constants. The argument is int width (the firmware stores %i0
 * unextended with stb and masks it per use); the byte used in the word is an 'unsigned short c = (unsigned char)p'
 * copy taken after the first read, and the counter is decremented before the second read.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ms);
extern unsigned char ldc_cmd82_last_mode;

#define DIMMING_PORTAL 2                        /* mailbox portal 2: the dimming processor */
#define COMMAND_SLOT   0x20                     /* its command slot; 0 = free */
#define WAIT_TRIES     100                      /* checks of the slot, 1 tick apart */

/*
 * Post command 0x82 with a mode byte (word 0x82000000 | mode) unless the low byte of the argument equals the
 * mode sent last (ldc_cmd82_last_mode); then nothing is sent. If the command slot is not 0 it is checked again
 * up to 100 times, waiting 1 tick before each check; if it never becomes 0 nothing is sent. The new mode is
 * remembered in either case. Called by ldc_api_set_mode_byte.
 */
void ldc_send_peaking(unsigned int mode)
{
    unsigned int slot_word;
    unsigned short mode_byte;
    int tries;

    if (ldc_cmd82_last_mode != (unsigned char)mode) {
        slot_word = 0xffffffff;
        ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
        mode_byte = (unsigned char)mode;
        tries = WAIT_TRIES;
        while (slot_word != 0) {
            timer_sleep_ticks(1);
            tries--;
            ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
            if (tries == 0)
                break;
        }
        if (slot_word == 0) {
            slot_word = mode_byte | 0x82000000;
            ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
        }
    }
    ldc_cmd82_last_mode = mode;
}
