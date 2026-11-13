/* dbg_dump_memory_bytes  (CED_ALL_2)
 *
 * Print memory as lines of address, bytes and characters.
 * Name basis: proven - debug command; rows of 16 bytes through the serial output routines
 *
 * Matching notes
 * --------------
 * CED_ALL_2 (leon2s 0xa00b2324-0xa00b24b0, 396 bytes), flags -mcpu=v8 -Os -g.
 * Source form: one unsigned char variable (c) holds the shifted byte in both byte loops.
 */
extern char DAT_a006c660[], DAT_a006c678[], DAT_a006c680[], DAT_a006c690[], s_a0069ee8[];
extern void uart_put_string(const char *);
extern void uart_put_hex32(unsigned int);
extern void uart_put_hex8(unsigned char);
extern void uart_put_char(unsigned char);
extern unsigned int reg_read_word(unsigned int *);

/*
 * Print n words starting at addr as a hex dump with a character column.
 *   addr: start address; 0 prints nothing; rounded down to a multiple of 4
 *   n:    number of 32-bit words; 0 means 32
 * The output is a line break, then one line per 16-byte row from the row containing addr to the row containing
 * the last word, then a line break. A line is: the row address (hex), a separator, the four words as hex bytes
 * (low byte first, each followed by a blank), a second separator, and the 16 bytes as characters (0x20..0x7e as
 * they are, anything else as a replacement string). Words of a row that lie outside addr .. addr + 4 * n are
 * left blank in the hex part and count as 0 in the character part. Words are read with reg_read_word.
 */
void dbg_dump_memory_bytes(unsigned int addr, unsigned int n)
{
    unsigned int *start, *end, *p, *row, *last;
    unsigned int buf[4];                /* the four words of the current row, for the character column */
    unsigned int w;
    int j, k;
    unsigned char c;

    if (addr == 0)
        return;
    addr &= ~3;
    if (n == 0)
        n = 32;
    start = (unsigned int *)addr;
    end = start + n;
    last = (unsigned int *)(((unsigned int)end + 0xf) & ~0xf);     /* end of the last row */
    p = (unsigned int *)(addr & ~0xf);                              /* start of the first row */
    uart_put_string(s_a0069ee8);  /* "\n" */
    for (row = p; row < last; row += 4) {
        uart_put_hex32((unsigned int)row);
        uart_put_string(DAT_a006c660);  /* " : " */
        for (j = 0; j < 4; j++) {
            if (p < start || p >= end) {
                buf[j] = 0;
                uart_put_string("            ");     /* as wide as a word printed in hex */
            } else {
                w = buf[j] = reg_read_word(p);
                for (k = 0; k < 4; k++) {
                    c = w >> (k * 8);
                    uart_put_hex8(c);
                    uart_put_string(DAT_a006c690);  /* " " */
                }
            }
            p++;
        }
        uart_put_string(DAT_a006c678);  /* "| " */
        for (j = 0; j < 4; j++) {
            w = buf[j];
            for (k = 0; k < 4; k++) {
                c = w >> (k * 8);
                if ((unsigned char)(c - 0x20) < 0x5f)
                    uart_put_char(c);
                else
                    uart_put_string(DAT_a006c680);  /* "." for a byte that is not printable */
            }
        }
        uart_put_string(s_a0069ee8);  /* "\n" */
    }
    uart_put_string(s_a0069ee8);  /* "\n" */
}
