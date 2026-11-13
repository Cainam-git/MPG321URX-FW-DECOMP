/* ldc_send_user_pdim  (FUN_a0139ddc)
 *
 * Send dimming command 0x30 (usUserPDIM): a 10-bit level scaled to 12 bits, when it has changed.
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts command 0x30; last value
 *   kept at 0xA802A45C; unused; the dimming program's handler of the command is ldc_cmd_set_user_pdim
 *   (fn_400014c0)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0139ddc @ 0xa0139ddc-0xa0139ed0 (61 words), flags -mcpu=v8 -O3 -g.
 * Source form: the polling skeleton of ldc_send_panel_size_and_start (goto send / check / done); the equal-value test jumps to
 * the final store (the firmware's early branch targets that sth). The ROM mailbox routines are declared without
 * parameter lists, as in ldc_send_gain_table1_point; with prototypes the -1 store is scheduled one slot earlier.
 */
extern unsigned short ldc_cmd30_last_level;
extern void ipc_mailbox_read();
extern void ipc_mailbox_write();
extern int timer_sleep_ticks(int ms);

#define DIMMING_PORTAL 2                        /* mailbox portal 2: the dimming processor */
#define COMMAND_SLOT   0x20                     /* its command slot; 0 = free */
#define WAIT_TRIES     100                      /* checks of the slot, 1 tick apart */
#define LEVEL_MAX_10_BIT 1023
#define LEVEL_MAX_12_BIT 4095

/*
 * Post command 0x30 with a level scaled from 0..1023 to 0..4095 (word 0x30000000 | level * 4095 / 1023), unless
 * the argument equals the level sent last (ldc_cmd30_last_level); then nothing is sent. If the command slot is
 * not 0 it is checked again up to 100 times, waiting 1 tick before each check; if it never becomes 0 nothing is
 * sent. The new level is remembered on every path. Nothing in the image calls this routine or stores its
 * address.
 */
void ldc_send_user_pdim(unsigned short level)
{
    unsigned int slot_word;
    int tries;
    unsigned short scaled_level;

    if (ldc_cmd30_last_level == level)
        goto done;
    scaled_level = (unsigned int)level * LEVEL_MAX_12_BIT / LEVEL_MAX_10_BIT;
    slot_word = 0xffffffff;
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    tries = WAIT_TRIES;
    if (slot_word == 0)
        goto send;
    do {
        timer_sleep_ticks(1);
        tries--;
        ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
        if (tries == 0)
            goto check;
    } while (slot_word != 0);
    goto send;
check:
    if (slot_word != 0)
        goto done;
send:
    slot_word = 0x30000000 | scaled_level;
    ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
done:
    ldc_cmd30_last_level = level;
}
