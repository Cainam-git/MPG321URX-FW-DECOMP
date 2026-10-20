/* leon2m FUN_a013129c @ 0xa013129c  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a0130438, then for i = 0..3 calls FUN_a013d684(i & 0xFF) and FUN_a013d918(i & 0xFF). Returns void:
 * the 'and %l1,0xff,%l0' before ret is the delay slot of the loop's ble, not a return value.
 */
extern int FUN_a0130438(void); /* 0xa0130438 */
extern int FUN_a013d684(int);  /* 0xa013d684 */
extern int FUN_a013d918(int);  /* 0xa013d918 */

void FUN_a013129c(void)
{
    int i;
    FUN_a0130438();
    i = 0;
    do {
        FUN_a013d684(i & 0xff);
        FUN_a013d918(i & 0xff);
        i++;
    } while (i <= 3);
}
