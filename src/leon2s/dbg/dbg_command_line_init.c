/* dbg_command_line_init  (FUN_a00b34a8)
 *
 * Reset the command line state and print the welcome banner.
 * Name basis: proven - prints 'Welcome to User's Command Line Debug'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b34a8 @ 0xa00b34a8, flags -mcpu=v8 -Os.
 * Source form: the five rows are cleared by a nested loop over a byte pointer; the banner is three calls of
 * uart_put_string.
 */
extern unsigned char dbg_hex_mode_flag;
extern unsigned int dbg_line_length;
extern unsigned char dbg_tool_mode_flag;
extern unsigned char dbg_tool_cb_flag;
extern unsigned char dbg_word_count;
extern int uart_put_string(const char *, ...);

#define LINE_WORD_ROWS    5             /* rows of the word store dbg_line_words */
#define LINE_WORD_BYTES   0x20          /* bytes per row */
#define DBG_LINE_WORDS_ADDRESS 0xa807dff0   /* address of dbg_line_words */

/*
 * Reset the state of the debug command line handler (hex mode, line length, tool mode, tool CB flag, word count
 * and the five word rows) and print the welcome banner on the serial port.
 */
void dbg_command_line_init(void)
{
    int row;
    int j;
    unsigned char *p;

    dbg_hex_mode_flag = 0;
    dbg_line_length = 0;
    dbg_tool_mode_flag = 0;
    dbg_tool_cb_flag = 0;
    dbg_word_count = 0;

    p = (unsigned char *)DBG_LINE_WORDS_ADDRESS;
    for (row = 0; row < LINE_WORD_ROWS; row++) {
        for (j = 0; j < LINE_WORD_BYTES; j++) {
            p[j] = 0;
        }
        p += LINE_WORD_BYTES;
    }

    uart_put_string("\n---------------------------------------------");
    uart_put_string("\n    Welcome to User's Command Line Debug");
    uart_put_string("\n---------------------------------------------\n");
}
