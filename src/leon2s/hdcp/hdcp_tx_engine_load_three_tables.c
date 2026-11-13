/* hdcp_tx_engine_load_three_tables  (FUN_a00c22a0)
 *
 * Send three 128-byte tables to the protection engine.
 * Name basis: descriptive - ROM tables or stored ones; engine block writes with modes 5, 3 and 4
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c22a0 @ 0xa00c22a0, flags -mcpu=v8 -Os -g (the section default).
 * Source form: the loop counter is initialised at its declaration, so the first copy loop has no init of its
 * own; the three tables are stack arrays declared in the order mode 5, mode 3, mode 4.
 */
extern unsigned char hdcp_use_builtin_tables_flag;
extern unsigned char hdcp_tx_engine_table_mode0[];
extern const unsigned char hdcp_tx_engine_table_mode5[];
extern const unsigned char hdcp_default_table_block[];
extern const unsigned char hdcp_tx_engine_table_mode4[];
extern void hdcp_tx_engine_reg_update_bits(unsigned int, short, unsigned int, unsigned int);
extern void hdcp_tx_engine_reg_write8(unsigned int, unsigned int, unsigned int);
extern void sys_otp_read_bytes(unsigned short, unsigned short, unsigned char *);
extern void hdcp_tx_engine_write_block(unsigned int, unsigned char *, unsigned char, unsigned char, unsigned short);

#define TABLE_LENGTH       0x80     /* bytes of each table */
#define BLOCK_LENGTH       0x400    /* last argument of hdcp_tx_engine_write_block, the same for all four */
#define DEFAULT_MODE3_SKIP 0x2d     /* the mode 3 table starts this far into hdcp_default_table_block */

/* Where the stored copy of each table lies in the one-time-programmable store. */
#define OTP_TABLE_MODE5    0x50a
#define OTP_TABLE_MODE3    0x285
#define OTP_TABLE_MODE4    0x48a

/*
 * Send the engine of one protection unit its tables.
 *
 *   port  the engine unit: 0 for the HDMI 2.0 inputs, 1 for the HDMI 2.1 inputs, 2 for the DisplayPort inputs
 *
 * Called by hdcp_rx_key_load_step in step 0 (key_step KEY_STEP_READ_TABLE), after it has put the 128 bytes
 * read from the receiver into hdcp_tx_engine_table_mode0.
 *
 * Order: bit 1 of engine register 0 is set and cleared again; the three 128-byte tables are sent with
 * hdcp_tx_engine_write_block in modes 5, 3 and 4; then hdcp_tx_engine_table_mode0 is sent in mode 0; last,
 * engine register 0 is set to 0 and register 3 to 1. Each of the three tables is read from the built-in copy
 * in the program image when hdcp_use_builtin_tables_flag is set (InitHDCP sets it when the 16 bytes
 * stored at 0x270 are all zero), otherwise from the store (OTP_TABLE_* addresses).
 */
void hdcp_tx_engine_load_three_tables(unsigned char port)
{
    unsigned char table_mode5[TABLE_LENGTH];
    unsigned char table_mode3[TABLE_LENGTH];
    unsigned char table_mode4[TABLE_LENGTH];
    unsigned short i = 0;

    hdcp_tx_engine_reg_update_bits(port, 0, 2, 1);
    hdcp_tx_engine_reg_update_bits(port, 0, 2, 0);
    if (hdcp_use_builtin_tables_flag != 0) {
        for (; i < TABLE_LENGTH; i++)
            table_mode5[i] = hdcp_tx_engine_table_mode5[i];
    } else {
        sys_otp_read_bytes(OTP_TABLE_MODE5, TABLE_LENGTH, table_mode5);
    }
    hdcp_tx_engine_write_block(port, table_mode5, 5, 0, BLOCK_LENGTH);
    if (hdcp_use_builtin_tables_flag != 0) {
        for (i = 0; i < TABLE_LENGTH; i++)
            table_mode3[i] = hdcp_default_table_block[i + DEFAULT_MODE3_SKIP];
    } else {
        sys_otp_read_bytes(OTP_TABLE_MODE3, TABLE_LENGTH, table_mode3);
    }
    hdcp_tx_engine_write_block(port, table_mode3, 3, 0, BLOCK_LENGTH);
    if (hdcp_use_builtin_tables_flag != 0) {
        for (i = 0; i < TABLE_LENGTH; i++)
            table_mode4[i] = hdcp_tx_engine_table_mode4[i];
    } else {
        sys_otp_read_bytes(OTP_TABLE_MODE4, TABLE_LENGTH, table_mode4);
    }
    hdcp_tx_engine_write_block(port, table_mode4, 4, 0, BLOCK_LENGTH);
    hdcp_tx_engine_write_block(port, hdcp_tx_engine_table_mode0, 0, 0, BLOCK_LENGTH);
    hdcp_tx_engine_reg_write8(port, 0, 0);
    hdcp_tx_engine_reg_write8(port, 3, 1);
}
