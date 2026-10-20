/* leon2s FUN_a00aeb6c @ 0xa00aeb6c  MATCH (-mcpu=v8 -Os, gcc 3.4.4, near)
 * near-miss repaired mechanically (tools/nearfix.py): already exact
 */
extern void FUN_a00ae1c0(unsigned int);
extern void FUN_a00a6c98();
extern int FUN_a00aeadc();
extern int FUN_a00aeb24();
extern unsigned char ARR_a8079310[];

void FUN_a00aeb6c(unsigned int param_1, unsigned int param_2)
{
    unsigned int uVar3;
    unsigned int uVar1;

    uVar3 = param_1 & 0xff;
    uVar1 = FUN_a00aeadc(uVar3);
    if ((uVar1 & 0xff) != 0) goto skip;
    if ((FUN_a00aeb24(uVar3) & 0xff) == 0) return;
skip:
    ARR_a8079310[uVar3] = 1;
    FUN_a00a6c98(uVar3, 0x30, 0x80, 1);
    FUN_a00a6c98(uVar3, 0x463, 1, 1);
    FUN_a00a6c98(uVar3, 0x463, 2, 1);
    FUN_a00a6c98(uVar3, 0x30, 0x80, 0);
    FUN_a00ae1c0(uVar3);
}
