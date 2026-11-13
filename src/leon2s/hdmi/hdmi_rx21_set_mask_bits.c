/* hdmi_rx21_set_mask_bits  (FUN_a00a2418)
 *
 * Set the control bits selected by a mask on an HDMI 2.1 receiver (newer chips).
 *   port: receiver
 *   mask
 * Name basis: descriptive - mailbox command 0x16; mask bits 0..4 -> bits 0xC..0xF, 0xB of word 0x30, plus 8
 *   and 9
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2418, flags -mcpu=v8 -Os -g (section default). The port is a raw parameter truncated at each use
 * (the firmware repeats the and 0xff). Counterpart of hdmi_rx21_clear_mask_bits.
 */
#define CHIP_REV_82 0x82                /* the bits are set on later chip revisions only */

/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    unsigned char pad[0x24];
    unsigned char *block9;              /* +0x24: register block 9 of the receiver */
    unsigned char rest[0xc];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char sys_get_chip_revision(void);
extern void reg_set_bit(int, unsigned char *);

/*
 * On chip revisions above 0x82 only: for each set bit of `mask` set one bit of the word array at byte offset
 * 0xC0 of register block 9 of receiver `port` (mask bit 0 -> bit 0xC, 1 -> 0xD, 2 -> 0xE, 3 -> 0xF,
 * 4 -> 0xB); then always set bits 8 and 9. Called by ipc_dispatch_command (mailbox command 0x16).
 *   port  HDMI 2.1 receiver 0/1
 *   mask  bits 0..4 select the bits to set
 */
void hdmi_rx21_set_mask_bits(unsigned int port, unsigned char mask)
{
    if (sys_get_chip_revision() > CHIP_REV_82) {
        if (mask & 1)
            reg_set_bit(0xc, ARR_a807db00[port & 0xff].block9 + 0xc0);
        if (mask & 2)
            reg_set_bit(0xd, ARR_a807db00[port & 0xff].block9 + 0xc0);
        if (mask & 4)
            reg_set_bit(0xe, ARR_a807db00[port & 0xff].block9 + 0xc0);
        if (mask & 8)
            reg_set_bit(0xf, ARR_a807db00[port & 0xff].block9 + 0xc0);
        if (mask & 0x10)
            reg_set_bit(0xb, ARR_a807db00[port & 0xff].block9 + 0xc0);
        reg_set_bit(8, ARR_a807db00[port & 0xff].block9 + 0xc0);
        reg_set_bit(9, ARR_a807db00[port & 0xff].block9 + 0xc0);
    }
}
