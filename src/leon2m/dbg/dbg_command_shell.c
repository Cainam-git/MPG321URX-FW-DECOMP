/* dbg_command_shell  (FUN_a00dcec4)
 *
 * Run the debug command line: read a line, find the command and carry it out.
 * Name basis: proven - prints the prompt 'MDBG >>'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dcec4 @ 0xA00DCEC4..0xA00DD250 (227 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on (no volatile, no asm):
 *  1. -msoft-float: with the FPU registers fixed, the loop optimiser's register threshold is small enough that
 *     the two error-text address halves stay inside the split loop (firmware 'bg,a; sethi %hi(0x198800)').
 *  2. split_line() is a static helper (inlined at -O3) taking the line, &dbg_shell_arg_count and the word
 *     array: the firmware keeps the full addresses of the count byte and of the word array in registers, as
 *     inlined pointer parameters do. dbg_strlen is called inside the helper.
 *  3. 'if (length == 0) return -1;' in the helper: the separate return value lets the jump bypass thread only
 *     that edge past the caller's 'if (split_result == 0)' (firmware 'be 0xA00DD0B4' straight to "MDBG >>"),
 *     while the loop-exit edges keep the test.
 *  4. The line terminator written 'length < 0x100 / length != 0 / else' (the firmware falls through to
 *     buffer[length - 1]).
 *  5. Store and increment as two statements ('buffer[length] = received; length++;') for the firmware's
 *     operand order.
 *  6. Lookup: the hit is handled inside the loop and leaves with 'found = 1; break;'; the not-found print is
 *     'if (!found)'. The loop is then big enough that the table address is made again in every round
 *     (offset + base, not one stepped pointer), as in the firmware.
 *  7. 'entry < count' with 'count = sizeof table / sizeof entry' (an int): a literal 'entry < 12' is folded to
 *     '<= 11' (cmp 0xb; ble); the variable keeps the firmware's 'cmp 0xc; bl'.
 *  8. The table's routine field is an integer address cast at the call: as a pointer, the pointer heuristic
 *     makes the call arm likely and the three argument values get other registers; as an integer they keep
 *     their first-use order (firmware l0/l2/l6).
 */

#define LINE_BUFFER_SIZE    0x100
#define LINE_MAX_TYPED      0xfe        /* characters kept; more are dropped without echo */
#define MAX_WORDS           5           /* command word and up to four numbers */
#define WORD_SIZE           0x20        /* 31 characters and the terminating 0 */
#define KEY_ESCAPE          0x1b

/* One entry of dbg_command_table (12 entries in ROM: mem, wmem, mdw, mww, ReadStackApi, dump, ldc, help, AT,
   DDRStress, ATTIMING and one with an empty name). */
struct dbg_cmd
{
  char name[0x20];
  unsigned int fn;              /* routine address, 0 = no routine */
};
extern int dbg_shell_line_length;
extern unsigned char dbg_shell_arg_count;
extern unsigned char dbg_shell_caret_flag;              /* set to 1 when '^' is typed as the first character */
extern char dbg_shell_line_buffer[LINE_BUFFER_SIZE];
extern char dbg_shell_args[MAX_WORDS][WORD_SIZE];
extern struct dbg_cmd dbg_command_table[12];
extern char s_00198b28[];                       /* "\b \b": erase the last character on the terminal */
extern int uart_rx_buffer_get(char *);
extern void uart_put_string(const char *);
extern void uart_put_char(int);
extern int dbg_strlen(const char *);
extern int dbg_strcmp(const char *, const char *);
extern int dbg_parse_number(const char *);
extern int dbg_printf(const char *, ...);

/*
 * Split the line into words at ' ', ',', '\t' and 0, counting them in *word_count.
 * Returns 0 when there are words to use, -1 for an empty line or a line without a word. A separator after
 * the fifth word, or a word longer than 31 characters, prints an overflow message and ends the split; the
 * words found up to then are used (return 0). A separator at the end of the line counts one word more.
 */
static int split_line(char *line, unsigned char *word_count, char (*words)[WORD_SIZE])
{
  int i, word_length, result, length;

  length = dbg_strlen(line);
  if (length == 0)
    return -1;
  result = -1;
  word_length = 0;
  for (i = 0; i < length; i++)
    {
      unsigned char ch = line[i];
      switch (ch)
        {
        case ' ':
        case ',':
        case 0:
        case '\t':
          /* A separator ends the current word, if there is one. */
          if (word_length != 0)
            {
              (*word_count)++;
              word_length = 0;
              if (*word_count > MAX_WORDS - 1)
                {
                  result = 1;
                  i = length;
                  dbg_printf("Argc is overflow\r\n");
                }
            }
          break;
        default:
          if (word_length + 1 > WORD_SIZE - 1)
            {
              result = 1;
              i = length;
              dbg_printf("Argv is overflow\r\n");
            }
          else
            {
              words[*word_count][word_length] = ch;
              word_length++;
              result = 0;
            }
          break;
        }
    }
  /* Count the last word; an overflow still uses the words found so far. */
  if (result == 0)
    (*word_count)++;
  else if (result == 1)
    result = 0;
  return result;
}

