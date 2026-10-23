/* leon2m FUN_a00a4448 @ 0xa00a4448 (-mcpu=v8 -O3 -g)
 * v = byte 0xA802D29F (0xA802D290 + 0xF) + 1 (8 bits). When v <= 5 stores v back and calls FUN_a00b7530(1) and
 * FUN_a00d4780(); otherwise stores 5. Sets bit 1 of byte 0xA802B08E and returns p1. Same code as FUN_a00a439c with
 * other constants.
 * See FUN_a00a439c for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern int FUN_a00b7530(int);
extern int FUN_a00d4780(void);

int FUN_a00a4448(int param_1, int param_2)
{
    unsigned char v = DAT_a802d290[0xf] + 1;
    
    if (v <= 5) {
        DAT_a802d290[0xf] = v;
        FUN_a00b7530(1);
        FUN_a00d4780();
    } else {
        DAT_a802d290[0xf] = 5;
    }
    
    DAT_a802b08e |= 2;
    return param_1;
}
