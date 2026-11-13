/* fwupd_find_file  (FUN_a0148120)
 *
 * Look for a named file on the update port.
 * Returns: 2 when found, else 4
 * Name basis: derived - retries the name match, handshake 0x48; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148120, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the name length is copied through an unsigned int into the loop index
 * (name_length_word = name_length; i = name_length_word;) before the calls; that keeps it in a call-saved register
 * as in the firmware. The search loop compares the index, not the character, with the last index.
 */
/* Register n of the update port window: address 0xCF000000 | n << 2. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define FWUPD_PORT_STATUS         0xf190        /* + 2 * port */
#define FWUPD_PORT_COMMAND        0xf191        /* + 2 * port */
#define FWUPD_STATE_DISK_MOUNTED  0x96          /* the update agent has mounted the disk and waits for commands */
#define FWUPD_CMD_SET_TARGET_FILE 0x48          /* the agent selects the listed entry as the target file */
#define FILE_NAME_LAST            44            /* last index of the name search (a name has at most 44 characters) */

/* Results. */
#define FIND_RESULT_FOUND         2
#define FIND_RESULT_NOT_FOUND     4             /* no match, or the agent left the disk-mounted state */

extern unsigned char fwupd_get_active_port(void);
extern unsigned int fwupd_get_file_name_buffer(void);
extern void fwupd_read_file_name(void);
extern unsigned char fwupd_is_file_name_match(unsigned char *buf, unsigned char n);

/*
 * Look for the file called name on the update port and have the update agent select it as the target file.
 *   name  file name, zero-terminated (or 44 characters long)
 * Returns FIND_RESULT_FOUND (2) when the file was found, else FIND_RESULT_NOT_FOUND (4).
 *
 * While the agent of the active port reports the disk-mounted state (0x96), the file name is read from the port
 * again and compared with name. On a match command 0x48 is written to the port, the routine waits until the
 * agent has taken it and returns.
 * No direct caller was found (docs/MAP.md: the entry routines of this route are not called in FW.021).
 */
int fwupd_find_file(unsigned char *name)
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
            if (fwupd_is_file_name_match(name, i) == 1) {
                RB(port * 2 + FWUPD_PORT_COMMAND) = FWUPD_CMD_SET_TARGET_FILE;
                while (RB(port * 2 + FWUPD_PORT_COMMAND) == FWUPD_CMD_SET_TARGET_FILE)
                    ;
                return FIND_RESULT_FOUND;
            }
        } while (RB(port * 2 + FWUPD_PORT_STATUS) == FWUPD_STATE_DISK_MOUNTED);
    }
    return FIND_RESULT_NOT_FOUND;
}
