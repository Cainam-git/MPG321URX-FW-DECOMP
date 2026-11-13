/* ddc_apply_maker_vcp_set  (FUN_a00cfacc)
 *
 * Carry out a DDC/CI 'Set VCP Feature' request for the maker code 0xFE and fill its reply.
 *   request
 *   reply: reply buffer
 * Note: Request byte 4 is the sub-code: 0x04 reset, 0x08 save, 0x10 (byte 5 = 0x0E) brightness knee, 0x12
 *   contrast, 0x14 colour, 0x16..0x1A colour entry, 0x60 input, 0x6C..0x70, 0xCC language, 0xE1 factory, 0xEF
 *   serial number or EDID write.
 * Name basis: derived - called only from the 0xFE case of the SetVCP switch of ddc_handle_request; switches on
 *   request byte 4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00cfacc @ 0xa00cfacc-0xa00d0e48 (1247 words), flags -mcpu=v8 -O3 -g.
 * Jump tables: the 0x14 colour switch at 0x0006ec0c (12 entries), the language switch at 0x0006eb74 (38 entries).
 * Source forms the exact build depends on:
 *  - the case blocks in ascending sub-code order (the switch becomes a compare tree); the send_crc_reply tests
 *    read request[4] directly;
 *  - case 4 holds its test of factory_marker in saved, the variable that case 8 uses for the burn-in byte;
 *  - case 0x12 stores request[5] first and then limits the stored byte;
 *  - the 0x14 colour temperature switch has no default ('color_temperature = 0;' before it), and the value is
 *    copied to the unsigned int word_value for the compare and store of byte +0x11 (the firmware keeps the
 *    zero-extended value, 'and %o5, 0xff, %l0' at 0xa00d04a4);
 *  - the OR of the three status flags is formed in the unsigned short status_flags and copied to word_value, with
 *    the low reply byte from the unsigned char copy flags_low;
 *  - the 0xE1 arms A2/00, A5/00, A7/06 and A7/03 call ddc_raise_event3 once after their if/else;
 *  - for 0xE1 key ED/05 the case ends without further tests (0xa00cfda0, 0xa00d0a24);
 *  - the A7/13 arm tests 'request[7] == 1' first; the other arm clears the bit, sets knee = 0x36f, stores knee in
 *    brightness_knee and 70 in brightness; the reply of the first arm also goes through knee;
 *  - in 0xEF the retry bytes are set in the order DAT_a802b0a4_retry_max, DAT_a802b0a3_retry_cnt; the serial arm
 *    reads request[7] and request[6] in that order and copies with its own counter j; the EDID path stores the
 *    end through the pointer edid_end_ptr; the 0x42 / 0x43 arms test 'end >= edid_end' first (copy loop and
 *    edid_api_write_port_edid call) with the plain copy loop as else; the last test is
 *    'offset_low + 0x20 < edid_end' (0xa00d016c).
 * Symbol names: GCC numbers the three address registers of the 0xEF case (%l1, %l3, %l4 at
 *   0xa00d008c..0xa00d0098 and 0xa00d015c) in the order of a hash of the symbol names. The original names are not
 *   known. The three names DAT_a802b0a3_retry_cnt (counter set to 2, decremented when the block sum is 0),
 *   DAT_a802b0a4_retry_max (its reload value) and DAT_a802d250_xfer (record of the 0xEF transfer) give the
 *   firmware's register order, so these three symbol names stay as they are. No other routine uses these three
 *   objects.
 */

/* The fields of the user settings record (docs/RECORDS.md) that this file uses through the record. */
struct user_settings_record {
    unsigned int word_0x0;                      /* +0x00: SETTINGS_WORD0_* bits */
    unsigned char pad004[5];
    unsigned char brightness;                   /* +0x09 */
    unsigned char contrast;                     /* +0x0A */
    unsigned char pad00b[5];
    unsigned char audio_level;                  /* +0x10 */
    unsigned char color_temperature;            /* +0x11 */
    unsigned char red_gain;                     /* +0x12..+0x14: the custom colour values */
    unsigned char green_gain;
    unsigned char blue_gain;
    unsigned char pad015[0x107];
    unsigned int professional_flags;            /* +0x11C: bit 31 automatic level */
    unsigned char pad120[0xb4];
    union {
        unsigned int word;                      /* bit 6 SETTINGS_CEC_PWM_ADJUST */
        unsigned char bytes[4];                 /* bytes[1] = +0x1D5, the burn-in flag */
    } word_0x1d4;
    unsigned char cec_pwm_brightness;           /* +0x1D8: the brightness that CEC PWM Adjust loads */
    unsigned char pad1d9;
    unsigned short brightness_knee;             /* +0x1DA */
    unsigned char pad1dc[0x1a];
    unsigned short factory_marker;              /* +0x1F6: FACTORY_MODE_MARKER or FACTORY_MODE_OFF_MARKER */
};
/* The record of an EDID or serial-number transfer over sub-code 0xEF (only this routine uses it). */
struct edid_transfer_record {
    unsigned char command;                      /* request byte 5: FACTORY_DATA_* */
    unsigned char sum;                          /* sum of the data bytes since the piece at offset_low 0 */
    unsigned short edid_end;                    /* EDID length; reaching it writes the EDID to the port */
};
/* The factory record (docs/RECORDS.md), 0x1C bytes; it starts with the serial number. */
struct factory_record_serial {
    unsigned char byte_0x0, byte_0x1;
    unsigned char serial_length;                /* +0x02: number of serial characters */
    unsigned char serial[0x19];                 /* +0x03: the characters, then the rest of the record */
};
/* The three DDC/CI status entries. */
struct ddc_status_entry {
    unsigned short value_and_key;               /* byte 0 value, byte 1 key (ddc_find_status_entry) */
    unsigned short flags;                       /* ORed together by ddc_combine_status_flags */
};
extern struct user_settings_record user_settings;
extern struct edid_transfer_record DAT_a802d250_xfer;
extern struct factory_record_serial factory_record;
extern struct ddc_status_entry ddc_status_entries[];
extern unsigned char ddc_tool_edid_buffer[];
extern unsigned char part_record[];
extern unsigned char user_settings_language, user_settings_red_black_level, user_settings_green_black_level, user_settings_blue_black_level, user_settings_input_source;
extern unsigned char ddc_tool_inverted_flag, ddc_color_entry_byte2, ddc_color_entry_byte1, ddc_color_entry_byte0, DAT_a802b0a3_retry_cnt, DAT_a802b0a4_retry_max;
extern unsigned char channel_records_byte_0x3a;

