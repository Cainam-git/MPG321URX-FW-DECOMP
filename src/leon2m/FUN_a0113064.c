/* leon2m FUN_a0113064 @ 0xa0113064  MATCH (-mcpu=v8 -O2 -g)
 * This function clears bits in two memory-mapped registers at 0xcf011800 and 0xcf011a00. If the input parameter is 0xff, it scans bits 0-4 of the original value from 0xcf011a00, calling the external function for each set bit and clearing that bit in both registers. Otherwise, it clears the bit corresponding to the input parameter in both registers. The function always returns 0. The loop structure and call ordering match the assembly; the main uncertainty is whether the return value is truly 0 or if the compiler is using a leftover register that Ghidra misidentified as a 64-bit return.
 */
extern int FUN_a011855c(void);
extern int func_0x4008e3c4(unsigned int, unsigned int);

#define REG_cf011800 (*(volatile unsigned int *)0xcf011800)
#define REG_cf011a00 (*(volatile unsigned int *)0xcf011a00)

void FUN_a0113064(unsigned char param_1)
{
    unsigned char uVar1;
    unsigned int uVar2;
    unsigned int uVar3;
    unsigned int uVar4;
    unsigned int uVar5;

    uVar1 = REG_cf011a00;
    FUN_a011855c();

    if (param_1 == 0xff) {
        uVar2 = 0;
        uVar3 = 0;
        do {
            uVar2 = uVar2 + 1;
            if (((uVar1 & 0xff) >> uVar3 & 1U) != 0) {
                func_0x4008e3c4(uVar3, 1);
                uVar4 = ~(1 << uVar3);
                REG_cf011800 = REG_cf011800 & uVar4;
                REG_cf011a00 = REG_cf011a00 & uVar4;
            }
            uVar3 = uVar2 & 0xff;
        } while (uVar3 < 5);
    } else {
        func_0x4008e3c4(param_1, 1);
        uVar5 = ~(1 << param_1);
        REG_cf011800 = REG_cf011800 & uVar5;
        REG_cf011a00 = REG_cf011a00 & uVar5;
    }

    return 0;
}
