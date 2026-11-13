/* hdmi_rx21_init_port  (INIT_handler)
 *
 * Set the start-up registers and records of one HDMI 2.1 receiver port.
 *   receiver: HDMI 2.1 receiver 0/1
 * Note: Label INIT_handler is not printed by the firmware.
 * Name basis: derived - prints '[INIT]: Port%c , 5V Ident = %d'; calls DRV_HDMI21_LTS_STS_InitialSettings;
 *   caller _hdmi21_Initialize
 *
 * Matching notes
 * --------------
 * INIT_handler (leon2s 0xa00a17c4-0xa00a1a80, 700 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the debug word is read into a local before the record byte stores, and the record stores are written in
 *    the order shown;
 *  - block 0 is reached through a local pointer for the words 0x30 / 0x31 / 0x21 only; every other access,
 *    the block 8 and block 2 fields included, goes through the table entry each time;
 *  - one unsigned char pointer serves both records.
 */

#define HDMI_MSG_INIT_INFO      0x01    /* dbg_hdmi_message_flags bit 0: '[INIT]' lines */

/* The HDMI 2.1 receivers use PHYs 2 and 3 (hdmi_rx21_get_phy_index). */
#define PHY_RX21_0              2
#define PHY_RX21_1              3
#define PHY_REG_2E60            0x2e60
#define BIT_SET                 1

/* Register block addresses of an HDMI 2.1 receiver (13 words, hdmi_rx21_reg_blocks): block k at
   0xCE009000 + k * 0x100, plus 0x1000 for receiver 1. Blocks 0..3, 6 and 8 are used here. */
struct hdmi_rx21_reg_blocks {
    volatile unsigned int *block0;
    volatile unsigned int *block1;
    volatile unsigned int *block2;
    volatile unsigned int *block3;
    volatile unsigned int *block4;
    volatile unsigned int *block5;
    volatile unsigned int *block6;
    volatile unsigned int *block7;
    volatile unsigned int *block8;
    unsigned char blocks_9_to_12[0x34 - 0x24];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];

/* Bytes of the receiver record (400 bytes, hdmi_rx21_input_records) written here. */
#define RX21_RECORD_SIZE        0x190
#define RX21_CONNECTED_COPY     2       /* hdmi_rx21_update_connect_state copies the connected flag (+3) here */
#define RX21_BYTE_0xBA          0xba
#define RX21_AUDIO_STREAM_HOLD  0x183   /* last status byte of the audio stream block: 0 lets
                                           DRV_HDMI_ModeDetect_FSM_Complete read the packet */
extern unsigned char hdmi_rx21_input_records[];

/* Fields of the link training record (struct hdmi_rx21_lts_record, 0xB0 bytes, hdmi_rx21_lts_records). */
#define LTS_RECORD_SIZE         0xb0
#define LTS_LAST_STATE          0x30    /* u32: rx-detect state seen at the last pass */
#define LTS_BYTE_0x3A           0x3a
#define LTS_BYTE_0x3B           0x3b
#define LTS_BYTE_0x3C           0x3c
extern unsigned char hdmi_rx21_lts_records[];

extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern void reg_clear_bit(unsigned int, volatile unsigned int *);
extern void hdmi_phy_write_bit(int mode, unsigned int bit, unsigned char phy, unsigned short reg);
extern void hdmi_rx21_write_block30_reg2(unsigned char, unsigned char, unsigned char);
extern void hdmi_rx21_init_packet_switch(unsigned char);
extern void DRV_HDMI21_LTS_STS_InitialSettings(unsigned char);

/*
 * Start-up settings of HDMI 2.1 receiver `receiver` (0 or 1; any other value returns at once). Called once
 * per receiver by _hdmi21_Initialize. Register words are named by block and byte offset; what the single
 * bits do is not shown by the code.
 *
 * In order:
 *   1. block 1 +0x3C: set bits 21..23.
 *   2. Receiver record: connected copy (+2) = 0, byte +0xBA = 1, audio stream hold (+0x183) = 1. With
 *      HDMI_MSG_INIT_INFO the '5V Ident' line is printed (always with 1).
 *   3. block 0 +0xC0: top byte 0x50; +0xC4: bytes 0 and 2 = 0, byte 1 = 1. (DRV_HDMI_Config_BCH writes the
 *      same top byte of +0xC0 and low byte of +0xC4 when it does not enable BCH.)
 *      block 0 +0x84: set bit 20; +0xD4: clear bit 20 + receiver.
 *   4. block 1 +0x24: set bits 27..31; +0x28: set bits 13, 8, 9, 10, clear bit 11; +0x34: byte 1 = 6.
 *      block 0 +0x40: clear bit 15.
 *   5. Link training record: byte +0x3A = 1, last_state = 0, bytes +0x3B / +0x3C = 0; then
 *      DRV_HDMI21_LTS_STS_InitialSettings.
 *   6. block 6 +0x90: clear bit 17; block 6 +0x08: set bit 8; PHY register 0x2E60 of the receiver's PHY:
 *      set bit 30; block 3 +0x7C: set bit 12; block 0 +0x04: set bit 21.
 *   7. block 8 +0x80: bits 8..31 = 0x40000 (top byte 4), then bits 0..2 set.
 *   8. hdmi_rx21_write_block30_reg2(receiver, 0x12, 1), hdmi_rx21_init_packet_switch(receiver), and
 *      block 2 +0x9C: top byte 2.
 */
