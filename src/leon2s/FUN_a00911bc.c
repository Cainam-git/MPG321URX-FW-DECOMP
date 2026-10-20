/* leon2s FUN_a00911bc @ 0xa00911bc  MATCH (-mcpu=v8 -Os -g)
 * The function takes an input, masks it to 0/1, calls FUN_a0074f60, then checks a byte at `0xa807cc64 + param_1*24 + 4`; if non-zero, it shifts the call result left by 2 and returns it as a 16-bit value. The key fix is declaring the array at the exact base address `0xa807cc64` and using the `+4` offset to match the target's `ldub [%g1 + 4]`.
 */
extern int FUN_a0074f60();
extern unsigned char ARR_a807cc64[];

unsigned short FUN_a00911bc(unsigned int param_1)
{
    unsigned int uVar1;
    
    param_1 = param_1 & 1;
    uVar1 = FUN_a0074f60(param_1);
    if (ARR_a807cc64[param_1 * 24 + 4] != 0) {
        uVar1 = uVar1 << 2;
    }
    return (unsigned short)uVar1;
}
