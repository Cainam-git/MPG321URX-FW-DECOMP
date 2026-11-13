/* hdcp_tx_hdmi_read_ksv_fifo  (FUN_a00c8824)
 *
 * Read the list of downstream key-selection values and feed it to the engine byte by byte.
 * Name basis: derived - DDC read of len bytes; prints
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c8824 @ 0xa00c8824-0xa00c89b8, flags -mcpu=v8 -Os -g.
 * Source form: the print format is the program-image address (passed as a pointer constant); the result of the
 * DDC read is kept in an unsigned char and returned.
 */
extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_tx_ddc_start(unsigned char, unsigned char, unsigned char, unsigned short);
extern int hdmi_tx_ddc_read(unsigned int, unsigned char *, unsigned short);
extern void hdmi_reg_update_bits(unsigned char, unsigned short, unsigned int, unsigned char);
extern void hdmi_reg_write8(unsigned char, unsigned short, unsigned char);
extern unsigned char hdmi_tx_reg_read8(unsigned char, int, unsigned short);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);

#define HDCP_DDC_DEVICE   0x74                  /* device address used for all handshake reads */
#define HDCP_DDC_KSV_FIFO 0x43                  /* offset of the list of downstream values */
#define MAX_LIST_LENGTH   0x27b                 /* longest list that fits the buffer (640 bytes) */
#define ERROR_LIST_LENGTH 0x0b                  /* returned for a longer list */
#define ENGINE_CMD_0B     0x0b                  /* hdcp_tx_engine_start_command code, here with length 0x4005 */
#define ENGINE_CMD_END    0                     /* code 0, length 0: after the data */
#define BKSV_REG          0x10                  /* registers 0x10..0x14 of the output hold the Bksv */
#define BKSV_LENGTH       5
#define HDMI_RX_BOTH      2                     /* port 2 of the hdmi_ register helpers = both receivers */

/*
 * Read the list of downstream devices' values (length bytes at DDC device 0x74, offset 0x43) from the screen on
 * HDMI output `port` and feed it, byte by byte, to the protection block of that output and to receiver
 * `receiver`, followed by the 5 bytes in registers 0x10..0x14 of the output. Returns 0x0B at once, without
 * any access, when length is above 0x27B; otherwise the result of the DDC read.
 *
 * Order of the steps after the read: bit 6 of register 0x88 of both receivers set; bit 4 of register 0x37 of
 * `receiver` cleared and set; engine command 0x0B with length 0x4005 started; a message printed; every list byte
 * written to register 0x38 of `receiver` and to register 1 of the output; the 5 bytes written to register 1;
 * engine command 0 with length 0 (end); bit 4 of register 0x37 and bit 6 of register 0x88 cleared.
 *
 * Called from hdcp_tx_hdmi_state_read_repeater_info with receiver 0 or 1, chosen from the input code of the
 * output's source.
 */
unsigned char hdcp_tx_hdmi_read_ksv_fifo(unsigned char port, unsigned char receiver, unsigned short length)
{
    unsigned char list[640];
    unsigned char result;
    unsigned short i;

    if (length > MAX_LIST_LENGTH) {
        dbg_printf((const char *)0x9f1c1ff8);
        return ERROR_LIST_LENGTH;
    }
    hdmi_tx_ddc_start(port, HDCP_DDC_DEVICE, HDCP_DDC_KSV_FIFO, length);
    result = hdmi_tx_ddc_read(port, list, length);
    hdmi_reg_update_bits(HDMI_RX_BOTH, 0x88, 0x40, 1);
    hdmi_reg_update_bits(receiver, 0x37, 0x10, 0);
    hdmi_reg_update_bits(receiver, 0x37, 0x10, 1);
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, 0x4005);
    dbg_printf((const char *)0x9f1c2020);
    for (i = 0; i < length; i++) {
        hdmi_reg_write8(receiver, 0x38, list[i]);
        hdcp_tx_reg_write(port, 1, list[i]);
    }
    for (i = 0; i < BKSV_LENGTH; i++)
        hdcp_tx_reg_write(port, 1, hdmi_tx_reg_read8(port, 0, i + BKSV_REG));
    hdcp_tx_engine_start_command(port, ENGINE_CMD_END, 0);
    hdmi_reg_update_bits(receiver, 0x37, 0x10, 0);
    hdmi_reg_update_bits(HDMI_RX_BOTH, 0x88, 0x40, 0);
    return result;
}
