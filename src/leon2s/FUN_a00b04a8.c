/* leon2s FUN_a00b04a8 @ 0xa00b04a8  MATCH (-mcpu=v8 -Os -g)
 * For port p = param_1 & 0xFF, fills four halfwords of p's 300-byte record in the table at 0xA807DC18 from
 * FUN_a00a6da8(p, reg): reg 0x94 -> +0x100, reg 0x96 -> +0x108, reg 0x98 -> +0x106 and reg 0x9A -> +0x10E, the last
 * two masked to 15 bits (0x7FFF). Returns nothing (ret; restore).
 */
extern int FUN_a00a6da8(int, int);
extern unsigned short DAT_a807dc18[];

void FUN_a00b04a8(unsigned int param_1)
{
    unsigned int uVar3;
    unsigned int uVar2;
    unsigned short *base;

    uVar3 = param_1 & 0xff;
    base = &DAT_a807dc18[uVar3 * 150];  // 300 bytes / 2 = 150 halfwords
    uVar2 = FUN_a00a6da8(uVar3, 0x94);
    base[0x80] = (unsigned short)uVar2;  // +0x100
    uVar2 = FUN_a00a6da8(uVar3, 0x96);
    base[0x84] = (unsigned short)uVar2;  // +0x108
    uVar2 = FUN_a00a6da8(uVar3, 0x98);
    base[0x83] = (unsigned short)(uVar2 & 0x7fff);  // +0x106
    uVar2 = FUN_a00a6da8(uVar3, 0x9a);
    base[0x87] = (unsigned short)(uVar2 & 0x7fff);  // +0x10e
}
