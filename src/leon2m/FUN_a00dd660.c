/* leon2m FUN_a00dd660 @ 0xa00dd660-0xa00dd6b0 (20 words).
 * Prints every entry of the null-terminated list of string pointers at 0xa8025c68 with the format "\n%s",
 * starting at entry 0 and stopping at the first null entry. No arguments, no return value.
 */
extern const char *DAT_a8025c68[];
extern int FUN_a00df170(const char *fmt, ...);

void FUN_a00dd660(void)
{
    int i;

    for (i = 0; DAT_a8025c68[i] != 0; i++)
        FUN_a00df170("\n%s", DAT_a8025c68[i]);
}
