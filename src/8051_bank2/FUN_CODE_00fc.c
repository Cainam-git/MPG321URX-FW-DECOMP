/* 8051_bank2 FUN_CODE_00fc @ 0x00fc  update agent: thin wrapper (built with OPTIMIZE(7,SPEED) LARGE;
 * at OPTIMIZE(7) Keil keeps LCALL + RET instead of a tail jump). Returns FUN_CODE_bcb3(). FUN_CODE_a8a3 (enter ISP)
 * calls it last, after clearing mailbox byte 0xF19A, and treats 0 as success. FUN_CODE_bcb3 sends the "region" command packet
 * over the service bus (src/8051_bank2/FUN_CODE_bcb3.c).
 */
unsigned char FUN_CODE_bcb3(void);
unsigned char FUN_CODE_00fc(void)
{
    return FUN_CODE_bcb3();
}
