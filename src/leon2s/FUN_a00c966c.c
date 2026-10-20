/* leon2s FUN_a00c966c @ 0xa00c966c-0xa00c972c (48 words), flags -mcpu=v8 -Os -g.
 * Byte local at [%fp-9] = 4. Loop 1: up to 10 times calls FUN_a00c7bf8(port & 0xff) then FUN_a0fc1794(10)
 * while the result byte != 0. Loop 2: the same with FUN_a00c8328(port & 0xff, &local) and FUN_a0fc1794(10).
 * Last result != 0 -> returns 0; else returns 0x22 when local == 4, else 0x14 (firmware: xor 4, cmp/subx =
 * -(local != 4), and -14, add 0x22).
 * Source form: "if (local == 4) return 0x22; return 0x14;" (the != form gives addx -1 / and 0xe).
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
