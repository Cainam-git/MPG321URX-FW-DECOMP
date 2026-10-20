/* leon2m FUN_a00a439c @ 0xa00a439c (-mcpu=v8 -O2 -g)
 * Increments the byte DAT_a802d290[0x49]. A result <= 5 is stored and followed by FUN_a00b7188(1) and
 * FUN_a00d4084(); a larger result stores 5. Then sets bit 1 of DAT_a802b08e and returns param_1 unchanged. The
 * indexed array form (base 0xa802d290, offset 0x49) gives the target's addressing.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern int FUN_a00b7188(int);
extern int FUN_a00d4084(void);

int FUN_a00a439c(int param_1, int param_2)
{
    unsigned char v = DAT_a802d290[0x49] + 1;
    
    if (v <= 5) {
        DAT_a802d290[0x49] = v;
        FUN_a00b7188(1);
        FUN_a00d4084();
    } else {
        DAT_a802d290[0x49] = 5;
    }
    
    DAT_a802b08e |= 2;
    return param_1;
}
