/* leon2m FUN_a013707c @ 0xa013707c (-mcpu=v8 -O2 -g)
 * Calls func_0x4008c4d0(1, 0x0C, &local, 1) with a zero-initialised 4-byte local and returns bit 28 of the value
 * written to it (0 or 1).
 */
extern int func_0x4008c4d0();

int FUN_a013707c(void)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(1, 0xc, &local_c, 1);
    return (local_c >> 0x1c) & 1;
}
