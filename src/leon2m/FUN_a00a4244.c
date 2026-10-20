/* leon2m FUN_a00a4244 @ 0xa00a4244  MATCH (-mcpu=v8 -O2 -g)
 * Increments the byte DAT_a802d290[9]. A result <= 100 is stored and followed by FUN_a00b7054(1) and
 * FUN_a00d8cd4(); a larger result stores 100. Then sets bit 1 of DAT_a802b08e.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern int FUN_a00b7054(int);
extern int FUN_a00d8cd4(void);

void FUN_a00a4244(void)
{
    unsigned char v = DAT_a802d290[9] + 1;

    if (v <= 0x64) {
        DAT_a802d290[9] = v;
        FUN_a00b7054(1);
        FUN_a00d8cd4();
    } else {
        DAT_a802d290[9] = 0x64;
    }

    DAT_a802b08e |= 2;
    return 0;
}
