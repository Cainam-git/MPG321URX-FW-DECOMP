/* hdcp_tx_engine_load_table  (FUN_a00c9e44)
 *
 * Load a 384-byte table into the engine of an output and read 32 bytes back.
 * Name basis: derived - table load with a read-back of the result
 *
 * Matching notes
 * --------------
 * FUN_a00c9e44 (leon2s 0xa00c9e44-0xa00ca074, 560 bytes), flags -mcpu=v8 -Os -g.
 * Loop counters are unsigned short. The mode byte is addressed as hdcp_tx_engine_buffer[0x17f], an element of the
 * buffer. The empty counting loop after the read-back is part of the build.
 */
extern unsigned char hdcp_use_builtin_table384_flag;
extern unsigned char hdcp_tx_engine_buffer[];
extern unsigned char hdcp_tx_work_block[];
extern const unsigned char hdcp_tx_engine_table_384[];
extern void hdcp_tx_engine_reg_update_bits(unsigned int, short, unsigned int, unsigned int);
extern void hdcp_tx_engine_reg_write8(unsigned int, unsigned int, unsigned int);
extern unsigned int hdcp_tx_engine_reg_read8(unsigned int, unsigned int);
extern void sys_otp_read_bytes(unsigned short, unsigned short, unsigned char *);
extern void hdcp_tx_engine_write_block(unsigned int, unsigned char *, unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_engine_run_step_first(unsigned char, unsigned short);
extern void hdcp_tx_engine_read_384_bytes(unsigned int, unsigned short);
extern int hdcp_tx_engine_read_block(unsigned int, unsigned char *, unsigned char, unsigned short);

#define TABLE_SIZE         0x180        /* bytes of the table and of hdcp_tx_engine_buffer */
#define MODE_BYTE_INDEX    0x17f        /* last byte of the buffer: the mode byte */
#define BUILTIN_MODE_BYTE  3            /* mode byte when the built-in table is used */
#define OTP_MODE_BYTE      0x734        /* store address of the mode byte otherwise */
#define OTP_TABLE          0x5b4        /* store address of the 0x180-byte table otherwise */
#define BLOCK_LENGTH       0xc00        /* last argument of the block calls: 0xc00 / 16 words = 0x180 bytes */
#define WRITE_MODE_HEADER  5            /* hdcp_tx_engine_write_block mode of the first send */
#define WRITE_MODE_TABLE   3            /* ... and of the second send */
#define READ_MODE_RESULT   6            /* hdcp_tx_engine_read_block mode of the read-back */
#define RESULT_OFFSET      0x160        /* the 32 result bytes are the last 32 bytes of the read-back */
#define RESULT_SIZE        0x20

/*
 * Load the 0x180-byte table into the protection engine of one output and read the 32 result bytes back.
 *
 *   unit  engine unit of the output (the record's engine_unit)
 *
 * Order:
 *  1. Bit 1 of engine register 0 is set and cleared again.
 *  2. The buffer is filled with zeros except its last byte, the mode byte: 3 when hdcp_use_builtin_table384_flag
 *     is set, otherwise the byte stored at 0x734. It is sent with write mode 5.
 *  3. The buffer is filled with the table: the built-in table 0x9f1c1ca8 when the flag is set, otherwise the
 *     0x180 bytes stored at 0x5b4. It is sent with write mode 3.
 *  4. hdcp_tx_engine_run_step_first and hdcp_tx_engine_read_384_bytes run with the same length. Then bits 6..7
 *     of engine register 0xf are set, register 0 is set to 0 and register 3 to 1, and the routine waits for
 *     bit 5 of register 2 (no time-out). Register 2 gets 0x40 and bit 0 of register 3 is cleared.
 *  5. The engine's block (read mode 6) is read back into the buffer. Its last 32 bytes (offset 0x160) are
 *     copied to hdcp_tx_work_block, and bits 6..7 of register 0xf are cleared.
 *
 * The caller (hdcp_tx_hdmi_state_compare_results) compares those 32 bytes with hdcp_tx_result_block.
 */
void hdcp_tx_engine_load_table(unsigned char unit)
{
    unsigned short i;

    hdcp_tx_engine_reg_update_bits(unit, 0, 2, 1);
    hdcp_tx_engine_reg_update_bits(unit, 0, 2, 0);
    if (hdcp_use_builtin_table384_flag != 0)
        hdcp_tx_engine_buffer[MODE_BYTE_INDEX] = BUILTIN_MODE_BYTE;
    else
        sys_otp_read_bytes(OTP_MODE_BYTE, 1, &hdcp_tx_engine_buffer[MODE_BYTE_INDEX]);
    for (i = 0; i < MODE_BYTE_INDEX; i++)
        hdcp_tx_engine_buffer[i] = 0;
    hdcp_tx_engine_write_block(unit, hdcp_tx_engine_buffer, WRITE_MODE_HEADER, 0, BLOCK_LENGTH);
    if (hdcp_use_builtin_table384_flag != 0) {
        for (i = 0; i < TABLE_SIZE; i++)
            hdcp_tx_engine_buffer[i] = hdcp_tx_engine_table_384[i];
    } else {
        sys_otp_read_bytes(OTP_TABLE, TABLE_SIZE, hdcp_tx_engine_buffer);
    }
    hdcp_tx_engine_write_block(unit, hdcp_tx_engine_buffer, WRITE_MODE_TABLE, 0, BLOCK_LENGTH);
    hdcp_tx_engine_run_step_first(unit, BLOCK_LENGTH);
    hdcp_tx_engine_read_384_bytes(unit, BLOCK_LENGTH);
    hdcp_tx_engine_reg_update_bits(unit, 0xf, 0xc0, 1);
    hdcp_tx_engine_reg_write8(unit, 0, 0);
    hdcp_tx_engine_reg_write8(unit, 3, 1);
    while ((hdcp_tx_engine_reg_read8(unit, 2) & 0x20) == 0)
        ;
    hdcp_tx_engine_reg_write8(unit, 2, 0x40);
    hdcp_tx_engine_reg_update_bits(unit, 3, 1, 0);
    hdcp_tx_engine_read_block(unit, hdcp_tx_engine_buffer, READ_MODE_RESULT, BLOCK_LENGTH);
    for (i = 0; i < TABLE_SIZE; i++)
        ;
    for (i = 0; i < RESULT_SIZE; i++)
        hdcp_tx_work_block[i] = hdcp_tx_engine_buffer[i + RESULT_OFFSET];
    hdcp_tx_engine_reg_update_bits(unit, 0xf, 0xc0, 0);
}
