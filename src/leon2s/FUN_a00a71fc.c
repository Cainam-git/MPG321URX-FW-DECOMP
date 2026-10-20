/* leon2s FUN_a00a71fc @ 0xa00a71fc  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned short DAT_a00b4d88[];

void FUN_a00a71fc(unsigned int param_1, unsigned short param_2, unsigned int param_3, unsigned int param_4)
{
    unsigned char i;
    
    param_1 &= 0xff;
    if (param_1 == 4) {
        i = 0;
        do {
            *(volatile unsigned int *)(0xcf000000 | 
                ((DAT_a00b4d88[i] + (unsigned short)param_2) * 4)) = 
                (*(volatile unsigned int *)(0xcf000000 | 
                    ((DAT_a00b4d88[i] + (unsigned short)param_2) * 4)) & ~param_3 | param_3 & param_4) & 0xff;
            i++;
        } while (i <= 3);
    } else if (param_1 < 4) {
        *(volatile unsigned int *)(0xcf000000 | 
            ((DAT_a00b4d88[param_1] + (unsigned short)param_2) * 4)) = 
            (*(volatile unsigned int *)(0xcf000000 | 
                ((DAT_a00b4d88[param_1] + (unsigned short)param_2) * 4)) & ~param_3 | param_3 & param_4) & 0xff;
    }
}
