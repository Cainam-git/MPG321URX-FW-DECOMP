/* leon2s FUN_a009dfa8 @ 0xa009dfa8 (-mcpu=v8 -Os -g)
 * For p = param_1 & 0xFF: q = word 8 (offset +0x20) of p's 52-byte record in the array at 0xA807DB00 (a pointer)
 * and s = the byte ARR_a80790a8[p]. Returns ((q[+0x50] << s) / ((q[+0x54] >> 2) << s)) & 0xFFFF, or 0 when the
 * divisor is 0. The index ARR_a807db00[p * 13 + 8] gives the firmware's smul %o0, 0x34 followed by
 * ld [%o5 + 0x20]; the divisor test is a compare with 0 and a branch around the division.
 */
extern unsigned char ARR_a80790a8[];
extern unsigned int ARR_a807db00[];

unsigned short FUN_a009dfa8(unsigned int param_1)
{
    unsigned int uVar2;
    unsigned int uVar4;
    unsigned int iVar3;
    unsigned char bVar1;
    
    param_1 &= 0xff;
    iVar3 = ARR_a807db00[param_1 * 13 + 8];
    bVar1 = ARR_a80790a8[param_1];
    uVar4 = (*(unsigned int *)(iVar3 + 0x54) >> 2) << bVar1;
    uVar2 = 0;
    if (uVar4 != 0) {
        uVar2 = (*(unsigned int *)(iVar3 + 0x50) << bVar1) / uVar4;
    }
    return uVar2 & 0xffff;
}
