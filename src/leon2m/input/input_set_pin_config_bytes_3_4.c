/* input_set_pin_config_bytes_3_4  (FUN_a01079f4)
 *
 * Store pin configuration bytes 3 and 4.
 * Name basis: descriptive - bytes at 0xA8027A85; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01079f4 @ 0xa01079f4, flags -mcpu=v8 -O2 -g.
 * Source form: one array symbol (one sethi/or base, offsets 3 and 4).
 */
extern unsigned char input_pin_config_bytes[];

/*
 * Store bytes 3 and 4 of input_pin_config_bytes (addresses 0xA8027A85 and 0xA8027A86).
 *
 * No routine in the image calls it.
 */
void input_set_pin_config_bytes_3_4(unsigned char byte3, unsigned char byte4)
{
    input_pin_config_bytes[3] = byte3;
    input_pin_config_bytes[4] = byte4;
}
