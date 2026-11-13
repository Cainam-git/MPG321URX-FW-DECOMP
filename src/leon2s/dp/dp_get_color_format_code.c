/* dp_get_color_format_code  (FUN_a00ada24)
 *
 * Work out the colour format code of a port's stream.
 * Returns: code
 * Name basis: derived - from two register readings with table look-ups
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ada24 @ 0xa00ada24-0xa00add0c, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - one exit: the two halves are the arms of one if/else and the function ends in a single 'return code;';
 *  - code is one unsigned int variable for the whole function (the 0xa / 0x1a ?: results go straight into the
 *    return register);
 *  - grouped case labels for the shared codes.
 */

/* DP input record (300 bytes per DP receiver, dp_input_records); only byte 0x11f is used here. */
struct dp_input_record {
    unsigned char bytes_0x0[0x11f];
    unsigned char byte_0x11f;               /* 1 = status block read in the port interrupt */
    unsigned char bytes_0x120[0x12c - 0x120];
};
extern struct dp_input_record dp_input_records[];

/* Receiver registers. The colour depth routine dp_get_color_depth picks its source the same way. */
#define DP_STATUS_REG_5         5           /* status block (dp_status_reg_read8) */
#define DP_STATUS5_BIT2         0x04
#define DP_REG_8D               0x8d        /* second source: bits 1..4 give the format */
#define DP_REG_8E               0x8e
#define DP_REG_8E_USE_BD        0x40        /* with status 5 bit 2: take register 0xBD */
#define DP_REG_8E_BIT7          0x80        /* second source: gives FORMAT_CODE_OTHER */
#define DP_REG_BD               0xbd        /* read twice, with register 0xBE bit 7 clear and set */
#define DP_REG_BE               0xbe
#define DP_REG_BE_BIT7          0x80

#define FORMAT_CODE_OTHER       1           /* every value without a code of its own */

extern unsigned int dp_status_reg_read8(unsigned char, unsigned short);
extern unsigned int dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char dp_get_msa_bit3(unsigned char);
extern unsigned char dp_is_msa_bit4_clear(unsigned char);

/*
 * Work out the colour format code of the stream on a DP receiver from the receiver's registers.
 *
 *   port      DP receiver 0 or 1
 *   dsc_flag  the caller passes bit 1 of the port record's published_flags (PORT_FLAG_DSC)
 *
 * Called by dp_run_link_state, which keeps the result in the port record's colour_space, prints it as
 * 'DP_GetClrSpace(%d) %02x' and, while the link is ready, compares it again ('color space changed'). The
 * same code numbers are what the main program's input_csc_setup calls the colour format code.
 *
 * First source (bit 2 of status register 5 and bit 6 of register 0x8E both set):
 *   1. read register 0xBD twice, first with bit 7 of register 0xBE clear (format), then with it set (second
 *      reading); bit 7 of 0xBE is cleared again;
 *   2. look the format up:
 *        low nibble     0     1     2/4/5   3     6     7
 *        high nibble 1  0x03  0x09  0x0f    0x15  0x1d  0x23
 *        high nibble 2  0x05  0x0b  0x11    0x17  0x1f  0x25
 *        high nibble 3  0x07  0x0d  0x13    0x19  0x21  0x27
 *      format 0x06 gives 0x1b, every other format FORMAT_CODE_OTHER;
 *   3. formats 0x20..0x27: subtract 2 when dp_get_msa_bit3 returns non-zero;
 *   4. subtract 1 when bit 7 of the second reading is set.
 * Second source (otherwise): the format is bits 1..4 of register 0x8D (kept in place, mask 0x1e).
 *   bit 7 of register 0x8E set gives FORMAT_CODE_OTHER; else 0x0a gives 2 (4 when dp_get_msa_bit3 is 0),
 *   0x1a gives 8 (10), 0x0c gives 2, 0x1c 8, 0x02 0x10, 0x12 0x16, 0x04 0x0e, 0x14 0x14.
 *   0x08 gives 8, but 0 unless dp_is_msa_bit4_clear, dsc_flag and byte 0x11f of the input record are all
 *   non-zero; every other format gives FORMAT_CODE_OTHER, or 8 under the same three conditions.
 */