extern void ddc_raise_event0(void);
extern void ddc_raise_event3(void);
extern void ddc_raise_event2(void);
extern void ddc_raise_event1(void);
extern void ddc_set_checksum_byte(unsigned char);
extern unsigned short lib_crc16_ccitt_update(unsigned char, unsigned short);
extern void sys_set_factory_mode_flag(void);
extern void sys_clear_factory_mode_flag(void);
extern void pq_api_enable_color_matrix(unsigned char ch, unsigned char off);
extern void pq_api_set_color_matrix_option(int);
extern void pq_color_matrix_set_red_gain(unsigned short v);
extern void pq_color_matrix_set_green_gain(unsigned short v);
extern void pq_color_matrix_set_blue_gain(unsigned short v);
extern void pq_user_apply_red_offset(void);
extern void pq_user_apply_green_offset(void);
extern void pq_user_apply_blue_offset(void);
extern void sys_user_factory_reset(void);
extern void gpio_set_port4_bit7_low_if_allowed(void);
extern void gpio_set_port4_bit4_high_if_allowed(void);
extern unsigned int sys_get_channel_state(unsigned int);
extern void sys_poll_events_stub_copy18(void);
extern void sys_poll_events_stub_copy19(void);
extern void SYSAPI_PowerOff(void);
extern unsigned char input_get_port_sync_mode(unsigned int);
extern void sys_poll_events_stub_copy20(int);
extern void pq_user_apply_color_gain(void);
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern int pq_select_rate_mode(unsigned short x);
extern void sys_user_apply_brightness(void);
extern int SYSAPI_WriteEEPROM(int, void *, int, int);
extern void pq_user_apply_color_settings(void);
extern void nvram_api_store_by_selector(unsigned char);
extern void pq_api_set_fill_color(int, int, int, int, int);
extern void pq_block_blank(unsigned char);
extern void nvram_set_device_setting(int, int);
extern void input_api_set_port_signal(unsigned char p, unsigned char on);
extern void sys_user_apply_auto_level(void);
extern void sys_user_save_mode_slot(void);
extern void edid_api_write_port_edid(unsigned char port, unsigned char b, unsigned int addr, unsigned short len,
                         unsigned char clear);

/* Reply byte 0 (docs/MAP.md: the DDC/CI address) and the first value of the reply XOR checksum. */
#define DDC_ADDRESS               0x6e
#define DDC_CHECKSUM_SEED         0x50
/* Reply byte 1: 0x80 + the number of bytes that follow it (before the checksum). */
#define DDC_LENGTH_BYTE(n)        ((n) + 0x80)

/* Sub-codes of SetVCP 0xFE (request byte 4). Request bytes 5..7 are the arguments, data starts at byte 8. */
enum maker_set_code {
    MAKER_SET_FACTORY_RESET     = 0x04,
    MAKER_SET_SAVE_SETTINGS     = 0x08,         /* write the settings record to the EEPROM */
    MAKER_SET_BRIGHTNESS_KNEE   = 0x10,         /* with request byte 5 = 0x0E */
    MAKER_SET_CONTRAST          = 0x12,
    MAKER_SET_COLOR             = 0x14,         /* colour temperature, or store the colour entry */
    MAKER_SET_COLOR_ENTRY_0     = 0x16,         /* matrix red gain, kept in ddc_color_entry_byte0 */
    MAKER_SET_COLOR_ENTRY_1     = 0x18,         /* matrix green gain, ddc_color_entry_byte1 */
    MAKER_SET_COLOR_ENTRY_2     = 0x1a,         /* matrix blue gain, ddc_color_entry_byte2 */
    MAKER_SET_1E                = 0x1e,
    MAKER_SET_1F                = 0x1f,         /* no case of its own: only the CRC reply */
    MAKER_SET_INPUT_SOURCE      = 0x60,
    MAKER_SET_RED_BLACK_LEVEL   = 0x6c,
    MAKER_SET_GREEN_BLACK_LEVEL = 0x6e,
    MAKER_SET_BLUE_BLACK_LEVEL  = 0x70,
    MAKER_SET_LANGUAGE          = 0xcc,
    MAKER_SET_POWER             = 0xd6,
    MAKER_SET_FACTORY           = 0xe1,         /* factory switches, chosen by request bytes 5 and 6 */
    MAKER_SET_PART_BYTE         = 0xe2,
    MAKER_SET_FILL_COLOR        = 0xe7,
    MAKER_SET_FACTORY_DATA      = 0xef          /* serial number or EDID, 32 bytes per request */
};

