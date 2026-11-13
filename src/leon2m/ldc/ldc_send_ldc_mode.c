/* ldc_send_ldc_mode  (FUN_a0139968)
 *
 * Send dimming command 0x20 (set LDC_Mode) with a mode value, only when the value has changed.
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts command 0x20; last value
 *   kept at 0xA802CB99; the dimming program's handler of the command is ldc_cmd_set_ldc_mode (fn_40001428)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0139968 @ 0xa0139968-0xa0139a30 (50 words), flags -mcpu=v8 -O3 -g.
 * Source form: the argument is int width (the firmware stores %i0 unextended with stb and masks it per use);
 * the decrement sits before the second read (firmware add/cmp, not addcc); the byte used in the word is an
 * 'unsigned short c = (unsigned char)p' copy taken after the first read (firmware 'and %i0,0xff,%l1' at the copy
 * and 'and %l1,0xff' at the use; an unsigned char copy gives 'mov %i0,%l1'). No aids.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ms);
extern unsigned char ldc_cmd20_last_mode;

#define DIMMING_PORTAL 2                        /* mailbox portal 2: the dimming processor */
#define COMMAND_SLOT   0x20                     /* its command slot; 0 = free */
#define WAIT_TRIES     100                      /* checks of the slot, 1 tick apart */

/*
 * Post command 0x20 with a mode byte (word 0x20000000 | mode) unless the low byte of the argument equals the
 * mode sent last (ldc_cmd20_last_mode); then nothing is sent. If the command slot is not 0 it is checked again
 * up to 100 times, waiting 1 tick before each check; if it never becomes 0 nothing is sent. The new mode is
 * remembered in either case. Called by ldc_api_set_dimming_mode.
 */
void ldc_send_ldc_mode(unsigned int mode)
{
    unsigned int slot_word;
    unsigned short mode_byte;
    int tries;

    if (ldc_cmd20_last_mode != (unsigned char)mode) {
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
            slot_word = mode_byte | 0x20000000;
            ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
        }
    }
    ldc_cmd20_last_mode = mode;
}
