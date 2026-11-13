/* hdmi_rx21_status04_bit17  (FUN_a00a28a4)
 *
 * Return bit 17 of status register 4 of an HDMI 2.1 receiver.
 *   p1: receiver
 * Returns: bit value
 * Name basis: descriptive - mailbox command 0x83 (status bit of HDMI port 2/3)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a28a4 @ 0xa00a28a4, flags -mcpu=v8 -Os -g.
 * The second parameter is declared and unused; the result is the flag (value != 0) as 0 or 1.
 */
/* One row of hdmi_rx21_reg_blocks (0x34 bytes per HDMI 2.1 receiver): pointers to the receiver's register blocks.
   Word 0 is block 0 (0xCE009000 for receiver 0, +0x1000 for receiver 1). */
struct hdmi_rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned char rest[0x30];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned int reg_test_bit(unsigned int bit, volatile unsigned int *word);

/* Bit 17 of the word at offset 4 of register block 0 of the receiver (0 or 1). Returns 1 when it is set, else 0. */
unsigned int hdmi_rx21_status04_bit17(unsigned int receiver, unsigned int unused)
{
    unsigned int bit_set;

    bit_set = reg_test_bit(17, ARR_a807db00[receiver & 0xff].block0 + 1);
    return (unsigned int)(bit_set != 0);
}
