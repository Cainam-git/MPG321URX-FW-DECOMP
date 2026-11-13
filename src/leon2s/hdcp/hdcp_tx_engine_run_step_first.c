/* hdcp_tx_engine_run_step_first  (FUN_a00c9b58)
 *
 * Write zero words to bank 6 of the engine, then run the register sequence that starts a step.
 * Name basis: descriptive - values (4, 7), (0, 1), (6, 1) and following
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c9b58 @ 0xa00c9b58, flags -mcpu=v8 -Os -g.
 * Source form: the Ghidra routine names of the register helpers and their prototypes are kept.
 */
extern void hdcp_tx_engine_write_block(unsigned int, void *, unsigned char, unsigned char, unsigned short); /* 0xa00c99a4 */
extern void hdcp_tx_engine_reg_write8(unsigned int, int, int); /* hdcp_tx_engine_reg_write8 */
extern void hdcp_tx_engine_reg_update_bits(unsigned int, int, int, int); /* hdcp_tx_engine_reg_update_bits */
extern int hdcp_tx_engine_reg_read8(unsigned int, int); /* hdcp_tx_engine_reg_read8 */

/*
 * Run the register sequence that starts a step of copy-protection engine unit `port`. `size` is 0x400 (callers
 * in hdcp_tx_hdmi_state_compare_results and hdcp_tx_dp_state_compare_results) or 0xC00 (hdcp_tx_engine_load_table); with 0x400 register 8 gets
 * 0x42 and bit 6 of register 0x0F is cleared, with any other value register 8 gets 0xC2 and that bit is set.
 *
 * Steps: hdcp_tx_engine_write_block(port, 0, 6, 4, size); registers 4 = 7, 0 = 1, 6 = 1, 7 = 0, 0 = 0,
 * 1 = 0xFD, 9 = 0; register 8 and bit 6 of register 0x0F as above; register 3 = 9; wait until bit 5 of register
 * 2 is set; register 3 = 0, register 8 = 0x40; bit 6 of register 0x0F cleared.
 */
void hdcp_tx_engine_run_step_first(unsigned char port, unsigned short size)
{
    int status;

    hdcp_tx_engine_write_block(port, 0, 6, 4, size);

    hdcp_tx_engine_reg_write8(port, 4, 7);
    hdcp_tx_engine_reg_write8(port, 0, 1);
    hdcp_tx_engine_reg_write8(port, 6, 1);
    hdcp_tx_engine_reg_write8(port, 7, 0);
    hdcp_tx_engine_reg_write8(port, 0, 0);
    hdcp_tx_engine_reg_write8(port, 1, 0xfd);
    hdcp_tx_engine_reg_write8(port, 9, 0);

    if (size == 0x400) {
        hdcp_tx_engine_reg_write8(port, 8, 0x42);
        hdcp_tx_engine_reg_update_bits(port, 0xf, 0x40, 0);
    } else {
        hdcp_tx_engine_reg_write8(port, 8, 0xc2);
        hdcp_tx_engine_reg_update_bits(port, 0xf, 0x40, 1);
    }

    hdcp_tx_engine_reg_write8(port, 3, 9);

    do {
        status = hdcp_tx_engine_reg_read8(port, 2);
    } while ((status & 0x20) == 0);

    hdcp_tx_engine_reg_write8(port, 3, 0);
    hdcp_tx_engine_reg_write8(port, 8, 0x40);
    hdcp_tx_engine_reg_update_bits(port, 0xf, 0x40, 0);
}
