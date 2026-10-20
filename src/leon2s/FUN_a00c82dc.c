/* leon2s FUN_a00c82dc @ 0xa00c82dc  MATCH (-mcpu=v8 -Os -g)
 * This should produce:
 * - `and %i0, 0xff, %i0` for param_1 mask
 * - Set up args and call FUN_a00c8048
 * - Mask result, store in result variable (which becomes %g1)
 * - Compare with 0, branch if non-zero
 * - If zero, set up args and call FUN_a00c81f8
 * - Mask result and return it
 * - The return path for the non-zero case returns the already-masked result
 */
extern int FUN_a00c8048();
extern int FUN_a00c81f8();

unsigned char FUN_a00c82dc(unsigned char param_1, unsigned int param_2)
{
    unsigned char result;
    
    param_1 = param_1 & 0xff;
    result = (unsigned char)(FUN_a00c8048(param_1, 0x74, 0x41, 2) & 0xff);
    if (result != 0) {
        return result;
    }
    return (unsigned char)(FUN_a00c81f8(param_1, param_2, 2) & 0xff);
}
