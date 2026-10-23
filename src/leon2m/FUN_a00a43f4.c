/* leon2m FUN_a00a43f4 @ 0xa00a43f4 (-mcpu=v8 -O3 -g)
 * v = byte 0xA802D2D9 (0xA802D290 + 0x49) - 1 (8 bits). When v <= 5 stores v back and calls FUN_a00b7188(1) and
 * FUN_a00d4084(); otherwise stores 0. Sets bit 1 of byte 0xA802B08E and returns p1. Same code as FUN_a00a4348 with
 * other constants.
 * See FUN_a00a4348 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern int FUN_a00b7188(int);
extern int FUN_a00d4084(void);

int FUN_a00a43f4(int param_1, int param_2)
{
    unsigned char v = DAT_a802d290[0x49] - 1;
    
    if (v <= 5) {
        DAT_a802d290[0x49] = v;
        FUN_a00b7188(1);
        FUN_a00d4084();
    } else {
        DAT_a802d290[0x49] = 0;
    }
    
    DAT_a802b08e |= 2;
    return param_1;
}
