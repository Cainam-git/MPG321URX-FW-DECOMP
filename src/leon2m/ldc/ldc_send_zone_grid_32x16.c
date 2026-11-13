/* ldc_send_zone_grid_32x16  (FUN_a0139b90)
 *
 * Send the 32 x 16 zone grid to the dimming processor.
 * Name basis: proven - docs/MAP.md: command 0x2A with the word 0x2A001020
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0139b90
 * The command word is built as (unsigned char 0x2A << 24) | (unsigned short 0x1020); that spelling is what gives
 * the firmware's sethi/srl/or sequence.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ms);

#define DIMMING_PORTAL 2                        /* mailbox portal 2: the dimming processor */
#define COMMAND_SLOT   0x20                     /* its command slot; 0 = free */
#define WAIT_TRIES     100                      /* checks of the slot, 1 tick apart */
#define COMMAND_ZONE_GRID 0x2a                  /* command 0x2A */
#define ZONE_GRID_32X16   0x1020                /* its value for the 32 x 16 grid (docs/MAP.md) */

/*
 * Post command 0x2A with the value 0x1020 (word 0x2A001020): the 32 x 16 zone grid. If the command slot is not
 * 0 it is checked again up to 100 times, waiting 1 tick before each check; if it never becomes 0 nothing is
 * sent. Called by System_Initialize and ldc_api_set_zone_grid.
 */
void ldc_send_zone_grid_32x16(void)
{
    unsigned int slot_word = 0xffffffff;
    int tries = WAIT_TRIES;
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    while (slot_word != 0) { tries--; timer_sleep_ticks(1); ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1); if (tries == 0) break; }
    if (slot_word == 0) { unsigned short value = ZONE_GRID_32X16; unsigned char command = COMMAND_ZONE_GRID; slot_word = (command << 24) | value; ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1); }
}
