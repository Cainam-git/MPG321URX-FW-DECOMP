/* leon2s FUN_a00a71fc @ 0xa00a71fc (-mcpu=v8 -Os -g)
 * With R(i) = register 0xCF000000 | ((halfword i of the table at 0xA00B4D88 + p2) * 4), sets R(i) to ((R(i) & ~p3)
 * | (p3 & p4)) & 0xff for i = 0 .. 3 when p1 (low byte) == 4, and for i = p1 when p1 < 4. Other p1 return without
 * an access.
 * Source form: Ghidra's type and symbol names are kept.
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
