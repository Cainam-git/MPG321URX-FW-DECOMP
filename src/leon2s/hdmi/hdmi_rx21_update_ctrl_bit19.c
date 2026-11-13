/* hdmi_rx21_update_ctrl_bit19  (FUN_a0098048)
 *
 * Set or clear bit 0x19 of block 1 register 0x34 of an HDMI 2.1 receiver from a block 2 status word.
 *   port: HDMI 2.1 receiver 0/1
 * Note: The bit is set when any of bits 8..11 of block 2 word index 0x20 (byte offset 0x80) is set together
 *   with the bit 8 places higher (bits 16..19).
 * Name basis: descriptive - bits 8..11 and 16..19 of block 2 word index 0x20; bit 0x19 of block 1 + 0x34
 *
 * Matching notes
 * --------------
 * FUN_a0098048 (leon2s 0xa0098048-0xa00980a4, 92 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: the register block (record word 2, volatile MMIO) is read twice; the two values are computed into
 * separate locals (one expression folds the 0xf mask into the test); the set and clear calls are tail calls.
 */
#define BLOCK1_REG_34   0x34            /* byte offset of the register in block 1 */
#define BLOCK2_REG_80   0x20            /* word index (byte offset 0x80) of the register in block 2 */

extern void reg_set_bit(unsigned int, int);
extern void reg_clear_bit(unsigned int, int);
extern unsigned char hdmi_rx21_reg_blocks[];    /* table of register block addresses, 0x34 bytes per receiver */

/*
 * Set or clear bit 0x19 of the register at block 1 + 0x34 of an HDMI 2.1 receiver from the register at
 * block 2 + 0x80: set when any of its bits 8..11 is set together with the bit 8 places higher (bits 16..19), clear
 * otherwise.
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_rx21_update_port_mode.
 */
void hdmi_rx21_update_ctrl_bit19(unsigned char port)
{
    unsigned int *blocks = (unsigned int *)(hdmi_rx21_reg_blocks + port * 0x34);
    volatile unsigned int *block2 = (volatile unsigned int *)blocks[2];

    unsigned int low_bits = block2[BLOCK2_REG_80] >> 8;
    unsigned int high_bits = (block2[BLOCK2_REG_80] >> 16) & 0xf;

    if (low_bits & high_bits)
        reg_set_bit(0x19, blocks[1] + BLOCK1_REG_34);
    else
        reg_clear_bit(0x19, blocks[1] + BLOCK1_REG_34);
}
