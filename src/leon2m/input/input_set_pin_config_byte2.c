/* input_set_pin_config_byte2  (FUN_a0107a08)
 *
 * Store pin configuration byte 2.
 * Name basis: descriptive - byte at 0xA8027A84; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0107a08 @ 0xa0107a08, flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char input_pin_config_byte2;

/*
 * Store byte 2 of the pin configuration (address 0xA8027A84, the third byte of input_pin_config_bytes).
 *
 * No routine in the image calls it.
 */
void input_set_pin_config_byte2(unsigned char value)
{
    input_pin_config_byte2 = value;
}
