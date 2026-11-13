/* dbg_dump_block_words  (FUN_CODE_d938)
 *
 * Read blocks through the USB block port and print them as 32-bit words.
 *   addr: address
 *   word_count
 * Name basis: derived - usb_port_read_blocks into DATA 0x22, printf '%08lX' per word
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. LARGE parameters addr (0x08F3..0x08F6, stored by ?C?LSTXDATA at entry) and
 * word_count (0x08F7), local i (0x08F8).
 * usb_port_read_blocks has the prototype (unsigned long addr, unsigned char n): n is a memory parameter (a char
 * after a long gets no register) at ?_FUN_CODE_e373?BYTE+4 = 0x098A, ?_FUN_CODE_e373?BYTE = 0x0986. Keil loads addr
 * (R4..R7) before it stores n, as the firmware does.
 * Source form the bytes depend on: two calls, 'if (word_count < 8) ...(addr, 1); else ...(addr, word_count >> 3);'.
 * Keil hoists the shared addr load in front of the JNC and cross-jumps the shared MOVX / LCALL tail (a one-call
 * form or ?: gives other code). Judge keys recorded in symbols/8051_bank2.libs.json: ?_FUN_CODE_e373?BYTE 2438
 * (0x0986), ?FUN_CODE_d938?XD 2291 (0x08F3), ?C?LLDIDATA 13444 (0x3484).
 */
extern unsigned char data usb_block_buffer[];   /* the block buffer usb_port_read_blocks fills */
extern void lib_printf517(void *fmt, ...) large;
void usb_port_read_blocks(unsigned long addr, unsigned char n);

/* dbg_dump_block_words: read port memory at block addr into the block buffer (DATA 0x22) and print its first
 * word_count 32-bit words, each with "%08lX\n" (CODE 0xC9CB).
 *
 * A block holds eight words: word_count / 8 blocks are read, one block when word_count is below 8. A word_count that
 * is not a multiple of 8 therefore prints words past the blocks just read.
 * Caller: usb_read_port_status_record, with the port's buffer block and word_count 1. */
void dbg_dump_block_words(unsigned long addr, unsigned char word_count)
{
    unsigned char i;
    if (word_count < 8) usb_port_read_blocks(addr, 1);
    else usb_port_read_blocks(addr, word_count >> 3);
    for (i = 0; i < word_count; i++)
        lib_printf517((void code *)0xc9cb, ((unsigned long data *)usb_block_buffer)[i]);
}
