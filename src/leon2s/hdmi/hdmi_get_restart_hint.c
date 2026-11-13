/* hdmi_get_restart_hint  (FUN_a008f9e4)
 *
 * Return the status latch flag the receiver poll set this pass.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: 0 or 1
 * Name basis: derived - record byte +0xA6, set by the state-5 poll from regs 0x72 bit 7 / 0x73 bit 6,
 *   published to the main chip
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008f9e4 @ 0xa008f9e4 (-mcpu=v8 -Os -g)
 * Source form: the record array is declared as bytes and indexed with the stride 0xb0 and the offset 0xa6.
 */

#define HDMI_RX_RECORD_SIZE         0xb0    /* bytes per receiver record */
#define RESTART_HINT_OFFSET         0xa6    /* restart_hint in struct hdmi_rx_record (see hdmi_poll_rx_status) */

extern unsigned char hdmi_rx_records[];

/* The record of receiver "port" is in hdmi_rx_records. hdmi_poll_rx_status clears restart_hint at the start of each
   pass and sets it when status register 0x72 bit 7 or 0x73 bit 6 was set. hdmi_update_port_status_flags copies
   the value into bit 14 of the port record's halfword 0xE. */
unsigned char hdmi_get_restart_hint(unsigned int port)
{
    return hdmi_rx_records[(port & 0xff) * HDMI_RX_RECORD_SIZE + RESTART_HINT_OFFSET];
}
