/* InitHDCP  (FUN_a00c1c18)
 *
 * Load the copy-protection keys and tables into the inputs and HDMI outputs; built-in if none stored.
 * Note: The first key set goes into the six inputs, the second into both HDMI outputs and registers
 *   0xCF018D24.. / 0xCF037800..
 * Name basis: proven - prints 'InitHDCP()......' at its start (original name from the text); eight stored
 *   reads in four groups (first key set, second key set, hdcp2 tables, key header), each with its own all-zero
 *   test that selects built-in copies
 *
 * Matching notes
 * --------------
 * FUN_a00c1c18 (leon2s, 0xa00c1c18-0xa00c224c, 1588 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the five stack buffers are declared in frame order (ksv, keys,
 * hdcp2_value, hdcp2_table, hdcp2_extra); the all-zero tests are written out as && chains; the loop counter
 * is an unsigned short.
 */
#define REG_cf012b84 (*(volatile unsigned int *)0xcf012b84)
#define REG_cf012b88 (*(volatile unsigned int *)0xcf012b88)
#define REG_cf012b8c (*(volatile unsigned int *)0xcf012b8c)

/* Addresses and lengths in the one-time-programmable store (sys_otp_read_bytes). */
#define OTP_KSV_FIRST       0x138       /* 5-byte key-selection value of the first key set */
#define OTP_KEYS_FIRST      0x20        /* key block of the first key set */
#define OTP_KSV_SECOND      0x260       /* 5-byte key-selection value of the second key set */
#define OTP_KEYS_SECOND     0x148       /* key block of the second key set */
#define OTP_HDCP2_VALUE     0x270       /* 16-byte value handed to the *_load_hdcp2_tables routines */
#define OTP_HDCP2_TABLE     0x280       /* 0x20A-byte table, same routines */
#define OTP_HDCP2_EXTRA     0x50a       /* 0x80-byte table, same routines */
#define OTP_KEY_HEADER      0x590       /* 0x24 bytes kept in hdcp_stored_key_header */

#define KSV_LENGTH          5
#define KEY_BLOCK_LENGTH    0x11a       /* bytes read; the last two (0x118, 0x119) are then overwritten */
#define HDCP2_VALUE_LENGTH  0x10
#define HDCP2_TABLE_LENGTH  0x20a
#define HDCP2_EXTRA_LENGTH  0x80
#define KEY_HEADER_LENGTH   0x24

#define HDMI_RX_BOTH        2           /* port 2 of the hdmi_ / hdmi_rx21_ register helpers = both receivers */
#define HDCP_RX_PORTS       6           /* inputs 0, 1 HDMI 2.0; 2, 3 HDMI 2.1; 4, 5 DisplayPort */
#define HDCP_TX_ALL_OUTPUTS 3           /* hdcp_tx_clear_ksv_table: all three outputs */
#define TICK_HOOK_INDEX     0

extern unsigned char hdcp_use_builtin_tables_flag;
extern unsigned char hdcp_use_builtin_table384_flag;
extern unsigned char hdcp_stored_key_header[];
extern unsigned char hdcp_rx_init_flag;
extern const unsigned char hdcp_rx_hdmi_recheck_ports_entry[];

extern int dbg_printf(const char *, ...);
extern void hdmi_reg_update_bits(unsigned char, unsigned short, unsigned int, unsigned char);
extern void hdmi_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdmi_rx21_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void sys_otp_read_bytes(unsigned short, unsigned short, unsigned char *);
extern void ipc_publish_status_flags(void);
extern void sys_register_tick_hook(unsigned int, const unsigned char *);
extern void hdcp_get_default_keys_first(unsigned char *, unsigned char *);
extern void hdcp_get_default_keys_second(unsigned char *, unsigned char *);
extern void hdcp_rx_hdmi_load_keys(unsigned char, unsigned char *, unsigned char *);
extern void hdcp_rx_hdmi21_load_keys(unsigned char, unsigned char *, unsigned char *);
extern void hdcp_rx_dp_load_keys(unsigned char, unsigned char *, unsigned char *);
extern void hdcp_tx_hdmi_load_fixed_streams(unsigned char *, unsigned char *);
extern void hdcp_rx_load_keys_block_first(unsigned char *, unsigned char *);
extern void hdcp_get_default_tables(unsigned char *, unsigned char *, unsigned char *, unsigned char *);
extern void hdcp_rx_hdmi_load_hdcp2_tables(unsigned char, unsigned char *, unsigned char *, unsigned char *, unsigned char *);
extern void hdcp_rx_hdmi21_load_hdcp2_tables(unsigned char, unsigned char *, unsigned char *, unsigned char *, unsigned char *);
extern void hdcp_rx_dp_load_hdcp2_tables(unsigned char, unsigned char *, unsigned char *, unsigned char *, unsigned char *);
extern void hdcp_get_default_id_reversed(unsigned char *, unsigned int, unsigned int);
extern void hdcp_rx_reset_port(unsigned char, unsigned char);
extern void hdcp_rx_set_ddc_addresses(void);
extern void hdcp_tx_clear_ksv_table(unsigned char);

