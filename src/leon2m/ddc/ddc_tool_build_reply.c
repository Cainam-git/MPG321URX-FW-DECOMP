/* ddc_tool_build_reply  (FUN_a00d1220)
 *
 * Fill the rest of a factory tool reply for a result code or an answer kind and store its checksum.
 *   request
 *   reply
 *   cmd: result code or answer kind chosen by the caller, not the request's command byte
 * Note: cmd is a result code (0xE0..0xE3, 0..2, 0x88) or an answer kind picked by the caller (0x92, 0x99,
 *   ...); answer kinds 0x6E, 0x6F, 0x98, 0xC2 and 0xD0 store no checksum.
 * Name basis: derived - callers ddc_tool_dispatch_command (result of its switch) and
 *   ddc_tool_answer_read_request (0x99 or a result code)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d1220 @ 0xa00d1220, flags -mcpu=v8 -O3 -g. Language switch: jump table 0x6ec3c.
 * Source forms the exact build depends on:
 *  - the checksum helper and the bodies of the five neighbouring routines (ddc_tool_calc_checksum,
 *    ddc_tool_fill_reply_0x97, ddc_tool_reply_color_temp_gains, ddc_tool_reply_key_test,
 *    ddc_tool_reply_factory_record, ddc_tool_reply_factory_status) are static helpers here, inlined;
 *  - the top byte of the on-time word is read through a byte member of a union with the word (a byte load, not a
 *    second extraction from the same word load);
 *  - the language cases are listed from 28 down to 0; case TOOL_RESULT_E2 is listed explicitly;
 *  - the TOOL_ANSWER_KEY_CHECK_1 / _2 stores are if/else, not ?:;
 *  - reply[6] is assigned before reply[7] in the TOOL_ANSWER_ON_TIME and TOOL_ANSWER_OLED_ERROR_REG arms.
 */

/* The parts of the three records that this file reads through the record (docs/RECORDS.md). */
struct user_settings_record {
    unsigned int word_0x0;                      /* +0x00: bit 14 = factory mode */
    unsigned char pad004[0x1a];
    unsigned char input_source;                 /* +0x1E: the Input Source menu index */
};
struct factory_record_bytes {
    unsigned char bytes[0x16];                  /* +0x03.. serial number, +0x10 key test bits */
    unsigned short oled_error_reg10;            /* +0x16 */
};
struct device_settings_head {
    unsigned int word_0x0, word_0x4;
    union {
        unsigned int word;                      /* +0x08: bits 8-23 hours, top byte minutes */
        unsigned char bytes[4];                 /* bytes[0] = the minutes */
    } on_time;
};
extern struct user_settings_record user_settings;
extern struct factory_record_bytes factory_record;
extern struct device_settings_head device_settings;
extern unsigned char user_settings_color_temperature;
extern unsigned char part_record[];
extern unsigned char user_settings_language;
extern unsigned char user_settings_burn_in_flag, user_settings_fast_uph;
extern unsigned char ipc_check_hdcp_stored_keys(unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);

#define DDC_CHECKSUM_SEED         0x50          /* first value of the reply XOR checksum */
/* Reply byte 1: 0x80 + the number of bytes that follow it (before the checksum). */
#define DDC_LENGTH_BYTE(n)        ((n) + 0x80)
#define DDC_LENGTH_MASK           0x7f

#define SETTINGS_WORD0_FACTORY_MODE_BIT 14
#define FACTORY_SERIAL            3             /* factory record +3: the serial characters */
#define FACTORY_KEY_TEST_BITS     0x10          /* factory record +0x10: one bit per front key passed */
#define SERIAL_ANSWER_LENGTH      13

/* Colour temperature values (settings +0x11) and the part record rows of their colour bytes. */
#define COLOR_TEMP_COOL           0
#define COLOR_TEMP_NORMAL         1
#define COLOR_TEMP_WARM           2
#define PART_WARM50               6
#define PART_NORMAL65             9
#define PART_COOL93               0x12

