/* leon2s FUN_a00a1098 @ 0xa00a1098 (-mcpu=v8 -Os -g)
 * The `(unsigned char)bVar2` cast should produce the `and %l0, 0xff, %g1` before the comparison.
 */
void FUN_a00a1098(unsigned int param_1, unsigned char param_2, unsigned int **param_3)
{
    unsigned int bVar2 = 0;
    
    if ((param_2 & 0xff) != 0) {
        do {
            if ((param_2 >> bVar2 & 1U) != 0) {
                if (*param_3 != 0) {
                    ((int (*)(unsigned int))*param_3)(param_1 & 0xff);
                }
            }
            param_3++;
            bVar2++;
        } while ((unsigned char)bVar2 < 8);
    }
}
