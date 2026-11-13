/* dp_tx_set_video_timing  (FUN_a0087ec8)
 *
 * Program the video timing and stream registers of a DP output.
 *   port_arg: output
 *   size: timing values
 * Name basis: derived - eight timing halfwords to registers 0x56..0x65 plus stream options; caller
 *   ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0087ec8 @ 0xa0087ec8-0xa00883b0 (1256 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the output parameter is unsigned int; the first part works on one unsigned char copy (port), the last part
 *    on a second copy (port_again) taken after the output 0 block, because the firmware extends the parameter
 *    again there;
 *  - the choice on the bits per colour is an if/else chain; the choice on byte 0x14 is a switch whose cases 0
 *    and 1 have their own body equal to the default (that keeps the jump table starting at 0), with the cases
 *    listed in the firmware's block order;
 *  - the path record is read through bit-fields of an unsigned int (one word load per test).
 */

/*
 * Path record of one DP output (40 bytes each, dp_tx_path_records). Mailbox commands 0x50..0x53 fill it from the
 * main program's output record: word 0 bits 25 and 27..31 are flag bits of that record, +4..+0x12 its eight
 * size values (h0..h7 of the main program's struct output_size_block), byte +0x14 its byte_0x14 and byte +0x15
 * its bits per colour (from the active panel row). Command 0x52 writes keep_reg50 alone, command 0x53
 * keep_timing alone.
 */
struct path_record {
    unsigned int bits_29_31 : 3;
    unsigned int keep_timing : 1;       /* bit 28: 1 = registers 0x56..0x65 are not written here */
    unsigned int keep_reg50 : 1;        /* bit 27: 1 = registers 0x50..0x52 are not rewritten here */
    unsigned int bit26 : 1;
    unsigned int reg70_bit5 : 1;        /* bit 25: copied to register 0x70 bit 5 */
    unsigned int bits_0_24 : 25;
    unsigned short size[8];             /* +4: the eight size values */
    unsigned char byte_0x14;            /* returned by dp_tx_get_path_byte20 */
    unsigned char bits_per_colour;      /* +0x15, returned by dp_tx_get_path_bits_per_colour */
    unsigned short half_0x16;
    unsigned int word_0x18;
    unsigned int word_0x1c;
    unsigned int word_0x20;
    unsigned int word_0x24;
};
extern struct path_record dp_tx_path_records[];

/* Transmitter registers that receive the eight size values, high byte first (low byte at register + 1). */
#define TX_REG_LINE_LENGTH_HI   0x56    /* size[0]: line length */
#define TX_REG_LINE_LENGTH_LO   0x57
#define TX_REG_SIZE5_HI         0x58    /* size[5]: twice size[4] */
#define TX_REG_SIZE5_LO         0x59
#define TX_REG_ACTIVE_WIDTH_HI  0x5a    /* size[2]: active width */
#define TX_REG_ACTIVE_WIDTH_LO  0x5b
#define TX_REG_SIZE4_HI         0x5c    /* size[4]: (line length - active width) / 3 */
#define TX_REG_SIZE4_LO         0x5d
#define TX_REG_FRAME_LENGTH_HI  0x5e    /* size[1]: frame length */
#define TX_REG_FRAME_LENGTH_LO  0x5f
#define TX_REG_SIZE7_HI         0x60    /* size[7]: twice size[6] */
#define TX_REG_SIZE7_LO         0x61
#define TX_REG_ACTIVE_HEIGHT_HI 0x62    /* size[3]: active height */
#define TX_REG_ACTIVE_HEIGHT_LO 0x63
#define TX_REG_SIZE6_HI         0x64    /* size[6]: (frame length - active height) / 3 */
#define TX_REG_SIZE6_LO         0x65

#define TX_REG_0x50             0x50    /* 24-bit value in registers 0x50..0x52, 0x50 = high byte */

#define DP_TX_OUTPUT_0          0       /* output 0 is the DP transmitter, 1..4 the eDP ones */

#define BITS_CLEAR              0       /* mode argument of dp_tx_reg_update_bits */
#define BITS_SET                1

extern void dp_tx_reg_update_bits(unsigned int port, short reg, unsigned int mask, unsigned int mode);
extern int dp_tx_reg_read24_stable(unsigned char port, unsigned short reg);
extern void dp_tx_reg_write8(unsigned int port, unsigned short reg, unsigned int v);
extern void dp_tx_set_reg70_bit5(unsigned char port, unsigned char v);
extern unsigned char dp_tx_get_path_bits_per_colour(unsigned int port);
extern unsigned char dp_tx_get_path_byte20(unsigned int port);
extern void dp_tx_write_regs_69_6a(unsigned char port, unsigned char a, unsigned char b);
extern void dp_tx_switch_reg_setup(unsigned int port, unsigned char en);
extern void dp_tx_set_lane_routing(unsigned char port);
extern void timer_delay_long_units(int);

