/* FUN_a00afbbc (leon2s, 0xa00afbbc-0xa00afd04, 328 bytes, 82 words).
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: port = (u8)param_1; FUN_a00a6c00(port, 0x2f, 0x30); FUN_a00a6c00(port, 0xf7, 0);
 * FUN_a00ab6e0(port, u16 field +0x120 of the 300-byte port record ARR_a807dc18[port], 1);
 * FUN_a00a6c98(port, 0xc2, 4, 1) and (.., 8, 1); when (u8)FUN_a008d800() > 0x81 set bit 4 of the
 * hardware word 0xcf011758; FUN_a00abff0, FUN_a00ac66c, FUN_a00af98c (port); FUN_a00aba5c(port, 1, 1, 0)
 * when byte +0x11f of the record is 1; FUN_a00ab884(port, 0); regs 0xc5 = 4, 0xc4 = 0x55; clears
 * bits port and port+4 of DAT_a8079372; regs 0x51 = 0xa0 and (tail) 0x23 = 0x40.
 * Fix vs draft: the record is ARR_a807dc18 as a 300-byte struct (the draft used
 * the mid-record name ARR_a807dd38 with byte offsets, which splits the address arithmetic).
 * Aids: none (volatile only on the 0xcf011758 hardware register).
 */
extern unsigned char DAT_a8079372;
extern unsigned int DAT_a807dd37;
#define _DAT_cf011758 (*(volatile unsigned int *)0xcf011758)
extern int FUN_a008d800();
extern void FUN_a00a6c00(unsigned int, unsigned short, unsigned int);
extern void FUN_a00a6c98(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00ab6e0(unsigned int, unsigned short, unsigned int);
extern void FUN_a00ab884(unsigned int, unsigned int);
extern void FUN_a00aba5c(unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00abff0(unsigned int);
extern int FUN_a00ac66c(unsigned int);
extern int FUN_a00af98c(unsigned int);
struct Port { unsigned char pad[0x11f]; unsigned char b11f; unsigned short h120; unsigned char pad2[300 - 0x122]; };
extern struct Port ARR_a807dc18[];

void FUN_a00afbbc(unsigned char param_1)
{
    unsigned int uVar2;
    unsigned int local_result;

    uVar2 = param_1 & 0xff;
    FUN_a00a6c00(uVar2, 0x2f, 0x30);
    FUN_a00a6c00(uVar2, 0xf7, 0);
    FUN_a00ab6e0(uVar2, ARR_a807dc18[uVar2].h120, 1);
    FUN_a00a6c98(uVar2, 0xc2, 4, 1);
    FUN_a00a6c98(uVar2, 0xc2, 8, 1);
    local_result = FUN_a008d800();
    if ((local_result & 0xff) > 0x81) {
        _DAT_cf011758 = _DAT_cf011758 | 0x10;
    }
    FUN_a00abff0(uVar2);
    FUN_a00ac66c(uVar2);
    FUN_a00af98c(uVar2);
    if (ARR_a807dc18[uVar2].b11f == 1) {
        FUN_a00aba5c(uVar2, 1, 1, 0);
    }
    FUN_a00ab884(uVar2, 0);
    FUN_a00a6c00(uVar2, 0xc5, 4);
    FUN_a00a6c00(uVar2, 0xc4, 0x55);
    DAT_a8079372 = DAT_a8079372 & ~(1 << param_1) & ~(0x10 << param_1);
    FUN_a00a6c00(uVar2, 0x51, 0xa0);
    FUN_a00a6c00(uVar2, 0x23, 0x40);
}
