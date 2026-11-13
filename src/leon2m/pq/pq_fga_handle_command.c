/* pq_fga_handle_command  (FUN_a012d554)
 *
 * Carry out one calibration command received over DDC/CI.
 * Name basis: derived - action chosen by a byte of the request; FGA writes, brightness, picture windows;
 *   called from the DDC/CI request handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012d554 @ 0xa012d554-0xa012e004 (2736 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the case bodies are written in the order 0x11, 0x17, 0x27, 0x12, 0x13, 0x1C, 0x14, 0x28, 0x2B, 0x29, 0x2E,
 *    0x24, 0x2F (the jump table, 31 entries from 0x11, fixes the block layout; the source order decides the
 *    registers);
 *  - key_index reads the tables as a flat unsigned short array (table[i * 2], table[i * 2 + 1]: index-first
 *    address sum) and passes the flag to a bit-count helper with an unsigned short value and a short mask (the
 *    firmware's copy of the flag and its in-loop mask load); the count is a byte set to 0xff on the no-bit path;
 *  - command 0x27 is an if-chain with one call per arm of req[6] == 0 (merged by cross-jumping);
 *  - pq_fga_write_offset is read and written as an unsigned short and, in command 0x27, as byte pairs indexed by
 *    req[6] (through a cast to union halfword_bytes);
 *  - pq_fga_lum_mode_low_byte is the low byte of the unsigned short pq_fga_lum_mode (a separate label in the build);
 *  - one variable k serves as loop counter and, in command 0x27, as the 16-bit value.
 * fga_off is the static helper of FGA_Init and nvram_write_fga_byte.
 */

/* The FGA block in storage: three fields of the device settings record (see FGA_Init). */
struct fga_location {
    unsigned char fga_selector;     /* +0x34: storage device of the FGA block (nvram_write) */
    unsigned int address : 16;      /* +0x35: start address of the FGA block on that device */
    unsigned char byte_0x37;        /* +0x37: block layout; 0 or 1 puts the marker area 0x120 bytes in, else 0x240 */
};
struct device_settings_record {
    unsigned char bytes_0x00[0x34];
    struct fga_location fga;
    unsigned char rest[0x18];
};

/* The request, as ddc_handle_request receives it for Set VCP feature 0xF1. */
enum {
    REQ_LENGTH  = 1,        /* 0x80 | number of bytes from REQ_OPCODE on */
    REQ_COMMAND = 4,        /* the FGA command below */
    REQ_DATA    = 5         /* first data byte */
};
#define REQ_LENGTH_TO_DATA_COUNT 131    /* 0x80 flag + opcode, VCP code and command byte */

/* FGA commands (request byte 4). Values from 0x11 to 0x2F without an entry do nothing. */
enum fga_command {
    FGA_CMD_WRITE_DATA     = 0x11,  /* 32 data bytes to the FGA block at pq_fga_write_offset */
    FGA_CMD_SET_COLOR      = 0x12,  /* one colour triple, placed by two keys */
    FGA_CMD_SET_PATTERN    = 0x13,  /* the firmware's NVT_FGA_SET_PATTERN: blank picture block 0 in a colour */
    FGA_CMD_BEGIN          = 0x14,  /* save the luminance settings, switch the picture stages off */
    FGA_CMD_SET_ROW        = 0x17,  /* 18 bytes into the colour rows */
    FGA_CMD_SAVE_COLORS    = 0x1c,  /* colour block and colour rows to storage */
    FGA_CMD_DONE           = 0x24,  /* restore the picture and the luminance settings, set FGA_STATE_DONE */
    FGA_CMD_LDC            = 0x27,  /* sub-commands by request byte 5 */
    FGA_CMD_SET_DEVICE     = 0x28,  /* storage device of the FGA block */
    FGA_CMD_SET_ADDRESS    = 0x29,  /* start address of the FGA block */
    FGA_CMD_WRITE_MARKER   = 0x2b,  /* one byte to the marker */
    FGA_CMD_SMALL_WINDOW   = 0x2e,  /* luminance mode 0 and the small window 1 */
    FGA_CMD_LUM_MODE_2     = 0x2f   /* luminance mode 2 with the saved gain */
};

