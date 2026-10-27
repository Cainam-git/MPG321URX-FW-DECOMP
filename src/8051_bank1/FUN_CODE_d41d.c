/* 8051_bank1 FUN_CODE_d41d @ 0xd41d..0xd44e (49 B)  Options: OPTIMIZE(8,SPEED) LARGE.
 * Clears the XDATA record at 0xA3E5: the byte 0xA3E7, the 16-bit words 0xA3E8, 0xA3E5 and 0xA3EA (in this order),
 * then the 32 unsigned long entries 0xA3EC + 4 i (i = 0..31, ?C?LSTKXDATA with an inline 0).
 * The record is one object (INC DPTR between its byte stores): int a (0xA3E5), byte b (0xA3E7), int c (0xA3E8),
 * int d (0xA3EA), unsigned long e[32] (0xA3EC..0xA46B).
 * No LCALL or LJMP to 0xD41D occurs in the bank-1 image.
 */
struct rec { unsigned int a; unsigned char b; unsigned int c; unsigned int d; unsigned long e[32]; };
extern struct rec xdata DAT_EXTMEM_a3e5;

void FUN_CODE_d41d(void)
{
    unsigned char i;

    DAT_EXTMEM_a3e5.b = 0;
    DAT_EXTMEM_a3e5.c = 0;
    DAT_EXTMEM_a3e5.a = 0;
    DAT_EXTMEM_a3e5.d = 0;
    for (i = 0; i < 0x20; i++) DAT_EXTMEM_a3e5.e[i] = 0;
}
