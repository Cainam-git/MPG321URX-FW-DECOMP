/* ipc_dispatch_command  (FUN_a0070b7c)
 *
 * Carry out one command message received from the main processor.
 *   msg: 32-byte command message
 * Note: Replies go back through ipc_send_reply.
 * Name basis: proven - switch on byte 2 of the verified slot-8 message, 109 cases; prints '_SetDPMST',
 *   '_SetLeonSPowerDown'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0070b7c @ 0xa0070b7c-0xa0072900 (7556 bytes), flags -mcpu=v8 -Os -g (the section default).
 * Jump tables: switchdataD_a007077c (the command switch, 256 entries), switchdataD_a0070758 (command 0x03),
 * switchdataD_a0070740 / switchdataD_a0070728 (commands 0xA0 / 0xA1).
 * Source forms the exact build depends on:
 *  - the case blocks are written in the firmware's block order (-Os keeps source order), so the command numbers
 *    are not sorted;
 *  - most cases copy msg->data into a local and its bytes into unsigned char locals (direct (unsigned char)
 *    casts of msg->data >> n are narrowed to byte loads); the order of those declarations and of the stores
 *    decides the instruction schedule;
 *  - the function-scope unsigned char arg holds the second data byte in many cases, and the two function-scope
 *    unsigned char variables arg1 and arg2 hold byte arguments in commands 0x13, 0x16, 0x27, 0x29, 0x59, 0x92
 *    and 0xF4 (one register each for the whole routine);
 *  - command 0x03 reads the word into an unsigned short and splits the 16-bit result as
 *    '(clock % 65536) >> 8' and 'clock % 256'; command 0x12 passes an unsigned short copy of the word to the
 *    final call; command 0x50 reads the low halfword of more[0] before the other words;
 *  - the saved register bytes are an initialised array in an inner block opened after the first call;
 *  - the copies of a path record for dp_tx_set_video_timing go through a block-local record pointer.
 */

/*
 * One command message from the main processor: the eight words of mailbox slot 8. The main program's
 * ipc_send_command builds it, ipc_poll_command reads it and checks it (ipc_verify_message) before it calls this
 * routine. Word 0 holds the checksum (top byte), the data length + 4, the command number and the marker 0x55;
 * the data bytes follow in words 1..7, four per word with the first byte in the low bits. "Data byte n" below
 * means byte n of that list: data byte 0 = bits 0..7 of data, data byte 4 = bits 0..7 of more[0], and so on.
 */
struct ipc_message {
    unsigned char checksum;         /* XOR of all bytes of the eight words */
    unsigned char length;           /* data length + 4 */
    unsigned char command;          /* command number (enum ipc_command) */
    unsigned char marker;           /* 0x55 */
    unsigned int data;              /* data bytes 0..3 */
    unsigned int more[6];           /* data bytes 4..27 */
};

/* DisplayPort input record (300 bytes per DP receiver, dp_input_records). Only the bytes written here are listed. */
struct dp_input_record {
    unsigned char before_0x110[0x110];
    unsigned char byte_0x110;       /* 1..3, selects the values of registers 0x201 / 0x3B1 / 0x3B3 */
    unsigned char byte_0x111;       /* 1..2, selects the values of registers 0x202 / 0x3B2 */
    unsigned char byte_0x112;       /* the MST switch of command 0x24 ('_SetDPMST') */
    unsigned char byte_0x113, byte_0x114, byte_0x115, byte_0x116;
    unsigned char byte_0x117;       /* 0, 1 or 2 */
    unsigned char byte_0x118;
    unsigned char byte_0x119;       /* port swap, used by dp_init_port when its flag argument is 0 */
    unsigned char byte_0x11a, byte_0x11b, byte_0x11c, byte_0x11d;
    unsigned char byte_0x11e;       /* picks the value of register 0x21C */
    unsigned char byte_0x11f;       /* 1 selects the other value of register 0x2B */
    unsigned short half_0x120;      /* divider for dp_write_rate_divider_regs */
    unsigned char byte_0x122, byte_0x123, byte_0x124, byte_0x125, byte_0x126, byte_0x127;
    unsigned char byte_0x128;       /* set to 1 by command 0x30 */
    unsigned char byte_0x129;       /* set by command 0x32 */
    unsigned char after_0x129[2];
};
extern struct dp_input_record dp_input_records[];

/*
 * HDMI TX request (20 bytes per HDMI TX port, hdmi_tx_requests), filled by commands 0x40..0x44. When a request is
 * marked pending, hdmi_tx_apply_pending_request copies the fields into the port's channel record (struct
 * hdmi_tx_channel_record); the comments say where each field goes there. Bytes +0x10..+0x12 go to registers 2
 * and 0x0B of bank 1 of the transmitter instead (hdmi_tx_apply_request_regs).
 */
struct hdmi_tx_request {
    unsigned short bit15 : 1;
    unsigned short bit14 : 1;               /* to channel word 0 bit 31 */
    unsigned short bit13 : 1;               /* to channel word 3 bit 31 */
    unsigned short bit12 : 1;               /* to channel word 0 bit 30 */
    unsigned short hsync_positive : 1;      /* bit 11, to channel word 0 bit 7 */
    unsigned short vsync_positive : 1;      /* bit 10, to channel word 0 bit 6 */
    unsigned short hdmi_mode : 1;           /* bit 9, to channel word 0 bit 5 */
    unsigned short bit8 : 1;                /* to channel word 4 bit 31 */
    unsigned short bit7 : 1;                /* to channel word 0 bit 4 */
    unsigned short bit6 : 1;                /* to channel word 0 bit 3 */
    unsigned short bit5 : 1;                /* to channel word 0 bit 2 and word 5 bit 15 */
    unsigned short bit4 : 1;                /* to channel word 0 bit 1 */
    unsigned short bit3 : 1;                /* to channel word 0 bit 0 */
    unsigned short bit2 : 1;                /* to channel word 4 bit 7 */
    unsigned short bit1 : 1;                /* to channel word 4 bit 6 */
    unsigned short bit0 : 1;                /* to channel word 4 bit 5 */
    union {
        struct {
            unsigned short bit15 : 1;       /* to channel word 4 bit 4 */
            unsigned short bit14 : 1;       /* to channel word 4 bit 3 */
            unsigned short bit13 : 1;       /* to channel word 0 bit 29 */
            unsigned short bits_8_12 : 5;
            unsigned short low_byte : 8;
        } bits;
        unsigned char bytes[2];             /* bytes[1] (+3) = source code, to channel byte +1 */
    } half_2;
    unsigned short pixel_clock;             /* +4, to channel word 2 (the pixel clock) */
    unsigned char byte_0x6;                 /* to channel byte +0xD */
    unsigned char byte_0x7;                 /* to channel byte +0xE */
    unsigned char byte_0x8;                 /* to channel byte +0x12 */
    unsigned char color_depth;              /* +9, to channel byte +0x11 */
    unsigned char byte_0xa;                 /* to channel byte +0xF */
    unsigned char byte_0xb;
    unsigned char input_code;               /* +0xC, to channel byte +0x17 */
    unsigned char byte_0xd;
    unsigned char byte_0xe;
    unsigned char byte_0xf;
    unsigned char bank1_reg2_high;          /* +0x10: high nibble of bank 1 register 2 */
    unsigned char bank1_reg2_low;           /* +0x11: low nibble of bank 1 register 2 */
    unsigned char bank1_reg0b;              /* +0x12: bank 1 register 0x0B */
    unsigned char byte_0x13;
};
extern struct hdmi_tx_request hdmi_tx_requests[];

/*
 * Path record of one DP output (40 bytes each, dp_tx_path_records), the same record as in dp_tx_set_video_timing.
 * Word 0 holds flag bits, +4..+0x12 the eight size values that dp_tx_set_video_timing writes to registers
 * 0x56..0x65, word +0x20 and byte +0x24 the link limits of command 0x5E.
 */
struct path_record {
    unsigned int reg70_bit4 : 1;            /* bit 31: passed to dp_tx_set_reg70_bit4 by command 0x55 */
    unsigned int bit30 : 1;
    unsigned int mode_flag : 1;             /* bit 29: record 0 = the bit dp_tx_get_mode_flag returns */
    unsigned int keep_timing : 1;           /* bit 28: 1 = registers 0x56..0x65 are not written */
    unsigned int keep_reg50 : 1;            /* bit 27: 1 = registers 0x50..0x52 are not rewritten */
    unsigned int bit26 : 1;
    unsigned int reg70_bit5 : 1;            /* bit 25: copied to register 0x70 bit 5 */
    unsigned int bit24 : 1;
    unsigned int source_code : 8;           /* +1: returned by input_get_port_source_code */
    unsigned int half_0x2 : 16;
    unsigned short line_length;             /* +4: size value 0 */
    unsigned short frame_length;            /* +6: size value 1 */
    unsigned short active_width;            /* +8: size value 2 */
    unsigned short active_height;           /* +0xA: size value 3 */
    unsigned short size4;                   /* +0xC: (line length - active width) / 3 */
    unsigned short size5;                   /* +0xE: twice size4 */
    unsigned short size6;                   /* +0x10: (frame length - active height) / 3 */
    unsigned short size7;                   /* +0x12: twice size6 */
    unsigned short byte_0x14 : 8;           /* returned by dp_tx_get_path_byte20 */
    unsigned short bits_per_colour : 8;     /* +0x15, returned by dp_tx_get_path_bits_per_colour */
    unsigned short half_0x16;
    unsigned int word_0x18;
    unsigned int word_0x1c;
    unsigned int bits_15_31 : 17;           /* bit 15 = the path option of dp_tx_get_path_option */
    unsigned int ctl_reg8_mode : 2;         /* bits 13..14: mode for control register 8 bits 6..7 */
    unsigned int ctl_reg9_bit3 : 1;         /* bit 12: control register 9 bit 3 */
    unsigned int link_option : 1;           /* bit 11: for dp_tx_set_link_option */
    unsigned int bits_8_10 : 3;
    unsigned int max_link_rate : 8;         /* bits 0..7: code for dp_tx_set_max_link_rate */
    unsigned char max_lane_count;           /* +0x24: code for dp_tx_set_max_lane_count */
    unsigned char byte_0x25;                /* cleared by command 0x50 */
    unsigned char byte_0x26;
    unsigned char byte_0x27;
};
extern struct path_record dp_tx_path_records[];

/* HDMI TX channel record (28 bytes per HDMI TX port, hdmi_tx_output_records); only the two bytes read here are named. */
struct hdmi_tx_channel_record {
    unsigned char byte_0x0;
    unsigned char source_code;              /* +1 */
    unsigned char byte_0x2, byte_0x3;
    unsigned char bytes_0x4[0x13];
    unsigned char input_code;               /* +0x17: the input code when the source code is 0xE1 / 0xE2 */
    unsigned char bytes_0x18[4];
};
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];

