/* fwupd_run_mailbox_command  (FUN_CODE_a36c)
 *
 * Carry out one command from the main processor's mailbox byte.
 *   cmd: command byte
 * Name basis: derived - 0xF198 commands: 0x70 mode (host/device), 0x31 set values, 0x52..0x58 name table,
 *   0x5A/0x5B/0x60 values
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_a36c @ 0xa36c (475 B, 0xA36C..0xA547), compiled with OPTIMIZE(8,SPEED) LARGE.
 * ?C?CCASE switch on cmd (LARGE parameter at 0x08E5); the case table at 0xA374..0xA3AD is data inside the function.
 * Locals record_total (0x08E6) and file_size (0x08EA).
 * Source forms: the mailbox bytes 0xF199..0xF19F are accessed through Keil's absacc.h XBYTE form (volatile xdata
 * pointer at 0); with plain extern bytes Keil keeps cmd in R7 across the record copy and the code is 2 bytes
 * shorter. The name table is declared with a fixed size (7 pieces of 6 bytes, under 256 bytes), so Keil computes
 * the piece offset in 8 bits (MUL AB, CLR A / ADDC); with an open size it adds B as the high byte. Case 0x60 is
 * written before case 0x5A (body order and local order in the firmware).
 */
#define XBYTE ((unsigned char volatile xdata *)0)

/* Mailbox bytes after the command byte 0xF198 (0xF199 .. 0xF19F): parameters in, answers out. */
#define FWUPD_MAILBOX_F199   0xF199
#define FWUPD_MAILBOX_F19A   0xF19A
#define FWUPD_MAILBOX_F19B   0xF19B
#define FWUPD_MAILBOX_F19C   0xF19C
#define FWUPD_MAILBOX_F19D   0xF19D
#define FWUPD_MAILBOX_F19E   0xF19E
#define FWUPD_MAILBOX_F19F   0xF19F

/* Commands of the mailbox byte, named after what this routine does with them. */
#define MBOX_CMD_SET_BAUD_RATE    0x11   /* uart_set_baud_rate(0xF19E, 0xF19F) */
#define MBOX_CMD_CD0A_BIT5_SET    0x21
#define MBOX_CMD_CD0A_BIT5_CLEAR  0x22
#define MBOX_CMD_SET_MEM_BASE     0x31   /* usb_mem_base = 0xF19C..0xF19F, usb_phy_tune_value = 0xF199 */
#define MBOX_CMD_WORK_BYTES_0_4   0x41   /* 0xF19B..0xF19F -> work array bytes 0..4 */
#define MBOX_CMD_WORK_BYTES_5_7   0x42   /* 0xF19B..0xF19D -> work array bytes 5..7 */
#define MBOX_CMD_GET_NAME_FIRST   0x52   /* 0x52..0x58: 6 bytes of the entry name each */
#define MBOX_CMD_GET_NAME_LAST    0x58
#define MBOX_CMD_SET_CONFIG_SUM   0x59   /* fwupd_config_sum = 0xF19A:0xF19B */
#define MBOX_CMD_GET_FILE_SIZE    0x5a   /* value at 0x0109 -> 0xF19B..0xF19E */
#define MBOX_CMD_GET_DRAM_ADDRESS 0x5b   /* fwupd_post_value_0717 */
#define MBOX_CMD_GET_RECORD_TOTAL 0x60   /* value at 0x0113, three bytes -> 0xF19B..0xF19D */
#define MBOX_CMD_SET_USB_MODE     0x70   /* fwupd_requested_usb_mode = 0xF19A */

#define CD0A_BIT5            0x20

