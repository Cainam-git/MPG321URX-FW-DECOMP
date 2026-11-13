/* hdmi_tx_dsc_write_timing  (FUN_a00dcdb8)
 *
 * Write the compression timing values of an HDMI transmitter.
 * Name basis: descriptive - 16-bit values packed into words; a step of hdmi_tx_run_step
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dcdb8 @ 0xa00dcdb8-0xa00dd154 (924 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - every value is computed first, in record field order (half_0x08 into `half8` and scaled, then width,
 *    half_0x0c, half_0x0e + half_0x0c; height and half_0x14 read into unsigned short locals), then the
 *    registers are written in address order, each value composed at its write;
 *  - the sums are written 'half_0x0e + half_0x0c' and 'half_0x16 + half_0x14';
 *  - each timing word is first ANDed (0xffff, then 0) and then written;
 *  - the 0x948 / 0x2010 tail reuses the shifted copy ('half8 >>= 2; half8_div8 = half8 >> 1;' before the
 *    0x948 store);
 *  - the local declarations, their types and the initial values of scale_div / scale_mul stay as written.
 */

/* The compression encoder record (written by sys_dsc_enc_set_parameters / sys_dsc_enc_configure). The
   halfwords whose meaning is not shown keep their byte offsets. */
struct dsc_encoder_rec {
    unsigned char bytes_0x0[7];
    unsigned char format;               /* +7: DSC_FORMAT_* */
    unsigned short half_0x08;
    unsigned short width;               /* +0xA */
    unsigned short half_0x0c;
    unsigned short half_0x0e;
    unsigned short half_0x10;
    unsigned short height;              /* +0x12 */
    unsigned short half_0x14;
    unsigned short half_0x16;
};
extern struct dsc_encoder_rec dsc_encoder_record;
extern unsigned int dp_tx_reg_read8(unsigned int, unsigned int);
extern unsigned int sys_return_zero(unsigned int);

#define DSC_FORMAT_RGB            0
#define DSC_FORMAT_YUV422         1
#define DSC_FORMAT_YUV420         2
#define DSC_FORMAT_YUV444         3
#define DSC_FORMAT_YUV422_SIMPLE  4

#define R(a) (*(volatile unsigned int *)(a))

/* Encoder parameter word 1 (sys_dsc_enc_compute_pps): bits 16..25 = bits per pixel * 16, the bits per pixel
   doubled for YUV422 and YUV420. */
#define DSC_ENC_WORD1             0xc0110004
#define DSC_ENC_WORD1_BPP_SHIFT   16
#define DSC_ENC_WORD1_BPP_MASK    0x3ff

#define DSC_TX_REG_8000           0xc0118000    /* 0, or lane count << 4 | mode | 0x100 for an output above 1 */
#define DSC_TX_REG_8000_BIT8      0x100

/* Timing words, at the same offsets as the block sys_dsc_enc_write_timing_words writes at 0xC0120800. */
#define DSC_TX_TIMING(offset)     (0xc0120900 + (offset))
#define DSC_TX_REG_2010           0xc0122010

#define DP_TX_REG_LANE_COUNT      3             /* DP output register 3, low bits = lane count */
#define HDMI_TX_LAST_PORT         1

/*
 * Write the timing words of the compression path of output `port` from dsc_encoder_record. Called by
 * hdmi_tx_dsc_setup (step DSC of hdmi_tx_run_step) before hdmi_tx_dsc_write_rate, which finds bpp_divisor
 * and its factors in nearly the same way.
 *
 *   1. bpp_divisor: from the bits per pixel the encoder holds in its word 1 (bpp_x16). RGB, YUV444 and
 *      YUV422_SIMPLE: 24 / (bpp_x16 >> 4). YUV422: 16, YUV420 (and any other format): 12, each divided by
 *      bpp_x16 >> 5 and rounded up.
 *   2. Register 0xC0118000 is cleared. HDMI ports 0 and 1: the scaled values are divided by 2 and the high
 *      half of word +0x24 gets 4 added. Any other port: the factors come from the lane count of DP output 0
 *      and the value of sys_return_zero (both written to 0xC0118000 with bit 8), and the addition is 3:
 *        mode 1 (never; sys_return_zero returns 0): 4 lanes divide by 4;
 *        mode 0: 4 lanes divide by 2, 2 lanes multiply by 3/4, 1 lane by 3/2.
 *      In the cases not listed scale_div stays 0.
 *   3. Each scaled value is value / bpp_divisor / scale_div * scale_mul. The words:
 *        +0x14 = 0x12000210              +0x18 = 0xFFFF0000
 *        +0x1C = half_0x08 scaled << 16 | 0xFFFF
 *        +0x20 = half_0x0c scaled << 16 | half_0x14
 *        +0x24 = (half_0x0e + half_0x0c) scaled | (half_0x16 + half_0x14 + addition) << 16
 *        +0x28 = width scaled in both halves
 *        +0x2C = height
 *        +0x48 = half_0x08 >> 2, +0x78 = 0, and 0xC0122010 = half_0x08 >> 3.
 */
