/* leon2m FUN_a00deef0 @ 0xa00deef0  MATCH (-mcpu=v8 -O2 -g)
 * Polls register 0xC00B0014 through func_0x4008c250 up to 0xFFFFF times until bit 5 (0x20) is set, then calls
 * func_0x4008c25c(0xC00B0000, param_1) with the sign-extended byte parameter. The write happens also when the poll
 * limit is reached.
 *
 * Required form: a while loop with the compare at the top (i <= 0xffffe, held in a local), the bit test inside,
 * and the increment after the test.
 */
extern int func_0x4008c250(unsigned int);
extern int func_0x4008c25c(unsigned int, signed char);

void FUN_a00deef0(signed char param_1)
{
    unsigned int i = 0;
    unsigned int bound = 0xffffe;
    
    while (i <= bound) {
        if (func_0x4008c250(0xc00b0014) & 0x20)
            break;
        i++;
    }
    
    func_0x4008c25c(0xc00b0000, param_1);
}
