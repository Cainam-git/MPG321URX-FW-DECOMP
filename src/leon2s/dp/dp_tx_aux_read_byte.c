/* dp_tx_aux_read_byte  (FUN_a008639c)
 *
 * Read one byte from a sink register over AUX.
 *   port: output
 *   mode: AUX command
 *   address: DPCD address
 *   out: byte out
 * Returns: 0 on success, 0xFF on failure
 * Name basis: derived - dp_tx_aux_transfer with length 0 into a buffer; used for DPCD reads such as 0x219 /
 *   0x220
 *
 * Matching notes
 * --------------
 * FUN_a008639c (leon2s 0xa008639c-0xa00863d4, 14 words), flags -mcpu=v8 -Os -g.
 * Source form: the result is 0 when the transfer returned 1, else 0xff (firmware xor 1 / cmp / subx / and 0xff).
 */
extern unsigned char dp_tx_aux_transfer(unsigned char, unsigned char, unsigned int, int, unsigned int);

/*
 * Read one byte from a DPCD address of the sink with an AUX transfer of length 1 (count argument 0).
 * Returns 0 on success, 0xff on failure.
 *   port:    link output
 *   mode:    AUX command
 *   address: DPCD address
 *   out:     address of the byte that receives the value
 */
unsigned char dp_tx_aux_read_byte(unsigned char port, unsigned char mode, unsigned int address, unsigned int out)
{
    if (dp_tx_aux_transfer(port, mode, address, 0, out) == 1)
        return 0;
    return 0xff;
}
