/* ipc_api_get_status_field  (FUN_a014ba68)
 *
 * Return the 2-bit status field of the input processor's mailbox word 0 as 0..3.
 * Returns: 0..3
 * Note: The arm for any other value gives 4; ipc_get_status_field returns two bits, so it is never taken.
 * Name basis: descriptive - maps the result of ipc_get_status_field (bits 1 and 2 of portal 1 word 0) 0..3 to
 *   itself; many callers in the menu code
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014ba68 @ 0xa014ba68-0xa014bac4 (23 words), flags -mcpu=v8 -O3 -g (-Os gives other code).
 * Source form: a plain switch with an unsigned char result; the compiler builds a signed case tree rooted at 1.
 */
extern unsigned char ipc_get_status_field(void);

/*
 * Return the status field of the input processor's mailbox portal (bits 1 and 2 of word 0, read by
 * ipc_get_status_field) as 0 to 3. Any other value would give 4; the field has two bits, so that case does
 * not occur. Callers include sys_user_apply_dimming_mode.
 */
unsigned char ipc_api_get_status_field(void)
{
  unsigned char field;

  switch (ipc_get_status_field()) {
  case 0:
    field = 0;
    break;
  case 1:
    field = 1;
    break;
  case 2:
    field = 2;
    break;
  case 3:
    field = 3;
    break;
  default:
    field = 4;
    break;
  }
  return field;
}