/* Request byte 5 of sub-code 0xEF. */
#define FACTORY_DATA_SERIAL       0x13
#define FACTORY_DATA_EDID         0x42
#define FACTORY_DATA_EDID_ALT     0x43          /* handled exactly as 0x42 */
#define EDID_PIECE                0x20          /* data bytes in one 0xEF request (request bytes 8..0x27) */

/* Settings word +0 bits. */
#define SETTINGS_WORD0_FACTORY_MODE 0x4000      /* bit 14: sys_set_factory_mode_flag / sys_clear_factory_mode_flag */
#define SETTINGS_WORD0_BIT12      0x1000
#define PROFESSIONAL_AUTO_LEVEL   0x80000000    /* professional_flags bit 31: automatic level */
#define SETTINGS_CEC_PWM_ADJUST   0x40          /* word_0x1d4 bit 6 */
#define BURN_IN_FLAG              1             /* word_0x1d4.bytes[1] = settings +0x1D5 */

#define FACTORY_MODE_MARKER       0x55aa        /* factory_marker values */
#define FACTORY_MODE_OFF_MARKER   0xbb99

#define CEC_PWM_OFF_KNEE          0x36f         /* brightness_knee when CEC PWM Adjust is switched off */
#define CEC_PWM_OFF_BRIGHTNESS    70
#define KNEE_MIN                  0x7e          /* limits of brightness_knee (the values of LEVEL_MIN / LEVEL_MAX) */
#define KNEE_MAX                  0x3ff

#define PERCENT_MAX               100

/* Part record rows of three colour bytes (docs/RECORDS.md). */
#define PART_WARM50               6
#define PART_NORMAL65             9
#define PART_COOL93               0x12
#define PART_ENTRY_21             0x21

#define EEPROM_AREA               0x30          /* first argument of SYSAPI_WriteEEPROM */
#define USER_SETTINGS_OFFSET      0
#define USER_SETTINGS_SIZE        0x1fc
#define FACTORY_RECORD_OFFSET     0x2e0
#define FACTORY_RECORD_SIZE       0x1c

/* Fields of nvram_set_device_setting cleared by key A3 00 00; 6 and 7 are the on-time minutes and hours. */
#define DEVICE_SETTING_8          8
#define DEVICE_SETTING_9          9
#define DEVICE_SETTING_ON_TIME_MINUTES 6
#define DEVICE_SETTING_ON_TIME_HOURS   7

/* States of sys_get_channel_state (channel word 0 bits 28..31). */
#define CH_STATE_OFF              0
#define CH_STATE_1                1
#define CH_STATE_4                4
#define MODE_WAITMODECHANGE       0xc

#define TIMING_REFRESH_RATE       1             /* input_api_get_timing_field: tenths of a hertz */
#define PORT_TYPE_5               5             /* input_get_port_sync_mode value */
#define ALL_PORTS                 0xfe          /* input_api_set_port_signal: every port */
#define PORT_SIGNAL_ON            1
#define EDID_SOURCE_FF            0xff          /* source passed to edid_api_write_port_edid */

/*
 * Inlined copy of ddc_build_crc_reply: reply 6E 83 02 crc_high crc_low, the CRC over request bytes 4..7
 * (lib_crc16_ccitt_update, starting from 0), and the reply checksum byte reset to 0x50.
 */
static void ddc_build_crc_reply(unsigned char *request, unsigned char *reply)
{
  unsigned short crc = 0;
  unsigned char i;

  for (i = 4; i < 8; i++)
    crc = lib_crc16_ccitt_update(request[i], crc);
  reply[0] = DDC_ADDRESS;
  reply[1] = DDC_LENGTH_BYTE(3);
  reply[2] = 2;
  reply[3] = crc >> 8;
  reply[4] = crc;
  ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
}

