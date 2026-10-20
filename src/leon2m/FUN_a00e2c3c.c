/* leon2m FUN_a00e2c3c @ 0xa00e2c3c (-mcpu=v8 -O2 -g)
 * Calls FUN_a00e05d8(param_1, 0x1c1, 1, 1), then polls FUN_a00e0514(param_1, 0x1e0, 1) until it returns 0 six
 * times in a row (a non-zero result restarts the count). Returns (FUN_a00e02ec(param_1, 0x1cf) << 8) |
 * FUN_a00e02ec(param_1, 0x1ce). Twin of FUN_a00e2d1c with other register numbers.
 *
 * The return value is written as a single expression, so the shift of the first result is emitted before the
 * second call as in the target.
 */
extern int FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00e0514(unsigned int, unsigned int, unsigned int);
extern int FUN_a00e02ec(unsigned int, unsigned int);

unsigned int FUN_a00e2c3c(unsigned int param_1)
{
    unsigned int uVar1;
    int iVar3;

    FUN_a00e05d8(param_1, 0x1c1, 1, 1);
    do {
        iVar3 = 0;
        while (1) {
            uVar1 = FUN_a00e0514(param_1, 0x1e0, 1);
            iVar3++;
            if (uVar1 != 0)
                break;
            if (5 < iVar3) {
                return (FUN_a00e02ec(param_1, 0x1cf) << 8) |
                       FUN_a00e02ec(param_1, 0x1ce);
            }
        }
    } while (1);
}
