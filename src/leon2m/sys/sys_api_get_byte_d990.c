/* sys_api_get_byte_d990  (FUN_a0143fe4)
 *
 * Return the byte at 0xA802D990.
 * Returns: byte
 * Name basis: descriptive - plain getter; unused
 *
 * Matching notes
 * --------------
 * FUN_a0143fe4 (leon2m 0xa0143fe4-0xa0143ff0, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Nothing in the image refers to this routine. Source form: a direct read of the extern symbol (sethi %hi +
 * load with the %lo offset in the retl delay slot).
 */
extern unsigned char sys_event_code_byte;

/* Return the byte at 0xA802D990. Nothing calls this routine. */
unsigned char sys_api_get_byte_d990(void)
{
    return sys_event_code_byte;
}
