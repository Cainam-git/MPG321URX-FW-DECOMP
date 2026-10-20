/* 8051_bank1 FUN_CODE_def4 @ 0xdef4  MATCH (OPTIMIZE(7,SPEED))
 * Calls FUN_CODE_dcf6, then FUN_CODE_d987. The second call is emitted as a tail jump (LCALL followed by LJMP). No
 * parameters or return value.
 */
extern void FUN_CODE_dcf6(void);
extern void FUN_CODE_d987(void);

void FUN_CODE_def4(void)
{
    FUN_CODE_dcf6();
    FUN_CODE_d987();
}