/* HDMI PHY record (24 bytes per PHY, hdmi_phy_records; PHYs 2 and 3 belong to the HDMI 2.1 receivers). */
struct hdmi_phy_record {
    unsigned char power;                    /* +0 */
    unsigned char eq_done;                  /* +1 */
    unsigned char byte_0x2;                 /* set by hdmi_phy_request_eq_reset */
    unsigned char byte_0x3, byte_0x4, byte_0x5, byte_0x6;
    unsigned char option_byte;              /* +7: set by command 0x15 */
    unsigned char rest[16];
};
extern struct hdmi_phy_record hdmi_phy_records[];

/*
 * The three configuration bytes handed to audio_configure (by value). Command 0x90 fills byte 0 with data
 * byte 0 in reversed bit order (data bit 0 becomes bit 7, data bit 7 becomes bit 0), bits 6..7 of byte 1 with
 * data byte 2, bits 4..5 of byte 1 with data byte 3, and byte 2 with data byte 1.
 */
struct audio_config_arg {
    unsigned char bit7 : 1;
    unsigned char bit6 : 1;
    unsigned char bit5 : 1;
    unsigned char bit4 : 1;
    unsigned char bit3 : 1;
    unsigned char bit2 : 1;
    unsigned char bit1 : 1;
    unsigned char bit0 : 1;
    unsigned char bits_6_7 : 2;
    unsigned char bits_4_5 : 2;
    unsigned char : 4;
    unsigned char byte_2;
};

/* Register numbers of the HDMI receivers that command 0x13 can write, picked by data byte 1. */
extern const unsigned short hdmi_rx_command_reg_list[];
/* Byte block from 0xA80788D0 that command 0x96 writes by index. It holds input_port_event_flags (+2),
 * input_command_flags (+4), ipc_status_flag_6 (+0xC) and input_event_clear_mask (+0xD). */
extern unsigned char ARR_a80788d0[];
extern unsigned char ipc_status_flag_6;
extern unsigned char input_event_clear_mask;
extern unsigned char sys_dsc_dec_command_value;
extern unsigned char sys_dsc_dec_restart_flag;
extern unsigned char dp_tx_edp_hpd_enable;
extern unsigned short ipc_command_0x76_low;
extern unsigned short ipc_command_0x76_high;
extern unsigned int dp_reg3d0_value;
extern unsigned char audio_mute_value;
extern unsigned char dp_tx_lane_route_byte;
extern unsigned char dp_tx_edp_first_output;
extern unsigned char dp_tx_edp_last_output;
extern unsigned char dp_tx_output_map;
extern unsigned char hdmi_rx21_lts_record0_byte1;   /* the FRL rate byte (+1) of HDMI 2.1 receiver 0's link training record */
extern unsigned char hdmi_rx21_lts_record1_byte1;   /* the same byte of receiver 1 */
extern unsigned char hdmi_tx_sink_flags;            /* byte 0 of hdmi_tx_sink_flags: HDMI TX port 0, status bit 3 */
extern unsigned char hdmi_tx_sink_flag_port1;                  /* byte 1 of hdmi_tx_sink_flags: HDMI TX port 1, status bit 4 */
extern unsigned char dp_tx_hpd_flag;

/* Four registers whose low bytes are saved before the command and written back after it. Nothing here shows
 * their use; they sit just below the DP receiver page select registers 0xCF03D014..0xCF03D020. */
#define REG_CF03D004 (*(volatile unsigned int *)0xcf03d004)
#define REG_CF03D008 (*(volatile unsigned int *)0xcf03d008)
#define REG_CF03D00C (*(volatile unsigned int *)0xcf03d00c)
#define REG_CF03D010 (*(volatile unsigned int *)0xcf03d010)

#define REPLY_BYTES         0x1c    /* data bytes of every reply (the 28-byte buffer) */
#define IPC_SLOT_STATUS     0       /* mailbox slot with the status words */
#define IPC_STATUS_WORD     3       /* its word 3: bits 16..23 = port change bits (ipc_set_port_changed_bit) */
#define IPC_SLOT_COMMAND    8       /* mailbox slot the command came in */
#define PORT_CHANGE_BITS    0xff0000

/* Input numbers inside commands (docs/MAILBOX.md). 6..8 only occur in command 0x03. */
#define INPUT_HDMI20_0      0
#define INPUT_HDMI20_1      1
#define INPUT_HDMI21_0      2
#define INPUT_HDMI21_1      3
#define INPUT_DP_0          4
#define INPUT_DP_1          5
#define INPUT_DP_0_FIELD_1  6       /* DP input 0 with field 1 in bits 6..7 of its register 0x9F */
#define INPUT_DP_0_FIELD_2  7
#define INPUT_DP_0_FIELD_3  8

#define HDMI_TX_PORTS       2
#define DP_RX_PORTS         2
#define DP_TX_OUTPUTS       5       /* output 0 = DP transmitter, 1..4 = eDP outputs */
#define DP_TX_OUTPUT_0      0
#define DP_TX_LANES         4
#define DP_RX_REG_FIRST     0x200   /* command 0x22 reads only registers 0x200..0x3FF */
#define DP_RX_REG_END       0x400
#define DP_RX_REG252        0x252
#define INPUT_CODE_DP_0     0x71    /* input codes of the two DP inputs */
#define INPUT_CODE_DP_1     0x81
#define DP_COLOR_DEPTH_MIN  8       /* least colour depth stored for a DP input code */
#define CHIP_REV_ABOVE      0xdf    /* sys_get_chip_revision returns 0x80..0x84, never above this */
#define CVTEM_CODE_DP       8       /* command 0xA1 answer for the DP inputs */
#define SINK_POWER_SAVE     0       /* dp_tx_set_sink_power: not 1 = write 2 (power-save) to sink register 0x600 */
#define POWER_DOWN_PRINT    999     /* number printed with '_SetLeonSPowerDown' */

/* Clear bits of command 0xFB. */
#define CLEAR_HDMI_TX0_SINK_FLAG 1
#define CLEAR_HDMI_TX1_SINK_FLAG 2
#define CLEAR_DP_TX_HPD_FLAG     4

/* Sub-commands of command 0x83 (data byte 1). */
#define PORT_STATUS_BIT     0
#define PORT_STATUS_FRL     1

/* Sub-commands of command 0x94 (data byte 0). */
#define AUDIO_LEVEL_OUTPUT  0
#define AUDIO_LEVEL_INPUTS  1

