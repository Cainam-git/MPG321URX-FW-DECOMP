/* ldc_send_zone_counts  (FUN_a0139c3c)
 *
 * Send the two zone counts as powers of two to the dimming processor.
 * Name basis: proven - docs/MAP.md: command 0x2B; called from System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0139c3c @ 0xa0139c3c-0xa0139d38 (63 words), flags -mcpu=v8 -O3 -g.
 * Source form: the second count is an unsigned short set to 0 after the first count loop (the firmware then
 * starts it in the register of the first loop's final test value, which is 0).
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ms);

#define DIMMING_PORTAL 2                        /* mailbox portal 2: the dimming processor */
#define COMMAND_SLOT   0x20                     /* its command slot; 0 = free */
#define WAIT_TRIES     100                      /* checks of the slot, 1 tick apart */
#define COMMAND_ZONE_COUNTS 0x2b                /* command 0x2B */
#define ZONE_COUNT_A 0x20                       /* 1 << 5 */
#define ZONE_COUNT_B 0x40                       /* 1 << 6 */

/*
 * Post command 0x2B with the base-2 logarithms of the two zone counts 0x20 and 0x40 (docs/MAP.md: 5 and 6):
 * word 0x2B000000 | (log2 of the second count << 8) | log2 of the first count. The logarithms are counted at
 * run time by shifting each count right until it reaches 1. If the command slot is not 0 it is checked again up
 * to 100 times, waiting 1 tick before each check; if it never becomes 0 nothing is sent. Called by
 * System_Initialize.
 */
void ldc_send_zone_counts(void)
{
    unsigned int slot_word;
    unsigned int counts;
    unsigned short first, second;
    unsigned int first_log2;
    unsigned short second_log2;
    int tries;

    first = ZONE_COUNT_A;
    second = ZONE_COUNT_B;
    first_log2 = 0;
    while (first >> 1) {
        first >>= 1;
        first_log2++;
    }
    second_log2 = 0;
    while (second >> 1) {
        second >>= 1;
        second_log2++;
    }
    counts = first_log2 | (second_log2 << 8);
    slot_word = 0xffffffff;
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    tries = WAIT_TRIES;
    while (slot_word != 0) {
        timer_sleep_ticks(1);
        tries--;
        ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
        if (tries == 0)
            break;
    }
    if (slot_word == 0) {
        slot_word = (unsigned short)counts | (COMMAND_ZONE_COUNTS << 24);
        ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    }
}
