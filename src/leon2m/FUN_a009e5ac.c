/* leon2m FUN_a009e5ac @ 0xa009e5ac-0xa009e624 (30 words).
 * Steps byte 0xa802d470 (offset 0x1e0 of the block at 0xa802d290) down by one; 0 becomes 1. FUN_a00a93bc(old value)
 * is called first and FUN_a00a9650(new value, 1) afterwards. Finally FUN_a00a813c(1, v, flag) with v = byte
 * 0xa8025c55 and flag 0 when the new value equals v, 1 otherwise.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c55;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a009e5ac(void)
{
    FUN_a00a93bc(DAT_a802d290[0x1e0]);
    if (DAT_a802d290[0x1e0] != 0)
        DAT_a802d290[0x1e0]--;
    else
        DAT_a802d290[0x1e0] = 1;
    FUN_a00a9650(DAT_a802d290[0x1e0], 1);
    {
        unsigned char v = DAT_a8025c55;
        if (DAT_a802d290[0x1e0] == v)
            FUN_a00a813c(1, v, 0);
        else
            FUN_a00a813c(1, v, 1);
    }
}
