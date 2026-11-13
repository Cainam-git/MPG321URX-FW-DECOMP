/* ipc_8051_get_boot_source  (FUN_a0133564)
 *
 * Return the boot source byte reported by the 8051.
 * Returns: byte
 * Name basis: derived - bits 8-15 of the word at offset 0xB8 of mailbox portal 0; printed as 'Boot from %02X'
 *   at start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133564 @ 0xa0133564, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: same as ipc_8051_get_status_byte1, with another word offset.
 */
extern int ipc_mailbox_read();

#define IPC_PORTAL_8051         0       /* mailbox portal between the main processor and the 8051 */
#define IPC_BOOT_WORD_OFFSET    0xb8    /* portal word 0xB8: bits 8..15 are the boot source */

/*
 * Return the boot source the 8051 reports: bits 8..15 of portal word 0xB8 (docs/MAILBOX.md: start-up release /
 * boot source). Caller: startup_bring_up_system, which waits for a value other than 0 and prints it as
 * "Boot from %02X".
 */
int ipc_8051_get_boot_source(void)
{
    unsigned int boot_word;

    boot_word = 0;
    ipc_mailbox_read(IPC_PORTAL_8051, IPC_BOOT_WORD_OFFSET, &boot_word, 1);
    return (boot_word >> 8) & 0xff;
}
