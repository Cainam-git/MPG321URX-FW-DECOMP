/* leon2s FUN_a00a6c00 @ 0xa00a6c00  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Finished from mechanical Ghidra C. Register write helper (twin of the read
 * helper FUN_a00a6bb8): writes the low byte of param_3 to register param_2 of port param_1 at
 * 0xcf000000 | ((base[port] + reg) * 4), base table at 0xa00b4d94. Port 2 means both ports (0
 * and 1); ports above 2 are ignored.
 * Still needs a real name and proper types.
 */
extern unsigned short DAT_a00b4d94[];

void FUN_a00a6c00(unsigned int param_1, unsigned short param_2, unsigned int param_3)
{
    unsigned char i;
    
    param_1 &= 0xff;
    if (param_1 > 2)
        return;
    
    if (param_1 == 2) {
        for (i = 0; i <= 1; i++) {
            *(volatile unsigned int *)(0xcf000000 | 
                ((DAT_a00b4d94[i] + (unsigned short)param_2) * 4)) = param_3 & 0xff;
        }
    } else {
        *(volatile unsigned int *)(0xcf000000 | 
            ((DAT_a00b4d94[param_1] + (unsigned short)param_2) * 4)) = param_3 & 0xff;
    }
}
