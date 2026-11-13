/* dbg_dump_memory_words  (FUN_a00dd43c)
 *
 * Print memory as lines of address and four words.
 * Name basis: proven - 32 words when the count is 0; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd43c @ 0xa00dd43c-0xa00dd540 (65 words).
 * The strings are named by their firmware addresses: " " (0x198bb0) and "\n" (0xfef90) are tails of other strings
 * merged by the linker, and " : " (0x198b60) and the nine spaces (0x198ba8) sit between strings of other
 * functions of this file.
 */
extern void uart_put_string(const char *);
extern void uart_put_hex32(unsigned int val);
extern const char s_000fef90[];
extern const char s_00198bb0[];

#define DUMP_DEFAULT_WORDS  32      /* words shown when the count is 0 */
#define DUMP_LINE_WORDS     4       /* words per line (16 bytes) */

/*
 * Debug aid: print a block of memory on the debug serial port.
 *
 *   addr   first address (rounded down to a word); 0 prints nothing
 *   count  number of words; 0 means 32
 *
 * Each line shows the address of a 16-byte row and its four words. The rows run from addr rounded down to a
 * multiple of 32 up to the end of the block rounded up to a multiple of 32; words outside the requested block
 * are shown as nine spaces. Nothing in the image calls this routine.
 */
void dbg_dump_memory_words(unsigned int addr, unsigned int count)
{
    unsigned int *first, *end, *word, *row, *last_row;
    int column;

    if (addr == 0)
        return;
    first = (unsigned int *)(addr & ~3);
    if (count == 0)
        count = DUMP_DEFAULT_WORDS;
    end = first + count;
    last_row = (unsigned int *)(((unsigned int)end + 31) & ~31);
    word = (unsigned int *)(addr & ~31);
    uart_put_string(s_000fef90);
    for (row = word; row < last_row; row += DUMP_LINE_WORDS) {
        uart_put_hex32((unsigned int)row);
        uart_put_string(" : ");
        for (column = 0; column < DUMP_LINE_WORDS; column++) {
            if (word < first || word >= end)
                uart_put_string("         ");
            else {
                uart_put_hex32(*word);
                uart_put_string(s_00198bb0);
            }
            word++;
        }
        uart_put_string(s_000fef90);
    }
    uart_put_string(s_000fef90);
}
