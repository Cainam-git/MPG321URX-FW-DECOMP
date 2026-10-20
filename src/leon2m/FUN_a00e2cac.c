/* leon2m FUN_a00e2cac @ 0xa00e2cac  MATCH (-mcpu=v8 -O2 -g)
 * The function polls a status/flag through `FUN_a00e0514` up to six times; if any poll returns nonzero it restarts the count. After six consecutive zero polls it reads two values through `FUN_a00e02ec` and returns `(value_at_0x202 << 8) | value_at_0x201`. The only change from the provided Ghidra C is forcing the first read's shift to happen before the second read by storing the shifted result in `uVar2` first, matching the target's `sll %o0, 8, %i0` placement.
 */
extern int FUN_a00e05d8(int, int, int, int);       /* 0xa00e05d8 */
extern unsigned int FUN_a00e0514(int, int, int);   /* 0xa00e0514 */
extern unsigned int FUN_a00e02ec(int, int);        /* 0xa00e02ec */

unsigned int FUN_a00e2cac(unsigned int param_1)
{
    unsigned int uVar1;
    unsigned int uVar2;
    int iVar3;

    FUN_a00e05d8(param_1, 0x1e2, 1, 1);
    do {
        iVar3 = 0;
        while (1) {
            uVar1 = FUN_a00e0514(param_1, 0x213, 1);
            iVar3++;
            if (uVar1 != 0)
                break;
            if (iVar3 > 5) {
                uVar2 = FUN_a00e02ec(param_1, 0x202) << 8;
                uVar1 = FUN_a00e02ec(param_1, 0x201);
                return uVar2 | uVar1;
            }
        }
    } while (1);
}
