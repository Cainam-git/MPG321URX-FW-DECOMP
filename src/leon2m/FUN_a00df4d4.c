/* leon2m FUN_a00df4d4 @ 0xa00df4d4  MATCH (-mcpu=v8 -O2 -g)
 * Polls the register at 0xC00B0014 through func_0x4008c250 until bit 5 (0x20) is set, then writes param_1 to
 * 0xC00B0000 through func_0x4008c25c. The signed char parameter produces the sll / sra sign extension.
 */
extern int func_0x4008c250(unsigned int);
extern int func_0x4008c25c(unsigned int, signed char);

void FUN_a00df4d4(signed char param_1)
{
    while ((func_0x4008c250(0xc00b0014) & 0x20) == 0)
        ;
    func_0x4008c25c(0xc00b0000, param_1);
}
