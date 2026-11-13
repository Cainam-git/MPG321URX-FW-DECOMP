/* input_csc_set_option_byte  (FUN_a01006d8)
 *
 * Store an option byte of the colour format handling.
 * Name basis: descriptive - byte at 0xA8027A74; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01006d8 @ 0xa01006d8, flags -mcpu=v8 -O2 -g (section default).
 * Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char input_csc_option_byte;

/*
 * Store the option byte. input_csc_set_format_code uses it as the colour format code when the selector is
 * neither 1 nor 2.
 *
 * No routine in the image calls it.
 */
void input_csc_set_option_byte(unsigned char value)
{
    input_csc_option_byte = value;
}
