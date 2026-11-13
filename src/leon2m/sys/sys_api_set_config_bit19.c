/* sys_api_set_config_bit19  (FUN_a014aa7c)
 *
 * Store configuration bit 19.
 * Name basis: descriptive - stSysConfig bit 19; unused
 *
 * Matching notes
 * --------------
 * FUN_a014aa7c (leon2m 0xa014aa7c-0xa014aaa0, 36 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a one-bit bit-field (12 bits above it in the big-endian word), read-modify-write.
 */
/* Word 0 of the system configuration record, seen from the top: 12 bits, then bit 19, then 19 bits. */
struct sys_config_bit19_word { unsigned int high:12, bit19:1, low:19; };
extern struct sys_config_bit19_word sys_config;

/*
 * Store bit 19 of the system configuration word.
 *
 *   value  bit 0 is the new value
 *
 * Nothing in the firmware calls it.
 */
void sys_api_set_config_bit19(unsigned int value)
{
    sys_config.bit19 = value;
}
