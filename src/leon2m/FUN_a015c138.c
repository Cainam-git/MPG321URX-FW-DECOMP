/* leon2m FUN_a015c138 @ 0xa015c138
 * The C library's _setlocale_r(p, category, locale) (newlib locale.o, built without multibyte support), linked at
 * this address. A NULL locale only returns "C". Otherwise the locale must compare equal (FUN_a015e078 = strcmp) to
 * "C" or to ""; then category and locale are stored in words +0x30 and +0x34 of the record p and "C" is returned,
 * else 0 is returned. Written in C because the archive member also defines its own data (.data/.bss), which the
 * firmware keeps at its own addresses. "C" and "" are the read-only string objects at 0x1A83E0 and 0xFF5E0,
 * declared as externs.
 */
struct reent {
    int unused[12];
    int current_category;       /* +0x30 */
    const char *current_locale; /* +0x34 */
};

extern const char s_001a83e0[]; /* "C" */
extern const char s_000ff5e0[]; /* "" */
extern int FUN_a015e078(const char *a, const char *b);

char *FUN_a015c138(struct reent *p, int category, const char *locale)
{
    if (locale) {
        if (FUN_a015e078(locale, s_001a83e0) && FUN_a015e078(locale, s_000ff5e0))
            return 0;
        p->current_category = category;
        p->current_locale = locale;
    }
    return (char *)s_001a83e0;
}
