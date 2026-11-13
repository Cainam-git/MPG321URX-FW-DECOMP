/* pq_api_set_two_bit_option  (FUN_a01492f0)
 *
 * Store an option 0..3 and write it to both 2-bit fields of the control byte.
 * Name basis: descriptive - stSysConfig byte +6; fields at bits 2-3 and 4-5 of the byte at 0xA802C9B0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01492f0 @ 0xa01492f0-0xa014931c (11 words), flags -mcpu=v8 -O3 -g.
 * Source form: old-style (K&R) definition: the option arrives as an int, is stored unmasked and masked for the
 * first call; the second call reads the stored byte back and is a tail call.
 */

/* The system configuration record, up to the field used here. */
struct sys_config_record {
    unsigned char pad[6];
    unsigned char option_byte;          /* +6 */
};
extern struct sys_config_record sys_config;
extern void osd_set_option_field(unsigned int, unsigned char);

#define OPTION_FIELD_FIRST  0           /* bits 2..3 of osd_option_byte */
#define OPTION_FIELD_SECOND 1           /* bits 4..5 */

/*
 * Store the option in sys_config byte +6 and write it to both 2-bit fields of osd_option_byte.
 * The only caller, osd_user_apply_menu_option, passes the user's option 0..3 (settings byte +6).
 */
void pq_api_set_two_bit_option(option)
    unsigned char option;
{
    sys_config.option_byte = option;
    osd_set_option_field(option, OPTION_FIELD_FIRST);
    osd_set_option_field(sys_config.option_byte, OPTION_FIELD_SECOND);
}
