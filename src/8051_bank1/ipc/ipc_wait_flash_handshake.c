/* ipc_wait_flash_handshake  (FUN_CODE_c163)
 *
 * Wait until the main processor signals that a flash job may start.
 * Returns: 1 ready, 0 time-out
 * Name basis: proven - polls portal word 0xB8 until its low byte is 1 (max 20000 reads); commands 0x11..0x15,
 *   0x27
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c163, OPTIMIZE(8,SPEED) LARGE. The low-byte test '(word & 0xff) == 1' is a 32-bit compare of the
 * zero-extended byte.
 */
extern unsigned long xdata DAT_EXTMEM_a4b3;
void ipc_portal_read(unsigned char off, unsigned long *dst, unsigned char n);

/*
 * ipc_wait_flash_handshake - read mailbox portal word 0xB8 up to 20000 times until its low byte is 1 (the main
 * processor's request). Returns 1 when it became 1, 0 after 20000 reads.
 * Callers: the command switch ipc_run_command (five calls): the flash-job commands run their job only when it returns 1,
 * then call ipc_finish_flash_handshake.
 */
unsigned char ipc_wait_flash_handshake(void)
{
    unsigned int tries;

    for (tries = 0; tries < 20000; tries++) {
        ipc_portal_read(0xb8, &DAT_EXTMEM_a4b3, 1);
        if ((DAT_EXTMEM_a4b3 & 0xff) == 1) break;
    }
    if (tries == 20000) return 0;
    return 1;
}
