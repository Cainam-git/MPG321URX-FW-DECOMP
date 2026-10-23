/* leon2m FUN_a00e2cac @ 0xa00e2cac (-mcpu=v8 -O2 -g)
 * FUN_a00e05d8(p, 0x1e2, 1, 1); then polls FUN_a00e0514(p, 0x213, 1): a non-zero result restarts the count (no
 * limit); after six zero results returns (FUN_a00e02ec(p, 0x202) << 8) | FUN_a00e02ec(p, 0x201).
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
