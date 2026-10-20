/* leon2s FUN_a00b0568 @ 0xa00b0568  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern void FUN_a008442c(unsigned char param_1);
extern void FUN_a00abba8(void);
extern int FUN_a00ae3a0(unsigned char param_1);
extern void FUN_a00b0540(unsigned char param_1);
extern unsigned char ARR_a8079318[];

void FUN_a00b0568(unsigned char param_1)
{
    unsigned char bVar4;
    unsigned int uVar2;
    unsigned char uVar3;
    unsigned char uVar5;
    
    uVar5 = param_1;
    bVar4 = 0;
    if (ARR_a8079318[uVar5] != 0) {
        FUN_a00b0540(param_1);
        FUN_a00ae3a0(uVar5);
        FUN_a008442c(param_1);
        ARR_a8079318[uVar5] = 0;
        uVar3 = 0;
        uVar2 = 0;
        do {
            bVar4 = bVar4 | ARR_a8079318[uVar3];
            uVar3 = (uVar3 + 1) & 0xff;
            uVar2 = uVar3;
        } while (uVar2 <= 1);
        if (bVar4 == 0) {
            FUN_a00abba8();
            return uVar5;
        }
    }
    return uVar5;
}
