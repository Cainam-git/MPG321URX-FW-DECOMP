/* dp_aux_answer_port1  (FUN_CODE_914b)
 *
 * Read an AUX request from DP receiver 1 and answer it.
 * Name basis: proven - request command nibble 9/8 native read/write, 1/5 and 0/4 I2C-over-AUX;
 *   dp_aux_build_reply(…, 1); caller dp_aux_service
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_914b @ 0x914b (248 B, OPTIMIZE(8,SPEED) LARGE), register bank 3 ('using 3').
 * Source forms: the FIFO status and data bytes are one 2-byte object (INC DPTR in the twin routines
 * dp_aux_snoop_port1 / dp_aux_snoop_port0); the wait loop tests an int-typed value (ANL A,#01H / JNZ). LARGE locals:
 * count 0xA548, request[17] 0xA549..0xA559, req_code 0xA55A.
 */
extern unsigned char xdata reg_dp_aux_rx_fifo_port1[2];
extern unsigned char xdata reg_dp_aux_ctrl_port1, reg_dp_aux_reply_len_port1, reg_dp_aux_rx_ack_port1;
extern unsigned char xdata DAT_EXTMEM_a547;
extern unsigned char xdata reg_chip_id;
extern bit dp_aux_no_request_flag;
extern void dp_aux_build_reply(unsigned char request_kind, unsigned char *request, unsigned char port);

/* Request kinds of dp_aux_build_reply, and the request codes (high nibble of the first request byte) that
 * select them. */
#define AUX_NATIVE_READ        0
#define AUX_NATIVE_WRITE       1
#define AUX_I2C_READ           2
#define AUX_I2C_WRITE          3
#define REQ_CODE_MASK          0xf0
#define REQ_CODE_NATIVE_READ   0x90
#define REQ_CODE_NATIVE_WRITE  0x80
#define REQ_CODE_I2C_READ      0x10
#define REQ_CODE_I2C_READ_40   0x50  /* the same with bit 6 set */
#define REQ_CODE_I2C_WRITE     0x00
#define REQ_CODE_I2C_WRITE_40  0x40  /* the same with bit 6 set */
#define REQ_LENGTH             3     /* request byte: byte count - 1 */

#define AUX_REQUEST_BYTES_MAX  0x11  /* further bytes go to XDATA 0xA547 and are lost */
#define AUX_FIFO_HAS_DATA      0x01  /* FIFO status bit 0: a request byte is waiting */
#define AUX_RX_ACK             0x01  /* set to take the request; the receiver clears it */
#define AUX_CTRL_BIT2          0x04
#define CHIP_ID_20             0x20  /* reg_chip_id value */
#define DP_PORT                1

/*
 * dp_aux_answer_port1 - read one AUX request from DP receiver 1 and answer it.
 * The request bytes are read from the FIFO (at most 17 are kept), the reply count is set to the request's
 * length byte + 1 (0 for a request of three bytes or fewer), the request is acknowledged, and
 * dp_aux_build_reply answers it by its request code; an unknown code sets the reply count to 0.
 * When the FIFO held at least one byte, the AUX control register gets 0 and then 1, and on chip 0x20 also bit 2;
 * with an empty FIFO dp_aux_no_request_flag is set instead.
 * Only caller: dp_aux_service (LCALL at 0xC1FB). dp_aux_answer_port0 is the same code on the registers of the other receiver.
 */
void dp_aux_answer_port1(void) using 3
{
    unsigned char count;
    unsigned char request[17];
    unsigned char req_code;
    count = 0;
    dp_aux_no_request_flag = 0;
    req_code = 0;
    while (reg_dp_aux_rx_fifo_port1[0] & AUX_FIFO_HAS_DATA) {
        if (count < AUX_REQUEST_BYTES_MAX) request[count++] = reg_dp_aux_rx_fifo_port1[1];
        else DAT_EXTMEM_a547 = reg_dp_aux_rx_fifo_port1[1];
    }
    if (count > 3) reg_dp_aux_reply_len_port1 = request[REQ_LENGTH] + 1;
    else reg_dp_aux_reply_len_port1 = 0;
    reg_dp_aux_rx_ack_port1 |= AUX_RX_ACK;
    while ((unsigned int)(reg_dp_aux_rx_ack_port1 & AUX_RX_ACK)) ;
    req_code = request[0] & REQ_CODE_MASK;
    if (req_code == REQ_CODE_NATIVE_READ) dp_aux_build_reply(AUX_NATIVE_READ, request, DP_PORT);
    else if (req_code == REQ_CODE_I2C_READ || req_code == REQ_CODE_I2C_READ_40) dp_aux_build_reply(AUX_I2C_READ, request, DP_PORT);
    else if (req_code == REQ_CODE_NATIVE_WRITE) dp_aux_build_reply(AUX_NATIVE_WRITE, request, DP_PORT);
    else if (req_code == REQ_CODE_I2C_WRITE || req_code == REQ_CODE_I2C_WRITE_40) dp_aux_build_reply(AUX_I2C_WRITE, request, DP_PORT);
    else reg_dp_aux_reply_len_port1 = 0;
    if (count == 0) dp_aux_no_request_flag = 1;
    if (!dp_aux_no_request_flag) {
        reg_dp_aux_ctrl_port1 = 0;
        reg_dp_aux_ctrl_port1 = 1;
        if (reg_chip_id == CHIP_ID_20) reg_dp_aux_ctrl_port1 |= AUX_CTRL_BIT2;
    }
}
