/* ldc_api_send_cmd_0x34  (FUN_a0143890)
 *
 * Send dimming command 0x34 with a 16-bit value.
 * Name basis: descriptive - tail call to the mailbox portal 2 sender; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0143890 @ 0xa0143890, flags -mcpu=v8 -O2 -g.
 * Source form: a one-line forward; the firmware makes it a tail call (the caller's return address is handed on),
 * followed by the nop that belongs to such a call sequence.
 */
extern void ldc_send_adim_min(unsigned short);

/* Forward value to ldc_send_adim_min (set ADIM_Min). Nothing in the firmware calls it and no stored address points at it. */
void ldc_api_send_cmd_0x34(unsigned short value)
{
    ldc_send_adim_min(value);
}
