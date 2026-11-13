/* audio_init_config  (FUN_a014f6f4)
 *
 * Build the audio configuration, switch the sound pins and send it to the input processor.
 * Name basis: derived - 3-byte record sent with mailbox command 0x90; called from System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014f6f4, flags -mcpu=v8 -O3 -g.
 * Source form: unsigned char bit-fields, first field = most significant bit (GCC accesses them with word loads
 * and stores on the aligned stack slot; the tests extract byte 0 with srl 24). Each test reads the record again.
 * The copy before the send is a structure assignment (lduh + ldub of the 3 bytes).
 */
/* The 3-byte audio configuration, as ipc_configure_audio takes it (byte 0 bits are listed from bit 7 down). */
struct audio_config {
    unsigned char byte0_bit7 : 1, byte0_bit6 : 1, byte0_bit5 : 1, byte0_bit4 : 1,
                  byte0_bit3 : 1, byte0_bit2 : 1, byte0_bit1 : 1, byte0_bit0 : 1;
    unsigned char byte1_bits7_6 : 2, byte1_bits5_0 : 6;     /* bits 5..0 of byte 1 are never written here */
    unsigned char byte2;
};
extern void gpio_set_pin_function(unsigned char, unsigned char, unsigned char);
extern void audio_select_output_pins(unsigned char);
extern void ipc_configure_audio(unsigned char *p);

/*
 * Build the audio configuration (byte 0 = 0x01, byte 1 bits 7..6 = 0, byte 2 = 1), switch the pins that the
 * set bits of byte 0 ask for, and send the configuration to the input processor (mailbox command 0x90, through
 * ipc_configure_audio).
 *
 * Byte 0 bits and their pins: bit 7 sets pins 1, 2, 4 and 8 of pin group 0xC to function 0xB; bit 6 and bit 5
 * call audio_select_output_pins with 0 and 1; bit 2 and bit 1 set pin 4 and pin 8 of pin group 0xE to function
 * 0xE. With the configuration built here only bit 0 is set, so no pin is switched.
 *
 * Called from System_Initialize.
 */
void audio_init_config(void)
{
    struct audio_config config;
    struct audio_config copy;

    config.byte0_bit7 = 0;
    config.byte0_bit6 = 0;
    config.byte0_bit5 = 0;
    config.byte0_bit4 = 0;
    config.byte0_bit3 = 0;
    config.byte0_bit2 = 0;
    config.byte0_bit1 = 0;
    config.byte0_bit0 = 1;
    config.byte2 = 1;
    config.byte1_bits7_6 = 0;
    if (config.byte0_bit7) {
        gpio_set_pin_function(0xc, 1, 0xb);
        gpio_set_pin_function(0xc, 2, 0xb);
        gpio_set_pin_function(0xc, 4, 0xb);
        gpio_set_pin_function(0xc, 8, 0xb);
    }
    if (config.byte0_bit6)
        audio_select_output_pins(0);
    if (config.byte0_bit5)
        audio_select_output_pins(1);
    if (config.byte0_bit2)
        gpio_set_pin_function(0xe, 4, 0xe);
    if (config.byte0_bit1)
        gpio_set_pin_function(0xe, 8, 0xe);
    copy = config;
    ipc_configure_audio((unsigned char *)&copy);
}