void hdmi_tx_dsc_write_timing(unsigned int port)
{
    unsigned char format, bpp_divisor, scale_div = 0, scale_mul = 1, dp_lanes, mode, high_add;
    unsigned short bpp_x16, half8, half8_div8, height, half_0x14;
    unsigned int half8_scaled, half_0x0c_scaled;
    unsigned short sum_scaled, width_scaled;

    format = dsc_encoder_record.format;
    bpp_x16 = (R(DSC_ENC_WORD1) >> DSC_ENC_WORD1_BPP_SHIFT) & DSC_ENC_WORD1_BPP_MASK;
    if (format == DSC_FORMAT_RGB || format == DSC_FORMAT_YUV444 || format == DSC_FORMAT_YUV422_SIMPLE)
        bpp_divisor = 24 / (bpp_x16 >> 4);
    else if (format == DSC_FORMAT_YUV422) {
        bpp_x16 >>= 5;
        bpp_divisor = (16 % bpp_x16 == 0) ? 16 / bpp_x16 : 16 / bpp_x16 + 1;
    } else {
        bpp_x16 >>= 5;
        bpp_divisor = (12 % bpp_x16 == 0) ? 12 / bpp_x16 : 12 / bpp_x16 + 1;
    }
    R(DSC_TX_REG_8000) = 0;
    if ((port & 0xff) <= HDMI_TX_LAST_PORT) {
        high_add = 4;
        scale_div = 2;
        scale_mul = 1;
    } else {
        dp_lanes = dp_tx_reg_read8(0, DP_TX_REG_LANE_COUNT) & 0xf;
        mode = sys_return_zero(0);
        high_add = 3;
        if (mode == 1) {
            if (dp_lanes == 4) {
                scale_div = 4;
                scale_mul = 1;
            }
        } else if (dp_lanes == 4) {
            scale_div = 2;
            scale_mul = 1;
        } else if (dp_lanes == 2) {
            scale_div = 4;
            scale_mul = 3;
        } else if (dp_lanes == 1) {
            scale_div = 2;
            scale_mul = 3;
        }
        R(DSC_TX_REG_8000) = (dp_lanes << 4) | mode | DSC_TX_REG_8000_BIT8;
    }
    half8 = dsc_encoder_record.half_0x08;
    half8_scaled = half8 / bpp_divisor / scale_div * scale_mul;
    width_scaled = dsc_encoder_record.width / bpp_divisor / scale_div * scale_mul;
    half_0x0c_scaled = dsc_encoder_record.half_0x0c / bpp_divisor / scale_div * scale_mul;
    sum_scaled = (dsc_encoder_record.half_0x0e + dsc_encoder_record.half_0x0c) / bpp_divisor / scale_div * scale_mul;
    height = dsc_encoder_record.height;
    half_0x14 = dsc_encoder_record.half_0x14;
    R(DSC_TX_TIMING(0x14)) = 0x12000210;
    R(DSC_TX_TIMING(0x18)) = 0xffff0000;
    R(DSC_TX_TIMING(0x1c)) &= 0xffff;
    R(DSC_TX_TIMING(0x1c)) = (half8_scaled << 16) | 0xffff;
    R(DSC_TX_TIMING(0x20)) &= 0;
    R(DSC_TX_TIMING(0x20)) = (half_0x0c_scaled << 16) | half_0x14;
    R(DSC_TX_TIMING(0x24)) &= 0;
    R(DSC_TX_TIMING(0x24)) = sum_scaled | ((unsigned int)((unsigned short)(dsc_encoder_record.half_0x16 + half_0x14) + high_add) << 16);
    R(DSC_TX_TIMING(0x28)) &= 0;
    R(DSC_TX_TIMING(0x28)) = width_scaled | ((unsigned int)width_scaled << 16);
    R(DSC_TX_TIMING(0x2c)) &= 0;
    R(DSC_TX_TIMING(0x2c)) = height;
    half8 >>= 2;
    half8_div8 = half8 >> 1;
    R(DSC_TX_TIMING(0x48)) = half8;
    R(DSC_TX_TIMING(0x78)) = 0;
    R(DSC_TX_REG_2010) = half8_div8;
}
