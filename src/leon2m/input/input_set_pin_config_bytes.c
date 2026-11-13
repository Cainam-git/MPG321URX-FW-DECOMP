/* input_set_pin_config_bytes  (FUN_a01079c0)
 *
 * Store the five pin configuration bytes.
 * Name basis: descriptive - bytes at 0xA8027A82; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01079c0 @ 0xa01079c0, flags -mcpu=v8 -O3 -g.
 */
extern unsigned char input_pin_config_bytes[];

/*
 * Copy five bytes to input_pin_config_bytes. Byte 0 is also set by input_set_pin_config_byte0, byte 2 by
 * input_set_pin_config_byte2, bytes 3 and 4 by input_set_pin_config_bytes_3_4.
 *
 *   config  the five bytes
 *
 * No routine in the image calls it.
 */
void input_set_pin_config_bytes(const unsigned char *config)
{
    input_pin_config_bytes[0] = config[0];
    input_pin_config_bytes[1] = config[1];
    input_pin_config_bytes[2] = config[2];
    input_pin_config_bytes[3] = config[3];
    input_pin_config_bytes[4] = config[4];
}
