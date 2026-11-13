/* hdmi_rx21_update_packet_forward_bit  (FUN_a00a93e4)
 *
 * Set or clear bit 23 of packet word 0xE8 of an HDMI 2.1 receiver by output use.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: descriptive - cleared when an HDMI output takes input 0x51 with hdmi_tx_get_ctrl_bit30 == 0;
 *   caller hdmi_rx21_modedet_watch_stable
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a93e4, flags -mcpu=v8 -Os -g.
 * Source form: a switch on port with the whole test written out in each case (constant record index); the
 * register block is reached through a non-volatile unsigned int pointer.
 */
struct hdmi_rx21_reg_blocks { unsigned char pad[0x30]; unsigned int *block12; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_tx_get_source_code(unsigned int);
extern unsigned char hdmi_tx_get_ctrl_bit30(unsigned int);

#define INPUT_CODE_HDMI21_0 0x51        /* input code of HDMI 2.1 receiver 0 */
#define PACKET_WORD_E8 (0xe8 / 4)       /* word 0xE8 of register block 12 (packet selection 1) */
#define FORWARD_BIT 0x800000            /* bit 23 */

/*
 * Set or clear bit 23 of word 0xE8 of register block 12 of an HDMI 2.1 receiver. The bit is cleared when
 * HDMI TX output 0 or output 1 takes input code 0x51 (HDMI 2.1 receiver 0) and has bit 30 of word 0 of its
 * TX channel record clear; otherwise it is set. The test does not depend on `port`, only the receiver written.
 * Called by hdmi_rx21_modedet_watch_stable.
 *   port: HDMI 2.1 receiver (0 or 1; any other value does nothing)
 */
void hdmi_rx21_update_packet_forward_bit(unsigned char port)
{
    switch (port) {
    case 0:
        if ((hdmi_tx_get_source_code(0) == INPUT_CODE_HDMI21_0 && hdmi_tx_get_ctrl_bit30(0) == 0) || (hdmi_tx_get_source_code(1) == INPUT_CODE_HDMI21_0 && hdmi_tx_get_ctrl_bit30(1) == 0))
            ARR_a807db00[0].block12[PACKET_WORD_E8] &= ~FORWARD_BIT;
        else
            ARR_a807db00[0].block12[PACKET_WORD_E8] |= FORWARD_BIT;
        break;
    case 1:
        if ((hdmi_tx_get_source_code(0) == INPUT_CODE_HDMI21_0 && hdmi_tx_get_ctrl_bit30(0) == 0) || (hdmi_tx_get_source_code(1) == INPUT_CODE_HDMI21_0 && hdmi_tx_get_ctrl_bit30(1) == 0))
            ARR_a807db00[1].block12[PACKET_WORD_E8] &= ~FORWARD_BIT;
        else
            ARR_a807db00[1].block12[PACKET_WORD_E8] |= FORWARD_BIT;
        break;
    }
}
