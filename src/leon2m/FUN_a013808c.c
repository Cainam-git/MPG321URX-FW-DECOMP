/* leon2m FUN_a013808c @ 0xa013808c (-mcpu=v8 -O2 -g)
 * Calls FUN_a01370dc(0x5c, 4, buf, 0) with the local bytes buf = {p1, 0, 0, 0} and FUN_a0137344(1); returns byte
 * 0xA802CBA3. Same code as FUN_a013851c with other constants.
 */
extern void FUN_a01370dc();
extern int FUN_a0137344();
extern unsigned char DAT_a802cba3;

int FUN_a013808c(unsigned char param_1)
{
    unsigned char local_10[4] = {param_1, 0, 0, 0};
    
    FUN_a01370dc(0x5c, 4, local_10, 0);
    FUN_a0137344(1);
    
    return DAT_a802cba3;
}
