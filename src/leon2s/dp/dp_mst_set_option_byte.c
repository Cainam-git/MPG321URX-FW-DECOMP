/* dp_mst_set_option_byte  (FUN_a00dc078)
 *
 * Store the MST service's option byte.
 * Name basis: descriptive - byte at 0xA8078841
 *
 * Matching notes
 * --------------
 * FUN_a00dc078 (leon2s 0xa00dc078-0xa00dc084, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 */
extern unsigned char dp_mst_message_state_option_byte;
/*
 * Store the option byte of the MST service. Called by dp_tx_check_training_lost with byte 3 of the link status
 * read from output 0; dp_mst_downstream_task tests bits 4 and 5 of it.
 */
void dp_mst_set_option_byte(unsigned char option)
{
    dp_mst_message_state_option_byte = option;
}
