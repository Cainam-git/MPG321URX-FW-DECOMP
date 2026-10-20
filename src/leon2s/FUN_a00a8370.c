/* leon2s FUN_a00a8370 @ 0xa00a8370 (-mcpu=v8 -Os -g)
 * 
 */
extern unsigned short DAT_a00b4d20[];

void FUN_a00a8370(unsigned int param_1, unsigned short param_2, unsigned int param_3)
{
    unsigned char i;
    unsigned short uVar1;

    param_1 &= 0xff;
    if (param_1 > 7) {
        i = 0;
        do {
            uVar1 = (unsigned short)i;
            *(volatile unsigned int *)(0xcf000000 | 
                ((DAT_a00b4d20[uVar1] + param_2) * 4)) = param_3 & 0xff;
            i++;
        } while ((unsigned char)i <= 7);
    } else {
        *(volatile unsigned int *)(0xcf000000 | 
            ((DAT_a00b4d20[param_1] + param_2) * 4)) = param_3 & 0xff;
    }
}
