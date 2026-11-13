/* hdmi_tx_send_avi_infoframe  (FUN_a0092100)
 *
 * Build and send the AVI InfoFrame of an HDMI TX port.
 *   port: HDMI TX port 0/1
 * Name basis: proven - header 0x82 2 0x0D to regs 0x140..0x142 with checksum; prints 'Color Space = RGB / YUV
 *   709 444'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0092100 @ 0xa0092100-0xa00924d8 (984 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - input_code is assigned in both arms of the 0xE1 / 0xE2 test, which reads source_code itself (an assignment
 *    before the test gives the switch index its own register);
 *  - the zero initialisers of byte4..byte6 are declared between word_0xc_negative and the byte reads;
 *  - the case order 0, 1, 3, 2, 4 of the second switch;
 *  - the checksum is accumulated statement by statement and negated in place;
 *  - the dsc_enable test reads the table entry again instead of through channel.
 */

/* Input codes (byte +1 or +0x17 of the TX channel record). */
enum {
    INPUT_CODE_DP_0 = 0x71,             /* DisplayPort receiver 0 */
    INPUT_CODE_DP_1 = 0x81,             /* DisplayPort receiver 1 */
    SOURCE_CODE_E1  = 0xe1              /* with 0xE1 / 0xE2 the input code is in byte +0x17 */
};

/* Colour space of the output, as the firmware's texts name them ('Color Space = ...'). */
enum {
    AVI_CS_RGB        = 0,
    AVI_CS_YUV709_444 = 1,
    AVI_CS_YUV709_422 = 2,
    AVI_CS_YUV601_444 = 3,
    AVI_CS_YUV601_422 = 4
};
#define CS_STEP_TO_422   2              /* color_space code + 2: the 4:2:2 code of the same family ('AVI 422') */

/* The AVI InfoFrame registers of bank 0: register 0x140 + n holds packet byte n. */
#define TX_BANK_0             0
#define AVI_REG_CONTROL       0x13E     /* bits 0..1 cleared while the packet is rewritten */
#define   AVI_CONTROL_BITS      3
#define AVI_REG_PACKET        0x140
#define AVI_PACKET_TYPE       0x82      /* packet bytes 0..2 */
#define AVI_PACKET_VERSION    2
#define AVI_PACKET_LENGTH     0x0D
#define AVI_REG_CHECKSUM      0x143     /* packet byte 3 */
#define AVI_FIRST_ZERO_BYTE   9         /* packet bytes 9..0x12 are written 0 */
#define AVI_PACKET_END        0x13

/* Limits of pixel_clock for the low bits of packet byte 8 (the mode passed to hdmi_tx_set_pixel_format). */
#define PIXEL_CLOCK_MODE_3_MAX  0x0C
#define PIXEL_CLOCK_MODE_1_MAX  0x19

#define CHANNEL_DSC_ENABLE    8         /* word 0 bit 3 */

/* TX channel record of one HDMI output (28 bytes, hdmi_tx_output_records), seen here as words and bytes. */
struct hdmi_tx_channel_record {
    union {
        unsigned int word;
        unsigned char bytes[4];         /* bytes[1] = source_code */
    } word_0x0;
    unsigned int word_0x4;
    int pixel_clock;                    /* +8 */
    union {
        int word;                       /* bit 31: word_0xc_bit31 */
        unsigned char bytes[4];         /* bytes[1] = color_space (+0xD), bytes[2] = byte_0xe */
    } word_0xc;
    unsigned int word_0x10;
    unsigned char bytes_0x14[4];        /* bytes_0x14[3] = input_code (+0x17) */
    unsigned int word_0x18;
};
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern unsigned int dp_get_msa_bit3(unsigned char);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdmi_tx_set_pixel_format(unsigned char, unsigned int);

/*
 * Build the AVI InfoFrame of one HDMI output from its TX channel record and write it to the transmitter.
 *
 *   port  HDMI TX port 0 or 1
 *
 * Called by hdmi_tx_run_step in set-up step 2 (the step taken when packet_bypass is clear).
 *
 * Phases:
 *   1. Read the record: word_0xc_bit31, color_space, byte_0xe, pixel_clock, and the input code (source_code,
 *      or input_code when source_code is 0xE1 / 0xE2).
 *   2. For a DisplayPort input whose dp_get_msa_bit3 reports 1, step color_space to its 4:2:2 code.
 *   3. Turn color_space into one of the five AVI_CS_* values, printing its name; an unknown code stays as it is
 *      ('Color Space = NG'), matches no case of phase 5 and leaves packet bytes 4..6 at 0 there.
 *   4. Hold the packet (register 0x13E bits 0..1 cleared) and write the header bytes 0x82, 2, 0x0D.
 *   5. Packet bytes 4..6 from the colour space; word_0xc_bit31 adds bit 2 to byte 6 (set) or bit 3 (clear)
 *      and gives byte 8 its bit 6 when clear. Byte 7 = byte_0xe.
 *   6. Unless dsc_enable is set, the low bits of byte 8 follow pixel_clock: 3 up to 0x0C, 1 up to 0x19, else 0.
 *      Byte 8 also goes to hdmi_tx_set_pixel_format.
 *   7. Bytes 9..0x12 are 0; byte 3 is the checksum that makes all packet bytes add up to 0 (mod 256);
 *      register 0x13E bits 0..1 set again.
 */
