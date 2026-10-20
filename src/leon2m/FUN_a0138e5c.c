/* leon2m FUN_a0138e5c @ 0xa0138e5c  MATCH (-mcpu=v8 -O2 -g)
 * Calls func_0x4008c4d0(1, 0, &local_c, 1) with local_c = 0 and returns (local_c >> 1) & 3 (srl %g1, 1, %i0; and
 * %i0, 3, %i0). The function reads no parameters.
 */
extern int func_0x4008c4d0();

int FUN_a0138e5c(void)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(1, 0, &local_c, 1);
    return (local_c >> 1) & 3;
}
