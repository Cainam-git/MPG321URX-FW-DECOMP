/* leon2s FUN_a00a0514 @ 0xa00a0514  MATCH (-mcpu=v8 -Os -g)
 * 
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
