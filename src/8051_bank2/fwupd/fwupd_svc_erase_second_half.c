/* fwupd_svc_erase_second_half  (FUN_CODE_dd1a)
 *
 * Send the erase walk's service record once for the second half of the flash range; read the reply.
 *   cmd99_arg: size code 0x10 only: not 0 sends service command 0x99 with 8 first, 0 sends it with 0
 * Note: Bytes 8 / 9 of the record: 0x20 / 0x3F, 0x40 / 0x7F, 0x80 / 0xFF, 0x00 / 0xFF for size codes 2, 4, 8,
 *   0x10; another size code sends no record.
 * Name basis: derived - fwupd_svc_send_rec_cbcc, the record fwupd_svc_erase_flash sends per step, with the
 *   first and last position of the second half; only caller fwupd_svc_erase_flash (update mode bit 2 without
 *   bit 1)
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED). The closing fwupd_svc_read_reply is a tail jump (LJMP) with the generic pointer
 * 01:0436 to fwupd_svc_packet, as in the other fwupd_svc_* routines. OPTIMIZE(7,SPEED) gives 93 B.
 */
extern unsigned char xdata fwupd_svc_packet[];
extern unsigned char xdata fwupd_flash_size_code;
void fwupd_svc_send_cmd_0x99(unsigned char a);
void fwupd_svc_send_rec_cbcc(unsigned char lo, unsigned char hi);
void fwupd_svc_read_reply(unsigned char *buf);

/* Values of fwupd_flash_size_code (flash size = code * 0x40000 bytes) this routine knows. */
#define SIZE_CODE_02 0x02
#define SIZE_CODE_04 0x04
#define SIZE_CODE_08 0x08
#define SIZE_CODE_10 0x10

/* fwupd_svc_erase_second_half: send the CODE 0xCBCC service record once, with bytes 8 and 9 chosen by
 * fwupd_flash_size_code, and read the main chip's reply.
 *
 * cmd99_arg: for size code 0x10 only, service command 0x99 goes first, with 8 when cmd99_arg is not 0, else 0.
 *
 * Bytes 8 / 9 are 0x20 / 0x3F, 0x40 / 0x7F, 0x80 / 0xFF or 0x00 / 0xFF for the size codes 2, 4, 8 and 0x10. These
 * are the low bytes of the first and last position of the second half of the range 0 .. size code * 32 - 1 that
 * fwupd_svc_erase_flash walks in steps of 16 with the same record; for size code 0x10 that walk also sends command
 * 0x99 with 8 before the second half. Any other size code sends no record, only the reply read.
 * Caller: fwupd_svc_erase_flash, with 1, for update mode bit 2 without bit 1. */
void fwupd_svc_erase_second_half(unsigned char cmd99_arg)
{
    if (fwupd_flash_size_code == SIZE_CODE_10) {
        if (cmd99_arg == 0) {
            fwupd_svc_send_cmd_0x99(0);
        } else {
            fwupd_svc_send_cmd_0x99(8);
        }
    }
    if (fwupd_flash_size_code == SIZE_CODE_02) {
        fwupd_svc_send_rec_cbcc(0x20, 0x3f);
    } else if (fwupd_flash_size_code == SIZE_CODE_04) {
        fwupd_svc_send_rec_cbcc(0x40, 0x7f);
    } else if (fwupd_flash_size_code == SIZE_CODE_08) {
        fwupd_svc_send_rec_cbcc(0x80, 0xff);
    } else if (fwupd_flash_size_code == SIZE_CODE_10) {
        fwupd_svc_send_rec_cbcc(0, 0xff);
    }
    fwupd_svc_read_reply(fwupd_svc_packet);
}
