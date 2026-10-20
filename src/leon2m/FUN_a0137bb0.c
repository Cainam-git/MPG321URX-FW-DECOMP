/* leon2m FUN_a0137bb0 @ 0xa0137bb0 (-mcpu=v8 -O2 -g)
 * 
 */
extern void FUN_a01370dc();
extern int FUN_a0137344();
extern unsigned char DAT_a802cba3;

int FUN_a0137bb0(void)
{
    unsigned char local_10[4] = {0, 0, 0, 0};
    
    FUN_a01370dc(0x87, 4, local_10, 0);
    FUN_a0137344(1);
    
    return DAT_a802cba3 & 1;
}