/*
 * Carry out a SetVCP request for the maker code 0xFE.
 *
 *   request  the request; byte 1 = 0x80 + length, byte 3 = 0xFE, byte 4 = the sub-code, bytes 5..7 its
 *            arguments, data from byte 8
 *   reply    the reply buffer (40 bytes)
 *
 * Called only from ddc_handle_request (its SetVCP answer). The caller does not clear the reply buffer before the
 * call, and afterwards adds the checksum and sends the first 10 bytes whatever this routine wrote.
 *
 * Several sub-codes end by raising pending DDC/CI events, which ddc_post_pending_event turns into application
 * events: ddc_raise_event0 = event 0xC0 (save the user settings), ddc_raise_event1 = 0xC2,
 * ddc_raise_event3 = 0xC1, ddc_raise_event2 = 0xC3.
 *
 * Phases:
 *   1. Decide whether the request gets the CRC reply (send_crc_reply): sub-codes 0x04, 0x1F, 0x60, 0xCC, 0x14
 *      with byte 7 = 0, 0x08 with bytes 5..6 = 01 00, 0x10 with byte 5 = 0x0E, and 0xE1 with bytes 5..6 = A0 00,
 *      A2 00, A5 00 or A4 20..23.
 *   2. Carry out the sub-code:
 *      - settings: factory reset (0x04), save (0x08), brightness knee (0x10), contrast (0x12), colour
 *        temperature and stored colour rows (0x14), matrix gains (0x16..0x1A), black levels (0x6C..0x70),
 *        input source (0x60), language (0xCC);
 *      - power (0xD6), the factory switches (0xE1), part record bytes (0xE2), fill colour (0xE7);
 *      - serial number and EDID transfer (0xEF), with replies of their own.
 *   3. Write the CRC reply when phase 1 chose it; it replaces bytes 0..4 of any reply written in phase 2.
 */
