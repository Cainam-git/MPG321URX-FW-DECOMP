/* leon2m FUN_a00dcec4 @ 0xA00DCEC4..0xA00DD250 (227 words): the Big chip's command shell "MDBG >>".
 * -mcpu=v8 -O3 -g -msoft-float.
 * Hand-written.
 *
 * Code:
 *  - Each call reads at most ONE character with FUN_a00deea4(&c) (ring buffer 0xa802b0ec); 0 = nothing received ->
 *    return at once. It never waits.
 *  - Line editor on the buffer 0xA802D498 (0x100 bytes), length int 0xA802D490: backspace (8) removes one char and
 *    echoes "\b \b" (ROM 0x198B28); ESC (0x1B) clears the line and prints "\n\rDBG >>" (0x198B48); '^' as the first
 *    char only sets byte 0xA802D495 = 1; any other char is stored and echoed (FUN_a00deef0) while length < 0xFE.
 *  - Only CR (0x0D) goes on: prints "\n\r" (0x198F48), terminates the line, then split(): FUN_a00dd83c (string
 *    length) and the split of the line at ' ', ',', '\t' or NUL into at most 5 words of at most 31 chars
 *    (0xA802D598, 5 x 0x20 bytes, count byte 0xA802D494; "Argc is overflow" 0x198B30 / "Argv is overflow" 0x198AF0).
 *  - The first word is looked up in the 12-entry ROM command table 0x198C90 (0x24 bytes per entry: 32-byte name,
 *    then the function address; mem, wmem, mdw, mww, ReadStackApi, dump, ldc, help, AT, DDRStress, ATTIMING, empty)
 *    with FUN_a00dd868 (string compare). Found and the address is not 0: the function is called with
 *    FUN_a00dcd38 (number parse) of words 1..4, then "\n\r", the command word and " OK." (0x198B58) are printed.
 *    Address 0 or no match: "Command Not Found!" (0x198B10). Then the 5 words are cleared, count = 0.
 *  - Always at the end: prints "MDBG >>" (0x198B08) and length = 0.
 *  Where: polled once per pass of main FUN_a00295a4's main loop (direct-call graph).
 *  Its own code has no wait: one character per call, every loop is bounded (line <= 0xFE chars, 12 table entries,
 *  5 x 32 clear). Its only input is that ring buffer.
 *
 * Source-shape levers (no aids, no volatile, no asm):
 *  1. -msoft-float: loop.c's threshold is (1 + number of non-fixed hard regs); with the FPU regs fixed it is small
 *     enough that the two error-string HIGHs stay inside the split loop (fw 'bg,a; sethi %hi(0x198800)').
 *  2. split() is a static helper (inlined at -O3) taking the line, &count and the word array: the fw keeps the
 *     FULL addresses of the count byte (ldub [%l4]) and of the word array in registers = inlined pointer params.
 *     strlen is inside the helper ('or %o0,0x98,%l5' before the call = the line param).
 *  3. 'if (len == 0) return -1;' in the helper: the return value is a separate set, so gcse's jump bypass threads
 *     ONLY the len == 0 edge past the caller's 'if (err == 0)' (fw 'be 0xA00DD0B4' straight to "MDBG >>"), while the
 *     loop-exit edges keep the test (fw dd020). No 'n = 0;' statement before the test is needed.
 *  4. Line terminator written 'len < 0x100 / len != 0 / else' (fw falls through to buf[len - 1]).
 *  5. Store then increment as two statements: 'buf[len] = c; len++;' gives the fw operand order [%l3 + %o4].
 *  6. Lookup: the hit is handled INSIDE the loop and leaves with 'found = 1; break;', the not-found print is
 *     'if (!found)' (bypass removes that test). The hit code is then inside the loop for loop.c, the loop is big
 *     enough that the table base lo_sum is 'not desirable' to move (fw re-makes it every round: 'or %l3,0x90,%i5'
 *     in the bl delay slot; offset + base, not one stepped pointer).
 *  7. 'n < num' with 'num = sizeof table / sizeof entry' (an int): a literal 'n < 12' is folded by fold-const to
 *     'n <= 11' (cmp 0xb; ble), the variable keeps 'cmp 0xc; bl' as in the fw.
 *  8. The table's function field is an integer address (unsigned int) cast at the call: with a pointer type
 *     PRED_POINTER makes the call arm likely; as an integer the arm is colder, the three argument values then tie
 *     in local-alloc's priority and keep their first-use order (l0/l1/l2 before regrename -> fw l0/l2/l6).
 *     (__builtin_expect (fn != 0, 0) on a pointer gives the same bytes; the integer field needs no aid.)
 */
