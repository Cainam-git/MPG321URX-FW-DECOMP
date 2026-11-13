/* ipc_handshake_8051_bytes  (FUN_a002fa34)
 *
 * Write 0xDD to shared byte 2, wait for 0xAA in byte 3, then clear the bytes (0x88 on timeout)
 * Note: Called when shared byte 1 reads 0x55; up to 0x7D001 polls.
 * Name basis: derived - code: ipc_write_8051_byte / ipc_read_8051_byte sequence; callers
 *   sys_call_startup_hook_if_marker, sys_main_loop_periodic_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002fa34 @ 0xa002fa34-0xa002fae0 (43 words), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: eight inline nop instructions (written as asm nops) after each failed poll; the poll count is
 * tested after the increment, as 'while (++i <= 0x7d000)'.
 */
extern unsigned char ipc_read_8051_byte(unsigned char channel);
extern void ipc_write_8051_byte(unsigned char channel, unsigned char value);

#define HANDSHAKE_REQUEST  0xdd         /* written to shared byte 2 */
#define HANDSHAKE_ANSWER   0xaa         /* expected in shared byte 3 */
#define HANDSHAKE_TIMEOUT  0x88         /* left in shared byte 2 when no answer came */
#define HANDSHAKE_POLLS    0x7d001      /* reads of byte 3 before giving up */

/*
 * Ask the 8051 for an answer through the shared bytes 2 and 3 and clear the three bytes 1..3 afterwards.
 * Writes HANDSHAKE_REQUEST to byte 2, then reads byte 3 up to HANDSHAKE_POLLS times until it holds HANDSHAKE_ANSWER.
 * On the answer, bytes 1, 2 and 3 are set to 0; after the last poll, byte 2 is left at HANDSHAKE_TIMEOUT instead.
 * Callers: sys_call_startup_hook_if_marker (when byte 1 reads IPC_MARKER_READY, 0x55); the start-up code also
 * installs it as the handler of interrupt source 1.
 */
void ipc_handshake_8051_bytes(void)
{
    unsigned int polls = 0;

    ipc_read_8051_byte(3);
    ipc_write_8051_byte(2, HANDSHAKE_REQUEST);
    do {
        if (ipc_read_8051_byte(3) == HANDSHAKE_ANSWER) {
            ipc_write_8051_byte(1, 0);
            ipc_write_8051_byte(2, 0);
            ipc_write_8051_byte(3, 0);
            return;
        }
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
    } while (++polls <= HANDSHAKE_POLLS - 1);
    ipc_write_8051_byte(1, 0);
    ipc_write_8051_byte(2, HANDSHAKE_TIMEOUT);
    ipc_write_8051_byte(3, 0);
}
