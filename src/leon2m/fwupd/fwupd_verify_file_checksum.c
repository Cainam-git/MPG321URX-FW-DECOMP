/* fwupd_verify_file_checksum  (FUN_a0147d70)
 *
 * Compare the checksum in a file's name with the sum of its data.
 * Returns: 2 or 3 for the result, 5 for a name that is too long
 * Name basis: proven - prints 'FileNameChkSum = %x', 'TotalFileNameLen = %d' and 'checksum = %x'
 *
 * Matching notes
 * --------------
 * FUN_a0147d70 (leon2m 0xa0147d70-0xa0147fb4, 580 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: result is set to FILE_CHECKSUM_MATCH before the last print call and changed to
 * FILE_CHECKSUM_MISMATCH after it, so the final compare stays a branch (a set right before the test would be
 * if-converted). The name length loop keeps its two exits (the zero byte, and the last position 0x2c).
 */
extern int dbg_printf(const char *fmt, ...);
extern unsigned char *fwupd_get_file_name_buffer(void);
extern void sys_mem_port_enable(unsigned char on);
extern void sys_mem_port_read_blocks(unsigned char *out, unsigned int addr, unsigned char n, unsigned char mode);
extern unsigned char fwupd_hex_digit_value(int ch);

#define REG(a) (*(volatile unsigned int *)(a))

/* The update agent's mailbox, seen from this processor: register 0xCF000000 + 4 * XDATA address of the 8051. */
#define FWUPD_MAILBOX_COMMAND 0xcf03c660        /* XDATA 0xF198, the command byte */
#define FWUPD_MAILBOX_F19B    0xcf03c66c        /* answer, low byte ... */
#define FWUPD_MAILBOX_F19C    0xcf03c670
#define FWUPD_MAILBOX_F19D    0xcf03c674
#define FWUPD_MAILBOX_F19E    0xcf03c678        /* ... high byte */

/* Commands of the mailbox byte (as the update agent's fwupd_run_mailbox_command names them). */
#define MBOX_CMD_GET_FILE_SIZE    0x5a
#define MBOX_CMD_GET_DRAM_ADDRESS 0x5b

#define NAME_LAST_POSITION 0x2c                 /* the length scan stops here */
#define NAME_LENGTH_MAX    0x27                 /* longer names are refused */
#define BLOCK_BYTES        32                   /* one read of sys_mem_port_read_blocks */
#define MODE_REVERSED      0                    /* sys_mem_port_read_blocks: not MODE_ASCENDING */

/* Results. */
#define FILE_CHECKSUM_MATCH    2
#define FILE_CHECKSUM_MISMATCH 3
#define FILE_NAME_TOO_LONG     5

/* An answer of the update agent: four mailbox bytes, high byte in 0xF19E. */
#define MAILBOX_ANSWER() \
    ((REG(FWUPD_MAILBOX_F19E) << 24) + (REG(FWUPD_MAILBOX_F19D) << 16) + (REG(FWUPD_MAILBOX_F19C) << 8) \
     + REG(FWUPD_MAILBOX_F19B))

/*
 * Check the update file against the checksum written in its name.
 *
 * The name is the one in fwupd_get_file_name_buffer. Its length is the position of the first zero byte, or 0x2c
 * when there is none up to there; a length above 0x27 gives FILE_NAME_TOO_LONG at once. Then two values are
 * asked from the update agent through its mailbox: MBOX_CMD_GET_FILE_SIZE and MBOX_CMD_GET_DRAM_ADDRESS. For
 * each, the command is written to the command byte and the routine waits until the byte reads something else (the
 * agent's main loop clears it after carrying the command out); the answer is in the four bytes after it.
 *
 * With the memory port on, file_size / 32 blocks of 32 bytes are read from the port, starting at block address
 * first_block, and all their bytes are added up in 16 bits; a last part shorter than 32 bytes is not counted.
 * The name's checksum is the four characters before the last four of the name, read as hexadecimal digits
 * (the first one is the high digit; the characters are not checked to be digits).
 *
 * Returns FILE_CHECKSUM_MATCH when the two are equal, FILE_CHECKSUM_MISMATCH when not. The only caller is
 * fwupd_find_and_verify_file, which returns this result.
 */
int fwupd_verify_file_checksum(void)
{
    unsigned char *name = fwupd_get_file_name_buffer();
    unsigned char block[BLOCK_BYTES];
    unsigned char pos, j, name_len = 0;
    unsigned int file_size, first_block, block_count, i;
    unsigned short sum, name_checksum;
    int result;

    for (pos = 0; pos <= NAME_LAST_POSITION; pos++) {
        if (name[pos] == 0) {
            name_len = pos;
            break;
        }
        if (pos == NAME_LAST_POSITION)
            name_len = pos;
    }
    dbg_printf("TotalFileNameLen = %d\r\n", name_len);
    if (name_len > NAME_LENGTH_MAX)
        return FILE_NAME_TOO_LONG;

    REG(FWUPD_MAILBOX_COMMAND) = MBOX_CMD_GET_FILE_SIZE;
    while (REG(FWUPD_MAILBOX_COMMAND) == MBOX_CMD_GET_FILE_SIZE)
        ;
    file_size = MAILBOX_ANSWER();
    REG(FWUPD_MAILBOX_COMMAND) = MBOX_CMD_GET_DRAM_ADDRESS;
    while (REG(FWUPD_MAILBOX_COMMAND) == MBOX_CMD_GET_DRAM_ADDRESS)
        ;
    first_block = MAILBOX_ANSWER();

    sys_mem_port_enable(1);
    block_count = file_size >> 5;               /* whole 32-byte blocks */
    sum = 0;
    for (i = 0; i < block_count; i++) {
        sys_mem_port_read_blocks(block, first_block + i, 1, MODE_REVERSED);
        for (j = 0; j <= BLOCK_BYTES - 1; j++)
            sum += block[j];
    }
    dbg_printf("checksum = %x\r\n", sum);
    sys_mem_port_enable(0);

    name_checksum = fwupd_hex_digit_value(name[name_len - 8]) << 12 | fwupd_hex_digit_value(name[name_len - 7]) << 8
        | fwupd_hex_digit_value(name[name_len - 6]) << 4 | fwupd_hex_digit_value(name[name_len - 5]);
    result = FILE_CHECKSUM_MATCH;
    dbg_printf("FileNameChkSum = %x\r\n", name_checksum);
    if (sum != name_checksum)
        result = FILE_CHECKSUM_MISMATCH;
    return result;
}
