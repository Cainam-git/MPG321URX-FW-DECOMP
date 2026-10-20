/* 8051_bank2 FUN_CODE_e141 @ 0xe141
 * Tail call FUN_CODE_c60e(a, XDATA ulong 0x090B, XDATA ulong 0x07D5). c60e takes three unsigned longs: the first in
 * R4..R7 (c60e homes it at 0x092D), the second and third in its LARGE parameter block ?_FUN_CODE_c60e?BYTE+4 / +8
 * = XDATA 0x0931 / 0x0935. Keil evaluates a first and PUSHes R4..R7 while it stores the other two (?C?LSTXDATA 0x34e1),
 * then POPs and LJMPs: the firmware's PUSH/POP pair. (A form that stores 0x0931 / 0x0935 as globals reaches 86.4 %.)
 * Same pattern in bank 1 FUN_CODE_d3b9 / d3eb (PUSH R6/R7 = first arg 0xA800).
 * Only caller 0xad86 (in FUN_CODE_ad56's real span; it loads ulong XDATA 0x0152 into R4..R7).
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE ONLY (SMALL 39 %; MATCH exact None 59/59).
 */
extern unsigned long xdata DAT_EXTMEM_090b, DAT_EXTMEM_07d5;
void FUN_CODE_c60e(unsigned long a, unsigned long b, unsigned long c);
void FUN_CODE_e141(unsigned long a)
{
    FUN_CODE_c60e(a, DAT_EXTMEM_090b, DAT_EXTMEM_07d5);
}
