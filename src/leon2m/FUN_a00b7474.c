/* leon2m FUN_a00b7474 @ 0xa00b7474 (-mcpu=v8 -O2 -g)
 * The function performs a fixed sequence of initialization calls, then reads a byte from a global address, passes it through `FUN_a00a3844`, and uses the result as an argument to `FUN_a00a31a4`. Finally it tail-calls `FUN_a00b34d4` with the first two arguments replaced by constants 3 and 5, and the remaining original parameters unchanged. The main uncertainty is whether the compiler will schedule the assignments of those constants into the delay slots of earlier calls exactly as in the target; the provided C relies on the optimizer to do so, as the original Ghidra output did.
 */
extern unsigned char DAT_a802d298;
extern int FUN_a00a31a4();
extern int FUN_a00a3844();
extern int FUN_a00a8c88();
extern void FUN_a00a9468();
extern int FUN_a00aba34();
extern int FUN_a00abc64();
extern int FUN_a00abe94();
extern int FUN_a00b34d4();
extern int FUN_a00b72cc();
extern void FUN_a0146a80();
extern void FUN_a0146b50();
extern void FUN_a0146b6c();

void FUN_a00b7474(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    FUN_a00a8c88();
    FUN_a00abe94(1);
    FUN_a00abc64(0);
    FUN_a00aba34(0);
    FUN_a00b72cc();
    FUN_a00a9468(2,0);
    FUN_a00a9468(0,1);
    FUN_a00a9468(1,3);
    FUN_a0146b50(0x1e5,0);
    FUN_a0146b6c(2,0);
    FUN_a0146a80(0x37,9,4,0x596,0);
    FUN_a00a31a4(0,0x37,9,4, FUN_a00a3844(0x1928b0, DAT_a802d298), 0);
    FUN_a00b34d4(3,5,param_3,param_4,param_5,param_6);
}
