/* dp_tx_aux_send_request  (FUN_a0086030)
 *
 * Write an AUX request (command, address, length, data) and start it.
 *   port: output
 *   mode: AUX command
 *   address
 *   count: length - 1
 *   buf: data
 * Name basis: derived - request header into register 0x30 as (cmd | addr bits), length and data, start bit in
 *   0x31; DP AUX layout
 *
 * Matching notes
 * --------------
 * FUN_a0086030 (leon2s 0xa0086030-0xa0086154, 73 words), flags -mcpu=v8 -Os -g.
 * Source form: a 'signed char length = n' local (firmware 'mov %i3,%i2' copy, sll/sra 24 compares, and the loop
 * counter takes %i3); a plain for loop whose rotated entry guard 'length >= 0' is the firmware's btst 0x80 (an
 * explicit if (!(length & 0x80)) + do/while is predicted the other way and reorg threads the exit branch);
 * the 3/0xb pick in its own else arm. The last write re-masks the port ('and %i0,0xff').
 */
#define AUX_REG_DATA    0x30    /* header, address, length and data bytes are written here, one byte at a time */
#define AUX_REG_CONTROL 0x31    /* written 0x71 before the request and 3 or 0xb after it */

extern void dp_tx_reg_write8(unsigned char, unsigned short, unsigned char);
extern void timer_delay_long_units(unsigned char);

/*
 * Send an AUX request through the registers of a link output. The request is: command (high nibble of the
 * first byte) with bits 16..19 of the address, address bits 8..15, address bits 0..7, then length - 1.
 * For the commands 0x80, 0x40 and 0 the data bytes buf[0..length] follow and the control register gets 0xb
 * afterwards; for any other command the control register gets 3 when length is 0, else 0xb. A short delay
 * (timer_delay_long_units(1)) ends the routine.
 *   port:    link output
 *   mode:    AUX command, only the high nibble is sent in the first byte
 *   address: address in the sink, 20 bits are used
 *   count:   length - 1, taken as a signed byte
 *   buf:     data bytes to send (read only for the commands above)
 */
void dp_tx_aux_send_request(unsigned int port, unsigned int mode, unsigned int address, unsigned int count,
                  unsigned char *buf)
{
    unsigned char output = port;
    unsigned char i;
    signed char length = count;
    dp_tx_reg_write8(output, AUX_REG_CONTROL, 0x71);
    dp_tx_reg_write8(output, AUX_REG_DATA, (mode & 0xf0) | ((address >> 16) & 0xf));
    dp_tx_reg_write8(output, AUX_REG_DATA, (address >> 8) & 0xff);
    dp_tx_reg_write8(output, AUX_REG_DATA, address & 0xff);
    mode &= 0xff;
    if (mode == 0x80 || mode == 0x40 || mode == 0) {
        dp_tx_reg_write8(output, AUX_REG_DATA, length);
        for (i = 0; i <= length; i++)
            dp_tx_reg_write8(output, AUX_REG_DATA, buf[i]);
        dp_tx_reg_write8(port & 0xff, AUX_REG_CONTROL, 0xb);
    } else {
        dp_tx_reg_write8(output, AUX_REG_DATA, length);
        if (length == 0)
            dp_tx_reg_write8(output, AUX_REG_CONTROL, 3);
        else
            dp_tx_reg_write8(output, AUX_REG_CONTROL, 0xb);
    }
    timer_delay_long_units(1);
}
