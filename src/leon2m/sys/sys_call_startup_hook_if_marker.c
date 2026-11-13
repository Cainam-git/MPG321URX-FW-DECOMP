/* sys_call_startup_hook_if_marker  (FUN_a0152f7c)
 *
 * Call a start-up routine when the marker read back is 0x55.
 * Name basis: descriptive - tail call when ipc_read_8051_byte(1) & 0xff == 0x55; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0152f7c @ 0xa0152f7c (-mcpu=v8 -O2 -g, the section default).
 * Source form: both callees are the RAM copies of ipc_read_8051_byte (0x4008c194) and ipc_handshake_8051_bytes
 * (0x4008fa34); the second is a tail call.
 */
extern int ipc_read_8051_byte(int);
extern void ipc_handshake_8051_bytes(void);

#define IPC_MARKER_READY 0x55   /* value of shared 8051 byte 1 that callers poll for */

/*
 * Read shared 8051 byte 1; when it holds 0x55, run the handshake on shared bytes 2 and 3
 * (ipc_handshake_8051_bytes). Otherwise do nothing.
 *
 * No direct caller was found.
 */
void sys_call_startup_hook_if_marker(void)
{
    if ((ipc_read_8051_byte(1) & 0xff) == IPC_MARKER_READY) {
        ipc_handshake_8051_bytes();
    }
}
