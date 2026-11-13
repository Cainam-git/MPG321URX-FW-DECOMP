/* dbg_strcmp  (FUN_a00dd868)
 *
 * Compare two texts.
 * Returns: 0 when equal
 * Name basis: proven - difference of the first unequal characters; used by the command line
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd868 @ 0xa00dd868-0xa00dd8ac, 68 bytes, 17 words, flags -mcpu=v8 -O3 -g.
 * Source form: the two char locals are loaded first and the pointer increments come before 'diff = c1 - c2'; then
 * the loads keep ldub + shift extension like the firmware (an int local or the increments after the subtraction
 * give ldsb, 2 words shorter). The characters are signed.
 */

/*
 * Compare two zero-ended texts character by character (as signed chars). Returns 0 when they are equal,
 * otherwise the difference of the first two characters that differ. Called from dbg_command_shell to find a
 * command by its name.
 */
int dbg_strcmp(const char *a, const char *b)
{
  char c1, c2;
  int diff;

  do {
    c1 = *a;
    c2 = *b;
    a++;
    b++;
    diff = c1 - c2;
  } while (!diff && c1);
  return diff;
}
