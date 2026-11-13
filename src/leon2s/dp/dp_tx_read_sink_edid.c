/* dp_tx_read_sink_edid  (FUN_a0088b60)
 *
 * Read the 256-byte EDID of a sink over I2C-over-AUX.
 * Note: Sets dp_tx_hpd_flag after all 16 parts were read.
 * Name basis: derived - 16 blocks from I2C address 0x50 (EDID) into a shared buffer; then sets dp_tx_hpd_flag,
 *   which is published as bit 5 of the status word
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: one 'offset = part << 4' temp shared by the store and the buffer
 * address; the fifth argument of dp_tx_aux_request is the address of dp_tx_aux_data_byte; the buffer
 * dp_tx_sink_edid_buffer is a symbol (sethi + or %lo 0).
 */
extern unsigned char dp_tx_aux_data_byte;
extern unsigned char dp_tx_hpd_flag;
extern unsigned char dp_tx_sink_edid_buffer[];
#define _DAT_cf018884 (*(volatile unsigned int *)0xcf018884)
extern unsigned char dp_tx_aux_read_byte(unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char dp_tx_aux_request(unsigned char, unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char dp_tx_aux_request_copy(unsigned char, unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char dp_tx_get_mode_flag(void);
extern unsigned char dp_tx_is_connected(unsigned char);

#define EDID_I2C_ADDRESS 0x50           /* I2C address of the EDID */

/*
 * Read the 256-byte EDID of the sink on a DP output into dp_tx_sink_edid_buffer, 16 bytes at a time.
 *
 *   port: DP output 0..4
 *
 * Called by the HPD action routines (DPTX_IsHPDAction_Off, dp_tx_edp_run_hpd_actions). Nothing is read when the
 * output is not connected. The loop stops early when the output is no longer connected or when bit 7 of
 * register 0xCF018884 is set; dp_tx_hpd_flag is set only after all 16 parts were read.
 */
void dp_tx_read_sink_edid(unsigned char port)
{
    unsigned char part;
    unsigned char aux_status;
    unsigned int offset;

    if (dp_tx_is_connected(port) == 0)
        return;
    /* With the mode flag set, output 0 first reads one byte through the AUX channel (arguments 0, 0x90,
       0x111); the EDID is not read when that fails or when bit 0 of the byte is set. */
    if (dp_tx_get_mode_flag() != 0 && port == 0) {
        if (dp_tx_aux_read_byte(0, 0x90, 0x111, &aux_status) != 0)
            return;
        if ((aux_status & 1) != 0)
            return;
    }
    part = 0;
    do {
        offset = part << 4;
        /* The offset byte goes out as a one-byte request to the EDID address ... */
        dp_tx_aux_data_byte = offset;
        dp_tx_aux_request(port, 0x40, EDID_I2C_ADDRESS, 0, &dp_tx_aux_data_byte);
        /* ... and the 16 bytes at that offset are read into the buffer. */
        dp_tx_aux_request_copy(port, 0x10, EDID_I2C_ADDRESS, 0xf, dp_tx_sink_edid_buffer + offset);
        part++;
        if (dp_tx_is_connected(port) == 0)
            return;
        if ((_DAT_cf018884 & 0x80) != 0)
            return;
    } while (part <= 0xf);
    dp_tx_hpd_flag = 1;
}
