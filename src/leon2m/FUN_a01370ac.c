/* leon2m FUN_a01370ac @ 0xa01370ac (-mcpu=v8 -O2 -g)
 * Reads one word w with func_0x4008c4d0(1, 0xc, &w, 1) (portal 1, offset 0xc) and returns bit 29 of it.
 */
extern int func_0x4008c4d0();

int FUN_a01370ac(void)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(1, 0xc, &local_c, 1);
    return (local_c >> 0x1d) & 1;
}
