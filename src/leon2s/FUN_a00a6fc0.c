/* leon2s FUN_a00a6fc0 @ 0xa00a6fc0 (-mcpu=v8 -Os -g)
 * Writes param_3 & 0xFF to the volatile register 0xCF000000 | ((DAT_a00b4d90[k] + param_2) * 4). For
 * param_1 = 0 or 1, k = param_1; for param_1 = 2 a do-while loop writes k = 0 and k = 1; for param_1 > 2 nothing
 * is written. DAT_a00b4d90 is a table of unsigned short entries.
 */
extern unsigned short DAT_a00b4d90[];

void FUN_a00a6fc0(unsigned int param_1, unsigned short param_2, unsigned int param_3)
{
    unsigned char i;
    
    param_1 &= 0xff;
    if (param_1 > 2)
        return;
    
    if (param_1 == 2) {
        i = 0;
        do {
            *(volatile unsigned int *)(0xcf000000 | 
                ((DAT_a00b4d90[i] + (unsigned short)param_2) * 4)) = param_3 & 0xff;
            i++;
        } while (i <= 1);
    } else {
        *(volatile unsigned int *)(0xcf000000 | 
            ((DAT_a00b4d90[param_1] + (unsigned short)param_2) * 4)) = param_3 & 0xff;
    }
}
