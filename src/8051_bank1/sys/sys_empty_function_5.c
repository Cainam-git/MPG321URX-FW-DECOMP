/* sys_empty_function_5  (FUN_CODE_df17)
 *
 * Empty function: returns at once.
 * Name basis: proven - a single return instruction
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_df17 @ 0xdf17  OPTIMIZE(7,SPEED): the body is a single RET.
 */
/*
 * Does nothing and returns. Only caller: usb_cc_read_line_levels (third of three empty calls), which nothing calls.
 */
void sys_empty_function_5(void)
{
}
