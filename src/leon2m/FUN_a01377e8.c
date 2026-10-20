/* leon2m FUN_a01377e8 @ 0xa01377e8  MATCH (-mcpu=v8 -O2 -g)
 * 
 */
extern void func_0x4008c4d0();

unsigned int FUN_a01377e8(unsigned short param_1, unsigned int param_2)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(1, 0xcc, &local_c, 1);
    return (param_1 & ((local_c & 0xff00) >> 8)) != 0;
}