/* Sub-commands of FGA_CMD_LDC (request byte 5); the 16-bit value is bytes 7 (low) and 8 (high). */
enum {
    LDC_SUB_SEND_VALUE  = 0x00,     /* ldc_api_send_cmd_0x31_sub1(value) */
    LDC_SUB_STORE_VALUE = 0x01,     /* value into halfword req[6] from pq_fga_write_offset on, low byte first */
    LDC_SUB_MODE        = 0xfe,     /* ldc_api_set_mode_byte(req[6] != 0) */
    LDC_SUB_WRITE       = 0xff      /* nvram_write of length 0 at marker area + 0x70 */
};

/* Offsets inside the marker area (from fga_off()). */
#define FGA_OFF_MARKER          0x00
#define FGA_OFF_COLOR_BLOCK     0x10
#define FGA_OFF_COLOR_ROWS      0x30
#define FGA_OFF_0X70            0x70

#define FGA_WRITE_CHUNK         0x20
#define FGA_COLOR_BLOCK_SIZE    0x1b    /* 3 rows of 3 colour triples */
#define FGA_COLOR_ROWS_SIZE     0x36    /* 3 rows of 18 bytes */
#define FGA_COLOR_ROW_SIZE      18
#define FGA_MARKER_DATA         0x78    /* marker written when the 32-byte writes reach the marker area */

/* The two key tables map a key byte to one flag bit; the masks say which flags have an entry (as in FGA_Init). */
#define FGA_FIRST_KEY_LAST_ROW  10      /* rows 0..10 of pq_fga_key_table_first (keys 0x10..0x24) */
#define FGA_SECOND_KEY_LAST_ROW 11      /* rows 0..11 of pq_fga_key_table_second */
#define FGA_BLOCK_KEYS          0x508   /* first table: keys 0x16, 0x20, 0x24 = colour block rows 0..2 */
#define FGA_COLOR_KEYS          0x92    /* second table: keys 50, 65, 93 = colour block columns 0..2 */
#define FGA_FIRST_KEY_PART      0x16    /* first key whose colours also go to the part record */
#define KEY_NOT_FOUND           0xff

#define FGA_STATE_DONE          0x20    /* ddc_handle_request prints "APPUserData.bFGADone" while it is set */
#define FGA_STATE_BIT6          0x40    /* set by FGA_CMD_BEGIN, cleared by FGA_CMD_DONE */

#define NVRAM_NO_COMMIT         0       /* last argument of nvram_write; 1 lets a flash-backed area advance */
#define NVRAM_COMMIT            1

#define LEVEL_MAX               0x3ff   /* full level for SetBrightness */
#define RETENTION_BITS_BEGIN    0x126   /* set in the retention registers' value by FGA_CMD_BEGIN */
#define PQ_STAGES_ALL           0xff
#define MAIN_CHANNEL            0

/* Arguments of pq_window_set_rect. */
#define FULL_PANEL_RECT         0, 0, 0xf00, 0x870          /* 3840 x 2160 */
#define FGA_WINDOW_RECT         0x540, 0x2f4, 0x480, 0x288  /* window 1 in FGA_CMD_BEGIN, window 0 in _SAVE_COLORS */
#define FGA_SMALL_WINDOW1_RECT  0x63a, 0x380, 0x28d, 0x16f  /* window 1 in FGA_CMD_SMALL_WINDOW */

/* Registers switched by FGA_CMD_BEGIN (cleared) and FGA_CMD_DONE (set); their function is not shown. */
#define REG_D0013F10            0xd0013f10      /* bit 0 */
#define REG_D0013F50            0xd0013f50      /* bit 31, as the three below */
#define REG_D0013F60            0xd0013f60
#define REG_D0013FD0            0xd0013fd0
#define REG_D0013FE0            0xd0013fe0

