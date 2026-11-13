/* dp_aux_snoop_port1  (FUN_CODE_b8fd)
 *
 * Read an AUX request seen on DP receiver 1 and track link training.
 * Name basis: derived - AUX FIFO 0xDCC9; native read/write (nibble 9/8) to dp_aux_track_link_training(…, 1);
 *   caller dp_aux_service
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b8fd, OPTIMIZE(8,SPEED) LARGE, register bank 3 ('using 3').
 * Source form: the status byte and the data byte of the FIFO are one 2-byte object (Keil reaches the second byte
 * with INC DPTR); with separate externs Keil reads the data byte once before the count test.
 */
extern unsigned char xdata reg_dp_aux_rx_fifo_port1[2];
extern unsigned char xdata reg_dp_aux_reply_len_port1;
extern unsigned char xdata DAT_EXTMEM_a547;
extern unsigned char xdata DAT_EXTMEM_a548[];
extern bit dp_aux_no_request_flag;
extern void dp_aux_track_link_training(unsigned char sel, unsigned char *p, unsigned char n);

/*
 * dp_aux_snoop_port1 - read the AUX request that DP receiver 1 has received and pass it to the link-training tracker.
 * While bit 0 of the FIFO status byte (0xDCC8) is set, the data byte is read: the first 17 bytes go to the request
 * buffer at XDATA 0xA548, any further ones to 0xA547 (so the buffer holds at most 17 bytes). dp_aux_no_request_flag
 * is cleared first. Then the reply-length register is set to (request byte 3 + 1) when more than 3 bytes were
 * read, else to 0. When the high nibble of request byte 0 is 9 or 8, dp_aux_track_link_training is called with
 * type 0 (native read) or 1 (native write), the buffer and receiver port 1.
 * Caller: dp_aux_service (dp_aux_service, code at 0xC200). Same code as dp_aux_snoop_port0 with the other receiver's registers.
 */
void dp_aux_snoop_port1(void) using 3
{
    unsigned char count;
    count = 0;
    dp_aux_no_request_flag = 0;
    while (reg_dp_aux_rx_fifo_port1[0] & 0x01) {
        if (count < 0x11) DAT_EXTMEM_a548[count++] = reg_dp_aux_rx_fifo_port1[1];
        else DAT_EXTMEM_a547 = reg_dp_aux_rx_fifo_port1[1];
    }
    if (count > 3) reg_dp_aux_reply_len_port1 = DAT_EXTMEM_a548[3] + 1;
    else reg_dp_aux_reply_len_port1 = 0;
    if ((DAT_EXTMEM_a548[0] & 0xf0) == 0x90) dp_aux_track_link_training(0, DAT_EXTMEM_a548, 1);
    else if ((DAT_EXTMEM_a548[0] & 0xf0) == 0x80) dp_aux_track_link_training(1, DAT_EXTMEM_a548, 1);
}
