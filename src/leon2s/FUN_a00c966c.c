/* leon2s FUN_a00c966c @ 0xa00c966c-0xa00c972c (48 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 * Code facts: byte local at [%fp-9] = 4. Loop 1: up to 10 times call FUN_a00c7bf8(port & 0xff) then
 * FUN_a0fc1794(10) while the result byte != 0. Loop 2: same with FUN_a00c8328(port & 0xff, &local)
 * and FUN_a0fc1794(10). Last result != 0 -> return 0; else return local != 4 ? 0x14 : 0x22
 * (fw: xor 4, cmp/subx = -(local != 4), and -14, add 0x22).
 * Fix vs the autoc draft: BEHAVIOUR bug, the 0x14/0x22 arms were swapped (draft returned 0x22 for != 4).
 * Written as "if (local == 4) return 0x22; return 0x14;" (the != form gives addx -1 / and 0xe).
 * Aids: none.
 */
extern unsigned char FUN_a00c7bf8(unsigned int param_1);
extern void FUN_a0fc1794(unsigned int param_1);
extern unsigned char FUN_a00c8328(unsigned int param_1, unsigned int param_2);

int FUN_a00c966c(unsigned int param_1)
{
    unsigned char local_9;
    unsigned char result;
    unsigned char count;
    
    local_9 = 4;
    count = 10;
    do {
        result = FUN_a00c7bf8(param_1 & 0xff);
        FUN_a0fc1794(10);
        count--;
    } while ((result != 0) && (count > 0));
    
    count = 10;
    do {
        result = FUN_a00c8328(param_1 & 0xff, (unsigned int)&local_9);
        FUN_a0fc1794(10);
        count--;
    } while ((result != 0) && (count > 0));
    
    if (result != 0) {
        return 0;
    }
    if (local_9 == 4) {
        return 0x22;
    }
    return 0x14;
}
