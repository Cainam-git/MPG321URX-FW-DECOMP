/* ipc_portal_read  (FUN_CODE_a4e9)
 *
 * Read words from the mailbox portal shared with the main processor.
 *   offset: byte offset
 *   words
 *   word_count
 * Name basis: proven - AHB 0x9F0A0100 + offset through reg_ahb_read32 (header of ipc_service_mailbox);
 *   counterpart ipc_portal_write
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a4e9 @ 0xa4e9..0xa57e (149 bytes), OPTIMIZE(8,SPEED) LARGE (level 7 gives 157 bytes).
 * Twin of ipc_portal_write (ipc_portal_write). word_count is passed in memory (XDATA 0xA4BD) because the generic
 *   pointer takes R1..R3. Only the low address byte changes, with an 8-bit add.
 * The firmware has a Keil common-entry block 0xA4D2..0xA4E9 in front of this routine (argument set-up shared by
 *   the calls in ipc_service_mailbox's module, ipc/ipc_service_mailbox.c). It is judged with that module; this file judges
 *   only 0xA4E9..0xA57E.
 */
#define PORTAL_AHB_BASE  0x9F0A0100   /* AHB address of the portal shared with the main processor */

/* One 32-bit AHB word, also as its four bytes (Keil stores the most significant byte first). */
typedef union { unsigned long value; unsigned char bytes[4]; } ahb_word;
extern ahb_word xdata reg_ahb_read_addr;
extern ahb_word reg_ahb_read32(void);

/*
 * ipc_portal_read - read word_count consecutive 32-bit words from the mailbox portal, starting at byte offset
 * offset of PORTAL_AHB_BASE, through the AHB bridge (reg_ahb_read32 reads the word at reg_ahb_read_addr).
 *   offset      byte offset in the portal (0x00..0xFF: only address bits 7..0 change)
 *   words       receives the words
 *   word_count  number of words
 * This is how the 8051 reads what the main processor posts: the command word and the message slots
 * (ipc_service_mailbox and the slot searches of its module), the word at 0x0C (MailBox_UpdateDDCFlag) and the
 * handshake word at 0xB8 (ipc_wait_flash_handshake, ipc_finish_flash_handshake, startup_release_leon2m).
 */
void ipc_portal_read(unsigned char offset, unsigned long *words, unsigned char word_count)
{
    unsigned char i;
    ahb_word addr;
    ahb_word word;
    addr.value = PORTAL_AHB_BASE;
    for (i = 0; i < word_count; i++) {
        addr.bytes[3] = offset + i * 4;    /* address bits 7..0 */
        reg_ahb_read_addr = addr;
        word = reg_ahb_read32();
        words[i] = word.value;
    }
}
