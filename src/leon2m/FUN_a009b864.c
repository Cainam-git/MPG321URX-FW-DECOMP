/* leon2m FUN_a009b864 @ 0xa009b864-0xa009b8e0 (31 words), flags -mcpu=v8 -O3 -g.
 * Steps byte 0xa802d420 (offset 0x190 of the block at 0xa802d290) down through 6..0 (0 becomes 6). FUN_a00a9cc8(old
 * value) is called first and FUN_a00a9dac(new value, 1) afterwards; then FUN_a00a813c(2, v, flag) with v = byte
 * 0xa8025c56 and flag 0 when the new value equals v, 1 otherwise, and the tail call FUN_a00b88b8(). Down counterpart
 * of FUN_a009b8e0 (same source form: the test is written '== 0' with the reset first, then '--').
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c56;
extern void FUN_a00a9cc8(unsigned char);
extern void FUN_a00a9dac(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00b88b8(void);

void FUN_a009b864(void)
{
    FUN_a00a9cc8(DAT_a802d290[0x190]);
    if (DAT_a802d290[0x190] == 0)
        DAT_a802d290[0x190] = 6;
    else
        DAT_a802d290[0x190]--;
    FUN_a00a9dac(DAT_a802d290[0x190], 1);
    {
        unsigned char v = DAT_a8025c56;
        if (DAT_a802d290[0x190] == v)
            FUN_a00a813c(2, v, 0);
        else
            FUN_a00a813c(2, v, 1);
    }
    FUN_a00b88b8();
}
