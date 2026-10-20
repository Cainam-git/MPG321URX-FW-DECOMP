/* leon2m FUN_a00b344c @ 0xa00b344c  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a0146b50(0x1E5, 0), FUN_a0146b6c(2, 0) and FUN_a0146a80(0x37, 9, 4, 0x596, 0), then passes
 * FUN_a00a3844(0x1928B0, ((param_1 & 0xFF) * 29 + DAT_a802d298) & 0xFFFF) to FUN_a00a31a4(0, 0x37, 9, 4, value, 0).
 * param_1 is unsigned int; the explicit '& 0xff' produces 'and %i0, 0xff, %i0'.
 */
extern void FUN_a0146b50(unsigned int, unsigned int); /* 0xa0146b50 */
extern void FUN_a0146b6c(unsigned int, unsigned int); /* 0xa0146b6c */
extern void FUN_a0146a80(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); /* 0xa0146a80 */
extern unsigned int FUN_a00a3844(int, unsigned short); /* 0xa00a3844 */
extern void FUN_a00a31a4(int, int, int, int, unsigned int, int); /* 0xa00a31a4 */
extern unsigned char DAT_a802d298; /* 0xa802d298 */

void FUN_a00b344c(unsigned int param_1)
{
    unsigned int uVar1;
    unsigned short uVar2;

    FUN_a0146b50(0x1e5, 0);
    FUN_a0146b6c(2, 0);
    uVar1 = param_1 & 0xff;
    FUN_a0146a80(0x37, 9, 4, 0x596, 0);
    uVar2 = (uVar1 * 29 + DAT_a802d298) & 0xffff;
    uVar1 = FUN_a00a3844(0x1928b0, uVar2);
    FUN_a00a31a4(0, 0x37, 9, 4, uVar1, 0);
}
