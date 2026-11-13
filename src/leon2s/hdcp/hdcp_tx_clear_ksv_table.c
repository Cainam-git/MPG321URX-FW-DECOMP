/* hdcp_tx_clear_ksv_table  (FUN_a00c79c8)
 *
 * Clear the stored 5-byte key-selection values: all three rows for port 3, else row 0 only.
 * Name basis: derived - 3 x 5 byte table at 0xA807CDA8
 *
 * Matching notes
 * --------------
 * FUN_a00c79c8 (leon2s 0xa00c79c8-0xa00c7a4c, 132 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: the row counter starts at 0 at its declaration and the row loop is a do-while.
 */
extern unsigned char hdcp_tx_ksv_table[3][5];

#define HDCP_TX_ALL_OUTPUTS 3                   /* port value that clears every row */
#define KSV_LENGTH          5                   /* bytes of one key-selection value */

/*
 * Clear stored key-selection values of the outputs (hdcp_tx_ksv_table: one 5-byte row per output). With
 * port == 3 all three rows are cleared. With any other value only row 0 is cleared: the row is not chosen by
 * port.
 *
 * Called from InitHDCP with 3, and from the output handshake states (for example
 * hdcp_tx_hdmi_state_compare_results, hdcp_tx_dp_state_compare_aux_block) with the output number.
 */
void hdcp_tx_clear_ksv_table(unsigned char port)
{
    unsigned char row = 0;
    unsigned char j = 0;

    if (port == HDCP_TX_ALL_OUTPUTS) {
        do {
            for (j = 0; j < KSV_LENGTH; j++)
                hdcp_tx_ksv_table[row][j] = 0;
            row++;
        } while (row < 3);
    } else {
        for (j = 0; j < KSV_LENGTH; j++)
            hdcp_tx_ksv_table[row][j] = 0;
    }
}
