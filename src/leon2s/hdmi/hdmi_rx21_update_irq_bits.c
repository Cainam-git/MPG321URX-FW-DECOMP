/* hdmi_rx21_update_irq_bits  (FUN_a009740c)
 *
 * Set or clear bit 0x10 of block 1 register 0x34 of an HDMI 2.1 receiver from its status bits.
 *   port: HDMI 2.1 receiver 0/1
 * Note: When it clears bit 0x10 it also clears bit 0x15 of block 0 + 0xEC if bit 0x14 there is set; bit 0x15
 *   is never set here.
 * Name basis: descriptive - bit tests on block 3 words +0x60 / +0x74; bit 0x10 of block 1 + 0x34, bit 0x15 of
 *   block 0 + 0xEC; caller hdmi_rx21_modedet_check_pll
 *
 * Matching notes
 * --------------
 * FUN_a009740c (leon2s 0xa009740c-0xa00974ec, 224 bytes), flags -mcpu=v8 -Os -g.
 * reg_test_bit(bit, address) tests a bit; reg_set_bit and reg_clear_bit are the two update calls. All final calls
 * are tail calls.
 * Source form: two separate ifs with their own reg_set_bit call (GCC merges the call tails); every access names
 * hdmi_rx21_reg_blocks[receiver] directly.
 */
/* One entry of the table at 0xA807DB00 (0x34 bytes per receiver): the addresses of the register blocks. */
struct hdmi_rx21_reg_blocks { unsigned int block0; unsigned int block1; unsigned int block2; unsigned int block3; unsigned char pad[0x34 - 0x10]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned int reg_test_bit(unsigned int, unsigned int);
extern void reg_set_bit(unsigned int, unsigned int);
extern void reg_clear_bit(unsigned int, unsigned int);

/*
 * Set or clear bit 0x10 of the register at block 1 + 0x34 of an HDMI 2.1 receiver from two registers of block 3:
 *   - set when bit 8 of block 3 + 0x60 and bit 0x11 of block 3 + 0x74 are both set, or when bit 0x11 of
 *     block 3 + 0x74 is clear and its bit 0x10 is set;
 *   - otherwise cleared, and in that case bit 0x15 of block 0 + 0xEC is cleared as well when its bit 0x14 is set.
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_rx21_modedet_check_pll (mode-detect state 4) when the PLL check passes.
 */
void hdmi_rx21_update_irq_bits(unsigned int port)
{
    unsigned char receiver = port;

    if (reg_test_bit(8, ARR_a807db00[receiver].block3 + 0x60) && reg_test_bit(0x11, ARR_a807db00[receiver].block3 + 0x74)) {
        reg_set_bit(0x10, ARR_a807db00[receiver].block1 + 0x34);
        return;
    }
    if (!reg_test_bit(0x11, ARR_a807db00[receiver].block3 + 0x74) && reg_test_bit(0x10, ARR_a807db00[receiver].block3 + 0x74)) {
        reg_set_bit(0x10, ARR_a807db00[receiver].block1 + 0x34);
        return;
    }
    reg_clear_bit(0x10, ARR_a807db00[receiver].block1 + 0x34);
    if (reg_test_bit(0x14, ARR_a807db00[receiver].block0 + 0xec))
        reg_clear_bit(0x15, ARR_a807db00[receiver].block0 + 0xec);
}
