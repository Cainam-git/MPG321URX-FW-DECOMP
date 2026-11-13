/* ldc_power_down_handshake  (FUN_a01396d8)
 *
 * Run the power-down handshake with the dimming processor.
 * Name basis: proven - docs/MAP.md: power-down handshake on slot 0x34 with value 0x55AA0002; called from
 *   SYSAPI_PowerOff and SYSAPI_PowerSaving
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01396d8 @ 0xa01396d8-0xa01397ec (69 words), flags -mcpu=v8 -O3 -g.
 * Aids: one asm nop after each counter decrement (the firmware has a real 'nop' there, not a delay slot; same
 * documented aid as the accepted a00de65c family). The counters are unsigned short.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);

#define DIMMING_PORTAL    2                     /* mailbox portal 2: the dimming processor */
#define HANDSHAKE_REPLY   0x34                  /* slot the dimming processor answers in */
#define HANDSHAKE_REQUEST 0x30                  /* slot the main processor writes to */
#define HANDSHAKE_CODE    0x55aa0002            /* power-down handshake word */
#define POLL_TRIES        0xffff                /* reads of the reply slot per wait */

/*
 * Power-down handshake with the dimming processor (the power-down handshake is the only message the main
 * processor sends it after start-up, docs/MAP.md). Called by SYSAPI_PowerOff and SYSAPI_PowerSaving.
 *
 *   1. If the reply slot already reads 0x55AA0002, write 0 to the request slot and read the reply slot until it
 *      reads 0 (at most 0xFFFF reads).
 *   2. Write 0x55AA0002 to the request slot and read the reply slot until it reads 0x55AA0002 (at most 0xFFFF
 *      reads).
 * It does not report whether the waits ended by the reply or by the read count.
 */
void ldc_power_down_handshake(void)
{
  unsigned int slot_word = 0;
  unsigned short tries;

  ipc_mailbox_read(DIMMING_PORTAL, HANDSHAKE_REPLY, &slot_word, 1);
  if (slot_word == HANDSHAKE_CODE) {
    slot_word = 0;
    ipc_mailbox_write(DIMMING_PORTAL, HANDSHAKE_REQUEST, &slot_word, 1);
    slot_word = 1;
    tries = POLL_TRIES;
    do {
      ipc_mailbox_read(DIMMING_PORTAL, HANDSHAKE_REPLY, &slot_word, 1);
      tries--;
      __asm__ volatile ("nop");
      if (tries == 0)
        break;
    } while (slot_word != 0);
  }
  slot_word = HANDSHAKE_CODE;
  ipc_mailbox_write(DIMMING_PORTAL, HANDSHAKE_REQUEST, &slot_word, 1);
  slot_word = 1;
  tries = POLL_TRIES;
  do {
    ipc_mailbox_read(DIMMING_PORTAL, HANDSHAKE_REPLY, &slot_word, 1);
    tries--;
    __asm__ volatile ("nop");
    if (tries == 0)
      break;
  } while (slot_word != HANDSHAKE_CODE);
}
