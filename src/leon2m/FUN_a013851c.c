/* leon2m FUN_a013851c @ 0xa013851c (-mcpu=v8 -O2 -g)
 * Sends {p, 0, 0, 0} with FUN_a01370dc(0xfd, 4, buf, 0), calls FUN_a0137344(1) and returns byte 0xA802CBA3.
 */
extern void FUN_a01370dc();
extern int FUN_a0137344();
extern unsigned char DAT_a802cba3;

int FUN_a013851c(unsigned char param_1)
{
    unsigned char local_10[4] = {param_1, 0, 0, 0};
    
    FUN_a01370dc(0xfd, 4, local_10, 0);
    FUN_a0137344(1);
    
    return DAT_a802cba3;
}
