/* dbg_strlen  (FUN_a00b1538)
 *
 * Return the length of a text.
 * Returns: length
 * Name basis: proven - counts bytes up to the first zero
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1538 @ 0xa00b1538 (-mcpu=v8 -Os -g).
 * Source form: the character is read again at the end of each pass, and the pointer and the count are
 * advanced in two statements.
 */
/* Return the number of bytes before the first zero byte of a text. */
int dbg_strlen(char *text)

{
  char c;
  int length;
  
  length = 0;
  c = *text;
  while (c != '\0') {
    text = text + 1;
    length = length + 1;
    c = *text;
  }
  return length;
}
