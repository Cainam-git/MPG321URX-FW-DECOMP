/* leon2m FUN_a01386ac @ 0xa01386ac  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a01370dc(0x94, 4, buf, 0) with buf = {param_1, low byte of param_2, high byte of param_2, 0}.
 */
extern int FUN_a01370dc();

void FUN_a01386ac(unsigned char param_1, unsigned short param_2)
{
    unsigned char local_10[4] = {param_1, (unsigned char)param_2, (unsigned char)(param_2 >> 8)};
    FUN_a01370dc(0x94, 4, local_10, 0);
}