void hdmi_rx21_init_port(unsigned int receiver)
{
    unsigned char port;
    unsigned char phy;
    unsigned char *record;
    unsigned int message_flags;
    volatile unsigned int *block0;

    port = receiver;
    if (port == 0)
        phy = PHY_RX21_0;
    else if (port == 1)
        phy = PHY_RX21_1;
    else
        return;
    reg_set_bit(0x17, ARR_a807db00[port].block1 + 15);
    reg_set_bit(0x16, ARR_a807db00[port].block1 + 15);
    reg_set_bit(0x15, ARR_a807db00[port].block1 + 15);
    message_flags = dbg_hdmi_message_flags;
    record = hdmi_rx21_input_records + port * RX21_RECORD_SIZE;
    record[RX21_CONNECTED_COPY] = 0;
    record[RX21_BYTE_0xBA] = 1;
    record[RX21_AUDIO_STREAM_HOLD] = 1;
    if (message_flags & HDMI_MSG_INIT_INFO)
        dbg_printf("[INIT]: Port%c , 5V Ident = %d ##\n", (char)(receiver + 0x41), 1);
    block0 = ARR_a807db00[port].block0;
    block0[0x30] = (block0[0x30] & 0xffffff) | 0x50000000;
    block0[0x31] = block0[0x31] & 0xffffff00;
    block0[0x31] = (block0[0x31] & 0xffff00ff) | 0x100;
    block0[0x31] = block0[0x31] & 0xff00ffff;
    reg_set_bit(0x14, block0 + 0x21);
    reg_clear_bit(port + 0x14, ARR_a807db00[port].block0 + 0x35);
    reg_set_bit(0x1b, ARR_a807db00[port].block1 + 9);
    reg_set_bit(0x1c, ARR_a807db00[port].block1 + 9);
    reg_set_bit(0x1d, ARR_a807db00[port].block1 + 9);
    reg_set_bit(0x1e, ARR_a807db00[port].block1 + 9);
    reg_set_bit(0x1f, ARR_a807db00[port].block1 + 9);
    reg_set_bit(0xd, ARR_a807db00[port].block1 + 10);
    reg_set_bit(8, ARR_a807db00[port].block1 + 10);
    reg_set_bit(9, ARR_a807db00[port].block1 + 10);
    reg_set_bit(10, ARR_a807db00[port].block1 + 10);
    reg_clear_bit(0xb, ARR_a807db00[port].block1 + 10);
    ARR_a807db00[port].block1[0xd] = (ARR_a807db00[port].block1[0xd] & 0xffff00ff) | 0x600;
    reg_clear_bit(0xf, ARR_a807db00[port].block0 + 0x10);
    record = hdmi_rx21_lts_records + port * LTS_RECORD_SIZE;
    record[LTS_BYTE_0x3A] = 1;
    *(unsigned int *)(record + LTS_LAST_STATE) = 0;
    record[LTS_BYTE_0x3B] = 0;
    record[LTS_BYTE_0x3C] = 0;
    DRV_HDMI21_LTS_STS_InitialSettings(port);
    reg_clear_bit(0x11, ARR_a807db00[port].block6 + 0x24);
    reg_set_bit(8, ARR_a807db00[port].block6 + 2);
    hdmi_phy_write_bit(BIT_SET, 0x1e, phy, PHY_REG_2E60);
    reg_set_bit(0xc, ARR_a807db00[port].block3 + 0x1f);
    reg_set_bit(0x15, ARR_a807db00[port].block0 + 1);
    ARR_a807db00[port].block8[0x20] = (ARR_a807db00[port].block8[0x20] & 0xff) | 0x4000000;
    ARR_a807db00[port].block8[0x20] = ARR_a807db00[port].block8[0x20] | 7;
    hdmi_rx21_write_block30_reg2(port, 0x12, 1);
    hdmi_rx21_init_packet_switch(port);
    ARR_a807db00[port].block2[0x27] = (ARR_a807db00[port].block2[0x27] & 0xffffff) | 0x2000000;
}
