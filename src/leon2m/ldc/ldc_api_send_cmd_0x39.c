/* ldc_api_send_cmd_0x39  (FUN_a01438a8)
 *
 * Send dimming command 0x39 with two 16-bit values.
 * Name basis: descriptive - tail call to the mailbox portal 2 sender; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01438a8 @ 0xa01438a8, flags -mcpu=v8 -O2 -g.
 * Source form: a one-line forward; the firmware makes it a tail call (the caller's return address is handed on)
 * with both arguments masked to 16 bits, followed by the nop that belongs to such a call sequence. The first
 * parameter is an unsigned short (the firmware masks it with sll / srl 16) although ldc_send_adim_level_and_percent takes it as
 * an unsigned int.
 */
extern void ldc_send_adim_level_and_percent(unsigned int percent, unsigned short value);

/*
 * Forward percent and value to ldc_send_adim_level_and_percent (set ADIM_BrighPercent and usUserADIM in one command).
 * Nothing in the firmware calls it and no stored address points at it.
 */
void ldc_api_send_cmd_0x39(unsigned short percent, unsigned short value)
{
    ldc_send_adim_level_and_percent(percent, value);
}
