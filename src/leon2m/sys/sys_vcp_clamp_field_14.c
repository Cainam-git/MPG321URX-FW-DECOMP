/* sys_vcp_clamp_field_14  (FUN_a00d40c8)
 *
 * Limit position field 0x14 of a channel to 63 and write it back.
 * Name basis: descriptive - sys_api_set_channel_position_field; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d40c8 @ 0xa00d40c8, flags -mcpu=v8 -O2 -g (section default).
 * Source form: a plain unsigned short clamp 'if (v > 0x3f) v = 0x3f'; unsigned char channel parameter and unsigned short
 * callee prototypes. Nothing calls it.
 */
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern void sys_api_set_channel_position_field(unsigned char, unsigned int, unsigned short, int);

#define POSITION_FIELD_14      0x14     /* field read and written back */
#define POSITION_FIELD_14_MAX  0x3f     /* 63: highest value kept */

/* Limit field 0x14 of channel ch to 63 and write it back. Nothing calls it. */
void sys_vcp_clamp_field_14(unsigned char ch)
{
    unsigned short value = input_api_get_timing_field(ch, POSITION_FIELD_14);

    if (value > POSITION_FIELD_14_MAX)
        value = POSITION_FIELD_14_MAX;
    sys_api_set_channel_position_field(ch, POSITION_FIELD_14, value, 1);
}