/* Result codes: byte 7 of most replies. The tool commands return TOOL_RESULT_DONE when carried out;
   ddc_tool_dispatch_command uses TOOL_RESULT_UNKNOWN for a command it does not know. */
#define TOOL_RESULT_DONE          0xe0
#define TOOL_RESULT_E1            0xe1          /* here: key check not 1, or input not in the table */
#define TOOL_RESULT_E2            0xe2          /* the answer to every cmd value not listed here */
#define TOOL_RESULT_UNKNOWN       0xe3
#define TOOL_RESULT_BAD_VALUE     0xe4          /* here: a request or setting value without an answer */

/* cmd values that ask for an answer. ddc_tool_dispatch_command passes them for its 's' requests (request
   byte 3 = 's', byte 5 = what is asked); ddc_tool_answer_read_request passes TOOL_ANSWER_TABLE_READ. */
enum tool_answer {
    TOOL_ANSWER_FACTORY_MODE   = 0x02,          /* 's' 0x02 */
    TOOL_ANSWER_BURN_IN        = 0x08,          /* 's' 0x08 */
    TOOL_ANSWER_INPUT          = 0x0a,          /* 's' 0x0A */
    TOOL_ANSWER_1F             = 0x1f,          /* 's' 0x1F */
    TOOL_ANSWER_KEY_TEST       = 0x69,          /* 's' 0x69 */
    TOOL_ANSWER_LANGUAGE       = 0x6a,          /* 's' 0x6A */
    TOOL_ANSWER_SERIAL         = 0x6b,          /* 's' 0x6B */
    TOOL_ANSWER_KEY_CHECK_1    = 0x6e,          /* 's' 0x6E */
    TOOL_ANSWER_KEY_CHECK_2    = 0x6f,          /* 's' 0x6F */
    TOOL_ANSWER_COLOR_GAINS    = 0x92,          /* 's' 0x11 */
    TOOL_ANSWER_ZERO_BYTES     = 0x93,          /* 's' 0x1C */
    TOOL_ANSWER_96             = 0x96,          /* asked for by no 's' request */
    TOOL_ANSWER_97             = 0x97,          /* 's' 0x1D */
    TOOL_ANSWER_98             = 0x98,          /* asked for by no 's' request */
    TOOL_ANSWER_TABLE_READ     = 0x99,          /* ddc_tool_answer_read_request */
    TOOL_ANSWER_FACTORY_STATUS = 0xaa,          /* 's' 0xAA */
    TOOL_ANSWER_OLED_ERROR_REG = 0xc2,          /* 's' 0xC2 */
    TOOL_ANSWER_ON_TIME        = 0xd0           /* 's' 0xD0 */
};

/* XOR checksum (inlined copy of ddc_tool_calc_checksum): seed XOR reply bytes 0 .. (byte 1 & 0x7F) + 1.
   Every caller stores it right behind those bytes. */
static unsigned char tool_checksum(const unsigned char *reply, unsigned char x)
{
    unsigned int n = (reply[1] & DDC_LENGTH_MASK) + 2;
    unsigned char i;

    for (i = 0; i < n; i++)
        x ^= reply[i];
    return x;
}

/* TOOL_ANSWER_97 (copy of ddc_tool_fill_reply_0x97): the fixed bytes 00 02 01. */
static void answer_97(unsigned char *reply)
{
    reply[1] = DDC_LENGTH_BYTE(8);
    reply[8] = 2;
    reply[9] = 1;
    reply[7] = 0;
    reply[10] = tool_checksum(reply, DDC_CHECKSUM_SEED);
}

/* TOOL_ANSWER_COLOR_GAINS (copy of ddc_tool_reply_color_temp_gains): the three part record colour bytes of the
   current colour temperature (Warm, Normal or Cool); other colour temperatures leave bytes 8..10 as they are. */
