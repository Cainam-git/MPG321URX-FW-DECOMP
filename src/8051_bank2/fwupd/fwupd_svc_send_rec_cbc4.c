/* fwupd_svc_send_rec_cbc4  (FUN_CODE_e384)
 *
 * Send the fixed eight-byte service record to the main chip and wait for it.
 * Name basis: descriptive - record from CODE 0xCBC4; I2C address 0x6E; wait up to 4000 units
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e384 @ 0xe384 (39 B), OPTIMIZE(8,SPEED).
 * The record is declared as an 8-byte struct, so the copy is one ?C?COPY call of length 8; the wait is a tail
 * call.
 */

/* The record at CODE 0xCBC4 holds the service packet 07 1E AA 55 CC 33 E2 1D; its last six bytes are the same as
 * bytes 2..7 of the ten-byte record at CODE 0xCBCC (fwupd_svc_send_rec_cbcc). It is copied to XDATA 0x08F3 and
 * sent from there. */
struct svc_record8 { unsigned char bytes[8]; };
extern struct svc_record8 code fwupd_svc_cmd_1e_record;
extern struct svc_record8 xdata DAT_EXTMEM_08f3;
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);

#define SVC_ADDRESS         0x6e    /* I2C slave address of every service packet */
#define SVC_RECORD8_BYTES   8
#define SVC_WAIT            0x0fa0  /* fwupd_wait_ready_line limit (4000) */

/* Send the CODE 0xCBC4 record and wait on the ready line. The reply is left for the caller to read.
 * Only caller: fwupd_svc_erase_flash, for update mode bit 0, in place of the stepped 0xCBCC records. */
void fwupd_svc_send_rec_cbc4(void)
{
    DAT_EXTMEM_08f3 = fwupd_svc_cmd_1e_record;
    i2c_write_packet(SVC_ADDRESS, SVC_RECORD8_BYTES, (unsigned char *)&DAT_EXTMEM_08f3);
    fwupd_wait_ready_line(SVC_WAIT);
}
