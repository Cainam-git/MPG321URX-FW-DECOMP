/* leon2m FUN_a013a728 @ 0xa013a728  MATCH (-mcpu=v8 -O2 -g)
 * Copies param_1 into a local word and writes it with func_0x4008c5f8(2, 0x38, &local, 1) (MailBox_Write, portal 2,
 * offset 0x38, one word).
 */
extern int func_0x4008c5f8();

void FUN_a013a728(unsigned int param_1)
{
    unsigned int local_c;
    local_c = param_1;
    func_0x4008c5f8(2, 0x38, &local_c, 1);
}