static void answer_color_gains(unsigned char *reply)
{
    reply[1] = DDC_LENGTH_BYTE(9);
    reply[7] = TOOL_RESULT_DONE;
    if (user_settings_color_temperature == COLOR_TEMP_WARM) {
        reply[8] = part_record[PART_WARM50];
        reply[9] = part_record[PART_WARM50 + 1];
        reply[10] = part_record[PART_WARM50 + 2];
    }
    else if (user_settings_color_temperature == COLOR_TEMP_NORMAL) {
        reply[8] = part_record[PART_NORMAL65];
        reply[9] = part_record[PART_NORMAL65 + 1];
        reply[10] = part_record[PART_NORMAL65 + 2];
    }
    else if (user_settings_color_temperature == COLOR_TEMP_COOL) {
        reply[8] = part_record[PART_COOL93];
        reply[9] = part_record[PART_COOL93 + 1];
        reply[10] = part_record[PART_COOL93 + 2];
    }
    reply[11] = tool_checksum(reply, DDC_CHECKSUM_SEED);
}

/* TOOL_ANSWER_KEY_TEST (copy of ddc_tool_reply_key_test): key test bit 0 in byte 6, bits 1..5 in byte 7. */
static void answer_key_test(unsigned char *reply)
{
    reply[6] = factory_record.bytes[FACTORY_KEY_TEST_BITS] & 1;
    reply[7] = factory_record.bytes[FACTORY_KEY_TEST_BITS] & 0x3e;
    reply[8] = tool_checksum(reply, DDC_CHECKSUM_SEED);
}

/* TOOL_ANSWER_SERIAL (copy of ddc_tool_reply_factory_record): 13 bytes of the factory record from +3. */
static void answer_serial(unsigned char *reply)
{
    int i;

    reply[1] = DDC_LENGTH_BYTE(19);
    reply[7] = TOOL_RESULT_DONE;
    for (i = 0; i < SERIAL_ANSWER_LENGTH; i++)
        reply[8 + i] = factory_record.bytes[FACTORY_SERIAL + i];
    reply[0x15] = tool_checksum(reply, DDC_CHECKSUM_SEED);
}

/* TOOL_ANSWER_FACTORY_STATUS (copy of ddc_tool_reply_factory_status): request byte 7 picks the value. */
static void answer_factory_status(const unsigned char *request, unsigned char *reply)
{
    if (request[7] == 0)
        reply[7] = (user_settings.word_0x0 >> SETTINGS_WORD0_FACTORY_MODE_BIT) & 1;
    else if (request[7] == 1)
        reply[7] = user_settings_burn_in_flag;
    else if (request[7] == 2)
        reply[7] = user_settings_fast_uph;
    else
        reply[7] = TOOL_RESULT_BAD_VALUE;
    reply[8] = tool_checksum(reply, DDC_CHECKSUM_SEED);
}

/*
 * Fill the rest of a factory tool reply and store its XOR checksum.
 *
 *   request  the tool request (bytes 3..6 are already copied into the reply)
 *   reply    the reply; the caller has cleared it and written bytes 0..6
 *   cmd      a result code (TOOL_RESULT_*, 0..2 or 0x88) or the kind of answer wanted (enum tool_answer)
 *
 * Called by ddc_tool_dispatch_command and ddc_tool_answer_read_request; both then reset the reply checksum
 * byte to 0x50 and queue the reply.
 *
 * Phases:
 *   1. An answer kind: fill the bytes from reply[6] or reply[7] on, set byte 1 where the length changes, and
 *      store the checksum behind the counted bytes. TOOL_ANSWER_KEY_CHECK_*, _OLED_ERROR_REG and _ON_TIME store no
 *      checksum; TOOL_ANSWER_98 changes nothing.
 *   2. Any other cmd is a result code: it goes to byte 7 (0x88 becomes 2, unknown codes TOOL_RESULT_E2), and
 *      the checksum to byte 8.
 *
 * TOOL_ANSWER_TABLE_READ stores the checksum at byte 0x47 when request byte 6 is 0x40 (byte 1 = 0xC5), else at
 * 0x17 (byte 1 = 0x95); 0x47 lies beyond the 40-byte buffer of ddc_tool_answer_read_request.
 */
