/* dbg_handle_input_line  (FUN_a00b28d0)
 *
 * Handle a line typed on the debug serial port: memory read and write lines and named commands.
 * Name basis: proven - hex word read / write, word split and the command table
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b28d0 @ 0xa00b28d0-0xa00b34a8 (3032 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * Source forms the exact build depends on:
 *  - the '\r' handler of hex mode parses only inside 'if (dbg_line_length >= 2)' and shares the clear-and-return
 *    tail with a short line;
 *  - the word split stores through 'char (*rows)[32]' as rows[*word_count][j]; the clearing loop addresses the
 *    rows through the constant DBG_LINE_WORDS_ADDRESS, not through dbg_line_words;
 *  - found is set to 0 before the 'if (split_state == SPLIT_OK)' test (0xa00b2f74);
 *  - the table loop runs to command_count = sizeof table / sizeof entry, kept in a local (cmp 8; bl at
 *    0xa00b302c);
 *  - the closing prints of a command that ran are written after the table loop as
 *    'if (found) { .. } else uart_put_string("\n\rCommand Not Found!\n\r");': the firmware forms the "\n\r"
 *    address again for that print (0xa00b300c) and both paths end in the one print call at 0xa00b3040;
 *  - the tool-mode quit request is kept as bit ST_QUIT of the local status word (tested at 0xa00b348c).
 */

/* Characters with a meaning of their own. */
#define KEY_HEX_LINE_CANCEL  0x1c       /* hex mode: drops the line typed so far ('^' does the same) */
#define KEY_ESCAPE           0x1b       /* command mode: drops the line and prints a new prompt */

#define LINE_MAX_CHARS       0xfe       /* characters kept in dbg_line_buffer; more are dropped */
#define HEX_MAX_BYTES        0x20       /* byte pairs kept in dbg_hex_bytes */
#define WORD_MAX_CHARS       0x1f       /* characters of one word in dbg_line_words */
#define DBG_LINE_WORDS_ADDRESS 0xa807dff0   /* address of dbg_line_words: five rows of 32 bytes */

/* Reply bytes of hex mode (sent as they are, not as text). */
#define HEX_REPLY_DONE       0x83       /* first byte: the command was carried out */
#define HEX_REPLY_FAILED     0x82       /* first byte: unknown command, wrong byte count or bad digit */
#define HEX_REPLY_DIGIT      0x90       /* a read word goes out as eight bytes 0x90 + nibble, high nibble first */
#define HEX_REPLY_END        0x8f       /* last byte of every reply */

/* Result of splitting a command line into words. */
#define SPLIT_NO_WORD        (-1)       /* the line holds only separators */
#define SPLIT_OK             0
#define SPLIT_OVERFLOW       1          /* a sixth word or a word above 31 characters; the rest is dropped */

/* Tool-mode commands, as stored in dbg_tool_request.command. */
#define TOOL_CMD_NONE        0          /* check digit wrong: nothing is done */
#define TOOL_CMD_READ_WORD   1          /* "*RD" */
#define TOOL_CMD_WRITE_WORD  2          /* "*WD" */
#define TOOL_CMD_RB          3          /* "*RB": stored, no action follows */
#define TOOL_CMD_WB          4          /* "*WB": stored, no action follows */
#define TOOL_CMD_SET_BASE    5          /* "*CB" */
#define TOOL_CMD_QUIT        0xffff     /* "*qt" */

#define ST_QUIT 0x01

/* One row of the command table: the name typed as word 0 and the function it runs. */
struct dbg_command {
    char name[32];
    void (*handler)(int, int, int, int);
};

/* A decoded tool-mode line. */
struct tool_request {
    unsigned int command;               /* TOOL_CMD_* */
    unsigned int address;               /* the four hex digits after the command letters */
    unsigned int value;                 /* "*WD": the eight hex digits after the address */
    char check_digit;                   /* "*WD": the character after the value */
};

/* The command table (8 rows): mem, wmem, mdw, mww, hrx21, maild, rt and a last row with no name and no
   function. */
extern struct dbg_command dbg_command_table[8];
extern struct tool_request dbg_tool_request;
extern unsigned char dbg_hex_mode_flag;
extern unsigned char dbg_tool_mode_flag;
extern int dbg_line_length;
extern unsigned char dbg_word_count;
extern unsigned int dbg_tool_address_base;
extern unsigned char dbg_hex_bytes[];
extern char dbg_line_buffer[];
extern unsigned char dbg_tool_reply_buffer[];
extern unsigned char dbg_tool_cb_flag;
extern const char s_a006c6b8[];         /* "\b \b": erases the last character on the terminal */

