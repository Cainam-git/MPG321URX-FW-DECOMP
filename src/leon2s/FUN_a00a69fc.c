/* leon2s FUN_a00a69fc @ 0xa00a69fc (-mcpu=v8 -Os -g)
 * k = p1 & 0xff. Writes p3 & 0xff to the register 0xCF000000 | ((halfword i of the table at 0xA00B4D98 + p2) * 4)
 * for i = 0 and 1 when k == 2, for i = k when k < 2; other k return without a write. Same code as FUN_a00a65c4
 * with other constants.
 */
extern unsigned short DAT_a00b4d98[];

void FUN_a00a69fc(unsigned int param_1, unsigned short param_2, unsigned int param_3)
{
    unsigned char i;
    
    param_1 &= 0xff;
    if (param_1 > 2)
        return;
    
    if (param_1 == 2) {
        i = 0;
        do {
            *(volatile unsigned int *)(0xcf000000 | 
                ((DAT_a00b4d98[i] + (unsigned short)param_2) * 4)) = param_3 & 0xff;
            i++;
        } while (i <= 1);
    } else if (param_1 < 2) {
        *(volatile unsigned int *)(0xcf000000 | 
            ((DAT_a00b4d98[param_1] + (unsigned short)param_2) * 4)) = param_3 & 0xff;
    }
}
