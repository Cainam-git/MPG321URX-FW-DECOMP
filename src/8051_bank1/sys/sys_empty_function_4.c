/* sys_empty_function_4  (FUN_CODE_df16)
 *
 * Empty function: returns at once.
 * Name basis: proven - a single return instruction
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_df16 @ 0xdf16  OPTIMIZE(7,SPEED): the body is a single RET.
 */
/*
 * Does nothing and returns. Only caller: usb_cc_read_line_levels (second of three empty calls), which nothing calls.
 */
void sys_empty_function_4(void)
{
}
