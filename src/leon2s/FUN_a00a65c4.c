/* leon2s FUN_a00a65c4 @ 0xa00a65c4 (-mcpu=v8 -Os -g)
 * The function writes a value to memory-mapped registers at addresses computed from a lookup table `DAT_a00b4d9c` plus a parameter, scaled and OR'd with the register base. For `param_1 == 2` it writes two entries; for `param_1 < 2` (i.e., 0 or 1) it writes one entry. The declaration must be an array because the assembly uses indexed `lduh` accesses.
 */
extern unsigned short DAT_a00b4d9c[];

void FUN_a00a65c4(unsigned int param_1, unsigned short param_2, unsigned int param_3)
{
    unsigned char i;
    
    param_1 &= 0xff;
    if (param_1 > 2)
        return;
    
    if (param_1 == 2) {
        i = 0;
        do {
            *(volatile unsigned int *)(0xcf000000 | 
                ((DAT_a00b4d9c[i] + (unsigned short)param_2) * 4)) = param_3 & 0xff;
            i++;
        } while (i <= 1);
    } else if (param_1 < 2) {
        *(volatile unsigned int *)(0xcf000000 | 
            ((DAT_a00b4d9c[param_1] + (unsigned short)param_2) * 4)) = param_3 & 0xff;
    }
}
