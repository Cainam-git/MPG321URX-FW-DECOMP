/* hdcp_rx_hdmi_recheck_ports  (FUN_a00c1ac0)
 *
 * Move the HDMI 2.0 and 2.1 inputs in state 5 or 6 on to state 7 once their event bit is set.
 * Name basis: descriptive - bit 5 of register 0x318 (HDMI 2.0 inputs) and bit 6 of register 0xA8 (HDMI 2.1
 *   inputs)
 *
 * Matching notes
 * --------------
 * FUN_a00c1ac0 (leon2s 0xa00c1ac0-0xa00c1c18, 344 bytes), flags -mcpu=v8 -Os -g.
 * Source form: a record pointer local per iteration.
 */
/* The 16-byte hdcp_rx_record entries: only the state byte at +0xD is used here. */
struct hdcp_rx_record {
    unsigned char pad[0xd];
    unsigned char state;
    unsigned char rest[2];
};
extern struct hdcp_rx_record hdcp_rx_record_hdmi20[];
extern struct hdcp_rx_record hdcp_rx_record_hdmi21[];
extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);
extern void hdmi_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdmi_reg_update_bits(unsigned char, unsigned short, unsigned int, unsigned char);
extern unsigned int hdmi_rx21_reg_read8(unsigned char, unsigned short);
extern void hdmi_rx21_reg_write8(unsigned char, unsigned short, unsigned char);

#define HDCP_RX_STATE_5 5                       /* states 5 and 6 are checked; the record then goes to state 7 */
#define HDCP_RX_STATE_7 7

/*
 * For each of the two HDMI 2.0 inputs and each of the two HDMI 2.1 inputs whose record is in state 5 or 6:
 *   HDMI 2.0: when bit 5 of register 0x318 is set, write 0x60 to it, set bit 4 of register 0x308 and move the
 *             record to state 7;
 *   HDMI 2.1: when bit 6 of register 0xA8 is set, write 0x60 to it, write the index registers (select 9, index 0, value 0x10,
 *             then 0x20 to register 0xA4) and move the record to state 7.
 *
 * Installed as a tick hook by InitHDCP.
 */
void hdcp_rx_hdmi_recheck_ports(void)
{
    unsigned char i;
    struct hdcp_rx_record *record;

    for (i = 0; i < 2; i++) {
        record = &hdcp_rx_record_hdmi20[i];
        if ((unsigned char)(record->state - HDCP_RX_STATE_5) <= 1 && (hdmi_reg_read8(i, 0x318) & 0x20)) {
            hdmi_reg_write8(i, 0x318, 0x60);
            hdmi_reg_update_bits(i, 0x308, 0x10, 1);
            record->state = HDCP_RX_STATE_7;
        }
    }
    for (i = 0; i < 2; i++) {
        record = &hdcp_rx_record_hdmi21[i];
        if ((unsigned char)(record->state - HDCP_RX_STATE_5) <= 1 && (hdmi_rx21_reg_read8(i, 0xa8) & 0x40)) {
            hdmi_rx21_reg_write8(i, 0xa8, 0x60);
            hdmi_rx21_reg_write8(i, 0xa6, 9);
            hdmi_rx21_reg_write8(i, 0xa4, 0);
            hdmi_rx21_reg_write8(i, 0xa5, 0);
            hdmi_rx21_reg_write8(i, 0xa7, 0x10);
            hdmi_rx21_reg_write8(i, 0xa4, 0x20);
            record->state = HDCP_RX_STATE_7;
        }
    }
}
