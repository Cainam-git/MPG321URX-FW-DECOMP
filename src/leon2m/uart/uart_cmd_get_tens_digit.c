/* uart_cmd_get_tens_digit  (FUN_a00c0b34)
 *
 * Return the tens digit of the value in a received set command.
 *   port: command port (2, 3 or 4)
 * Returns: value 0..100 (byte minus '0'), or 0xFF when above 100
 * Note: Byte 8 of the port's receive record minus '0'.
 * Name basis: derived - callers parse the three value digits (e.g. the colour gain set)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c0b34, flags -mcpu=v8 -O3 -g.
 * Source form: as in the other frame-byte readers, the difference goes into an unsigned short local; the test reads it
 * as (unsigned char)value and the return as value & 0xff, from an int function.
 */
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];

#define VALUE_CHAR_BASE   0x30      /* '0': a value byte of the frame is the value plus 0x30 */
#define FRAME_VALUE_MAX   100       /* largest value the reader accepts */
#define BAD_VALUE         0xff      /* result for a value above FRAME_VALUE_MAX */

/*
 * Read byte 8 of the receive record of a PC tool command port as a value: the byte minus '0'. Frames of the set
 * commands carry their value in bytes 7, 8 and 9; this reader takes byte 8, the second of the three.
 *
 *   port  the command port: 2 and 3 have their own receive records, any other number uses uart_cmd_rx_record
 *
 * Returns the value (0..100), or BAD_VALUE (0xff) when the byte minus '0' is above 100.
 * Used, with the readers of the other two bytes, by the set command for the custom colour gains.
 */
int uart_cmd_get_tens_digit(unsigned char port)
{
    unsigned int frame_byte;
    unsigned short value;

    if (port == 2)
        frame_byte = uart_cmd_rx_record_port2[8];
    else if (port == 3)
        frame_byte = uart_cmd_rx_record_port3[8];
    else
        frame_byte = uart_cmd_rx_record[8];
    value = frame_byte - VALUE_CHAR_BASE;
    if ((unsigned char)value > FRAME_VALUE_MAX)
        return BAD_VALUE;
    return value & 0xff;
}
