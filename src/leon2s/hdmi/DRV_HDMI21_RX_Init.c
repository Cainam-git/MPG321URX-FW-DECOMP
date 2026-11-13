/* DRV_HDMI21_RX_Init  (DRV_HDMI21_RX_Init)
 *
 * Initialise the HDMI 2.1 receiver driver and enable both ports once.
 * Name basis: proven - original name printed ('[INIT]: DRV_HDMI21_RX_Init %d'); caller input_init_receivers
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_RX_Init @ 0xa00a1cdc, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the print string is a symbol; `i = 0` is at the declaration and
 * the middle loop has its own counter j; the register-block word is read again for each of the three
 * calls in the last loop.
 */
#define HDMI_MSG_INIT_INFO 1         /* debug message bit: '[INIT]' lines (dbg_hdmi_message_flags) */

/* Row of hdmi_rx21_reg_blocks: the register block bases of one HDMI 2.1 receiver (0x34 bytes). */
struct rx21_reg_blocks {
    unsigned int block0_to_5[6];
    unsigned int *block6;
    unsigned char bytes_0x1c_to_0x33[0x34 - 0x1c];
};
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned char hdmi_rx21_init_done_flag;
extern unsigned int dbg_hdmi_message_flags;
extern void DRV_HDMI_IF_Init(void);
extern void DRV_HDMI_IF_Disconnect(unsigned char);
extern void hdmi_rx21_set_connected(unsigned char);
extern void hdmi_rx21_set_port_enable(unsigned char, unsigned char);
extern void reg_set_bit(unsigned int, int);
extern void hdmi_phy_update_reg(unsigned char, unsigned int, unsigned int, unsigned int);
extern unsigned int hdmi_is_second_port(unsigned char);
extern int dbg_printf(const char *, ...);

/* Initialises the HDMI 2.1 receivers; does its work only the first time it is called (the flag
 * hdmi_rx21_init_done_flag is set at the end). In order: DRV_HDMI_IF_Init; for both receivers
 * DRV_HDMI_IF_Disconnect and hdmi_rx21_set_connected; hdmi_rx21_set_port_enable(receiver, 1) for both;
 * then for each receiver one PHY register update (register 0x2e70, value 0xf00) and three bit sets (bits
 * 11, 9 and 10) in register 0x08 of register block 6. Called from input_init_receivers. */
void DRV_HDMI21_RX_Init(void)
{
    unsigned char i = 0;
    unsigned char j;

    if (hdmi_rx21_init_done_flag == 0) {
        if (dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO)
            dbg_printf("[INIT]: DRV_HDMI21_RX_Init %d\r\n", 999);
        DRV_HDMI_IF_Init();
        for (; i < 2; i++) {
            DRV_HDMI_IF_Disconnect(i);
            hdmi_rx21_set_connected(i);
        }
        for (j = 0; j < 2; j++)
            hdmi_rx21_set_port_enable(j, 1);
        for (i = 0; i < 2; i++) {
            hdmi_phy_update_reg(hdmi_is_second_port(i), 0x2e70, 0xffffffff, 0xf00);
            reg_set_bit(0xb, (int)hdmi_rx21_reg_blocks[i].block6 + 8);
            reg_set_bit(9, (int)hdmi_rx21_reg_blocks[i].block6 + 8);
            reg_set_bit(10, (int)hdmi_rx21_reg_blocks[i].block6 + 8);
        }
        hdmi_rx21_init_done_flag = 1;
    }
}
