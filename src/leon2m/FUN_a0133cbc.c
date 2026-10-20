/* leon2m FUN_a0133cbc @ 0xa0133cbc (-mcpu=v8 -O2 -g)
 * Reads a 32-bit register value through the register read function func_0x4008c4d0 (channel 0, address 0xc,
 * 1-byte read, result returned through a pointer) and returns byte param_1 (0-3) of it: shift right by
 * `param_1 * 8`, mask to 8 bits. Ghidra shows a second parameter; the assembly never reads `%i1`, so it is omitted.
 */
extern void func_0x4008c4d0();

int FUN_a0133cbc(unsigned char param_1)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(0, 0xc, &local_c, 1);
    return (local_c >> (param_1 << 3)) & 0xff;
}
