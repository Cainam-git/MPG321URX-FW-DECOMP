/* fwupd_find_and_verify_file  (FUN_a0147fb4)
 *
 * Look for a named file on the update port and verify its checksum.
 * Returns: status code
 * Name basis: derived - retries the name match ('File match'), handshake 0x46, then
 *   fwupd_verify_file_checksum; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147fb4 @ 0xa0147fb4-0xa0148120 (91 words), flags -mcpu=v8 -O3 -g. Variant of fwupd_find_file
 * (fwupd_find_file).
 * Source form the exact build depends on: as in fwupd_find_file, the name length is copied through an unsigned int
 * into the loop index (name_length_word = name_length; i = name_length_word;) before the calls, and the name is
 * compared with the index i.
 */
/* Register n of the update port window: address 0xCF000000 | n << 2. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define FWUPD_PORT_STATUS         0xf190        /* + 2 * port */
#define FWUPD_PORT_COMMAND        0xf191        /* + 2 * port */
#define FWUPD_STATE_DISK_MOUNTED  0x96          /* the update agent has mounted the disk and waits for commands */
#define FWUPD_STATE_FAILED        0x9c          /* the agent's failure state */
#define FWUPD_CMD_LOAD_FILE       0x46          /* the agent loads the selected file into memory */
#define FILE_NAME_LAST            44            /* last index of the name search (a name has at most 44 characters) */

/* Results. */
#define FIND_RESULT_FAILED        3             /* the agent went to its failure state after the command */
#define FIND_RESULT_NOT_FOUND     4             /* no match, or the agent left the disk-mounted state */

extern unsigned char fwupd_get_active_port(void);
extern unsigned int fwupd_get_file_name_buffer(void);
extern void fwupd_read_file_name(void);
extern void ipc_signal_alive(void);
extern unsigned char fwupd_is_file_name_match(unsigned char *buf, unsigned char n);
extern int fwupd_verify_file_checksum(void);

/*
 * Look for the file called name on the update port; when it is found, have the update agent load it and check
 * its checksum.
 *   name  file name, zero-terminated (or 44 characters long)
 * Returns FIND_RESULT_NOT_FOUND (4) when the agent leaves the disk-mounted state without a match,
 * FIND_RESULT_FAILED (3) when the agent reports its failure state after the load, else the result of
 * fwupd_verify_file_checksum (2 match, 3 mismatch, 5 name too long).
 *
 * While the agent of the active port reports the disk-mounted state (0x96), the file name is read from the port
 * again and compared with name; the sign of life to the 8051 is sent in the loop. On a match command 0x46 is
 * written to the port and the routine waits until the agent has taken it.
 * No direct caller was found (docs/MAP.md: the entry routines of this route are not called in FW.021).
 */
unsigned char fwupd_find_and_verify_file(unsigned char *name)
{
    unsigned char i, name_length = 0, port;
    unsigned int name_length_word;

    /* The length of the name: index of its first zero byte, else the last index of the search. */
    for (i = 0; i <= FILE_NAME_LAST; i++) {
        if (name[i] == 0) {
            name_length = i;
            break;
        }
        if (i == FILE_NAME_LAST)
            name_length = i;
    }
    name_length_word = name_length;
    i = name_length_word;           /* from here i holds the name length */
    port = fwupd_get_active_port();
    fwupd_get_file_name_buffer();
    if (RB(port * 2 + FWUPD_PORT_STATUS) == FWUPD_STATE_DISK_MOUNTED) {
        do {
            fwupd_read_file_name();
            ipc_signal_alive();
            if (fwupd_is_file_name_match(name, i) == 1) {
                RB(port * 2 + FWUPD_PORT_COMMAND) = FWUPD_CMD_LOAD_FILE;
                while (RB(port * 2 + FWUPD_PORT_COMMAND) == FWUPD_CMD_LOAD_FILE)
                    ipc_signal_alive();
                if (RB(port * 2 + FWUPD_PORT_STATUS) == FWUPD_STATE_FAILED)
                    return FIND_RESULT_FAILED;
                return fwupd_verify_file_checksum();
            }
        } while (RB(port * 2 + FWUPD_PORT_STATUS) == FWUPD_STATE_DISK_MOUNTED);
    }
    return FIND_RESULT_NOT_FOUND;
}
