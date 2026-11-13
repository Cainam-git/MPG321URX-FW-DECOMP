/* hdmi_rx21_set_event_reg78_bit9  (FUN_a00a0514)
 *
 * Set bit 9 of event register 0x78 of both HDMI 2.1 receivers.
 * Name basis: descriptive - caller _hdmi_Init_Interrupt
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a0514, flags -mcpu=v8 -Os -g (section default).
 */
extern unsigned char hdmi_rx21_reg_blocks;
extern void reg_set_bit(unsigned int bit, int word_address);

/*
 * Set bit 9 of the event word at byte offset 0x78 of register block 0 of both HDMI 2.1 receivers. Called by
 * _hdmi_Init_Interrupt.
 */
void hdmi_rx21_set_event_reg78_bit9(void)
{
    unsigned char port;

    port = 0;
    do {
        reg_set_bit(9, *(int *)(&hdmi_rx21_reg_blocks + (port & 0xff) * 0x34) + 0x78);
        port++;
    } while ((port & 0xff) <= 1);
}