extern int uart_read_rx_byte(unsigned char *);
extern void uart_put_string(const char *);
extern void uart_put_char(unsigned char);
extern int dbg_strlen(char *);
extern int dbg_strcmp(const char *, const char *);
extern int dbg_parse_number(char *);
extern int dbg_parse_hex_digits(const unsigned char *, int);
extern int dbg_format_hex32(unsigned char *, unsigned int);
extern int dbg_line_checksum_digit(unsigned int, unsigned int);
extern unsigned int reg_read_word(unsigned int *);
extern void reg_write_word(unsigned int *, unsigned int);

extern char dbg_line_words[5][32];

/*
 * Take one character from the debug serial port and act on it. Called once per pass of the input
 * program's main loop (sys_main_part6); returns at once when no character has arrived.
 *
 * The line typed so far is kept in dbg_line_buffer, its length in dbg_line_length. A line is read in one of
 * three ways:
 *
 * 1. Hex mode (dbg_hex_mode_flag, entered by '^' as the first character of a line). Characters are stored
 *    without echo. On '\r' the first character is the command and the rest is read as hex byte pairs, with ' '
 *    or ',' allowed between pairs, at most 32 bytes. The first four bytes are a big-endian address.
 *      R aaaaaaaa                    read the word at the address; reply 0x83, eight digit bytes, 0x8f
 *      W aaaaaaaa vvvvvvvv           write the word; reply 0x83 0x8f
 *      U aaaaaaaa vvvvvvvv mmmmmmmm  write the bits of mask m from v, keep the others; reply 0x83 0x8f
 *    Lower case letters work the same. Anything else, a wrong byte count or a bad digit replies 0x82 0x8f.
 *    Hex mode ends with every '\r'.
 *
 * 2. Command mode (the normal case). Characters are echoed; backspace and escape edit the line. On '\r' the
 *    line is split into at most five words; word 0 is looked up in the command table dbg_command_table and its
 *    function is called with words 1 to 4 converted by dbg_parse_number. A line "*CB00000" or "{#UTIL#}"
 *    switches to tool mode instead.
 *
 * 3. Tool mode (dbg_tool_mode_flag). Each line is a command of three characters, four hex digits of address
 *    and a check digit (dbg_line_checksum_digit: '0' + the low four bits of the sum of the bytes of address and
 *    value):
 *      *RDaaaac           read the word at dbg_tool_address_base + address; reply "#", the word in eight hex
 *                         digits, its check digit, " OK!#\n"
 *      *WDaaaavvvvvvvvc   write value v there; reply "#OK!#\n"
 *      *CBaaaac           set dbg_tool_address_base to address << 16; reply "#", the four address digits,
 *                         " OK!#\n"
 *      *qt                back to command mode
 *    A wrong check digit gets no reply. "*RB" and "*WB" are decoded but nothing is done for them. The entry
 *    line "*CB00000" has the same form: *CB, address 0000 and its check digit '0'.
 *
 * uart_put_string sends a carriage return after each line feed.
 */
