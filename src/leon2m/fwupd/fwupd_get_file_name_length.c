/* fwupd_get_file_name_length  (FUN_a0147cac)
 *
 * Return the length of a file name, at most 44.
 * Returns: length
 * Name basis: derived - index of the first zero byte in 44 bytes; unused
 *
 * Matching notes
 * --------------
 * FUN_a0147cac (leon2m 0xa0147cac-0xa0147d0c, 96 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: the loop sets r on a zero byte (break) and on the last index.
 */
#define FILE_NAME_MAX 44                /* longest name: the zero-byte search covers bytes 0 to 44 */

/*
 * Return the length of the file name at name: the index of its first zero byte, or 44 when none of bytes 0 to
 * 43 is zero. A zero byte at index 44 and a name without any zero byte both give 44. Nothing in the image
 * refers to this routine.
 */
unsigned char fwupd_get_file_name_length(const unsigned char *name)
{
    unsigned char i, length = 0;

    for (i = 0; i < FILE_NAME_MAX + 1; i++) {
        if (name[i] == 0) {
            length = i;
            break;
        }
        if (i == FILE_NAME_MAX)
            length = i;
    }
    return length;
}