/*
 * Write the stored path record of a DP output into its transmitter registers.
 *
 *   port_arg  output number (low byte used): 0 = DP transmitter, 1..4 = eDP
 *   size      the eight size values of the output's path record (a copy of dp_tx_path_records[port].size)
 *
 * Called by ipc_dispatch_command for mailbox commands 0x50..0x53, each time after it has changed the path
 * record of the output.
 *
 * Phases, in order:
 *   1. Set register 0x6f bit 0, register 0x70 bits 0, 2 and 3 and register 0x6d bits 3 and 7; copy the
 *      record's bit 25 into register 0x70 bit 5.
 *   2. Unless keep_reg50 is set: wait, read the 24-bit value of registers 0x50..0x52 (dp_tx_reg_read24_stable)
 *      and write it back, then clear register 0x70 bit 2.
 *   3. Output 0 only: from the record's bits per colour and its byte 0x14 compute registers 0x66, 0x67, 0x69
 *      and 0x6a and bits 2 and 3 of register 0x6f; switch the register set-up of dp_tx_switch_reg_setup by
 *      whether register 0x67 got a value; rewrite the lane routing.
 *   4. Unless keep_timing is set: write the eight size values to registers 0x56..0x65, then clear register
 *      0x70 bit 0 and register 0x6d bits 3 and 7.
 *   5. Pulse register 0 bit 3 (set, then clear).
 * Register 0x6f bit 0 and register 0x70 bit 3 stay set.
 */
