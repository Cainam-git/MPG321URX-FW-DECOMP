/* sys_empty_function  (FUN_CODE_e551)
 *
 * Empty function: returns at once.
 * Name basis: proven - a single return instruction
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e551 @ 0xe551, OPTIMIZE(7,SPEED).
 */

/* Does nothing: the body is a single RET. Only caller: fwupd_svc_write_protect_off, before it switches the write
 * protection off. */
void sys_empty_function(void)
{
}
