/* leon2m FUN_a00e02a0 @ 0xa00e02a0  MATCH (-mcpu=v8 -O2 -g)
 * Writes param_3 to base[param_1] + param_2, where base[] is a 3-entry local table of the register bases
 * 0xC0020000, 0xC0030000 and 0xC0040000 (stored at %sp+0x60..%sp+0x68). The final store is st [%g1 + %o1] with
 * %g1 = the selected base and %o1 = param_2.
 */
extern void FUN_a00e02a0(int param_1, int param_2, unsigned int param_3);

void FUN_a00e02a0(int param_1, int param_2, unsigned int param_3)
{
    unsigned int local_18[3];
    
    local_18[0] = 0xc0020000;
    local_18[1] = 0xc0030000;
    local_18[2] = 0xc0040000;
    
    *(unsigned int *)(local_18[param_1] + param_2) = param_3;
    return;
}
