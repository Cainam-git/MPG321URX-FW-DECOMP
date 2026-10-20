/* leon2m FUN_a0137724 @ 0xa0137724  MATCH (-mcpu=v8 -O2 -g)
 * The function calls a function at 0x4008c4d0 with arguments (1, 12, pointer to local variable, 1), then returns bits 6-7 of the result stored in that local variable. The parameters `param_1` and `param_2` from Ghidra are unused and should be dropped. The return is simply `(local_c >> 6) & 3` — no need for the 64-bit CONCAT44 construct since the function returns int.
 */
extern int func_0x4008c4d0();

int FUN_a0137724(void)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(1, 0xc, &local_c, 1);
    return (local_c >> 6) & 3;
}
