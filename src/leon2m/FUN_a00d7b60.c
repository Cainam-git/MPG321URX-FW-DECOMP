/* leon2m FUN_a00d7b60 @ 0xa00d7b60-0xa00d7bc0 (24 words).
 * Returns 1 when FUN_a014ba68() is 2 or FUN_a014bd70(0) is 1, else 0; both functions are always called.
 * No direct calls to it in the code.
 */
extern unsigned char FUN_a014ba68(void);
extern unsigned char FUN_a014bd70(unsigned char ch);

int FUN_a00d7b60(void)
{
    unsigned char r = 0;

    if (FUN_a014ba68() == 2)
        r = 1;
    if (FUN_a014bd70(0) == 1)
        r = 1;
    return r & 1;
}