struct dbg_cmd
{
  char name[0x20];
  unsigned int fn;              /* function address, 0 = no function */
};
extern int DAT_a802d490;                /* line length */
extern unsigned char DAT_a802d494;      /* word count */
extern unsigned char DAT_a802d495;      /* '^' seen as first char */
extern char DAT_a802d498[0x100];        /* line buffer */
extern char DAT_a802d598[5][0x20];      /* words */
extern struct dbg_cmd DAT_00198c90[12]; /* ROM command table */
extern char s_00198f48[], s_00198b08[], s_00198b10[], s_00198b28[], s_00198b30[], s_00198af0[], s_00198b48[],
  s_00198b58[];
extern int FUN_a00deea4(char *);
extern void FUN_a00def40(const char *);
extern void FUN_a00deef0(int);
extern int FUN_a00dd83c(const char *);
extern int FUN_a00dd868(const char *, const char *);
extern int FUN_a00dcd38(const char *);
extern int FUN_a00df170(const char *, ...);

/* Split the line into words. Returns 0 = words ready, -1 = empty line (or no word), the overflow cases end the
   loop (i = len) with err = 1, which is turned into 0 (the words found so far are used). */
static int split(char *line, unsigned char *argc, char (*argv)[0x20])
{
  int i, k, err, len;

  len = FUN_a00dd83c(line);
  if (len == 0)
    return -1;
  err = -1;
  k = 0;
  for (i = 0; i < len; i++)
    {
      unsigned char ch = line[i];
      switch (ch)
        {
        case ' ':
        case ',':
        case 0:
        case '\t':
          if (k != 0)
            {
              (*argc)++;
              k = 0;
              if (*argc > 4)
                {
                  err = 1;
                  i = len;
                  FUN_a00df170(s_00198b30);
                }
            }
          break;
        default:
          if (k + 1 > 0x1f)
            {
              err = 1;
              i = len;
              FUN_a00df170(s_00198af0);
            }
          else
            {
              argv[*argc][k] = ch;
              k++;
              err = 0;
            }
          break;
        }
    }
  if (err == 0)
    (*argc)++;
  else if (err == 1)
    err = 0;
  return err;
}

void FUN_a00dcec4(void)
{
  char c;
  unsigned char enter;
  int err, n, a, b, found, num;
  char (*av)[0x20];

  if (FUN_a00deea4(&c) == 0)
    return;
  enter = 0;
  switch (c)
    {
    case '\r':
      enter = 1;
      break;
    case '\b':
      if (DAT_a802d490 > 0)
        {
          DAT_a802d490--;
          FUN_a00def40(s_00198b28);
        }
      break;
    case 0x1b:
      DAT_a802d490 = 0;
      FUN_a00def40(s_00198b48);
      break;
    default:
      if (DAT_a802d490 == 0 && c == '^')
        {
          DAT_a802d495 = 1;
          DAT_a802d490 = 0;
        }
      else if (DAT_a802d490 < 0xfe)
        {
          DAT_a802d498[DAT_a802d490] = c;
          DAT_a802d490++;
          FUN_a00deef0(c);
        }
      break;
    }
  if (!enter)
    return;
  FUN_a00def40(s_00198f48);
  if (DAT_a802d490 < 0x100)
    DAT_a802d498[DAT_a802d490] = 0;
  else if (DAT_a802d490 != 0)
    DAT_a802d498[DAT_a802d490 - 1] = 0;
  else
    DAT_a802d498[0] = 0;
  err = split(DAT_a802d498, &DAT_a802d494, DAT_a802d598);
  if (err == 0)
    {
      av = DAT_a802d598;
      found = 0;
      num = sizeof(DAT_00198c90) / sizeof(DAT_00198c90[0]);
      for (n = 0; n < num; n++)
        if (FUN_a00dd868(DAT_00198c90[n].name, av[0]) == 0)
          {
            unsigned int fn;

            FUN_a00def40(s_00198f48);
            fn = DAT_00198c90[n].fn;
            if (fn)
              {
                int a1 = FUN_a00dcd38(av[1]);
                int a2 = FUN_a00dcd38(av[2]);
                int a3 = FUN_a00dcd38(av[3]);
                int a4 = FUN_a00dcd38(av[4]);
                ((void (*) (int, int, int, int)) fn) (a1, a2, a3, a4);
                FUN_a00def40(s_00198f48);
                FUN_a00def40(av[0]);
                FUN_a00def40(s_00198b58);
              }
            else
              FUN_a00def40(s_00198b10);
            found = 1;
            break;
          }
      if (!found)
        FUN_a00def40(s_00198b10);
      for (a = 0; a <= 4; a++)
        for (b = 0; b <= 0x1f; b++)
          DAT_a802d598[a][b] = 0;
      DAT_a802d494 = 0;
    }
  FUN_a00def40(s_00198b08);
  DAT_a802d490 = 0;
}
