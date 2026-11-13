/* ddc_answer_maker_vcp_get  (FUN_a00cf2d4)
 *
 * Fill the reply to a DDC/CI 'Get VCP Feature' request for the maker code 0xFE (sub-code in byte 4).
 *   request
 *   reply: reply buffer
 * Note: Sub-codes 0x10 brightness, 0x12 contrast, 0x16/0x18/0x1A the stored colour entry bytes, 0x60 input,
 *   0x6C..0x70 black levels, 0xCC language, 0xE1/0xE9 texts, 0xE2 part record byte, 0xEF serial number or
 *   EDID.
 * Name basis: derived - called only from the 0xFE case of the GetVCP switch of ddc_handle_request; switches on
 *   request byte 4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00cf2d4 @ 0xa00cf2d4-0xa00cfa14 (464 words), flags -mcpu=v8 -O3 -g. Language switch: jump table
 * 0xa00ceb24 (20 entries).
 * Source forms the exact build depends on:
 *  - the case blocks in the order 0x10, 0x12, 0x16, 0x18, 0x1a, 0x6c, 0x6e, 0x70, 0x60, 0xcc, 0xe2, 0xe1, 0xe9,
 *    0xef (this order gives the register choices);
 *  - the 6, 14 and 18 byte copy loops compare with a limit held in the variable count (cmp count; bcs), the
 *    32 byte loops with the constant (cmp 0x1f; bleu).
 */

/* The factory record (docs/RECORDS.md), 0x1C bytes; it starts with the serial number. */
struct factory_record_serial {
    unsigned char byte_0x0, byte_0x1;
    unsigned char serial_length;                /* +0x02: number of serial characters */
    unsigned char serial[0x19];                 /* +0x03: the characters, then the rest of the record */
};
extern struct factory_record_serial factory_record;
extern unsigned char ddc_tool_edid_buffer[];
extern unsigned char user_settings_language, user_settings_brightness, user_settings_contrast, user_settings_red_black_level, user_settings_green_black_level, user_settings_blue_black_level, user_settings_input_source;
extern unsigned char ddc_color_entry_byte2, ddc_color_entry_byte1, ddc_color_entry_byte0;
extern unsigned char part_record, part_record_byte_0x1, part_record_byte_0x2, part_record_byte_0x3, part_record_byte_0x4, part_record_byte_0x5;
/* Three texts in read-only data, each a length byte followed by the characters: 0x198328 "MSI MPG 321URX"
   (14), 0x198338 "FW.021" (6), 0x198340 an 18-character text. */
extern const unsigned char ddc_model_name_text[], ddc_firmware_version_text[], ddc_key_a7_text[];
extern void ddc_build_vcp_reply(unsigned char *, unsigned char, unsigned char, unsigned char, unsigned char);
extern void ddc_set_checksum_byte(unsigned char);
extern int SYSAPI_ReadEEPROM(int, void *, int, int);
extern void edid_api_read_port_edid(int, void *, unsigned short *);

/* Reply byte 0 (docs/MAP.md: the DDC/CI address) and the first value of the reply XOR checksum. */
#define DDC_ADDRESS               0x6e
#define DDC_CHECKSUM_SEED         0x50
/* Reply byte 1: 0x80 + the number of bytes that follow it (before the checksum). */
#define DDC_LENGTH_BYTE(n)        ((n) + 0x80)

#define VCP_MAKER                 0xfe          /* the GetVCP code whose sub-codes this routine answers */

