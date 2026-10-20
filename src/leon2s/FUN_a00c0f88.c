/* leon2s FUN_a00c0f88 @ 0xa00c0f88 (-mcpu=v8 -Os)
 */
extern int func_0xa0fb657c(int, int); // 0xa0fb657c
extern int func_0xa0fb65c4(int, int, int); // 0xa0fb65c4
extern unsigned char DAT_a8078620[]; // 0xa8078620

void FUN_a00c0f88(unsigned int param_1, unsigned char *param_2, unsigned char *param_3, int param_4, unsigned char *param_5)
{
    unsigned int uVar3;
    unsigned short uVar2;
    int ret_val;

    uVar3 = param_1 & 0xff;
    func_0xa0fb65c4(uVar3, 0x310, 0x21);
    uVar2 = 0;
    do {
        func_0xa0fb65c4(uVar3, 0x312, param_2[uVar2]);
        uVar2 = uVar2 + 1;
    } while (uVar2 <= 0xf);
    ret_val = func_0xa0fb657c(uVar3, 0x309);
    { unsigned char v = (ret_val & ~3) | 1; ret_val = v & 0xfd; }
    func_0xa0fb65c4(uVar3, 0x309, ret_val);
    uVar2 = 0;
    do {
        func_0xa0fb65c4(uVar3, 0x30b, param_3[uVar2]);
        uVar2 = uVar2 + 1;
    } while (uVar2 <= 0x209);
    func_0xa0fb65c4(uVar3, 0x310, 0x2d);
    uVar2 = 0;
    do {
        func_0xa0fb65c4(uVar3, 0x312, DAT_a8078620[uVar2]);
        uVar2 = uVar2 + 1;
    } while (uVar2 <= 0xa);
    func_0xa0fb65c4(uVar3, 0x310, 0x20);
    uVar2 = 0;
    do {
        func_0xa0fb65c4(uVar3, 0x312, param_5[uVar2]);
        uVar2 = uVar2 + 1;
    } while (uVar2 <= 0x13f);
}
