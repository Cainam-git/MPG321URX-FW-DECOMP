/* 8051_bank1 FUN_CODE_dc3b @ 0xdc3b  MATCH (OPTIMIZE(7,SPEED))
 * Calls FUN_CODE_df0f and the thunk at 0xDEFF, then FUN_CODE_cd4b when XDATA 0xA770 is 0 or 1. The extern name
 * thunk_FUN_CODE_deff makes the linker emit the LCALL operand 0xDEFF.
 */
extern void FUN_CODE_df0f(void);
extern void thunk_FUN_CODE_deff(void);
extern void FUN_CODE_cd4b(void);
extern unsigned char xdata DAT_EXTMEM_a770;

void FUN_CODE_dc3b(void)
{
    FUN_CODE_df0f();
    thunk_FUN_CODE_deff();
    if ((DAT_EXTMEM_a770 == 0x01) || (DAT_EXTMEM_a770 == 0x00)) {
        FUN_CODE_cd4b();
    }
}
