/* dbg_write_memory_word  (CED_ALL_4)
 *
 * Store a word at an address and print it.
 * Name basis: proven - debug command; only for an address that is a multiple of 4
 *
 * Matching notes
 * --------------
 * CED_ALL_4 (leon2s 0xa00b258c-0xa00b25f8, 108 bytes), flags -mcpu=v8 -Os -g.
 */
extern char DAT_a006c698[], DAT_a006c6b0[], s_a0069ee8[];
extern void uart_put_string(const char *);
extern void uart_put_hex32(unsigned int);
extern void reg_write_word(unsigned int *, unsigned int);

/*
 * Debug console command: store a word at an address and print what was done.
 *
 *   addr: address to write; 0 does nothing.
 *   val:  the word to store.
 *
 * Prints a line break, " [", the address and "] : ". An address that is not a multiple of 4 is refused with
 * "Address Fail" and nothing is stored; otherwise the word is stored (through reg_write_word) and printed.
 */
void dbg_write_memory_word(unsigned int addr, unsigned int val)
{
    if (addr == 0)
        return;
    uart_put_string(DAT_a006c698);  /* "\n [" */
    uart_put_hex32(addr);
    uart_put_string(DAT_a006c6b0);  /* "] : " */
    if (addr & 3) {
        uart_put_string("Address Fail\n");
    } else {
        reg_write_word((unsigned int *)addr, val);
        uart_put_hex32(val);
        uart_put_string(s_a0069ee8);  /* "\n" */
    }
}
