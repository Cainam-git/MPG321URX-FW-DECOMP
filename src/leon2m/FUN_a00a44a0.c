/* leon2m FUN_a00a44a0 @ 0xa00a44a0 (-mcpu=v8 -O3 -g)
 * Twin of FUN_a00a4348: same code, other constants.
 * See FUN_a00a4348 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern int FUN_a00b7530(int);
extern int FUN_a00d4780(void);

int FUN_a00a44a0(int param_1, int param_2)
{
    unsigned char v = DAT_a802d290[0xf] - 1;
    
    if (v <= 5) {
        DAT_a802d290[0xf] = v;
        FUN_a00b7530(1);
        FUN_a00d4780();
    } else {
        DAT_a802d290[0xf] = 0;
    }
    
    DAT_a802b08e |= 2;
    return param_1;
}