extern struct device_settings_record device_settings;
extern unsigned char part_record[];
extern unsigned char pq_fga_state_bits;
extern unsigned char pq_fga_status;
extern unsigned short pq_fga_lum_gain;
extern unsigned short pq_fga_lum_mode;
extern unsigned char pq_fga_lum_mode_low_byte;
extern unsigned short pq_fga_color_offset;
extern unsigned short pq_fga_key_index_second;
extern unsigned short pq_fga_key_index_first;
extern unsigned short pq_fga_saved_flag_registers;
extern unsigned char pq_fga_color_block[];
extern unsigned char pq_fga_color_rows[];
union halfword_bytes { unsigned short h; struct { unsigned char lo, hi; } b; };
extern unsigned short pq_fga_write_offset;
extern unsigned short pq_fga_row_offset;
extern const unsigned short pq_fga_key_table_second[];
extern const unsigned short pq_fga_key_table_first[];
extern void oled_set_lum_mode(unsigned char);
extern void oled_set_lum_gain(unsigned short);
extern void SetBrightness(unsigned short);
extern void pq_window_disable(int);
extern void pq_window_enable(unsigned int);
extern void pq_select_window(unsigned int);
extern void pq_window_set_rect(unsigned short, unsigned short, unsigned short, unsigned short);
extern void pq_window_enable_stages(unsigned int);
extern void pq_window_set_item3(unsigned char);
extern void pq_window_set_item4(unsigned char);
extern void pq_window_set_item5(unsigned char);
extern void pq_block0_set_blank_mode(unsigned char);
extern void oled_flag_registers_write(unsigned short);
extern unsigned short oled_flag_registers_read(void);
extern unsigned char sys_api_get_channel_port_flag6(int);
extern unsigned char sys_api_get_channel_port_flag9(int);
extern unsigned char ipc_api_get_status_field(void);
extern unsigned short oled_get_lum_mode(void);
extern unsigned short oled_get_lum_gain(void);
extern void pq_gamma_disable_primary_lut(void);
extern void pq_gamma_disable_secondary_lut(void);
extern void pq_gamma_disable_first_curve_stage(void);
extern void pq_gamma_disable_second_curve_stage(void);
extern void pq_color_matrix_clear_bit0(void);
extern void pq_color_matrix_clear_option_bit(void);
extern void pq_ace_write_reg_d8(unsigned char);
extern void pq_window_disable_stages(unsigned int);
extern void nvram_erase_area(unsigned char);
extern void pq_block_set_blank_color(int, int, int, int);
extern void ldc_api_set_mode_byte(unsigned char);
extern void ldc_api_send_cmd_0x31_sub1(unsigned short);
extern int dbg_printf(const char *, ...);
extern void nvram_write(unsigned char, unsigned short, unsigned short, void *, unsigned char);

#define REG(a) (*(volatile unsigned int *)(a))

/* Offset of a part of the marker area from the start of the FGA block. */
static unsigned short fga_off(unsigned short sub)
{
    unsigned short area;
    if (device_settings.fga.byte_0x37 <= 1)
        area = 0x120;
    else
        area = 0x240;
    return (area & 0x360) + sub;
}

/* Write one byte to the marker (the code of nvram_write_fga_byte). */
static void write_marker_byte(unsigned char value)
{
    nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + fga_off(FGA_OFF_MARKER), 1, &value, NVRAM_COMMIT);
}

/* The number of mask bits below the flag's bit, or KEY_NOT_FOUND when the flag is not in the mask. */
static unsigned char count_mask_bits_below(unsigned short flag, short mask)
{
    unsigned char b, count;

    count = 0;
    if (!(flag & mask))
        count = 0xff;
    else
        for (b = 0; (flag >> b) != 1; b++)
            if ((mask >> b) & 1)
                count++;
    return count;
}

/* Look a key up in a table of {key, flag} pairs and return the position of its flag among the mask bits.
   A key that is not in rows 0..last_row reads the pair after them. */