/* Sub-codes of GetVCP 0xFE (request byte 4). */
enum maker_get_code {
    MAKER_GET_BRIGHTNESS        = 0x10,         /* settings byte +9 */
    MAKER_GET_CONTRAST          = 0x12,         /* settings byte +0xA */
    MAKER_GET_COLOR_ENTRY_0     = 0x16,         /* ddc_color_entry_byte0: the matrix red gain set by SetVCP 0xFE/0x16 */
    MAKER_GET_COLOR_ENTRY_1     = 0x18,         /* ddc_color_entry_byte1: green, set by 0xFE/0x18 */
    MAKER_GET_COLOR_ENTRY_2     = 0x1a,         /* ddc_color_entry_byte2: blue, set by 0xFE/0x1A */
    MAKER_GET_INPUT_SOURCE      = 0x60,         /* settings byte +0x1E, translated */
    MAKER_GET_RED_BLACK_LEVEL   = 0x6c,
    MAKER_GET_GREEN_BLACK_LEVEL = 0x6e,
    MAKER_GET_BLUE_BLACK_LEVEL  = 0x70,
    MAKER_GET_LANGUAGE          = 0xcc,         /* settings byte +8, translated */
    MAKER_GET_TEXT              = 0xe1,         /* fixed bytes or one of the texts, chosen by request bytes 5..7 */
    MAKER_GET_PART_BYTE         = 0xe2,         /* part record byte (request byte 5) - 1 */
    MAKER_GET_MODEL_NAME        = 0xe9,         /* the text "MSI MPG 321URX" */
    MAKER_GET_FACTORY_DATA      = 0xef          /* the serial number, or 32 bytes of EDID */
};

/* Request byte 5 of sub-code 0xEF. */
#define FACTORY_DATA_SERIAL       0x13
#define FACTORY_DATA_EDID         0x42
#define FACTORY_DATA_EDID_ALT     0x43          /* answered exactly as 0x42 */

#define EEPROM_AREA               0x30          /* first argument of SYSAPI_ReadEEPROM */
#define FACTORY_RECORD_OFFSET     0x2e0         /* docs/DATA.md: where the factory record is saved */
#define FACTORY_RECORD_SIZE       0x1c
#define EDID_SOURCE_FF            0xff          /* source passed to edid_api_read_port_edid */
#define EDID_PIECE                0x20          /* EDID bytes in one reply */

/*
 * Fill the reply to a GetVCP request for the maker code 0xFE.
 *
 *   request  the request; byte 3 = 0xFE, byte 4 = the sub-code, bytes 5..7 its arguments
 *   reply    the reply buffer (40 bytes)
 *
 * Called only from ddc_handle_request (its GetVCP answer), and only when the request has more than two bytes
 * after the length byte. The caller has already cleared the reply and written 6E 88 02 00 FE 00 into bytes 0..5;
 * after this routine it adds the checksum and queues the reply: 10 bytes, 0x1E bytes for sub-codes 0xE1 and
 * 0xE9, 0x22 bytes for 0xEF. An unknown sub-code leaves the reply as the caller wrote it.
 *
 * Phases, one per sub-code group:
 *   1. Single values (0x10, 0x12, 0x16..0x1A, 0x6C..0x70): ddc_build_vcp_reply writes 6E 88 02 00 FE 01 and the
 *      four value bytes 6..9. Brightness and contrast go to byte 7 with the other three 0; the colour entry
 *      bytes and black levels go to byte 9 with bytes 6..8 = FF 00 00.
 *   2. Input source (0x60) and language (0xCC): the setting is translated to another number first.
 *   3. Part record bytes (0xE2): request byte 5 = 1..6 picks part record byte 0..5.
 *   4. Texts (0xE1, 0xE9): fixed bytes, or one of the three texts in read-only data copied to bytes 5 on.
 *   5. Factory data (0xEF): the serial number from the factory record, read again from the EEPROM, or 32 bytes
 *      of the EDID at the offset in request bytes 6..7.
 * Where the reply is filled here, ddc_set_checksum_byte resets the reply checksum byte to 0x50, as
 * ddc_build_vcp_reply does.
 */
