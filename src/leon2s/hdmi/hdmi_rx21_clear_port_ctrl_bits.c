/* hdmi_rx21_clear_port_ctrl_bits  (FUN_a009f66c)
 *
 * Clear a fixed set of control bits of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: descriptive - bits 0xB, 0, 1, 8, 9, 0x11, 6 and a top byte; caller hdmi_rx21_restart_port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009f66c, flags -mcpu=v8 -Os -g (section default). sethi / or 0xff builds the mask 0xFFFF00FF.
 */
extern unsigned char ARR_a807db00;
extern int reg_clear_bit(int, void *);
extern int sys_get_chip_revision(void);

#define CHIP_REV_82 0x82                /* the last step below runs on later chip revisions only */

/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    unsigned char pad0[0x0c];
    unsigned int *block3;               /* +0x0C: 0xCE009300 (+0x1000 for receiver 1) */
    unsigned char pad1[0x08];
    unsigned int *block6;               /* +0x18: 0xCE009600 */
    unsigned char pad2[0x1c];
};

/*
 * Clear a fixed set of bits in the registers of HDMI 2.1 receiver `port`:
 *   block 3: word 0x1F bit 0xB; word 0x18 bits 0, 1, 8 and 9; the top byte of word 0x17;
 *   block 6: word 0x24 bit 0x11; word 0x20 bit 6; and, on chip revisions above 0x82, bits 8..15 of word 0x2C.
 * Called by hdmi_rx21_restart_port.
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_clear_port_ctrl_bits(unsigned char port)
{
    struct hdmi_rx21_reg_blocks *blocks;
    unsigned int word;

    blocks = (struct hdmi_rx21_reg_blocks *)((unsigned char *)&ARR_a807db00 + port * 0x34);
    reg_clear_bit(0xb, blocks->block3 + 0x1f);
    reg_clear_bit(0, blocks->block3 + 0x18);
    reg_clear_bit(1, blocks->block3 + 0x18);
    word = blocks->block3[0x17];
    blocks->block3[0x17] = word & 0x00ffffff;
    reg_clear_bit(8, blocks->block3 + 0x18);
    reg_clear_bit(9, blocks->block3 + 0x18);
    reg_clear_bit(0x11, blocks->block6 + 0x24);
    reg_clear_bit(6, blocks->block6 + 0x20);
    if ((unsigned char)sys_get_chip_revision() > CHIP_REV_82) {
        blocks->block6[0x2c] &= 0xffff00ff;
    }
}
