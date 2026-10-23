/* 8051_bank1 FUN_CODE_8947 @ 0x8947..0x8A51 (266 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_8947(ch, b, v): loads five generic register pointers for ch from the CODE tables of 7 entries at
 * 0xB114, 0xB129, 0xB153, 0xB168, 0xB17D into XDATA 0xA6DF, 0xA6E2, 0xA6E5, 0xA6E8, 0xA6EB (e.g. ch 0: 0xF01C,
 * 0xF01D, 0xF15B, 0xF15D, 0xF15E), then writes 0xA0 to the first, 0xE8 to the second, 0 to the third, v to the
 * fourth when v is not 0, and XDATA 0xA6DE to the fifth when 0xA6DE is not 0. The second parameter b (R5) is not
 * used. No LCALL/LJMP to 0x8947 occurs in the bank-1 image.
 * Source form: 'b = b;' (the usual way to silence Keil's unreferenced-parameter warning) emits no code and keeps
 * Keil from storing b to its XDATA slot; without it the function starts with 'MOV DPTR,#slot / MOV A,R5 / MOVX'.
 * The CODE tables are declared with their size (7), which gives the 8-bit MUL AB index. The targets are hardware
 * registers (volatile).
 */
extern unsigned char volatile * code DAT_CODE_b114[7];
extern unsigned char volatile * code DAT_CODE_b129[7];
extern unsigned char volatile * code DAT_CODE_b153[7];
extern unsigned char volatile * code DAT_CODE_b168[7];
extern unsigned char volatile * code DAT_CODE_b17d[7];
extern unsigned char volatile * xdata DAT_EXTMEM_a6df;
extern unsigned char volatile * xdata DAT_EXTMEM_a6e2;
extern unsigned char volatile * xdata DAT_EXTMEM_a6e5;
extern unsigned char volatile * xdata DAT_EXTMEM_a6e8;
extern unsigned char volatile * xdata DAT_EXTMEM_a6eb;
extern unsigned char xdata DAT_EXTMEM_a6de;

void FUN_CODE_8947(unsigned char ch, unsigned char b, unsigned char v)
{
    b = b;
    DAT_EXTMEM_a6df = DAT_CODE_b114[ch];
    DAT_EXTMEM_a6e2 = DAT_CODE_b129[ch];
    DAT_EXTMEM_a6e5 = DAT_CODE_b153[ch];
    DAT_EXTMEM_a6e8 = DAT_CODE_b168[ch];
    DAT_EXTMEM_a6eb = DAT_CODE_b17d[ch];
    *DAT_EXTMEM_a6df = 0xa0;
    *DAT_EXTMEM_a6e2 = 0xe8;
    *DAT_EXTMEM_a6e5 = 0;
    if (v) *DAT_EXTMEM_a6e8 = v;
    if (DAT_EXTMEM_a6de) *DAT_EXTMEM_a6eb = DAT_EXTMEM_a6de;
}
