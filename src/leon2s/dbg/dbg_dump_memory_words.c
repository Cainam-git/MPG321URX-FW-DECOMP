/* dbg_dump_memory_words  (CED_ALL_3)
 *
 * Print memory as lines of four words.
 * Name basis: proven - debug command; 32 words by default
 *
 * Matching notes
 * --------------
 * CED_ALL_3 (leon2s 0xa00b24b0-0xa00b258c, 220 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: addr is masked in place before the n test; the row limit is computed before the loop; each word
 * case makes its own calls.
 */
extern char DAT_a006c660[], DAT_a006c688[], DAT_a006c690[], s_a0069ee8[];
extern void uart_put_string(const char *);
extern void uart_put_hex32(unsigned int);
extern unsigned int reg_read_word(unsigned int *);

/*
 * Debug console command: print memory words, four to a line.
 *
 *   addr: address of the first word; rounded down to a multiple of 4. 0 prints nothing.
 *   n:    number of words to print; 0 stands for 32.
 *
 * Each line starts with the address of its first slot (lines begin at a multiple of 32 bytes, so the first and
 * the last line can start before addr or reach past the end), then " : ", then four slots. A slot inside the
 * range shows the word (read through reg_read_word) followed by one space; a slot outside the range shows nine
 * spaces.
 */
void dbg_dump_memory_words(unsigned int addr, unsigned int n)
{
    unsigned int *start, *end, *word, *line, *last_line_end;
    int slot;

    if (addr == 0)
        return;
    addr &= ~3;
    if (n == 0)
        n = 32;
    start = (unsigned int *)addr;
    end = start + n;
    /* The end of the range, rounded up to a multiple of 32 bytes. */
    last_line_end = (unsigned int *)(((unsigned int)end + 0x1f) & ~0x1f);
    word = (unsigned int *)(addr & ~0x1f);
    uart_put_string(s_a0069ee8);  /* "\n" */
    for (line = word; line < last_line_end; line += 4) {
        uart_put_hex32((unsigned int)line);
        uart_put_string(DAT_a006c660);  /* " : " */
        for (slot = 0; slot < 4; slot++) {
            if (word < start || word >= end) {
                uart_put_string(DAT_a006c688);  /* nine spaces */
            } else {
                uart_put_hex32(reg_read_word(word));
                uart_put_string(DAT_a006c690);  /* " " */
            }
            word++;
        }
        uart_put_string(s_a0069ee8);  /* "\n" */
    }
    uart_put_string(s_a0069ee8);  /* "\n" */
}
