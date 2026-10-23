/* 8051_bank2 FUN_CODE_e141 @ 0xe141
 * Tail call FUN_CODE_c60e(a, b, XDATA ulong 0x07D5). Both functions take unsigned long parameters: e141's a comes in
 * R4..R7, b in e141's LARGE parameter block ?_FUN_CODE_e141?BYTE+4 = XDATA 0x090B (the only caller, 0xad86 in
 * FUN_CODE_ad56, stores 0x200 there with ?C?LSTKXDATA and loads ulong XDATA 0x0152 into R4..R7). c60e's second
 * and third parameters go to its block ?_FUN_CODE_c60e?BYTE+4 / +8 = XDATA 0x0931 / 0x0935. Keil keeps a on the
 * stack (PUSH R4..R7) while it copies b and the third value with ?C?LSTXDATA, then POPs and LJMPs.
 * Same pattern in bank 1 FUN_CODE_d3b9 / d3eb (PUSH R6/R7 = first arg 0xA800). Compiled OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned long xdata DAT_EXTMEM_07d5;
void FUN_CODE_c60e(unsigned long a, unsigned long b, unsigned long c);
void FUN_CODE_e141(unsigned long a, unsigned long b)
{
    FUN_CODE_c60e(a, b, DAT_EXTMEM_07d5);
}
