/* input_decode_port_code  (FUN_a006d5a8)
 *
 * Map the codes 0x31..0x81 to the indices 0..5.
 * Returns: index 0..5
 * Name basis: descriptive - 0x31 + 0x10 * n -> n, others 0; caller ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d5a8 @ 0xa006d5a8, flags -mcpu=v8 -Os -g. The result is returned masked with 7.
 */

/*
 * Map the code 0x31 + 0x10 * n (0x31, 0x41, 0x51, 0x61, 0x71, 0x81) to the index n (0..5). Every other
 * code gives 0. Called from ipc_dispatch_command.
 */
unsigned char input_decode_port_code(unsigned char code)
{
    unsigned char index = 0;

    switch (code) {
    case 0x31: index = 0; break;
    case 0x41: index = 1; break;
    case 0x51: index = 2; break;
    case 0x61: index = 3; break;
    case 0x71: index = 4; break;
    case 0x81: index = 5; break;
    }
    return index & 7;
}
