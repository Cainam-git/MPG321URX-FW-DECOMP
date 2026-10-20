/* leon2m FUN_a00a429c @ 0xa00a429c (-mcpu=v8 -O2 -g)
 * Counts down the byte DAT_a802d290[9]: when it holds 1..0x65 ((unsigned char)(v - 1) <= 0x64), stores v - 1 and
 * calls FUN_a00b7054(1) and FUN_a00d8cd4(); otherwise sets it to 0. In both cases sets bit 1 of DAT_a802b08e.
 * Returns param_1 unchanged (ret / restore).
 */
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802d290[];
extern int FUN_a00b7054(int);
extern int FUN_a00d8cd4(void);

int FUN_a00a429c(int param_1, int param_2)
{
    unsigned char v = DAT_a802d290[9];
    
    if ((unsigned char)(v - 1) <= 0x64) {
        v--;
        DAT_a802d290[9] = v;
        FUN_a00b7054(1);
        FUN_a00d8cd4();
    } else {
        DAT_a802d290[9] = 0;
    }
    
    DAT_a802b08e |= 2;
    return param_1;
}
