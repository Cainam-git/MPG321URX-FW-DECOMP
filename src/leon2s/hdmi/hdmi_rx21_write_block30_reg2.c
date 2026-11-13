/* hdmi_rx21_write_block30_reg2  (FUN_a00a2f70)
 *
 * Write a 6-bit value and an enable bit to register 2 of block 0x30 of a receiver.
 *   receiver
 *   value: 6-bit value
 *   enable
 * Name basis: descriptive - caller hdmi_rx21_init_port with 0x12, 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2f70 @ 0xa00a2f70, flags -mcpu=v8 -Os -g.
 * Source form: the row is indexed by the u8 receiver each time; the two bit routines are tail calls. The base
 * is hdmi_rx21_reg_blocks (not the mid-row address 0xa807db30).
 */
/* One row of hdmi_rx21_reg_blocks (0x34 bytes per HDMI 2.1 receiver): word 0 points to register block 0 of the
   receiver (0xCE009000, +0x1000 for receiver 1), word 1 to block 1, and so on up to block 12 at +0x30. */
struct hdmi_rx21_reg_blocks { unsigned char pad[0x30]; unsigned int *block12; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern void reg_set_bit(unsigned int, unsigned int *);
extern void reg_clear_bit(unsigned int, unsigned int *);

/* Word 2 of register block 12 of the HDMI 2.1 receiver. With enable set, its low 6 bits are replaced by value
   and bit 7 is set; with enable clear, bit 7 is cleared and the value is not used. Called by
   hdmi_rx21_init_port with value 0x12 and enable 1. */
void hdmi_rx21_write_block30_reg2(unsigned char receiver, unsigned char value, unsigned char enable)
{
    if (enable != 0) {
        ARR_a807db00[receiver].block12[2] = (ARR_a807db00[receiver].block12[2] & ~0x3f) | value;
        reg_set_bit(7, ARR_a807db00[receiver].block12 + 2);
    } else {
        reg_clear_bit(7, ARR_a807db00[receiver].block12 + 2);
    }
}
