/* ipc_finish_flash_handshake  (FUN_CODE_cb1d)
 *
 * Tell the main processor that the flash job is finished.
 * Name basis: proven - sets the low byte of portal word 0xB8 to 2 (after ipc_wait_flash_handshake)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cb1d @ 0xcb1d (72 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * Source form: the low-byte replacement is the 32-bit expression '(x & 0xffffff00) | 2' (bytes 0..2 loaded, byte 3
 * = 2, stored with ?C?LSTXDATA); the third argument of both callees is passed in their XDATA parameter blocks.
 */
extern unsigned long xdata DAT_EXTMEM_a4b3;
void ipc_portal_read(unsigned char offset, unsigned long *dst, unsigned char words);
void ipc_portal_write(unsigned char offset, unsigned long *src, unsigned char words);

/* Mailbox word that carries the flash handshake, and its value "done". */
#define IPC_HANDSHAKE_OFFSET 0xb8
#define IPC_HANDSHAKE_DONE   2

/*
 * Answer the flash handshake: set the low byte of the handshake word (0xB8)
 * to 2, write it back and read it once more. Called from the command switch
 * (five calls, each after ipc_wait_flash_handshake returned 1).
 */
void ipc_finish_flash_handshake(void)
{
    ipc_portal_read(IPC_HANDSHAKE_OFFSET, &DAT_EXTMEM_a4b3, 1);
    DAT_EXTMEM_a4b3 = (DAT_EXTMEM_a4b3 & 0xffffff00) | IPC_HANDSHAKE_DONE;
    ipc_portal_write(IPC_HANDSHAKE_OFFSET, &DAT_EXTMEM_a4b3, 1);
    ipc_portal_read(IPC_HANDSHAKE_OFFSET, &DAT_EXTMEM_a4b3, 1);
}