void ddc_apply_maker_vcp_set(unsigned char *request, unsigned char *reply)
{
    unsigned char send_crc_reply;
    unsigned char color_temperature;
    unsigned char marker_was_set;
    unsigned char saved;
    unsigned char offset_high;
    unsigned char offset_low;
    unsigned char count;
    unsigned char edid_size_code;
    unsigned char i;
    unsigned char j;
    unsigned short old_knee;
    unsigned int word_value;
    unsigned char flags_low;
    unsigned short knee;
    unsigned short status_flags;
    unsigned short *edid_end_ptr;

    /* Phase 1: the requests answered with the CRC reply. */
    send_crc_reply = 0;
    if (request[4] == MAKER_SET_FACTORY_RESET || (request[4] == MAKER_SET_COLOR && request[7] == 0) || request[4] == MAKER_SET_1F || request[4] == MAKER_SET_INPUT_SOURCE || request[4] == MAKER_SET_LANGUAGE
        || (request[4] == MAKER_SET_FACTORY && request[5] == 0xa0 && request[6] == 0) || (request[4] == MAKER_SET_FACTORY && request[5] == 0xa2 && request[6] == 0)
        || (request[4] == MAKER_SET_FACTORY && request[5] == 0xa5 && request[6] == 0))
        send_crc_reply = 1;
    else if (request[4] == MAKER_SET_SAVE_SETTINGS && request[5] == 1 && request[6] == 0)
        send_crc_reply = 1;
    else if (request[4] == MAKER_SET_BRIGHTNESS_KNEE) {
        if (request[5] == 0xe)
            send_crc_reply = 1;
    } else if (request[4] == MAKER_SET_FACTORY && request[5] == 0xa4) {
        if (request[6] == 0x22 || request[6] == 0x23 || request[6] == 0x20 || request[6] == 0x21)
            send_crc_reply = 1;
    }

    /* Phase 2: the sub-code. */
    switch (request[4]) {
    case MAKER_SET_FACTORY_RESET:
        /* When the reset clears a factory marker that was set, two GPIO port 4 pins are switched and the
           second save event is left out. */
        saved = user_settings.factory_marker == FACTORY_MODE_MARKER;
        sys_user_factory_reset();
        ddc_raise_event0();
        if (saved && user_settings.factory_marker != FACTORY_MODE_MARKER) {
            gpio_set_port4_bit7_low_if_allowed();
            gpio_set_port4_bit4_high_if_allowed();
            break;
        }
        ddc_raise_event0();
        break;
    case MAKER_SET_SAVE_SETTINGS:
        /* Arguments 01 00 00 first reset the settings, keeping the factory marker state and the burn-in flag. */
        if (request[5] == 1 && request[6] == 0 && request[7] == 0) {
            marker_was_set = user_settings.factory_marker == FACTORY_MODE_MARKER;
            saved = user_settings.word_0x1d4.bytes[BURN_IN_FLAG];
            sys_user_factory_reset();
            if (marker_was_set == 1)
                user_settings.factory_marker = FACTORY_MODE_MARKER;
            else
                user_settings.factory_marker = FACTORY_MODE_OFF_MARKER;
            user_settings.word_0x1d4.bytes[BURN_IN_FLAG] = saved;
        }
        SYSAPI_WriteEEPROM(EEPROM_AREA, &user_settings, USER_SETTINGS_OFFSET, USER_SETTINGS_SIZE);
        break;
    case MAKER_SET_BRIGHTNESS_KNEE:
        /* Bytes 7..8 = the new knee (high, low), limited to 0x7E..0x3FF and applied. Byte 6 = 1 keeps it and
           saves the settings; any other value puts the old knee back in the record afterwards (without
           applying it again). The result of pq_select_rate_mode is not used. */
        if (request[5] != 0xe)
            break;
        old_knee = user_settings.brightness_knee;
        user_settings.brightness_knee = request[7] << 8 | request[8];
        pq_select_rate_mode((unsigned short)input_api_get_timing_field(0, TIMING_REFRESH_RATE) / 10);
        if (user_settings.brightness_knee > KNEE_MAX)
            user_settings.brightness_knee = KNEE_MAX;
        else if (user_settings.brightness_knee < KNEE_MIN)
            user_settings.brightness_knee = KNEE_MIN;
        sys_user_apply_brightness();
        if (request[6] == 1)
            SYSAPI_WriteEEPROM(EEPROM_AREA, &user_settings, USER_SETTINGS_OFFSET, USER_SETTINGS_SIZE);
        else
            user_settings.brightness_knee = old_knee;
        ddc_build_crc_reply(request, reply);
        break;
    case MAKER_SET_CONTRAST:
        pq_api_enable_color_matrix(0, 0);
        pq_api_set_color_matrix_option(1);
        user_settings.contrast = request[5];
        if (user_settings.contrast > PERCENT_MAX)
            user_settings.contrast = PERCENT_MAX;
        pq_user_apply_color_gain();
        ddc_raise_event0();
        break;
    case MAKER_SET_COLOR:
        if (request[7] == 1) {
            /* Byte 5 -> colour temperature byte: 5 -> 1, 6 -> 4, 8 -> 7, 11 -> 0x17, any other 0. Applied only
               when it changes. */
            color_temperature = 0;
            switch (request[5]) {
            case 5: color_temperature = 1; break;
            case 6: color_temperature = 4; break;
            case 8: color_temperature = 7; break;
            case 11: color_temperature = 0x17; break;
            }
            word_value = color_temperature;
            if (user_settings.color_temperature != word_value) {
                pq_api_enable_color_matrix(0, 0);
                pq_api_set_color_matrix_option(1);
                user_settings.color_temperature = word_value;
                pq_user_apply_color_settings();
            }
        } else if (request[7] == 0) {
            /* Store the three colour entry bytes (the matrix gains of sub-codes 0x16..0x1A) in a part record row
               chosen by byte 5, or, for 11, as the custom gains scaled from 0..255 to 0..100; then store. */
            switch (request[5]) {
            case 1:
                part_record[PART_ENTRY_21] = ddc_color_entry_byte0;
                part_record[PART_ENTRY_21 + 1] = ddc_color_entry_byte1;
                part_record[PART_ENTRY_21 + 2] = ddc_color_entry_byte2;
                nvram_api_store_by_selector(0);
                break;
            case 5:
                part_record[PART_WARM50] = ddc_color_entry_byte0;
                part_record[PART_WARM50 + 1] = ddc_color_entry_byte1;
                part_record[PART_WARM50 + 2] = ddc_color_entry_byte2;
                nvram_api_store_by_selector(0);
                break;
            case 6:
                part_record[PART_NORMAL65] = ddc_color_entry_byte0;
                part_record[PART_NORMAL65 + 1] = ddc_color_entry_byte1;
                part_record[PART_NORMAL65 + 2] = ddc_color_entry_byte2;
                nvram_api_store_by_selector(0);
                break;
            case 8:
                part_record[PART_COOL93] = ddc_color_entry_byte0;
                part_record[PART_COOL93 + 1] = ddc_color_entry_byte1;
                part_record[PART_COOL93 + 2] = ddc_color_entry_byte2;
                nvram_api_store_by_selector(0);
                break;
            case 11:
                user_settings.red_gain = (ddc_color_entry_byte0 * 100 + 0x7f) / 0xffu;
                user_settings.green_gain = (ddc_color_entry_byte1 * 100 + 0x7f) / 0xffu;
                user_settings.blue_gain = (ddc_color_entry_byte2 * 100 + 0x7f) / 0xffu;
                nvram_api_store_by_selector(0);
                break;
            }
        }
        break;
    case MAKER_SET_COLOR_ENTRY_0:
        /* Byte 7 = the gain; the matrix gets gain + 1. Nothing is saved. */
        pq_api_enable_color_matrix(0, 0);
        pq_api_set_color_matrix_option(1);
        ddc_color_entry_byte0 = request[7];
        pq_color_matrix_set_red_gain(ddc_color_entry_byte0 + 1);
        break;
    case MAKER_SET_COLOR_ENTRY_1:
        pq_api_enable_color_matrix(0, 0);
        pq_api_set_color_matrix_option(1);
        ddc_color_entry_byte1 = request[7];
        pq_color_matrix_set_green_gain(ddc_color_entry_byte1 + 1);
        break;
    case MAKER_SET_COLOR_ENTRY_2:
        pq_api_enable_color_matrix(0, 0);
        pq_api_set_color_matrix_option(1);
        ddc_color_entry_byte2 = request[7];
        pq_color_matrix_set_blue_gain(ddc_color_entry_byte2 + 1);
        break;
    case MAKER_SET_1E:
        /* Not on a port of type 5: the (empty) event stub, and event 0xC2 when channel record 0 byte +0x3A is
           set. */
        if (input_get_port_sync_mode(0) != PORT_TYPE_5) {
            sys_poll_events_stub_copy20(0);
            if (channel_records_byte_0x3a != 0)
                ddc_raise_event1();
        }
        break;
    case MAKER_SET_INPUT_SOURCE:
        /* Byte 5 -> Input Source setting: 3 -> 2, 0x11 -> 4, 0x12 -> 6, 0x0F -> 0xB, 0x10 -> 0xD, 1 -> 0; other
           values leave it. Only stored and saved here. */
        if (request[5] == 3)
            user_settings_input_source = 2;
        else if (request[5] == 0x11)
            user_settings_input_source = 4;
        else if (request[5] == 0x12)
            user_settings_input_source = 6;
        else if (request[5] == 0xf)
            user_settings_input_source = 0xb;
        else if (request[5] == 0x10)
            user_settings_input_source = 0xd;
        else if (request[5] == 1)
            user_settings_input_source = 0;
        ddc_raise_event0();
        break;
    case MAKER_SET_RED_BLACK_LEVEL:
        pq_api_enable_color_matrix(0, 0);
        pq_api_set_color_matrix_option(1);
        user_settings_red_black_level = request[7];
        pq_user_apply_red_offset();
        ddc_raise_event0();
        break;
    case MAKER_SET_GREEN_BLACK_LEVEL:
        pq_api_enable_color_matrix(0, 0);
        pq_api_set_color_matrix_option(1);
        user_settings_green_black_level = request[7];
        pq_user_apply_green_offset();
        ddc_raise_event0();
        break;
    case MAKER_SET_BLUE_BLACK_LEVEL:
        pq_api_enable_color_matrix(0, 0);
        pq_api_set_color_matrix_option(1);
        user_settings_blue_black_level = request[7];
        pq_user_apply_blue_offset();
        ddc_raise_event0();
        break;
    case MAKER_SET_LANGUAGE:
        /* Byte 7 -> menu language (settings byte +8, 1 = English); other values leave it. */
        switch (request[7]) {
        case 1: user_settings_language = 0; break;
        case 2: user_settings_language = 1; break;
        case 3: user_settings_language = 2; break;
        case 4: user_settings_language = 3; break;
        case 5: user_settings_language = 4; break;
        case 6: user_settings_language = 7; break;
        case 7: user_settings_language = 6; break;
        case 8: user_settings_language = 9; break;
        case 9: user_settings_language = 8; break;
        case 10: user_settings_language = 5; break;
        case 12: user_settings_language = 0xe; break;
        case 13: user_settings_language = 0xa; break;
        case 15: user_settings_language = 0x13; break;
        case 18: user_settings_language = 0x1a; break;
        case 20: user_settings_language = 0x15; break;
        case 24: user_settings_language = 0x11; break;
        case 25: user_settings_language = 0xd; break;
        case 35: user_settings_language = 0xb; break;
        case 37: user_settings_language = 0x10; break;
        }
        ddc_raise_event0();
        break;
    case MAKER_SET_POWER:
        /* Byte 5 = 5 powers off when channel 0 is not off. Values 1 and 0 only call empty stubs. */
        if (request[5] == 1) {
            if ((unsigned char)sys_get_channel_state(0) != CH_STATE_4)
                sys_poll_events_stub_copy18();
        } else if (request[5] == 0) {
            if ((unsigned char)sys_get_channel_state(0) != CH_STATE_1 && (unsigned char)sys_get_channel_state(1) != CH_STATE_1)
                sys_poll_events_stub_copy19();
        } else if (request[5] == 5) {
            if ((unsigned char)sys_get_channel_state(0) != CH_STATE_OFF)
                SYSAPI_PowerOff();
        }
        ddc_raise_event0();
        break;
    case MAKER_SET_FACTORY:
        /* Factory switches, keyed by bytes 5 and 6; byte 7 is the value. */
        if (request[5] == 0xa0 && request[6] == 0) {
            /* A0 00: factory mode on (1) or off (0). */
            if (request[7] == 1)
                sys_set_factory_mode_flag();
            else if (request[7] == 0)
                sys_clear_factory_mode_flag();
        } else if (request[5] == 0xa1 && request[6] == 0) {
            /* A1 00: in factory mode the routine never returns. */
            if (user_settings.word_0x0 & SETTINGS_WORD0_FACTORY_MODE)
                for (;;)
                    ;
        } else if (request[5] == 0xa2 && request[6] == 0) {
            /* A2 00: the burn-in flag. */
            if (request[7] != 0)
                user_settings.word_0x1d4.bytes[BURN_IN_FLAG] = request[7];
            else
                user_settings.word_0x1d4.bytes[BURN_IN_FLAG] = 0;
            ddc_raise_event3();
            ddc_raise_event0();
        } else if (request[5] == 0xa2 && request[6] == 1) {
            /* A2 01: set ddc_tool_inverted_flag to byte 7 (0 or 1; other values: no reply), switch every port
               signal on, and answer 6E 84 02 flags_high flag*2 flags_low with the OR of the status entry
               flags. */
            status_flags = 0;
            for (i = 0; i < 3; i++)
                status_flags |= ddc_status_entries[i].flags;
            word_value = status_flags;
            flags_low = word_value;
            if (request[7] == 1)
                ddc_tool_inverted_flag = 1;
            else if (request[7] == 0) {
                input_api_set_port_signal(ALL_PORTS, PORT_SIGNAL_ON);
                ddc_tool_inverted_flag = 0;
            } else
                break;
            input_api_set_port_signal(ALL_PORTS, PORT_SIGNAL_ON);
            reply[0] = DDC_ADDRESS;
            reply[1] = DDC_LENGTH_BYTE(4);
            reply[2] = 2;
            reply[3] = word_value >> 8;
            reply[4] = ddc_tool_inverted_flag * 2;
            reply[5] = flags_low;
            ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
        } else if (request[5] == 0xa3 && request[6] == 0 && request[7] == 0) {
            /* A3 00 00: clear device settings 8, 9 and the on-time (6, 7). */
            nvram_set_device_setting(DEVICE_SETTING_8, 0);
            nvram_set_device_setting(DEVICE_SETTING_9, 0);
            nvram_set_device_setting(DEVICE_SETTING_ON_TIME_MINUTES, 0);
            nvram_set_device_setting(DEVICE_SETTING_ON_TIME_HOURS, 0);
            ddc_raise_event3();
        } else if (request[5] == 0xa5 && request[6] == 0) {
            /* A5 00: factory marker set (1, also audio level 100) or cleared. */
            if (request[7] == 1) {
                user_settings.factory_marker = FACTORY_MODE_MARKER;
                user_settings.audio_level = 100;
            } else
                user_settings.factory_marker = FACTORY_MODE_OFF_MARKER;
            ddc_raise_event3();
            ddc_raise_event0();
        } else if (request[5] == 0xed && request[6] == 5) {
            break;
        } else if (request[5] == 0xa7 && request[6] == 6) {
            /* A7 06: settings word 0 bit 12. */
            if (request[7] == 1)
                user_settings.word_0x0 |= SETTINGS_WORD0_BIT12;
            else
                user_settings.word_0x0 &= ~SETTINGS_WORD0_BIT12;
            ddc_raise_event3();
            ddc_raise_event0();
        } else if (request[5] == 0xa7 && request[6] == 3) {
            /* A7 03: automatic level off (0) or on (1); applied at once in channel state 0xC. */
            if (request[7] == 0)
                user_settings.professional_flags &= ~PROFESSIONAL_AUTO_LEVEL;
            else if (request[7] == 1)
                user_settings.professional_flags |= PROFESSIONAL_AUTO_LEVEL;
            if ((unsigned char)sys_get_channel_state(0) == MODE_WAITMODECHANGE)
                sys_user_apply_auto_level();
            ddc_raise_event3();
            ddc_raise_event0();
        } else if (request[5] == 0xa7 && request[6] == 0x13) {
            /* A7 13: CEC PWM Adjust. On: brightness = cec_pwm_brightness, reply 6E 87 02 03 6F 03 FF 96 FF.
               Off: knee 0x36F and brightness 70, no reply. Both apply the brightness, save the mode slot and
               write the settings to the EEPROM. */
            if (request[7] == 1) {
                user_settings.word_0x1d4.word |= SETTINGS_CEC_PWM_ADJUST;
                user_settings.brightness = user_settings.cec_pwm_brightness;
                sys_user_apply_brightness();
                sys_user_save_mode_slot();
                SYSAPI_WriteEEPROM(EEPROM_AREA, &user_settings, USER_SETTINGS_OFFSET, USER_SETTINGS_SIZE);
                knee = CEC_PWM_OFF_KNEE;
                reply[0] = DDC_ADDRESS;
                reply[1] = DDC_LENGTH_BYTE(7);
                reply[2] = 2;
                reply[3] = knee >> 8;
                reply[4] = knee;
                reply[5] = 3;
                reply[6] = 0xff;
                reply[7] = 0x96;
                reply[8] = 0xff;
                ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
            } else {
                user_settings.word_0x1d4.word &= ~SETTINGS_CEC_PWM_ADJUST;
                knee = CEC_PWM_OFF_KNEE;
                user_settings.brightness_knee = knee;
                user_settings.brightness = CEC_PWM_OFF_BRIGHTNESS;
                sys_user_apply_brightness();
                sys_user_save_mode_slot();
                SYSAPI_WriteEEPROM(EEPROM_AREA, &user_settings, USER_SETTINGS_OFFSET, USER_SETTINGS_SIZE);
            }
        }
        break;
    case MAKER_SET_PART_BYTE:
        /* Byte 5 = 1..6: part record byte 0..5 = byte 7 of the reply buffer, which nothing has written at this
           point; then event 0xC3. */
        if (request[5] == 1) {
            part_record[0] = reply[7];
            ddc_raise_event2();
        } else if (request[5] == 2) {
            part_record[1] = reply[7];
            ddc_raise_event2();
        } else if (request[5] == 3) {
            part_record[2] = reply[7];
            ddc_raise_event2();
        } else if (request[5] == 4) {
            part_record[3] = reply[7];
            ddc_raise_event2();
        } else if (request[5] == 5) {
            part_record[4] = reply[7];
            ddc_raise_event2();
        } else if (request[5] == 6) {
            part_record[5] = reply[7];
            ddc_raise_event2();
        }
        break;
    case MAKER_SET_FILL_COLOR:
        /* Fill colour of port 0 from bytes 5..7, then picture block 0 is blanked. */
        pq_api_set_fill_color(0, request[5], request[6], request[7], 0);
        pq_block_blank(0);
        break;
    case MAKER_SET_FACTORY_DATA:
        DAT_a802b0a4_retry_max = 2;
        DAT_a802b0a3_retry_cnt = 2;
        DAT_a802d250_xfer.command = request[5];
        if (DAT_a802d250_xfer.command == FACTORY_DATA_SERIAL) {
            /* Serial number: request[1] + 0x7A is the length in byte 1 minus 6, which is the number of data
               bytes from byte 8 on. They go into the factory record, which is written to the EEPROM. Reply
               6E 88 offset_high offset_low length. */
            offset_low = request[7];
            offset_high = request[6];
            factory_record.serial_length = request[1] + 0x7a;
            DAT_a802d250_xfer.sum = 0;
            reply[0] = DDC_ADDRESS;
            reply[1] = DDC_LENGTH_BYTE(8);
            reply[2] = offset_high;
            reply[3] = offset_low;
            reply[4] = factory_record.serial_length;
            ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
            for (j = 0; j < factory_record.serial_length; j++)
                factory_record.serial[j] = request[8 + j];
            SYSAPI_WriteEEPROM(EEPROM_AREA, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
            break;
        }

        /* EDID: 32 data bytes for offset (byte 6) * 256 + (byte 7). The sum of the data bytes restarts at
           offset_low 0. Reply 6E 88 offset_high offset_low 20. */
        offset_high = request[6];
        offset_low = request[7];
        if (offset_low == 0)
            DAT_a802d250_xfer.sum = 0;
        count = EDID_PIECE;
        for (i = 0; i < count; i++)
            DAT_a802d250_xfer.sum += request[8 + i];
        reply[0] = DDC_ADDRESS;
        reply[1] = DDC_LENGTH_BYTE(8);
        reply[2] = offset_high;
        reply[3] = offset_low;
        reply[4] = EDID_PIECE;
        ddc_set_checksum_byte(DDC_CHECKSUM_SEED);

        /* The EDID length: 0x80 for pieces below offset_low 0x60; the piece at 0x60 sets it from its byte that
           lands at offset 0x7E (request byte 0x26): 0 -> 0x80, 1 -> 0x100, 2 -> 0x180, more -> 0x200. Pieces
           above 0x60 leave it. */
        edid_size_code = request[0x26];
        edid_end_ptr = &DAT_a802d250_xfer.edid_end;
        if (offset_low < 0x60)
            *edid_end_ptr = 0x80;
        else if (offset_low == 0x60) {
            if (edid_size_code == 0)
                *edid_end_ptr = 0x80;
            else if (edid_size_code == 1)
                *edid_end_ptr = 0x100;
            else if (edid_size_code == 2)
                *edid_end_ptr = 0x180;
            else
                *edid_end_ptr = 0x200;
        }

        /* Copy the piece into ddc_tool_edid_buffer; the piece that reaches the EDID length writes 0x100 bytes
           of the buffer to the port EDID of source 0xFF. */
        if (DAT_a802d250_xfer.command == FACTORY_DATA_EDID) {
            if ((unsigned short)(offset_high * 0x100 + offset_low + 0x20) >= DAT_a802d250_xfer.edid_end) {
                for (i = 0; i < 0x20; i++)
                    ddc_tool_edid_buffer[offset_high * 0x100 + offset_low + i] = request[8 + i];
                edid_api_write_port_edid(EDID_SOURCE_FF, 1, (unsigned int)ddc_tool_edid_buffer, 0x100, 1);
            } else {
                for (i = 0; i < 0x20; i++)
                    ddc_tool_edid_buffer[offset_high * 0x100 + offset_low + i] = request[8 + i];
            }
        }
        if (DAT_a802d250_xfer.command == FACTORY_DATA_EDID_ALT) {
            if ((unsigned short)(offset_high * 0x100 + offset_low + 0x20) >= DAT_a802d250_xfer.edid_end) {
                for (i = 0; i < 0x20; i++)
                    ddc_tool_edid_buffer[offset_high * 0x100 + offset_low + i] = request[8 + i];
                edid_api_write_port_edid(EDID_SOURCE_FF, 1, (unsigned int)ddc_tool_edid_buffer, 0x100, 1);
            } else {
                for (i = 0; i < 0x20; i++)
                    ddc_tool_edid_buffer[offset_high * 0x100 + offset_low + i] = request[8 + i];
            }
        }

        /* Last piece (tested with offset_low alone): a zero sum counts the retry byte down (reloaded from
           retry_max at 0), nothing else reads it; a non-zero sum replaces the reply with
           6E 83 offset_high offset_low (length - 6). */
        if (offset_low + 0x20 < DAT_a802d250_xfer.edid_end)
            break;
        if (DAT_a802d250_xfer.sum == 0) {
            if (--DAT_a802b0a3_retry_cnt == 0)
                DAT_a802b0a3_retry_cnt = DAT_a802b0a4_retry_max;
            break;
        }
        reply[0] = DDC_ADDRESS;
        reply[1] = DDC_LENGTH_BYTE(3);
        reply[2] = request[6];
        reply[3] = request[7];
        reply[4] = request[1] + 0x7a;
        ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
        break;
    }

    /* Phase 3. */
    if (send_crc_reply)
        ddc_build_crc_reply(request, reply);
}
