/* ldc_send_panel_size_and_start  (FUN_a0139a30)
 *
 * Send the active panel size to the dimming processor and start its program.
 * Name basis: proven - docs/MAP.md: command 0x21; called from System_Initialize and the output set-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0139a30 @ 0xa0139a30, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: 0x1001 and 0xFF0101 are built from a variable (sethi + add, not a folded constant); the counter
 * is decremented before the re-read (add + cmp, not addcc); the wait is written with gotos (send / check).
 */

#define DIMMING_PORTAL 2                        /* mailbox portal 2: the dimming processor */
#define COMMAND_SLOT   0x20                     /* its command slot; 0 = free */
#define WAIT_TRIES     100                      /* checks of the slot, 1 tick apart */

#define SLOT_PANEL_SIZE    0xa0                 /* slots written before the command */
#define SLOT_WORD_A4       0xa4
#define SLOT_WORD_A8       0xa8
#define SLOT_WORD_AC       0xac
#define SLOT_TABLE_C0      0xc0                 /* 8 words */
#define SLOT_TABLE_E0      0xe0                 /* 8 words */
#define COMMAND_PANEL_SIZE_AND_START 0x21000001 /* command 0x21, value 1 */

/* The active panel row (0xA802E378, 0x58 bytes): the two halfwords sent here. */
struct panel_row {
    unsigned int word_0x00;
    unsigned short half_0x04;
    unsigned char byte_0x06, byte_0x07;
    unsigned short half_0x08, half_0x0a;
};
extern struct panel_row panel_active_row;
extern unsigned int ldc_start_words_c0[8], ldc_start_words_e0[8];
extern void ipc_mailbox_write(unsigned char, unsigned char, unsigned int *, unsigned char);
extern void ipc_mailbox_read(unsigned char, unsigned char, unsigned int *, unsigned char);
extern void timer_sleep_ticks(int);

/*
 * Write the start-up block into the dimming processor's mailbox portal, then post command 0x21 to start its
 * program (docs/MAP.md). The block, in order:
 *   slot 0xA0  halfword +8 of the active panel row in bits 16..31, halfword +0xA in bits 0..15
 *   slot 0xA4  0xFFF
 *   slot 0xA8  0x1001
 *   slot 0xAC  0xFF0101
 *   slot 0xC0  8 words from ldc_start_words_c0 (ROM)
 *   slot 0xE0  8 words from ldc_start_words_e0 (ROM)
 * Then the command slot is checked up to 100 times, 1 tick apart, until it reads 0, and 0x21000001 is written
 * to it; when the slot stays busy nothing is sent and no error is reported.
 * Called by System_Initialize and by the output set-up (panel_setup_output_after_row_change).
 */
void ldc_send_panel_size_and_start(void)
{
    unsigned int slot_word, status;
    unsigned int one = 1;
    int tries;

    slot_word = (panel_active_row.half_0x08 << 16) + panel_active_row.half_0x0a;
    ipc_mailbox_write(DIMMING_PORTAL, SLOT_PANEL_SIZE, &slot_word, 1);
    slot_word = 0xfff;
    ipc_mailbox_write(DIMMING_PORTAL, SLOT_WORD_A4, &slot_word, 1);
    slot_word = (one << 12) + one;
    ipc_mailbox_write(DIMMING_PORTAL, SLOT_WORD_A8, &slot_word, 1);
    slot_word = (0xffu << 16) + (one << 8) + one;
    ipc_mailbox_write(DIMMING_PORTAL, SLOT_WORD_AC, &slot_word, 1);
    ipc_mailbox_write(DIMMING_PORTAL, SLOT_TABLE_C0, ldc_start_words_c0, 8);
    ipc_mailbox_write(DIMMING_PORTAL, SLOT_TABLE_E0, ldc_start_words_e0, 8);
    status = 0xffffffff;
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &status, 1);
    tries = WAIT_TRIES;
    if (status == 0) goto send;
    do {
        timer_sleep_ticks(1);
        tries--;
        ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &status, 1);
        if (tries == 0) goto check;
    } while (status != 0);
    goto send;
check:
    if (status != 0) return;
send:
    status = COMMAND_PANEL_SIZE_AND_START;
    ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &status, 1);
}
