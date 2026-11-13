/* hdcp_tx_hdmi_run_fixed_block  (FUN_a00ca6d4)
 *
 * Write a 16-byte fixed block to the engine, wait and read 32 result bytes.
 * Name basis: descriptive - ROM table, poll of register 8
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ca6d4 @ 0xa00ca6d4-0xa00ca8c4, -mcpu=v8 -Os -g.
 * The counters are unsigned char; the empty delay loops are part of the build. The fixed block lies in the program image outside the loaded part (address 0x9f1c1e48).
 */
extern const unsigned char hdcp_tx_engine_fixed_block[];
extern unsigned char hdcp_tx_result_block[];
extern void hdcp_tx_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned short);

#define OUTPUT_DP            2          /* the DisplayPort output; the two HDMI outputs are 0 and 1 */
#define FIXED_BLOCK_OFFSET   0x4f       /* the 16 bytes sent are hdcp_tx_engine_fixed_block[0x4f..0x5e] */
#define FIXED_BLOCK_SIZE     16
#define RESULT_SIZE          32
#define COMMAND_LENGTH       0x8000     /* length given with the engine commands 1, 3, 6, 0xf and 0x10 */
#define POLL_TRIES           0xff

/*
 * Send a fixed 16-byte block to the protection block of an output, start the engine commands that follow, wait
 * for register 8 and read 32 result bytes into hdcp_tx_result_block.
 *
 *   port  video output 0..2 (the protection block of that output)
 *
 * Returns 1 when the wait on register 8 runs out (255 reads without bit 0 or bit 1 set), 0 when the result was
 * read.
 *
 * Called by hdcp_tx_hdmi_state_read_32_bytes (HDMI outputs) and hdcp_tx_dp_state_compare_aux_block (DisplayPort).
 *
 * Order:
 *  1. Bits 0 and 1 of register 5 are set. Engine command 0xf (length 0x8000).
 *  2. The 16 bytes are written one by one: to register 0x12 for the HDMI outputs, to register 1 for output 2.
 *  3. Engine commands 1, 3 and 0xf, each followed by an empty delay loop.
 *  4. Bits 0 and 1 of register 8 are set, register 6 gets 8, and register 8 is read until one of its bits 0..1
 *     is set (return 1 when that does not happen within 255 reads).
 *  5. Engine commands 0x10 and 6; after the second one 32 bytes are read from register 1 into
 *     hdcp_tx_result_block.
 */
unsigned char hdcp_tx_hdmi_run_fixed_block(unsigned char port)
{
    unsigned char i, tries;

    hdcp_tx_reg_update_bits(port, 5, 1, 1);
    hdcp_tx_reg_update_bits(port, 5, 2, 1);
    hdcp_tx_engine_start_command(port, 0xf, COMMAND_LENGTH);
    for (i = 0; i < FIXED_BLOCK_SIZE; i++) {
        if (port != OUTPUT_DP)
            hdcp_tx_reg_write(port, 0x12, hdcp_tx_engine_fixed_block[FIXED_BLOCK_OFFSET + i]);
        else
            hdcp_tx_reg_write(OUTPUT_DP, 1, hdcp_tx_engine_fixed_block[FIXED_BLOCK_OFFSET + i]);
    }
    hdcp_tx_engine_start_command(port, 1, COMMAND_LENGTH);
    for (i = 0; i <= 0xa; i++)
        ;
    hdcp_tx_engine_start_command(port, 3, COMMAND_LENGTH);
    for (i = 0; i <= 0xa; i++)
        ;
    hdcp_tx_engine_start_command(port, 0xf, COMMAND_LENGTH);
    for (i = 0; i <= 0xf; i++)
        ;
    hdcp_tx_reg_update_bits(port, 8, 3, 1);
    hdcp_tx_reg_write(port, 6, 8);
    tries = POLL_TRIES;
    while ((hdcp_tx_reg_read(port, 8) & 3) == 0) {
        tries--;
        if (tries == 0)
            return 1;
    }
    hdcp_tx_engine_start_command(port, 0x10, COMMAND_LENGTH);
    for (i = 0; i <= 0x1f; i++)
        ;
    hdcp_tx_engine_start_command(port, 6, COMMAND_LENGTH);
    for (i = 0; i < RESULT_SIZE; i++)
        hdcp_tx_result_block[i] = hdcp_tx_reg_read(port, 1);
    for (i = 0; i <= 0x1f; i++)
        ;
    return 0;
}