void ddc_tool_build_reply(const unsigned char *request, unsigned char *reply, unsigned char cmd)
{
    unsigned int on_time_minutes;

    /* Phase 1: answers. */
    if (cmd == TOOL_ANSWER_TABLE_READ) {
        if (request[6] == 0x40)
            reply[0x47] = tool_checksum(reply, DDC_CHECKSUM_SEED);
        else
            reply[0x17] = tool_checksum(reply, DDC_CHECKSUM_SEED);
    }
    else if (cmd == TOOL_ANSWER_98) {
    }
    else if (cmd == TOOL_ANSWER_97) {
        answer_97(reply);
    }
    else if (cmd == TOOL_ANSWER_96) {
        reply[8] = tool_checksum(reply, DDC_CHECKSUM_SEED);
    }
    else if (cmd == TOOL_ANSWER_ZERO_BYTES) {
        /* Done and six zero bytes. */
        reply[1] = DDC_LENGTH_BYTE(12);
        reply[7] = TOOL_RESULT_DONE;
        reply[8] = 0;
        reply[9] = 0;
        reply[10] = 0;
        reply[11] = 0;
        reply[12] = 0;
        reply[13] = 0;
        reply[14] = tool_checksum(reply, DDC_CHECKSUM_SEED);
    }
    else if (cmd == TOOL_ANSWER_COLOR_GAINS) {
        answer_color_gains(reply);
    }
    else if (cmd == TOOL_ANSWER_KEY_TEST) {
        answer_key_test(reply);
    }
    else if (cmd == TOOL_ANSWER_KEY_CHECK_1) {
        /* The input processor's check of the stored copy-protection keys, 1 and 2. */
        if (ipc_check_hdcp_stored_keys(1) == 1)
            reply[7] = TOOL_RESULT_DONE;
        else
            reply[7] = TOOL_RESULT_E1;
    }
    else if (cmd == TOOL_ANSWER_KEY_CHECK_2) {
        if (ipc_check_hdcp_stored_keys(2) == 1)
            reply[7] = TOOL_RESULT_DONE;
        else
            reply[7] = TOOL_RESULT_E1;
    }
    else if (cmd == TOOL_ANSWER_LANGUAGE) {
        /* Menu language (settings byte +8, 1 = English) -> the tool's language number in byte 7; this is the
           inverse of the table in ddc_tool_set_language. A language above 28 gives TOOL_RESULT_BAD_VALUE in
           byte 8 instead of TOOL_RESULT_DONE. */
        reply[8] = TOOL_RESULT_DONE;
        switch (user_settings_language) {
        case 28: reply[7] = 0x1f; break;
        case 27: reply[7] = 0x1e; break;
        case 26: reply[7] = 0x1d; break;
        case 25: reply[7] = 5; break;
        case 24: reply[7] = 8; break;
        case 23: reply[7] = 0x1c; break;
        case 22: reply[7] = 6; break;
        case 21: reply[7] = 0x1b; break;
        case 20: reply[7] = 0x1a; break;
        case 19: reply[7] = 0x19; break;
        case 18: reply[7] = 0x18; break;
        case 17: reply[7] = 0x17; break;
        case 16: reply[7] = 0x16; break;
        case 15: reply[7] = 0x15; break;
        case 14: reply[7] = 0x14; break;
        case 13: reply[7] = 0x10; break;
        case 12: reply[7] = 0x13; break;
        case 11: reply[7] = 0x12; break;
        case 10: reply[7] = 0x11; break;
        case 9: reply[7] = 7; break;
        case 8: reply[7] = 9; break;
        case 7: reply[7] = 0xd; break;
        case 6: reply[7] = 0xe; break;
        case 5: reply[7] = 3; break;
        case 4: reply[7] = 4; break;
        case 3: reply[7] = 1; break;
        case 2: reply[7] = 2; break;
        case 1: reply[7] = 0; break;
        case 0: reply[7] = 0xc; break;
        default: reply[8] = TOOL_RESULT_BAD_VALUE; break;
        }
        reply[1] = DDC_LENGTH_BYTE(7);
        reply[9] = tool_checksum(reply, DDC_CHECKSUM_SEED);
    }
    else if (cmd == TOOL_ANSWER_SERIAL) {
        answer_serial(reply);
    }
    else if (cmd == TOOL_ANSWER_1F) {
        /* Bytes 7..10 stay as the caller cleared them. */
        reply[1] = DDC_LENGTH_BYTE(9);
        reply[11] = tool_checksum(reply, DDC_CHECKSUM_SEED);
    }
    else if (cmd == TOOL_ANSWER_FACTORY_MODE) {
        reply[7] = (user_settings.word_0x0 >> SETTINGS_WORD0_FACTORY_MODE_BIT) & 1;
        reply[8] = tool_checksum(reply, DDC_CHECKSUM_SEED);
    }
    else if (cmd == TOOL_ANSWER_BURN_IN) {
        reply[7] = user_settings_burn_in_flag;
        reply[8] = tool_checksum(reply, DDC_CHECKSUM_SEED);
    }
    else if (cmd == TOOL_ANSWER_FACTORY_STATUS) {
        answer_factory_status(request, reply);
    }
    else if (cmd == TOOL_ANSWER_OLED_ERROR_REG) {
        /* Factory record halfword +0x16 (high, low). */
        reply[6] = factory_record.oled_error_reg10 >> 8;
        reply[7] = factory_record.oled_error_reg10;
    }
    else if (cmd == TOOL_ANSWER_ON_TIME) {
        /* The on-time in minutes: hours * 60 + minutes (high, low). */
        on_time_minutes = (unsigned short)(device_settings.on_time.word >> 8) * 60 + device_settings.on_time.bytes[0];
        reply[6] = on_time_minutes >> 8;
        reply[7] = on_time_minutes;
    }
    else if (cmd == TOOL_ANSWER_INPUT) {
        /* The source of the Input Source setting: 0 -> 8, 1 -> 9, 2 -> 0x0D, 3 -> 0x0F, other -> TOOL_RESULT_E1.
           The translation is called again for every test. */
        if (input_api_source_id_to_menu_index(user_settings.input_source) == 0)
            reply[7] = 8;
        else if (input_api_source_id_to_menu_index(user_settings.input_source) == 1)
            reply[7] = 9;
        else if (input_api_source_id_to_menu_index(user_settings.input_source) == 2)
            reply[7] = 0xd;
        else if (input_api_source_id_to_menu_index(user_settings.input_source) == 3)
            reply[7] = 0xf;
        else
            reply[7] = TOOL_RESULT_E1;
        reply[8] = tool_checksum(reply, DDC_CHECKSUM_SEED);
    }

    /* Phase 2: result codes. Case 2 is never reached here (cmd 2 is TOOL_ANSWER_FACTORY_MODE above). */
    else {
        switch (cmd) {
        case 0:
        case 1:
        case 2:
            reply[7] = cmd;
            break;
        case 0x88:
            reply[7] = 2;
            break;
        case TOOL_RESULT_DONE:
            reply[7] = TOOL_RESULT_DONE;
            break;
        case TOOL_RESULT_E1:
            reply[7] = TOOL_RESULT_E1;
            break;
        case TOOL_RESULT_E2:
            reply[7] = TOOL_RESULT_E2;
            break;
        case TOOL_RESULT_UNKNOWN:
            reply[7] = TOOL_RESULT_UNKNOWN;
            break;
        case TOOL_RESULT_BAD_VALUE:
            reply[7] = TOOL_RESULT_BAD_VALUE;
            break;
        default:
            reply[7] = TOOL_RESULT_E2;
            break;
        }
        reply[8] = tool_checksum(reply, DDC_CHECKSUM_SEED);
    }
}
