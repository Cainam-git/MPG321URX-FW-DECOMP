/* hdmi_rx21_clear_mask_bits  (FUN_a00a2564)
 *
 * Clear the control bits selected by a mask on both HDMI 2.1 receivers (newer chips).
 *   mask
 * Name basis: descriptive - mailbox command 0x16; counterpart of hdmi_rx21_set_mask_bits
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2564, flags -mcpu=v8 -Os -g (section default).
 */
#define CHIP_REV_82 0x82                /* the bits are cleared on later chip revisions only */

/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    unsigned char pad[0x24];
    unsigned char *block9;              /* +0x24: register block 9 of the receiver */
    unsigned char rest[0xc];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char sys_get_chip_revision(void);
extern void reg_clear_bit(int, unsigned char *);

/*
 * On chip revisions above 0x82 only: for each set bit of `mask` clear one bit of the word array at byte offset
 * 0xC0 of register block 9, in receiver 0 and then receiver 1 (mask bit 0 -> bit 0xC, 1 -> 0xD, 2 -> 0xE,
 * 3 -> 0xF, 4 -> 0xB). Bits 8 and 9 are not touched. Counterpart of hdmi_rx21_set_mask_bits. Called by
 * ipc_dispatch_command (mailbox command 0x16).
 *   mask  bits 0..4 select the bits to clear
 */
void hdmi_rx21_clear_mask_bits(unsigned char mask)
{
    if (sys_get_chip_revision() > CHIP_REV_82) {
        if (mask & 1) {
            reg_clear_bit(0xc, ARR_a807db00[0].block9 + 0xc0);
            reg_clear_bit(0xc, ARR_a807db00[1].block9 + 0xc0);
        }
        if (mask & 2) {
            reg_clear_bit(0xd, ARR_a807db00[0].block9 + 0xc0);
            reg_clear_bit(0xd, ARR_a807db00[1].block9 + 0xc0);
        }
        if (mask & 4) {
            reg_clear_bit(0xe, ARR_a807db00[0].block9 + 0xc0);
            reg_clear_bit(0xe, ARR_a807db00[1].block9 + 0xc0);
        }
        if (mask & 8) {
            reg_clear_bit(0xf, ARR_a807db00[0].block9 + 0xc0);
            reg_clear_bit(0xf, ARR_a807db00[1].block9 + 0xc0);
        }
        if (mask & 0x10) {
            reg_clear_bit(0xb, ARR_a807db00[0].block9 + 0xc0);
            reg_clear_bit(0xb, ARR_a807db00[1].block9 + 0xc0);
        }
    }
}
