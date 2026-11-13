/* hdmi_init_receivers  (FUN_a008f54c)
 *
 * Load the start-up settings of both HDMI 2.0 receivers.
 * Name basis: derived - fixed register set-up for 'both ports', audio level 0x8000, packet flags set; caller
 *   input_init_receivers
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008f54c @ 0xa008f54c, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the two registers of the 0xCF00F000 block are reached through the local base ((base | offset) as a
 *    volatile pointer);
 *  - the unused locals j and k are kept;
 *  - the callees are declared with int parameters;
 *  - the three hold flags are stored in the order audio, HDR, vendor.
 */

/* Receiver record of an HDMI 2.0 port (0xB0 bytes, hdmi_rx_records[port]); only the hold flags are used here.
   A packet area is copied in by hdmi_poll_rx_status only while its hold flag is 0. */
struct hdmi_rx_record {
    unsigned char bytes_0x0[0x21];
    unsigned char hdr_hold;                     /* +0x21 */
    unsigned char bytes_0x22[0x6a - 0x22];
    unsigned char audio_hold;                   /* +0x6A */
    unsigned char bytes_0x6b[0x8c - 0x6b];
    unsigned char vendor_hold;                  /* +0x8C */
    unsigned char bytes_0x8d[0xb0 - 0x8d];
};
extern struct hdmi_rx_record hdmi_rx_records[];
extern void hdmi_reg_write8(int, int, int);
extern void hdmi_reg_update_bits(int, int, int, int);
extern void audio_set_hdmi_rx_level(int, int);
extern void timer_delay_long_units(int);
extern void hdmi_init_packet_switch(int);
extern void hdmi_reset_reg340_block(int);

#define BOTH_RECEIVERS   2          /* receiver argument of the HDMI 2.0 helpers: both receivers */
#define BITS_CLEAR       0          /* last argument of hdmi_reg_update_bits */
#define BITS_SET         1

/* Receiver registers written here (by number; what they control is not shown). */
#define RX_REG_5         0x005
#define RX_REG_8         0x008
#define RX_REG_41        0x041
#define RX_REG_79        0x079
#define RX_REG_7A        0x07a
#define RX_REG_120       0x120
#define RX_REG_121       0x121
#define RX_REG_124       0x124
#define RX_REG_126       0x126
#define RX_REG_127       0x127
#define RX_REG_128       0x128
#define RX_REG_129       0x129
#define RX_REG_135       0x135
#define RX_REG_1AF       0x1af
#define RX_REG_29F       0x29f
#define RX_REG_2A7       0x2a7
#define RX_REG_2D0       0x2d0
#define RX_REG_2FE       0x2fe

#define BLOCK_F000       0xcf00f000
#define BLOCK_REG_21C    0x21c
#define BLOCK_REG_224   0x224      /* receiver 0: bits 0 and 4, receiver 1: bits 1 and 5 */

#define AUDIO_START_LEVEL 0x8000

/*
 * Give both HDMI 2.0 receivers their start-up register values. Called by input_init_receivers.
 *
 * Nearly every write goes to both receivers at once (receiver argument BOTH_RECEIVERS). In order:
 *  - register 5 written with 0xFF, then 0x10;
 *  - register 0x21C of the 0xCF00F000 block: bits 3 and 4 cleared, bits 0 and 7 set;
 *  - registers 0x124 = 0x7C, 0x121 = 1, 0x120 = 0, one long delay unit, 0x120 = 2, then 0x126..0x129 =
 *    0x40, 9, 0xE4, 0x60;
 *  - audio level 0x8000 (audio_set_hdmi_rx_level);
 *  - bit 4 of 0x2A7 set, 0x2FE = 6, bit 0 and bit 2 of register 8 set and bit 3 cleared, 0x1AF = 9,
 *    0x29F = 2, 0x135 = 6, 0x2D0 = 1;
 *  - register 0x224 of the 0xCF00F000 block = 0x33: both bits of both receivers, the state
 *    hdmi_apply_color_depth sets for 8 bits per colour;
 *  - bit 5 of 0x79 set, bits 0..2 of 0x7A set, the packet-forwarding defaults of receivers 0 and 1
 *    (hdmi_init_packet_switch), 0x41 = 0, and registers 0x340..0x343 reset (hdmi_reset_reg340_block);
 *  - in the records of both receivers the hold flags of the audio, HDR and vendor packet areas are set to 1.
 */
void hdmi_init_receivers(void)
{
    unsigned char i;
    unsigned int j, k;
    unsigned int base = BLOCK_F000;

    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_5, 0xff);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_5, 0x10);

    *(volatile unsigned int *)(base | BLOCK_REG_21C) =
        (*(volatile unsigned int *)(base | BLOCK_REG_21C) & ~0x18) | 0x81;

    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_124, 0x7c);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_121, 1);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_120, 0);
    timer_delay_long_units(1);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_120, 2);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_126, 0x40);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_127, 9);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_128, 0xe4);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_129, 0x60);
    audio_set_hdmi_rx_level(BOTH_RECEIVERS, AUDIO_START_LEVEL);
    hdmi_reg_update_bits(BOTH_RECEIVERS, RX_REG_2A7, 0x10, BITS_SET);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_2FE, 6);
    hdmi_reg_update_bits(BOTH_RECEIVERS, RX_REG_8, 5, BITS_SET);
    hdmi_reg_update_bits(BOTH_RECEIVERS, RX_REG_8, 8, BITS_CLEAR);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_1AF, 9);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_29F, 2);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_135, 6);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_2D0, 1);

    *(volatile unsigned int *)(base | BLOCK_REG_224) = 0x33;

    hdmi_reg_update_bits(BOTH_RECEIVERS, RX_REG_79, 0x20, BITS_SET);
    hdmi_reg_update_bits(BOTH_RECEIVERS, RX_REG_7A, 7, BITS_SET);
    hdmi_init_packet_switch(0);
    hdmi_init_packet_switch(1);
    hdmi_reg_write8(BOTH_RECEIVERS, RX_REG_41, 0);
    hdmi_reset_reg340_block(BOTH_RECEIVERS);

    /* While a hold flag is 1, hdmi_poll_rx_status does not copy that packet area into the record. */
    for (i = 0; i < 2; i++) {
        hdmi_rx_records[i].audio_hold = 1;
        hdmi_rx_records[i].hdr_hold = 1;
        hdmi_rx_records[i].vendor_hold = 1;
    }
}
