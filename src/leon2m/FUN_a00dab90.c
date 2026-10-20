/* leon2m FUN_a00dab90 @ 0xa00dab90 (-mcpu=v8 -O2 -g)
 * Twin of FUN_a00dabc8: same code, other constants.
 * See FUN_a00dabc8 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a802d290[];
extern int FUN_a0127154(int);

void FUN_a00dab90(void)
{
    if (DAT_a802d290[0x1ec] == 0) {
        FUN_a0127154(0);
        return;
    }
    FUN_a0127154(DAT_a802d290[0x1ed]);
}
