/* setlocale  (FUN_a015c1c0)
 *
 * Set the locale through _setlocale_r with the global reentrancy structure.
 * Name basis: proven - wrapper passing _impure_ptr to _setlocale_r
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015c1c0 @ 0xa015c1c0, flags -mcpu=v8 -O2 -g.
 * The call to _setlocale_r is a tail call (call with %o7 saved in %g1 and restored in the delay slot).
 */
struct reent;

extern struct reent *_impure_ptr;
extern char *_setlocale_r(struct reent *p, int category, const char *locale);

/*
 * Call _setlocale_r with the state record _impure_ptr (0xA802AA18) and the two arguments, and return its result.
 */
char *setlocale(int category, const char *locale)
{
    return _setlocale_r(_impure_ptr, category, locale);
}
