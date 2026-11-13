/* __locale_charset  (FUN_a015c1a8)
 *
 * Return the character-set name pointer stored at 0xA802AAA8.
 * Returns: pointer to the charset name
 * Name basis: proven - returns the stored pointer (newlib locale.c)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015c1a8 @ 0xa015c1a8, flags -mcpu=v8 -O2 -g.
 * Leaf function: retl with the load in the delay slot.
 */
extern char *libc_locale_charset;

/*
 * Return the character-set name pointer stored in libc_locale_charset (0xA802AAA8).
 */
char *__locale_charset(void)
{
    return libc_locale_charset;
}
