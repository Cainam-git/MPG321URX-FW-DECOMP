/* leon2s FUN_a00a0514 @ 0xa00a0514 (-mcpu=v8 -Os -g)
 * For i = 0 and 1: FUN_a00a73ac(9, word 0 of the 0x34-byte record i at 0xA807DB00, plus 0x78).
 */
extern unsigned char DAT_a807db00;
extern void FUN_a00a73ac(unsigned int param_1, int param_2);

void FUN_a00a0514(void)
{
    unsigned char i;
    
    i = 0;
    do {
        FUN_a00a73ac(9, *(int *)(&DAT_a807db00 + (i & 0xff) * 0x34) + 0x78);
        i++;
    } while ((i & 0xff) <= 1);
}
