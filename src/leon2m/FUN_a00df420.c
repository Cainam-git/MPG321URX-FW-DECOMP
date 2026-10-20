/* leon2m FUN_a00df420 @ 0xa00df420  MATCH (-mcpu=v8 -O2 -g)
 * Waits until bit 0 of register 0xC00B0014 (read through func_0x4008c250) is set, with no timeout, then returns
 * the low byte of register 0xC00B0000.
 */
extern int func_0x4008c250(unsigned int);

int FUN_a00df420(void)
{
    while ((func_0x4008c250(0xc00b0014) & 1) == 0)
        ;
    return func_0x4008c250(0xc00b0000) & 0xff;
}