unsigned char dp_get_color_format_code(unsigned char port, unsigned char dsc_flag)
{
    unsigned int code;
    unsigned char format;
    unsigned char second_reading;

    if ((dp_status_reg_read8(port, DP_STATUS_REG_5) & DP_STATUS5_BIT2) && (dp_reg_read8(port, DP_REG_8E) & DP_REG_8E_USE_BD)) {
        /* First source, step 1. */
        dp_reg_update_bits(port, DP_REG_BE, DP_REG_BE_BIT7, 0);
        format = dp_reg_read8(port, DP_REG_BD);
        dp_reg_update_bits(port, DP_REG_BE, DP_REG_BE_BIT7, 1);
        second_reading = dp_reg_read8(port, DP_REG_BD);
        dp_reg_update_bits(port, DP_REG_BE, DP_REG_BE_BIT7, 0);
        /* Step 2: table look-up. */
        switch (format) {
        case 6:
            code = 0x1b;
            break;
        case 0x10:
            code = 3;
            break;
        case 0x11:
            code = 9;
            break;
        case 0x13:
            code = 0x15;
            break;
        case 0x12:
        case 0x14:
        case 0x15:
            code = 0xf;
            break;
        case 0x16:
            code = 0x1d;
            break;
        case 0x17:
            code = 0x23;
            break;
        case 0x20:
            code = 5;
            break;
        case 0x21:
            code = 0xb;
            break;
        case 0x23:
            code = 0x17;
            break;
        case 0x22:
        case 0x24:
        case 0x25:
            code = 0x11;
            break;
        case 0x26:
            code = 0x1f;
            break;
        case 0x27:
            code = 0x25;
            break;
        case 0x30:
            code = 7;
            break;
        case 0x31:
            code = 0xd;
            break;
        case 0x33:
            code = 0x19;
            break;
        case 0x32:
        case 0x34:
        case 0x35:
            code = 0x13;
            break;
        case 0x36:
            code = 0x21;
            break;
        case 0x37:
            code = 0x27;
            break;
        default:
            code = FORMAT_CODE_OTHER;
            break;
        }
        if (format >= 0x20 && format <= 0x27) {        /* step 3 */
            if (dp_get_msa_bit3(port))
                code -= 2;
        }
        if (second_reading & 0x80)                      /* step 4 */
            code -= 1;
    } else {
        /* Second source. */
        format = dp_reg_read8(port, DP_REG_8D) & 0x1e;
        if (dp_reg_read8(port, DP_REG_8E) & DP_REG_8E_BIT7)
            code = FORMAT_CODE_OTHER;
        else switch (format) {
        case 0xa:
            code = dp_get_msa_bit3(port) ? 2 : 4;
            break;
        case 0x1a:
            code = dp_get_msa_bit3(port) ? 8 : 10;
            break;
        case 0xc:
            code = 2;
            break;
        case 0x1c:
            code = 8;
            break;
        case 2:
            code = 0x10;
            break;
        case 0x12:
            code = 0x16;
            break;
        case 4:
            code = 0xe;
            break;
        case 0x14:
            code = 0x14;
            break;
        case 8:
            if (dp_is_msa_bit4_clear(port) && dsc_flag) {
                code = 8;
                if (!dp_input_records[port].byte_0x11f)
                    code = 0;
            } else
                code = 0;
            break;
        default:
            code = FORMAT_CODE_OTHER;
            if (dp_is_msa_bit4_clear(port) && dsc_flag) {
                code = 8;
                if (!dp_input_records[port].byte_0x11f)
                    code = FORMAT_CODE_OTHER;
            }
            break;
        }
    }
    return code;
}
