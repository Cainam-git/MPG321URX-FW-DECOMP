/* 8051_bank1 FUN_CODE_de12 @ 0xde12
 * bit: XDATA 0xA3EA (16 bit) == 0. 0xA3EA/0xA3EB is one unsigned int: FUN_CODE_38a7 writes it as R6:R7
 * (MOV A,R6 / MOVX / INC DPTR / MOV A,R7 / MOVX, e.g. 0x399d) and FUN_CODE_5c06 reads it into R4:R5 (0x5c6c).
 * Keil's int != 0 test is MOVX / JNZ to the low byte's JZ / INC DPTR / MOVX / JZ, which is the firmware's
 * 'JNZ de1a' into the second test that the two-char forms (a[0] || a[1]) could not give.
 * Callers 0x38ad (FUN_CODE_38a7), 0x5c56, 0x5c64, 0x5dc2 (FUN_CODE_5c06).
 * Options: OPTIMIZE(8,SPEED).
 */
extern unsigned int xdata DAT_EXTMEM_a3ea;
bit FUN_CODE_de12(void)
{
    if (DAT_EXTMEM_a3ea) return 0;
    return 1;
}
