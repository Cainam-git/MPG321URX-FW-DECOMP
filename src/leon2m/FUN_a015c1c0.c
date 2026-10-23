/* leon2m FUN_a015c1c0 @ 0xa015c1c0 (-mcpu=v8 -O2 -g)
 * The C library's setlocale(category, locale) (newlib locale.o): passes the reent pointer stored in the word
 * 0xA802AA18 together with (category, locale) to FUN_a015c138 (_setlocale_r) and returns its result. GCC emits it
 * as a leaf with a tail call (call with %o7 saved in %g1 and restored in the delay slot).
 */
struct reent;

extern struct reent *_DAT_a802aa18;
extern char *FUN_a015c138(struct reent *p, int category, const char *locale);

char *FUN_a015c1c0(int category, const char *locale)
{
    return FUN_a015c138(_DAT_a802aa18, category, locale);
}
