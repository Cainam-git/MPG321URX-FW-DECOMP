/* hdcp_tx_hdmi_read_bksv  (FUN_a00c850c)
 *
 * Read the receiver's key-selection value, load it into the engine and check it.
 * Returns: 0x78 when it is invalid
 * Name basis: proven - DDC device 0x74, offset 0, five bytes (Bksv) into registers 0x10..0x14
 *
 * Matching notes
 * --------------
 * FUN_a00c850c (leon2s 0xa00c850c-0xa00c85b8, 172 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: start_result is an int; the loop counter i (unsigned char) is reused for the result of
 * hdcp_is_ksv_valid and for the value 0x78 that is returned (this keeps the firmware's sign extension, xor with
 * start_result and addx/neg/and/add sequence).
 */
extern void hdmi_tx_reg_write8(unsigned char, int, unsigned short, unsigned char);
extern unsigned char hdmi_tx_ddc_start(unsigned char port, unsigned char a, unsigned char b, unsigned short n);
extern void hdmi_tx_ddc_read(unsigned char port, unsigned char *buf, unsigned short n);
extern char hdcp_is_ksv_valid(unsigned char *buf);

#define HDCP_DDC_DEVICE   0x74                  /* device address used for all handshake reads */
#define HDCP_DDC_BKSV     0x00                  /* offset of the 5-byte Bksv */
#define KSV_LENGTH        5
#define ENGINE_BKSV_REG   0x10                  /* registers 0x10..0x14 of the output receive the bytes */
#define ERROR_INVALID_KSV 0x78                  /* returned when the 5 bytes fail the bit-count test */

/*
 * Read the 5-byte Bksv of the screen on HDMI output `port` (DDC device 0x74, offset 0), write the bytes to
 * registers 0x10..0x14 of the output, then test them with hdcp_is_ksv_valid. Returns 0 when valid, 0x78 when
 * not, or the non-zero result of the DDC start when it fails (nothing is read then).
 *
 * Called from hdcp_tx_hdmi_state_run_checks.
 */
unsigned int hdcp_tx_hdmi_read_bksv(unsigned char port)
{
    unsigned char ksv[KSV_LENGTH];
    unsigned char i;
    int start_result;

    start_result = hdmi_tx_ddc_start(port, HDCP_DDC_DEVICE, HDCP_DDC_BKSV, KSV_LENGTH);
    if (start_result != 0)
        return start_result;
    hdmi_tx_ddc_read(port, ksv, KSV_LENGTH);
    for (i = 0; i < KSV_LENGTH; i++)
        hdmi_tx_reg_write8(port, 0, i + ENGINE_BKSV_REG, ksv[i]);
    i = hdcp_is_ksv_valid(ksv);
    if (i == start_result) {
        i = ERROR_INVALID_KSV;
        return i;
    }
    return 0;
}
