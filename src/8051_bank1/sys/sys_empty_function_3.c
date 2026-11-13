/* sys_empty_function_3  (FUN_CODE_df14)
 *
 * Empty function: returns at once.
 * Name basis: proven - a single return instruction
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_df14 @ 0xdf14  OPTIMIZE(7,SPEED): the body is a single RET.
 */
/*
 * Does nothing and returns. Only caller: usb_cc_read_line_levels (first of three empty calls), which nothing calls.
 */
void sys_empty_function_3(void)
{
}
