/* input_set_port_option_mask  (FUN_a0070000)
 *
 * Build the per-port option bit mask from three command bytes.
 *   option_bytes: three option bytes
 * Name basis: descriptive - bits 0..2 of three bytes combined into the mask word read by
 *   input_get_port_option*; caller ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0070000 @ 0xa0070000, flags -mcpu=v8 -Os -g.
 * Source form: the loop ORs into the global directly (the compiler keeps it in a register over the loop and
 * stores it once after, with the address high part copied to a second register); option_bytes >> 8 and
 * >> 16 are written in the tests.
 */

extern unsigned int input_port_option_mask;

/*
 * Build the port option mask from the three low bytes of 'option_bytes' (byte 0 = bits 0..7, byte 1 = bits 8..15,
 * byte 2 = bits 16..23). Only bits 0..2 of each byte are used; for i = 0..2 they set these mask bits:
 *   bit i       when byte 0 or byte 1 has bit i
 *   bit 8 + i   when byte 2 has bit i
 *   bit 16 + i  when byte 0 and byte 1 both have bit i
 *   bit 24 + i  when byte 1 has bit i
 * Read back by input_get_port_option and input_get_port_option_level. Called from ipc_dispatch_command.
 */
void input_set_port_option_mask(unsigned int option_bytes)
{
    unsigned char i;

    input_port_option_mask = 0;
    for (i = 0; i < 3; i++) {
        if ((unsigned char)(option_bytes & (1 << i)) || (unsigned char)((option_bytes >> 8) & (1 << i)))
            input_port_option_mask |= (1 << i);
        if ((unsigned char)((option_bytes >> 16) & (1 << i)))
            input_port_option_mask |= (1 << i) << 8;
        if ((unsigned char)(option_bytes & (1 << i)) && (unsigned char)((option_bytes >> 8) & (1 << i)))
            input_port_option_mask |= (1 << i) << 16;
        if ((unsigned char)((option_bytes >> 8) & (1 << i)))
            input_port_option_mask |= (1 << i) << 24;
    }
}
