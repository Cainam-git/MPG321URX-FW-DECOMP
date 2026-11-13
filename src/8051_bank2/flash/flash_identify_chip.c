/* flash_identify_chip  (FUN_CODE_0003)
 *
 * Identify the SPI flash chip from its JEDEC ID and load its parameter record.
 * Returns: 0 found, 2 unknown chip
 * Note: Record copied to 0x0640; byte 4 = size code used by the write loops.
 * Name basis: proven - sends 9Fh (JEDEC Read ID); chip table CODE 0xCB8C (ids
 *   EF4018/EF4019/C22019/1C7019/C84019)
 *
 * Matching notes
 * --------------
 * One Keil C51 module, OPTIMIZE(8,SPEED) LARGE, holding flash_identify_chip, fwupd_svc_spi_transfer,
 * fwupd_svc_read_reply, fwupd_svc_send_cmd_0x0f, fwupd_svc_send_rec_cbcc, fwupd_svc_write_register,
 * fwupd_svc_query_cmd_0x36, fwupd_svc_claim_link, fwupd_svc_erase_flash and fwupd_run_isp_write.
 * Keil's "reuse of common entry code" emits these blocks in front of the callees (all byte-exact with this file):
 *   fwupd_svc_read_reply_entry @ 0xe4b9 in front of fwupd_svc_read_reply: R3:R2:R1 = generic pointer to fwupd_svc_packet, shared
 *     by the fwupd_svc_read_reply(fwupd_svc_packet) calls of fwupd_svc_write_register, fwupd_svc_query_cmd_0x36,
 *     fwupd_svc_claim_link and fwupd_svc_erase_flash;
 *   fwupd_svc_send_cmd_0x0f_entry @ 0xe1b5 in front of fwupd_svc_send_cmd_0x0f: R7 = (unsigned char)(pos >> 4) (pos in R4:R5), from
 *     fwupd_svc_erase_flash;
 *   fwupd_svc_send_rec_cbcc_entry @ 0xdf76 in front of fwupd_svc_send_rec_cbcc: R7 = low byte of pos (XDATA 0x08F2), R5 = R7 + 0x0E;
 *   fwupd_svc_write_register_entry1 @ 0xda66 and fwupd_svc_write_register_entry2 @ 0xda86 in front of fwupd_svc_write_register, from its calls in
 *     flash_identify_chip and fwupd_svc_spi_transfer.
 * The local 'pos' of fwupd_svc_erase_flash is a block operand: no local of another routine of this module may carry
 * that name (block operands are resolved by name).
 *
 * Source forms the exact build depends on:
 *   - fwupd_svc_send_rec_cbcc copies the record as a struct (an initialised local array compiles to the same
 *     instructions, but its init image cannot be placed, so record and copy use their addresses).
 *   - fwupd_svc_erase_flash: 'if (x == 0x10) e331(8); else e331(0);' (a ?: gives MOV R7,#0 instead of
 *     CLR A / MOV R7,A); '(x << 8) >> 3' gives the 3-step RRC loop (x << 5 gives MUL AB).
 *   - fwupd_run_isp_write: 'fwupd_svc_erase_flash(mode);' is written at the end of both branches of the bit 2 / bit 3
 *     test. Keil joins the two copies of that call (0xA9CC) and keeps the two copies of
 *     'write_protect_off(); read_reply(); timer_delay_units(10);' (0xA9B4 and 0xA9C1) as the firmware does; with the
 *     call written once after the if / else Keil also merges the three calls of the inner block into the else branch
 *     (405 of 416 bytes).
 */
#include <absacc.h>

/* The service link: I2C packets on the update agent's I2C bus, all to one slave address. Packet byte 0 is the
 * number of bytes that follow, byte 1 the command. */
#define SVC_ADDRESS             0x6e    /* I2C slave address of every service packet */
#define SVC_CMD_WRITE_REG       0x78    /* 04 78 <reg high byte> <reg byte> <value> */
#define SVC_REG_SPI_WINDOW      0xa700  /* register window that holds the SPI bytes of fwupd_svc_spi_transfer */
#define SVC_SPI_READ_BACK       0x10    /* bytes read back from the window after a transfer */
#define SVC_REG_CHIP_ROW_BYTE2  0xf067  /* gets byte 2 of the identified chip's table row */
#define SVC_REG_ID_TRY          0xf068  /* gets flash_id_try_values[try] before each id read */
#define SVC_REG_ID_BYTES        0xf064  /* 0xF064..0xF066: the three id bytes read after each try */