extern unsigned char xdata reg_usb0_byte_0a;
extern unsigned char xdata usb_phy_tune_value;
extern unsigned char xdata fwupd_requested_usb_mode;
/* The name of the directory entry listed last, read out in 7 pieces of 6 bytes (bytes 0..41). */
extern unsigned char xdata fwupd_entry_name[7][6];
extern void uart_set_baud_rate(unsigned char a, unsigned int b);
extern void fwupd_set_value_08c9(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
extern void lib_copy_to_work_array(unsigned char off, unsigned char *src, unsigned char n);
extern void fwupd_set_value_0156(unsigned int v);
extern unsigned long fwupd_get_record_total(void);
extern unsigned long fwupd_get_value_0109_copy(void);
extern void fwupd_post_value_0717(void);

/* fwupd_run_mailbox_command: carry out one command the main processor wrote into mailbox byte 0xF198.
 *
 * cmd: the command byte. Caller: sys_main, which takes a non-zero 0xF198, passes it here and then clears 0xF198
 * (during the 16 start-up rounds and in every main-loop round).
 *
 * Parameters are read from and answers written to the mailbox bytes 0xF199..0xF19F; see the command list above.
 * Values are stored low byte first in the answer bytes. A command not listed does nothing. The routine returns
 * nothing; the main processor sees only the answer bytes.
 * Of the work array commands: lib_copy_to_work_array stores into the 8 bytes at XDATA 0x064A.
 */
void fwupd_run_mailbox_command(unsigned char cmd)
{
    unsigned long record_total, file_size;
    switch (cmd) {
    case MBOX_CMD_SET_BAUD_RATE:
        uart_set_baud_rate(XBYTE[FWUPD_MAILBOX_F19E], XBYTE[FWUPD_MAILBOX_F19F]);
        break;
    case MBOX_CMD_CD0A_BIT5_SET:
        reg_usb0_byte_0a |= CD0A_BIT5;
        break;
    case MBOX_CMD_CD0A_BIT5_CLEAR:
        reg_usb0_byte_0a &= 0xdf;
        break;
    case MBOX_CMD_SET_MEM_BASE:
        /* First byte = bits 24..31 of the base. */
        fwupd_set_value_08c9(XBYTE[FWUPD_MAILBOX_F19C], XBYTE[FWUPD_MAILBOX_F19D], XBYTE[FWUPD_MAILBOX_F19E], XBYTE[FWUPD_MAILBOX_F19F]);
        usb_phy_tune_value = XBYTE[FWUPD_MAILBOX_F199];
        break;
    case MBOX_CMD_WORK_BYTES_0_4:
        lib_copy_to_work_array(0, &XBYTE[FWUPD_MAILBOX_F19B], 5);
        break;
    case MBOX_CMD_WORK_BYTES_5_7:
        lib_copy_to_work_array(5, &XBYTE[FWUPD_MAILBOX_F19B], 3);
        break;
    case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: case 0x58:
        /* Piece cmd - 0x52 of the entry name into 0xF19A..0xF19F. */
        cmd -= MBOX_CMD_GET_NAME_FIRST;
        XBYTE[FWUPD_MAILBOX_F19A] = fwupd_entry_name[cmd][0];
        XBYTE[FWUPD_MAILBOX_F19B] = fwupd_entry_name[cmd][1];
        XBYTE[FWUPD_MAILBOX_F19C] = fwupd_entry_name[cmd][2];
        XBYTE[FWUPD_MAILBOX_F19D] = fwupd_entry_name[cmd][3];
        XBYTE[FWUPD_MAILBOX_F19E] = fwupd_entry_name[cmd][4];
        XBYTE[FWUPD_MAILBOX_F19F] = fwupd_entry_name[cmd][5];
        break;
    case MBOX_CMD_SET_CONFIG_SUM:
        fwupd_set_value_0156(((unsigned int)XBYTE[FWUPD_MAILBOX_F19A] << 8) | XBYTE[FWUPD_MAILBOX_F19B]);
        break;
    case MBOX_CMD_GET_RECORD_TOTAL:
        /* Sizes of records 1 and up, each rounded up to 256-byte units and added (fwupd_build_record_table);
         * only bits 0..23 are posted. */
        record_total = fwupd_get_record_total();
        XBYTE[FWUPD_MAILBOX_F19B] = record_total;
        XBYTE[FWUPD_MAILBOX_F19C] = record_total >> 8;
        XBYTE[FWUPD_MAILBOX_F19D] = record_total >> 16;
        break;
    case MBOX_CMD_GET_FILE_SIZE:
        file_size = fwupd_get_value_0109_copy();
        XBYTE[FWUPD_MAILBOX_F19B] = file_size;
        XBYTE[FWUPD_MAILBOX_F19C] = file_size >> 8;
        XBYTE[FWUPD_MAILBOX_F19D] = file_size >> 16;
        XBYTE[FWUPD_MAILBOX_F19E] = file_size >> 24;
        break;
    case MBOX_CMD_GET_DRAM_ADDRESS:
        fwupd_post_value_0717();
        break;
    case MBOX_CMD_SET_USB_MODE:
        /* 0 = host mode, 1 = device mode; sys_main sets the controllers up when this differs from the mode in
         * effect. */
        fwupd_requested_usb_mode = XBYTE[FWUPD_MAILBOX_F19A];
        break;
    }
}
