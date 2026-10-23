/* 8051_bank1 thunk_FUN_CODE_568f @ 0xdeff (3 bytes)
 * OPTIMIZE(8,SPEED).
 * Caller: FUN_CODE_dc3b (LCALL at 0xDC3E). Calls FUN_CODE_568f with no arguments (568f reads no register on entry). At OPTIMIZE(8) Keil turns the final call into a tail jump, so the whole
 * function is one LJMP 0x568F.
 */
extern void FUN_CODE_568f(void);

void thunk_FUN_CODE_568f(void)
{
    FUN_CODE_568f();
}