#define FLASH_CMD_READ_ID       0x9f    /* JEDEC Read ID */
#define FLASH_ID_TRIES          3
#define CHIP_NOT_FOUND          0xff    /* returned by both table lookups */
#define CHIP_ROW_BYTE_F067      2       /* row byte written to SVC_REG_CHIP_ROW_BYTE2 */
#define CHIP_TABLE              ((void code *)0xcb8c)   /* = flash_chip_table, passed as a plain address */

#define IDENTIFY_OK             0
#define IDENTIFY_UNKNOWN_CHIP   2

extern unsigned char code flash_id_try_values[];
void fwupd_svc_spi_transfer(unsigned char *spi_bytes, unsigned char part1_len, unsigned char part2_len);
unsigned char flash_lookup_jedec_id(unsigned char *buf, void *tbl);
unsigned char flash_lookup_chip_id(unsigned char *buf, void *tbl);
/* One row of flash_chip_table (8 bytes). Byte 2 goes to SVC_REG_CHIP_ROW_BYTE2, byte 4 is the size code
 * (fwupd_flash_size_code), bytes 5..7 are the three id bytes the lookups compare. */
struct flash_chip_row { unsigned char bytes[8]; };
extern struct flash_chip_row code flash_chip_table[];
extern struct flash_chip_row xdata fwupd_flash_chip_row;
extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply(unsigned char *buf);
unsigned char fwupd_svc_write_register(unsigned int reg, unsigned char val);
void fwupd_svc_query_cmd_0x11(void);
unsigned char fwupd_svc_read_register(unsigned int reg);

/* Find out which flash chip is fitted and copy its row of flash_chip_table to fwupd_flash_chip_row (XDATA 0x0640),
 * where the erase and write code reads it (byte 4 = fwupd_flash_size_code, XDATA 0x0644).
 *
 * Phases, in order:
 *   1. Read ID: the command byte 0x9F goes out through the SPI registers (fwupd_svc_spi_transfer); the reply is
 *      read back into 'reply'.
 *   2. Direct lookup: when reply bytes 3 and 4 are EF 40, reply bytes 3..5 are looked up in flash_chip_table
 *      (flash_lookup_jedec_id, exact order). A hit goes straight to phase 4 and returns. A miss falls through to
 *      phase 3, like any other reply.
 *   3. Up to three tries: write flash_id_try_values[try] to register 0xF068, send service command 0x11, read the
 *      three bytes of registers 0xF064..0xF066 and look them up with flash_lookup_chip_id (the three bytes in any
 *      order). The first hit ends the tries.
 *   4. On a hit: copy the row to fwupd_flash_chip_row and write its byte 2 to register 0xF067.
 * Returns IDENTIFY_OK (0) with a chip found, IDENTIFY_UNKNOWN_CHIP (2) without; on 2 fwupd_flash_chip_row keeps its
 * old contents.
 * Called by fwupd_run_isp_write after it has taken the service link (fwupd_svc_claim_link(1)).
 */
