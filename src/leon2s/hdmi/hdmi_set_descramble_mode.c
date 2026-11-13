/* hdmi_set_descramble_mode  (FUN_a007ec30)
 *
 * Set or clear the two bits that hdmi_get_scramble_lock and hdmi_get_scramble_status read.
 *   phy
 *   lock_value: descramble on
 *   status_value: ratio on
 * Note: First value: bit 0 of register 0x2F6 (HDMI 2.1: bit 16 of block-3 word +0x74); second value: bit 2
 *   (bit 18). A value of 1 sets, anything else clears.
 * Name basis: derived - bits 0x10 / 0x12 (HDMI 2.1 register block) or bits 0 / 2 of receiver register 0x2F6;
 *   caller prints 'HDMI_SET_DESCRAMBLE_MODE = 0x05 / 0x00'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007ec30 @ 0xa007ec30-0xa007ed0c, flags -mcpu=v8 -Os -g.
 * Source form: lock_value and status_value are unsigned int parameters converted to unsigned char locals inside the
 * first arm; the conversion is shared with the byte argument of the other arm (the firmware masks each once, after
 * the hdmi_is_hdmi21_phy call).
 */
/* One row of hdmi_rx21_reg_blocks: the register block addresses of an HDMI 2.1 receiver (0x34 bytes, 13 words). */
struct hdmi_rx21_reg_blocks { unsigned char pad[0xc]; unsigned int block3; unsigned char pad2[0x34 - 0x10]; };

extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern void hdmi_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void reg_set_bit(unsigned int, int);
extern void reg_clear_bit(unsigned int, int);

/*
 * Write two bits of a PHY's receiver: each is set when its value is 1 and cleared otherwise.
 *   - lock_value goes to the bit that hdmi_get_scramble_lock reads (bit 16 of the word at offset 0x74 of register
 *     block 3 on an HDMI 2.1 PHY, bit 0 of register 0x2F6 on an HDMI 2.0 PHY);
 *   - status_value goes to the bit that hdmi_get_scramble_status reads (bit 18 of that word, bit 2 of register
 *     0x2F6).
 * Block 3 is taken from row 0 of hdmi_rx21_reg_blocks for PHY 2 and row 1 for PHY 3.
 * Called by DRV_HDMI_EQScan_FSM_PHY_Init.
 */
void hdmi_set_descramble_mode(unsigned char phy, unsigned int lock_value, unsigned int status_value)
{
    unsigned char row;

    if (hdmi_is_hdmi21_phy(phy)) {
        unsigned char lock = lock_value;
        unsigned char status = status_value;
        row = phy != 2;
        if (lock == 1)
            reg_set_bit(0x10, ARR_a807db00[row].block3 + 0x74);
        else
            reg_clear_bit(0x10, ARR_a807db00[row].block3 + 0x74);
        if (status == 1)
            reg_set_bit(0x12, ARR_a807db00[row].block3 + 0x74);
        else
            reg_clear_bit(0x12, ARR_a807db00[row].block3 + 0x74);
    } else {
        hdmi_reg_update_bits(phy, 0x2f6, 1, lock_value);
        hdmi_reg_update_bits(phy, 0x2f6, 4, status_value);
    }
}