void dp_tx_set_video_timing(unsigned int port_arg, unsigned short *size)
{
    unsigned char port = port_arg;
    unsigned char port_again;
    unsigned int reg50_value;
    unsigned char reg66;
    unsigned char reg67 = 0;
    unsigned char reg69 = 0;
    unsigned char reg6a;
    unsigned char bits_per_colour;

    /* Phase 1. */
    dp_tx_reg_update_bits(port, 0x6f, 1, BITS_SET);
    dp_tx_reg_update_bits(port, 0x70, 0xd, BITS_SET);
    dp_tx_reg_update_bits(port, 0x6d, 0x88, BITS_SET);
    dp_tx_set_reg70_bit5(port, dp_tx_path_records[port].reg70_bit5);

    /* Phase 2: rewrite registers 0x50..0x52 with their own value. */
    if (!dp_tx_path_records[port].keep_reg50) {
        timer_delay_long_units(0x50);
        reg50_value = dp_tx_reg_read24_stable(port, TX_REG_0x50);
        dp_tx_reg_write8(port, 0x52, reg50_value & 0xff);
        reg50_value >>= 8;
        dp_tx_reg_write8(port, 0x51, reg50_value & 0xff);
        reg50_value >>= 8;
        dp_tx_reg_write8(port, 0x50, reg50_value & 0xff);
        dp_tx_reg_update_bits(port, 0x70, 4, BITS_CLEAR);
    }

    /* Phase 3: colour and stream registers, output 0 only. */
    if (port == DP_TX_OUTPUT_0) {
        /* Bits per colour 6 / 8 / 10 give register 0x66 bits 5..6 = 0 / 1 / 2 and register 0x6a = 0x80 / 0x81 /
           0x82; any other value is treated as 8. */
        bits_per_colour = dp_tx_get_path_bits_per_colour(DP_TX_OUTPUT_0);
        if (bits_per_colour == 8) {
            reg66 = 0x20;
            reg6a = 0x81;
        } else if (bits_per_colour == 6) {
            reg66 = 0;
            reg6a = 0x80;
        } else if (bits_per_colour == 10) {
            reg66 = 0x40;
            reg6a = 0x82;
        } else {
            reg66 = 0x20;
            reg6a = 0x81;
        }
        /*
         * Byte 0x14 of the record, taken in pairs (2k and 2k+1 act the same):
         *   6 / 12 / 18 / 24        register 0x67 = 0x40, register 0x69 = 0x30 / 0x31 / 0x32 / 0x33,
         *                           register 0x6f bit 3 set, bit 2 clear
         *   2 / 8 / 14 / 20         register 0x66 |= 0x0c / 0x1c / 0x04 / 0x14, register 0x6f bits 2 and 3 clear
         *   4 / 10 / 16 / 22        register 0x66 |= 0x0a / 0x1a / 0x02 / 0x12, register 0x6f bit 2 set, bit 3 clear
         *   0 and above 25          nothing added, register 0x6f bits 2 and 3 clear
         */
        switch (dp_tx_get_path_byte20(DP_TX_OUTPUT_0)) {
        case 6:
        case 7:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_CLEAR);
            reg67 = 0x40;
            reg69 = 0x30;
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_SET);
            break;
        case 12:
        case 13:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_CLEAR);
            reg67 = 0x40;
            reg69 = 0x31;
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_SET);
            break;
        case 18:
        case 19:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_CLEAR);
            reg67 = 0x40;
            reg69 = 0x32;
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_SET);
            break;
        case 24:
        case 25:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_CLEAR);
            reg67 = 0x40;
            reg69 = 0x33;
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_SET);
            break;
        case 2:
        case 3:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_CLEAR);
            reg66 |= 0xc;
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_CLEAR);
            break;
        case 4:
        case 5:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_SET);
            reg66 |= 0xa;
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_CLEAR);
            break;
        case 8:
        case 9:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_CLEAR);
            reg66 |= 0x1c;
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_CLEAR);
            break;
        case 10:
        case 11:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_SET);
            reg66 |= 0x1a;
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_CLEAR);
            break;
        case 14:
        case 15:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_CLEAR);
            reg66 |= 4;
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_CLEAR);
            break;
        case 16:
        case 17:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_SET);
            reg66 |= 2;
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_CLEAR);
            break;
        case 20:
        case 21:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_CLEAR);
            reg66 |= 0x14;
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_CLEAR);
            break;
        case 22:
        case 23:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_SET);
            reg66 |= 0x12;
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_CLEAR);
            break;
        case 0:
        case 1:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_CLEAR);
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_CLEAR);
            break;
        default:
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 4, BITS_CLEAR);
            dp_tx_reg_update_bits(DP_TX_OUTPUT_0, 0x6f, 8, BITS_CLEAR);
            break;
        }
        dp_tx_reg_write8(DP_TX_OUTPUT_0, 0x66, reg66);
        dp_tx_reg_write8(DP_TX_OUTPUT_0, 0x67, reg67);
        dp_tx_write_regs_69_6a(DP_TX_OUTPUT_0, reg69, reg6a);
        if (reg67)
            dp_tx_switch_reg_setup(DP_TX_OUTPUT_0, 1);
        else
            dp_tx_switch_reg_setup(DP_TX_OUTPUT_0, 0);
        dp_tx_set_lane_routing(DP_TX_OUTPUT_0);
    }

    /* Phase 4: the eight size values. */
    port_again = port_arg;
    if (!dp_tx_path_records[port_again].keep_timing) {
        dp_tx_reg_write8(port_again, TX_REG_LINE_LENGTH_LO, size[0] & 0xff);
        dp_tx_reg_write8(port_again, TX_REG_LINE_LENGTH_HI, size[0] >> 8);
        dp_tx_reg_write8(port_again, TX_REG_FRAME_LENGTH_LO, size[1] & 0xff);
        dp_tx_reg_write8(port_again, TX_REG_FRAME_LENGTH_HI, size[1] >> 8);
        dp_tx_reg_write8(port_again, TX_REG_ACTIVE_WIDTH_LO, size[2] & 0xff);
        dp_tx_reg_write8(port_again, TX_REG_ACTIVE_WIDTH_HI, size[2] >> 8);
        dp_tx_reg_write8(port_again, TX_REG_ACTIVE_HEIGHT_LO, size[3] & 0xff);
        dp_tx_reg_write8(port_again, TX_REG_ACTIVE_HEIGHT_HI, size[3] >> 8);
        dp_tx_reg_write8(port_again, TX_REG_SIZE4_LO, size[4] & 0xff);
        dp_tx_reg_write8(port_again, TX_REG_SIZE4_HI, size[4] >> 8);
        dp_tx_reg_write8(port_again, TX_REG_SIZE5_LO, size[5] & 0xff);
        dp_tx_reg_write8(port_again, TX_REG_SIZE5_HI, size[5] >> 8);
        dp_tx_reg_write8(port_again, TX_REG_SIZE6_LO, size[6] & 0xff);
        dp_tx_reg_write8(port_again, TX_REG_SIZE6_HI, size[6] >> 8);
        dp_tx_reg_write8(port_again, TX_REG_SIZE7_LO, size[7] & 0xff);
        dp_tx_reg_write8(port_again, TX_REG_SIZE7_HI, size[7] >> 8);
        dp_tx_reg_update_bits(port_again, 0x70, 1, BITS_CLEAR);
        dp_tx_reg_update_bits(port_again, 0x6d, 0x88, BITS_CLEAR);
    }

    /* Phase 5. */
    dp_tx_reg_update_bits(port_again, 0, 8, BITS_SET);
    dp_tx_reg_update_bits(port_again, 0, 8, BITS_CLEAR);
}