/* Command numbers (byte 2 of word 0). The names say what this routine does with them. */
enum ipc_command {
    IPC_CMD_LINK_TEST                   = 0x00, /* reply the bytes 0..27 */
    IPC_CMD_SET_HDMI_PHY_STATE          = 0x01,
    IPC_CMD_SET_PORT_TYPE               = 0x02,
    IPC_CMD_GET_INPUT_CLOCK             = 0x03,
    IPC_CMD_ENABLE_HDMI_PHY_INPUT       = 0x11,
    IPC_CMD_RESTART_HDMI_PORT           = 0x12,
    IPC_CMD_WRITE_HDMI_RX_LISTED_REG    = 0x13,
    IPC_CMD_SET_HDCP_RX_PORT_OPTION     = 0x14,
    IPC_CMD_SET_HDMI_PHY_OPTION_BYTE    = 0x15,
    IPC_CMD_SET_HDMI21_PORT_MASK        = 0x16,
    IPC_CMD_SET_DP_RX_CONFIG            = 0x20,
    IPC_CMD_SET_DP_RX_MODE              = 0x21,
    IPC_CMD_GET_DP_RX_REGISTER          = 0x22,
    IPC_CMD_WRITE_DP_RX_DPCD_REG        = 0x23,
    IPC_CMD_SET_DP_MST                  = 0x24,
    IPC_CMD_SET_DP_RX_CAPABILITIES      = 0x25,
    IPC_CMD_SET_DP_RX_SETTING_115       = 0x26,
    IPC_CMD_SET_DP_RX_REGS_C5_C4        = 0x27,
    IPC_CMD_SET_DP_RX_REG40_BITS        = 0x28,
    IPC_CMD_SET_DP_RX_REG9F_FIELD       = 0x29,
    IPC_CMD_PULSE_DP_RX_REG30_BIT6      = 0x2a,
    IPC_CMD_CLEAR_DP_RX_REG3D0          = 0x2b,
    IPC_CMD_SET_DP_RX_REG44_BITS        = 0x2c,
    IPC_CMD_SET_DP_RX_SETTING_116       = 0x2d,
    IPC_CMD_SET_DP_RX_LANE_OPTIONS      = 0x2e,
    IPC_CMD_SET_DP_MST_LOGICAL_NUMBER   = 0x2f,
    IPC_CMD_SET_DP_RX_FLAG_128          = 0x30,
    IPC_CMD_CHECK_DP_RX_SERVICE         = 0x31,
    IPC_CMD_SET_DP_RX_BYTE_129          = 0x32,
    IPC_CMD_SET_DSC_4_SLICES_OPTION     = 0x33,
    IPC_CMD_SET_HDMI_TX_REQUEST_BYTES   = 0x40,
    IPC_CMD_SET_HDMI_TX_REQUEST_BIT12   = 0x41,
    IPC_CMD_SET_HDMI_TX_REQUEST         = 0x42,
    IPC_CMD_CLEAR_HDMI_TX_REQUEST_BIT14 = 0x43,
    IPC_CMD_STAGE_HDMI_TX_REQUEST_BYTES = 0x44,
    IPC_CMD_GET_HDMI_TX_REGISTERS       = 0x45,
    IPC_CMD_GET_HDMI_TX_STATUS_BIT31    = 0x46,
    IPC_CMD_SET_HDMI_TX_REG0D_BIT2      = 0x47,
    IPC_CMD_SET_DP_TX_TIMING            = 0x50,
    IPC_CMD_DP_TX_TIMING_PART           = 0x51,
    IPC_CMD_SET_DP_TX_KEEP_REG50        = 0x52,
    IPC_CMD_SET_DP_TX_KEEP_TIMING       = 0x53,
    IPC_CMD_SET_DP_TX_PATH_BIT30        = 0x54,
    IPC_CMD_OUTPUT_FLAG_BIT31           = 0x55,
    IPC_CMD_OUTPUT_REQUEST_FLAGS        = 0x56,
    IPC_CMD_GET_DP_TX_REG70_BIT4        = 0x57,
    IPC_CMD_SET_DP_TX_DRIVE_LEVELS      = 0x59,
    IPC_CMD_WRITE_DP_TX_REG57           = 0x5a,
    IPC_CMD_SET_DP_TX_REG70_BIT5        = 0x5b,
    IPC_CMD_IS_DP_TX_LINK_ACTIVE        = 0x5c,
    IPC_CMD_SET_HDCP_TX_DP_BYPASS       = 0x5d,
    IPC_CMD_SET_DP_TX_LINK_LIMITS       = 0x5e,
    IPC_CMD_SET_DP_TX_REG11_MODE        = 0x5f,
    IPC_CMD_REQUEST_DP_TX_PACING_UPDATE = 0x60,
    IPC_CMD_SET_DP_TX_FASTMUTE_PATTERN  = 0x63,
    IPC_CMD_SET_EVENT_CLEAR_MASK        = 0x70,
    IPC_CMD_GET_INPUT_TIMING            = 0x71,
    IPC_CMD_POWER_DOWN_FOR_SAVING       = 0x72,
    IPC_CMD_POWER_DOWN                  = 0x73,
    IPC_CMD_SET_DSC_DEC_COMMAND         = 0x74,
    IPC_CMD_SET_EDP_HPD_ENABLE          = 0x75,
    IPC_CMD_SET_HDR_PEAK_LUMINANCE      = 0x76,
    IPC_CMD_SELECT_HDR_SOURCE           = 0x77,
    IPC_CMD_SET_HDR_SOURCE_ENABLE       = 0x78,
    IPC_CMD_GET_HDR_STATUS              = 0x79,
    IPC_CMD_SET_HDR_ENABLE              = 0x7a,
    IPC_CMD_REQUEST_HDR_RELOAD          = 0x7b,
    IPC_CMD_GET_DP_RX_REG3D0_VALUE      = 0x7c,
    IPC_CMD_SET_COMMAND_FLAGS           = 0x7d,
    IPC_CMD_SET_PORT_OPTION_MASK        = 0x7e,
    IPC_CMD_APPLY_PORT_ENABLE_MASK      = 0x7f,
    IPC_CMD_SET_DP_RX_SETTING_11F       = 0x80,
    IPC_CMD_ACK_PORT_CHANGE             = 0x81,
    IPC_CMD_LINK_TEST_82                = 0x82, /* as 0x00 */
    IPC_CMD_GET_HDMI_PORT_STATUS        = 0x83,
    IPC_CMD_LINK_TEST_84                = 0x84, /* as 0x00 */
    IPC_CMD_LINK_TEST_85                = 0x85, /* as 0x00 */
    IPC_CMD_SET_DP_RX_REG252_BITS       = 0x86,
    IPC_CMD_PING                        = 0x87,
    IPC_CMD_SET_HDR_MODE_BYTE           = 0x88,
    IPC_CMD_CONFIGURE_AUDIO             = 0x90,
    IPC_CMD_SET_AUDIO_MUTE              = 0x91,
    IPC_CMD_ROUTE_AUDIO_SOURCE          = 0x92,
    IPC_CMD_SET_AUDIO_UNIT_FREQUENCY    = 0x93,
    IPC_CMD_SET_AUDIO_LEVEL             = 0x94,
    IPC_CMD_CLEAR_AUDIO_LEVEL_STEPS     = 0x95,
    IPC_CMD_SET_STATUS_BLOCK_BYTE       = 0x96,
    IPC_CMD_GET_INPUT_STATUS_BYTE       = 0xa0,
    IPC_CMD_GET_INPUT_SETTING_BYTE      = 0xa1,
    IPC_CMD_RELOAD_HDR_TONE_CURVE       = 0xa2,
    IPC_CMD_SET_HDR_OPTION_BYTE         = 0xa3,
    IPC_CMD_GET_HDMI21_FRL_RATE         = 0xa4,
    IPC_CMD_CONFIGURE_DSC_ENCODER       = 0xa5,
    IPC_CMD_PRINT_TIMING_CHANGE         = 0xa6,
    IPC_CMD_WRITE_HDMI_PHY_REG          = 0xf0,
    IPC_CMD_WRITE_HDMI_RX_REG           = 0xf1,
    IPC_CMD_READ_HDMI_RX_REG            = 0xf2,
    IPC_CMD_READ_INFOFRAME              = 0xf3,
    IPC_CMD_WRITE_HDMI_TX_REG           = 0xf4,
    IPC_CMD_WRITE_DP_RX_PAGED_REG       = 0xf5,
    IPC_CMD_WRITE_DP_RX_LOW_REG         = 0xf6,
    IPC_CMD_READ_DP_RX_REG              = 0xf7,
    IPC_CMD_READ_DP_TX_REG              = 0xf8,
    IPC_CMD_WRITE_DP_TX_REG             = 0xf9,
    IPC_CMD_OSD_UNZIP                   = 0xfa,
    IPC_CMD_CLEAR_STATUS_FLAGS          = 0xfb,
    IPC_CMD_CHECK_HDCP_STORED_KEYS      = 0xfd,
    IPC_CMD_SET_DSC_ENCODER_PARAMETERS  = 0xfe,
    IPC_CMD_RESTART_DP_UNIT             = 0xff
};