void ddc_answer_maker_vcp_get(unsigned char *request, unsigned char *reply)
{
    unsigned char i, offset_high, offset_low, source_code, count;
    unsigned short edid_length;

    switch (request[4]) {

    /* Phase 1: single values. */
    case MAKER_GET_BRIGHTNESS:
        ddc_build_vcp_reply(reply, 0, user_settings_brightness, 0, 0);
        break;
    case MAKER_GET_CONTRAST:
        ddc_build_vcp_reply(reply, 0, user_settings_contrast, 0, 0);
        break;
    case MAKER_GET_COLOR_ENTRY_0:
        /* Request byte 5 = 2 gets the fixed answer 00 FF 00 00 instead of the colour entry byte. */
        if (request[5] == 2)
            ddc_build_vcp_reply(reply, 0, 0xff, 0, 0);
        else
            ddc_build_vcp_reply(reply, 0xff, 0, 0, ddc_color_entry_byte0);
        break;
    case MAKER_GET_COLOR_ENTRY_1:
        ddc_build_vcp_reply(reply, 0xff, 0, 0, ddc_color_entry_byte1);
        break;
    case MAKER_GET_COLOR_ENTRY_2:
        ddc_build_vcp_reply(reply, 0xff, 0, 0, ddc_color_entry_byte2);
        break;
    case MAKER_GET_RED_BLACK_LEVEL:
        ddc_build_vcp_reply(reply, 0xff, 0, 0, user_settings_red_black_level);
        break;
    case MAKER_GET_GREEN_BLACK_LEVEL:
        ddc_build_vcp_reply(reply, 0xff, 0, 0, user_settings_green_black_level);
        break;
    case MAKER_GET_BLUE_BLACK_LEVEL:
        ddc_build_vcp_reply(reply, 0xff, 0, 0, user_settings_blue_black_level);
        break;

    /* Phase 2: translated settings. */
    case MAKER_GET_INPUT_SOURCE:
        /* Input Source setting -> answer value: 4 and 7 give 0x11, 6 gives 0x12, 0xB and 0xC give 0x0F, 0xD gives
           0x10, 2 gives 3, every other source 1. The answer goes to byte 9, with 03 01 00 in bytes 6..8. */
        if (user_settings_input_source == 4)
            source_code = 0x11;
        else if (user_settings_input_source == 6)
            source_code = 0x12;
        else if (user_settings_input_source == 7)
            source_code = 0x11;
        else if (user_settings_input_source == 0xb)
            source_code = 0xf;
        else if (user_settings_input_source == 0xc)
            source_code = 0xf;
        else if (user_settings_input_source == 0xd)
            source_code = 0x10;
        else if (user_settings_input_source == 2)
            source_code = 3;
        else
            source_code = 1;
        ddc_build_vcp_reply(reply, 3, 1, 0, source_code);
        break;
    case MAKER_GET_LANGUAGE:
        reply[0] = DDC_ADDRESS;
        reply[1] = DDC_LENGTH_BYTE(8);
        reply[2] = 2;
        reply[3] = 0;
        reply[4] = VCP_MAKER;
        reply[5] = 1;
        reply[6] = 0;
        reply[7] = 0xff;
        reply[8] = 0;
        /* Menu language (settings byte +8, 1 = English) -> the number in byte 7. Languages 12, 15 and 18 and
           every language above 19 give 2, as language 1 does. */
        switch (user_settings_language) {
        case 0: reply[7] = 1; break;
        case 1: reply[7] = 2; break;
        case 2: reply[7] = 3; break;
        case 3: reply[7] = 4; break;
        case 4: reply[7] = 5; break;
        case 5: reply[7] = 0xa; break;
        case 6: reply[7] = 7; break;
        case 7: reply[7] = 6; break;
        case 8: reply[7] = 9; break;
        case 9: reply[7] = 8; break;
        case 10: reply[7] = 0xd; break;
        case 11: reply[7] = 0x23; break;
        case 13: reply[7] = 0x19; break;
        case 14: reply[7] = 0xc; break;
        case 16: reply[7] = 0x25; break;
        case 17: reply[7] = 0x18; break;
        case 19: reply[7] = 0xf; break;
        default: reply[7] = 2; break;
        }
        ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
        break;

    /* Phase 3: the first six bytes of the part record. Any other request byte 5 leaves the reply unchanged. */
    case MAKER_GET_PART_BYTE:
        if (request[5] == 1)
            ddc_build_vcp_reply(reply, 0, part_record, 0, 0);
        else if (request[5] == 2)
            ddc_build_vcp_reply(reply, 0, part_record_byte_0x1, 0, 0);
        else if (request[5] == 3)
            ddc_build_vcp_reply(reply, 0, part_record_byte_0x2, 0, 0);
        else if (request[5] == 4)
            ddc_build_vcp_reply(reply, 0, part_record_byte_0x3, 0, 0);
        else if (request[5] == 5)
            ddc_build_vcp_reply(reply, 0, part_record_byte_0x4, 0, 0);
        else if (request[5] == 6)
            ddc_build_vcp_reply(reply, 0, part_record_byte_0x5, 0, 0);
        break;

    /* Phase 4: fixed bytes and texts. Request bytes 5..7 must match one of three keys exactly. */
    case MAKER_GET_TEXT:
        if (request[5] == 0xa5 && request[6] == 3 && request[7] == 0) {
            /* Key A5 03 00: the fixed bytes FE 02 B0 in bytes 4..6. */
            reply[0] = DDC_ADDRESS;
            reply[1] = DDC_LENGTH_BYTE(8);
            reply[2] = 2;
            reply[3] = 0;
            reply[4] = VCP_MAKER;
            reply[5] = 2;
            reply[6] = 0xb0;
            ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
        } else if (request[5] == 0xa7 && request[6] == 7 && request[7] == 0) {
            /* Key A7 07 00: the 18-character text at 0x198340 into bytes 5..22. */
            reply[0] = DDC_ADDRESS;
            reply[1] = DDC_LENGTH_BYTE(21);
            ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
            count = 0x12;
            for (i = 0; i < count; i++)
                reply[i + 5] = ddc_key_a7_text[i + 1];
        } else if (request[5] == 0xe6 && request[6] == 6 && request[7] == 0) {
            /* Key E6 06 00: "FW.021" into bytes 5..10. */
            reply[0] = DDC_ADDRESS;
            reply[1] = DDC_LENGTH_BYTE(9);
            ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
            count = 6;
            for (i = 0; i < count; i++)
                reply[i + 5] = ddc_firmware_version_text[i + 1];
        }
        break;
    case MAKER_GET_MODEL_NAME:
        /* Only with request bytes 6 and 7 zero: "MSI MPG 321URX" into bytes 5..18. */
        if (request[6] == 0 && request[7] == 0) {
            reply[0] = DDC_ADDRESS;
            reply[1] = DDC_LENGTH_BYTE(17);
            ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
            count = 0xe;
            for (i = 0; i < count; i++)
                reply[i + 5] = ddc_model_name_text[i + 1];
        }
        break;

    /* Phase 5: factory data. */
    case MAKER_GET_FACTORY_DATA:
        edid_length = 0x100;
        if (request[5] == FACTORY_DATA_SERIAL) {
            /* The serial number from byte 2 on. The length byte is formed from the serial length in RAM; the
               record is then read again from the EEPROM and the characters are copied with the length just
               read. */
            reply[0] = DDC_ADDRESS;
            reply[1] = factory_record.serial_length + 0x80;
            ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
            SYSAPI_ReadEEPROM(EEPROM_AREA, &factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
            for (i = 0; i < factory_record.serial_length; i++)
                reply[i + 2] = factory_record.serial[i];
        } else {
            /* 32 EDID bytes from ddc_tool_edid_buffer at offset (request byte 6) * 256 + (request byte 7) into
               bytes 2..33. Offset 0 first reads the whole EDID of source 0xFF into the buffer. Byte 1 stays
               0x88. Any other request byte 5 sends just the head. */
            offset_high = request[6];
            offset_low = request[7];
            reply[0] = DDC_ADDRESS;
            reply[1] = DDC_LENGTH_BYTE(8);
            if (request[5] == FACTORY_DATA_EDID) {
                if (offset_high == 0 && offset_low == 0)
                    edid_api_read_port_edid(EDID_SOURCE_FF, ddc_tool_edid_buffer, &edid_length);
                for (i = 0; i < EDID_PIECE; i++)
                    reply[i + 2] = ddc_tool_edid_buffer[offset_high * 0x100 + offset_low + i];
            }
            if (request[5] == FACTORY_DATA_EDID_ALT) {
                if (offset_high == 0 && offset_low == 0)
                    edid_api_read_port_edid(EDID_SOURCE_FF, ddc_tool_edid_buffer, &edid_length);
                for (i = 0; i < EDID_PIECE; i++)
                    reply[i + 2] = ddc_tool_edid_buffer[offset_high * 0x100 + offset_low + i];
            }
            ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
        }
        break;
    }
}
