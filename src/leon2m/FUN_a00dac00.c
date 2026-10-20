/* leon2m FUN_a00dac00 @ 0xa00dac00  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a012743c(0) when DAT_a802d290[0x1E8] is zero, otherwise FUN_a012743c(DAT_a802d290[0x1E9]). The
 * unsigned char parameter matches the ldub before the call.
 */
extern unsigned char DAT_a802d290[]; /* 0xa802d290 */
extern int FUN_a012743c(unsigned char); /* 0xa012743c */

void FUN_a00dac00(void)
{
    if (DAT_a802d290[0x1e8] == 0) {
        FUN_a012743c(0);
        return;
    }
    FUN_a012743c(DAT_a802d290[0x1e9]);
}
