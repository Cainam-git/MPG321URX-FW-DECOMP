/* sys_is_channel_value_below_default  (FUN_a013d198)
 *
 * Return whether a channel value is below the default of the ROM row.
 * Returns: 0 or 1
 * Name basis: descriptive - halfword 0xA802DF84 against the ROM default row
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013d198 @ 0xa013d198 (-mcpu=v8 -O3 -g)
 * Source form: the result type is unsigned char (it was the decompiler's bool); the two halfwords are
 * unsigned short.
 */
extern unsigned short panel_default_row_active_lines;
extern unsigned short channel_records_half_0x54;

/* Return 1 when the halfword at +0x54 of the first channel record is smaller than the halfword at +0x0a
 * of the default row in ROM (0x001A30DA), else 0. */
unsigned char sys_is_channel_value_below_default(void)

{
  return channel_records_half_0x54 < panel_default_row_active_lines;
}