unsigned char flash_identify_chip(void)
{
    unsigned char byte_index, attempt, row;
    unsigned char reply[16];
    unsigned char result;

    /* 1. Read ID through the SPI registers. */
    reply[0] = 1;
    reply[1] = 3;
    reply[2] = FLASH_CMD_READ_ID;
    fwupd_svc_spi_transfer(reply, 2, 1);

    /* 2. Direct lookup for an id that starts EF 40. */
    if (reply[3] == 0xef && reply[4] == 0x40) {
        row = flash_lookup_jedec_id(reply, CHIP_TABLE);
        if (row == CHIP_NOT_FOUND) {
            result = IDENTIFY_UNKNOWN_CHIP;     /* and on to the tries below */
        } else {
            result = IDENTIFY_OK;
            fwupd_flash_chip_row = flash_chip_table[row];
            fwupd_svc_write_register(SVC_REG_CHIP_ROW_BYTE2, fwupd_flash_chip_row.bytes[CHIP_ROW_BYTE_F067]);
            return result;
        }
    }

    /* 3. Read the id through registers 0xF064..0xF066, up to three times. */
    for (attempt = 0; attempt < FLASH_ID_TRIES; attempt++) {
        fwupd_svc_write_register(SVC_REG_ID_TRY, flash_id_try_values[attempt]);
        fwupd_svc_query_cmd_0x11();
        for (byte_index = 0; byte_index < 3; byte_index++) reply[byte_index] = fwupd_svc_read_register(SVC_REG_ID_BYTES + byte_index);
        row = flash_lookup_chip_id(reply, CHIP_TABLE);
        if (row != CHIP_NOT_FOUND) break;
    }

    /* 4. Keep the row of the chip found. */
    if (row == CHIP_NOT_FOUND) {
        result = IDENTIFY_UNKNOWN_CHIP;
    } else {
        result = IDENTIFY_OK;
        fwupd_flash_chip_row = flash_chip_table[row];
        fwupd_svc_write_register(SVC_REG_CHIP_ROW_BYTE2, fwupd_flash_chip_row.bytes[CHIP_ROW_BYTE_F067]);
    }
    return result;
}


void fwupd_svc_query_cmd_0x25(void);
void timer_delay_units(unsigned char t);

/* Run one transfer through the SPI registers 0xF0C0..0xF0C6 and the window at 0xA700.
 *   spi_bytes: part1_len + part2_len bytes to send; on return it holds the first 16 bytes of the window
 *   part1_len: written to register 0xF0C4 (and, halved, into bits 4..7 of 0xF0C0)
 *   part2_len: register 0xF0C6 gets part1_len + part2_len
 * After the bytes: service command 0x25, a wait of 0x14 delay units, then the window is read back.
 */
void fwupd_svc_spi_transfer(unsigned char *spi_bytes, unsigned char part1_len, unsigned char part2_len)
{
    unsigned char idx;
    fwupd_svc_write_register(0xf0c0, ((part1_len >> 1) << 4) | 3);
    fwupd_svc_write_register(0xf0c1, 0xa7);
    fwupd_svc_write_register(0xf0c2, 0);
    fwupd_svc_write_register(0xf0c3, 0xa7);
    fwupd_svc_write_register(0xf0c4, part1_len);
    fwupd_svc_write_register(0xf0c5, 0xa7);
    fwupd_svc_write_register(0xf0c6, part1_len + part2_len);
    for (idx = 0; idx < part1_len + part2_len; idx++) fwupd_svc_write_register(SVC_REG_SPI_WINDOW + idx, spi_bytes[idx]);
    fwupd_svc_query_cmd_0x25();
    timer_delay_units(0x14);
    for (idx = 0; idx < SVC_SPI_READ_BACK; idx++) spi_bytes[idx] = fwupd_svc_read_register(SVC_REG_SPI_WINDOW + idx);
}

/* Write one register over the service link: packet 04 78 <reg high byte> <reg byte> <val>, wait on the ready
 * line, read the reply into fwupd_svc_packet. Returns what i2c_write_packet returned. */
unsigned char fwupd_svc_write_register(unsigned int reg, unsigned char val)
{
    unsigned char write_status;
    fwupd_svc_packet[0] = 4;
    fwupd_svc_packet[1] = SVC_CMD_WRITE_REG;
    fwupd_svc_packet[2] = reg >> 8;
    fwupd_svc_packet[3] = reg;
    fwupd_svc_packet[4] = val;
    write_status = i2c_write_packet(SVC_ADDRESS, 5, fwupd_svc_packet);
    fwupd_wait_ready_line(100);
    fwupd_svc_read_reply(fwupd_svc_packet);
    return write_status;
}


extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char i2c_read_packet(unsigned char addr, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply(unsigned char *buf);
void timer_delay_units(unsigned char n);
void timer_delay_base(void);
/* Read a reply packet from the service address into buf, then a short delay. */
void fwupd_svc_read_reply(unsigned char *buf)
{
    i2c_read_packet(SVC_ADDRESS, buf);
    timer_delay_units(2);
}


extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply(unsigned char *buf);
/* Service packet 02 0F <arg>, wait on the ready line, read the reply. */
void fwupd_svc_send_cmd_0x0f(unsigned char arg)
{
    fwupd_svc_packet[0] = 2;
    fwupd_svc_packet[1] = 0x0f;
    fwupd_svc_packet[2] = arg;
    i2c_write_packet(SVC_ADDRESS, 3, fwupd_svc_packet);
    fwupd_wait_ready_line(100);
    fwupd_svc_read_reply(fwupd_svc_packet);
}


/* The ten-byte service record at CODE 0xCBCC and its working copy at XDATA 0x08F5. */
struct svc_record10 { unsigned char bytes[10]; };
extern struct svc_record10 code fwupd_svc_record10_template;
extern struct svc_record10 xdata fwupd_svc_record10_copy;
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
/* Send the CODE 0xCBCC record with bytes 8 and 9 replaced by arg8 and arg9, then wait on the ready line (limit 5000).
 * The reply is left for the caller to read. */
void fwupd_svc_send_rec_cbcc(unsigned char arg8, unsigned char arg9)
{
    fwupd_svc_record10_copy = fwupd_svc_record10_template;
    fwupd_svc_record10_copy.bytes[8] = arg8;
    fwupd_svc_record10_copy.bytes[9] = arg9;
    i2c_write_packet(SVC_ADDRESS, 10, fwupd_svc_record10_copy.bytes);
    fwupd_wait_ready_line(5000);
}


extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char i2c_read_packet(unsigned char addr, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply(unsigned char *buf);
void fwupd_svc_read_reply(unsigned char *buf);
void timer_delay_units(unsigned char t);
unsigned char fwupd_svc_write_register(unsigned int reg, unsigned char val);


extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply(unsigned char *buf);
/* Service packet 02 36 <arg>, wait on the ready line (limit 4000); returns reply bytes 2 and 3 as one 16-bit value
 * (byte 2 high). */
unsigned int fwupd_svc_query_cmd_0x36(unsigned char arg)
{
    fwupd_svc_packet[0] = 2;
    fwupd_svc_packet[1] = 0x36;
    fwupd_svc_packet[2] = arg;
    i2c_write_packet(SVC_ADDRESS, 3, fwupd_svc_packet);
    fwupd_wait_ready_line(4000);
    fwupd_svc_read_reply(fwupd_svc_packet);
    return ((unsigned int)fwupd_svc_packet[2] << 8) | fwupd_svc_packet[3];
}


sfr P1 = 0x90;
sbit P1_4 = P1 ^ 4;
extern unsigned char xdata fwupd_svc_packet[];
extern unsigned char xdata fwupd_svc_claim_reply_byte1, fwupd_svc_claim_reply_byte2;
void i2c_set_bit_delay(unsigned char a);
void timer_delay_units(unsigned char n);
void fwupd_svc_bus_handshake(unsigned char m);
void fwupd_svc_read_reply(unsigned char *buf);
unsigned char fwupd_svc_read_register(unsigned int reg);
unsigned char fwupd_svc_write_register(unsigned int reg, unsigned char val);

/* Take (take = 1) or release (take = 0) the service link.
 * Sets the bit delay of the update agent's I2C bus to 0x14 for the handshake and back to 1 at the end, sets P1.4 and runs
 * fwupd_svc_bus_handshake(take). On take it also keeps reply bytes 1 and 2 in XDATA 0x0648 / 0x0649 and writes a
 * fixed set of registers: 0xF04C = 0x60, 0xD929 = 0x06, 0xF1A8 = 0x02; when register 0xF050 bit 2 is set,
 * 0xF11C bit 6 on and 0xF11D bit 6 off; 0xF0E0 = 0xAA; 0xF0FF bit 6 on. */
void fwupd_svc_claim_link(unsigned char take)
{
    i2c_set_bit_delay(0x14);
    P1_4 = 1;
    timer_delay_units(2);
    fwupd_svc_bus_handshake(take);
    if (take == 1) {
        timer_delay_units(5);
        fwupd_svc_read_reply(fwupd_svc_packet);
        fwupd_svc_claim_reply_byte1 = fwupd_svc_packet[1];
        fwupd_svc_claim_reply_byte2 = fwupd_svc_packet[2];
        fwupd_svc_write_register(0xf04c, 0x60);
        fwupd_svc_write_register(0xd929, 0x06);
        fwupd_svc_write_register(0xf1a8, 0x02);
        if (fwupd_svc_read_register(0xf050) & 0x04) {
            fwupd_svc_write_register(0xf11c, fwupd_svc_read_register(0xf11c) | 0x40);
            fwupd_svc_write_register(0xf11d, fwupd_svc_read_register(0xf11d) & ~0x40);
        }
        fwupd_svc_write_register(0xf0e0, 0xaa);
        fwupd_svc_write_register(0xf0ff, fwupd_svc_read_register(0xf0ff) | 0x40);
    }
    i2c_set_bit_delay(1);
}


/* Update mode bits, as fwupd_run_isp_write and fwupd_svc_erase_flash test them. */
#define ISP_MODE_BIT0           0x01    /* erase: one fixed record (fwupd_svc_send_rec_cbc4) */
#define ISP_MODE_BIT1           0x02    /* erase with bit 2: second half of the position range only */
#define ISP_MODE_BIT2           0x04    /* without bit 1: erase = fwupd_svc_erase_second_half(1) */
#define ISP_MODE_BIT3           0x08    /* protect steps twice, control bit 0 then 1 (fwupd_svc_set_control_bit) */
#define ISP_MODE_RETURNS        0x10    /* returns a result instead of ending in an endless loop (port command 0x16) */
#define ISP_MODE_PICK_REGION    0x11    /* also picks the DUALFW region and prints the result (port command 0x17) */
#define FLASH_SIZE_CODE_10      0x10    /* the one size code that sends 8 with command 0x99 */
#define ERASE_STEP              16      /* positions per erase record */

extern unsigned char xdata fwupd_svc_packet[];
extern unsigned char xdata fwupd_flash_size_code;
extern void fwupd_svc_send_rec_cbc4(void);
extern void fwupd_svc_read_reply(unsigned char *p);
extern void fwupd_svc_erase_second_half(unsigned char a);
extern void fwupd_svc_send_cmd_0x99(unsigned char a);
void fwupd_svc_send_cmd_0x0f(unsigned char a);
void fwupd_svc_send_rec_cbcc(unsigned char a, unsigned char b);

/* Erase step of fwupd_run_isp_write, chosen by the mode bits:
 *   bit 0: send the CODE 0xCBC4 record (fwupd_svc_send_rec_cbc4) and read the reply;
 *   bit 2 without bit 1: fwupd_svc_erase_second_half(1);
 *   otherwise a walk over the positions 0 .. size code * 32 - 1 (bits 2 and 1 together: from the middle on, after
 *   service command 0x99 with 8 for size code 0x10, else 0), in steps of 16. Each step sends service command 0x0F
 *   with pos / 16 when pos is a multiple of 16 (the start and the step make it one every time), then the CODE 0xCBCC
 *   record with bytes 8 and 9 = pos and pos + 14 (low bytes), and reads the reply. */
void fwupd_svc_erase_flash(unsigned char mode)
{
    unsigned int pos_end;
    unsigned int pos;
    if (mode & ISP_MODE_BIT0) {
        fwupd_svc_send_rec_cbc4();
        fwupd_svc_read_reply(fwupd_svc_packet);
        return;
    }
    if ((mode & ISP_MODE_BIT2) && !(mode & ISP_MODE_BIT1)) {
        fwupd_svc_erase_second_half(1);
        return;
    }
    if ((mode & ISP_MODE_BIT2) && (mode & ISP_MODE_BIT1)) {
        /* Second half only. */
        pos_end = ((unsigned int)fwupd_flash_size_code << 8) >> 3;
        if (fwupd_flash_size_code == FLASH_SIZE_CODE_10) fwupd_svc_send_cmd_0x99(8); else fwupd_svc_send_cmd_0x99(0);
        for (pos = pos_end >> 1; pos < pos_end; pos += ERASE_STEP) {
            if ((pos & 0x0f) == 0) fwupd_svc_send_cmd_0x0f(pos >> 4);
            fwupd_svc_send_rec_cbcc(pos, pos + 14);
            fwupd_svc_read_reply(fwupd_svc_packet);
        }
    } else {
        /* The whole range. */
        pos_end = ((unsigned int)fwupd_flash_size_code << 8) >> 3;
        for (pos = 0; pos < pos_end; pos += ERASE_STEP) {
            if ((pos & 0x0f) == 0) fwupd_svc_send_cmd_0x0f(pos >> 4);
            fwupd_svc_send_rec_cbcc(pos, pos + 14);
            fwupd_svc_read_reply(fwupd_svc_packet);
        }
    }
}

#define FMT_RESULT_LINE         ((void code *)0xcb51)   /* "result = %d\r\n" */
#define SVC_REG_F1E0            0xf1e0  /* bit 3 is cleared around the erase and write steps */
#define F1E0_CLEAR_BIT3         0xf7
#define FWUPD_MAILBOX_F19A      0xF19A  /* = reg_fwupd_mailbox_f19a */

/* fwupd_dualfw_region (XDATA 0x0434): current and next DUALFW region index. */
struct dualfw_region { unsigned char cur; unsigned char next; };
extern struct dualfw_region xdata fwupd_dualfw_region;
extern unsigned char xdata fwupd_state_reg_on_flag;
extern void lib_printf517(void *fmt, ...) large;
void fwupd_svc_claim_link(unsigned char m);
unsigned char flash_identify_chip(void);
void fwupd_pick_valid_region(void);
unsigned char fwupd_refresh_flash_records(unsigned char mode);
void fwupd_svc_set_isp_mode(unsigned char a);
void fwupd_svc_send_cmd_0xa3(unsigned char a);
unsigned char fwupd_svc_send_region_thunk(void);
void fwupd_svc_set_control_bit(bit on);
void fwupd_svc_send_0x99_and_record(void);
void fwupd_svc_erase_flash(unsigned char mode);
void fwupd_write_flash_blocks(unsigned char mode);
void fwupd_write_dualfw_tag(unsigned char mode);
unsigned char fwupd_svc_write_register(unsigned int reg, unsigned char val);
unsigned char fwupd_svc_read_register(unsigned int reg);
void fwupd_svc_set_write_protect(unsigned char on);
void timer_delay_units(unsigned char n);
void fwupd_svc_write_protect_off(void);

/* Write the flash over the service link in the given update mode.
 *
 * With mode bit 4 (modes 0x10 / 0x11) it returns:
 *   1. take the link, identify the chip;
 *   2. mode 0x11: pick the valid DUALFW region, refresh the flash records, print "result = %d";
 *      other modes: region cur = 2, next = 0, refresh the flash records;
 *   3. fwupd_svc_set_write_protect(0), register 0xD7E0 = 0x81, fwupd_svc_set_isp_mode(1),
 *      service command 0xA3 with 0xF3;
 *   4. with no error so far: mailbox byte 0xF19A = 0 and fwupd_svc_send_region_thunk; returns 1 when that
 *      returns 0. Any error returns 0.
 * Without bit 4 it never returns:
 *   1. take the link, register 0xF0DE = 0x21, identify the chip (result not tested), keep register 0xF1E0 and
 *      clear its bit 3;
 *   2. write protect off (twice with bit 3, around fwupd_svc_set_control_bit), then the erase step;
 *   3. fwupd_svc_set_write_protect(0), restore 0xF1E0, write the blocks (fwupd_write_flash_blocks);
 *   4. with bit 2 or 3: write the DUALFW tag and fwupd_svc_set_write_protect(1) (bit 3: again with the control bit);
 *   5. 0xF1E0 with bit 3 clear, then restored; release the link; endless loop.
 * Caller: fwupd_step_port_state, on port commands 0x11 / 0x12 / 0x14 / 0x15 (modes 1 / 2 / 4 / 8) and 0x16 / 0x17
 * (modes 0x10 / 0x11, after printing "CMD_START_ISP_ROMCODE_MODE" / "..._DUALFW"). On a return of 1 it then
 * watches mailbox byte 0xF19A.
 */
bit fwupd_run_isp_write(unsigned char mode)
{
    unsigned char f1e0_saved;   /* register 0xF1E0 as read before the erase */
    unsigned char status;       /* OR of the step results (0 = no error); at the end 1 = success */
    status = 0;
    if (mode & ISP_MODE_RETURNS) {
        /* 1. Link and chip. */
        fwupd_svc_claim_link(1);
        status |= flash_identify_chip();
        /* 2. Region and flash records. */
        if (mode == ISP_MODE_PICK_REGION) {
            fwupd_pick_valid_region();
            status |= fwupd_refresh_flash_records(mode);
            lib_printf517(FMT_RESULT_LINE, (unsigned int)status);
        } else {
            fwupd_dualfw_region.next = 0;
            fwupd_dualfw_region.cur = 2;
            status |= fwupd_refresh_flash_records(mode);
        }
        /* 3. Protect, register 0xD7E0, ISP mode, command 0xA3. */
        fwupd_svc_set_write_protect(0);
        fwupd_svc_write_register(0xd7e0, 0x81);
        fwupd_svc_set_isp_mode(1);
        fwupd_svc_send_cmd_0xa3(0xf3);
        /* 4. Only without an error: clear mailbox byte 0xF19A and pass on to fwupd_svc_send_region. */
        if (status == 0) {
            XBYTE[FWUPD_MAILBOX_F19A] = 0;
            if (fwupd_svc_send_region_thunk() == 0) status = 1;
            else status = 0;
        } else status = 0;
        return status;
    }

    /* 1. Link, chip, register 0xF1E0. */
    fwupd_state_reg_on_flag = 0;
    fwupd_svc_claim_link(1);
    fwupd_svc_write_register(0xf0de, 0x21);
    flash_identify_chip();
    f1e0_saved = fwupd_svc_read_register(SVC_REG_F1E0);
    fwupd_svc_write_register(SVC_REG_F1E0, f1e0_saved & F1E0_CLEAR_BIT3);

    /* 2. Write protect off, then erase. */
    if ((mode & ISP_MODE_BIT2) || (mode & ISP_MODE_BIT3)) {
        if (mode & ISP_MODE_BIT3) fwupd_svc_set_control_bit(0);
        fwupd_svc_write_protect_off();
        fwupd_svc_read_reply(fwupd_svc_packet);
        timer_delay_units(10);
        fwupd_svc_send_0x99_and_record();
        if (mode & ISP_MODE_BIT3) {
            fwupd_svc_set_control_bit(1);
            fwupd_svc_write_protect_off();
            fwupd_svc_read_reply(fwupd_svc_packet);
            timer_delay_units(10);
        }
        fwupd_svc_erase_flash(mode);
    } else {
        fwupd_svc_write_protect_off();
        fwupd_svc_read_reply(fwupd_svc_packet);
        timer_delay_units(10);
        fwupd_svc_erase_flash(mode);
    }

    /* 3. Write the blocks. */
    fwupd_svc_set_write_protect(0);
    fwupd_svc_read_reply(fwupd_svc_packet);
    fwupd_svc_write_register(SVC_REG_F1E0, f1e0_saved);
    fwupd_write_flash_blocks(mode);

    /* 4. DUALFW tag and write protect on. */
    if ((mode & ISP_MODE_BIT2) || (mode & ISP_MODE_BIT3)) {
        if (mode & ISP_MODE_BIT3) fwupd_svc_set_control_bit(0);
        fwupd_write_dualfw_tag(mode);
        fwupd_svc_set_write_protect(1);
        if (mode & ISP_MODE_BIT3) {
            fwupd_svc_set_control_bit(1);
            fwupd_svc_set_write_protect(1);
        }
    }

    /* 5. Release the link and stop here. */
    fwupd_svc_write_register(SVC_REG_F1E0, f1e0_saved & F1E0_CLEAR_BIT3);
    fwupd_svc_write_register(SVC_REG_F1E0, f1e0_saved);
    fwupd_svc_claim_link(0);
    for (;;) ;
}
