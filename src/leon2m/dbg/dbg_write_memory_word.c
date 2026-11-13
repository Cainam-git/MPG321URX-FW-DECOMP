/* dbg_write_memory_word  (FUN_a00dd3d4)
 *
 * Store a word at an address and print it.
 * Name basis: proven - prints 'Address Fail' for an unaligned address; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd3d4 @ 0xa00dd3d4-0xa00dd43c (26 words).
 * Source form: the final "\n" is the string at 0xfef90 (the tail of another string, merged by the linker), so it
 * is named by its address symbol s_000fef90. The "Address Fail" text carries its own "\n".
 */
extern void uart_put_string(const char *);
extern void uart_put_hex32(unsigned int val);
extern const char s_000fef90[];

/*
 * Debug aid: write value to the word at address and show it on the debug serial port.
 *
 *   address  where to write; 0 does nothing
 *   value    the word to store
 *
 * Prints " [<address>] : " first. An address that is not a multiple of 4 prints "Address Fail" and writes
 * nothing; otherwise the value is stored and printed. Nothing in the image calls this routine.
 */
void dbg_write_memory_word(unsigned int *address, unsigned int value)
{
    if (address) {
        uart_put_string("\n [");
        uart_put_hex32((unsigned int)address);
        uart_put_string("] : ");
        if ((unsigned int)address & 3)
            uart_put_string("Address Fail\n");
        else {
            *address = value;
            uart_put_hex32(value);
            uart_put_string(s_000fef90);
        }
    }
}
