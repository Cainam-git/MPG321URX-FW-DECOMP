/* leon2m FUN_a00e2aec @ 0xa00e2aec  MATCH (-mcpu=v8 -O2 -g)
 * FUN_a00e05d8(param_1, 0x1C1, 1, 0), then polls FUN_a00e0514(param_1, 0x1E0, 1) until it has returned zero six
 * times in a row (a nonzero return restarts the count). Returns (FUN_a00e02ec(param_1, 0x1CF) << 8) |
 * FUN_a00e02ec(param_1, 0x1CE). The result is a single expression, which places the sll directly after the first
 * read, before the second call.
 */
/* 0xa00e2aec */
extern int FUN_a00e02ec(unsigned int, unsigned int);                    /* 0xa00e02ec */
extern int FUN_a00e0514(unsigned int, unsigned int, unsigned int);      /* 0xa00e0514 */
extern int FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int); /* 0xa00e05d8 */

unsigned int FUN_a00e2aec(unsigned int param_1, unsigned int param_2)
{
    unsigned int uVar1;
    int iVar3;

    FUN_a00e05d8(param_1, 0x1c1, 1, 0);
    do {
        iVar3 = 0;
        while (1) {
            uVar1 = FUN_a00e0514(param_1, 0x1e0, 1);
            iVar3 = iVar3 + 1;
            if (uVar1 != 0) break;
            if (5 < iVar3) {
                return (FUN_a00e02ec(param_1, 0x1cf) << 8) | FUN_a00e02ec(param_1, 0x1ce);
            }
        }
    } while (1);
}
