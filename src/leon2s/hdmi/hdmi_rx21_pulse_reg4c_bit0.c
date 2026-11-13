/* hdmi_rx21_pulse_reg4c_bit0  (FUN_a009fe60)
 *
 * Set and then clear bit 0 of register 0x4C of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: descriptive - caller hdmi_rx21_modedet_wait_eq_done at the end of EQ
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009fe60, flags -mcpu=v8 -Os -g (section default).
 * Source form: the base is hdmi_rx21_reg_blocks as a struct array (the firmware adds, then loads from record + 0x14);
 * volatile, because the firmware reads and writes the register twice.
 */
/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    unsigned char pad0[0x14];
    volatile unsigned char *block5;     /* +0x14: register block 5 of the receiver */
    unsigned char pad18[0x34 - 0x18];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];

/*
 * Set bit 0 of the word at byte offset 0x4C of register block 5 of receiver `port` and clear it again.
 * Called by hdmi_rx21_modedet_wait_eq_done when the EQ is finished.
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_pulse_reg4c_bit0(unsigned char port)
{
    volatile unsigned char *block5 = ARR_a807db00[port].block5;

    *(volatile unsigned int *)(block5 + 0x4c) |= 1;
    *(volatile unsigned int *)(block5 + 0x4c) &= ~1u;
}