/*
 * Set up the copy protection of the input program at start-up (the firmware prints it as "InitHDCP()").
 * Called once from input_init_receivers, which calls it through its part-3 address 0x9F1B1C18.
 *
 * Every block comes from the one-time-programmable store; when the block that is read first is all zero,
 * nothing is stored there and the built-in copy from the program image is used instead.
 *
 * Phases, in order:
 *   1. Registers 0xCF012B84 / 88 / 8C, then bit 2 of register 0x2E is set on both HDMI 2.0 receivers for the
 *      time of the key loads.
 *   2. First key set (key-selection value + key block) into all six inputs: the two HDMI 2.0, the two
 *      HDMI 2.1 and the two DisplayPort receivers.
 *   3. Second key set into both HDMI outputs (hdcp_tx_hdmi_load_fixed_streams) and into registers
 *      0xCF018D24.. / 0xCF037800.. (hdcp_rx_load_keys_block_first).
 *   4. Bit 2 of register 0x2E cleared again; register writes on the HDMI 2.0 and HDMI 2.1 receivers.
 *   5. The three hdcp2 tables into all six inputs; hdcp_use_builtin_tables_flag tells whether the built-in
 *      ones were used.
 *   6. The 0x24-byte key header into hdcp_stored_key_header (built-in 16 bytes when the stored ones are zero;
 *      hdcp_use_builtin_table384_flag tells which).
 *   7. Reset the protection records of all six inputs, write the device addresses of their control ports,
 *      clear the key-selection values of all three outputs.
 *   8. Mark the set-up done, publish the status flags to the main processor and install
 *      hdcp_rx_hdmi_recheck_ports as tick hook.
 */
