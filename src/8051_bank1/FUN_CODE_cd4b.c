/* 8051_bank1 FUN_CODE_cd4b @ 0xcd4b (65 B)  Byte-exact with OPTIMIZE(8,SPEED).
 * Handles the request code returned by FUN_CODE_c4ee: 1 = "_SYS_CECRequest_PowerUp", 2 = "..._PowerDown",
 * 3 = "..._ActivateSC", 5 = "..._DeviceControl_Power"; each case prints its string with FUN_CODE_2820 (printf,
 * code strings at 0xB9F4 / 0xBA0E / 0xBA2A / 0xBA47). Cases 1 and 3 set bit 0x11 (BITS_22_1, the bit that
 * FUN_CODE_deb0 tests and clears); case 5 sets it only when FUN_CODE_dedc() (XDATA 0xA759) is 0x40. Other codes do
 * nothing. Only caller FUN_CODE_dc3b (0xDC4D). Keil tests the cases in the order 2, 3, 5, 1 and shares the
 * final LCALL of the four print calls.
 */
extern bit BITS_22_1;
extern unsigned char FUN_CODE_c4ee(void);
extern unsigned char FUN_CODE_dedc(void);
extern void FUN_CODE_2820(void *fmt, ...) large;   /* printf */

void FUN_CODE_cd4b(void)
{
    switch (FUN_CODE_c4ee()) {
    case 1:
        BITS_22_1 = 1;
        FUN_CODE_2820((void code *)0xb9f4 /* "_SYS_CECRequest_PowerUp\r\n" */);
        break;
    case 2:
        FUN_CODE_2820((void code *)0xba0e /* "_SYS_CECRequest_PowerDown\r\n" */);
        break;
    case 3:
        BITS_22_1 = 1;
        FUN_CODE_2820((void code *)0xba2a /* "_SYS_CECRequest_ActivateSC\r\n" */);
        break;
    case 5:
        if (FUN_CODE_dedc() == 0x40) BITS_22_1 = 1;
        FUN_CODE_2820((void code *)0xba47 /* "_SYS_CECRequest_DeviceControl_Power\r\n" */);
        break;
    }
}
