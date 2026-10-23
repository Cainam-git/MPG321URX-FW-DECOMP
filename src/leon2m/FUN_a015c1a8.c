/* leon2m FUN_a015c1a8 @ 0xa015c1a8 (-mcpu=v8 -O2 -g)
 * The C library's __locale_charset() (newlib locale.o): returns the character-set name pointer stored in the word
 * 0xA802AAA8 (the member's own data, kept by the firmware at that address). Leaf function: retl with the load in
 * the delay slot.
 */
extern char *DAT_a802aaa8;

char *FUN_a015c1a8(void)
{
    return DAT_a802aaa8;
}