void dbg_handle_input_line(void)
{
    char c;

    if (uart_read_rx_byte((unsigned char *)&c) == 0)
        return;

    if (dbg_hex_mode_flag != 0) {
        /* ---- Hex mode ---- */
        unsigned char command, have_high_digit, high_digit, digit, length, done;
        unsigned int i, byte_count, address, value, mask;
        int shift;

        switch (c) {
        case KEY_HEX_LINE_CANCEL:
        case '^':
            dbg_line_length = 0;
            return;
        case '\r':
            if (dbg_line_length >= 2) {
            /* Phase 1: read the hex byte pairs after the command letter. */
            length = dbg_line_length;
            command = dbg_line_buffer[0];
            have_high_digit = 0;
            high_digit = 0;
            byte_count = 0;
            for (i = 1; i < length; i++) {
                digit = dbg_line_buffer[i];
                if (digit >= 'a' && digit <= 'f')
                    digit = digit - 'a' + 10;
                else if (digit >= 'A' && digit <= 'F')
                    digit = digit - 'A' + 10;
                else if (digit >= '0' && digit <= '9')
                    digit = digit - '0';
                else if (digit == ' ' || digit == ',') {
                    /* A separator is allowed only between pairs. */
                    if (have_high_digit) {
                        command = 0xff;
                        break;
                    }
                    high_digit = 0;
                    continue;
                } else {
                    command = 0xff;
                    break;
                }
                if (!have_high_digit) {
                    high_digit = digit;
                    have_high_digit = 1;
                } else {
                    have_high_digit = 0;
                    if (byte_count <= HEX_MAX_BYTES - 1) {
                        dbg_hex_bytes[byte_count++] = (high_digit << 4) + digit;
                        continue;
                    }
                    command = 0xff;
                    break;
                }
            }
            /* A single digit left over at the end. */
            if (byte_count < HEX_MAX_BYTES && have_high_digit)
                command = 0xff;

            /* Phase 2: the address, from the first four bytes. */
            address = 0;
            value = 0;
            mask = 0;
            switch (command) {
            case 'R':
            case 'W':
            case 'U':
            case 'r':
            case 'w':
            case 'u':
                for (i = 0; i < 4; i++)
                    address = (address << 8) + dbg_hex_bytes[i];
                break;
            }

            /* Phase 3: carry out the command; the reply is built in dbg_hex_bytes. */
            done = 0;
            switch (command) {
            case 'R':
            case 'r':
                if (byte_count != 4)
                    break;
                value = reg_read_word((unsigned int *)address);
                dbg_hex_bytes[0] = HEX_REPLY_DONE;
                for (i = 1, shift = 0x1c; i < 9; i++, shift -= 4)
                    dbg_hex_bytes[i] = ((value >> shift) & 0xf) + HEX_REPLY_DIGIT;
                dbg_hex_bytes[9] = HEX_REPLY_END;
                dbg_hex_bytes[10] = 0;
                uart_put_string((const char *)dbg_hex_bytes);
                done = 1;
                break;
            case 'U':
            case 'u':
                if (byte_count != 12)
                    break;
                for (i = 4; i < 8; i++)
                    value = (value << 8) + dbg_hex_bytes[i];
                for (i = 8; i < 12; i++)
                    mask = (mask << 8) + dbg_hex_bytes[i];
                value &= mask;
                reg_write_word((unsigned int *)address, (reg_read_word((unsigned int *)address) & ~mask) | value);
                dbg_hex_bytes[0] = HEX_REPLY_DONE;
                dbg_hex_bytes[1] = HEX_REPLY_END;
                dbg_hex_bytes[2] = 0;
                uart_put_string((const char *)dbg_hex_bytes);
                done = 1;
                break;
            case 'W':
            case 'w':
                if (byte_count != 8)
                    break;
                for (i = 4; i < 8; i++)
                    value = (value << 8) + dbg_hex_bytes[i];
                reg_write_word((unsigned int *)address, value);
                dbg_hex_bytes[0] = HEX_REPLY_DONE;
                dbg_hex_bytes[1] = HEX_REPLY_END;
                dbg_hex_bytes[2] = 0;
                uart_put_string((const char *)dbg_hex_bytes);
                done = 1;
                break;
            }
            if (!done) {
                dbg_hex_bytes[0] = HEX_REPLY_FAILED;
                dbg_hex_bytes[1] = HEX_REPLY_END;
                dbg_hex_bytes[2] = 0;
                uart_put_string((const char *)dbg_hex_bytes);
            }
            }
            /* Every '\r' ends hex mode. */
            dbg_line_length = 0;
            dbg_hex_mode_flag = 0;
            return;
        default:
            if (dbg_line_length < LINE_MAX_CHARS) {
                dbg_line_buffer[dbg_line_length] = c;
                dbg_line_length++;
            }
            return;
        }
    } else {
        /* ---- Line editing in command and tool mode ---- */
        unsigned char line_done = 0;

        switch (c) {
        case '\b':
            if (dbg_line_length > 0) {
                dbg_line_length--;
                uart_put_string(s_a006c6b8);
            }
            break;
        case '\r':
            line_done = 1;
            break;
        case KEY_ESCAPE:
            dbg_line_length = 0;
            uart_put_string("\n\rDBG >>");
            break;
        default:
            if (dbg_line_length == 0 && c == '^') {
                dbg_hex_mode_flag = 1;
                dbg_line_length = 0;
            } else if (dbg_line_length < LINE_MAX_CHARS) {
                dbg_line_buffer[dbg_line_length] = c;
                dbg_line_length++;
                uart_put_char(c);
            }
            break;
        }
        if (!line_done)
            return;

        /* The line is complete: terminate it. */
        uart_put_string("\n\r");
        if (dbg_line_length < 0x100)
            dbg_line_buffer[dbg_line_length] = 0;
        else if (dbg_line_length != 0)
            dbg_line_buffer[dbg_line_length - 1] = 0;
        else
            dbg_line_buffer[0] = 0;

        if (dbg_tool_mode_flag == 0) {
            /* ---- Command mode ---- */
            int length, i, j, split_state, k, found, command_count;
            char (*words)[32];
            unsigned char *row;
            unsigned char *word_count;
            char (*rows)[32];
            unsigned char *line;
            void (*handler)(int, int, int, int);

            /* The two lines that enter tool mode; other lines starting with '*' or '{' are dropped. Neither
               prints a prompt. */
            if ((unsigned char)dbg_line_buffer[0] == '*') {
                if (dbg_strcmp("*CB00000", dbg_line_buffer) == 0)
                    dbg_tool_mode_flag = 1;
            } else if ((unsigned char)dbg_line_buffer[0] == '{') {
                if (dbg_strcmp("{#UTIL#}", dbg_line_buffer) == 0)
                    dbg_tool_mode_flag = 1;
            } else {
            /* Phase 1: split the line at ' ', '\t' and ',' into the rows of dbg_line_words. */
            line = (unsigned char *)dbg_line_buffer;
            length = dbg_strlen((char *)line);
            word_count = &dbg_word_count;
            rows = dbg_line_words;
            if (length != 0) {
                split_state = SPLIT_NO_WORD;
                j = 0;
                for (i = 0; i < length; i++) {
                    unsigned char ch = line[i];

                    switch (ch) {
                    case ' ':
                    case 0:
                    case '\t':
                    case ',':
                        if (j != 0) {
                            (*word_count)++;
                            j = 0;
                            if (*word_count > 4) {
                                split_state = SPLIT_OVERFLOW;
                                i = length;
                            }
                        }
                        break;
                    default:
                        if (j + 1 > WORD_MAX_CHARS) {
                            split_state = SPLIT_OVERFLOW;
                            i = length;
                        } else {
                            rows[*word_count][j] = ch;
                            j++;
                            split_state = SPLIT_OK;
                        }
                        break;
                    }
                }
                if (split_state == SPLIT_OK)
                    (*word_count)++;
                /* An overflow is not an error: the words split so far are used. */
                if (split_state == SPLIT_OVERFLOW) {
                    split_state = SPLIT_OK;
                }

                /* Phase 2: look word 0 up in the command table and run its function. */
                found = 0;
                if (split_state == SPLIT_OK) {
                    words = dbg_line_words;
                    command_count = sizeof(dbg_command_table) / sizeof(dbg_command_table[0]);
                    for (k = 0; k < command_count; k++) {
                        if (dbg_strcmp(dbg_command_table[k].name, words[0]) == 0) {
                            uart_put_string("\n\r");
                            handler = dbg_command_table[k].handler;
                            if (handler != 0) {
                                /* Missing words are empty rows. */
                                handler(dbg_parse_number(words[1]), dbg_parse_number(words[2]),
                                        dbg_parse_number(words[3]), dbg_parse_number(words[4]));
                                found = 1;
                            }
                            break;
                        }
                    }
                    if (found) {
                        uart_put_string("\n\r");
                        uart_put_string(words[0]);
                        uart_put_string(" OK.\n\r");
                    } else
                        uart_put_string("\n\rCommand Not Found!\n\r");

                    /* Phase 3: clear the rows for the next line. */
                    row = (unsigned char *)DBG_LINE_WORDS_ADDRESS;
                    {
                        int row_index, column;

                        for (row_index = 0; row_index < 5; row_index++) {
                            for (column = 0; column < 0x20; column++)
                                row[column] = 0;
                            row += 0x20;
                        }
                    }
                    dbg_word_count = 0;
                }
            }
            uart_put_string("DBG >>");
            }
        } else if (dbg_line_length > 2) {
            /* ---- Tool mode ---- */
            unsigned int address;
            unsigned int value;
            char *line;
            unsigned int status;

            /* Phase 1: decode the line into dbg_tool_request. The address digits are read for every line. */
            line = dbg_line_buffer;
            address = dbg_parse_hex_digits((unsigned char *)line + 3, 4);
            if (line[0] == '*' && line[1] == 'q' && line[2] == 't')
                dbg_tool_request.command = TOOL_CMD_QUIT;
            else if (line[0] == '*' && line[1] == 'R' && line[2] == 'D') {
                if ((dbg_line_checksum_digit(address, 0) & 0xff) == line[7]) {
                    dbg_tool_request.address = address;
                    dbg_tool_request.command = TOOL_CMD_READ_WORD;
                } else
                    dbg_tool_request.command = TOOL_CMD_NONE;
            } else if (line[0] == '*' && line[1] == 'W' && line[2] == 'D') {
                /* The check digit is tested when the command is carried out. */
                value = dbg_parse_hex_digits((unsigned char *)line + 7, 8);
                dbg_tool_request.address = address;
                dbg_tool_request.value = value;
                dbg_tool_request.check_digit = line[15];
                dbg_tool_request.command = TOOL_CMD_WRITE_WORD;
            } else if (line[0] == '*' && line[1] == 'R' && line[2] == 'B')
                dbg_tool_request.command = TOOL_CMD_RB;
            else if (line[0] == '*' && line[1] == 'W' && line[2] == 'B')
                dbg_tool_request.command = TOOL_CMD_WB;
            else if (line[0] == '*' && line[1] == 'C' && line[2] == 'B') {
                if ((dbg_line_checksum_digit(address, 0) & 0xff) != line[7])
                    dbg_tool_request.command = TOOL_CMD_NONE;
                else {
                    dbg_tool_request.command = TOOL_CMD_SET_BASE;
                    dbg_tool_request.address = address;
                    /* Only written here and cleared by dbg_command_line_init; no routine of this program
                       reads it. */
                    if (address == 0x1000)
                        dbg_tool_cb_flag = 1;
                    else
                        dbg_tool_cb_flag = 0;
                }
            } else
                goto out;

            /* Phase 2: carry out the command; replies are built in dbg_tool_reply_buffer. */
            status = 0;
            switch (dbg_tool_request.command) {
            case TOOL_CMD_QUIT:
                status |= ST_QUIT;
                break;
            case TOOL_CMD_READ_WORD: {
                unsigned int word = reg_read_word((unsigned int *)(dbg_tool_address_base + (dbg_tool_request.address & ~3)));
                int check = dbg_line_checksum_digit(word, 0);

                /* "#", eight hex digits, check digit, " OK!#\n" */
                dbg_format_hex32(&dbg_tool_reply_buffer[1], word);
                dbg_tool_reply_buffer[0] = '#';
                dbg_tool_reply_buffer[9] = check;
                dbg_tool_reply_buffer[10] = ' ';
                dbg_tool_reply_buffer[11] = 'O';
                dbg_tool_reply_buffer[12] = 'K';
                dbg_tool_reply_buffer[13] = '!';
                dbg_tool_reply_buffer[14] = '#';
                dbg_tool_reply_buffer[15] = '\n';
                dbg_tool_reply_buffer[16] = 0;
                uart_put_string((const char *)dbg_tool_reply_buffer);
                break;
            }
            case TOOL_CMD_WRITE_WORD:
                /* The check digit covers address and value. */
                if ((dbg_line_checksum_digit(dbg_tool_request.address, dbg_tool_request.value) & 0xff) != dbg_tool_request.check_digit)
                    break;
                reg_write_word((unsigned int *)(dbg_tool_address_base + (dbg_tool_request.address & ~3)), dbg_tool_request.value);
                dbg_tool_reply_buffer[0] = '#';
                dbg_tool_reply_buffer[1] = 'O';
                dbg_tool_reply_buffer[2] = 'K';
                dbg_tool_reply_buffer[3] = '!';
                dbg_tool_reply_buffer[4] = '#';
                dbg_tool_reply_buffer[5] = '\n';
                dbg_tool_reply_buffer[6] = 0;
                uart_put_string((const char *)dbg_tool_reply_buffer);
                break;
            case TOOL_CMD_SET_BASE:
                dbg_tool_address_base = dbg_tool_request.address << 16;
                /* The eight digits go to bytes 0x10..0x17; the reply takes the last four. */
                dbg_format_hex32(&dbg_tool_reply_buffer[0x10], dbg_tool_request.address);
                dbg_tool_reply_buffer[0] = '#';
                dbg_tool_reply_buffer[1] = dbg_tool_reply_buffer[0x14];
                dbg_tool_reply_buffer[2] = dbg_tool_reply_buffer[0x15];
                dbg_tool_reply_buffer[3] = dbg_tool_reply_buffer[0x16];
                dbg_tool_reply_buffer[4] = dbg_tool_reply_buffer[0x17];
                dbg_tool_reply_buffer[5] = ' ';
                dbg_tool_reply_buffer[6] = 'O';
                dbg_tool_reply_buffer[7] = 'K';
                dbg_tool_reply_buffer[8] = '!';
                dbg_tool_reply_buffer[9] = '#';
                dbg_tool_reply_buffer[10] = '\n';
                dbg_tool_reply_buffer[11] = 0;
                uart_put_string((const char *)dbg_tool_reply_buffer);
                break;
            }
            if (status & ST_QUIT)
                dbg_tool_mode_flag = 0;
        }
    }
out:
    dbg_line_length = 0;
}
