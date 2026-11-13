/* fwupd_svc_send_0x99_and_record  (FUN_CODE_e4a4)
 *
 * Send service command 0x99, then the ten-byte service record, and read the answer.
 * Name basis: descriptive - fwupd_svc_send_cmd_0x99(0), fwupd_svc_send_rec_cbcc(0x0E, 0x0E)
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e4a4 @ 0xe4a4, OPTIMIZE(8,SPEED).
 * Source form: the last call goes to the label LAB_CODE_e4bf (the code of fwupd_svc_read_reply) with a generic
 * pointer to XDATA 0x0436 built from a cast of the address; Keil makes it a tail jump (LJMP).
 */
extern void fwupd_svc_send_cmd_0x99(unsigned char);
extern void fwupd_svc_send_rec_cbcc(unsigned char, unsigned char);
extern void LAB_CODE_e4bf(char *);     /* fwupd_svc_read_reply */

#define RECORD_BYTE_8_9     0x0e    /* value for both bytes 8 and 9 of the CODE 0xCBCC record */

/* Service command 02 99 00 (with its reply), then the CODE 0xCBCC record with bytes 8 and 9 = 0x0E, then the reply
 * to the record is read into fwupd_svc_packet (XDATA 0x0436).
 * Only caller: fwupd_run_isp_write, in the modes with bit 2 or bit 3, after the first write protect off and before
 * the erase step. */
void fwupd_svc_send_0x99_and_record(void) {
    fwupd_svc_send_cmd_0x99(0);
    fwupd_svc_send_rec_cbcc(RECORD_BYTE_8_9, RECORD_BYTE_8_9);
    LAB_CODE_e4bf((char *)((char xdata *)0x0436));
}
