/* ipc_sum_flash_data  (FUN_CODE_b781)
 *
 * Walk the 2 KB flash data buffer in four 512-byte blocks and return a 32-bit result that is always 0.
 * Returns: 0 (the result starts at 0 and is only shifted)
 * Note: Per block the bytes are added into an 8-bit sum and the 32-bit result is shifted left by (sum + 8);
 *   nothing is ever added to the result, so it is not a sum of the data.
 * Name basis: derived - four 512-byte blocks at 0xA800; result word posted to portal word 0xB0
 *   (ipc_post_result_word) after message type 7 and command 0x12
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b781, OPTIMIZE(8,SPEED) LARGE.
 * LARGE locals (XDATA): the pointer p is a generic pointer advanced by ?C?ILDIX; the 512-count is a register pair.
 */
extern unsigned char xdata flash_data_buffer[];

/*
 * ipc_sum_flash_data - go through the 2 KB flash data buffer at XDATA 0xA800 in four blocks of 0x200 bytes. Per
 * block, the bytes are added into an 8-bit sum; the 32-bit result is then shifted left by (that sum + 8). Returns
 * the result.
 * Callers: code at 0x21B0 (inside the range of ipc_run_message) and ipc_run_command.
 */
unsigned long ipc_sum_flash_data(void)
{
    unsigned char block;
    unsigned char byte_sum;
    unsigned long result;
    unsigned char *ptr;
    unsigned int count;

    result = 0;
    ptr = flash_data_buffer;
    for (block = 0; block != 4; block++) {
        byte_sum = 0;
        for (count = 0; count != 0x200; count++) {
            byte_sum += *ptr++;
        }
        result = result << (byte_sum + 8);
    }
    return result;
}
