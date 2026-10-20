/* leon2s FUN_a006fb00 @ 0xa006fb00  MATCH (-mcpu=v8 -Os -g)
 * 
 */
extern unsigned int DAT_a80788e0;
extern unsigned char DAT_a80788e4;
extern void FUN_a006fad4(unsigned int, int, int, unsigned int);

void FUN_a006fb00(void)
{
    unsigned int *p = &DAT_a80788e0;
    *p |= 1;
    DAT_a80788e4 = 1;
    FUN_a006fad4(0, 0, (int)p, 1);
    return;
}
