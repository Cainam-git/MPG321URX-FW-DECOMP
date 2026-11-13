/* dp_tx_read_link_status  (FUN_a0086e58)
 *
 * Read the sink's link status (lane lock and adjust requests).
 *   port: output
 *   out: record
 * Name basis: proven - 8 bytes from DPCD 0x200 unpacked into a 16-byte record
 *
 * Matching notes
 * --------------
 * FUN_a0086e58 (leon2s 0xa0086e58-0xa0086fb0, 344 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the buffer is zeroed on declaration; the 2-bit fields are split with mask and shift.
 */
extern unsigned char dp_tx_aux_request(unsigned char, unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char dp_tx_aux_request_copy(unsigned char, unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char dp_tx_get_mode_flag(void);

/*
 * Read the 8 status bytes at DPCD 0x200 (command 0x90, length 7) and unpack them into a 16-byte record.
 *   out[0]:    bit 7 is set before the read and cleared again when the read failed
 *   out[1],[2]: status bytes 0 and 1
 *   out[3]:    byte read from DPCD 0x2003, see below
 *   out[4..7]: status bytes 2..5
 *   out[8..0xf]: the four 2-bit fields of status byte 6 go to out[8], out[0xc], out[9], out[0xd] (low pair
 *              first) and those of status byte 7 to out[0xa], out[0xe], out[0xb], out[0xf]
 * Then, for port 0, DPCD 0x2003 is read into the buffer (command 0x90). out[3] gets that byte when
 * dp_tx_get_mode_flag() is non-zero and the port is 0; otherwise out[3] is 0 and DPCD 0x2003 is written
 * with the buffer (command 0x80, length 1).
 *   port: link output
 *   out:  16-byte record
 */
void dp_tx_read_link_status(unsigned char port, unsigned char *out)
{
    unsigned char status[8] = {0};
    out[0] |= 0x80;
    if (dp_tx_aux_request_copy(port, 0x90, 0x200, 7, status) == 0)
        out[0] &= 0x7f;
    out[1] = status[0];
    out[2] = status[1];
    out[4] = status[2];
    out[5] = status[3];
    out[6] = status[4];
    out[7] = status[5];
    out[8] = status[6] & 3;
    out[0xc] = (status[6] & 0xc) >> 2;
    out[9] = (status[6] & 0x30) >> 4;
    out[0xd] = status[6] >> 6;
    out[0xa] = status[7] & 3;
    out[0xe] = (status[7] & 0xc) >> 2;
    out[0xb] = (status[7] & 0x30) >> 4;
    out[0xf] = status[7] >> 6;
    if (port == 0)
        dp_tx_aux_request_copy(0, 0x90, 0x2003, 0, status);
    if (dp_tx_get_mode_flag() != 0 && port == 0)
        out[3] = status[0];
    else {
        out[3] = 0;
        dp_tx_aux_request(port, 0x80, 0x2003, 0, status);
    }
}
