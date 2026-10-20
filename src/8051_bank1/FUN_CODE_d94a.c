/* 8051_bank1 FUN_CODE_d94a @ 0xd94a
 * Consistent read of the 16-bit IDATA int 0x57: copy it to IDATA 0x59 until the copy equals 0x57 again (the 8051
 * reads the two bytes one by one), then return the copy (R6:R7).
 * volatile is real on 0x57: it is read again for the compare (XRL A,@R0 against 0x58 / 0x57). 0x59 is not volatile:
 * Keil keeps it in R6:R7 for the compare and the return. Without the return value (void forms) or with 0x59
 * volatile Keil keeps 0x57 in R6:R7 instead (45..61 %). FUN_CODE_d44e uses the uint result.
 * 35 call sites in: 42f6 4ec1 5091 50c9 568f 5a39 65e9 7b5a 9caa a1fe a57e bf7b c830 d44e dd41 
 * Byte-exact with OPTIMIZE(8,SPEED) (MATCH exact None 31/31).
 */
extern unsigned int volatile idata DAT_INTMEM_57;
extern unsigned int idata DAT_INTMEM_59;
unsigned int FUN_CODE_d94a(void)
{
    do DAT_INTMEM_59 = DAT_INTMEM_57; while (DAT_INTMEM_59 != DAT_INTMEM_57);
    return DAT_INTMEM_59;
}
