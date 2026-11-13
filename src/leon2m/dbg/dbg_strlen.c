/* dbg_strlen  (FUN_a00dd83c)
 *
 * Return the length of a text.
 * Returns: length
 * Name basis: proven - counts bytes up to the first zero; used by the command line
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd83c @ 0xa00dd83c, flags -mcpu=v8 -O2 -g.
 * Source form: the pointer is advanced in the loop (not indexed), the character is re-read at the end of each
 * pass, and the blank line between the header and the brace is kept.
 */

/* Number of bytes before the first zero byte of text. Used by dbg_command_shell and dbg_parse_number. */
int dbg_strlen(char *text)

{
  char character;
  int length;
  
  length = 0;
  character = *text;
  while (character != '\0') {
    text = text + 1;
    length = length + 1;
    character = *text;
  }
  return length;
}
