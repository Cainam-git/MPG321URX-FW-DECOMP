/* sys_api_set_flag_e403  (FUN_a014a820)
 *
 * Store 0 or 1 in the flag byte at stSysConfig +0x33.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a820 @ 0xa014a820-0xa014a860 (16 words), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with the cases 0 and 1 and a default case that both store 1; an if/else chain gives other
 * code.
 */
extern unsigned char sys_config_byte_0x33;

/*
 * Store the flag byte at +0x33 of the system configuration record: 0 for 0, 1 for any other value.
 *
 *   value  the new flag
 */
void sys_api_set_flag_e403(unsigned char value)
{
    switch (value) {
    case 0:
        sys_config_byte_0x33 = 0;
        break;
    case 1:
        sys_config_byte_0x33 = 1;
        break;
    default:
        sys_config_byte_0x33 = 1;
        break;
    }
}
