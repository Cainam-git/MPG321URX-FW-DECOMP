/* leon2m FUN_a00a4348 @ 0xa00a4348  MATCH (-mcpu=v8 -O2 -g)
 * Decrements the byte counter at offset 0x0A of the mode record DAT_a802d290. If the decremented value (as
 * unsigned byte) is <= 100 it is stored and FUN_a00b6f20(1) and FUN_a00d7de0() are called; otherwise (the counter
 * was 0) the counter is set to 0. Then sets bit 1 of DAT_a802b08e and returns the first parameter unchanged in
 * %o0. The call results are not used.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern int FUN_a00b6f20(int);
extern int FUN_a00d7de0(void);

int FUN_a00a4348(int param_1, int param_2)
{
    unsigned char v = DAT_a802d290[0xa] - 1;
    
    if (v <= 100) {
        DAT_a802d290[0xa] = v;
        FUN_a00b6f20(1);
        FUN_a00d7de0();
    } else {
        DAT_a802d290[0xa] = 0;
    }
    
    DAT_a802b08e |= 2;
    return param_1;
}