extern void *lib_memset(void *, int, unsigned int);
extern void *lib_memcpy(void *dst, const void *src, unsigned int n);
extern void ipc_send_reply(int id, unsigned char len, unsigned char *d);
extern void ipc_read_mailbox_slot(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern void ipc_write_mailbox_slot(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern int dbg_printf(const char *fmt, ...);
extern void hdmi_phy_request_eq_reset(unsigned char);
extern void input_set_port_type(unsigned char n, unsigned char type);
extern int hdmi_calc_pixel_clock(unsigned char port);
extern int hdmi_rx21_calc_tmds_clock(unsigned char idx);
extern int dp_calc_pixel_clock(unsigned char port);
extern void dp_set_reg9f_field(unsigned char, unsigned char);
extern void hdmi_phy_set_input_enable(unsigned char, unsigned char);
extern void hdmi_tmds_restart_port(unsigned char);
extern void hdmi_rx21_restart_port(unsigned char);
extern void hdmi_rx21_reset_rx_detect_state(unsigned char);
extern void hdmi_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdmi_rx21_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdcp_rx_set_port_option(unsigned char, unsigned char);
extern void hdmi_rx21_set_mask_bits(unsigned char, unsigned char);
extern void hdmi_rx21_clear_mask_bits(unsigned char);
extern void dp_init_port(unsigned char port, unsigned char flag);
extern void dp_program_port(unsigned char port);
extern void dp_setup_port_regs(unsigned char port);
extern void dp_apply_port_settings(unsigned char port);
extern void dp_mst_select_port(unsigned char);
extern void dp_mst_reset_port(void);
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern void dp_write_dpcd_reg(unsigned char port, unsigned short reg, unsigned char val);
extern void dp_set_port0_setting_112(unsigned char, unsigned char);
extern void dp_write_capability_regs(unsigned char port);
extern void dp_set_port_setting_115(unsigned char, unsigned char);
extern void dp_set_regs_c5_c4(unsigned char, unsigned char, unsigned char);
extern void dp_set_reg40_bits_6_7(unsigned char);
extern void dp_set_reg30_bit6(unsigned char);
extern void dp_clear_reg223_bit7(unsigned char);
extern void dp_clear_reg3d0_value(unsigned char);
extern void dp_set_reg44_high_bits(unsigned char, unsigned char);
extern void dp_set_port_setting_116(unsigned char, unsigned char);
extern void dp_set_lane_option_bit(unsigned char, unsigned char);
extern unsigned char sys_get_chip_revision(void);
extern void dp_set_port_enable_bits(unsigned char, unsigned char, unsigned char);
extern void dp_apply_port_link_bytes(unsigned char);
extern void dp_mst_set_option_word(unsigned char);
extern unsigned char dp_is_port_ready_for_service(unsigned char);
extern void dp_pulse_hpd_block(void);
extern void dp_set_dsc_4_slices_option(unsigned char, unsigned char);
extern void hdmi_tx_apply_request_regs(unsigned char);
extern void hdmi_tx_mark_request_pending(unsigned char);
extern unsigned char hdmi_tx_reg_read8(unsigned char, unsigned short, unsigned short);
extern unsigned int hdmi_tx_get_status_bit31(unsigned char);
extern void hdmi_tx_set_reg0d_bit2(unsigned char, unsigned char);
extern void dp_tx_set_video_timing(unsigned int arg, unsigned short *p);
extern void dp_tx_set_reg70_bit4(unsigned char, unsigned char);
extern void dp_tx_post_action_flags(unsigned char port, unsigned short bits);
extern unsigned char dp_tx_get_reg70_bit4(unsigned char);
extern void dp_tx_set_drive_level_base(unsigned char, unsigned char, unsigned char);
extern void dp_tx_write_reg57_latched(unsigned char, unsigned short);
extern void dp_tx_set_reg70_bit5(unsigned char port, unsigned char v);
extern unsigned char dp_tx_is_link_active(unsigned char);
extern void hdcp_tx_dp_set_bypass(unsigned char);
extern void dp_tx_set_ctl_reg9_bit3(unsigned char, unsigned char);
extern void dp_tx_set_ctl_reg8_bits67(unsigned char, unsigned char);
extern void dp_tx_set_max_link_rate(unsigned char, unsigned char);
extern void dp_tx_set_max_lane_count(unsigned char, unsigned char);
extern void dp_tx_set_link_option(unsigned char, unsigned char);
extern void dp_tx_set_reg11_mode(unsigned char, unsigned char);
extern void dp_tx_request_pacing_update(unsigned char);
extern void dp_tx_set_fastmute_pattern(unsigned char, unsigned char);
extern void input_read_port_timing(struct ipc_message *s, unsigned char *d);
extern int dp_tx_set_sink_power(int a, int b);
extern void irq_set_mask_preset(unsigned char on);
extern void input_power_off_receivers_mode1(void);
extern void input_power_off_receivers_mode0(void);
extern void ipc_publish_status_flags(void);
extern unsigned char dp_tx_mode_requested_1(void);
extern unsigned char dp_tx_mode_requested_2(void);
extern unsigned char dp_tx_mode_requested_3(void);
extern unsigned char dp_tx_mode_requested_4(void);
extern void dp_tx_force_hpd_check(unsigned char);
extern void hdr_set_peak_luminance(unsigned short);
extern unsigned char input_decode_port_code(unsigned char code);
extern void hdr_select_source(unsigned char);
extern void hdr_set_source_disable_bit(unsigned char, unsigned char);
extern unsigned char hdr_get_status_code(void);
extern void hdr_set_enable(unsigned char);
extern void hdr_request_reload(void);
extern unsigned int dp_read_reg3d0_value(unsigned char ch);
extern void input_set_command_flags(unsigned char);
extern void input_set_port_option_mask(unsigned int v);
extern void input_apply_port_enable_mask(unsigned char mask);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern unsigned char dp_tx_option_enabled_stub_copy(void);
extern void hdr_set_mode_byte(unsigned char);
extern unsigned char hdmi_rx21_status04_bit17(unsigned char);
extern unsigned char hdmi_get_reg6_bit0(unsigned char);
extern unsigned char hdmi_rx21_is_frl_mode(unsigned char port);
extern void audio_configure(struct audio_config_arg cfg);
extern void audio_set_mute(unsigned char on);
extern void audio_route_source(unsigned char src, unsigned char out, unsigned char unit, unsigned char en);
extern void audio_set_unit_frequency(unsigned char, unsigned char);
extern void audio_set_input_levels(unsigned short v, unsigned char);
extern void audio_set_output_level(unsigned short v);
extern void audio_clear_level_step(void);
extern unsigned char hdmi_rx21_get_cvtem_flag(unsigned char);
extern unsigned char dp_get_msa_bit3(unsigned char ch);
extern unsigned char hdmi_rx21_get_cvtem_code(unsigned char);
extern void hdr_request_curve_table_reload(void);
extern void hdr_init(unsigned char);
extern void hdr_set_option_byte(unsigned char);
extern void sys_dsc_enc_configure(struct ipc_message *);
extern void hdmi_phy_write_reg(unsigned char ch, unsigned short reg, unsigned char val);
extern unsigned char hdmi_reg_read8(unsigned char, unsigned short);
extern unsigned char hdmi_rx21_reg_read8(unsigned char, unsigned short);
extern void hdmi_read_infoframe(unsigned char port, unsigned char sel, unsigned char *buf);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);
extern void dp_write_port_reg_wrapper(unsigned char, unsigned short, unsigned char);
extern void dp_write_low_reg(unsigned char, unsigned short, unsigned char);
extern unsigned char dp_tx_reg_read8(unsigned char, unsigned short);
extern void dp_tx_reg_write8(unsigned char, unsigned short, unsigned char);
extern void osd_request_unzip(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned char mode);
extern unsigned char hdcp_tx_check_stored_keys(unsigned char);
extern void sys_dsc_enc_set_parameters(struct ipc_message *);
extern void dp_unit_restart(unsigned char port, unsigned char mode);

/*
 * Carry out one command from the main processor and answer it.
 *
 * msg: the command message (struct ipc_message), already checked by the caller ipc_poll_command, which is the
 * only caller. Inputs are numbered as in docs/MAILBOX.md: 0 and 1 are the HDMI 2.0 inputs, 2 and 3 the HDMI 2.1
 * inputs, 4 and 5 the DisplayPort inputs. Most commands carry the port or output number in data byte 0.
 *
 * Phases, in order:
 *   1. Clear the 28-byte reply buffer.
 *   2. Save the low bytes of the registers 0xCF03D004, 0xCF03D008, 0xCF03D00C and 0xCF03D010.
 *   3. Carry out the command: one case per command number. The commands come in groups:
 *        0x00..0x16  HDMI receivers and PHYs (0x00 is a link test);
 *        0x20..0x33  DP receivers (records dp_input_records);
 *        0x40..0x47  HDMI transmitters (requests hdmi_tx_requests);
 *        0x50..0x63  DP outputs (path records dp_tx_path_records), with 0x5D for the DP protection bypass;
 *        0x70..0x88  input ports, power down, the DSC decoder, HDR, link tests 0x82 / 0x84 / 0x85;
 *        0x90..0x96  audio;
 *        0xA0..0xA6  status bytes of the inputs, HDR curve, DSC encoder, a debug print;
 *        0xF0..0xFF  single register reads and writes, OSD unzip, flag clears, protection key check,
 *                    DSC encoder parameters, DP receiver unit restart.
 *      A command that answers fills the reply buffer and sets has_reply. Unknown numbers do nothing.
 *   4. Send the reply when there is one: ipc_send_reply with the command number as id and all 28 bytes.
 *   5. Write 0 to word 0 of the command slot. The main program's ipc_send_command waits for this word to read
 *      0 before it sends the next command (and, when asked to wait, after sending).
 *   6. Write the saved bytes back to the four registers.
 * Commands 0x72 and 0x73 power the receivers down and stop in an endless loop, so they never reach phases 4..6
 * and the main processor gets no answer to them.
 */
void ipc_dispatch_command(struct ipc_message *msg)
{
    unsigned char reply[0x1c];
    unsigned char *reply_ptr = reply;
    unsigned char command;
    unsigned char has_reply;
    unsigned char i;
    unsigned char port;
    unsigned char arg;
    unsigned char arg1;
    unsigned char arg2;
    unsigned short clock;

    /* Phase 1: a reply sends 28 bytes, so the unused ones are zero. */
    lib_memset(reply_ptr, 0, REPLY_BYTES);
    {
        unsigned char saved_regs[4] = { 0 };

        /* Phase 2. */
        saved_regs[0] = REG_CF03D004;
        saved_regs[1] = REG_CF03D008;
        saved_regs[2] = REG_CF03D00C;
        saved_regs[3] = REG_CF03D010;
        command = msg->command;
        has_reply = 0;

        /* Phase 3. */
        switch (command) {
        case IPC_CMD_LINK_TEST:
            for (i = 0; i < REPLY_BYTES; i++)
                reply[i] = i;
            has_reply = 1;
            break;
        case IPC_CMD_SET_HDMI_PHY_STATE:
            /* Data byte 0 = PHY. */
            hdmi_phy_request_eq_reset(msg->data);
            break;
        case IPC_CMD_SET_PORT_TYPE:
            /* Data byte 0 = port, data byte 1 = type. */
            arg = msg->data >> 8;
            input_set_port_type(msg->data, arg);
            break;
        case IPC_CMD_GET_INPUT_CLOCK:
            /* Reply bytes 0..1 = the clock value of input 0..8 (low byte first); other inputs give 0. */
            {
                unsigned short input = msg->data;
                clock = 0;
                switch (input & 0xff) {
                case INPUT_HDMI20_0:
                case INPUT_HDMI20_1:
                    clock = hdmi_calc_pixel_clock(input);
                    break;
                case INPUT_HDMI21_0:
                case INPUT_HDMI21_1:
                    clock = hdmi_rx21_calc_tmds_clock(input - INPUT_HDMI21_0);
                    break;
                case INPUT_DP_0:
                case INPUT_DP_1:
                    clock = dp_calc_pixel_clock(input - INPUT_DP_0);
                    break;
                /* 6..8: DP input 0 measured with field 1..3 in register 0x9F, which is set back to 0 afterwards. */
                case INPUT_DP_0_FIELD_1:
                    dp_set_reg9f_field(0, 1);
                    clock = dp_calc_pixel_clock(0);
                    dp_set_reg9f_field(0, 0);
                    break;
                case INPUT_DP_0_FIELD_2:
                    dp_set_reg9f_field(0, 2);
                    clock = dp_calc_pixel_clock(0);
                    dp_set_reg9f_field(0, 0);
                    break;
                case INPUT_DP_0_FIELD_3:
                    dp_set_reg9f_field(0, 3);
                    clock = dp_calc_pixel_clock(0);
                    dp_set_reg9f_field(0, 0);
                    break;
                }
                reply[1] = (clock % 65536) >> 8;
                reply[0] = clock % 256;
                has_reply = 1;
            }
            break;
        case IPC_CMD_ENABLE_HDMI_PHY_INPUT:
            /* Data byte 0 = PHY, data byte 1 = enable. */
            arg = msg->data >> 8;
            hdmi_phy_set_input_enable(msg->data, arg);
            break;
        case IPC_CMD_RESTART_HDMI_PORT:
            /* Data byte 0 = input 0..3: the HDMI 2.1 path for inputs 2 and 3, the HDMI 2.0 path for 0 and 1.
             * Then the PHY state byte is set with the same number. */
            {
                unsigned int word = msg->data;
                unsigned short port16 = word;
                if ((unsigned char)word > INPUT_HDMI20_1) {
                    port = word - INPUT_HDMI21_0;
                    hdmi_rx21_restart_port(port);
                    hdmi_rx21_reset_rx_detect_state(port);
                } else
                    hdmi_tmds_restart_port(word);
                hdmi_phy_request_eq_reset(port16);
            }
            break;
        case IPC_CMD_WRITE_HDMI_RX_LISTED_REG:
            /* Data byte 0 = input, byte 1 = index into the register list, byte 2 = value. */
            {
                unsigned int word = msg->data;
                unsigned char input = word;
                unsigned short reg = hdmi_rx_command_reg_list[(word >> 8) & 0xff];
                arg1 = word >> 16;
                if (input > INPUT_HDMI20_1)
                    hdmi_rx21_reg_write8(word - INPUT_HDMI21_0, reg, arg1);
                else
                    hdmi_reg_write8(input, reg, arg1);
            }
            break;
        case IPC_CMD_SET_DP_RX_CONFIG:
            /* The full configuration of one DP receiver (data byte 0), then its whole set-up (dp_init_port with
             * flag 0, so the port swap comes from byte_0x119). */
            port = msg->data;
            dp_input_records[port].byte_0x110 = msg->data >> 8;
            dp_input_records[port].byte_0x111 = msg->data >> 16;
            /* Data byte 3, bits 0..4. */
            dp_input_records[port].byte_0x112 = (unsigned char)(msg->data >> 24) & 1;
            dp_input_records[port].byte_0x113 = ((unsigned char)(msg->data >> 24) >> 1) & 1;
            dp_input_records[port].byte_0x114 = ((unsigned char)(msg->data >> 24) >> 2) & 1;
            dp_input_records[port].byte_0x115 = ((unsigned char)(msg->data >> 24) >> 3) & 1;
            dp_input_records[port].byte_0x116 = ((unsigned char)(msg->data >> 24) >> 4) & 1;
            dp_input_records[port].byte_0x118 = msg->more[0];
            /* Data byte 5, bits 0 and 2..7 (bit 1 is not used). */
            dp_input_records[port].byte_0x119 = (msg->more[0] >> 8) & 1;
            dp_input_records[port].byte_0x11b = ((unsigned char)(msg->more[0] >> 8) >> 2) & 1;
            dp_input_records[port].byte_0x11c = ((unsigned char)(msg->more[0] >> 8) >> 3) & 1;
            dp_input_records[port].byte_0x11d = ((unsigned char)(msg->more[0] >> 8) >> 4) & 1;
            dp_input_records[port].byte_0x11e = ((unsigned char)(msg->more[0] >> 8) >> 5) & 1;
            dp_input_records[port].byte_0x11f = ((unsigned char)(msg->more[0] >> 8) >> 6) & 1;
            dp_input_records[port].byte_0x126 = (unsigned char)(msg->more[0] >> 8) >> 7;
            dp_input_records[port].half_0x120 = msg->more[0] >> 16;
            dp_input_records[port].byte_0x117 = msg->more[1];
            dp_input_records[port].byte_0x122 = 1;
            dp_init_port(port, 0);
            break;
        case IPC_CMD_SET_DP_RX_MODE:
            /* Data bytes 0..3 and 8 as in command 0x20; then the receiver's registers are written again and
             * dp_mst_select_port / dp_mst_reset_port run for it. */
            port = msg->data;
            dp_input_records[port].byte_0x110 = msg->data >> 8;
            dp_input_records[port].byte_0x111 = msg->data >> 16;
            dp_input_records[port].byte_0x112 = (unsigned char)(msg->data >> 24) & 1;
            dp_input_records[port].byte_0x113 = ((unsigned char)(msg->data >> 24) >> 1) & 1;
            dp_input_records[port].byte_0x114 = ((unsigned char)(msg->data >> 24) >> 2) & 1;
            dp_input_records[port].byte_0x115 = ((unsigned char)(msg->data >> 24) >> 3) & 1;
            dp_input_records[port].byte_0x116 = ((unsigned char)(msg->data >> 24) >> 4) & 1;
            dp_input_records[port].byte_0x117 = msg->more[1];
            dp_input_records[port].byte_0x122 = 1;
            dp_program_port(port);
            dp_setup_port_regs(port);
            dp_apply_port_settings(port);
            dp_mst_select_port(msg->data);
            dp_mst_reset_port();
            break;
        case IPC_CMD_GET_DP_RX_REGISTER:
            /* Data byte 0 = DP receiver, bytes 1..2 = register; registers outside 0x200..0x3FF read as 0. */
            {
                unsigned int word = msg->data;
                unsigned char rx = word;
                unsigned short reg = word >> 8;
                if (reg < DP_RX_REG_FIRST || reg >= DP_RX_REG_END)
                    reply[0] = 0;
                else
                    reply[0] = dp_reg_read8(rx, reg);
            }
            has_reply = 1;
            break;
        case IPC_CMD_WRITE_DP_RX_DPCD_REG:
            /* Data byte 0 = DP receiver, bytes 1..2 = register, byte 3 = value. */
            dp_write_dpcd_reg(msg->data, msg->data >> 8, msg->data >> 24);
            break;
        case IPC_CMD_SET_DP_MST:
            /* Data byte 0 = DP receiver, data byte 1 = MST on (1) or off (0). The value also goes into the
             * mode flag of path record 0; i holds it here. */
            port = msg->data;
            i = msg->data >> 8;
            dp_tx_path_records[0].mode_flag = i;
            dp_input_records[port].byte_0x112 = i;
            dbg_printf("_SetDPMST %d\r\n", i);
            dp_set_port0_setting_112(port, i);
            dp_mst_select_port(port);
            dp_mst_reset_port();
            break;
        case IPC_CMD_SET_DP_MST_LOGICAL_NUMBER:
            dbg_printf("\033[1;32mMSTLogicalNum : %d\r\n\033[m", (unsigned char)msg->data);
            dp_mst_set_option_word(msg->data);
            break;
        case IPC_CMD_SET_DP_RX_CAPABILITIES:
            /* Data byte 0 = DP receiver, byte 1 -> byte_0x117, byte 2 -> byte_0x110; then registers
             * 0x200..0x203 and 0x266 are written again from the record. */
            {
                unsigned int word = msg->data;
                unsigned char rx = word, byte_117 = word >> 8, byte_110 = word >> 16;
                dp_input_records[rx].byte_0x117 = byte_117;
                dp_input_records[rx].byte_0x110 = byte_110;
                dp_write_capability_regs(rx);
            }
            break;
        case IPC_CMD_SET_DP_RX_SETTING_115:
            arg = msg->data >> 8;
            dp_set_port_setting_115(msg->data, arg);
            break;
        case IPC_CMD_SET_DP_RX_REGS_C5_C4:
            {
                unsigned int word = msg->data;
                arg = word >> 8;
                arg1 = word >> 16;
                dp_set_regs_c5_c4(word, arg, arg1);
            }
            break;
        case IPC_CMD_SET_DP_RX_REG40_BITS:
            dp_set_reg40_bits_6_7(msg->data);
            break;
        case IPC_CMD_SET_DP_RX_REG9F_FIELD:
            arg1 = msg->data >> 8;
            dp_set_reg9f_field(msg->data, arg1);
            break;
        case IPC_CMD_PULSE_DP_RX_REG30_BIT6:
            dp_set_reg30_bit6(msg->data);
            break;
        case IPC_CMD_CLEAR_DP_RX_REG3D0:
            port = msg->data;
            dp_clear_reg223_bit7(port);
            dp_clear_reg3d0_value(port);
            break;
        case IPC_CMD_SET_DP_RX_REG44_BITS:
            arg = msg->data >> 8;
            dp_set_reg44_high_bits(msg->data, arg);
            break;
        case IPC_CMD_SET_DP_RX_SETTING_116:
            arg = msg->data >> 8;
            dp_set_port_setting_116(msg->data, arg);
            break;
        case IPC_CMD_SET_DSC_4_SLICES_OPTION:
            /* Data byte 0 = DP receiver, byte 1 = the 'DSC 3440 4 slices' option, stored by
             * dp_set_dsc_4_slices_option; the option picks register values in the DP receiver set-up, which is
             * then written again. */
            port = msg->data;
            arg = msg->data >> 8;
            dp_set_dsc_4_slices_option(port, arg);
            dp_program_port(port);
            break;
        case IPC_CMD_SET_DP_RX_LANE_OPTIONS:
            /* Data byte 0 = DP receiver, bytes 1..3 -> byte_0x118 / byte_0x11a / byte_0x11b, byte 4 = lane
             * option bit. */
            {
                unsigned int word = msg->data;
                unsigned char rx = word, byte_118 = word >> 8, byte_11a = word >> 16, byte_11b = word >> 24,
                    lane_option = msg->more[0];
                dp_input_records[rx].byte_0x118 = byte_118;
                dp_input_records[rx].byte_0x11a = byte_11a;
                dp_input_records[rx].byte_0x11b = byte_11b;
                /* The chip revision is never above 0xDF, so dp_set_port_enable_bits is not reached here. */
                if (lane_option == 0) {
                    dp_set_lane_option_bit(rx, 0);
                    if (sys_get_chip_revision() > CHIP_REV_ABOVE)
                        dp_set_port_enable_bits(rx, 0, 1);
                } else {
                    dp_set_lane_option_bit(rx, 1);
                    if (sys_get_chip_revision() > CHIP_REV_ABOVE)
                        dp_set_port_enable_bits(rx, 1, 1);
                }
                dp_apply_port_link_bytes(rx);
            }
            break;
        case IPC_CMD_SET_DP_RX_FLAG_128:
            port = msg->data;
            if (port < DP_RX_PORTS)
                dp_input_records[port].byte_0x128 = 1;
            break;
        case IPC_CMD_CHECK_DP_RX_SERVICE:
            /* Reply 1 when either DP receiver is connected with its record flag set; then also pulse bit 1 of
             * register 0xCF0132C0 (dp_pulse_hpd_block). */
            if (dp_is_port_ready_for_service(0) == 1 || dp_is_port_ready_for_service(1) == 1) {
                reply[0] = 1;
                dp_pulse_hpd_block();
            } else
                reply[0] = 0;
            has_reply = 1;
            break;
        case IPC_CMD_SET_DP_RX_BYTE_129:
            {
                unsigned int word = msg->data;
                unsigned char rx = word, value = word >> 8;
                if (rx < DP_RX_PORTS)
                    dp_input_records[rx].byte_0x129 = value;
            }
            break;
        case IPC_CMD_SET_HDMI_TX_REQUEST_BYTES:
            /* Data byte 0 = HDMI TX port, bytes 1..4 -> request bytes +0x10..+0x13, then written to the
             * transmitter at once. */
            {
                unsigned int word = msg->data;
                unsigned char tx = word, reg2_high = word >> 8, reg2_low = word >> 16, reg0b = word >> 24,
                    byte_13 = msg->more[0];
                hdmi_tx_requests[tx].bank1_reg2_high = reg2_high;
                hdmi_tx_requests[tx].bank1_reg2_low = reg2_low;
                hdmi_tx_requests[tx].bank1_reg0b = reg0b;
                hdmi_tx_requests[tx].byte_0x13 = byte_13;
                if (tx < HDMI_TX_PORTS)
                    hdmi_tx_apply_request_regs(tx);
            }
            break;
        case IPC_CMD_SET_HDMI_TX_REQUEST_BIT12:
            port = msg->data;
            arg = msg->data >> 8;
            hdmi_tx_requests[port].bit12 = arg;
            if (port < HDMI_TX_PORTS)
                hdmi_tx_mark_request_pending(port);
            break;
        case IPC_CMD_SET_HDMI_TX_REQUEST:
            /* The full request of one HDMI TX port (data byte 0), marked pending for
             * hdmi_tx_apply_pending_request. */
            arg = msg->data;
            if (arg < HDMI_TX_PORTS) {
                unsigned char byte4, byte7, byte10, code;
                unsigned short half;
                hdmi_tx_requests[arg].half_2.bytes[1] = msg->data >> 8;    /* source code */
                hdmi_tx_requests[arg].pixel_clock = msg->data >> 16;
                /* Data byte 4: bits 7, 6, 5 and the low five bits. */
                byte4 = msg->more[0];
                hdmi_tx_requests[arg].bit13 = byte4 >> 7;
                hdmi_tx_requests[arg].hsync_positive = byte4 >> 6;
                hdmi_tx_requests[arg].vsync_positive = byte4 >> 5;
                hdmi_tx_requests[arg].byte_0x6 = byte4 & 0x1f;
                hdmi_tx_requests[arg].byte_0x7 = msg->more[0] >> 8;
                /* Data byte 6: colour depth in the low nibble, byte_0xa in the high nibble. */
                half = msg->more[0] >> 16;
                hdmi_tx_requests[arg].color_depth = half & 0xf;
                hdmi_tx_requests[arg].byte_0xa = (half & 0xf0) >> 4;
                /* Data byte 7: one flag per bit. */
                byte7 = msg->more[0] >> 24;
                hdmi_tx_requests[arg].bit12 = byte7;
                hdmi_tx_requests[arg].hdmi_mode = byte7 >> 1;
                hdmi_tx_requests[arg].bit8 = byte7 >> 2;
                hdmi_tx_requests[arg].bit14 = byte7 >> 3;
                hdmi_tx_requests[arg].bit5 = byte7 >> 4;
                hdmi_tx_requests[arg].bit4 = byte7 >> 5;
                hdmi_tx_requests[arg].bit3 = byte7 >> 6;
                hdmi_tx_requests[arg].half_2.bits.bit13 = byte7 >> 7;
                /* For the source codes 0xE1 and 0xE2 the channel record's input code counts, for the others
                 * its source code. A DP input code keeps the colour depth at 8 or more. */
                if ((unsigned char)(hdmi_tx_requests[arg].half_2.bytes[1] + 0x1f) < 2)
                    code = hdmi_tx_output_records[arg].input_code;
                else
                    code = hdmi_tx_output_records[arg].source_code;
                switch (code) {
                case INPUT_CODE_DP_0:
                case INPUT_CODE_DP_1:
                    if (hdmi_tx_requests[arg].color_depth < DP_COLOR_DEPTH_MIN)
                        hdmi_tx_requests[arg].color_depth = DP_COLOR_DEPTH_MIN;
                    break;
                }
                hdmi_tx_requests[arg].byte_0x8 = msg->more[1];
                /* Data byte 10: one flag per bit (bit 2 is not used). */
                half = msg->more[1] >> 16;
                byte10 = half;
                hdmi_tx_requests[arg].bit7 = half;
                hdmi_tx_requests[arg].bit6 = byte10 >> 1;
                hdmi_tx_requests[arg].bit2 = byte10 >> 3;
                hdmi_tx_requests[arg].bit1 = byte10 >> 4;
                hdmi_tx_requests[arg].bit0 = byte10 >> 5;
                hdmi_tx_requests[arg].half_2.bits.bit15 = (byte10 >> 6) & 1;
                hdmi_tx_requests[arg].half_2.bits.bit14 = byte10 >> 7;
                hdmi_tx_requests[arg].byte_0xd = msg->more[1] >> 24;
                hdmi_tx_requests[arg].byte_0xe = msg->more[2];
                hdmi_tx_requests[arg].byte_0xf = msg->more[2] >> 8;
                hdmi_tx_requests[arg].input_code = msg->more[3] >> 16;
                hdmi_tx_mark_request_pending(arg);
            }
            break;
        case IPC_CMD_CLEAR_HDMI_TX_REQUEST_BIT14:
            port = msg->data;
            if (port < HDMI_TX_PORTS) {
                hdmi_tx_requests[port].bit14 = 0;
                hdmi_tx_mark_request_pending(port);
            }
            break;
        case IPC_CMD_STAGE_HDMI_TX_REQUEST_BYTES:
            /* As command 0x40, but the bytes wait for the pending request instead of being written now. */
            {
                unsigned int word = msg->data;
                unsigned char tx = word, reg2_high = word >> 8, reg2_low = word >> 16, reg0b = word >> 24,
                    byte_13 = msg->more[0];
                hdmi_tx_requests[tx].bank1_reg2_high = reg2_high;
                hdmi_tx_requests[tx].bank1_reg2_low = reg2_low;
                hdmi_tx_requests[tx].bank1_reg0b = reg0b;
                hdmi_tx_requests[tx].byte_0x13 = byte_13;
                if (tx < HDMI_TX_PORTS)
                    hdmi_tx_mark_request_pending(tx);
            }
            break;
        case IPC_CMD_GET_HDMI_TX_REGISTERS:
            /* Reply bytes 0..7 = bank 0 registers 0x3A..0x3D and 0x60..0x63 (zeros for a port above 1). */
            port = msg->data;
            if (port < HDMI_TX_PORTS) {
                reply[0] = hdmi_tx_reg_read8(port, 0, 0x3a);
                reply[1] = hdmi_tx_reg_read8(port, 0, 0x3b);
                reply[2] = hdmi_tx_reg_read8(port, 0, 0x3c);
                reply[3] = hdmi_tx_reg_read8(port, 0, 0x3d);
                reply[4] = hdmi_tx_reg_read8(port, 0, 0x60);
                reply[5] = hdmi_tx_reg_read8(port, 0, 0x61);
                reply[6] = hdmi_tx_reg_read8(port, 0, 0x62);
                reply[7] = hdmi_tx_reg_read8(port, 0, 0x63);
            }
            has_reply = 1;
            break;
        case IPC_CMD_SET_DP_TX_TIMING:
            /* Data byte 0 = DP output. Data byte 1 bits 0..5 = flag bits 31, 30, 29, 28, 27 and 25 of the path
             * record, byte 2 = source code, bytes 4..5 -> word_0x18, bytes 6 / 7 = byte_0x14 / bits per colour,
             * bytes 8..23 = the eight size values. The output is then programmed. */
            arg = msg->data;
            dp_tx_path_records[arg].reg70_bit4 = msg->data >> 8;
            dp_tx_path_records[arg].bit30 = msg->data >> 9;
            dp_tx_path_records[arg].mode_flag = msg->data >> 10;
            dp_tx_path_records[arg].keep_timing = msg->data >> 11;
            dp_tx_path_records[arg].keep_reg50 = msg->data >> 12;
            dp_tx_path_records[arg].reg70_bit5 = msg->data >> 13;
            dp_tx_path_records[arg].source_code = (msg->data & 0xff0000) >> 16;
            {
                unsigned int low_half = (unsigned short)msg->more[0];
                unsigned int sizes_0_1, sizes_2_3, sizes_4_5, sizes_6_7;
                dp_tx_path_records[arg].byte_0x14 = (msg->more[0] & 0xff0000) >> 16;
                dp_tx_path_records[arg].bits_per_colour = msg->more[0] >> 24;
                sizes_0_1 = msg->more[1];
                sizes_2_3 = msg->more[2];
                sizes_4_5 = msg->more[3];
                sizes_6_7 = msg->more[4];
                dp_tx_path_records[arg].line_length = sizes_0_1;
                dp_tx_path_records[arg].frame_length = sizes_0_1 >> 16;
                dp_tx_path_records[arg].active_width = sizes_2_3;
                dp_tx_path_records[arg].active_height = sizes_2_3 >> 16;
                dp_tx_path_records[arg].size4 = sizes_4_5;
                dp_tx_path_records[arg].size5 = sizes_4_5 >> 16;
                dp_tx_path_records[arg].size6 = sizes_6_7;
                dp_tx_path_records[arg].size7 = sizes_6_7 >> 16;
                dp_tx_path_records[arg].word_0x18 = low_half;
            }
            dp_tx_path_records[arg].byte_0x25 = 0;
            /* dp_tx_set_video_timing gets a copy of the 28 bytes from +4 (sizes up to word_0x1c). */
            {
                struct path_record *path = &dp_tx_path_records[arg];
                unsigned short timing[14];
                lib_memcpy(timing, &path->line_length, 0x1c);
                dp_tx_set_video_timing(arg, timing);
            }
            break;
        case IPC_CMD_DP_TX_TIMING_PART:
            /* Data byte 0 = DP output, bytes 1 / 2 = byte_0x14 / bits per colour; then programmed again. */
            {
                unsigned int word = msg->data;
                unsigned char output = word, byte_14 = word >> 8, bpc = word >> 16;
                dp_tx_path_records[output].byte_0x14 = byte_14;
                dp_tx_path_records[output].bits_per_colour = bpc;
                port = output;
            }
            {
                struct path_record *path = &dp_tx_path_records[port];
                unsigned short timing[14];
                lib_memcpy(timing, &path->line_length, 0x1c);
                dp_tx_set_video_timing(port, timing);
            }
            break;
        case IPC_CMD_SET_DP_TX_KEEP_REG50:
            port = msg->data;
            arg = msg->data >> 8;
            dp_tx_path_records[port].keep_reg50 = arg;
            {
                struct path_record *path = &dp_tx_path_records[port];
                unsigned short timing[14];
                lib_memcpy(timing, &path->line_length, 0x1c);
                dp_tx_set_video_timing(port, timing);
            }
            break;
        case IPC_CMD_SET_DP_TX_KEEP_TIMING:
            port = msg->data;
            arg = msg->data >> 8;
            dp_tx_path_records[port].keep_timing = arg;
            {
                struct path_record *path = &dp_tx_path_records[port];
                unsigned short timing[14];
                lib_memcpy(timing, &path->line_length, 0x1c);
                dp_tx_set_video_timing(port, timing);
            }
            break;
        case IPC_CMD_SET_DP_TX_PATH_BIT30:
            /* Only stored; nothing is programmed. */
            port = msg->data;
            arg = msg->data >> 8;
            dp_tx_path_records[port].bit30 = arg;
            break;
        case IPC_CMD_OUTPUT_FLAG_BIT31:
            port = msg->data;
            arg = msg->data >> 8;
            dp_tx_path_records[port].reg70_bit4 = arg;
            dp_tx_set_reg70_bit4(port, dp_tx_path_records[port].reg70_bit4);
            break;
        case IPC_CMD_GET_DP_TX_REG70_BIT4:
            reply[0] = dp_tx_get_reg70_bit4(msg->data);
            has_reply = 1;
            break;
        case IPC_CMD_OUTPUT_REQUEST_FLAGS:
            /* Data byte 0 = DP output, bytes 1..2 = action flags added to its pending ones. */
            dp_tx_post_action_flags(msg->data, msg->data >> 8);
            break;
        case IPC_CMD_SET_DP_TX_DRIVE_LEVELS:
            /* Data byte 0 = DP output; data bytes 4 + 2 * lane and 5 + 2 * lane = swing and pre-emphasis of
             * lanes 0..3. The selector passed on is output | lane << 4. */
            arg = msg->data;
            for (i = 0; i < DP_TX_LANES; i++)
            {
                unsigned int lane_word = msg->more[i >> 1];
                unsigned char shift = (i & 1) * 16;
                arg1 = lane_word >> shift;
                arg2 = lane_word >> (shift + 8);
                dp_tx_set_drive_level_base((arg & 0xf) | (i << 4), arg1, arg2);
            }
            break;
        case IPC_CMD_WRITE_DP_TX_REG57:
            dp_tx_write_reg57_latched(msg->data, msg->data >> 8);
            break;
        case IPC_CMD_SET_DP_TX_REG70_BIT5:
            port = msg->data;
            arg = msg->data >> 8;
            dp_tx_path_records[port].reg70_bit5 = arg;
            dp_tx_set_reg70_bit5(port, arg);
            break;
        case IPC_CMD_CHECK_HDCP_STORED_KEYS:
            reply[0] = hdcp_tx_check_stored_keys(msg->data);
            has_reply = 1;
            break;
        case IPC_CMD_IS_DP_TX_LINK_ACTIVE:
            reply[0] = dp_tx_is_link_active(msg->data);
            has_reply = 1;
            break;
        case IPC_CMD_SET_HDCP_TX_DP_BYPASS:
            /* Data byte 1 = bypass on or off. The reply carries only zeros. */
            hdcp_tx_dp_set_bypass(msg->data >> 8);
            has_reply = 1;
            break;
        case IPC_CMD_SET_EVENT_CLEAR_MASK:
            /* Event bits that ipc_publish_port_status clears after it has published them. */
            input_event_clear_mask = msg->data;
            break;
        case IPC_CMD_POWER_DOWN_FOR_SAVING:
            /* Sink of DP output 0 to power-save, receivers off (mode 1), status flag 6 published, then stop.
             * irq_set_mask_preset(1) comes before the power-off, irq_set_mask_preset(0) after it. */
            dp_tx_set_sink_power(DP_TX_OUTPUT_0, SINK_POWER_SAVE);
            irq_set_mask_preset(1);
            input_power_off_receivers_mode1();
            ipc_status_flag_6 = 1;
            ipc_publish_status_flags();
            irq_set_mask_preset(0);
            for (;;)
                ;
        case IPC_CMD_SET_DP_RX_SETTING_11F:
            /* byte_0x11f, then the whole set-up of the DP receiver again. */
            port = msg->data;
            dp_input_records[port].byte_0x11f = msg->data >> 8;
            dp_init_port(port, 0);
            break;
        case IPC_CMD_ACK_PORT_CHANGE:
            /* Clear the port change bits named in data byte 0 from bits 16..23 of status word 3 (slot 0). */
            {
                unsigned int bits = msg->data;
                unsigned int status = 0;
                ipc_read_mailbox_slot(IPC_SLOT_STATUS, IPC_STATUS_WORD, &status, 1);
                status = (status & ~PORT_CHANGE_BITS) | (((status >> 16) & ~bits & 0xff) << 16);
                ipc_write_mailbox_slot(IPC_SLOT_STATUS, IPC_STATUS_WORD, &status, 1);
            }
            break;
        case IPC_CMD_SET_STATUS_BLOCK_BYTE:
            /* Data byte 1 stored at index data byte 0 of the byte block 0xA80788D0. */
            ARR_a80788d0[(unsigned char)msg->data] = msg->data >> 8;
            break;
        case IPC_CMD_GET_INPUT_STATUS_BYTE:
            /* Data byte 0 = input: the second CVTEM field of an HDMI 2.1 input, bit 3 of indirect register 8
             * of a DP input, 0 for the HDMI 2.0 inputs. */
            switch ((unsigned char)msg->data) {
            case INPUT_HDMI20_0:
            case INPUT_HDMI20_1:
                reply[0] = 0;
                break;
            case INPUT_HDMI21_0:
                reply[0] = hdmi_rx21_get_cvtem_flag(0);
                break;
            case INPUT_HDMI21_1:
                reply[0] = hdmi_rx21_get_cvtem_flag(1);
                break;
            case INPUT_DP_0:
                reply[0] = dp_get_msa_bit3(0);
                break;
            case INPUT_DP_1:
                reply[0] = dp_get_msa_bit3(1);
                break;
            }
            has_reply = 1;
            break;
        case IPC_CMD_GET_HDMI21_FRL_RATE:
            /* Data byte 0 = input 2 or 3; any other input answers 0. */
            arg = msg->data;
            reply[0] = 0;
            switch (arg) {
            case INPUT_HDMI21_0:
                reply[0] = hdmi_rx21_lts_record0_byte1;
                break;
            case INPUT_HDMI21_1:
                reply[0] = hdmi_rx21_lts_record1_byte1;
                break;
            }
            has_reply = 1;
            break;
        case IPC_CMD_GET_INPUT_SETTING_BYTE:
            /* Data byte 0 = input: the first CVTEM field of an HDMI 2.1 input, 8 for the DP inputs, 0 for the
             * HDMI 2.0 inputs. */
            switch ((unsigned char)msg->data) {
            case INPUT_HDMI20_0:
            case INPUT_HDMI20_1:
                reply[0] = 0;
                break;
            case INPUT_HDMI21_0:
                reply[0] = hdmi_rx21_get_cvtem_code(0);
                break;
            case INPUT_HDMI21_1:
                reply[0] = hdmi_rx21_get_cvtem_code(1);
                break;
            case INPUT_DP_0:
            case INPUT_DP_1:
                reply[0] = CVTEM_CODE_DP;
                break;
            }
            has_reply = 1;
            break;
        case IPC_CMD_LINK_TEST_82:
            for (i = 0; i < REPLY_BYTES; i++)
                reply[i] = i;
            has_reply = 1;
            break;
        case IPC_CMD_GET_HDMI_PORT_STATUS:
            /* Data byte 0 = HDMI input 0..3, data byte 1 = what to answer. */
            {
                unsigned char rx = msg->data;
                unsigned char is_hdmi21 = 0;
                unsigned char sub = msg->data >> 8;
                if ((unsigned char)msg->data >= INPUT_HDMI21_0) {
                    rx = msg->data - INPUT_HDMI21_0;
                    is_hdmi21 = 1;
                }
                switch (sub) {
                case PORT_STATUS_BIT:
                    /* Bit 17 of status register 4 (HDMI 2.1) or bit 0 of register 6 (HDMI 2.0), as 0 or 1. */
                    if (!(is_hdmi21 ? hdmi_rx21_status04_bit17(rx) : hdmi_get_reg6_bit0(rx)))
                        reply_ptr[0] = 0;
                    else
                        reply_ptr[0] = 1;
                    break;
                case PORT_STATUS_FRL:
                    /* The FRL test result is not used: the answer is six zero bytes. */
                    if (is_hdmi21)
                        hdmi_rx21_is_frl_mode(rx);
                    reply_ptr[0] = 0;
                    reply_ptr[1] = 0;
                    reply_ptr[2] = 0;
                    reply_ptr[3] = 0;
                    reply_ptr[4] = 0;
                    reply_ptr[5] = 0;
                    break;
                }
            }
            has_reply = 1;
            break;
        case IPC_CMD_LINK_TEST_84:
            for (i = 0; i < REPLY_BYTES; i++)
                reply[i] = i;
            has_reply = 1;
            break;
        case IPC_CMD_PING:
            /* dp_tx_option_enabled_stub_copy always returns 1. */
            has_reply = 1;
            reply[0] = dp_tx_option_enabled_stub_copy();
            break;
        case IPC_CMD_LINK_TEST_85:
            for (i = 0; i < REPLY_BYTES; i++)
                reply[i] = i;
            has_reply = 1;
            break;
        case IPC_CMD_SET_DP_RX_REG252_BITS:
            /* Data byte 0 = DP receiver; bits 8..10 of the data word become bits 5..7 of register 0x252. */
            dp_reg_write8(msg->data, DP_RX_REG252, (msg->data >> 3) & 0xe0);
            break;
        case IPC_CMD_SET_DSC_DEC_COMMAND:
            /* Picked up by the DSC decoder state machine (sys_dsc_dec_run_state). */
            sys_dsc_dec_command_value = msg->data;
            sys_dsc_dec_restart_flag = 1;
            break;
        case IPC_CMD_GET_INPUT_TIMING:
            /* Reply = the eight timing values of the input in data byte 0. */
            input_read_port_timing(msg, reply);
            has_reply = 1;
            break;
        case IPC_CMD_SET_HDCP_RX_PORT_OPTION:
            hdcp_rx_set_port_option(msg->data >> 8, msg->data);
            break;
        case IPC_CMD_SET_DP_TX_LINK_LIMITS:
            /* Data byte 0 = DP output. Byte 1 bits 0..1 = control register 8 mode, bit 2 = control register
             * 9 bit 3; byte 4 = maximum link rate code, byte 5 = maximum lane count code, byte 9 bit 0 = link
             * option. For the eDP outputs (1..4) bytes 2, 6, 7 and 8 also set the lane route byte, the first
             * and last eDP output and the output map. The limits are then passed on. */
            port = msg->data;
            dp_tx_path_records[port].ctl_reg8_mode = msg->data >> 8;
            dp_tx_path_records[port].ctl_reg9_bit3 = (unsigned char)(msg->data >> 8) >> 2;
            if (port != DP_TX_OUTPUT_0)
                dp_tx_lane_route_byte = msg->data >> 16;
            dp_tx_path_records[port].max_link_rate = msg->more[0];
            dp_tx_path_records[port].max_lane_count = msg->more[0] >> 8;
            if (port != DP_TX_OUTPUT_0) {
                dp_tx_edp_first_output = msg->more[0] >> 16;
                dp_tx_edp_last_output = msg->more[0] >> 24;
                dp_tx_output_map = msg->more[1];
            }
            dp_tx_path_records[port].link_option = (unsigned char)(msg->more[1] >> 8);
            dp_tx_set_ctl_reg9_bit3(port, dp_tx_path_records[port].ctl_reg9_bit3);
            dp_tx_set_ctl_reg8_bits67(port, dp_tx_path_records[port].ctl_reg8_mode);
            dp_tx_set_max_link_rate(port, dp_tx_path_records[port].max_link_rate);
            dp_tx_set_max_lane_count(port, dp_tx_path_records[port].max_lane_count);
            dp_tx_set_link_option(port, dp_tx_path_records[port].link_option);
            break;
        case IPC_CMD_CONFIGURE_DSC_ENCODER:
            sys_dsc_enc_configure(msg);
            break;
        case IPC_CMD_SET_DP_TX_REG11_MODE:
            arg = msg->data >> 8;
            dp_tx_set_reg11_mode(msg->data, arg);
            break;
        case IPC_CMD_REQUEST_DP_TX_PACING_UPDATE:
            port = msg->data;
            if (port < DP_TX_OUTPUTS)
                dp_tx_request_pacing_update(port);
            break;
        case IPC_CMD_SET_DP_TX_FASTMUTE_PATTERN:
            arg = msg->data >> 8;
            dp_tx_set_fastmute_pattern(msg->data, arg);
            break;
        case IPC_CMD_SET_EDP_HPD_ENABLE:
            /* When the eDP HPD handling is switched off, each eDP output 1..4 whose mode update the main
             * processor requested (input_command_flags bits 3..6) gets a forced HPD check. */
            {
                unsigned int word = msg->data;
                dp_tx_edp_hpd_enable = word;
                if ((unsigned char)word == 0) {
                    if (dp_tx_mode_requested_1())
                        dp_tx_force_hpd_check(1);
                    if (dp_tx_mode_requested_2())
                        dp_tx_force_hpd_check(2);
                    if (dp_tx_mode_requested_3())
                        dp_tx_force_hpd_check(3);
                    if (dp_tx_mode_requested_4())
                        dp_tx_force_hpd_check(4);
                }
            }
            break;
        case IPC_CMD_SET_HDR_PEAK_LUMINANCE:
            /* Data bytes 0..1 = peak luminance; both halves of the word are also kept. */
            ipc_command_0x76_low = msg->data;
            hdr_set_peak_luminance(msg->data);
            ipc_command_0x76_high = msg->data >> 16;
            break;
        case IPC_CMD_SELECT_HDR_SOURCE:
            /* Data byte 0 = port code 0x31..0x81, passed on as index 0..5. */
            hdr_select_source(input_decode_port_code(msg->data));
            break;
        case IPC_CMD_SET_HDR_SOURCE_ENABLE:
            hdr_set_source_disable_bit(input_decode_port_code(msg->data), msg->data >> 8);
            break;
        case IPC_CMD_GET_HDR_STATUS:
            has_reply = 1;
            reply[0] = hdr_get_status_code();
            break;
        case IPC_CMD_SET_HDR_ENABLE:
            hdr_set_enable(msg->data);
            break;
        case IPC_CMD_REQUEST_HDR_RELOAD:
            hdr_request_reload();
            break;
        case IPC_CMD_SET_HDR_MODE_BYTE:
            hdr_set_mode_byte(msg->data);
            break;
        case IPC_CMD_RELOAD_HDR_TONE_CURVE:
            hdr_request_curve_table_reload();
            hdr_init(0);
            break;
        case IPC_CMD_SET_HDR_OPTION_BYTE:
            hdr_set_option_byte(msg->data);
            break;
        case IPC_CMD_GET_DP_RX_REG3D0_VALUE:
            /* Data byte 0 = input: 4 and 6..8 read DP receiver 0, 5 reads receiver 1, others give 0. Reply
             * bytes 0..2 = the 24-bit value, low byte first; the value is also kept in dp_reg3d0_value. */
            switch ((unsigned char)msg->data) {
            case INPUT_DP_0:
            case INPUT_DP_0_FIELD_1:
            case INPUT_DP_0_FIELD_2:
            case INPUT_DP_0_FIELD_3:
                dp_reg3d0_value = dp_read_reg3d0_value(0);
                break;
            case INPUT_DP_1:
                dp_reg3d0_value = dp_read_reg3d0_value(1);
                break;
            default:
                dp_reg3d0_value = 0;
                break;
            }
            reply[0] = dp_reg3d0_value;
            reply[1] = dp_reg3d0_value >> 8;
            reply[2] = dp_reg3d0_value >> 16;
            reply[3] = 0;
            has_reply = 1;
            break;
        case IPC_CMD_SET_COMMAND_FLAGS:
            input_set_command_flags(msg->data);
            break;
        case IPC_CMD_APPLY_PORT_ENABLE_MASK:
            input_apply_port_enable_mask(msg->data);
            break;
        case IPC_CMD_SET_PORT_OPTION_MASK:
            input_set_port_option_mask(msg->data);
            break;
        case IPC_CMD_POWER_DOWN:
            /* As command 0x72 with receiver power-off mode 0, after the print. */
            dbg_printf("_SetLeonSPowerDown %d\r\n", POWER_DOWN_PRINT);
            dp_tx_set_sink_power(DP_TX_OUTPUT_0, SINK_POWER_SAVE);
            irq_set_mask_preset(1);
            input_power_off_receivers_mode0();
            ipc_status_flag_6 = 1;
            ipc_publish_status_flags();
            irq_set_mask_preset(0);
            for (;;)
                ;
        case IPC_CMD_GET_HDMI_TX_STATUS_BIT31:
            /* Only a port 0 or 1 gets an answer. */
            port = msg->data;
            if (port < HDMI_TX_PORTS) {
                has_reply = 1;
                reply[0] = hdmi_tx_get_status_bit31(port) & 1;
            }
            break;
        case IPC_CMD_SET_HDMI_TX_REG0D_BIT2:
            port = msg->data;
            arg = msg->data >> 8;
            if (port < HDMI_TX_PORTS)
                hdmi_tx_set_reg0d_bit2(port, arg);
            break;
        case IPC_CMD_SET_HDMI_PHY_OPTION_BYTE:
            hdmi_phy_records[(unsigned char)msg->data].option_byte = msg->data >> 8;
            break;
        case IPC_CMD_SET_HDMI21_PORT_MASK:
            /* Data byte 0 = input (2 or 3 = HDMI 2.1 receiver 0 or 1), byte 1 = 1 to set, byte 2 = mask. Any
             * other input, or byte 1 not 1, clears the mask bits on both receivers. */
            {
                unsigned int word = msg->data;
                unsigned char input = word, receiver;
                arg1 = word >> 8;
                arg2 = word >> 16;
                receiver = 0;
                if (input != INPUT_HDMI21_0)
                    receiver = input == INPUT_HDMI21_1 ? 1 : 0xff;
                if (arg1 == 1 && receiver != 0xff)
                    hdmi_rx21_set_mask_bits(receiver, arg2);
                else
                    hdmi_rx21_clear_mask_bits(arg2);
            }
            break;
        case IPC_CMD_CONFIGURE_AUDIO:
            /* Repack data bytes 0..3 into the three configuration bytes (see struct audio_config_arg). */
            {
                struct audio_config_arg cfg;
                unsigned int word = msg->data;
                unsigned char byte0;
                cfg.bit7 = word & 1;
                byte0 = word;
                cfg.bit6 = byte0 >> 1;
                cfg.bit5 = byte0 >> 2;
                cfg.bit4 = byte0 >> 3;
                cfg.bit3 = byte0 >> 4;
                cfg.bit2 = byte0 >> 5;
                cfg.bit1 = byte0 >> 6;
                cfg.bit0 = byte0 >> 7;
                cfg.byte_2 = word >> 8;
                cfg.bits_6_7 = word >> 16;
                cfg.bits_4_5 = word >> 24;
                audio_configure(cfg);
            }
            break;
        case IPC_CMD_SET_AUDIO_MUTE:
            audio_mute_value = msg->data;
            audio_set_mute(audio_mute_value);
            break;
        case IPC_CMD_ROUTE_AUDIO_SOURCE:
            /* Data bytes 0..3 = source, output, audio unit, enable. */
            {
                unsigned int word = msg->data;
                unsigned char source = word, enable = word >> 24;
                arg1 = word >> 8;
                arg2 = word >> 16;
                audio_route_source(source, arg1, arg2, enable);
            }
            break;
        case IPC_CMD_SET_AUDIO_UNIT_FREQUENCY:
            audio_set_unit_frequency(msg->data, msg->data >> 8);
            break;
        case IPC_CMD_SET_AUDIO_LEVEL:
            /* Data byte 0 = 0 for the main output, 1 for all receivers; bytes 1..2 = level. */
            {
                unsigned int word = msg->data;
                unsigned char sub = word;
                unsigned short level = word >> 8;
                if (sub == AUDIO_LEVEL_INPUTS)
                    audio_set_input_levels(level, 1);
                else if (sub == AUDIO_LEVEL_OUTPUT)
                    audio_set_output_level(level);
            }
            break;
        case IPC_CMD_CLEAR_AUDIO_LEVEL_STEPS:
            audio_clear_level_step();
            break;
        case IPC_CMD_WRITE_HDMI_PHY_REG:
            /* Data byte 0 = PHY, bytes 1..2 = register, byte 3 = value. */
            hdmi_phy_write_reg(msg->data, msg->data >> 8, msg->data >> 24);
            break;
        case IPC_CMD_WRITE_HDMI_RX_REG:
            /* Data byte 0 = input 0..3, bytes 1..2 = register, byte 3 = value. */
            {
                unsigned int word = msg->data;
                unsigned short reg = word >> 8;
                unsigned char value = word >> 24;
                if ((unsigned char)word > INPUT_HDMI20_1)
                    hdmi_rx21_reg_write8(word - INPUT_HDMI21_0, reg, value);
                else
                    hdmi_reg_write8(word, reg, value);
            }
            break;
        case IPC_CMD_READ_HDMI_RX_REG:
            {
                unsigned int word = msg->data;
                unsigned short reg = word >> 8;
                if ((unsigned char)word > INPUT_HDMI20_1)
                    reply[0] = hdmi_rx21_reg_read8(word - INPUT_HDMI21_0, reg);
                else
                    reply[0] = hdmi_reg_read8(word, reg);
            }
            has_reply = 1;
            break;
        case IPC_CMD_READ_INFOFRAME:
            /* Data byte 0 = HDMI 2.0 receiver, byte 1 = InfoFrame type; the reply is the 28 bytes. */
            hdmi_read_infoframe(msg->data, msg->data >> 8, reply);
            has_reply = 1;
            break;
        case IPC_CMD_WRITE_HDMI_TX_REG:
            /* Data byte 0 = HDMI TX port, byte 1 = bank, bytes 2..3 = register, byte 4 = value. */
            {
                unsigned int word = msg->data;
                unsigned char tx = word;
                arg1 = word >> 8;
                hdmi_tx_reg_write8(tx, arg1, word >> 16, msg->more[0]);
            }
            break;
        case IPC_CMD_WRITE_DP_RX_PAGED_REG:
            dp_write_port_reg_wrapper(msg->data, msg->data >> 8, msg->data >> 24);
            break;
        case IPC_CMD_WRITE_DP_RX_LOW_REG:
            dp_write_low_reg(msg->data, msg->data >> 8, msg->data >> 24);
            break;
        case IPC_CMD_READ_DP_RX_REG:
            reply[0] = dp_reg_read8(msg->data, msg->data >> 8);
            has_reply = 1;
            break;
        case IPC_CMD_READ_DP_TX_REG:
            reply[0] = dp_tx_reg_read8(msg->data, msg->data >> 8);
            has_reply = 1;
            break;
        case IPC_CMD_WRITE_DP_TX_REG:
            dp_tx_reg_write8(msg->data, msg->data >> 8, msg->data >> 24);
            break;
        case IPC_CMD_OSD_UNZIP:
            /* The four words and the mode (low byte of more[3]) for osd_run_pending_unzip. */
            osd_request_unzip(msg->data, msg->more[0], msg->more[1], msg->more[2], msg->more[3]);
            break;
        case IPC_CMD_CLEAR_STATUS_FLAGS:
            /* Data byte 0 = which of the published status flags to clear; port holds the bits here. */
            port = msg->data;
            if (port & CLEAR_HDMI_TX0_SINK_FLAG)
                hdmi_tx_sink_flags = 0;
            if (port & CLEAR_HDMI_TX1_SINK_FLAG)
                hdmi_tx_sink_flag_port1 = 0;
            if (port & CLEAR_DP_TX_HPD_FLAG)
                dp_tx_hpd_flag = 0;
            break;
        case IPC_CMD_SET_DSC_ENCODER_PARAMETERS:
            sys_dsc_enc_set_parameters(msg);
            break;
        case IPC_CMD_RESTART_DP_UNIT:
            dp_unit_restart(msg->data, 0);
            break;
        case IPC_CMD_PRINT_TIMING_CHANGE:
            dbg_printf("=====AT Prepare Timing Change %08lX %08lX %08lX=====\r\n", msg->data, msg->more[0], msg->more[1]);
            break;
        }

        /* Phase 4. */
        if (has_reply)
            ipc_send_reply(command, REPLY_BYTES, reply);

        /* Phase 5: the command slot is free again. */
        {
            unsigned int free_word = 0;
            ipc_write_mailbox_slot(IPC_SLOT_COMMAND, 0, &free_word, 1);
        }

        /* Phase 6. */
        REG_CF03D004 = saved_regs[0];
        REG_CF03D008 = saved_regs[1];
        REG_CF03D00C = saved_regs[2];
        REG_CF03D010 = saved_regs[3];
    }
}
