/* FUN_a00a93bc (leon2m, 0xa00a93bc-0xa00a9468, 172 bytes, 43 words).
 * Flags: -mcpu=v8 -O3 -g.
 * Code facts: base = (u8)(p*2 + 5); func_0x4008e2a4() twice; FUN_a0146c40(3, 0, 0); FUN_a00b3ed0(0, 0, 0, 0) (four
 * arguments: the fw sets only %o0..%o3 before that call); func_0x4008e2a4(); then for b = 0..2: v = (u16)(base +
 * b), FUN_a0146b20(0, 0x27, v, 1, 0, 0) and FUN_a0146b20(0, 0x34, v, 1, 0, 0).
 * Compiler aids: none.
 */
extern void FUN_a00b3ed0(unsigned char param_1, unsigned char param_2, unsigned int param_3, unsigned int param_4);
extern void FUN_a0146b20(unsigned char param_1, unsigned short param_2, unsigned short param_3, unsigned char param_4, unsigned char param_5, unsigned char param_6);
extern void FUN_a0146c40(unsigned int param_1, unsigned int param_2, unsigned int param_3);
extern int func_0x4008e2a4(void);

void FUN_a00a93bc(unsigned char param_1)
{
    unsigned char bVar;
    unsigned short uVar2;
    unsigned short uVar3;

    uVar3 = (unsigned short)((param_1 & 0xff) * 2 + 5);

    func_0x4008e2a4();
    func_0x4008e2a4();

    FUN_a0146c40(3, 0, 0);
    FUN_a00b3ed0(0, 0, 0, 0);

    func_0x4008e2a4();

    bVar = 0;
    do {
        uVar2 = (unsigned short)((unsigned short)(uVar3 & 0xff) + (unsigned short)bVar);
        FUN_a0146b20(0, 0x27, uVar2, 1, 0, 0);
        FUN_a0146b20(0, 0x34, uVar2, 1, 0, 0);
        bVar++;
    } while (bVar < 3);
}
