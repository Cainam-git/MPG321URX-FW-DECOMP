/* dbg_dump_memory_bytes  (FUN_a00dd250)
 *
 * Print memory as lines of address, bytes and characters.
 * Name basis: proven - through the serial port output routines; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd250 @ 0xa00dd250, flags -mcpu=v8 -O3 -g -msoft-float (the reserved floating-point registers
 * change the loop scheduling).
 * Source forms the exact build depends on:
 *  - the line's four words are kept in a local array buf[4];
 *  - the strings are named by their firmware addresses (s_...): " " (0x198bb0) and "\n" (0xfef90) are tails of
 *    other strings merged by the linker, and the order of the other strings is set by other functions of this
 *    file.
 */

extern void uart_put_string(const char *);
extern void uart_put_hex32(unsigned int val);
extern void uart_put_hex8(unsigned char);
extern void uart_put_char(signed char);
extern const char s_000fef90[];     /* "\n" */
extern const char s_00198b80[];     /* "." */
extern const char s_00198bb0[];     /* " " */

#define DUMP_DEFAULT_WORDS 32       /* words printed when the count is 0 */
#define DUMP_LINE_WORDS    4        /* one output line = 16 bytes = 4 words */

/*
 * Print a block of memory on the debug serial port as a hex dump.
 *
 *   addr   first byte; rounded down to a word. 0 prints nothing.
 *   words  number of words; 0 means 32.
 *
 * The dump starts with a line feed. Each line covers 16 bytes aligned to 16 and shows the line address, " : ", the
 * four words as bytes (each word from its lowest 8 bits to its highest), then "| " and the same bytes as
 * characters ('.' for anything outside 0x20..0x7e). Words of the line that lie outside the requested range are
 * left blank in the byte columns and count as 0 in the character columns. Nothing in the firmware calls it.
 */
void dbg_dump_memory_bytes(unsigned int addr, unsigned int words)
{
    unsigned int *start, *end, *p, *row, *last;
    unsigned int line[DUMP_LINE_WORDS];
    int i, j;

    if (addr == 0)
        return;
    start = (unsigned int *)(addr & ~3);
    if (words == 0)
        words = DUMP_DEFAULT_WORDS;
    end = start + words;
    last = (unsigned int *)(((unsigned int)end + 15) & ~15);    /* end rounded up to a whole line */
    p = (unsigned int *)(addr & ~15);                           /* start rounded down to a whole line */
    uart_put_string(s_000fef90);
    for (row = p; row < last; row += DUMP_LINE_WORDS) {
        uart_put_hex32((unsigned int)row);
        uart_put_string(" : ");
        for (i = 0; i < DUMP_LINE_WORDS; i++) {
            if (p < start || p >= end) {
                line[i] = 0;
                uart_put_string("            ");
            } else {
                unsigned int w = *p;
                line[i] = w;
                for (j = 0; j < 4; j++) {
                    uart_put_hex8(w >> (j * 8));
                    uart_put_string(s_00198bb0);
                }
            }
            p++;
        }
        uart_put_string("| ");
        for (i = 0; i < DUMP_LINE_WORDS; i++) {
            unsigned int w = line[i];
            for (j = 0; j < 4; j++) {
                unsigned char c = w >> (j * 8);
                if (c >= 0x20 && c <= 0x7e)
                    uart_put_char(c);
                else
                    uart_put_string(s_00198b80);
            }
        }
        uart_put_string(s_000fef90);
    }
    uart_put_string(s_000fef90);
}
