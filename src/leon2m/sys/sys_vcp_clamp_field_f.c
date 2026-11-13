/* sys_vcp_clamp_field_f  (FUN_a00d444c)
 *
 * Limit field 0x0F of a channel to field 0x12 and write it back.
 * Name basis: descriptive - reached through a table; no direct caller
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d444c @ 0xa00d444c, flags -mcpu=v8 -O2 -g.
 * No direct callers (reached through a table). Reads field 0xF, then field 0x12 once for the compare and a second time
 * for the value taken.
 */
extern unsigned short input_api_get_timing_field(unsigned char, int);
extern void sys_api_set_channel_position_field(unsigned char, int, unsigned short, int);

#define POSITION_FIELD_F       0x0f     /* the field that is limited */
#define POSITION_FIELD_F_MAX   0x12     /* the field that holds its upper limit */

/* Limit field 0x0F of channel ch to the value of field 0x12 and write it back. Reached through a table. */
void sys_vcp_clamp_field_f(unsigned char ch)
{
    unsigned short value = input_api_get_timing_field(ch, POSITION_FIELD_F);

    if (value > input_api_get_timing_field(ch, POSITION_FIELD_F_MAX))
        value = input_api_get_timing_field(ch, POSITION_FIELD_F_MAX);
    sys_api_set_channel_position_field(ch, POSITION_FIELD_F, value, 1);
}