static unsigned char key_index(const unsigned short *table, unsigned char last_row, unsigned char key, unsigned short mask)
{
    unsigned char i;

    for (i = 0; i <= last_row; i++)
        if (key == table[i * 2])
            break;
    return count_mask_bits_below(table[i * 2 + 1], mask);
}

/*
 * One FGA command from a DDC/CI Set VCP request with VCP code 0xF1 (called by ddc_handle_request).
 *
 *   req  the request: byte 1 = 0x80 | length, byte 4 = the command (enum fga_command), data from byte 5
 *
 * The commands, by what the code does:
 *   0x11  write 32 data bytes to the FGA block at pq_fga_write_offset and move it on; add the data bytes to the
 *         byte sum pq_fga_status (read back by pq_fga_get_status); when the offset reaches the marker area,
 *         write FGA_MARKER_DATA there and start again at offset 0.
 *   0x12  place a colour triple (bytes 6..8) in the colour block: row by the first key (byte 9), column by the
 *         colour-temperature key (byte 5). For first key 0x16 the triple also goes to the part record entry of
 *         that colour temperature. An unknown key gives KEY_NOT_FOUND, and the store is not checked.
 *   0x13  blank picture block 0 in the colour of bytes 5..7.
 *   0x14  save the OLED luminance mode and gain and the retention registers' value, set full level, switch the
 *         gamma tables, curve stages and colour matrix off, clear the sums and offsets, set window 2 to the
 *         whole panel with items 3..5 at 0 and window 1 to FGA_WINDOW_RECT, and erase the FGA storage area.
 *   0x17  append 18 data bytes to the colour rows (and to the byte sum).
 *   0x1C  write the colour block and the colour rows to storage, reset both offsets; window 1 off, window 0 on
 *         with FGA_WINDOW_RECT.
 *   0x24  unblank, restore the retention value; under the port condition below set the five registers again;
 *         window 2 off, window 0 to the whole panel, restore the luminance mode and gain, set FGA_STATE_DONE.
 *   0x27  value forwarding to the dimming processor and the halfword table (enum above).
 *   0x28, 0x29  set the storage device and the start address of the FGA block.
 *   0x2B  write data byte 5 to the marker.
 *   0x2E, 0x2F  fixed luminance and window settings.
 */
