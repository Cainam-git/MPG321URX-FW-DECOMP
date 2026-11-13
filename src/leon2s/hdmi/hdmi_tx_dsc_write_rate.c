/* hdmi_tx_dsc_write_rate  (FUN_a00dd154)
 *
 * Compute the compressed-stream rate value of an HDMI transmitter and write it.
 * Name basis: descriptive - from the timing record, a divisor register and two factors; prints
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dd154 @ 0xa00dd154-0xa00dd37c (552 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - word_0x20 is read into its own variable; its three upper bytes go into unsigned int locals before the
 *    sum byte1 + (byte2 << 8) + (byte3 << 16);
 *  - the frequency word is shifted into `value` (reused) before the low-byte store;
 *  - the local declarations, their types and the initial values of scale_div / scale_mul stay as written,
 *    including the unused int locals q and num.
 */

/* The compression encoder record (written by sys_dsc_enc_set_parameters / sys_dsc_enc_configure). */
struct dsc_encoder_rec {
    unsigned char bytes_0x0[4];
    unsigned char bit_depth;            /* +4, printed here as 'deepcolor' */
    unsigned char bytes_0x5[2];
    unsigned char format;               /* +7: DSC_FORMAT_* */
    unsigned char bytes_0x8[0x18];
    unsigned int word_0x20;             /* bits 0..1 + bit 7: shift; bits 8..31: rate value */
};
extern struct dsc_encoder_rec dsc_encoder_record;
extern int dbg_printf(const char *, ...);
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

/* Clock synthesiser 1, the registers sys_dsc_dec_set_pll writes in mode 1: the 24-bit frequency word, one
   byte per register, written here between clearing bit 7 of 0xCF014100 and setting bit 7 of 0xCF014114. */
#define PLL1_REG_4100             0xcf014100
#define PLL1_FREQ_LOW             0xcf014104
#define PLL1_FREQ_MID             0xcf014108
#define PLL1_FREQ_HIGH            0xcf01410c
#define PLL1_REG_4114             0xcf014114
#define PLL1_REG_BIT7             0x80

#define DP_TX_REG_LANE_COUNT      3             /* DP output register 3, low bits = lane count */
#define HDMI_TX_LAST_PORT         1

#define RATE_SHIFT_MASK           3
#define RATE_SHIFT_EXTRA          0x80          /* adds 1 to the shift */

/*
 * Write the frequency word of clock synthesiser 1 for output `port` from the rate value in word_0x20 of
 * dsc_encoder_record. Called by hdmi_tx_dsc_setup (step DSC of hdmi_tx_run_step) after
 * hdmi_tx_dsc_write_timing. Prints the record's bit depth first.
 *
 *   1. bpp_divisor as in hdmi_tx_dsc_write_timing: from the bits per pixel in encoder word 1 (bpp_x16).
 *      RGB, YUV444 and YUV422_SIMPLE: 24 / (bpp_x16 >> 4); YUV422: 16, YUV420 (and any other format): 12,
 *      each divided by bpp_x16 >> 5 and rounded up.
 *   2. The two factors. HDMI ports 0 and 1: 2 and 1. Any other port: 4 and 1 when sys_return_zero gives 1
 *      (it returns 0), else by the lane count of DP output 0: 4 lanes 2 and 1, 2 lanes 4 and 3, 1 lane 2 and
 *      3, any other count 0 and 1. Unlike hdmi_tx_dsc_write_timing both factors divide here.
 *   3. rate = (bits 8..31 of word_0x20) << shift / bpp_divisor / (scale_div * scale_mul), with shift = bits
 *      0..1 of word_0x20 plus 1 when bit 7 is set.
 *   4. The frequency word rate >> 1 goes byte by byte into 0xCF014104 / 108 / 10C.
 */
void hdmi_tx_dsc_write_rate(unsigned int port)
{
    unsigned char format, bpp_divisor, scale_div = 0, scale_mul = 1, dp_lanes, shift;
    unsigned short bpp_x16;
    int q, num;
    unsigned int value, word_0x20, rate;
    unsigned int byte1, byte2, byte3;

    format = dsc_encoder_record.format;
    dbg_printf("\033[1;31minput DSC Encoder's deepcolor = %d\n\033[m", dsc_encoder_record.bit_depth);
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
    if ((port & 0xff) <= HDMI_TX_LAST_PORT) {
        scale_div = 2;
        scale_mul = 1;
    } else {
        dp_lanes = dp_tx_reg_read8(0, DP_TX_REG_LANE_COUNT) & 0xf;
        if ((sys_return_zero(0) & 0xff) == 1) {
            scale_div = 4;
            scale_mul = 1;
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
    }
    word_0x20 = dsc_encoder_record.word_0x20;
    shift = word_0x20 & RATE_SHIFT_MASK;
    if (word_0x20 & RATE_SHIFT_EXTRA)
        shift++;
    byte1 = (word_0x20 >> 8) & 0xff;
    byte2 = (word_0x20 >> 16) & 0xff;
    byte3 = word_0x20 >> 24;
    value = byte1 + (byte2 << 8) + (byte3 << 16);
    rate = (value << shift) / bpp_divisor / (scale_div * scale_mul);
    R(PLL1_REG_4100) &= ~PLL1_REG_BIT7;
    value = rate >> 1;
    R(PLL1_FREQ_LOW) = value & 0xff;
    R(PLL1_FREQ_MID) = (rate >> 9) & 0xff;
    R(PLL1_FREQ_HIGH) = (rate >> 17) & 0xff;
    R(PLL1_REG_4114) |= PLL1_REG_BIT7;
}
