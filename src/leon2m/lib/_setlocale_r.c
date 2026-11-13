/* _setlocale_r  (FUN_a015c138)
 *
 * Accept only the C locale; store category and locale name in the reentrancy structure.
 * Name basis: proven - newlib locale.c behaviour; record names it
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015c138 @ 0xa015c138, flags -mcpu=v8 -O2 -g.
 * Written in C because the archive member also defines its own data (.data/.bss), which the firmware keeps at its
 * own addresses. "C" and "" are the read-only string objects at 0x1A83E0 and 0xFF5E0, declared as externs.
 */
/* The part of the C library state record used here. */
struct reent {
    int unused[12];
    int current_category;       /* +0x30 */
    const char *current_locale; /* +0x34 */
};

extern const char s_001a83e0[]; /* "C" */
extern const char s_000ff5e0[]; /* "" */
extern int strcmp(const char *a, const char *b);

/*
 * Set the locale of the state record p. Only the locale names "C" and "" are accepted.
 *   category  stored at +0x30 of the record
 *   locale    NULL asks for the current locale and changes nothing; otherwise stored at +0x34 when it equals "C"
 *             or ""; any other name returns 0 and changes nothing
 * Returns "C" (the string at 0x1A83E0).
 */
char *_setlocale_r(struct reent *p, int category, const char *locale)
{
    if (locale) {
        if (strcmp(locale, s_001a83e0) && strcmp(locale, s_000ff5e0))
            return 0;
        p->current_category = category;
        p->current_locale = locale;
    }
    return (char *)s_001a83e0;
}
