/* ipc_configure_dsc_encoder  (FUN_a0138c50)
 *
 * Ask the input processor to configure the picture compression encoder.
 * Name basis: derived - command 0xA5 through the mailbox portal 1 sender; unused; mailbox command 0xA5, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138c50 @ 0xa0138c50-0xa0138e28 (118 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the message is a zeroed local array; the register choice is an
 * if/else-if chain on encoder->source (a switch gives a compare tree); volatile only on the hardware registers.
 */
#define R(a) (*(volatile unsigned int *)(a))            /* 8-bit register in a 32-bit word */

#define IPC_CMD_CONFIGURE_DSC_ENCODER 0xa5              /* command number in the input program's dispatcher */
#define DSC_COMMAND_BYTES             0x18
#define IPC_SEND_NO_WAIT              0

/* Encoder sources, as the input program names them (sys_dsc_enc_select_route). */
#define DSC_SOURCE_DISP  0
#define DSC_SOURCE_P2    2
#define DSC_SOURCE_P3    3

/* Clock generator registers: the 24-bit value lies in the low bytes of value + 0, + 4, + 8. */
#define GPLL_DISPM_VALUE 0xcf012884
#define GPLL_DISP2_VALUE 0xcf012904
#define GPLL_DISP3_VALUE 0xcf012944
#define GPLL_DIVIDERS    0xcf014740                     /* post-dividers: DISPM bits 7..6, DISP2 3..2, DISP3 1..0 */
#define GPLL_REG_10      0x10                           /* the register 0x10 above a generator's value */

/* The leading fields of an encoder timing record, named as in the input program's dsc_encoder_rec. */
struct dsc_encoder_rec {
    unsigned char byte_0x00, byte_0x01, byte_0x02, byte_0x03;
    unsigned char bit_depth;                            /* +4 */
    unsigned char source;                               /* +5: DSC_SOURCE_DISP, _P2 or _P3 */
    unsigned char byte_0x06;
    unsigned char format;                               /* +7: 0 RGB, 1 YUV422, 2 YUV420, 3 YUV444, 4 YUV422_SIMPLE */
    unsigned short half[8];                             /* +8..+0x16: [1] = width, [5] = height */
};
extern void ipc_send_command(int, int, unsigned char *, int);

/*
 * Send command 0xA5 with 24 data bytes to the input processor, whose handler (sys_dsc_enc_configure) copies them
 * into its encoder timing record and then programs the encoder.
 *
 *   byte_0x18  data byte 0; the input program stores it at +0x18 of its record
 *   encoder    the record whose source, format, bit_depth and eight halfwords are sent
 *
 * Data bytes: 0 byte_0x18, 1 source, 2 format, 3 bit_depth, 4..19 half[0..7] (low byte first). Bytes 20..23
 * describe the clock generator of the source: DISPM for DSC_SOURCE_DISP, DISP2 for DSC_SOURCE_P2, DISP3 for
 * DSC_SOURCE_P3. Byte 20 is the generator's 2-bit post-divider ORed with the register 0x10 above its value,
 * bytes 21..23 are its 24-bit value, low byte first. From them the input program computes a value (the 24-bit
 * value shifted left by the low five bits of byte 20, times 10, >> 17, times 12 / 10, doubled when bit 7 of
 * byte 20 is set) and from that the slice count and the bits-per-pixel divisor of its record. For any other source bytes 20..23 stay 0.
 * The command is sent without waiting. No call to this routine was found in the code.
 */
void ipc_configure_dsc_encoder(unsigned char byte_0x18, struct dsc_encoder_rec *encoder)
{
    unsigned char data[24] = { 0 };

    data[0] = byte_0x18;
    data[1] = encoder->source;
    data[2] = encoder->format;
    data[3] = encoder->bit_depth;
    data[4] = encoder->half[0];
    data[5] = encoder->half[0] >> 8;
    data[6] = encoder->half[1];
    data[7] = encoder->half[1] >> 8;
    data[8] = encoder->half[2];
    data[9] = encoder->half[2] >> 8;
    data[10] = encoder->half[3];
    data[11] = encoder->half[3] >> 8;
    data[12] = encoder->half[4];
    data[13] = encoder->half[4] >> 8;
    data[14] = encoder->half[5];
    data[15] = encoder->half[5] >> 8;
    data[16] = encoder->half[6];
    data[17] = encoder->half[6] >> 8;
    data[18] = encoder->half[7];
    data[19] = encoder->half[7] >> 8;
    if (encoder->source == DSC_SOURCE_DISP) {
            data[20] = (R(GPLL_DIVIDERS) >> 6) & 3;
            data[20] |= R(GPLL_DISPM_VALUE + GPLL_REG_10);
            data[21] = R(GPLL_DISPM_VALUE);
            data[22] = R(GPLL_DISPM_VALUE + 4);
            data[23] = R(GPLL_DISPM_VALUE + 8);
    } else if (encoder->source == DSC_SOURCE_P2) {
            data[20] = (R(GPLL_DIVIDERS) >> 2) & 3;
            data[20] |= R(GPLL_DISP2_VALUE + GPLL_REG_10);
            data[21] = R(GPLL_DISP2_VALUE);
            data[22] = R(GPLL_DISP2_VALUE + 4);
            data[23] = R(GPLL_DISP2_VALUE + 8);
    } else if (encoder->source == DSC_SOURCE_P3) {
            data[20] = R(GPLL_DIVIDERS) & 3;
            data[20] |= R(GPLL_DISP3_VALUE + GPLL_REG_10);
            data[21] = R(GPLL_DISP3_VALUE);
            data[22] = R(GPLL_DISP3_VALUE + 4);
            data[23] = R(GPLL_DISP3_VALUE + 8);
    }
    ipc_send_command(IPC_CMD_CONFIGURE_DSC_ENCODER, DSC_COMMAND_BYTES, data, IPC_SEND_NO_WAIT);
}
