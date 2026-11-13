/* fwupd_is_file_name_match  (FUN_a0123c80)
 *
 * Compare a name with the file name read from the update port.
 * Returns: 1 when equal
 * Name basis: proven - prints 'File match'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0123c80 @ 0xa0123c80-0xa0123cf0 (28 words), flags -mcpu=v8 -O3 -g.
 * Source form: the match is reported inside the loop, when the last compared byte (index n - 1) is equal.
 */
extern int dbg_printf(const char *fmt, ...);
extern unsigned char fwupd_file_name[];

/*
 * Compare the start of a name with the file name read from the update port (fwupd_file_name).
 *   name:   the name to test
 *   length: number of bytes to compare
 * Returns 1 and prints "File match" when the first length bytes are equal; returns 0 at the first difference, and
 * for length 0. Callers: fwupd_find_and_verify_file, fwupd_find_file.
 */
unsigned char fwupd_is_file_name_match(unsigned char *name, unsigned char length)
{
    unsigned char i;

    for (i = 0; i < length; i++) {
        if (name[i] != fwupd_file_name[i])
            return 0;
        if (i == length - 1) {
            dbg_printf("File match\r\n");
            return 1;
        }
    }
    return 0;
}
