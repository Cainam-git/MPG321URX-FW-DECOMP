/* input_set_pin_config_byte0  (FUN_a0107a14)
 *
 * Store pin configuration byte 0.
 * Name basis: descriptive - byte at 0xA8027A82; set at start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0107a14 @ 0xa0107a14, flags -mcpu=v8 -O2 -g (section default).
 */
extern unsigned char input_pin_config_bytes;

/*
 * Store byte 0 of the pin configuration (address 0xA8027A82, the first byte of input_pin_config_bytes).
 *
 * Called from startup_init_input_ports.
 */
void input_set_pin_config_byte0(unsigned char value)
{
    input_pin_config_bytes = value;
}
