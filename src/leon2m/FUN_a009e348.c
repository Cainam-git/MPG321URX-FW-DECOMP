/* leon2m FUN_a009e348 @ 0xa009e348-0xa009e3c8 (32 words).
 * Steps byte 0xa802d33c (offset 0xac of the block at 0xa802d290) down through 0..4 (0 becomes 4). FUN_a00a93bc(old
 * value) is called first, then FUN_a00da754(new value) and FUN_a00a9650(new value, 1), and finally FUN_a00a813c(1, v,
 * flag) with v = byte 0xa8025c55 and flag 0 when the new value equals v, 1 otherwise. Same code as FUN_a009e5ac with
 * another byte and range.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c55;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00da754(unsigned char);

void FUN_a009e348(void)
{
    FUN_a00a93bc(DAT_a802d290[0xac]);
    if (DAT_a802d290[0xac] != 0)
        DAT_a802d290[0xac]--;
    else
        DAT_a802d290[0xac] = 4;
    FUN_a00da754(DAT_a802d290[0xac]);
    FUN_a00a9650(DAT_a802d290[0xac], 1);
    {
        unsigned char v = DAT_a8025c55;
        if (DAT_a802d290[0xac] == v)
            FUN_a00a813c(1, v, 0);
        else
            FUN_a00a813c(1, v, 1);
    }
}