void InitHDCP(void)
{
    unsigned char ksv[KSV_LENGTH];                  /* key-selection value of the key set being loaded */
    unsigned char keys[KEY_BLOCK_LENGTH];           /* key block of the key set being loaded */
    unsigned char hdcp2_value[HDCP2_VALUE_LENGTH];
    unsigned char hdcp2_table[0x210];               /* 0x20A bytes used */
    unsigned char hdcp2_extra[0x140];               /* 0x80 bytes loaded, 0x80..0x13F cleared */
    unsigned short i;

    /* 1. Start. */
    REG_cf012b84 = 0;
    REG_cf012b88 = 0;
    REG_cf012b8c = 0x44;
    dbg_printf("\nInitHDCP()......%d\r\n", 0);
    hdmi_reg_update_bits(HDMI_RX_BOTH, 0x2e, 4, 1);

    /* 2. First key set, into every input. */
    sys_otp_read_bytes(OTP_KSV_FIRST, KSV_LENGTH, ksv);
    if (ksv[0] == 0 && ksv[1] == 0 && ksv[2] == 0 && ksv[3] == 0 && ksv[4] == 0) {
        hdcp_get_default_keys_first(ksv, keys);
    } else {
        sys_otp_read_bytes(OTP_KEYS_FIRST, KEY_BLOCK_LENGTH, keys);
        /* Byte 0x118 is 0x68 for the one stored value 24 C8 EB 3E 9C and 0 for every other. */
        if (ksv[0] == 0x24 && ksv[1] == 0xc8 && ksv[2] == 0xeb && ksv[3] == 0x3e && ksv[4] == 0x9c)
            keys[0x118] = 0x68;
        else
            keys[0x118] = 0;
        keys[0x119] = 0;
    }
    hdcp_rx_hdmi_load_keys(0, ksv, keys);
    hdcp_rx_hdmi_load_keys(1, ksv, keys);
    hdcp_rx_hdmi21_load_keys(0, ksv, keys);
    hdcp_rx_hdmi21_load_keys(1, ksv, keys);
    hdcp_rx_dp_load_keys(0, ksv, keys);
    hdcp_rx_dp_load_keys(1, ksv, keys);

    /* 3. Second key set, into the HDMI outputs and the register block behind hdcp_rx_load_keys_block_first. */
    sys_otp_read_bytes(OTP_KSV_SECOND, KSV_LENGTH, ksv);
    if (ksv[0] == 0 && ksv[1] == 0 && ksv[2] == 0 && ksv[3] == 0 && ksv[4] == 0) {
        hdcp_get_default_keys_second(ksv, keys);
    } else {
        sys_otp_read_bytes(OTP_KEYS_SECOND, KEY_BLOCK_LENGTH, keys);
        keys[0x118] = 0;
        keys[0x119] = 0;
    }
    hdcp_tx_hdmi_load_fixed_streams(ksv, keys);
    hdcp_rx_load_keys_block_first(ksv, keys);

    /* 4. Key loads done. */
    hdmi_reg_update_bits(HDMI_RX_BOTH, 0x2e, 4, 0);
    hdmi_reg_write8(HDMI_RX_BOTH, 0x46, 0x60);
    hdmi_rx21_reg_update_bits(HDMI_RX_BOTH, 0x41, 0x10, 1);
    hdmi_rx21_reg_update_bits(HDMI_RX_BOTH, 0x42, 1, 1);

    /* 5. The hdcp2 tables, into every input. */
    for (i = 0x80; i < 0x140; i++)
        hdcp2_extra[i] = 0;
    hdcp_use_builtin_tables_flag = 0;
    sys_otp_read_bytes(OTP_HDCP2_VALUE, HDCP2_VALUE_LENGTH, hdcp2_value);
    if (hdcp2_value[0] == 0 && hdcp2_value[1] == 0 && hdcp2_value[2] == 0 && hdcp2_value[3] == 0 && hdcp2_value[4] == 0 && hdcp2_value[5] == 0 && hdcp2_value[6] == 0 &&
        hdcp2_value[7] == 0 && hdcp2_value[8] == 0 && hdcp2_value[9] == 0 && hdcp2_value[10] == 0 && hdcp2_value[11] == 0 && hdcp2_value[12] == 0 && hdcp2_value[13] == 0 &&
        hdcp2_value[14] == 0 && hdcp2_value[15] == 0) {
        hdcp_get_default_tables(hdcp2_value, hdcp2_table, 0, hdcp2_extra);
        hdcp_use_builtin_tables_flag = 1;
    } else {
        sys_otp_read_bytes(OTP_HDCP2_TABLE, HDCP2_TABLE_LENGTH, hdcp2_table);
        sys_otp_read_bytes(OTP_HDCP2_EXTRA, HDCP2_EXTRA_LENGTH, hdcp2_extra);
    }
    hdcp_rx_hdmi_load_hdcp2_tables(0, hdcp2_value, hdcp2_table, 0, hdcp2_extra);
    hdcp_rx_hdmi_load_hdcp2_tables(1, hdcp2_value, hdcp2_table, 0, hdcp2_extra);
    hdcp_rx_hdmi21_load_hdcp2_tables(0, hdcp2_value, hdcp2_table, 0, hdcp2_extra);
    hdcp_rx_hdmi21_load_hdcp2_tables(1, hdcp2_value, hdcp2_table, 0, hdcp2_extra);
    hdcp_rx_dp_load_hdcp2_tables(0, hdcp2_value, hdcp2_table, 0, hdcp2_extra);
    hdcp_rx_dp_load_hdcp2_tables(1, hdcp2_value, hdcp2_table, 0, hdcp2_extra);

    /* 6. The key header; only its first 16 bytes decide whether it is stored. */
    hdcp_use_builtin_table384_flag = 0;
    sys_otp_read_bytes(OTP_KEY_HEADER, KEY_HEADER_LENGTH, hdcp_stored_key_header);
    if (hdcp_stored_key_header[0] == 0 && hdcp_stored_key_header[1] == 0 && hdcp_stored_key_header[2] == 0 && hdcp_stored_key_header[3] == 0 &&
        hdcp_stored_key_header[4] == 0 && hdcp_stored_key_header[5] == 0 && hdcp_stored_key_header[6] == 0 && hdcp_stored_key_header[7] == 0 &&
        hdcp_stored_key_header[8] == 0 && hdcp_stored_key_header[9] == 0 && hdcp_stored_key_header[10] == 0 && hdcp_stored_key_header[11] == 0 &&
        hdcp_stored_key_header[12] == 0 && hdcp_stored_key_header[13] == 0 && hdcp_stored_key_header[14] == 0 &&
        hdcp_stored_key_header[15] == 0) {
        hdcp_get_default_id_reversed(hdcp_stored_key_header, 0, 0);
        hdcp_use_builtin_table384_flag = 1;
    }

    /* 7. Reset the input records; the second argument selects the register writes of the reset: 1 those of
          the HDMI receivers (inputs 0..3), 0 those of the DisplayPort receivers (inputs 4, 5). */
    for (i = 0; i < 4; i++)
        hdcp_rx_reset_port(i, 1);
    for (i = 4; i < HDCP_RX_PORTS; i++)
        hdcp_rx_reset_port(i, 0);
    hdcp_rx_set_ddc_addresses();
    hdcp_tx_clear_ksv_table(HDCP_TX_ALL_OUTPUTS);

    /* 8. Done: status bit 1 of the published flags; hdcp_rx_hdmi_recheck_ports becomes a tick hook. */
    hdcp_rx_init_flag = 1;
    ipc_publish_status_flags();
    dbg_printf("InitHDCP() END......%d\r\n", 0);
    sys_register_tick_hook(TICK_HOOK_INDEX, hdcp_rx_hdmi_recheck_ports_entry);
}