void hdmi_tx_send_avi_infoframe(unsigned char port)
{
    /* 1. */
    struct hdmi_tx_channel_record *channel = &hdmi_tx_output_records[port];
    unsigned char input_code;
    int word_0xc_negative = channel->word_0xc.word < 0;
    unsigned char byte4 = 0;
    unsigned char byte5 = 0;
    unsigned char byte6 = 0;
    unsigned char byte7 = channel->word_0xc.bytes[2];
    unsigned char color_space = channel->word_0xc.bytes[1];
    int pixel_clock = channel->pixel_clock;
    unsigned char byte8;
    unsigned char checksum;
    unsigned short i;

    if ((unsigned char)(channel->word_0x0.bytes[1] - SOURCE_CODE_E1) < 2)
        input_code = channel->bytes_0x14[3];
    else
        input_code = channel->word_0x0.bytes[1];

    /* 2. DisplayPort inputs. */
    switch (input_code) {
    case INPUT_CODE_DP_0:
        if (dp_get_msa_bit3(0) & 0xff) {
            color_space += CS_STEP_TO_422;
            dbg_printf("AVI 422 \n\r");
        }
        break;
    case INPUT_CODE_DP_1:
        if (dp_get_msa_bit3(1) & 0xff) {
            color_space += CS_STEP_TO_422;
            dbg_printf("AVI 422 \n\r");
        }
        break;
    }

    /* 3. Each colour space has two or four codes. */
    if (color_space < 2) {
        dbg_print_string("\x1b[0m\t\t - Color Space = RGB\n");
        color_space = AVI_CS_RGB;
    } else if ((unsigned char)(color_space - 8) < 2 || color_space == 0x14 || color_space == 0x15) {
        dbg_print_string("\x1b[0m\t\t - Color Space = YUV 709 444\n");
        color_space = AVI_CS_YUV709_444;
    } else if ((unsigned char)(color_space - 2) < 2 || color_space == 0xe || color_space == 0xf) {
        dbg_print_string("\x1b[0m\t\t - Color Space = YUV 601 444\n");
        color_space = AVI_CS_YUV601_444;
    } else if ((unsigned char)(color_space - 10) < 2 || color_space == 0x16 || color_space == 0x17) {
        dbg_print_string("\x1b[0m\t\t - Color Space = YUV 709 422\n");
        color_space = AVI_CS_YUV709_422;
    } else if ((unsigned char)(color_space - 4) < 2 || color_space == 0x10 || color_space == 0x11) {
        dbg_print_string("\x1b[0m\t\t - Color Space = YUV 601 422\n");
        color_space = AVI_CS_YUV601_422;
    } else
        dbg_print_string("\x1b[0m\t\t - Color Space = NG\n");

    /* 4. Header. */
    hdmi_tx_reg_update_bits(port, TX_BANK_0, AVI_REG_CONTROL, AVI_CONTROL_BITS, 0);
    hdmi_tx_reg_write8(port, TX_BANK_0, AVI_REG_PACKET + 0, AVI_PACKET_TYPE);
    hdmi_tx_reg_write8(port, TX_BANK_0, AVI_REG_PACKET + 1, AVI_PACKET_VERSION);
    hdmi_tx_reg_write8(port, TX_BANK_0, AVI_REG_PACKET + 2, AVI_PACKET_LENGTH);

    /* 5. Packet bytes 4..7. */
    switch (color_space) {
    case AVI_CS_RGB:
        byte4 = 2;
        byte5 = 0;
        byte6 = 0;
        break;
    case AVI_CS_YUV709_444:
        byte4 = 0x42;
        byte5 = 0xc0;
        byte6 = 0x10;
        break;
    case AVI_CS_YUV601_444:
        byte4 = 0x42;
        byte5 = 0xc0;
        byte6 = 0;
        break;
    case AVI_CS_YUV709_422:
        byte4 = 0x22;
        byte5 = 0xc0;
        byte6 = 0x10;
        break;
    case AVI_CS_YUV601_422:
        byte4 = 0x22;
        byte5 = 0xc0;
        byte6 = 0;
        break;
    }
    if (word_0xc_negative) {
        byte6 |= 4;
        byte8 = 0;
    } else {
        byte6 |= 8;
        byte8 = 0x40;
    }
    hdmi_tx_reg_write8(port, TX_BANK_0, AVI_REG_PACKET + 4, byte4);
    hdmi_tx_reg_write8(port, TX_BANK_0, AVI_REG_PACKET + 5, byte5);
    hdmi_tx_reg_write8(port, TX_BANK_0, AVI_REG_PACKET + 6, byte6);
    hdmi_tx_reg_write8(port, TX_BANK_0, AVI_REG_PACKET + 7, byte7);
    checksum = AVI_PACKET_TYPE + AVI_PACKET_VERSION + AVI_PACKET_LENGTH;
    checksum += byte4;
    checksum += byte5;
    checksum += byte6;
    checksum += byte7;

    /* 6. Packet byte 8. */
    if (!(hdmi_tx_output_records[port].word_0x0.word & CHANNEL_DSC_ENABLE)) {
        if (pixel_clock <= PIXEL_CLOCK_MODE_3_MAX)
            byte8 |= 3;
        else if (pixel_clock <= PIXEL_CLOCK_MODE_1_MAX)
            byte8 |= 1;
    }
    hdmi_tx_set_pixel_format(port, byte8);
    hdmi_tx_reg_write8(port, TX_BANK_0, AVI_REG_PACKET + 8, byte8);
    checksum += byte8;

    /* 7. Rest of the packet, checksum, release. */
    for (i = AVI_FIRST_ZERO_BYTE; i < AVI_PACKET_END; i++)
        hdmi_tx_reg_write8(port, TX_BANK_0, i + AVI_REG_PACKET, 0);
    checksum = -checksum;
    hdmi_tx_reg_write8(port, TX_BANK_0, AVI_REG_CHECKSUM, checksum);
    hdmi_tx_reg_update_bits(port, TX_BANK_0, AVI_REG_CONTROL, AVI_CONTROL_BITS, 1);
}
