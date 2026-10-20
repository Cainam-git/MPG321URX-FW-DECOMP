/* leon2m FUN_a01384ac @ 0xa01384ac  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a01370dc(0x83, 4, buffer, 0) with the 4-byte buffer {param_1, param_2, 0, 0}, then FUN_a0137344(1)
 * ('call; mov 1, %o0', then 'nop; ret; restore'). Returns void.
 */
extern void FUN_a01370dc();
extern int FUN_a0137344();

void FUN_a01384ac(unsigned char param_1, unsigned char param_2)
{
    unsigned char buf[4] = {param_1, param_2};
    FUN_a01370dc(0x83, 4, buf, 0);
    FUN_a0137344(1);
}
