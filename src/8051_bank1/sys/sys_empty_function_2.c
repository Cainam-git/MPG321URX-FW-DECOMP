/* sys_empty_function_2  (FUN_CODE_df0f)
 *
 * Empty function: returns at once.
 * Name basis: proven - a single return instruction
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_df0f @ 0xdf0f  OPTIMIZE(7,SPEED): the body is a single RET.
 */
/*
 * Does nothing and returns. Only caller: sys_service_ddc_and_cec, as its first step on every call.
 */
void sys_empty_function_2(void)
{
}