/*
 * The "MDBG >>" command line of the debug serial port. Polled once per pass of the main loop (startup_main).
 *
 * Phases of one call:
 *   1. Take at most one received character; return at once when there is none, so it never waits.
 *   2. Line editing: backspace erases one character, ESC drops the line and prints "DBG >>", '^' as the first
 *      character only sets dbg_shell_caret_flag, any other character is stored and echoed while the line has room.
 *      Every character but CR ends the call here.
 *   3. CR: end the line with 0 and split it into words.
 *   4. Look the first word up in dbg_command_table. When it is found and has a routine, call the routine with
 *      words 1..4 read as numbers (hexadecimal with 0x, else decimal), then print the word and " OK.";
 *      otherwise print "Command Not Found!". Clear the words.
 *   5. Print the prompt "MDBG >>" and start a new line.
 *
 * Every loop is bounded: the line (at most 0xFE characters), the 12 table entries, the 5 x 32 clear.
 */
void dbg_command_shell(void)
{
  char received;
  unsigned char line_done;
  int split_result, entry, word, pos, found, count;
  char (*words)[WORD_SIZE];

  /* 1. */
  if (uart_rx_buffer_get(&received) == 0)
    return;
  /* 2. Line editing. */
  line_done = 0;
  switch (received)
    {
    case '\r':
      line_done = 1;
      break;
    case '\b':
      if (dbg_shell_line_length > 0)
        {
          dbg_shell_line_length--;
          uart_put_string(s_00198b28);
        }
      break;
    case KEY_ESCAPE:
      dbg_shell_line_length = 0;
      uart_put_string("\n\rDBG >>");
      break;
    default:
      if (dbg_shell_line_length == 0 && received == '^')
        {
          dbg_shell_caret_flag = 1;
          dbg_shell_line_length = 0;
        }
      else if (dbg_shell_line_length < LINE_MAX_TYPED)
        {
          dbg_shell_line_buffer[dbg_shell_line_length] = received;
          dbg_shell_line_length++;
          uart_put_char(received);
        }
      break;
    }
  if (!line_done)
    return;
  /* 3. End the line and split it. */
  uart_put_string("\n\r");
  if (dbg_shell_line_length < LINE_BUFFER_SIZE)
    dbg_shell_line_buffer[dbg_shell_line_length] = 0;
  else if (dbg_shell_line_length != 0)
    dbg_shell_line_buffer[dbg_shell_line_length - 1] = 0;
  else
    dbg_shell_line_buffer[0] = 0;
  split_result = split_line(dbg_shell_line_buffer, &dbg_shell_arg_count, dbg_shell_args);
  if (split_result == 0)
    {
      /* 4. Find the command and run it. */
      words = dbg_shell_args;
      found = 0;
      count = sizeof(dbg_command_table) / sizeof(dbg_command_table[0]);
      for (entry = 0; entry < count; entry++)
        if (dbg_strcmp(dbg_command_table[entry].name, words[0]) == 0)
          {
            unsigned int routine;

            uart_put_string("\n\r");
            routine = dbg_command_table[entry].fn;
            if (routine)
              {
                /* Words not typed are empty: all five are cleared after every command. */
                int arg1 = dbg_parse_number(words[1]);
                int arg2 = dbg_parse_number(words[2]);
                int arg3 = dbg_parse_number(words[3]);
                int arg4 = dbg_parse_number(words[4]);
                ((void (*) (int, int, int, int)) routine) (arg1, arg2, arg3, arg4);
                uart_put_string("\n\r");
                uart_put_string(words[0]);
                uart_put_string(" OK.\n\r");
              }
            else
              uart_put_string("\n\rCommand Not Found!\n\r");
            found = 1;
            break;
          }
      if (!found)
        uart_put_string("\n\rCommand Not Found!\n\r");
      for (word = 0; word <= MAX_WORDS - 1; word++)
        for (pos = 0; pos <= WORD_SIZE - 1; pos++)
          dbg_shell_args[word][pos] = 0;
      dbg_shell_arg_count = 0;
    }
  /* 5. */
  uart_put_string("MDBG >>");
  dbg_shell_line_length = 0;
}
