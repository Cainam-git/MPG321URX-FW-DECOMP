/* leon2m FUN_a00b37a4 @ 0xa00b37a4  MATCH (-mcpu=v8 -O2 -g)
 * The `i - 1` is computed in the delay slot of the `be,a`, so it's `i` (the old value) minus 1. Since `i` hasn't been incremented yet when the break happens, `i-1` is correct. When the loop exits normally, `i` has been incremented, so `i-1` gives the last valid index.
 */
extern int FUN_a00d8b38(void); /* 0xa00d8b38 */
extern void FUN_a01577f4(unsigned char *, unsigned int, unsigned short); /* 0xa01577f4 */
extern void FUN_a0146b6c(int, int); /* 0xa0146b6c */
extern void FUN_a0146b50(int, int); /* 0xa0146b50 */
extern void FUN_a0146a80(int, int, int, int, int); /* 0xa0146a80 */
extern void FUN_a00a31a4(int, int, int, int, unsigned char *, int); /* 0xa00a31a4 */

void FUN_a00b37a4(void)
{
    unsigned char local_18[16];
    unsigned int uVar2;
    unsigned char i;
    unsigned char bVar3;

    uVar2 = FUN_a00d8b38();
    FUN_a01577f4(local_18, 0x1981d8, (unsigned short)uVar2);

    i = 0;
    do {
        if (local_18[i & 0xff] == 0)
            break;
        i++;
        bVar3 = (unsigned char)i;
    } while (bVar3 <= 0xf);

    local_18[0] = i - 1;
    FUN_a0146b6c(2, 0);
    FUN_a0146b50(0x1b5, 0);
    FUN_a0146a80(0xe, 2, 8, 0x596, 0);
    FUN_a00a31a4(0, 0xe, 2, 8, local_18, 0);
}