void pq_fga_handle_command(unsigned char *req)
{
    unsigned short k;

    switch (req[REQ_COMMAND]) {
    case FGA_CMD_WRITE_DATA:
        nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + pq_fga_write_offset, FGA_WRITE_CHUNK, req + REQ_DATA, NVRAM_NO_COMMIT);
        pq_fga_write_offset += FGA_WRITE_CHUNK;
        /* The sum covers the data bytes the length byte announces. */
        for (k = 0; k < req[REQ_LENGTH] - REQ_LENGTH_TO_DATA_COUNT; k++)
            pq_fga_status += req[5 + k];
        if (pq_fga_write_offset == fga_off(FGA_OFF_MARKER)) {
            unsigned char marker = FGA_MARKER_DATA;
            nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + pq_fga_write_offset, 1, &marker, NVRAM_COMMIT);
            pq_fga_write_offset = 0;
        }
        break;
    case FGA_CMD_SET_ROW:
        for (k = 0; k < FGA_COLOR_ROW_SIZE; k++) {
            pq_fga_status += req[5 + k];
            pq_fga_color_rows[pq_fga_row_offset + k] = req[5 + k];
        }
        pq_fga_row_offset += FGA_COLOR_ROW_SIZE;
        break;
    case FGA_CMD_LDC:
        if (req[5] == LDC_SUB_SEND_VALUE)
            ldc_api_send_cmd_0x31_sub1((req[8] << 8) + req[7]);
        else if (req[5] == LDC_SUB_STORE_VALUE) {
            k = (req[8] << 8) + req[7];
            ((union halfword_bytes *)&pq_fga_write_offset)[req[6]].b.lo = k;
            ((union halfword_bytes *)&pq_fga_write_offset)[req[6]].b.hi = k >> 8;
        } else if (req[5] == LDC_SUB_MODE) {
            if (req[6] == 0)
                ldc_api_set_mode_byte(0);
            else
                ldc_api_set_mode_byte(1);
        } else if (req[5] == LDC_SUB_WRITE)
            nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + fga_off(FGA_OFF_0X70), 0, &pq_fga_write_offset, NVRAM_NO_COMMIT);
        break;
    case FGA_CMD_SET_COLOR:
        pq_fga_status += req[6] + req[7] + req[8];
        /* Colour block position: row from the first key, column from the colour-temperature key. */
        pq_fga_key_index_first = key_index(pq_fga_key_table_first, FGA_FIRST_KEY_LAST_ROW, req[9], FGA_BLOCK_KEYS);
        pq_fga_key_index_second = key_index(pq_fga_key_table_second, FGA_SECOND_KEY_LAST_ROW, req[5], FGA_COLOR_KEYS);
        pq_fga_color_offset = pq_fga_key_index_first * 9 + pq_fga_key_index_second * 3;
        for (k = 0; k < 3; k++)
            pq_fga_color_block[pq_fga_color_offset + k] = req[6 + k];
        if (req[9] == FGA_FIRST_KEY_PART) {
            /* The part record keeps one triple per colour temperature; 50 / 65 / 93 are the factory menu rows
               Warm 50 / Normal 65 / Cool 93. */
            switch (req[5]) {
            case 0x32: part_record[6] = req[6]; part_record[7] = req[7]; part_record[8] = req[8]; break;             /* 50 */
            case 0x41: part_record[9] = req[6]; part_record[0xa] = req[7]; part_record[0xb] = req[8]; break;         /* 65 */
            case 0x4b: part_record[0xc] = req[6]; part_record[0xd] = req[7]; part_record[0xe] = req[8]; break;       /* 75 */
            case 0x52: part_record[0xf] = req[6]; part_record[0x10] = req[7]; part_record[0x11] = req[8]; break;     /* 82 */
            case 0x5d: part_record[0x12] = req[6]; part_record[0x13] = req[7]; part_record[0x14] = req[8]; break;    /* 93 */
            case 0x73: part_record[0x15] = req[6]; part_record[0x16] = req[7]; part_record[0x17] = req[8]; break;    /* 115 */
            case 0x82: part_record[0x21] = req[6]; part_record[0x22] = req[7]; part_record[0x23] = req[8]; break;    /* 130 */
            }
        }
        break;
    case FGA_CMD_SET_PATTERN:
        pq_block0_set_blank_mode(2);
        pq_block_set_blank_color(0, req[5], req[6], req[7]);
        dbg_printf("NVT_FGA_SET_PATTERN ,%d %d %d\r\n", req[5], req[6], req[7]);
        break;
    case FGA_CMD_SAVE_COLORS:
        nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + fga_off(FGA_OFF_COLOR_BLOCK), FGA_COLOR_BLOCK_SIZE, pq_fga_color_block, NVRAM_NO_COMMIT);
        nvram_write(device_settings.fga.fga_selector, device_settings.fga.address + fga_off(FGA_OFF_COLOR_ROWS), FGA_COLOR_ROWS_SIZE, pq_fga_color_rows, NVRAM_NO_COMMIT);
        pq_fga_write_offset = 0;
        pq_fga_row_offset = 0;
        pq_window_disable(1);
        pq_window_enable(0);
        pq_select_window(0);
        pq_window_set_rect(FGA_WINDOW_RECT);
        break;
    case FGA_CMD_BEGIN:
        /* Keep what FGA_CMD_DONE restores. */
        pq_fga_lum_mode = oled_get_lum_mode();
        pq_fga_lum_gain = oled_get_lum_gain();
        oled_set_lum_mode(1);
        SetBrightness(LEVEL_MAX);
        pq_fga_saved_flag_registers = oled_flag_registers_read();
        /* Switch the picture stages off. */
        pq_gamma_disable_primary_lut();
        pq_gamma_disable_secondary_lut();
        pq_gamma_disable_first_curve_stage();
        pq_gamma_disable_second_curve_stage();
        pq_color_matrix_clear_bit0();
        pq_color_matrix_clear_option_bit();
        pq_fga_state_bits |= FGA_STATE_BIT6;
        pq_fga_status = 0;
        pq_fga_write_offset = 0;
        pq_fga_row_offset = 0;
        pq_ace_write_reg_d8(2);
        oled_flag_registers_write(pq_fga_saved_flag_registers | RETENTION_BITS_BEGIN);
        REG(REG_D0013F10) &= ~1;
        REG(REG_D0013F50) &= 0x7fffffff;
        REG(REG_D0013F60) &= 0x7fffffff;
        REG(REG_D0013FD0) &= 0x7fffffff;
        REG(REG_D0013FE0) &= 0x7fffffff;
        /* Window 2: the whole panel; window 1: FGA_WINDOW_RECT. */
        pq_window_disable_stages(PQ_STAGES_ALL);
        pq_window_disable(0);
        pq_window_enable(2);
        pq_select_window(2);
        pq_window_set_rect(FULL_PANEL_RECT);
        pq_window_enable_stages(2);
        pq_window_set_item3(0);
        pq_window_set_item4(0);
        pq_window_set_item5(0);
        pq_window_enable(1);
        pq_select_window(1);
        pq_window_set_rect(FGA_WINDOW_RECT);
        SetBrightness(LEVEL_MAX);
        nvram_erase_area(device_settings.fga.fga_selector);
        pq_fga_state_bits &= ~FGA_STATE_DONE;
        break;
    case FGA_CMD_SET_DEVICE:
        device_settings.fga.fga_selector = req[5];
        break;
    case FGA_CMD_WRITE_MARKER:
        write_marker_byte(req[5]);
        break;
    case FGA_CMD_SET_ADDRESS:
        device_settings.fga.address = req[5] | req[6] << 8;
        break;
    case FGA_CMD_SMALL_WINDOW:
        oled_set_lum_mode(0);
        SetBrightness(LEVEL_MAX);
        pq_window_disable(0);
        pq_window_enable(2);
        pq_select_window(2);
        pq_window_set_rect(FULL_PANEL_RECT);
        pq_window_enable_stages(2);
        pq_window_set_item3(0);
        pq_window_set_item4(0);
        pq_window_set_item5(0);
        pq_window_enable(1);
        pq_select_window(1);
        pq_window_set_rect(FGA_SMALL_WINDOW1_RECT);
        break;
    case FGA_CMD_DONE:
        pq_block0_set_blank_mode(0);
        oled_flag_registers_write(pq_fga_saved_flag_registers);
        /* The registers come back on only for a channel-0 port with flag 6 and a non-zero mailbox status field,
           or with flag 9. */
        if ((sys_api_get_channel_port_flag6(0) == 1 && ipc_api_get_status_field()) || sys_api_get_channel_port_flag9(0)) {
            REG(REG_D0013F10) |= 1;
            REG(REG_D0013F50) |= 0x80000000;
            REG(REG_D0013F60) |= 0x80000000;
            REG(REG_D0013FD0) |= 0x80000000;
            REG(REG_D0013FE0) |= 0x80000000;
        }
        pq_window_disable(2);
        pq_select_window(0);
        pq_window_set_rect(FULL_PANEL_RECT);
        oled_set_lum_mode(pq_fga_lum_mode_low_byte);     /* low byte of the mode saved by FGA_CMD_BEGIN */
        oled_set_lum_gain(pq_fga_lum_gain);
        pq_fga_state_bits = (pq_fga_state_bits | FGA_STATE_DONE) & ~FGA_STATE_BIT6;
        break;
    case FGA_CMD_LUM_MODE_2:
        oled_set_lum_mode(2);
        oled_set_lum_gain(pq_fga_lum_gain);
        break;
    }
}
