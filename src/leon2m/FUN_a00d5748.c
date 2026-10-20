/* leon2m FUN_a00d5748 @ 0xa00d5748 (-mcpu=v8 -O2 -g)
 * Calls FUN_a0145508(1), then for n = 4, 0xB, 0xF and 0x14 in turn passes the result of FUN_a0145660(0, n),
 * truncated to 16 bits, to FUN_a0145808(0, n, value, 1). The last call is a
 * tail call (restore in the delay slot).
 */
extern int FUN_a0145508();
extern int FUN_a0145660();
extern void FUN_a0145808();

void FUN_a00d5748(void)
{
    unsigned short uVar1;

    FUN_a0145508(1);
    uVar1 = FUN_a0145660(0, 4);
    FUN_a0145808(0, 4, uVar1, 1);
    uVar1 = FUN_a0145660(0, 0xb);
    FUN_a0145808(0, 0xb, uVar1, 1);
    uVar1 = FUN_a0145660(0, 0xf);
    FUN_a0145808(0, 0xf, uVar1, 1);
    uVar1 = FUN_a0145660(0, 0x14);
    FUN_a0145808(0, 0x14, uVar1, 1);
    return;
}
