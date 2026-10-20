/* leon2m FUN_a00a42f0 @ 0xa00a42f0  MATCH (-mcpu=v8 -O2 -g)
 * The function returns 1 in both cases, as shown by `mov 1, %o0` before the branch.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern int FUN_a00b6f20(int);
extern int FUN_a00d7de0(void);

void FUN_a00a42f0(void)
{
    unsigned char v = DAT_a802d290[0xa] + 1;
    
    if (v <= 0x64) {
        DAT_a802d290[0xa] = v;
        FUN_a00b6f20(1);
        FUN_a00d7de0();
    } else {
        DAT_a802d290[0xa] = 0x64;
    }
    
    DAT_a802b08e |= 2;
    return 1;
}
