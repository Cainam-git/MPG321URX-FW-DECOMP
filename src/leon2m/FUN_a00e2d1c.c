/* leon2m FUN_a00e2d1c @ 0xa00e2d1c  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a00e05d8(param_1, 0x216, 1, 1), then polls FUN_a00e0514(param_1, 0x23b, 1) until it returns 0 six
 * times in a row (a non-zero result restarts the count). Returns (FUN_a00e02ec(param_1, 0x227) << 8) |
 * FUN_a00e02ec(param_1, 0x226). Twin of FUN_a00e2c3c with other register numbers; param_2 is unused.
 *
 * The return value is written as a single expression, so the first result is shifted (sll %o0, 8, %i0) before the
 * second call as in the target.
 */
extern unsigned int FUN_a00e02ec(unsigned int, unsigned int); /* 0xa00e02ec */
extern unsigned int FUN_a00e0514(unsigned int, unsigned int, unsigned int); /* 0xa00e0514 */
extern unsigned int FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int); /* 0xa00e05d8 */

unsigned int FUN_a00e2d1c(unsigned int param_1, unsigned int param_2)
{
    unsigned int uVar1;
    int iVar3;

    FUN_a00e05d8(param_1, 0x216, 1, 1);
    do {
        iVar3 = 0;
        while (1) {
            uVar1 = FUN_a00e0514(param_1, 0x23b, 1);
            iVar3 = iVar3 + 1;
            if (uVar1 != 0) break;
            if (5 < iVar3) {
                return (FUN_a00e02ec(param_1, 0x227) << 8) | FUN_a00e02ec(param_1, 0x226);
            }
        }
    } while (1);
}
