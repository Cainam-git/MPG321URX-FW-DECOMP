/* dp_tx_aux_write_byte  (FUN_a0086360)
 *
 * Write one byte to a sink register over AUX.
 *   port: output
 *   mode: AUX command
 *   address: DPCD address
 *   value
 * Returns: 0 on success, 0xFF on failure
 * Name basis: derived - dp_tx_aux_transfer with the value as data; callers write DPCD 0x600, 0x107, 0x100..
 *
 * Matching notes
 * --------------
 * FUN_a0086360 (leon2s, 0xa0086360-0xa008639c, 60 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the data pointer is the address of the unsigned char parameter itself (firmware
 * 'stb %i3, [%fp + 0x50]' = its home slot, then 'add %fp, 0x50, %o4'). The result is 0 when the transfer
 * returned 1, else 0xff (firmware xor/cmp/subx, then 'and 0xff').
 */
extern unsigned char dp_tx_aux_transfer(unsigned char, unsigned char, unsigned int, unsigned int, unsigned char *);

/*
 * Write one byte to a DPCD address of the sink with an AUX transfer of length 1.
 * Returns 0 on success, 0xff on failure.
 *   port:    link output
 *   mode:    AUX command
 *   address: DPCD address
 *   value:   byte to send
 * The callers write DPCD 0x600, 0x107 and 0x100..
 */
unsigned char dp_tx_aux_write_byte(unsigned char port, unsigned char mode, unsigned int address, unsigned char value)
{
    unsigned char ok = dp_tx_aux_transfer(port, mode, address, 0, &value);
    return (ok == 1) ? 0 : 0xff;
}
