/* leon2s FUN_a00ad644 @ 0xa00ad644 (-mcpu=v8 -Os -g)
 * This function reads a hardware register via the helper `FUN_a00a6bb8` (register block selected by byte-masked param_1, sub-register 0x44), masks the result with 3, and returns whether the masked value is non-zero (as 0 or 1). The `cmp %g0, %o0; addx %g0, 0, %i0` sequence confirms a boolean-returning comparison. The return value is a full word: the function ends with `ret; restore` leaving the comparison result in `%i0`.
 */
extern unsigned int FUN_a00a6bb8(unsigned int param_1, unsigned short param_2);

unsigned int FUN_a00ad644(unsigned int param_1)
{
    return (FUN_a00a6bb8(param_1 & 0xff, 0x44) & 3) != 0;
}
